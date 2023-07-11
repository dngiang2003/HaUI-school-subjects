using System;

namespace Bai3b
{
    class Program
    {
        static void Main(string[] args)
        {
            double a, b, c;

            Console.Write("Nhập giá trị của a: ");
            a = double.Parse(Console.ReadLine());

            Console.Write("Nhập giá trị của b: ");
            b = double.Parse(Console.ReadLine());

            Console.Write("Nhập giá trị của c: ");
            c = double.Parse(Console.ReadLine());

            double delta = b * b - 4 * a * c;

            if (delta < 0)
            {
                Console.WriteLine("Phương trình vô nghiệm.");
            }
            else if (delta == 0)
            {
                double x = -b / (2 * a);
                Console.WriteLine("Phương trình có nghiệm kép: {0}", x);
            }
            else
            {
                double x1 = (-b + Math.Sqrt(delta)) / (2 * a);
                double x2 = (-b - Math.Sqrt(delta)) / (2 * a);
                Console.WriteLine("Phương trình có hai nghiệm phân biệt:");
                Console.WriteLine("x1 = {0}", x1);
                Console.WriteLine("x2 = {0}", x2);
            }
        }
    }
}
