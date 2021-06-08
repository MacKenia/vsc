create sch ema teacher;
create table teacherinfo
(
    num int(10) PRIMARY KEY UNIQUE NOT NULL,
    name varchar(20) not null,
    sex varchar(4) not null,
    birthday datetime ,
    address varchar(50)
);
insert into teacherinfo values(1001,'张龙','男','1984-11-08','北京市昌平区');
insert into teacherinfo values(1002,'李梅','女','1970-01-21','北京市海淀区');
insert into teacherinfo values(1003,'王一丰','男','1976-10-30','北京市昌平区');
insert into teacherinfo values(1004,'赵六','男','1980-06-05','北京市顺义区');
delimiter .
create procedure teachernfo1(in teacherid int, in type int, out info varchar(20))