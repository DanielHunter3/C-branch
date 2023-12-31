namespace ConsoleApp_СS_Mystery
{
    class Programm
    {
        public static void Main()
        {
            List<string> list = new List<string>() { "+", "-", "*", "/", "^" };

            Console.Write("Enter a first number: ");
            double x = Convert.ToDouble(Console.ReadLine());

            Console.Write("Enter a symbal: ");
            string symbal = Console.ReadLine();

            bool is_bool = in_list(list, symbal);
            if (is_bool == false) { Environment.Exit(1); }

            Console.Write("Enter a second number: ");
            double y = Convert.ToDouble(Console.ReadLine());

            Math math = new Math(x, y);
            Console.WriteLine($"Result: {math.math_operations(symbal)}");

        }

        public static bool in_list(List<string> list, string str)
        {
            foreach (var i in list) { if (i ==  str) return true; }
            return false;
        }
    }

    class Math
    {
        private double x, y;

        public Math(double x, double y) { this.x = x; this.y = y; }

        public double math_operations(string symbal)
        {
            switch (symbal)
            {
                case "+": return x + y;
                case "-": return x - y;
                case "*": return x * y;
                case "/":
                    if (y == 0.0)
                    {
                        Environment.Exit(1);
                        return 0.0;
                    }
                    else return x / y;
                case "^": return MathF.Pow((float)x, (float)y);
            }
            return 0.0;
        }
    }
}