using System;

namespace Bai3a
{
    class Program
    {
        static void Main(string[] args)
        {
            double a, b;

            Console.Write("Nhập giá trị của a: ");
            a = double.Parse(Console.ReadLine());

            Console.Write("Nhập giá trị của b: ");
            b = double.Parse(Console.ReadLine());

            if (a == 0)
            {
                if (b == 0)
                    Console.WriteLine("Phương trình vô số nghiệm.");
                else
                    Console.WriteLine("Phương trình vô nghiệm.");
            }
            else
            {
                double x = -b / a;
                Console.WriteLine("Nghiệm của phương trình là: {0}", x);
            }
        }
    }
}