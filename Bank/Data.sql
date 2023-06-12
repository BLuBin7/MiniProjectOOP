use master;
if exists(select * 
          from sys.databases 
		  where name = 'Csdl_TuyenXeBuyt')
drop database Csdl_TuyenXeBuyt;
go
create database Csdl_TuyenXeBuyt;
go

use Csdl_TuyenXeBuyt;

create table DVVANHANH (
   MaDV			int not null,
   TenDonVi		varchar(70) not null,
   constraint PK_DVVANHANH primary key (MaDV)
);

create table TUYENBUYT (
   MaTB			int	not null,
   TenTuyen		varchar(50) not null,
   CuLy			int null,
   SoChuyen		int null,
   MaDV			int	not null,
   constraint PK_TUYENBUYT primary key (MaTB),
   constraint FK_TUYENBUYT_DVVANHANH foreign key (MaDV) references DVVANHANH (MaDV)
);

create table TRAMDUNG (
   MaTD        	int not null,
   TenTram      varchar(50) not null,
   Loai			varchar(20) not null,
   DiaDiem      varchar(70) null,
   constraint PK_TRAMDUNG primary key (MaTD)
);

create table LOTRINH (
   MaTB			int not null,
   ThuTuTram	int not null,
   MaTD			int not null,
   constraint PK_LOTRINH primary key (MaTB, ThuTuTram),
   constraint UK_LOTRINH unique (MaTB, MaTD),
   constraint FK_LOTRINH_TUYENBUYT foreign key (MaTB) references TUYENBUYT (MaTB),
   constraint FK_LOTRINH_TRAMDUNG foreign key (MaTD) references TRAMDUNG (MaTD)
);


-- Them dong bang DVVANHANH
insert into DVVANHANH values (1,'Cong ty TNHH Du lich, Dich vu Xay dung Bao Yen (Bao Yen Group)');
insert into DVVANHANH values (2,'HTX Van tai 19/5');
insert into DVVANHANH values (3,'HTX Van tai Xe buyt Quyet Thang');
insert into DVVANHANH values (4,'Cong ty Co phan Xe khach Sai Gon (SaigonBus)');
insert into DVVANHANH values (5,'Lien hiep HTX Van tai Thanh pho');
insert into DVVANHANH values (6,'HTX Van tai so 28');

-- Them dong bang TUYENBUYT
insert into TUYENBUYT values (1,'Ben Thanh - BX Cho Lon',8900,240,1);
insert into TUYENBUYT values (3,'Ben Thanh - Thanh Loc',20600,312,2);
insert into TUYENBUYT values (4,'Ben Thanh - BX An Suong',16420,303,1);
insert into TUYENBUYT values (6,'BX Cho Lon - Truong Dai hoc Nong Lam',26500,190,3);
insert into TUYENBUYT values (7,'BX Cho Lon - Go Vap',15500,150,4);
insert into TUYENBUYT values (18,'Ben Thanh - Cho Hiep Thanh',22730,200,2);

-- Them dong bang TRAMDUNG
insert into TRAMDUNG values (1,'Cong Truong Me Linh','Ben xe','Cong truong Me Linh Thi Sach, Quan 1');
insert into TRAMDUNG values (2,'Ben Bach Dang','Tru dung','21 Ton Duc Thang, Quan 1');
insert into TRAMDUNG values (3,'Cuc Hai Quan Thanh Pho','Nha cho','2-4 Ham Nghi, Quan 1');
insert into TRAMDUNG values (4,'Cho Cu','Nha cho','84 Ham Nghi, Quan 1');
insert into TRAMDUNG values (5,'Truong Cao Thang','Nha cho','122 Ham Nghi, Quan 1');
insert into TRAMDUNG values (6,'Cong ty Duong sat','Nha cho','136 Ham Nghi, Quan 1');
insert into TRAMDUNG values (7,'Ben Thanh B','Ben xe','Ben Thanh Pham Ngu Lao, Quan 1');
insert into TRAMDUNG values (8,'Truong Ernst Thalmann','Nha cho','8 Tran Hung Dao, Quan 1');
insert into TRAMDUNG values (9,'KTX Tran Hung Dao','Nha cho','10 Tran Hung Dao, Quan 1');
insert into TRAMDUNG values (10,'Rap Hung Dao','Nha cho','112 Tran Hung Dao, Quan 1');
insert into TRAMDUNG values (11,'Benh vien Rang Ham Mat','Nha cho','150 Tran Hung Dao, Quan 1');
insert into TRAMDUNG values (12,'Tran Dinh Xu','Tru dung','210 - 212 Tran Hung Dao, Quan 1');
insert into TRAMDUNG values (13,'Tong Cty Samco','Nha cho','262 Tran Hung Dao, Quan 1');
insert into TRAMDUNG values (14,'Cho Nanci','Tru dung','290 Tran Hung Dao, Quan 1');
insert into TRAMDUNG values (15,'Nguyen Bieu','Tru dung','454 Tran Hung Dao, Quan 5');
insert into TRAMDUNG values (16,'Truong Cao dang Kinh te Doi ngoai','Nha cho','520 Tran Hung Dao, Quan 5');
insert into TRAMDUNG values (17,'Tran Binh Trong','Tru dung','564 Tran Hung Dao, Quan 5');
insert into TRAMDUNG values (18,'Benh vien Chan thuong Chinh hinh','Nha cho','696 Tran Hung Dao, Quan 5');
insert into TRAMDUNG values (19,'Rap Dong Thap','Tru dung','780 Tran Hung Dao, Quan 5');
insert into TRAMDUNG values (20,'Rap Dong Da','Tru dung','882 Tran Hung Dao, Quan 5');
insert into TRAMDUNG values (21,'Dong Khanh','Tru dung','18 Tran Hung Dao, Quan 5');
insert into TRAMDUNG values (22,'Nha Van hoa Quan 5','Tru dung','388 Tran Phu, Quan 5');
insert into TRAMDUNG values (23,'Ngo Quyen','Bien treo','212 Tran Hung Dao, Quan 5');
insert into TRAMDUNG values (24,'Tan Da','Tru dung','274 Tran Hung Dao, Quan 5');
insert into TRAMDUNG values (25,'Trieu Quang Phuc','Tru dung','346 Tran Hung Dao, Quan 5');
insert into TRAMDUNG values (26,'Buu dien Quan 5','Bien treo','13-15 Chau Van Liem, Quan 5');
insert into TRAMDUNG values (27,'Hai Thuong Lan Ong','Tru dung','210-212 Hai Thuong Lan Ong, Quan 5');
insert into TRAMDUNG values (28,'Cho Kim Bien','Tru dung','5 Trang Tu, Quan 5');
insert into TRAMDUNG values (29,'Ben xe Cho Lon','Ben xe','GA HKXB CHO LON Le Quang Sung, Quan 5');
insert into TRAMDUNG values (30,'TDH xe buyt Sai Gon','Ben xe','TDH xe buyt Sai Gon- CV 23/9 Le Lai, Quan 1');
insert into TRAMDUNG values (31,'Ton That Tung','Nha cho','Doi dien 204 Le Lai, Quan 1');
insert into TRAMDUNG values (32,'Nguyen Thi Nghia','Nha cho','Doi dien 96 Le Lai, Quan 1');
insert into TRAMDUNG values (33,'Khach san New world','Nha cho','Doi dien 1A Pham Hong Thai Le Lai, Quan 1');
insert into TRAMDUNG values (34,'Ben Thanh D','Ben xe','Ben Thanh Pham Ngu Lao, Quan 1');
insert into TRAMDUNG values (35,'Ham Nghi','Nha cho','163 Ham Nghi, Quan 1');
insert into TRAMDUNG values (36,'Cho Cu','Nha cho','89A Ham Nghi, Quan 1');
insert into TRAMDUNG values (37,'Ho Tung Mau','Nha cho','67 Ham Nghi, Quan 1');
insert into TRAMDUNG values (38,'Ben Bach Dang','Nha cho','Ben thuy noi dia Thu Thiem Ton Duc Thang, Quan 1');
insert into TRAMDUNG values (39,'Cong Truong Me Linh','Tru dung','2 Hai Ba Trung, Quan 1');
insert into TRAMDUNG values (40,'Nha Hat Thanh Pho','O son','74/A2-74/A4 Hai Ba Trung, Quan 1');
insert into TRAMDUNG values (41,'Benh vien Nhi Dong 2','Nha cho','Doi dien 115Ter Hai Ba Trung, Quan 1');
insert into TRAMDUNG values (42,'Buu Dien Thanh Pho','Tru dung','86 Hai Ba Trung, Quan 1');
insert into TRAMDUNG values (43,'So Cong Thuong','Nha cho','142 Hai Ba Trung, Quan 1');
insert into TRAMDUNG values (44,'Cong vien Le Van Tam','Nha cho','Doi dien 245 Hai Ba Trung, Quan 1');
insert into TRAMDUNG values (45,'Nha tho Tan Dinh','Tru dung','298 Hai Ba Trung, Quan 1');
insert into TRAMDUNG values (46,'Cho Tan Dinh','Tru dung','372-374 Hai Ba Trung, Quan 1');
insert into TRAMDUNG values (47,'Cau Kieu','O son','28 - 30 Phan Dinh Phung, Quan Phu Nhuan');
insert into TRAMDUNG values (48,'Cho Phu Nhuan','O son','158 - 160 Phan Dinh Phung, Quan Phu Nhuan');
insert into TRAMDUNG values (49,'Truong Cao Dang Kinh te Doi ngoai','O son','312 - 314 Phan Dinh Phung, Quan Phu Nhuan');
insert into TRAMDUNG values (50,'Nga Tu Phu Nhuan','Tru dung','392 Nguyen Kiem, Quan Phu Nhuan');
insert into TRAMDUNG values (51,'Nha Truyen Thong','Tru dung','466 Nguyen Kiem, Quan Phu Nhuan');
insert into TRAMDUNG values (52,'Nga ba Ho Van Hue','Tru dung','582 Nguyen Kiem, Quan Phu Nhuan');
insert into TRAMDUNG values (53,'Coop Mart Nguyen Kiem','Tru dung','668-670 Nguyen Kiem, Quan Phu Nhuan');
insert into TRAMDUNG values (54,'Chua Van Hanh','Nha cho','750 Nguyen Kiem, Quan Phu Nhuan');
insert into TRAMDUNG values (55,'Truong Cao dang Hai Quan','Nha cho','780A Nguyen Kiem, Quan Go Vap');
insert into TRAMDUNG values (56,'Tram dau Nguyen Thai Son','Tru dung','36 Nguyen Thai Son, Quan Go Vap');
insert into TRAMDUNG values (57,'Benh Vien 175','Tru dung','90 Nguyen Thai Son, Quan Go Vap');
insert into TRAMDUNG values (58,'Nga Ba Pham Ngu Lao','Tru dung','182 (148B) Nguyen Thai Son, Quan Go Vap');
insert into TRAMDUNG values (59,'Nha Tang Le','Bien treo','220 (175) Pham Ngu Lao , Quan Go Vap');
insert into TRAMDUNG values (60,'Sieu Thi Big C','Bien treo','72 (45) Pham Ngu Lao , Quan Go Vap');
insert into TRAMDUNG values (61,'Sieu thi Van Lang','Tru dung','36 Nguyen Oanh, Quan Go Vap');
insert into TRAMDUNG values (62,'Nga Tu Phan Van Tri','Tru dung','150 Nguyen Oanh, Quan Go Vap');
insert into TRAMDUNG values (63,'Doanh trai Quan doi','Nha cho','152 Nguyen Oanh, Quan Go Vap');
insert into TRAMDUNG values (64,'Cu xa Lam Son','Nha cho','214 Nguyen Oanh, Quan Go Vap');
insert into TRAMDUNG values (65,'Dai Liet si','Nha cho','Doi dien 197 (93) Nguyen Oanh, Quan Go Vap');
insert into TRAMDUNG values (66,'Nga tu An Nhon','Tru dung','388 Nguyen Oanh, Quan Go Vap');
insert into TRAMDUNG values (67,'Ben Do','Tru dung','530 Nguyen Oanh, Quan Go Vap');
insert into TRAMDUNG values (68,'Cau An Loc','Tru dung','604 Nguyen Oanh, Quan Go Vap');
insert into TRAMDUNG values (69,'Nha hang Ben Xua','Tru dung','42 Ha Huy Giap, Quan 12');
insert into TRAMDUNG values (70,'Nga tu Ga','Tru dung','154 Ha Huy Giap, Quan 12');
insert into TRAMDUNG values (71,'Dinh than Giao Khau','O son','332 Ha Huy Giap, Quan 12');
insert into TRAMDUNG values (72,'Cay xang Tai Loc','O son','408B Ha Huy Giap, Quan 12');
insert into TRAMDUNG values (73,'Vuon kieng Quang Dung','Tru dung','452 Ha Huy Giap, Quan 12');
insert into TRAMDUNG values (74,'Ga ra Thanh Hau','Tru dung','508 (63A) Ha Huy Giap, Quan 12');
insert into TRAMDUNG values (75,'Cho Thanh Xuan','Nha cho','Nha van hoa P. Thanh Loc Ha Huy Giap, Quan 12');
insert into TRAMDUNG values (76,'Truong Cao dang dien luc 2','Tru dung','554 (Truong dien luc 2) Ha Huy Giap, Quan 12');
insert into TRAMDUNG values (77,'THANH LOC','Ben xe','4/38 To 11 KP 1 Phuong Thanh Loc Quan 12 Ha Huy Giap, Quan 12');
insert into TRAMDUNG values (78,'Ben Thanh E','Ben xe','Ben Thanh Pham Ngu Lao, Quan 1');
insert into TRAMDUNG values (79,'Den Tho An Giao, Pasteur','Nha cho','Den Tho An Giao Pasteur, Quan 1');
insert into TRAMDUNG values (80,'Le Thanh Ton','Tru dung','144 Pasteur, Quan 1');
insert into TRAMDUNG values (81,'Ly Tu Trong','Tru dung','158 Pasteur, Quan 1');
insert into TRAMDUNG values (82,'Cong vien 30/4','Tru dung','178 Pasteur, Quan 1');
insert into TRAMDUNG values (83,'Nguyen Thi Minh Khai','Nha cho','184 Pasteur, Quan 1');
insert into TRAMDUNG values (84,'Dai hoc Kien Truc','Nha cho','194 D Pasteur, Quan 3');
insert into TRAMDUNG values (85,'So Tu Phap','Nha cho','214 Pasteur, Quan 3');
insert into TRAMDUNG values (86,'Dien Bien Phu','Nha cho','232 Pasteur, Quan 3');
insert into TRAMDUNG values (87,'Vien Pasteur','Nha cho','Doi dien 153 A-B Vo Thi Sau, Quan 3');
insert into TRAMDUNG values (88,'Vien Pasteur','Nha cho','252 (Doi dien 173) Nam Ky Khoi Nghia, Quan 3');
insert into TRAMDUNG values (89,'Ngan hang Sacombank','Tru dung','260 Nam Ky Khoi Nghia, Quan 3');
insert into TRAMDUNG values (90,'Ly Chinh Thang','O son','288 B7 Nam Ky Khoi Nghia, Quan 3');
insert into TRAMDUNG values (91,'Chua Vinh Nghiem','Tru dung','382E Nam Ky Khoi Nghia, Quan 3');
insert into TRAMDUNG values (92,'Tran Huy Lieu','Tru dung','40 Nguyen Van Troi, Quan Phu Nhuan');
insert into TRAMDUNG values (93,'Trung tam van hoa Quan Phu Nhuan','Tru dung','68 Nguyen Van Troi, Quan Phu Nhuan');
insert into TRAMDUNG values (94,'Hoc vien Hang kHong','Tru dung','104 Nguyen Van Troi, Quan Phu Nhuan');
insert into TRAMDUNG values (95,'Benh vien Quan Phu Nhuan','Tru dung','142 Nguyen Van Troi, Quan Phu Nhuan');
insert into TRAMDUNG values (96,'Cay xang Quan khu 7','Nha cho','180 Nguyen Van Troi, Quan Phu Nhuan');
insert into TRAMDUNG values (97,'Cong truoc SVD Quan Khu 7','Nha cho','A2 (San van dong Quan khu 7) Phan Dinh Giot, Quan Tan Binh');
insert into TRAMDUNG values (98,'Cong vien Hoang Van Thu','Nha cho','Cong vien Hoang Van Thu Phan Thuc Duyen, Quan Tan Binh');
insert into TRAMDUNG values (99,'Lang Cha Ca','Nha cho','20 Tran Quoc Hoan, Quan Tan Binh');
insert into TRAMDUNG values (100,'Sieu thi Maximark Cong Hoa','Tru dung','60 Cong Hoa, Quan Tan Binh');
insert into TRAMDUNG values (101,'Nha hat Quan Doi','Tru dung','138 (Ke nha hat Quan doi) Cong Hoa, Quan Tan Binh');
insert into TRAMDUNG values (102,'Ngan hang Quan doi','Nha cho','Tiec cuoi Huong Sen Cong Hoa, Quan Tan Binh');
insert into TRAMDUNG values (103,'Cong ty Lo Hoi','Tru dung','184 Cong Hoa, Quan Tan Binh');
insert into TRAMDUNG values (104,'Nga tu Hoang Hoa Tham','Tru dung','304 Cong Hoa, Quan Tan Binh');
insert into TRAMDUNG values (105,'Nga ba Binh Gia','Tru dung','390 Cong Hoa, Quan Tan Binh');
insert into TRAMDUNG values (106,'Le Van Huan','Tru dung','496 Cong Hoa, Quan Tan Binh');
insert into TRAMDUNG values (107,'592, Cong Hoa','O son','592 Cong Hoa, Quan Tan Binh');
insert into TRAMDUNG values (108,'Thuong Uyen','Nha cho','660 (ke 592) Cong Hoa, Quan Tan Binh');
insert into TRAMDUNG values (109,'Mui tau Cong Hoa','Tru dung','19B1 Truong Chinh, Quan Tan Binh');
insert into TRAMDUNG values (110,'Hoa Kieng Thanh Hung','Nha cho','9B Truong Chinh, Quan Tan Binh');
insert into TRAMDUNG values (111,'Tan Son','Nha cho','720 Truong Chinh, Quan Tan Binh');
insert into TRAMDUNG values (112,'Sieu thi Coop Mart Thang Loi','Nha cho','792 (25/19) Truong Chinh, Quan Tan Binh');
insert into TRAMDUNG values (113,'Khu Cong Nghiep tan Binh','Nha cho','906 Truong Chinh, Quan Tan Binh');
insert into TRAMDUNG values (114,'Thien Hoa','Nha cho','1/17A Truong Chinh, Quan 12');
insert into TRAMDUNG values (115,'Sieu thi Cho Lon','Nha cho','189/4 Truong Chinh, Quan 12');
insert into TRAMDUNG values (116,'Chua Vinh Phuoc','Nha cho','258 Truong Chinh, Quan 12');
insert into TRAMDUNG values (117,'Chua Lac Quang','Nha cho','408 Truong Chinh, Quan 12');
insert into TRAMDUNG values (118,'Bitis','Nha cho','640 Truong Chinh, Quan 12');
insert into TRAMDUNG values (119,'Cho Chieu','Nha cho','774A Truong Chinh, Quan 12');
insert into TRAMDUNG values (120,'Ben xe An Suong','Tru dung','116 Quoc lo 22, Quan 12');
insert into TRAMDUNG values (121,'Ben xe An Suong','Ben xe','Ben xe An Suong Quoc lo 22, Quan 12');
insert into TRAMDUNG values (122,'Ben Thanh F','Ben xe','Ben Thanh Pham Ngu Lao, Quan 1');
insert into TRAMDUNG values (123,'Nha tho Duc Ba','O son','47 Le Duan, Quan 1');
insert into TRAMDUNG values (124,'Cty Xo So Kien Thiet','Tru dung','Sofitel Plaza Le Duan, Quan 1');
insert into TRAMDUNG values (125,'Dai hoc Khoa hoc xa hoi nhan van','Nha cho','10 Dinh Tien Hoang, Quan 1');
insert into TRAMDUNG values (126,'SVD Hoa Lu','Nha cho','2 Dinh Tien Hoang, Quan 1');
insert into TRAMDUNG values (127,'Nguyen Dinh Chieu','Nha cho','18 Dinh Tien Hoang, Quan 1');
insert into TRAMDUNG values (128,'Dien Bien Phu','Tru dung','68 Dinh Tien Hoang, Quan 1');
insert into TRAMDUNG values (129,'Cau Bong','Tru dung','96 Dinh Tien Hoang, Quan Binh Thanh');
insert into TRAMDUNG values (130,'Benh vien Binh Thanh','Nha cho','114 Dinh Tien Hoang, Quan Binh Thanh');
insert into TRAMDUNG values (131,'Lang Ong Ba Chieu','Nha cho','Doi dien 129 Dinh Tien Hoang, Quan Binh Thanh');
insert into TRAMDUNG values (132,'UBND Quan Binh Thanh','Tru dung','6-8 Phan Dang Luu, Quan Binh Thanh');
insert into TRAMDUNG values (133,'Benh Vien Gia Dinh','Nha cho','2 No Trang Long, Quan Binh Thanh');
insert into TRAMDUNG values (134,'Ho boi Dai Dong','Tru dung','48 No Trang Long, Quan Binh Thanh');
insert into TRAMDUNG values (135,'Nga Tu Binh Hoa','Tru dung','276 Le Quang Dinh, Quan Binh Thanh');
insert into TRAMDUNG values (136,'Chua Hung Gia Tu','Tru dung','336 Le Quang Dinh, Quan Binh Thanh');
insert into TRAMDUNG values (137,'Nga Tu Xom Ga','Tru dung','424 Le Quang Dinh, Quan Binh Thanh');
insert into TRAMDUNG values (138,'Chua Gia Lam','Tru dung','488 Le Quang Dinh, Quan Binh Thanh');
insert into TRAMDUNG values (139,'Nga Ba Nguyen Hong','Tru dung','566 Le Quang Dinh, Quan Go Vap');
insert into TRAMDUNG values (140,'Truong Dai hoc Cong nghiep','Tru dung','28 Nguyen Van Nghi, Quan Go Vap');
insert into TRAMDUNG values (141,'Sieu thi Van Lang','Tru dung','Sieu thi Van Lang Quang Trung, Quan Go Vap');
insert into TRAMDUNG values (142,'Cong ty 32','Tru dung','138 Quang Trung, Quan Go Vap');
insert into TRAMDUNG values (143,'Nha Tho Xom Thuoc','Tru dung','190 Quang Trung, Quan Go Vap');
insert into TRAMDUNG values (144,'UBND Quan Go Vap','Tru dung','328 Quang Trung, Quan Go Vap');
insert into TRAMDUNG values (145,'VKS nhan dan Quan Go Vap','Tru dung','402 - 404 Quang Trung, Quan Go Vap');
insert into TRAMDUNG values (146,'Chua Huynh Kim','O son','548 Quang Trung, Quan Go Vap');
insert into TRAMDUNG values (147,'Sieu thi Binh Dan, Quang Trung','Tru dung','628A Quang Trung, Quan Go Vap');
insert into TRAMDUNG values (148,'Cho Thong Tay','Tru dung','734 Quang Trung, Quan Go Vap');
insert into TRAMDUNG values (149,'Truong THPT Nguyen Cong Tru','Tru dung','872 (96H) Quang Trung, Quan Go Vap');
insert into TRAMDUNG values (150,'Det may Phuong Dong','Nha cho','930 (Kho 97) Quang Trung, Quan Go Vap');
insert into TRAMDUNG values (151,'Lang SOS','Tru dung','1010 Quang Trung, Quan Go Vap');
insert into TRAMDUNG values (152,'Cong ty Dong Tam','Tru dung','1134 Quang Trung, Quan Go Vap');
insert into TRAMDUNG values (153,'Nga Tu Cau cong','Tru dung','1246 Quang Trung, Quan Go Vap');
insert into TRAMDUNG values (154,'Cho Cau','Tru dung','1324 Quang Trung, Quan Go Vap');
insert into TRAMDUNG values (155,'Cho Cau','O son','113 Quang Trung, Quan 12');
insert into TRAMDUNG values (156,'Cau vuot Quang Trung','Tru dung','170 Quang Trung, Quan 12');
insert into TRAMDUNG values (157,'Cong vien phan mem Quang Trung','Nha cho','Cong vien phan mem Quang Trung To Ky, Quan 12');
insert into TRAMDUNG values (158,'Dong Bac','O son','288 To Ky, Quan 12');
insert into TRAMDUNG values (159,'Dien luc Hoc Mon','O son','Dien luc Hoc Mon To Ky, Quan 12');
insert into TRAMDUNG values (160,'Chiec non Ky Dieu','O son','312 To Ky, Quan 12');
insert into TRAMDUNG values (161,'Cho Tan Chanh Hiep','Tru dung','414 To Ky, Quan 12');
insert into TRAMDUNG values (162,'Doanh trai Quan Doi','O son','A49 To Ky, Quan 12');
insert into TRAMDUNG values (163,'Truong Dai hoc Lao dong Xa hoi','Tru dung','72 To Ky, Quan 12');
insert into TRAMDUNG values (164,'Nga 3 Bau','Tru dung','Lo A4D Nguyen Anh Thu, Quan 12');
insert into TRAMDUNG values (165,'Tram y te','O son','772 Nguyen Anh Thu, Quan 12');
insert into TRAMDUNG values (166,'Trung tam y te Quan 12','Tru dung','927 Nguyen Anh Thu, Quan 12');
insert into TRAMDUNG values (167,'Quan Nam Lua','Tru dung','785 Nguyen Anh Thu, Quan 12');
insert into TRAMDUNG values (168,'Nga tu Nuoc da','O son','753 Nguyen Anh Thu, Quan 12');
insert into TRAMDUNG values (169,'Truong tieu hoc Nguyen Trai','Tru dung','Truong Nguyen Trai Nguyen Anh Thu, Quan 12');
insert into TRAMDUNG values (170,'Nga 3 Dong Quang','Tru dung','581-577 Nguyen Anh Thu, Quan 12');
insert into TRAMDUNG values (171,'Cay xang Hiep Thanh','Tru dung','46/8 Nguyen Anh Thu, Quan 12');
insert into TRAMDUNG values (172,'Cua hang Ngoc Son','O son','86H Nguyen Anh Thu, Quan 12');
insert into TRAMDUNG values (173,'Cong an Hiep Thanh','Tru dung','425 Nguyen Anh Thu, Quan 12');
insert into TRAMDUNG values (174,'Ngan hang Agribank','Tru dung','296 Nguyen Anh Thu, Quan 12');
insert into TRAMDUNG values (175,'Hiep Thanh','Ben xe','BAI XE HIEP THANH Nguyen Anh Thu, Quan 12');

-- Them dong bang LOTRINH
insert into LOTRINH values (1,1,1);
insert into LOTRINH values (1,2,2);
insert into LOTRINH values (1,3,3);
insert into LOTRINH values (1,4,4);
insert into LOTRINH values (1,5,5);
insert into LOTRINH values (1,6,6);
insert into LOTRINH values (1,7,7);
insert into LOTRINH values (1,8,8);
insert into LOTRINH values (1,9,9);
insert into LOTRINH values (1,10,10);
insert into LOTRINH values (1,11,11);
insert into LOTRINH values (1,12,12);
insert into LOTRINH values (1,13,13);
insert into LOTRINH values (1,14,14);
insert into LOTRINH values (1,15,15);
insert into LOTRINH values (1,16,16);
insert into LOTRINH values (1,17,17);
insert into LOTRINH values (1,18,18);
insert into LOTRINH values (1,19,19);
insert into LOTRINH values (1,20,20);
insert into LOTRINH values (1,21,21);
insert into LOTRINH values (1,22,22);
insert into LOTRINH values (1,23,23);
insert into LOTRINH values (1,24,24);
insert into LOTRINH values (1,25,25);
insert into LOTRINH values (1,26,26);
insert into LOTRINH values (1,27,27);
insert into LOTRINH values (1,28,28);
insert into LOTRINH values (1,29,29);
insert into LOTRINH values (3,1,30);
insert into LOTRINH values (3,2,31);
insert into LOTRINH values (3,3,32);
insert into LOTRINH values (3,4,33);
insert into LOTRINH values (3,5,34);
insert into LOTRINH values (3,6,35);
insert into LOTRINH values (3,7,36);
insert into LOTRINH values (3,8,37);
insert into LOTRINH values (3,9,38);
insert into LOTRINH values (3,10,39);
insert into LOTRINH values (3,11,40);
insert into LOTRINH values (3,12,41);
insert into LOTRINH values (3,13,42);
insert into LOTRINH values (3,14,43);
insert into LOTRINH values (3,15,44);
insert into LOTRINH values (3,16,45);
insert into LOTRINH values (3,17,46);
insert into LOTRINH values (3,18,47);
insert into LOTRINH values (3,19,48);
insert into LOTRINH values (3,20,49);
insert into LOTRINH values (3,21,50);
insert into LOTRINH values (3,22,51);
insert into LOTRINH values (3,23,52);
insert into LOTRINH values (3,24,53);
insert into LOTRINH values (3,25,54);
insert into LOTRINH values (3,26,55);
insert into LOTRINH values (3,27,56);
insert into LOTRINH values (3,28,57);
insert into LOTRINH values (3,29,58);
insert into LOTRINH values (3,30,59);
insert into LOTRINH values (3,31,60);
insert into LOTRINH values (3,32,61);
insert into LOTRINH values (3,33,62);
insert into LOTRINH values (3,34,63);
insert into LOTRINH values (3,35,64);
insert into LOTRINH values (3,36,65);
insert into LOTRINH values (3,37,66);
insert into LOTRINH values (3,38,67);
insert into LOTRINH values (3,39,68);
insert into LOTRINH values (3,40,69);
insert into LOTRINH values (3,41,70);
insert into LOTRINH values (3,42,71);
insert into LOTRINH values (3,43,72);
insert into LOTRINH values (3,44,73);
insert into LOTRINH values (3,45,74);
insert into LOTRINH values (3,46,75);
insert into LOTRINH values (3,47,76);
insert into LOTRINH values (3,48,77);
insert into LOTRINH values (4,1,30);
insert into LOTRINH values (4,2,31);
insert into LOTRINH values (4,3,32);
insert into LOTRINH values (4,4,33);
insert into LOTRINH values (4,5,78);
insert into LOTRINH values (4,6,35);
insert into LOTRINH values (4,7,36);
insert into LOTRINH values (4,8,79);
insert into LOTRINH values (4,9,80);
insert into LOTRINH values (4,10,81);
insert into LOTRINH values (4,11,82);
insert into LOTRINH values (4,12,83);
insert into LOTRINH values (4,13,84);
insert into LOTRINH values (4,14,85);
insert into LOTRINH values (4,15,86);
insert into LOTRINH values (4,16,87);
insert into LOTRINH values (4,17,88);
insert into LOTRINH values (4,18,89);
insert into LOTRINH values (4,19,90);
insert into LOTRINH values (4,20,91);
insert into LOTRINH values (4,21,92);
insert into LOTRINH values (4,22,93);
insert into LOTRINH values (4,23,94);
insert into LOTRINH values (4,24,95);
insert into LOTRINH values (4,25,96);
insert into LOTRINH values (4,26,97);
insert into LOTRINH values (4,27,98);
insert into LOTRINH values (4,28,99);
insert into LOTRINH values (4,29,100);
insert into LOTRINH values (4,30,101);
insert into LOTRINH values (4,31,102);
insert into LOTRINH values (4,32,103);
insert into LOTRINH values (4,33,104);
insert into LOTRINH values (4,34,105);
insert into LOTRINH values (4,35,106);
insert into LOTRINH values (4,36,107);
insert into LOTRINH values (4,37,108);
insert into LOTRINH values (4,38,109);
insert into LOTRINH values (4,39,110);
insert into LOTRINH values (4,40,111);
insert into LOTRINH values (4,41,112);
insert into LOTRINH values (4,42,113);
insert into LOTRINH values (4,43,114);
insert into LOTRINH values (4,44,115);
insert into LOTRINH values (4,45,116);
insert into LOTRINH values (4,46,117);
insert into LOTRINH values (4,47,118);
insert into LOTRINH values (4,48,119);
insert into LOTRINH values (4,49,120);
insert into LOTRINH values (4,50,121);
insert into LOTRINH values (18,1,30);
insert into LOTRINH values (18,2,31);
insert into LOTRINH values (18,3,32);
insert into LOTRINH values (18,4,33);
insert into LOTRINH values (18,5,122);
insert into LOTRINH values (18,6,35);
insert into LOTRINH values (18,7,36);
insert into LOTRINH values (18,8,79);
insert into LOTRINH values (18,9,80);
insert into LOTRINH values (18,10,81);
insert into LOTRINH values (18,11,82);
insert into LOTRINH values (18,12,123);
insert into LOTRINH values (18,13,124);
insert into LOTRINH values (18,14,125);
insert into LOTRINH values (18,15,126);
insert into LOTRINH values (18,16,127);
insert into LOTRINH values (18,17,128);
insert into LOTRINH values (18,18,129);
insert into LOTRINH values (18,19,130);
insert into LOTRINH values (18,20,131);
insert into LOTRINH values (18,21,132);
insert into LOTRINH values (18,22,133);
insert into LOTRINH values (18,23,134);
insert into LOTRINH values (18,24,135);
insert into LOTRINH values (18,25,136);
insert into LOTRINH values (18,26,137);
insert into LOTRINH values (18,27,138);
insert into LOTRINH values (18,28,139);
insert into LOTRINH values (18,29,140);
insert into LOTRINH values (18,30,141);
insert into LOTRINH values (18,31,142);
insert into LOTRINH values (18,32,143);
insert into LOTRINH values (18,33,144);
insert into LOTRINH values (18,34,145);
insert into LOTRINH values (18,35,146);
insert into LOTRINH values (18,36,147);
insert into LOTRINH values (18,37,148);
insert into LOTRINH values (18,38,149);
insert into LOTRINH values (18,39,150);
insert into LOTRINH values (18,40,151);
insert into LOTRINH values (18,41,152);
insert into LOTRINH values (18,42,153);
insert into LOTRINH values (18,43,154);
insert into LOTRINH values (18,44,155);
insert into LOTRINH values (18,45,156);
insert into LOTRINH values (18,46,157);
insert into LOTRINH values (18,47,158);
insert into LOTRINH values (18,48,159);
insert into LOTRINH values (18,49,160);
insert into LOTRINH values (18,50,161);
insert into LOTRINH values (18,51,162);
insert into LOTRINH values (18,52,163);
insert into LOTRINH values (18,53,164);
insert into LOTRINH values (18,54,165);
insert into LOTRINH values (18,55,166);
insert into LOTRINH values (18,56,167);
insert into LOTRINH values (18,57,168);
insert into LOTRINH values (18,58,169);
insert into LOTRINH values (18,59,170);
insert into LOTRINH values (18,60,171);
insert into LOTRINH values (18,61,172);
insert into LOTRINH values (18,62,173);
insert into LOTRINH values (18,63,174);
insert into LOTRINH values (18,64,175);
