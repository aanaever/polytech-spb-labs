import java.util.Random;
public class CustomRandomGeneratorMuller {
    private Random random;

    public CustomRandomGeneratorMuller() {
        random = new Random();
    }

    public double[] generateRandomNumberMuller() {
        double r1 = random.nextDouble();
        double r2 = random.nextDouble();

        double z1 = Math.cos(2 * Math.PI * r1) * Math.sqrt(-2 * Math.log(r2));
        double z2 = Math.sin(2 * Math.PI * r1) * Math.sqrt(-2 * Math.log(r2));
        return new double[]{0.749655 * z1, 0.749655 * z2};

    }
}
