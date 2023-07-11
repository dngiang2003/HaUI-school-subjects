using System;

namespace CanBacHai
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Nhap so a: ");
            double a = Convert.ToDouble(Console.ReadLine());

            Console.WriteLine("Nhap do chinh xac epsilon: ");
            double epsilon = Convert.ToDouble(Console.ReadLine());

            double squareRoot = CalculateSquareRoot(a, epsilon);

            Console.WriteLine("Can bac hai cua {0} la: {1}", a, squareRoot);
            Console.ReadLine();
        }

        static double CalculateSquareRoot(double a, double epsilon)
        {
            double x0 = a / 2; // Giá trị ban đầu

            while (true)
            {
                double x1 = 0.5 * (x0 + a / x0); // Công thức Newton-Raphson

                if (Math.Abs(x1 - x0) < epsilon) // Kiểm tra độ chính xác
                    return x1;

                x0 = x1;
            }
        }
    }
}
