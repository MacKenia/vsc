/*==============================================================*/
/* DBMS name:      MySQL 5.0                                    */
/* Created on:     2021/6/3 10:46:18                            */
/*==============================================================*/


drop table if exists user_book_r;

drop table if exists �鼮��;

drop table if exists �û���;

drop table if exists ������ϸ��;

drop table if exists ������;

/*==============================================================*/
/* Table: user_book_r                                           */
/*==============================================================*/
create table user_book_r
(
   �û����                 numeric(20,0) not null,
   �鼮���                 varchar(20) not null,
   primary key (�û����, �鼮���)
);

alter table user_book_r comment '�û����鼮�Ĺ�ϵ';

/*==============================================================*/
/* Table: �鼮��                                                   */
/*==============================================================*/
create table �鼮��
(
   �鼮���                 varchar(20) not null,
   �������                 numeric(20,0),
   �鼮����                 varchar(20),
   �鼮�۸�                 float(8,2),
   primary key (�鼮���)
);

alter table �鼮�� comment '���ǹ����鼮��Ϣ�ı��';

/*==============================================================*/
/* Table: �û���                                                   */
/*==============================================================*/
create table �û���
(
   �û����                 numeric(20,0) not null,
   �û���                  varchar(20),
   �Ա�                   numeric(1,0),
   primary key (�û����)
);

alter table �û��� comment '���ǹ����û���Ϣ�ı��';

/*==============================================================*/
/* Table: ������ϸ��                                                 */
/*==============================================================*/
create table ������ϸ��
(
   ������ϸ���               numeric(20,0) not null,
   �û����                 numeric(20,0),
   �������                 numeric(20,0),
   �鼮����                 numeric(10,0),
   primary key (������ϸ���)
);

alter table ������ϸ�� comment '���ǹ��ڶ�����ϸ�ı��';

/*==============================================================*/
/* Table: ������                                                   */
/*==============================================================*/
create table ������
(
   �������                 numeric(20,0) not null,
   �鼮���                 varchar(20),
   �鼮��_�鼮���             varchar(20),
   �鼮��_�鼮���2            varchar(20),
   ������ϸ���               numeric(20,0),
   �û����                 numeric(20,0),
   �µ�ʱ��                 datetime,
   �����ܼ�                 float(8,2),
   primary key (�������)
);

alter table ������ comment '���ǹ��ڶ����ı��';

alter table user_book_r add constraint FK_user_book_r foreign key (�û����)
      references �û��� (�û����) on delete restrict on update restrict;

alter table user_book_r add constraint FK_user_book_r2 foreign key (�鼮���)
      references �鼮�� (�鼮���) on delete restrict on update restrict;

alter table �鼮�� add constraint FK_book_order_r foreign key (�������)
      references ������ (�������) on delete restrict on update restrict;

alter table ������ϸ�� add constraint FK_order_item_r2 foreign key (�������)
      references ������ (�������) on delete restrict on update restrict;

alter table ������ϸ�� add constraint FK_user_item_r foreign key (�û����)
      references �û��� (�û����) on delete restrict on update restrict;

alter table ������ add constraint FK_Relationship_3 foreign key (�鼮��_�鼮���)
      references �鼮�� (�鼮���) on delete restrict on update restrict;

alter table ������ add constraint FK_Relationship_4 foreign key (�鼮��_�鼮���2)
      references �鼮�� (�鼮���) on delete restrict on update restrict;

alter table ������ add constraint FK_book_order_r2 foreign key (�鼮���)
      references �鼮�� (�鼮���) on delete restrict on update restrict;

alter table ������ add constraint FK_order_item_r foreign key (������ϸ���)
      references ������ϸ�� (������ϸ���) on delete restrict on update restrict;

alter table ������ add constraint FK_user_order_r foreign key (�û����)
      references �û��� (�û����) on delete restrict on update restrict;

