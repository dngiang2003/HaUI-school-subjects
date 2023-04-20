create database QLKHO

use QLKHO

create table TON (
	MaVT char(20) primary key,
	TenVT char(30),
	SoLuongT int
)

create table NHAP (
	SoHDN char(10),
	MaVT char(20),
	SoLuongN int,
	DonGiaN float,
	NgayN date,

	constraint pk_nhap primary key (SoHDN, MaVT),
	constraint fk_nhap foreign key (MaVT) references TON(MaVT)
)

create table XUAT (
	SoHDX char(10),
	MaVT char(20),
	SoLuongX int,
	DonGiaX float,
	NgayX date,

	constraint pk_xuat primary key (SoHDX, MaVT),
	constraint fk_xuat foreign key (MaVT) references TON(MaVT)
)

insert into TON values 
	('01', 'Banh ngot', 1),
	('02', 'Keo mut', 7),
	('03', 'Khan uot', 3),
	('04', 'Khau trang', 5),
	('05', 'Sua tam', 2)

insert into NHAP values
	('N01', '01', 20, 100, '01/04/2022'),
	('N02', '03', 15, 80, '02/04/2022'),
	('N03', '05', 6, 130, '03/04/2022')

insert into XUAT values
	('X01', '01', 20, 300, '04/04/2022'),
	('X02', '03', 15, 170, '05/04/2022')


-- cau 2: đưa ra tên vật tư số lượng tồn nhiều nhất
select top 1 * from TON
order by SoLuongT desc 

-- cau 3: dua ra cac vat tu co so luong xuat lon hon 100
select TON.MaVT, SoHDX, TenVT, SoLuongX from TON
inner join XUAT on TON.MaVT = XUAT.MaVT
where SoLuongX > 100

-- cau 4: Tạo view đưa ra tháng xuất, năm xuất, tổng số lượng xuất thống kê theo tháng và năm xuất
go
create view cau4
as
select month(NgayX) as 'Thang xuat', year(NgayX) as 'Nam xuat',
		sum(SoLuongX) as 'So luong xuat'
		from XUAT
		group by month(NgayX), year(NgayX)
go
select * from cau4

-- cau5:tạo view đưa ra mã vật tư. tên vật tư. số lượng nhập. số lượng xuất. đơn giá N. đơn giá X. ngày nhập. Ngày xuất
go
create view cau5
as
select TON.MaVT, TenVT, SoLuongN, DonGiaN, DonGiaX, NgayN, NgayX
from TON inner join NHAP on TON.MaVT = NHAP.MaVT
		inner join XUAT on TON.MaVT = XUAT.MaVT
go 
select * from cau5

-- cau 6:
go
create view cau6
as
select TON.MaVT, TenVT, sum(SoLuongN - SoLuongX + SoLuongT) as 'So luong con'
from TON inner join NHAP on TON.MaVT = NHAP.MaVT
		inner join XUAT on NHAP.MaVT = XUAT.MaVT
		group by TON.MaVT, TenVT

select * from cau6
go

