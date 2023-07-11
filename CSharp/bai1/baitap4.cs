using System;

namespace XepLoaiHS
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.Write("Nhap ho ten hoc sinh: ");
            string hoTen = Console.ReadLine();

            Console.Write("Nhap diem thi cuoi ky: ");
            double diemThi = Convert.ToDouble(Console.ReadLine());

            string xepLoai = "";

            if (diemThi >= 8)
                xepLoai = "Giỏi";
            else if (diemThi >= 6.5)
                xepLoai = "Khá";
            else if (diemThi >= 5)
                xepLoai = "Trung bình";
            else
                xepLoai = "Yếu";

            Console.WriteLine("\nHọ tên học sinh: " + hoTen.ToUpper());
            Console.WriteLine("Kết quả xếp loại: " + xepLoai);

            Console.ReadLine();
        }
    }
}
