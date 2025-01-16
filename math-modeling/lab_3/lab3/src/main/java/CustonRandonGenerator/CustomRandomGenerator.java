
import java.util.Random;

public class CustomRandomGenerator {
    private static final int RANDOM_NUMS = 12;
    private Random random;

    public CustomRandomGenerator() {
        random = new Random();
    }

    public double generateNextRandom() {
        double v = 0;
        for (int i = 0; i < RANDOM_NUMS; i++) {
            v += random.nextDouble();
        }
        double m = RANDOM_NUMS / 2.0;
        double sigma = Math.sqrt(RANDOM_NUMS / 12.0);
        double z = (v - m) / sigma;
        return 0.749655 * z;
    }

}



