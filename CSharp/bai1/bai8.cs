using System;

namespace Bai8
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Nhap vao mot so nguyen duong n:");
            int n = int.Parse(Console.ReadLine());

            Console.WriteLine("Cac so tu 1 den {0}, bo qua cac so chia het cho 5:", n);
            for (int i = 1; i <= n; i++)
            {
                if (i % 5 != 0)
                {
                    Console.WriteLine(i);
                }
            }

            Console.ReadLine();
        }
    }
}
