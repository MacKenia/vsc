

/*==============================================================*/
/* DBMS name:      MySQL 5.0                                    */
/* Created on:     2021/6/16 15:54:44                           */
/*==============================================================*/

drop table if exists users;

drop table if exists badusage;

drop table if exists cycle;

drop table if exists rent;

/*==============================================================*/
/* Table: users                                                 */
/*==============================================================*/
create table users
(
   userid               varchar(12) not null UNIQUE,
   grade                smallint,
   balance              float(8,2),
   violated             int,
   primary key (userid)
);

alter table users comment '用户信息';


/*==============================================================*/
/* Table: badusage                                              */
/*==============================================================*/
create table badusage
(
   userid               varchar(12) not null UNIQUE,
   time                 datetime,
   behaviour            smallint,
   pay                  float(8,2),
   primary key (userid),
   foreign key (userid) references users(userid)
);

alter table badusage comment '用于标记违规记录';

/*==============================================================*/
/* Table: cycle                                                 */
/*==============================================================*/
create table cycle
(
   cycleid              varchar(12) not null UNIQUE,
   battary              smallint,
   usedtimes            smallint,
   distance             int,
   primary key (cycleid)
);

alter table cycle comment '单车信息';

/*==============================================================*/
/* Table: rent                                                  */
/*==============================================================*/
create table rent
(
   userid               varchar(12) not null,
   cycleid              varchar(12) not null,
   stime                datetime,
   etime                datetime,
   distance             smallint,
   legal                bool,
   primary key (userid, cycleid),
   foreign key (cycleid) references cycle(cycleid),
   foreign key (userid) references users(userid)
);

alter table rent comment '租用关系';

alter table rent add constraint 被使用 foreign key (cycleid)
      references cycle (cycleid) on delete restrict on update restrict;

