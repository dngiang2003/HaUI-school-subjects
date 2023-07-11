using System;

namespace Bai2
{
    class Program
    {
        static void Main(string[] args)
        {
            double length, width;
            
            Console.Write("Nhập vào chiều dài của hình chữ nhật: ");
            length = double.Parse(Console.ReadLine());

            Console.Write("Nhập vào chiều rộng của hình chữ nhật: ");
            width = double.Parse(Console.ReadLine());

            double perimeter = 2 * (length + width);
            double area = length * width;

            Console.WriteLine("Chu vi của hình chữ nhật là: {0}", perimeter);
            Console.WriteLine("Diện tích của hình chữ nhật là: {0}", area);
        }
    }
}
