using System;

class Program
{
    static void Main()
    {
        int number;
        do
        {
            Console.Write("Nhập vào một số nguyên: ");
            number = Convert.ToInt32(Console.ReadLine());

            if (number <= 0)
            {
                Console.WriteLine("Số không hợp lệ. Vui lòng nhập lại!");
            }
        } while (number <= 0);

        Console.WriteLine("Số nguyên dương đã nhập là: " + number);
    }
}
