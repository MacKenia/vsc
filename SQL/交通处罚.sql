/*==============================================================*/
/* DBMS name:      MySQL 5.0                                    */
/* Created on:     2021/6/3 19:24:58                            */
/*==============================================================*/


drop table if exists P_v_p_r2;

drop table if exists c_vio_r;

drop table if exists ��Ա;

drop table if exists ����;

drop table if exists ����;

drop table if exists ������Ϣ;

drop table if exists Υ�±�;

drop table if exists Υ����Ա;

/*==============================================================*/
/* Table: P_v_p_r2                                              */
/*==============================================================*/
create table P_v_p_r2
(
   ����ǩ��                 varchar(20) not null,
   Υ����Աǩ��               varchar(20) not null,
   primary key (����ǩ��, Υ����Աǩ��)
);

/*==============================================================*/
/* Table: c_vio_r                                               */
/*==============================================================*/
create table c_vio_r
(
   ���������պ�               varchar(10) not null,
   Υ������                 date not null,
   primary key (���������պ�, Υ������)
);

/*==============================================================*/
/* Table: ��Ա                                                    */
/*==============================================================*/
create table ��Ա
(
   ����                   varchar(20) not null,
   Υ����Աǩ��               varchar(20),
   ���������պ�               varchar(10),
   ����ִ�պ�                varchar(20),
   ��ַ                   varchar(20),
   �ʱ�                   varchar(20),
   �绰                   varchar(20),
   primary key (����)
);

alter table ��Ա comment '����һ��������Ա�ı�';

/*==============================================================*/
/* Table: ����                                                    */
/*==============================================================*/
create table ����
(
   ����                   char(10) not null,
   ����                   char(10) not null,
   �ݿۼ�ʻִ��               char(10) not null,
   ����                   varchar(20),
   primary key (����, ����, �ݿۼ�ʻִ��)
);

alter table ���� comment '���ǹ��ڴ�����ʽ�ı�';

/*==============================================================*/
/* Table: ����                                                    */
/*==============================================================*/
create table ����
(
   ���������պ�               varchar(10) not null,
   ����                   varchar(20),
   �ͺ�                   varchar(10),
   ���쳧                  varchar(20),
   ��������                 datetime,
   primary key (���������պ�)
);

alter table ���� comment '���ǹ��������ı�';

/*==============================================================*/
/* Table: ������Ϣ                                                  */
/*==============================================================*/
create table ������Ϣ
(
   ����ǩ��                 varchar(20) not null,
   ����                   varchar(20),
   ������                 varchar(20),
   primary key (����ǩ��)
);

alter table ������Ϣ comment '���ǹ���ִ���ߵ���Ϣ';

/*==============================================================*/
/* Table: Υ�±�                                                   */
/*==============================================================*/
create table Υ�±�
(
   Υ������                 date not null,
   ����                   varchar(20),
   ʱ��                   time,
   Υ�µص�                 varchar(20),
   Υ�¼���                 varchar(20),
   primary key (Υ������)
);

alter table Υ�±� comment '���ǹ���Υ����Ϣ�ı�';

/*==============================================================*/
/* Table: Υ����Ա                                                  */
/*==============================================================*/
create table Υ����Ա
(
   Υ����Աǩ��               varchar(20) not null,
   ����                   varchar(20),
   primary key (Υ����Աǩ��)
);

alter table Υ����Ա comment 'Υ����Աǩ��';

alter table P_v_p_r2 add constraint FK_P_v_p_r3 foreign key (����ǩ��)
      references ������Ϣ (����ǩ��) on delete restrict on update restrict;

alter table P_v_p_r2 add constraint FK_P_v_p_r4 foreign key (Υ����Աǩ��)
      references Υ����Ա (Υ����Աǩ��) on delete restrict on update restrict;

alter table c_vio_r add constraint FK_c_vio_r foreign key (���������պ�)
      references ���� (���������պ�) on delete restrict on update restrict;

alter table c_vio_r add constraint FK_c_vio_r2 foreign key (Υ������)
      references Υ�±� (Υ������) on delete restrict on update restrict;

alter table ��Ա add constraint FK_p_c_r foreign key (���������պ�)
      references ���� (���������պ�) on delete restrict on update restrict;

alter table ��Ա add constraint FK_p_v_p_r foreign key (Υ����Աǩ��)
      references Υ����Ա (Υ����Աǩ��) on delete restrict on update restrict;

alter table ���� add constraint FK_p_pun_r foreign key (����)
      references ��Ա (����) on delete restrict on update restrict;

alter table ���� add constraint FK_p_c_r2 foreign key (����)
      references ��Ա (����) on delete restrict on update restrict;

alter table ������Ϣ add constraint FK_p_po_r foreign key (����)
      references ��Ա (����) on delete restrict on update restrict;

alter table Υ�±� add constraint FK_p_v_r foreign key (����)
      references ��Ա (����) on delete restrict on update restrict;

alter table Υ����Ա add constraint FK_p_v_p_r2 foreign key (����)
      references ��Ա (����) on delete restrict on update restrict;


