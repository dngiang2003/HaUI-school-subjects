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
	Commision numeric,
	DepartmentNo int not null
	foreign key references Department(DepartmentNo)
)

insert into Department values
	(10, 'Accounting', 'Melbourne'),
	(20, 'Research', 'Adealide'),
	(30, 'Sales', 'Sydney'),
	(40, 'Operations', 'Perth')

insert into Employee values
	(1, 'John', 'Smith', 'Clerk', '11/12/1980', 800, null, 20),
	(2, 'Peter', 'Allen', 'Salesman', '5/2/1981', 1600, 300, 30),
	(3, 'Kate', 'Ward', 'Salesman', '8/4/1981', 1250, 300, 30),
	(4, 'Jack', 'Jones', 'Manager', '2/1/1981', 2975, null, 20),
	(5, 'Joe', 'Martin', 'Salesman', '2/8/1981', 1250, 300, 30)

-- 4.1
select * from Department

-- 4.2
select * from Employee

-- 4.3
select EmpNo, Fname, Lname from Employee
where Fname like 'Kate%'

-- 4.4
select Fname + ' ' + Lname as 'Full name', Salary,
		Salary * 1.1 as 'New Salary'
from Employee

-- 4.5
select Fname, Lname, HireDate
from Employee
where year(HireDate) = 1981
order by Lname asc

-- 4.6
select avg(salary) as 'Luong TB',
		max(salary) as 'Luong cao nhat',
		min(salary) as 'Luong thap nhat'
from Employee
group by DepartmentNo

-- 4.7
select DepartmentNo, count(EmpNo) as 'So luong nguoi'
from Employee
group by DepartmentNo

-- 4.8
select Employee.DepartmentNo, DepartmentName, 
		Fname + ' ' + Lname as 'Full name', Job, Salary
from Employee
inner join Department
on Employee.DepartmentNo = Department.DepartmentNo

-- 4.9
select Department.DepartmentNo, DepartmentName, 
		Location, count(EmpNo) as 'So luong nguoi'
from Employee
inner join Department
on Employee.DepartmentNo = Department.DepartmentNo
group by Department.DepartmentNo, DepartmentName, Location

-- 4.10 giong 4.9