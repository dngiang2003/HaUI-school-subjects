using System;

class Program
{
    static void Main()
    {
        Console.Write("Nhập vào một số nguyên từ 1 đến 7: ");
        int number = Convert.ToInt32(Console.ReadLine());

        string dayOfWeek;
        switch (number)
        {
            case 1:
                dayOfWeek = "Chủ nhật";
                break;
            case 2:
                dayOfWeek = "Thứ hai";
                break;
            case 3:
                dayOfWeek = "Thứ ba";
                break;
            case 4:
                dayOfWeek = "Thứ tư";
                break;
            case 5:
                dayOfWeek = "Thứ năm";
                break;
            case 6:
                dayOfWeek = "Thứ sáu";
                break;
            case 7:
                dayOfWeek = "Thứ bảy";
                break;
            default:
                dayOfWeek = "Số không hợp lệ";
                break;
        }

        Console.WriteLine("Thứ trong tuần tương ứng là: " + dayOfWeek);
    }
}
