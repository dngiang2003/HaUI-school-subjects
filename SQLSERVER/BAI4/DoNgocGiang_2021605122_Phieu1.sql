CREATE DATABASE QLBanHang;

GO
USE QLBanHang;

-- 1.1
CREATE TABLE HangSX(
	MaHangSX nchar(10) not null primary key,
	TenHang nvarchar(20) not null,
	DiaChi nvarchar(30) not null,
	SoDT nvarchar(20) not null,
	Email nvarchar(30)
)

-- 1.2
CREATE TABLE SanPham(
	MaSP nchar(10) not null primary key,
	MaHangSX nchar(10) not null Foreign Key References HangSX(MaHangSX),
	TenSP nvarchar(20) not null,
	SoLuong int,
	MauSac nvarchar(20) not null,
	GiaBan money not null,
	DonViTinh nchar(10),
	MoTa nvarchar(max)
)

-- 1.3
CREATE TABLE NhanVien(
	MaNV nchar(10) not null primary key,
	TenNV nvarchar(20) not null,
	GioiTinh nchar(10) not null,
	DiaChi nvarchar(30) not null,
	SoDT nvarchar(20) not null,
	Email nvarchar(30) not null,
	TenPhong nvarchar(30) not null
)

-- 1.4
CREATE TABLE PNhap(
	SoHDN nchar(10) not null primary key,
	NgayNhap date not null,
	MaNV nchar(10) not null foreign key references NhanVien(MaNV)
)

-- 1.5
CREATE TABLE Nhap(
	SoHDN nchar(10) not null primary key(SoHDN, MaSP)
	foreign key references PNhap(SoHDN),
	MaSP nchar(10) foreign key references SanPham(MaSP),
	SoLuongN int not null,
	DonGiaN money
)

-- 1.6
CREATE TABLE PXuat(
	SoHDX nchar(10) not null primary key,
	NgayXuat Date,
	MaNV nchar(10) not null foreign key references NhanVien(MaNV)
)

-- 1.7
CREATE TABLE Xuat(
	SoHDX nchar(10) not null primary key(SoHDX, MaSP)
	foreign key references PXuat(SoHDX),
	MaSP nchar(10) not null
	foreign key references SanPham(MaSP),
	SoLuongX int
)

-- 1.8
INSERT INTO HangSX VALUES
	('H01', 'SamSung', N'Korea', '011-08271717', 'ss@gmail.com.kr'),
	('H02', 'OPPO', N'China', '081-08626262', 'oppo@gmail.com.cn'),
	('H03', 'Vinfone', N'Việt Nam', '084-098262626', 'vf@gmail.com.vn')

-- 1.9
INSERT INTO NhanVien VALUES
	('NV01', N'Nguyễn Thị Thu', N'Nữ', 'Hà Nội','0982626521', 'thu@gmail.com', N'Kế toán'),
	('NV02', N'Lê Văn Nam', N'Nam', 'Bắc Ninh','0972525252', 'nam@gmail.com', N'Vật tư'),
	('NV03', N'Trần Hòa Bình', N'Nữ', 'Hà Nội','0972525252', 'hb@gmail.com', N'Kế toán')

-- 1.10
INSERT INTO SanPham VALUES
	('SP01', 'H02', 'F1 Plus', 100, 'Xám', 7000000, N'Chiếc', N'Hàng cận cao cấp'),
	('SP02', 'H01', 'Galaxy Note11', 50, 'Đỏ', 19000000, N'Chiếc', N'Hàng cao cấp'),
	('SP03', 'H02', 'F3 lite', 200, 'Nâu', 3000000, N'Chiếc', N'Hàng phổ thông'),
	('SP04', 'H03', 'Vjoy3', 200, 'Xám', 1500000, N'Chiếc', N'Hàng phổ thông'),
	('SP05', 'H01', 'Galaxy V21', 500, 'Nâu', 8000000, N'Chiếc', N'Hàng cận cao cấp')

-- 1.11
INSERT INTO PNhap VALUES
	('N01', '2/5/2019', 'NV01'),
	('N02', '4/7/2020', 'NV03'),
	('N03', '5/17/2020', 'NV03'),
	('N04', '3/22/2020', 'NV03'),
	('N05', '7/7/2020', 'NV01')

-- 1.12
INSERT INTO Nhap VALUES
	('N01', 'SP02', 10, 17000000),
	('N02', 'SP01', 30, 6000000),
	('N03', 'SP04', 20, 1200000),
	('N04', 'SP01', 10, 6200000),
	('N05', 'SP05', 20, 7000000)

-- 1.13
INSERT INTO PXuat VALUES
	('X01', '6/14/2020', 'NV02'),
	('X02', '3/5/2019', 'NV03'),
	('X03', '12/12/2020', 'NV01'),
	('X04', '6/2/2020', 'NV02'),
	('X05', '5/18/2020', 'NV01')

-- 1.14
INSERT INTO Xuat VALUES
	('X01', 'SP03', 5),
	('X02', 'SP02', 3),
	('X03', 'SP02', 1),
	('X04', 'SP03', 2),
	('X05', 'SP05', 1)

-- 1. Hiển thị thông tin các bảng dữ liệu trên
select * from SanPham
select * from HangSX
select * from NhanVien
select * from Nhap
select * from PNhap
select * from Xuat
select * from PXuat

-- 2. Đưa ra thông tin MaSP, TenSP, TenHang, SoLuong, MauSac, GiaBan, DonViTinh, MoTa
-- của các sản phẩm sắp xếp theo chiều giảm dần giá bán.
select MaSP, TenSP, SoLuong, MauSac, GiaBan, DonViTinh, MoTa 
from SanPham order by GiaBan desc

-- 3. Đưa ra thông tin các sản phẩm có trong cữa hàng do công ty có tên hãng là Samsung sản xuất.
select * from SanPham
where MaHangSX in (select MaHangSX from HangSX
						where TenHang = N'Samsung')

-- 4. Đưa ra thông tin các nhân viên Nữ ở phòng ‘Kế toán’
select * from NhanVien
where GioiTinh = N'Nữ' and TenPhong = N'Kế toán'

-- 5. Đưa ra thông tin phiếu nhập gồm: SoHDN, MaSP, TenSP, TenHang, SoLuongN, 
-- DonGiaN, TienNhap=SoLuongN*DonGiaN, MauSac, DonViTinh, NgayNhap, TenNV, 
-- TenPhong, sắp xếp theo chiều tăng dần của hóa đơn nhập
select Nhap.SoHDN, SanPham.MaSP, TenSP, TenHang, SoLuongN, DonGiaN, SoLuongN * DonGiaN as N'TienNhap', 
		MauSac, DonViTinh, NgayNhap, TenNV, TenPhong
from HangSX
inner join SanPham on HangSX.MaHangSX = SanPham.MaHangSX
inner join Nhap on SanPham.MaSP = Nhap.MaSP
inner join PNhap on Nhap.SoHDN = PNhap.SoHDN
inner join NhanVien on PNhap.MaNV = NhanVien.MaNV
order by SoHDN asc

-- 6. Đưa ra thông tin phiếu xuất gồm: SoHDX, MaSP, TenSP, TenHang, SoLuongX, 
-- GiaBan, tienxuat=SoLuongX*GiaBan, MauSac, DonViTinh, NgayXuat, TenNV, 
-- TenPhong trong tháng 06 năm 2020, sắp xếp theo chiều tăng dần của SoHDX.

select Xuat.SoHDX, SanPham.MaSP, TenSP, TenHang, SoLuongX, GiaBan, 
		SoLuongX * GiaBan as N'Tiền xuất', MauSac, 
		DonViTinh, NgayXuat, TenNV, TenPhong
from Xuat 
inner join SanPham on Xuat.MaSP = SanPham.MaSP
inner join PXuat on Xuat.SoHDX = PXuat.SoHDX 
inner join NhanVien on PXuat.MaNV = NhanVien.MaNV
inner join HangSX on SanPham.MaHangSX = HangSX.MaHangSX
where month(NgayXuat) = 6 and year(NgayXuat) = 2020
order by SoHDX asc