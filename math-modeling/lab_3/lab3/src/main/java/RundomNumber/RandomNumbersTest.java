import java.util.Random;
import java.util.Arrays;

public class RandomNumbersTest {
    public static void main(String[] args) {
        int n = 100000; // количество случайных чисел
        int numOfIntervals = 10; //  количество интервалов для гистограммы
        double[] count = new double[numOfIntervals];
        double sum = 0, sumOfSquares = 0;
        double mTheor = 0.5;

        Random random = new Random();

        for (int i = 0; i < n; i++) {
            double randValue = random.nextDouble();
            sum += randValue;
            sumOfSquares += Math.pow(randValue - mTheor, 2);

            int intervalIndex = (int) (randValue * numOfIntervals);
            count[intervalIndex]++;
        }

        double m = sum / n;
        double D = sumOfSquares / n;
        double sigma = Math.sqrt(D);

        System.out.println("Мат. ожидание: " + m);
        System.out.println("Дисперсия : " + D);
        System.out.println("Среднеквадратическое отклонение: " + sigma);

         for (int i = 0; i < numOfIntervals; i++) {
           double percentage = (count[i] / n) * 100;
           System.out.printf("Interval %d [%f, %f): %f%% (%d)%n", i, (double) i / numOfIntervals, (double) (i + 1) / numOfIntervals,percentage, (int)count[i]);
         }
    }
}
