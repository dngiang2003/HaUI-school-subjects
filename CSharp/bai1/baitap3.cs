using System;

namespace TamGiac
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Nhap vao do dai cac canh a, b, c cua tam giac:");
            double a = GetPositiveNumber("a");
            double b = GetPositiveNumber("b");
            double c = GetPositiveNumber("c");

            if (IsValidTriangle(a, b, c))
            {
                double perimeter = CalculatePerimeter(a, b, c);
                double area = CalculateArea(a, b, c);

                Console.WriteLine("Chu vi cua tam giac la: " + perimeter);
                Console.WriteLine("Dien tich cua tam giac la: " + area);
            }
            else
            {
                Console.WriteLine("Ba canh a, b, c khong tao thanh mot tam giac hop le.");
            }

            Console.ReadLine();
        }

        static double GetPositiveNumber(string sideName)
        {
            double number;
            while (true)
            {
                Console.Write($"Nhap vao do dai canh {sideName}: ");
                if (double.TryParse(Console.ReadLine(), out number) && number > 0)
                {
                    return number;
                }
                Console.WriteLine("Vui long nhap mot so duong.");
            }
        }

        static bool IsValidTriangle(double a, double b, double c)
        {
            return a + b > c && a + c > b && b + c > a;
        }

        static double CalculatePerimeter(double a, double b, double c)
        {
            return a + b + c;
        }

        static double CalculateArea(double a, double b, double c)
        {
            double p = (a + b + c) / 2;
            return Math.Sqrt(p * (p - a) * (p - b) * (p - c));
        }
    }
}
