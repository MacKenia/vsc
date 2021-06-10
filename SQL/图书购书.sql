/*==============================================================*/
/* DBMS name:      MySQL 5.0                                    */
/* Created on:     2021/6/3 10:46:18                            */
/*==============================================================*/


drop table if exists user_book_r;

drop table if exists 书籍表;

drop table if exists 用户表;

drop table if exists 订单明细表;

drop table if exists 订单表;

/*==============================================================*/
/* Table: user_book_r                                           */
/*==============================================================*/
create table user_book_r
(
   用户编号                 numeric(20,0) not null,
   书籍编号                 varchar(20) not null,
   primary key (用户编号, 书籍编号)
);

alter table user_book_r comment '用户于书籍的关系';

/*==============================================================*/
/* Table: 书籍表                                                   */
/*==============================================================*/
create table 书籍表
(
   书籍编号                 varchar(20) not null,
   订单编号                 numeric(20,0),
   书籍名称                 varchar(20),
   书籍价格                 float(8,2),
   primary key (书籍编号)
);

alter table 书籍表 comment '这是关于书籍信息的表格';

/*==============================================================*/
/* Table: 用户表                                                   */
/*==============================================================*/
create table 用户表
(
   用户编号                 numeric(20,0) not null,
   用户名                  varchar(20),
   性别                   numeric(1,0),
   primary key (用户编号)
);

alter table 用户表 comment '这是关于用户信息的表格';

/*==============================================================*/
/* Table: 订单明细表                                                 */
/*==============================================================*/
create table 订单明细表
(
   订单明细编号               numeric(20,0) not null,
   用户编号                 numeric(20,0),
   订单编号                 numeric(20,0),
   书籍数量                 numeric(10,0),
   primary key (订单明细编号)
);

alter table 订单明细表 comment '这是关于订单明细的表格';

/*==============================================================*/
/* Table: 订单表                                                   */
/*==============================================================*/
create table 订单表
(
   订单编号                 numeric(20,0) not null,
   书籍编号                 varchar(20),
   书籍表_书籍编号             varchar(20),
   书籍表_书籍编号2            varchar(20),
   订单明细编号               numeric(20,0),
   用户编号                 numeric(20,0),
   下单时间                 datetime,
   订单总价                 float(8,2),
   primary key (订单编号)
);

alter table 订单表 comment '这是关于订单的表格';

alter table user_book_r add constraint FK_user_book_r foreign key (用户编号)
      references 用户表 (用户编号) on delete restrict on update restrict;

alter table user_book_r add constraint FK_user_book_r2 foreign key (书籍编号)
      references 书籍表 (书籍编号) on delete restrict on update restrict;

alter table 书籍表 add constraint FK_book_order_r foreign key (订单编号)
      references 订单表 (订单编号) on delete restrict on update restrict;

alter table 订单明细表 add constraint FK_order_item_r2 foreign key (订单编号)
      references 订单表 (订单编号) on delete restrict on update restrict;

alter table 订单明细表 add constraint FK_user_item_r foreign key (用户编号)
      references 用户表 (用户编号) on delete restrict on update restrict;

alter table 订单表 add constraint FK_Relationship_3 foreign key (书籍表_书籍编号)
      references 书籍表 (书籍编号) on delete restrict on update restrict;

alter table 订单表 add constraint FK_Relationship_4 foreign key (书籍表_书籍编号2)
      references 书籍表 (书籍编号) on delete restrict on update restrict;

alter table 订单表 add constraint FK_book_order_r2 foreign key (书籍编号)
      references 书籍表 (书籍编号) on delete restrict on update restrict;

alter table 订单表 add constraint FK_order_item_r foreign key (订单明细编号)
      references 订单明细表 (订单明细编号) on delete restrict on update restrict;

alter table 订单表 add constraint FK_user_order_r foreign key (用户编号)
      references 用户表 (用户编号) on delete restrict on update restrict;

