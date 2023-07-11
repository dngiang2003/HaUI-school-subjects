using System;

namespace TongHop
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.Write("Nhập số nguyên m = ");
            int m = int.Parse(Console.ReadLine());
            Console.Write("Nhập số nguyên n = ");
            int n = int.Parse(Console.ReadLine());
            // Tìm ước chung lớn nhất của m và n
            int gcd = findGCD(m, n);
            // Rút gọn phân số
            m /= gcd;
            n /= gcd;
            Console.WriteLine("Phân số rút gọn {0}/{1} la: {2}/{3}", m * gcd, n * gcd, m, n);
        }

        // Hàm tìm ước chung lớn nhấ
        static int findGCD(int a, int b)
        {
            if (b == 0) return a;
            return findGCD(b, a % b);
        }
    }
}
