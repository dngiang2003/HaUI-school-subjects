﻿use master
go

create database QLBanHang
go

use QLBanHang

create table HangSX(
	MaHangSX nchar(10) not null primary key,
	TenHang nvarchar(20) not null,
	DiaChi nvarchar(30),
	soDT nvarchar(20),
	Email nvarchar(30)
)

create table SanPham(
	MaSP nchar(10) not null primary key,
	MaHangSX nchar(10) not null,
	TenSP nvarchar(20) not null,
	SoLuong int,
	MauSac nvarchar(20),
	GiaBan money,
	DonViTinh nchar(10),
	MoTa nvarchar(max),
	constraint FK_SP_MaHangSX foreign key(MaHangSX)
		references HangSX(MaHangSX)
)

create table NhanVien(
	MaNV nchar(10) not null primary key,
	TenNV nvarchar(20) not null,
	GioiTinh nchar(10),
	DiaChi nvarchar(30),
	SoDT nvarchar(20),
	Email nvarchar(30),
	TenPhong nvarchar(30)
)

create table PNhap(
	SoHDN nchar(10) not null primary key,
	NgayNhap date,
	MaNV nchar(10) not null,
	constraint FK_PN_MaNV foreign key(MaNV)
		references NhanVien(MaNV)
)

create table Nhap(
	SoHDN nchar(10) not null,
	MaSP nchar(10) not null,
	SoLuongN int,
	DonGiaN money,
	constraint PK_SoHDN_MaSP primary key(SoHDN, MaSP),
	constraint FK_Nhap_SoHDN foreign key(SoHDN)
		references PNhap(SoHDN),
	constraint FK_Nhap_MaSP foreign key(MaSP)
		references SanPham(MaSP)
)

create table PXuat(
	SoHDX nchar(10) not null primary key,
	NgayXuat date,
	MaNV nchar(10) not null,

	constraint FK_PX_MaNV foreign key(MaNV)
		references NhanVien(MaNV)
)

create table Xuat(
	SoHDX nchar(10) not null,
	MaSP nchar(10) not null,
	SoLuongX int,

	constraint PK_SoHDX_MaSP primary key(SoHDX, MaSP),
	constraint FK_Xuat_SoHDX foreign key(SoHDX)
		references PXuat(SoHDX),
	constraint FK_Xuat_MaSP foreign key(MaSP)
		references SanPham(MaSP)
)

go

insert into HangSX values
	('H01', 'Samsung', N'Korea', '011-08271717', 'ss@gmail.com.kr'),
	('H02', 'OPPO', N'China', '081-08626262', 'oppo@gmail.com.cn'),
	('H03', 'Vinfone', N'Việt nam', '084-098262626', 'vf@gmail.com.vn')

insert into SanPham values
	('SP01', 'H02', 'F1 Plus', 100, N'Xám', 7000000, N'Chiếc', N'Hàng cận cao cấp'),
	('SP02', 'H01', 'Galaxy Note11', 50, N'Đỏ', 19000000, N'Chiếc', N'Hàng cao cấp'),
	('SP03', 'H02', 'F3 lite', 200, N'Nâu', 3000000, N'Chiếc', N'Hàng phổ thông'),
	('SP04', 'H03', 'Vjoy3', 200, N'Xám', 1500000, N'Chiếc', N'Hàng phổ thông'),
	('SP05', 'H01', 'Galaxy V21', 500, N'Nâu', 8000000, N'Chiếc', N'Hàng cận cao cấp')

insert into NhanVien values
	('NV01', N'Nguyễn Thị Thu', N'Nữ', N'Hà Nội', '0982626521', 'thu@gmail.com', N'Kế toán'),
	('NV02',N'Lê Văn Nam',N'Nam',N'Bắc Ninh','0972525252','nam@gmail.com',N'Vật tư'),
	('NV03',N'Trần Hòa Bình',N'Nữ',N'Hà Nội','0328388388','hb@gmail.com',N'Kế toán')

insert into PNhap values
	('N01', '2019-2-5', 'NV01'),
	('N02', '2020-4-7', 'NV02'),
	('N03', '2019-5-17', 'NV02'),
	('N04', '2019-3-22', 'NV03'),
	('N05', '2019-7-7', 'NV01')


insert into Nhap values
	('N01', 'SP02', 10, 17000000),
	('N02', 'SP01', 30,  6000000),
	('N03', 'SP04', 20, 1200000),
	('N04', 'SP01', 10, 6200000),
	('N05', 'SP05', 20, 7000000)


insert into PXuat values
	('X01', '2020-6-14', 'NV02'),
	('X02', '2019-3-5', 'NV03'),
	('X03', '2019-12-12', 'NV01'),
	('X04', '2019-6-2', 'NV02'),
	('X05', '2019-5-18', 'NV01')


insert into Xuat values
	('X01', 'SP03', 5),
	('X02', 'SP01', 3),
	('X03', 'SP02', 1),
	('X04', 'SP03', 2),
	('X05', 'SP05', 1)

go

use QLBanHang
go
--a

select * from HangSX
select * from SanPham
select * from NhanVien
select * from PNhap
select * from Nhap
select * from PXuat
select * from Xuat

go

--a (1đ). Đưa ra các thông tin về các hóa đơn mà hãng Samsung đã nhập trong năm 2020,
--gồm: SoHDN, MaSP, TenSP, SoLuongN, DonGiaN, NgayNhap, TenNV, TenPhong.
CREATE VIEW Cau_a
AS
	SELECT Nhap.SoHDN, SanPham.MaSP, TenSP, SoLuongN, DonGiaN, NgayNhap, TenNV, TenPhong
	FROM Nhap
		INNER JOIN SanPham
			ON Nhap.MaSP = SanPham.MaSP
		INNER JOIN PNhap
			ON Nhap.SoHDN = PNhap.SoHDN
		INNER JOIN NhanVien
			ON NhanVien.MaNV = PNhap.MaNV
		INNER JOIN HangSX
			ON HangSX.MaHangSX = SanPham.MaHangSX
	WHERE TenHang = 'Samsung' and YEAR(NgayNhap) = 2020
go

SELECT * FROM Cau_a
go
--b (1đ). Đưa ra các thông tin sản phẩm có giá bán từ 100.000 đến 500.000 của hãng
--Samsung.
CREATE VIEW Cau_b
AS
	Select MaSP, TenSP, SoLuong, MauSac, GiaBan, DonViTinh, MoTa
	From SanPham
		Inner join HangSX on SanPham.MaHangSX = HangSX.MaHangSX
	Where TenHang = 'Samsung' And GiaBan Between 100000 And 500000
go

SELECT * FROM Cau_b
go

--c (1đ). Tính tổng tiền đã nhập trong năm 2020 của hãng Samsung.

Create view Cau_c
as
	Select Sum(SoLuongN*DonGiaN) As N'Tổng tiền nhập'
	From Nhap
		Inner join SanPham on Nhap.MaSP = SanPham.MaSP
		Inner join HangSX on SanPham.MaHangSX = HangSX.MaHangSX
		Inner join PNhap on Nhap.SoHDN=PNhap.SoHDN
	Where Year(NgayNhap)=2020 And TenHang = 'Samsung'

go

SELECT * FROM Cau_c
go

--d (1đ). Thống kê tổng tiền đã xuất trong ngày 14/06/2020.
Create view Cau_d
as
	Select Sum(SoLuongX*GiaBan) As N'Tổng tiền xuất'
	From Xuat
		Inner join SanPham on Xuat.MaSP = SanPham.MaSP
		Inner join PXuat on Xuat.SoHDX=PXuat.SoHDX
	Where NgayXuat = '06/14/2020'

go

SELECT * FROM Cau_d
go
--e (1đ). Đưa ra SoHDN, NgayNhap có tiền nhập phải trả cao nhất trong năm 2020.
Create view Cau_e
as
	Select Nhap.SoHDN,NgayNhap
	From Nhap
		Inner join PNhap on Nhap.SoHDN=PNhap.SoHDN
	Where Year(NgayNhap)=2020 
			And SoLuongN*DonGiaN =(Select Max(SoLuongN*DonGiaN)
										From Nhap Inner join PNhap
													on Nhap.SoHDN=PNhap.SoHDN
										Where Year(NgayNhap)=2020
									)
go

SELECT * FROM Cau_e
go

--f (1đ). Hãy thống kê xem mỗi hãng sản xuất có bao nhiêu loại sản phẩm
Create view Cau_f
as
	Select HangSX.MaHangSX, TenHang, Count(*) As N'Số lượng sp'
	From SanPham Inner join HangSX on SanPham.MaHangSX = HangSX.MaHangSX
	Group by HangSX.MaHangSX, TenHang
go

SELECT * FROM Cau_f
go
--g (1đ). Hãy thống kê xem tổng tiền nhập của mỗi sản phẩm trong năm 2020.
Create view Cau_g
as
	Select Sum(SoLuongX*GiaBan) As N'Tổng tiền xuất'
	From Xuat
		Inner join SanPham on Xuat.MaSP = SanPham.MaSP
		Inner join PXuat on Xuat.SoHDX=PXuat.SoHDX
	Where NgayXuat = '06/14/2020'

go

SELECT * FROM Cau_g
go
--h (1đ). Hãy thống kê các sản phẩm có tổng số lượng xuất năm 2020 là lớn hơn 10.000 sản
--phẩm của hãng Samsung.
Create view Cau_d
as
	Select Sum(SoLuongX*GiaBan) As N'Tổng tiền xuất'
	From Xuat
		Inner join SanPham on Xuat.MaSP = SanPham.MaSP
		Inner join PXuat on Xuat.SoHDX=PXuat.SoHDX
	Where NgayXuat = '06/14/2020'

go

SELECT * FROM Cau_d
go
--i (1đ). Thống kê số lượng nhân viên Nam của mỗi phòng ban.
Create view Cau_d
as
	Select Sum(SoLuongX*GiaBan) As N'Tổng tiền xuất'
	From Xuat
		Inner join SanPham on Xuat.MaSP = SanPham.MaSP
		Inner join PXuat on Xuat.SoHDX=PXuat.SoHDX
	Where NgayXuat = '06/14/2020'

go

SELECT * FROM Cau_d
go
--j (1đ). Thống kê tổng số lượng nhập của mỗi hãng sản xuất trong năm 2018.
Create view Cau_d
as
	Select Sum(SoLuongX*GiaBan) As N'Tổng tiền xuất'
	From Xuat
		Inner join SanPham on Xuat.MaSP = SanPham.MaSP
		Inner join PXuat on Xuat.SoHDX=PXuat.SoHDX
	Where NgayXuat = '06/14/2020'

go

SELECT * FROM Cau_d
go
--k (1đ). Hãy thống kê xem tổng lượng tiền xuất của mỗi nhân viên trong năm 2018 là bao
--nhiêu.
Create view Cau_d
as
	Select Sum(SoLuongX*GiaBan) As N'Tổng tiền xuất'
	From Xuat
		Inner join SanPham on Xuat.MaSP = SanPham.MaSP
		Inner join PXuat on Xuat.SoHDX=PXuat.SoHDX
	Where NgayXuat = '06/14/2020'

go

SELECT * FROM Cau_d
go