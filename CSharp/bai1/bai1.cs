using System;

namespace Bai1
{
    class Program
    {
        static void Main(string[] args)
        {
            int n;
            Console.Write("Nhập số nguyên n = ");
            n = int.Parse(Console.ReadLine());
            // kiểm tra tính chẵn lẻ
            if (n % 2 == 0)
                Console.WriteLine("{0} là số chẵn", n);
            else
                Console.WriteLine("{0} là số lẻ", n);
            // kiểm tra tính âm dương
            if (n > 0)
                Console.WriteLine("{0} là số dương", n);
            else if (n < 0)
                Console.WriteLine("{0} là số âm", n);
            else 
                Console.WriteLine("{0} không là số âm cũng không là số dương", n);
        }
    }
}