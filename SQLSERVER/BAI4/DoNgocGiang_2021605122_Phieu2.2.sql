-- tao database
create database QLBanHang

go
use QLBanHang

-- tao bang HangSX
create table HangSX(
	MaHangSX nchar(10) not null primary key,
	TenHang nvarchar(20),
	DiaChi nvarchar(30),
	SoDT nvarchar(20),
	Email nvarchar(30)
)

-- tao bang SanPham
create table SanPham(
	MaSP nchar(10) not null primary key,
	MaHangSX nchar(10) not null,
	TenSP nvarchar(20),
	SoLuong int,
	MauSac nvarchar(20),
	GiaBan money,
	DonViTinh nchar(10),
	MoTa nvarchar(max),
	constraint FK_SP_MaHangSX foreign key(MaHangSX)
		references HangSX(MaHangSX)
)

-- tao bang NhanVien
create table NhanVien(
	MaNV nchar(10) not null primary key,
	TenNV nvarchar(20),
	GioiTinh nchar(10),
	DiaChi nvarchar(30),
	SoDT nvarchar(20),
	Email nvarchar(30),
	TenPhong nvarchar(30)
)

-- tao bang Pnhap
create table PNhap(
	SoHDN nchar(10) not null primary key,
	NgayNhap Date,
	MaNV nchar(10),
	constraint FK_MaNV_PNhap foreign key (MaNV)
		references NhanVien(MaNV)
)

-- tao bang Nhap
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

-- tao bang PXuat
create table PXuat(
	SoHDX nchar(10) not null primary key,
	NgayXuat date,
	MaNV nchar(10) not null,
	constraint FK_PXuat_MaNV foreign key(MaNV)
		references NhanVien(MaNV)
)

-- tao bang Xuat
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

-- chen du lieu bang HangSX
insert into HangSX values
	('H01', 'Samsung', N'Korea', '011-08271717', 'ss@gmail.com.kr'),
	('H02', 'OPPO', N'China', '081-08626262', 'oppo@gmail.com.cn'),
	('H03', 'Vinfone', N'Việt nam', '084-098262626', 'vf@gmail.com.vn')

-- chen du lieu bang SanPham
insert into SanPham values
	('SP01', 'H02', 'F1 Plus', 100, N'Xám', 7000000, N'Chiếc', N'Hàng cận cao cấp'),
	('SP02', 'H01', 'Galaxy Note11', 50, N'Đỏ', 19000000, N'Chiếc', N'Hàng cao cấp'),
	('SP03', 'H02', 'F3 lite', 200, N'Nâu', 3000000, N'Chiếc', N'Hàng phổ thông'),
	('SP04', 'H03', 'Vjoy3', 200, N'Xám', 1500000, N'Chiếc', N'Hàng phổ thông'),
	('SP05', 'H01', 'Galaxy V21', 500, N'Nâu', 8000000, N'Chiếc', N'Hàng cận cao cấp')

-- chen du lieu bang NhanVien
insert into NhanVien values
	('NV01', N'Nguyễn Thị Thu', N'Nữ', N'Hà Nội', '0982626521', 'thu@gmail.com', N'Kế toán'),
	('NV02',N'Lê Văn Nam',N'Nam',N'Bắc Ninh','0972525252','nam@gmail.com',N'Vật tư'),
	('NV03',N'Trần Hòa Bình',N'Nữ',N'Hà Nội','0328388388','hb@gmail.com',N'Kế toán')

-- chen du lieu bang PNhap
insert into PNhap values
	('N01', '2019-2-5', 'NV01'),
	('N02', '2020-4-7', 'NV02'),
	('N03', '2019-5-17', 'NV02'),
	('N04', '2019-3-22', 'NV03'),
	('N05', '2019-7-7', 'NV01')

-- chen du lieu bang Nhap
insert into Nhap values
	('N01', 'SP02', 10, 17000000),
	('N02', 'SP01', 30,  6000000),
	('N03', 'SP04', 20, 1200000),
	('N04', 'SP01', 10, 6200000),
	('N05', 'SP05', 20, 7000000)

-- chen du lieu bang PXuat
insert into PXuat values
	('X01', '2020-6-14', 'NV02'),
	('X02', '2019-3-5', 'NV03'),
	('X03', '2019-12-12', 'NV01'),
	('X04', '2019-6-2', 'NV02'),
	('X05', '2019-5-18', 'NV01')

-- chen du lieu bang Xuat
insert into Xuat values
	('X01', 'SP03', 5),
	('X02', 'SP01', 3),
	('X03', 'SP02', 1),
	('X04', 'SP03', 2),
	('X05', 'SP05', 1)

-- 4.2.a Hãy Đưa ra tổng tiền nhập của mỗi nhân viên trong tháng 8 – năm 2018 có tổng giá trị lớn hơn 100.000
select sum(SoLuongN * DonGiaN) as 'Tong Tien Nhap', MaNV from Nhap
inner join PNhap on Nhap.SoHDN = PNhap.SoHDN
where month(NgayNhap) = 8 and year(NgayNhap) = 2018
group by MaNV
having sum(SoLuongN * DonGiaN) > 100000

-- 4.2.b Hãy Đưa ra danh sách các sản phẩm đã nhập nhưng chưa xuất bao giờ.
select SanPham.MaSP, TenSP from SanPham
inner join Nhap on SanPham.MaSP = nhap.MaSP
where SanPham.MaSP not in (select MaSP from Xuat)


-- 4.2.c  Hãy Đưa ra danh sách các sản phẩm đã nhập năm 2020 và đã xuất năm 2020.
select * from SanPham
where MaSP in (select MaSP from Nhap
	inner join PNhap on Nhap.SoHDN = PNhap.SoHDN
		where year(NgayNhap) = '2020')
and MaSP in (select MaSP from Xuat
	inner join PXuat on Xuat.SoHDX = PXuat.SoHDX
		where year(NgayXuat) = '2020')

-- 4.2.d  Hãy Đưa ra danh sách các nhân viên vừa nhập vừa xuất.
select * from NhanVien
where MaNV in (select MaNV from PNhap)
	and MaNV in (select MaNV from PXuat)

-- 4.2.e Hãy Đưa ra danh sách các nhân viên không tham gia việc nhập và xuất
select * from NhanVien
where MaNV in (select MaNV from PNhap)
	and MaNV not in (select MaNV from PXuat)

select * from NhanVien
where MaNV in (select MaNV from PNhap
			   except
			   select MaNV from PXuat)
	and MaNV in (select MaNV from PXuat
				except
				select MaNV from PNhap)
