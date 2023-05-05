create database QLHS

go
use QLHS

create table Lop (
		TenLop varchar(10) not null primary key,
		GVCN nvarchar(30)
)

create table HocSinh (
	MaHS varchar(3) not null primary key,
	HoTen nvarchar(30) not null,
	NgaySinh date,
	GioiTinh bit,
	TenLop varchar(10)
	constraint FK_Lop_HocSinh foreign key(TenLop) references Lop(TenLop)
)

create table Diem (
	MaHS varchar(3) not null,
	Toan tinyint,
	Ly tinyint,
	Hoa tinyint
	constraint FK_HocSinh_Diem foreign key(MaHS) references HocSinh(MaHS)
)

insert into Lop values
	('CNTT01', N'Đỗ Ngọc Giang'),
	('CNTT02', N'Lê Thu Phương'),
	('CNTT03', N'Phạm Thị Chuyên')

insert into HocSinh values
	('001', N'Nguyễn Tường Lân', '2003-06-05', 1, 'CNTT03'),
	('002', N'Trần Minh Thái', '2003-10-08', 1, 'CNTT01'),
	('003', N'Nguyễn Từ Quảng', '2003-11-10', 1, 'CNTT02')

insert into Diem values
	('001', 7, 9, 8),
	('002', 9, 7, 6),
	('003', 6, 8, 9)

go
create view DanhSachDiem
as
	select Lop.TenLop, GVCN, HoTen, year(NgaySinh), Toan, Ly, Hoa
	from Lop inner join HocSinh on Lop.TenLop = HocSinh.TenLop
			inner join Diem on HocSinh.MaHS = Diem.MaHS
	where year(NgaySinh) = 2022
go

select * from DanhSachDiem
