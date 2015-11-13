/*==============================================================*/
/* Nom de SGBD :  MySQL 5.0                                     */
/* Date de création :  29/10/2015 15:31:37                      */
/*==============================================================*/


drop table if exists ALIMENT;

drop table if exists INGREDIENT;

drop table if exists RECETTE;

drop table if exists RECETTE_PREFEREE;

drop table if exists SEXE;

drop table if exists SOUS_CATEGORIE;

drop table if exists SUPER_CATEGORIE;

drop table if exists UTILISATEUR;

/*==============================================================*/
/* Table : ALIMENT                                              */
/*==============================================================*/
create table ALIMENT
(
   ID_ALIMENT           int not null auto_increment,
   LIBELLE_ALIMENT      varchar(40) not null,
   primary key (ID_ALIMENT)
);

/*==============================================================*/
/* Table : INGREDIENT                                           */
/*==============================================================*/
create table INGREDIENT
(
   ID_RECETTE           bigint not null,
   ID_ALIMENT           bigint not null,
   primary key (ID_RECETTE, ID_ALIMENT)
);

/*==============================================================*/
/* Table : RECETTE                                              */
/*==============================================================*/
create table RECETTE
(
   ID_RECETTE           int not null auto_increment,
   TITRE                longtext not null,
   INGREDIENTS          longtext,
   PREPARATION          longtext,
   primary key (ID_RECETTE)
);

/*==============================================================*/
/* Table : RECETTE_PREFEREE                                     */
/*==============================================================*/
create table RECETTE_PREFEREE
(
   LOGIN                varchar(20) not null,
   ID_RECETTE           int not null auto_increment,
   primary key (ID_RECETTE, LOGIN)
);

/*==============================================================*/
/* Table : SEXE                                                 */
/*==============================================================*/
create table SEXE
(
   ID_SEXE              int not null auto_increment,
   LIBELLE_SEXE         varchar(20) not null,
   primary key (ID_SEXE)
);

/*==============================================================*/
/* Table : SOUS_CATEGORIE                                       */
/*==============================================================*/
create table SOUS_CATEGORIE
(
   ALI_ID_ALIMENT       bigint not null,
   ID_ALIMENT           bigint not null,
   primary key (ALI_ID_ALIMENT, ID_ALIMENT)
);

/*==============================================================*/
/* Table : SUPER_CATEGORIE                                      */
/*==============================================================*/
create table SUPER_CATEGORIE
(
   ALI_ID_ALIMENT       bigint not null,
   ID_ALIMENT           bigint not null,
   primary key (ALI_ID_ALIMENT, ID_ALIMENT)
);

/*==============================================================*/
/* Table : UTILISATEUR                                          */
/*==============================================================*/
create table UTILISATEUR
(
   LOGIN                varchar(20) not null,
   ID_SEXE              bigint not null,
   PASSWORD             varchar(32) not null,
   NOM                  varchar(20),
   PRENOM               varchar(20),
   primary key (LOGIN)
);

alter table INGREDIENT add constraint FK_A_POUR_ALIMENT foreign key (ID_ALIMENT)
      references ALIMENT (ID_ALIMENT) on delete restrict on update restrict;

alter table INGREDIENT add constraint FK_EST_DANS_RECETTE foreign key (ID_RECETTE)
      references RECETTE (ID_RECETTE) on delete restrict on update restrict;

alter table RECETTE_PREFEREE add constraint FK_RECETTE_PREFEREE_RECETTE foreign key (ID_RECETTE)
      references RECETTE (ID_RECETTE) on delete restrict on update restrict;

alter table RECETTE_PREFEREE add constraint FK_RECETTE_PREFEREE_UTILISATEUR foreign key (LOGIN)
      references UTILISATEUR (LOGIN) on delete restrict on update restrict;

alter table SOUS_CATEGORIE add constraint FK_SOUS_CATEGORIE_DESTINATIO foreign key (ALI_ID_ALIMENT)
      references ALIMENT (ID_ALIMENT) on delete restrict on update restrict;

alter table SOUS_CATEGORIE add constraint FK_SOUS_CATEGORIE_ORIGINE foreign key (ID_ALIMENT)
      references ALIMENT (ID_ALIMENT) on delete restrict on update restrict;

alter table SUPER_CATEGORIE add constraint FK_SUPER_CATEGORIE_DESTINATION foreign key (ALI_ID_ALIMENT)
      references ALIMENT (ID_ALIMENT) on delete restrict on update restrict;

alter table SUPER_CATEGORIE add constraint FK_SUPER_CATEGORIE_ORIGINE foreign key (ID_ALIMENT)
      references ALIMENT (ID_ALIMENT) on delete restrict on update restrict;

alter table UTILISATEUR add constraint FK_A_POUR_SEXE foreign key (ID_SEXE)
      references SEXE (ID_SEXE) on delete restrict on update restrict;

