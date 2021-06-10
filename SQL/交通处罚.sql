/*==============================================================*/
/* DBMS name:      MySQL 5.0                                    */
/* Created on:     2021/6/3 19:24:58                            */
/*==============================================================*/


drop table if exists P_v_p_r2;

drop table if exists c_vio_r;

drop table if exists 人员;

drop table if exists 处罚;

drop table if exists 汽车;

drop table if exists 警务信息;

drop table if exists 违章表;

drop table if exists 违规人员;

/*==============================================================*/
/* Table: P_v_p_r2                                              */
/*==============================================================*/
create table P_v_p_r2
(
   警察签字                 varchar(20) not null,
   违规人员签字               varchar(20) not null,
   primary key (警察签字, 违规人员签字)
);

/*==============================================================*/
/* Table: c_vio_r                                               */
/*==============================================================*/
create table c_vio_r
(
   机动车牌照号               varchar(10) not null,
   违章日期                 date not null,
   primary key (机动车牌照号, 违章日期)
);

/*==============================================================*/
/* Table: 人员                                                    */
/*==============================================================*/
create table 人员
(
   姓名                   varchar(20) not null,
   违规人员签字               varchar(20),
   机动车牌照号               varchar(10),
   驾照执照号                varchar(20),
   地址                   varchar(20),
   邮编                   varchar(20),
   电话                   varchar(20),
   primary key (姓名)
);

alter table 人员 comment '这是一个关于人员的表';

/*==============================================================*/
/* Table: 处罚                                                    */
/*==============================================================*/
create table 处罚
(
   警告                   char(10) not null,
   罚款                   char(10) not null,
   暂扣驾驶执照               char(10) not null,
   姓名                   varchar(20),
   primary key (警告, 罚款, 暂扣驾驶执照)
);

alter table 处罚 comment '这是关于处罚方式的表';

/*==============================================================*/
/* Table: 汽车                                                    */
/*==============================================================*/
create table 汽车
(
   机动车牌照号               varchar(10) not null,
   姓名                   varchar(20),
   型号                   varchar(10),
   制造厂                  varchar(20),
   生产日期                 datetime,
   primary key (机动车牌照号)
);

alter table 汽车 comment '这是关于汽车的表';

/*==============================================================*/
/* Table: 警务信息                                                  */
/*==============================================================*/
create table 警务信息
(
   警察签字                 varchar(20) not null,
   姓名                   varchar(20),
   警务编号                 varchar(20),
   primary key (警察签字)
);

alter table 警务信息 comment '这是关于执法者的信息';

/*==============================================================*/
/* Table: 违章表                                                   */
/*==============================================================*/
create table 违章表
(
   违章日期                 date not null,
   姓名                   varchar(20),
   时间                   time,
   违章地点                 varchar(20),
   违章记载                 varchar(20),
   primary key (违章日期)
);

alter table 违章表 comment '这是关于违章信息的表';

/*==============================================================*/
/* Table: 违规人员                                                  */
/*==============================================================*/
create table 违规人员
(
   违规人员签字               varchar(20) not null,
   姓名                   varchar(20),
   primary key (违规人员签字)
);

alter table 违规人员 comment '违规人员签字';

alter table P_v_p_r2 add constraint FK_P_v_p_r3 foreign key (警察签字)
      references 警务信息 (警察签字) on delete restrict on update restrict;

alter table P_v_p_r2 add constraint FK_P_v_p_r4 foreign key (违规人员签字)
      references 违规人员 (违规人员签字) on delete restrict on update restrict;

alter table c_vio_r add constraint FK_c_vio_r foreign key (机动车牌照号)
      references 汽车 (机动车牌照号) on delete restrict on update restrict;

alter table c_vio_r add constraint FK_c_vio_r2 foreign key (违章日期)
      references 违章表 (违章日期) on delete restrict on update restrict;

alter table 人员 add constraint FK_p_c_r foreign key (机动车牌照号)
      references 汽车 (机动车牌照号) on delete restrict on update restrict;

alter table 人员 add constraint FK_p_v_p_r foreign key (违规人员签字)
      references 违规人员 (违规人员签字) on delete restrict on update restrict;

alter table 处罚 add constraint FK_p_pun_r foreign key (姓名)
      references 人员 (姓名) on delete restrict on update restrict;

alter table 汽车 add constraint FK_p_c_r2 foreign key (姓名)
      references 人员 (姓名) on delete restrict on update restrict;

alter table 警务信息 add constraint FK_p_po_r foreign key (姓名)
      references 人员 (姓名) on delete restrict on update restrict;

alter table 违章表 add constraint FK_p_v_r foreign key (姓名)
      references 人员 (姓名) on delete restrict on update restrict;

alter table 违规人员 add constraint FK_p_v_p_r2 foreign key (姓名)
      references 人员 (姓名) on delete restrict on update restrict;


