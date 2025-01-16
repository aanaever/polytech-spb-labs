public class CustomRandomMullerTest {
    public static void main(String[] args) {
        int n = 100000;
        int numOfIntervals = 15;
        double[] intervals = new double[numOfIntervals];
        double mx = 0.0;
        double s = 0.749655;
        double MIN_VALUE = mx - 3 * s;
        double MAX_VALUE = mx + 3 * s;

        CustomRandomGeneratorMuller generator = new CustomRandomGeneratorMuller();

        double sum = 0;
        double sumOfSquares = 0;
        for (int i = 0; i < n / 2; i++) {
            double[] randValues = generator.generateRandomNumberMuller();
            for (double randValue : randValues) {
                sum += randValue;
                sumOfSquares += randValue * randValue;

                int intervalIndex = (int) ((randValue - MIN_VALUE) / (MAX_VALUE - MIN_VALUE) * numOfIntervals);
                if (intervalIndex >= 0 && intervalIndex < numOfIntervals) {
                    intervals[intervalIndex]++;
                }
            }
        }

        double m = sum / n;
        double D = (sumOfSquares / n ) - (m * m);
        double sigma = Math.sqrt(D);

        System.out.println("Математическое ожидание: " + m);
        System.out.println("Среднеквадратическое отклонение: " + sigma);

        for (int i = 0; i < numOfIntervals; i++) {
            double intervalStart = MIN_VALUE + i * (MAX_VALUE - MIN_VALUE) / numOfIntervals;
            double intervalEnd = MIN_VALUE + (i + 1) * (MAX_VALUE - MIN_VALUE) / numOfIntervals;
            double percentage = (intervals[i] / n ) * 100;
            System.out.printf("Interval %d [%f, %f): %f%% (%d)%n",
                    i, intervalStart, intervalEnd,
                    percentage, (int) intervals[i]);
        }
    }
}
