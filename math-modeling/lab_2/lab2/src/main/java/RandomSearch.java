import java.util.ArrayList;
import java.util.List;
import java.util.Random;

import org.knowm.xchart.*;
import org.knowm.xchart.style.lines.SeriesLines;
import org.knowm.xchart.style.markers.SeriesMarkers;

public class RandomSearch {
        private static double A = 1;
        private static double B = 1;

        public static double ellipsoid(double x, double y) {
                return Math.pow(x / A, 2) + Math.pow(y / B, 2);
        }

        public static double rosenbrock(double x, double y) {
                return (1 - x) * (1 - x) + 100 * (y - x * x) * (y - x * x);
        }

        public static List<double[]> randomSearchMinimization(double lowerBoundX, double upperBoundX, double lowerBoundY, double upperBoundY, int iterations, boolean isEllipsoid, double[] startPoint, double stepSize, double epsilon) {
                List<double[]> searchPoints = new ArrayList<>();
                Random random = new Random();

                double bestX = startPoint[0];
                double bestY = startPoint[1];
                double bestValue = isEllipsoid ? ellipsoid(bestX, bestY) : rosenbrock(bestX, bestY);

                searchPoints.add(new double[]{bestX, bestY});
                System.out.printf("Iteration 1: x=%.4f, y=%.4f, value=%.8f%n", bestX, bestY, bestValue);

                for (int i = 1; i < iterations; i++) {
                        //double x = bestX + stepSize * (random.nextDouble() * 2 - 1);
                        //double y = bestY + stepSize * (random.nextDouble() * 2 - 1);
                        double angle = random.nextDouble() * 2 * Math.PI;

                        //вычисляем координаты на плоскости со лучайным углом и используя шаг
                        double x = bestX + stepSize * Math.cos(angle);
                        double y = bestY + stepSize * Math.sin(angle);
                        double currentValue = isEllipsoid ? ellipsoid(x, y) : rosenbrock(x, y);

                        if (currentValue < bestValue) {
                                double diff = bestValue - currentValue;
                                if (diff < epsilon) {
                                        break;
                                }
                                bestX = x;
                                bestY = y;
                                bestValue = currentValue;
                                searchPoints.add(new double[]{bestX, bestY});
                                System.out.printf("Iteration %d: x=%.4f, y=%.4f, value=%.8f%n", i + 1, bestX, bestY, bestValue);
                        } else if (i == iterations - 1 && searchPoints.size() == 1) {
                                // Если метод не нашел более оптимальной точки после всех итераций, завершаем поиск
                                System.out.println("Search ended: no better point found.");
                                break;

                        } else if (i == iterations - 1) {
                                // Если достигнут лимит итераций и найдена более оптимальная точка, завершаем поиск
                                System.out.println("Search ended: limit reached.");
                                break;
                        }
                }
                return searchPoints;
        }

        public static void main(String[] args) {

                double lowerBoundX = -1000;
                double upperBoundX = 1000;
                double lowerBoundY = -1000;
                double upperBoundY = 1000;
                int iterations = 10000;

                //true для эллипсоида (0,0) , false для Розенброка (1.1)
                boolean isEllipsoidFunction = true;

                double[] startPoint = {1, 2};
                double stepSize = 0.06;
                double epsilon = 0.0001;

                List<double[]> searchPoints = randomSearchMinimization(lowerBoundX, upperBoundX, lowerBoundY, upperBoundY, iterations, isEllipsoidFunction, startPoint, stepSize, epsilon);
                double[] xData = new double[searchPoints.size()];
                double[] yData = new double[searchPoints.size()];

                for (int i = 0; i < searchPoints.size(); i++) {
                        xData[i] = searchPoints.get(i)[0];
                        yData[i] = searchPoints.get(i)[1];
                }

                // Создание и отображение графика
                XYChart chart = new XYChartBuilder().width(800).height(600).title("Random Search Trajectory").xAxisTitle("X").yAxisTitle("Y").build();
                XYSeries series = chart.addSeries("Search Points", xData, yData);
                series.setMarker(SeriesMarkers.CIRCLE);
                series.setLineStyle(SeriesLines.SOLID);

                new SwingWrapper<>(chart).displayChart();
        }
}