-- tạo dữ liệu, bằng và insert dữ liệu tương tự phiếu 1

go
use ThucTap

-- 2.1
select madt, tendt
from DeTai
where madt in (select madt from HuongDan
					where magv in (select magv from GiangVien
							where hotengv = 'Tran son'))

-- 2.2
select tendt
from DeTai
where madt not in (select madt from HuongDan)

-- 2.3
select magv, hotengv, Khoa.tenkhoa
from GiangVien inner join Khoa
on GiangVien.makhoa = Khoa.makhoa
where magv in (select magv from HuongDan group by magv
										having count(masv) > 2)

-- 2.4 
select madt, tendt
from DeTai
where kinhphi = (select max(kinhphi) from DeTai)

-- 2.5
select madt, tendt
from DeTai
where madt in (select madt from HuongDan group by madt
										having count(masv) > 2)

-- 2.6
select Sinhvien.masv, hotensv, HuongDan.ketqua
from Sinhvien inner join HuongDan
on SinhVien.masv = HuongDan.masv
where Sinhvien.makhoa in (select makhoa from Khoa
							where tenkhoa in ('DIA LY', 'QLTN'))

-- 2.7
select tenKhoa, count(maSV) as N'Số lượng'
from Khoa inner join SinhVien
on Khoa.maKhoa = SinhVien.maKhoa
group by Khoa.maKhoa, tenKhoa

-- 2.8
select SinhVien.masv, hotensv, makhoa, namsinh, quequan
from SinhVien inner join HuongDan
on SinhVien.masv = HuongDan.masv
inner join DeTai
on HuongDan.madt = DeTai.madt
where quequan = NoiThucTap

-- 2.9
select * from SinhVien
where masv in (select masv from HuongDan
				where ketqua is null)

-- 2.10
select masv, hotensv from SinhVien
where masv in (select masv from HuongDan
				where ketqua = 0)