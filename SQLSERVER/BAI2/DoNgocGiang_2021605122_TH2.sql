create database MarkManagement;

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

select * from Students
select * from Subjects
select * from Mark

drop database MarkManagement;