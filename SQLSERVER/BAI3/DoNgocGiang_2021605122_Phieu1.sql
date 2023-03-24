-- Tao CSDL ThucTap
create database ThucTap

-- tro den database de thao tac
go
use ThucTap

-- tao bang Khoa
create table Khoa(
	makhoa char(10) not null primary key,
	tenkhoa char(30) not null,
	dienthoai char(10) not null
)

-- tao bang GiangVien
create table GiangVien(
	magv int not null primary key,
	hotengv char(30) not null,
	luong decimal(5, 2) not null,
	makhoa char(10) not null foreign key references Khoa(makhoa)
)

-- tao bang sinh vien
create table SinhVien(
	masv int not null primary key,
	hotensv char(30) not null,
	makhoa char(10) not null foreign key references Khoa(makhoa),
	namsinh int not null,
	quequan char(30) not null
)

--  tao bang DeTai
create table DeTai(
	madt char(10) not null primary key,
	tendt char(10) not null,
	kinhphi int not null,
	NoiThucTap char(30) not null
)

-- tao bang HuongDan
create table HuongDan(
	masv int not null foreign key references SinhVien(masv),
	madt char(10) not null foreign key references DeTai(madt),
	magv int not null foreign key references GiangVien(magv),
	ketqua decimal(5, 2)
)

insert into Khoa values
	('K01', 'CNTT', '0912345678'),
	('K02', 'DIA LY', '0945678123'),
	('K03', 'QLTN', '0914725836'),
	('K04', 'Toan', '0914725836'),
	('K05', 'CONG NGHE SINH HOC', '0914725836')

insert into DeTai values
	('DT01', 'ABC', 500000, 'Ha Noi'),
	('DT02', 'DEF', 200000, 'Ha Noi'),
	('DT03', 'GHI', 250000, 'Ha Noi'),
	('DT04', 'KML', 100000, 'Ha Noi'),
	('DT05', 'XYZ', 950000, 'Ha Noi')

insert into GiangVien values
	(100, 'Nguyen Thi A', 50.0, 'K05'),
	(101, 'Nguyen Thi B', 55.0, 'K02'),
	(102, 'Nguyen Van C', 65.0, 'K01'),
	(103, 'Nguyen Van D', 45.0, 'K03'),
	(104, 'Nguyen Thi E', 50.0, 'K04')
	
insert into GiangVien values
	(105, 'Nguyen Thi F', 50.0, 'K05')

insert into SinhVien values
	(200, 'Sinh Vien A', 'K05', 2000, 'Ha Noi'),
	(201, 'Sinh Vien B', 'K02', 2000, 'Ha Noi'),
	(202, 'Le Van Son', 'K01', 2000, 'Ha Noi'),
	(203, 'Le Van Son', 'K05', 2000, 'Ha Noi'),
	(204, 'Nguyen Thi E', 'K04', 2000, 'Ha Noi')

insert into HuongDan values
	(202, 'DT02', 101, 9.2),
	(201, 'DT01', 100, 8.0),
	(200, 'DT03', 103, 7.5),
	(203, 'DT05', 104, 9.4),
	(204, 'DT04', 105, 8.2)

-- 2.1
select GiangVien.magv, GiangVien.hotengv, Khoa.tenkhoa 
from GiangVien
join Khoa on GiangVien.makhoa = Khoa.makhoa;

-- 2.2
select magv, hotengv, tenkhoa
from GiangVien inner join Khoa
on GiangVien.makhoa = Khoa.makhoa
where tenkhoa in ('DIA LY', 'QLTN')

-- 2.3
select count(masv) AS N'Số lượng'
from SinhVien
where makhoa in (select makhoa from Khoa where tenkhoa = 'CONG NGHE SINH HOC')

-- 2.4
select masv, hotensv, year(getdate()) - namsinh as N'Tuổi'
from SinhVien
where makhoa in (select makhoa from Khoa where tenkhoa = 'TOAN')

-- 2.5
select count(magv) as N'Số lượng'
from GiangVien
where makhoa in (select makhoa from Khoa where tenkhoa = 'CONG NGHE SINH HOC')

-- 2.6
select * from SinhVien
where masv not in (select masv from huongdan)

-- 2.7
select Khoa.makhoa, tenkhoa, count(magv) as N'Số lượng'
from Khoa inner join GiangVien
on Khoa.makhoa = GiangVien.makhoa
group by Khoa.makhoa, Khoa.tenkhoa

-- 2.8
select dienthoai
from Khoa inner join SinhVien
on Khoa.makhoa = SinhVien.makhoa
where SinhVien.hotensv = 'Le van son'

-- 2.8
select dienthoai
from Khoa
where makhoa in (select makhoa from SinhVien 
	where hotensv = 'Le van son' )