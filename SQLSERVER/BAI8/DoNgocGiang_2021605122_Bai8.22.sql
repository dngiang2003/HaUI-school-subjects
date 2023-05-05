﻿use master
go
create database QLBanHang

go 
use QLBanHang
go
create table HangSX (
    MaHangSX nchar(10) not null primary key,
    TenHang nvarchar(30) not null,
    DiaChi nvarchar(50),
    SoDT nvarchar(20),
    Email nvarchar(30)
);

create table SanPham (
    MaSP nchar(10) not null primary key,
    MaHangSX nchar(10) not null,
    TenSP nvarchar(30) not null,
    SoLuong int,
    MauSac nvarchar(20),
	GiaBan money,
	DonViTinh nchar(10),
	MoTa nvarchar(max),
	constraint FK_SP_MaHangSX foreign key(maHangSX)
	references HangSX(maHangSX)
);

create table NhanVien(
	MaNV nchar(10) not null primary key,
	TenNV nvarchar(20),
	GioiTinh nchar(10),
	DiaChi nvarchar(30),
	SoDT nvarchar(20),
	Email nvarchar(30),
	TenPhong nvarchar(30)
);

create table PNhap(
	SoHDN nchar(10) not null primary key,
	NgayNhap Date,
	MaNV nchar(10),
	constraint FK_MaNV_PNhap foreign key (MaNV)
	references NhanVien(MaNV)
);

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
);

create table PXuat(
	SoHDX nchar(10) not null primary key,
	NgayXuat date,
	MaNV nchar(10) not null,
	constraint FK_PXuat_MaNV foreign key(MaNV)
	references NhanVien(MaNV)
);

create table Xuat(
	SoHDX nchar(10) not null,
	MaSP nchar(10) not null,
	SoLuongX int,
	constraint PK_SoHDX_MaSP primary key(SoHDX, maSP),
	constraint FK_Xuat_SoHDX foreign key(SoHDX)
	references PXuat(SoHDX),
	constraint FK_Xuat_MaSP foreign key(MaSP)
	references SanPham(MaSP)
);

-- Nhap du lieu:
insert into HangSX values
	('H01', 'Samsung', N'Korea', '011-08271717', 'ss@gmail.com.kr'),
	('H02', 'OPPO', N'China', '081-08626262', 'oppo@gmail.com.cn'),
	('H03', 'Vinfone', N'Việt nam', '084-098262626', 'vf@gmail.com.vn');

insert into SanPham values
	('SP01', 'H02', 'F1 Plus', 100, N'Xám', 7000000, N'Chiếc', N'Hàng cận cao cấp'),
	('SP02', 'H01', 'Galaxy Note11', 50, N'Đỏ', 19000000, N'Chiếc', N'Hàng cao cấp'),
	('SP03', 'H02', 'F3 lite', 200, N'Nâu', 3000000, N'Chiếc', N'Hàng phổ thông'),
	('SP04', 'H03', 'Vjoy3', 200, N'Xám', 1500000, N'Chiếc', N'Hàng phổ thông'),
	('SP05', 'H01', 'Galaxy V21', 500, N'Nâu', 8000000, N'Chiếc', N'Hàng cận cao cấp');

insert into NhanVien values
	('NV01', N'Nguyễn Thị Thu', N'Nữ', N'Hà Nội', '0982626521', 'thu@gmail.com', N'Kế toán'),
	('NV02',N'Lê Văn Nam',N'Nam',N'Bắc Ninh','0972525252','nam@gmail.com',N'Vật tư'),
	('NV03',N'Trần Hòa Bình',N'Nữ',N'Hà Nội','0328388388','hb@gmail.com',N'Kế toán');

insert into PNhap values
	('N01', '2019-2-5', 'NV01'),
	('N02', '2020-4-7', 'NV02'),
	('N03', '2019-5-17', 'NV02'),
	('N04', '2019-3-22', 'NV03'),
	('N05', '2019-7-7', 'NV01');

insert into Nhap values
	('N01', 'SP02', 10, 17000000),
	('N02', 'SP01', 30,  6000000),
	('N03', 'SP04', 20, 1200000),
	('N04', 'SP01', 10, 6200000),
	('N05', 'SP05', 20, 7000000);

insert into PXuat values
	('X01', '2020-6-14', 'NV02'),
	('X02', '2019-3-5', 'NV03'),
	('X03', '2019-12-12', 'NV01'),
	('X04', '2019-6-2', 'NV02'),
	('X05', '2019-5-18', 'NV01');

insert into Xuat values
	('X01', 'SP03', 5),
	('X02', 'SP01', 3),
	('X03', 'SP02', 1),
	('X04', 'SP03', 2),
	('X05', 'SP05', 1);

-- a: 
go 
create proc SP_NhapHangSX(@mahangsx nchar(10), @tenhang nvarchar(30), @diachi nvarchar(50), @sodt nvarchar(20), @email nvarchar(30))
as 
begin
   if(exists(select * from HangSX where HangSX.TenHang = @tenhang))
      print N'Tên hãng sản xuất đã tồn tại!'
    else 
      begin 
        insert into HangSX values(@mahangsx,@tenhang,@diachi,@sodt,@email)
        print N'Đã thêm hãng sản xuất!'
      end
end;

go 
exec SP_NhapHangSX 'H04', 'Apple', N'Mỹ', '0534653874', 'apple123@gmail.com';
select * from HangSX;

go
create proc SP_ThemHangSX(@MaH nchar(10), @TenH nvarchar(30),
							@DC nvarchar(50), @SoDT nvarchar(20),
							@Email nvarchar(30), @TraVe int output)

as
	begin
		if (not exists(select * from HangSX where TenHang = @TenH))
			begin
				set @TraVe = 0
				insert into HangSX values(@MaH, @TenH, @DC, @SoDT, @Email)
			end
		else
			set @TraVe = 1
		return @TraVe
	end

go
select * from HangSX
declare @Bien int
exec SP_ThemHangSX 'H001', 'May giat', 'Viet Nam', '0399912334', 'test@gmail.com' @Bien output
select @Bien



go
create proc SP_ThemNhap(@SoHDN nchar(10), @MaSP nchar(10), 
						@MaNV nchar(10), @NgayNhap date,
						@SoLuongN int, @DonGiaN money, @TraVe int output)
as
	begin
		if (not exists (select * from SanPham where MaSP = @MaSP))
			set @TraVe = 1
		else if (not exists (select * from NhanVien where MaNV = @MaNV))
			set @TraVe = 2
		else if (exists (select * from Nhap where SoHDN = @SoHDN))
			begin
				update Nhap set MaSP = @MaSP, MaNV = @MaNV, NgayNhap = @NgayNhap,
								SoLuongN = @SoLuongN, DonGiaN = @DonGiaN
				where SoHDN = @SoHDN
			end
		else
			begin
				insert into Nhap (SoHDN, MaSP, MaNV, NgayNhap, SoLuongN, DonGiaN)
				values (@SoHDN, @MaSP, @MaNV, @NgayNhap, @SoLuongN, @DonGiaN)
				set @TraVe = 0
			end
		return @TraVe
	end

select * from Nhap
declare @KetQua int
exec SP_ThemNhap 'N001', 'H03', 'NV01', '01-01-2023', 12, 300000, @KetQua output
select @KetQua


go
create proc ThemXuat(@SoHDX nchar(10), @MaSP nchar(10), 
					@MaNV nchar(10), @NgayXuat date, @SoLuongX int, 
					@TraVe int output)
as
	begin
		if (not exists (select * from SanPham where MaSP = @MaSP))
			set @TraVe = 1
		else if (not exists (select * from NhanVien where MaNV = @MaNV))
			set @TraVe = 2
		else if (@SoLuongX > (select SoLuong from SanPham where MaSP = @MaSP))
			set @TraVe = 3
		else 
			begin
				if (exists (select * from Xuat where SoHDX = @SoHDX))
					begin
						update Xuat set MaSP = @MaSP, 
						MaNV = @MaNV, NgayXuat = @NgayXuat, 
						SoLuongX = @SoLuongX
					end
				else
					begin
						insert into Xuat (SoHDX, MaSP, MaNV, NgayXuat, SoLuongX)
						values (@SoHDX, @MaSP, @MaNV, @NgayXuat, @SoLuongX)
						set @TraVe = 0
					end
			end
	end

select * from Xuat
declare @KetQua int
exec SP_ThemNhap 'X001', 'H03', 'NV01', '01-01-2023', 12, @KetQua output
select @KetQua
