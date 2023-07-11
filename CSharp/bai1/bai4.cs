using System;

namespace Bai4
{
    class Program
    {
        static void Main(string[] args)
        {
            double bacLuong, ngayCong, phuCap;
            
            Console.Write("Nhập vào bậc lương: ");
            bacLuong = double.Parse(Console.ReadLine());

            Console.Write("Nhập vào số ngày công: ");
            ngayCong = double.Parse(Console.ReadLine());

            Console.Write("Nhập vào phụ cấp: ");
            phuCap = double.Parse(Console.ReadLine());

            double NCTL;

            if (ngayCong < 25)
            {
                NCTL = ngayCong;
            }
            else
            {
                NCTL = 25 + (ngayCong - 25) * 2;
            }

            double tienLinh = bacLuong * 1_490_000 * NCTL + phuCap;

            Console.WriteLine("Tiền thực lĩnh là: {0}", tienLinh);
        }
    }
}
