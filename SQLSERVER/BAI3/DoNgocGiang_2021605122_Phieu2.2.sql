create database MarkManagement

go
use MarkManagement

create table Students(
	StudentID nvarchar(12) not null primary key,
	StudentName nvarchar(25) not null,
	DateofBirth datetime not null,
	Email nvarchar(40),
	Phone nvarchar(12),
	Class nvarchar(10)
)

create table Subjects(
	SubjectID nvarchar(10) not null primary key,
	SubjectName nvarchar(25) not null
)

create table Mark(
	StudentID nvarchar(12) not null,
	SubjectID nvarchar(10) not null,
	Date datetime,
	Theory tinyint,
	Practical tinyint,
	primary key(StudentID, SubjectID) 
)

insert into Students values
	('AV0807005', N'Mail Trung Hiếu', '11/10/1989', 'trunghieu@yahoo.com', '0904115116', 'AV1'),
	('AV0807006', N'Nguyễn Quý Hùng ', '2/12/1988', 'quyhung@yahoo.com', '0986757463', 'AV2'),
	('AV0807007', N'Đỗ Đắc Huỳnh', '2/1/1990', 'dachuynh@yahoo.com', '0986757463', 'AV2'),
	('AV0807008', N'An Đăng Khuê', '6/3/1986', 'dangkhue@yahoo.com', '0986757463', 'AV1'),
	('AV0807009', N'Nguyễn T. Tuyết Lan', '12/7/1989', 'tuyetlan@yahoo.com', '0983310342', 'AV2'),
	('AV0807010', N'Đinh Phụng Long', '2/12/1990', 'phunglong@yahoo.com', '0904115116', 'AV1'),
	('AV0807011', N'Nguyễn Tuấn Nam', '2/3/1990', 'tuannam@yahoo.com', '0904115116', 'AV1')

insert into Subjects values
	('S001', 'SQL'),
	('S002', 'Java Simplefield'),
	('S003', 'Active Server Page')

insert into Mark values
	('AV0807005', 'S001','6/5/2008', 8, 25),
	('AV0807006', 'S002', '6/5/2008', 16, 30),
	('AV0807007', 'S001', '6/5/2008', 10, 25),
	('AV0807009', 'S003', '6/5/2008', 7, 13),
	('AV0807010', 'S003', '6/5/2008', 9, 16),
	('AV0807011', 'S002', '6/5/2008', 8, 30),
	('AV0807012', 'S001', '6/5/2008', 7, 31),
	('AV0807005', 'S002', '6/6/2008', 12, 11),
	('AV0807010', 'S001', '6/6/2008', 7, 6)

-- 4.1 Hiển thị nội dung bảng Students
select * from Students

-- 4.2 Hiển thị nội dung danh sách sinh viên lớp AV1
select * from Students
where Class = 'AV1'

-- 4.3 Sử dụng lệnh UPDATE để chuyển sinh viên có mã AV0807012 sang lớp AV2
update Students
set Class = 'AV2'
where StudentID = 'AV0807012'

-- 4.4 Tính tổng số sinh viên của từng lớp
select Class, count(StudentID) as 'So luong hs'
from Students
group by Class

-- 4.5 Hiển thị danh sách sinh viên lớp AV2 được sắp xếp tăng dần theo StudentName
select * from Students
where Class = 'AV2'
order by StudentName asc

-- 4.6 Hiển thị danh sách sinh viên không đạt lý thuyết môn S001 (theory <10) thi ngày 6/5/2008
select * from Students
where StudentID in (select StudentID from Mark
					where SubjectID = 'S001' and Theory < 10 and Date = 6/5/2008)

-- 4.7 Hiển thị tổng số sinh viên không đạt lý thuyết môn S001. (theory <10)
select count(StudentID) as 'So hoc sinh' from Mark
where SubjectID = 'S001' and Theory < 10

-- 4.8 Hiển thị Danh sách sinh viên học lớp AV1 và sinh sau ngày 1/1/1980
select * from Students
where DateofBirth = '1/1/1980' and Class = 'AV1'

-- 4.9 Xoá sinh viên có mã AV0807011

-- 4.10 StudentID, StudentName, SubjectName, Theory
--				Practical, Date mã S001 ngày 6/5/2008

select Students.StudentID, StudentName, SubjectName
		Theory, Practical, Date
from Students 
inner join Mark
on Students.StudentID = Mark.StudentID
inner join Subjects
on Mark.SubjectID = Subjects.SubjectID
where Date = '6/5/2008' and Subjects.SubjectID = 'S001'