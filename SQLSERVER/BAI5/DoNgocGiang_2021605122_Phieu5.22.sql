-- tạo database QLSV
create database QLSV

-- sử dụng database
use QLSV
go

-- tạo bảng LOP
create table LOP (
	MaLop char(5) not null primary key,
	TenLop varchar(10) not null,
	Phong int,
)

-- tao bảng SV
create table SV (
	MaSV char(5) not null primary key,
	TenSV varchar(20) not null,
	MaLop char(5) not null,
	constraint FK_SV_LOP foreign key(MaLop) references LOP(MaLop)
)

-- thêm dữ liệu bảng LOP
insert into LOP values
	('1', 'CD', 1),
	('2', 'DH', 2),
	('3', 'LT', 2),
	('4', 'CH', 4)

-- thêm dữ liệu bảng SV
insert into SV values
	('1', 'A', '1'),
	('2', 'B', '2'),
	('3', 'C', '1'),
	('4', 'D', '3')

select * from LOP
select * from SV
go

-- Câu 1: Viết hàm thống kê xem mỗi lớp có bao nhiêu sinh viên 
-- với malop là tham số truyền vào từ bàn phím
create function thongke(@MaLop char(5))
returns int
as
begin
	declare @sl int
	select @sl = count(SV.MaSV)
	from SV inner join LOP
	on SV.MaLop = LOP.MaLop
	where LOP.MaLop = @MaLop
	group by LOP.TenLop
	return @sl
end
go
select dbo.thongke('2') as 'So luong SV'
go

create function getSVtheoLop(@TenLop varchar(10))
returns @bangSV table (MaSV char(5), TenSV varchar(10))
as
begin
	insert into @bangSV
		select MaSV, TenSV from SV
		where MaLop = (select MaLop from LOP
						where TenLop = @TenLop)
	return
end
go
select dbo.getSVtheoLop('CD') as 'Sinh Vien'
go
