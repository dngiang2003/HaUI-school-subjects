-- tao database
create database TRUONGHOC
go
-- xoa database

-- su dung db
use TRUONGHOC
go

-- tao bang hoc sinh
create table HOCSINH(
	MAHS char(5),
	TEN nvarchar(30),
	NAM bit,
	NGAYSINH datetime,
	DIACHI varchar(20),
	DIEMTB float
)

--  tao bang GIAOVIEN
create table GIAOVIEN(
	MAGV char(5),
	TEN nvarchar(30),
	NAM bit,
	NGAYSINH datetime,
	DIACHI varchar(20),
	LUONG money
)

-- tao bang LOPHOC
create table LOPHOC(
	MALOP char(5),
	TENLOP nvarchar(30),
	SOLUONG int
)

insert dbo.HOCSINH values 
	('CS001' , N'VĂN A' , 1 ,'19940226', 'HANOI' ,9.0),
	('CS002' , N'KIM LONG' , 1 ,'19940226', 'DONGNAI' ,9.0),
	('CS003' , N'VĂN C' , 1 ,'19940226', 'HANOI' ,9.0),
	('CS004' , N'VĂN D' , 1 ,'19940226', 'HUNGYEN' ,9.0),
	('CS005' , N'VĂN E' , 1 ,'19940226', 'YENBAI' ,9.0)


select * from HOCSINH
select * from GIAOVIEN

--Ví dụ 1: Xóa tất cả dữ liệu trong Table HOCSINH, ta sử dụng lệnh:
delete dbo.HOCSINH

--Ví dụ 2: Xóa những giáo viên có lương hơn 5000:
delete dbo.GIAOVIEN where LUONG >5000

--Ví dụ 3: Xóa những giáo viên có lương hơn 5000 và mã số giáo viên <15
delete dbo.GIAOVIEN where LUONG > 5000 and MAGV < 15

--Ví dụ 4: Xóa những học sinh có điểm TB là 1; 8; 9.
delete dbo.HOCSINH where DIEMTB IN (1,8,9)

--Ví dụ 5: Xóa những học sinh có mã học sinh thuộc danh sách FD001, FD002, FD003
delete from dbo.HOCSINH where MAHS IN ('FD002','FD001', 'FD003')

--Ví dụ 6: Xóa những học sinh có điểm trong khoảng 1 đến 8
delete dbo.HOCSINH where DIEMTB between 1 and 8

--Ví dụ 7: Xóa những học sinh có địa chỉ không phải ở Đà Lạt.
delete dbo.HOCSINH where DIACHI not like '%DALAT%'

--update Record
--Ví dụ 1: Cập nhập Lương của tất cả giáo viên thành 10000
update dbo.GIAOVIEN set LUONG = 10000

--Ví dụ 2: Cập nhập lương của tất cả giáo viên thành 10000 và địa chỉ tại DALAT
update dbo.GIAOVIEN set LUONG = 10000, DIACHI ='DALAT'

--Ví dụ 3: Cập nhập lương của những giáo viên nam thành 1
update dbo.GIAOVIEN set LUONG = 1
where Nam = '1'