import java.util.Objects;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        String[] vec = { "+", "-", "*", "/", "^" };

        System.out.print("Enter a first number: ");
        Scanner scanner_num1 = new Scanner(System.in);
        double x = scanner_num1.nextDouble();

        System.out.print("Enter a symbal: ");
        Scanner scanner_symbal = new Scanner(System.in);
        String symbal = scanner_symbal.nextLine();

        boolean is_bool = in_array(vec, symbal);
        if (!is_bool) { System.exit(1); }

        System.out.print("Enter a second number: ");
        Scanner scanner_num2 = new Scanner(System.in);
        double y = scanner_num2.nextDouble();

        Calculator math = new Calculator(x, y);
        System.out.println("Result: " + math.math_operations(symbal));
    }

    public static boolean in_array(String[] vec, String str) {
        for (var i: vec) { if (Objects.equals(i, str)) { return true; } }
        return false;
    }
}

class Calculator {
    final private double x, y;
    
    Calculator(double x, double y) {
        this.x = x;
        this.y = y;
    }
    
    public double math_operations(String str) {
        if (Objects.equals(str, "+")) { return x + y; }
        else if (Objects.equals(str, "-")) { return x - y; }
        else if (Objects.equals(str, "*")) { return x * y; }
        else if (Objects.equals(str, "/")) {
            if (y == 0.0) {
                System.exit(1);
            }
            else { return x / y; }
        }
        else if (Objects.equals(str, "^")) { return Math.pow(x, y); }
        else { System.exit(1); }
        return 0.0;
    }
}