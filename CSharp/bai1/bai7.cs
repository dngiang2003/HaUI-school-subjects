using System;

namespace Bai7
{
    class Program
    {
        static void Main()
        {
            Console.Write("Nhập vào một số nguyên dương: ");
            int n = Convert.ToInt32(Console.ReadLine());

            if (IsPrime(n))
                Console.WriteLine("{0} là số nguyên tố.", n);
            else
                Console.WriteLine("{0} không là số nguyên tố.", n);
        }

        static bool IsPrime(int number)
        {
            if (number <= 1)
                return false;

            for (int i = 2; i * i <= number; i++)
            {
                if (number % i == 0)
                    return false;
            }

            return true;
        }
    }
}
