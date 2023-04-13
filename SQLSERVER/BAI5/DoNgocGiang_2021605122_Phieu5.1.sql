-- tao database
create database TRUONGHOC
go

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