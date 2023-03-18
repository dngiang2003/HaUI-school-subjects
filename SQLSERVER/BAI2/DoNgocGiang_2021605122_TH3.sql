create database DeptEmp

go
use DeptEmp

create table Department(
	DepartmentNo int not null primary key,
	DepartmentName nvarchar(25) not null,
	Location nvarchar(25) not null
)

create table Employee(
	EmpNo int not null primary key,
	Fname nvarchar(15) not null,
	Lname nvarchar(15) not null,
	Job nvarchar(25) not null,
	HireDate datetime not null,
	Salary numeric not null,
	Commision numeric not null,
	DepartmentNo int not null
	foreign key references Department(DepartmentNo)
)

insert into Department values
	(10, 'Accounting', 'Melbourne'),
	(20, 'Research', 'Adealide'),
	(30, 'Sales', 'Sydney'),
	(40, 'Operations', 'Perth')


insert into Employee values
	(1, 'John', 'Smith', 'Clerk', '11/12/1980', 800, 300, 20),
	(2, 'Peter', 'Allen', 'Salesman', '5/2/1981', 1600, 300, 30),
	(3, 'Kate', 'Ward', 'Salesman', '8/4/1981', 1250, 300, 30),
	(4, 'Jack', 'Jones', 'Manager', '2/1/1981', 2975, 300, 20),
	(5, 'Joe', 'Martin', 'Salesman', '2/8/1981', 1250, 300, 30)

select * from Department
where DepartmentNo >= 20

select * from Employee