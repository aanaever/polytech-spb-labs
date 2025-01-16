package com.example.demo;

import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.chart.LineChart;
import javafx.scene.chart.NumberAxis;
import javafx.scene.chart.XYChart;
import javafx.stage.Stage;

import java.util.ArrayList;

public class Graph extends Application {

    @Override
    public void start(Stage stage) throws Exception {

        // Создаем оси координат
        final NumberAxis xAxis = new NumberAxis();
        final NumberAxis yAxis = new NumberAxis();
        xAxis.setLabel("t");
        yAxis.setLabel("y(t)");

        // Создаем график
        final LineChart<Number, Number> lineChart = new LineChart<>(xAxis, yAxis);
        lineChart.setTitle("y = 3*Z1 - 15*Z2 + 18*Z3");

        // Добавляем точки на график
        XYChart.Series<Number, Number> series = new XYChart.Series<>();
        ArrayList<Double> xValues = new ArrayList<>();
        ArrayList<Double> yValues = new ArrayList<>();

        // Инициализация переменных
        double x = 5, k = 3, a1 = 3,
                a2 = 2, b1 = 4, b2 = 5;
        double Z1 = 0, Z2 = 0, Z3 = 0;
        double h = 0.05;
        double t = 0;

        while (t < 45) {
            double[] DZ = calculateNewValues(Z1, Z2, Z3, h);
            double DZ1 = DZ[0];
            double DZ2 = DZ[1];
            double DZ3 = DZ[2];
            double y = 3 * Z1 - 15 * Z2 + 18 * Z3;
            Z1 = DZ1;
            Z2 = DZ2;
            Z3 = DZ3;
            xValues.add(t);
            yValues.add(y);
            t += h;
            if (yValues.size() % 25 == 0) {
                System.out.printf("%.2f\t%.4f\n", t, y);
            }
        }

        for (int i = 0; i < xValues.size(); i++) {
            series.getData().add(new XYChart.Data<>(xValues.get(i), yValues.get(i)));
        }
        lineChart.getData().add(series);

        // Создаем сцену и добавляем график на нее
        Scene scene = new Scene(lineChart, 800, 600);
        stage.setScene(scene);
        stage.show();
    }

    public static double[] calculateNewValues(double z1, double z2, double z3, double h) {
        double dz1 = z1 + h * z2;
        double dz2 = z2 + h * z3;
        double dz3 = z3 + h * (5 - z1 -14 * z2 - 65 * z3)/ 100;
        return new double[] { dz1, dz2, dz3 };
    }

    public static void main(String[] args) {
        launch(args);
    }
}