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

delete from TON from NHAP 
inner join TON on NHAP.MaVT = TON.MaVT
inner join XUAT on Xuat.MaVT = Ton.MaVT
where DonGiaX < DonGiaN

select * from TON

update XUAT
set NgayX = NgayN
from NHAP inner join XUAT
on NHAP.MaVT = XUAT.MaVT
where NHAP.MaVT = XUAT.MaVT and NgayX < NgayN 

select * from XUAT