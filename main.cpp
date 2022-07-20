
//#include "CTDL_DSMB.h"
//#include "CTDL_KH.h"
#include "CTDL_DSCB.h"
#define getmouseclick(WM_LBUTTONDBLCLK,x, y) {getmouseclick(WM_LBUTTONDBLCLK,x, y); cout <<"("<<x << ";" << y <<")"<< endl;}
using namespace std;
// CAC SLIDE DUNG TRONG BAI
void slideQLMayBay(DSMB &dsmb, DS_CB &dscb, KHACHHANG &dskh );
void slideQLVe(DSMB &dsmb, DS_CB &dscb, KHACHHANG &dskh);
void slideQLChuyenBay(DSMB &dsmb, DS_CB &dscb, KHACHHANG &dskh );
void slideSD_MayBay(DS_CB dscb, DSMB dsmb,KHACHHANG dskh, string macb);
void slideLOC_ChuyenBay(DSMB &dsmb, DS_CB &dscb, KHACHHANG &dskh);


//MENU CHINH
void slideMenu(DSMB &dsmb, KHACHHANG &dskh, DS_CB &dscb) {
	cleardevice();
	nutLenh(10,150,220,200,"QUAN LY MAY BAY");
	nutLenh(10,220,220,270,"QUAN LY CHUYEN BAY");
	nutLenh(10,290,220,340,"QUAN LY VE");
	nutLenh(10,360,220,410,"QUAN LY THONG KE");
	setcolor(1);
	line(230,0,230,1000);
	outtextXY(750,260,"- - - DO AN QUAN LY MAY BAY - - -");
	outtextXY(750,290,"(NHÓM 20)");
	outtextXY(735,340,"N18DCCN101-NGUYEN CHI TIN");
	outtextXY(745,370,"N18DCCN101-NGUYEN CHI TIN");
	outtextXY(760,400,"N18DCCN101-NGUYEN CHI TIN");
	line(230,230,1800,230);
	line(230,410,1800,410);
	
	while(true) {
		int x=-1;
		int y=-1;
		delay(1);
		static int soTrang=1;
		int QLMB=0,QLCB=0,QLV=0,QLTK=0;
		if (ismouseclick(WM_LBUTTONDBLCLK)) {
			getmouseclick(WM_LBUTTONDBLCLK,x, y);
			QLMB=((x>=10&&x<=220&&y>=150&&y<=200)? 2: 0);
			QLCB=((x>=10&&x<=220&&y>=220&&y<=270)? 2: 0);
			QLV=((x>=10&&x<=220&&y>=290&&y<=340)? 2: 0);
			QLTK=((x>=10&&x<=220&&y>=360&&y<=410)? 2: 0);
		}
		if(QLMB==2) slideQLMayBay(dsmb,dscb,dskh);
		if(QLCB==2) slideQLChuyenBay(dsmb,dscb,dskh);
		if(QLV==2) 	slideQLVe(dsmb,dscb,dskh);
		if(QLTK==2) slideLOC_ChuyenBay(dsmb,dscb,dskh);
	}
}
void slideQLMayBay(DSMB &dsmb, DS_CB &dscb,KHACHHANG &dskh) {
	static int soTrang=1;
	cleardevice();
	xuatDsMayBay(dsmb,soTrang);
	nutLenh(10,10,60,40,"<");
	int sohieu_add=0, loai=0,socho=0,sohieu_update=0;
	string sohieu_add_str="",loai_str="",socho_str="",sohieu_update_str="";
	string mmh="",nk="",hk="",n="",svmin="",svmax="",mltc="";
	while(true) {
		int x=-1;
		int y=-1;
		delay(1);
		//--------------------------------------------- tiêu dê cau bang--------------
		tieuDe(100,120,520,160,"SO HIEU MAY BAY");
//		tieuDe(220,120,370,160,"MA MH");
//		tieuDe(370,120,780,160,"TEN MH");
//		tieuDe(780,120,1000,160,"NIEN KHOA");
//		tieuDe(1000,120,1050,160,"HK");
//		tieuDe(1050,120,1120,160,"NHOM");
		tieuDe(520,120,920,160,"LOAI MAY BAY");
		tieuDe(920,120,1320,160,"SO CHO");
		line(0,115,1800,115);
		
		//----------------------------------------------------tao ô nhâp-----
		hinhChuNhatRong(100,10,400,50,7);//sohieu
//		hinhChuNhatDac(100,15,115,30,1);//sohieu
		hinhChuNhatRong(550,10,900,50,7);//loai
		hinhChuNhatRong(1150,10,1300,50,7);//socho
		chuThich(250,80,7,"So Hieu May Bay");
//		hinhChuNhatRong(300,10,500,50,7);//nien khoa
//		chuThich(400,80,7,"Nien khoa");
//		hinhChuNhatRong(550,10,700,50,7);//hoc ki
//		chuThich(625,80,7,"Hoc ki");
//		hinhChuNhatRong(750,10,900,50,7);//nhom
//		chuThich(825,80,7,"Nhom");
		
		chuThich(725,80,7,"Loai May Bay");
		
		chuThich(1225,80,7,"So Cho");
		
		//---------------------------------------------------full bottom----
		hinhChuNhatRong(370,620,570,660,7);	//sohieu_update
		
		chuThich(470,690,7,"SO HIEU MAY BAY");
		nutLenh(100,620,170,660,"THEM");
		nutLenh(190,620,260,660,"XOA");
		nutLenh(280,620,350,660,"SUA");
		nutLenh(1270,620,1320,660,">");
		nutLenh(1200,620,1250,660,"<");
		
		//-----------------------------------------------ve 10 khung cua table---
		for(int i=1; i<=10; i++) {
			hinhChuNhatRong(100,120+(40*i),520,120+(40*(i+1)),1);
//			hinhChuNhatRong(220,120+(40*i),370,120+(40*(i+1)),1);
//			hinhChuNhatRong(370,120+(40*i),780,120+(40*(i+1)),1);
//			hinhChuNhatRong(780,120+(40*i),1000,120+(40*(i+1)),1);
//			hinhChuNhatRong(1000,120+(40*i),1050,120+(40*(i+1)),1);
//			hinhChuNhatRong(1050,120+(40*i),1120,120+(40*(i+1)),1);
			hinhChuNhatRong(520,120+(40*i),920,120+(40*(i+1)),1);
			hinhChuNhatRong(920,120+(40*i),1320,120+(40*(i+1)),1);
		}
		
		//------------------------------------bat các nut them xoa sua toi lui--------
		int thoat=0,them=0,xoa=0,toi=0,lui=0,sua=0;
		if (ismouseclick(WM_LBUTTONDBLCLK)) {
			getmouseclick(WM_LBUTTONDBLCLK,x, y);
			thoat=((x>=10&&x<=60&&y>=10&&y<=40)? 2: 0);
			them=((x>=100&&x<=170&&y>=620&&y<=660)? 2: 0);
			xoa=((x>=190&&x<=260&&y>=620&&y<=660)? 2: 0);
			sua=((x>=280&&x<=350&&y>=620&&y<=660)? 2: 0);
			toi=((x>=1270&&x<=1320&&y>=620&&y<=660)? 2: 0);
			lui=((x>=1200&&x<=1250&&y>=620&&y<=660)? 2: 0);
		}
		
		
		
		//-------------------------------- bat khi bam vao header khung nhap -----
		if (ismouseclick(WM_LBUTTONDOWN)) {
			getmouseclick(WM_LBUTTONDOWN, x, y);
			
//			hinhChuNhatRong(100,10,400,50,7); SH
//			hinhChuNhatRong(550,10,900,50,7);//loai
//			hinhChuNhatRong(1150,10,1300,50,7);
			sohieu_update=((x>=370 && x<=570 && y>=620 && y<=660)? 1: 0);
			sohieu_add=((x>=100 && x<=400 && y>=10 && y<=50)? 1: 0);
			loai=((x>=550 && x<=900 && y>=10 && y<=50)? 1: 0);
			socho=((x>=1150 && x<=1300 && y>=10 && y<=50)? 1: 0);
		}
		
		
		if(sohieu_update) {
			hinhChuNhatRong(370,620,570,660,1);
			khungNhap(375,645,sohieu_update_str,8,2,0,0,36);
			hinhChuNhatRong(100,10,400,50,7);//sohieu
			thoatKhungNhap(105,35,sohieu_add_str,8,2,0,1);
			hinhChuNhatRong(550,10,900,50,7);//loai
			thoatKhungNhap(555,35,loai_str,8,2,0,1);
			hinhChuNhatRong(1150,10,1300,50,7);//socho
			thoatKhungNhap(1155,35,socho_str,8,2,0,1);
		}
		
		if(sohieu_add) {
			hinhChuNhatRong(370,620,570,660,7);
			thoatKhungNhap(375,645,sohieu_update_str,8,2,0,1);
			hinhChuNhatRong(100,10,400,50,1);//sohieu
			khungNhap(105,35,sohieu_add_str,8,2,0,1,36);
			hinhChuNhatRong(550,10,900,50,7);//loai
			thoatKhungNhap(555,35,loai_str,8,2,0,1);
			hinhChuNhatRong(1150,10,1300,50,7);//socho
			thoatKhungNhap(1155,35,socho_str,8,2,0,1);
		}
		if(loai) {
			hinhChuNhatRong(370,620,570,660,7);
			thoatKhungNhap(375,645,sohieu_update_str,8,2,0,1);
			hinhChuNhatRong(100,10,400,50,7);//sohieu
			thoatKhungNhap(105,35,sohieu_add_str,8,2,0,1);
			hinhChuNhatRong(550,10,900,50,1);//loai
			khungNhap(555,35,loai_str,8,2,0,1,36);
			hinhChuNhatRong(1150,10,1300,50,7);//socho
			thoatKhungNhap(1155,35,socho_str,8,2,0,1);
		}
		
		if(socho) {
			hinhChuNhatRong(370,620,570,660,7);
			thoatKhungNhap(375,645,sohieu_update_str,8,2,0,1);
			hinhChuNhatRong(100,10,400,50,7);//sohieu
			thoatKhungNhap(105,35,sohieu_add_str,8,2,0,1);
			hinhChuNhatRong(550,10,900,50,7);//loai
			thoatKhungNhap(555,35,loai_str,8,2,0,1);
			hinhChuNhatRong(1150,10,1300,50,1);//socho
			khungNhap(1155,35,socho_str,8,2,0,1,5);
		}
		
		
		if(thoat==2) slideMenu(dsmb,dskh,dscb);
		else if(lui == 2 && soTrang > 1) {
			soTrang--;
			clearManHinhMB();
			xuatDsMayBay(dsmb,soTrang);
		} else if(toi == 2 && soTrang <(dsmb.sl + 9) /10) {
			soTrang++;
			clearManHinhMB();
			xuatDsMayBay(dsmb,soTrang);	
		} else if(them==2) {
			
			if(sohieu_add_str==""||loai_str==""||socho_str=="")
			{
				chuThich(780,660,RED,"YEU CAP NHAP DAY DU CAC TRUONG");
			}
			else if(dsmb.sl==300) chuThich(780,660,RED,"     CT QUAN LY TOI DA 300 MB     ");
			else if(check_space(sohieu_add_str)) chuThich(780,660,RED,"SO HIEU MAY BAY KH DC CO KHOANG TRONG");
			else if(stoi(socho_str)<20||stoi(socho_str)>300) chuThich(780,660,RED,"     SO CHO KHONG DUOC BE HON 20 VA LON HON 300   ");
			else if(CHECKsh_MB(dsmb,sohieu_add_str))
			{
				MayBay *p= new MayBay;
				p->SoHieu=sohieu_add_str;
				p->Loai=loai_str;
				p->SoCho=stoi(socho_str);
				ADD_MB(dsmb,p);
				clearManHinhMB();
				Ghifile_MB(dsmb);
				xuatDsMayBay(dsmb,soTrang);
				chuThich(780,660,GREEN,"           DA THEM THANH CONG                ");
			}else{
				
				chuThich(780,660,RED,"              MA MAY BAY DA TON TAI !           ");
			}
			
		}

		
		else if(xoa==2) {

			if(sohieu_update_str=="")
			{
				chuThich(800,660,RED,"   KHONG DC DE TRONG SO HIEU MAY BAY      ");
			}
			else if(CHECKsh_MB(dsmb,sohieu_update_str)||check_space(sohieu_update_str))
			{
				chuThich(800,660,RED,"   KHONG TON TAI MAY BAY TRONG DANH SACH     ");
			}
			else if(check_deleteMB(dscb,sohieu_update_str))
			{
				chuThich(800,660,RED,"KH THE XOA MAY BAY DANG THUC HIEN CHUYEN BAY ");
			}
			else{
				DELETE_MB(dsmb, sohieu_update_str);
				clearManHinhMB();
				Ghifile_MB(dsmb);
				xuatDsMayBay(dsmb,soTrang);
				chuThich(800,660,GREEN,"           DA XOA MAY BAY                   ");
				
			}


		} else if(sua==2) {
			
			if(sohieu_add_str==""||loai_str==""||socho_str=="")
			{
				chuThich(780,660,RED,"YEU CAP NHAP DAY DU CAC TRUONG");
			}
			else if(dsmb.sl==300) chuThich(780,660,RED,"     CT QUAN LY TOI DA 300 MB     ");
			else if(check_space(sohieu_add_str)) chuThich(780,660,RED,"SO HIEU MAY BAY KH DC CO KHOANG TRONG");
			else if(stoi(socho_str)<20||stoi(socho_str)>300) chuThich(780,660,RED,"     SO CHO KHONG DUOC BE HON 20 VA LON HON 300   ");
			else if( stoi(socho_str)<check_socho(dscb,sohieu_add_str)) chuThich(780,660,RED,"   KH THE CHINH SUA SO LUONG CHO VI DA CO HK ÐK  ");
			else if(!CHECKsh_MB(dsmb,sohieu_add_str))
			{
				string str=UPDATE_MB(dsmb,sohieu_add_str,loai_str,stoi(socho_str));
				clearManHinhMB();
				Ghifile_MB(dsmb);
				xuatDsMayBay(dsmb,soTrang);
				chuThich(780,660,GREEN,"          CAP NHAT MAY BAY THANH CONG            ");
			}
			else{
				
				chuThich(780,660,RED,"             SO HIEU MAY BAY KH TON TAI !          ");
			}		


		}


	}
}

void slideQLChuyenBay(DSMB &dsmb, DS_CB &dscb, KHACHHANG &dskh ) {
	cleardevice();
	static int soTrang=1;
	xuatDsChuyenBay(dscb,soTrang);
	nutLenh(10,10,60,40,"<");
	int mcb_add=0, datestart=0,sohieumb=0, sbden=0, mcb_edit=0, macb_delete=0, datestart_edit=0;
	string mcb_add_str="" ,sanbayden_add_str="",datestart_str="",trangthai_str="",sohieumb_str="",macb_delete_string="",macb_edit_string="",datestart_edit_string="";

	while(true) {
		int x=-1;
		int y=-1;
		delay(1);
		//--------------------------------------------- tiêu dê cau bang--------------
		tieuDe(300,120,480,160,"MA CHUYEN BAY");
//		tieuDe(220,120,370,160,"MA MH");
//		tieuDe(370,120,780,160,"TEN MH");
//		tieuDe(780,120,1000,160,"NIEN KHOA");
//		tieuDe(1000,120,1050,160,"HK");
		tieuDe(480,120,700,160,"TG KHOI HANH");
		tieuDe(700,120,900,160,"TRANG THAI");
		tieuDe(900,120,1120,160,"SO HIEU MAY BAY");
		tieuDe(1120,120,1400,160,"SAN BAY DEN");
		line(0,115,1800,115);
		
		//----------------------------------------------------tao ô nhâp-----
		hinhChuNhatRong(300,10,500,50,7);//MACB
		hinhChuNhatRong(550,10,800,50,7);//TGSTART
		hinhChuNhatRong(850,10,1050,50,7);//SHMB
		hinhChuNhatRong(1100,10,1350,50,7);//SB DEN
		
//		hinhChuNhatRong(300,10,500,50,7);//nien khoa
//		chuThich(400,80,7,"Nien khoa");
//		hinhChuNhatRong(550,10,700,50,7);//hoc ki
//		chuThich(625,80,7,"Hoc ki");
//		hinhChuNhatRong(750,10,900,50,7);//nhom
//		chuThich(825,80,7,"Nhom");	
		chuThich(400,80,7,"MA CHUYEN BAY");
		chuThich(675,10,7,"vd: 2022/02/01-09:21");
		chuThich(675,80,7,"T/G KHOI HANH");
		chuThich(950,80,7,"SO HIEU MAY BAY");
		chuThich(1200,80,7,"SAN BAY DEN");
		
		
		//---------------------------------------------------full bottom----
		
		
		nutLenh(30,360,100,400,"SUA");
		chuThich(200,490,7,"T/G KH (EDIT)");
		chuThich(200,350,7,"MA CB (EDIT)");
		nutLenh(30,220,100,260,"XOA");
		chuThich(200,280,7,"MA CB (HUY)");
		hinhChuNhatRong(120,360,280,400,7);	//sohieu_update
		hinhChuNhatRong(120,430,280,470,7);	// DATE_UPDATE
		hinhChuNhatRong(120,220,280,260,7); // HUY CHUYEN

		
		nutLenh(210,10,280,50,"THEM");
		nutLenh(1270,620,1320,660,">");
		nutLenh(1200,620,1250,660,"<");
		
		//-----------------------------------------------ve 10 khung cua table---
		for(int i=1; i<=10; i++) {

		
			hinhChuNhatRong(300,120+(40*i),480,120+(40*(i+1)),1);
			hinhChuNhatRong(480,120+(40*i),700,120+(40*(i+1)),1);
//			hinhChuNhatRong(370,120+(40*i),780,120+(40*(i+1)),1);
//			hinhChuNhatRong(780,120+(40*i),1000,120+(40*(i+1)),1);
//			hinhChuNhatRong(1000,120+(40*i),1050,120+(40*(i+1)),1);
			hinhChuNhatRong(1120,120+(40*i),1400,120+(40*(i+1)),1);
			hinhChuNhatRong(700,120+(40*i),900,120+(40*(i+1)),1);
			hinhChuNhatRong(900,120+(40*i),1120,120+(40*(i+1)),1);
		}
		
		//------------------------------------bat các nut them xoa sua toi lui--------
		int thoat=0,them=0,xoa=0,toi=0,lui=0,sua=0;
		if (ismouseclick(WM_LBUTTONDBLCLK)) {
			getmouseclick(WM_LBUTTONDBLCLK,x, y);
			thoat=((x>=10&&x<=60&&y>=10&&y<=40)? 2: 0);
			them=((x>=210&&x<=280&&y>=10&&y<=50)? 2: 0);
			xoa=((x>=30&&x<=100&&y>=220&&y<=260)? 2: 0);
			sua=((x>=30&&x<=100&&y>=360&&y<=400)? 2: 0);
			toi=((x>=1270&&x<=1320&&y>=620&&y<=660)? 2: 0);
			lui=((x>=1200&&x<=1250&&y>=620&&y<=660)? 2: 0);
		}
		
		
		
		//-------------------------------- bat khi bam vao header khung nhap -----
		if (ismouseclick(WM_LBUTTONDOWN)) {
			getmouseclick(WM_LBUTTONDOWN, x, y);
			
//		hinhChuNhatRong(300,10,500,50,7);//MACB
//		hinhChuNhatRong(550,10,800,50,7);//TGSTART
//		hinhChuNhatRong(850,10,1050,50,7);//SHMB
//		hinhChuNhatRong(1100,10,1350,50,7);//SB DEN
			sbden=(((x>=1100 && x<=1350 && y>=10 && y<=50)? 1: 0));
			mcb_add=((x>=300 && x<=500 && y>=10 && y<=50)? 1: 0);
			datestart=((x>=550 && x<=800 && y>=10 && y<=50)? 1: 0);
			sohieumb=((x>=850 && x<=1050 && y>=10 && y<=50)? 1: 0);	
			mcb_edit=((x>=120 && x<=280 && y>=360 && y<=400)? 1: 0);
			datestart_edit=((x>=120 && x<=280 && y>=430 && y<=470)? 1: 0);
			macb_delete=((x>=120 && x<=280 && y>=220 && y<=260)? 1: 0);
		}
//		
		
		if(mcb_add) {
			
//		hinhChuNhatRong(300,10,500,50,7);//MACB
//		hinhChuNhatRong(550,10,800,50,7);//TGSTART
//		hinhChuNhatRong(850,10,1050,50,7);//SHMB
//		hinhChuNhatRong(1100,10,1350,50,7);//SB DEN
			hinhChuNhatRong(1100,10,1350,50,7); // sb den
			thoatKhungNhap(1105,35,sanbayden_add_str,8,2,0,0);
			hinhChuNhatRong(300,10,500,50,1); // ma add
			khungNhap(305,35,mcb_add_str,8,2,0,1,36);
			hinhChuNhatRong(550,10,800,50,7);//time add
			thoatKhungNhap(555,35,datestart_str,8,2,0,1);
			hinhChuNhatRong(850,10,1050,50,7);//shmb add
			thoatKhungNhap(855,35,sohieumb_str,8,2,0,1);
			hinhChuNhatRong(120,220,280,260,7);//ma delete
			thoatKhungNhap(125,245,macb_delete_string,8,2,0,1);
			hinhChuNhatRong(120,360,280,400,7);//ma edit
			thoatKhungNhap(125,385,macb_edit_string,8,2,0,1);
			hinhChuNhatRong(120,430,280,470,7);//time edit
			thoatKhungNhap(125,455,datestart_edit_string,8,2,0,1);
		
		}
		
		if(datestart) {
			hinhChuNhatRong(1100,10,1350,50,7); // sb den
			thoatKhungNhap(1105,35,sanbayden_add_str,8,2,0,0);
			hinhChuNhatRong(300,10,500,50,7); // ma add
			thoatKhungNhap(305,35,mcb_add_str,8,2,0,0);
			hinhChuNhatRong(550,10,800,50,1);//time add
			khungNhap(555,35,datestart_str,8,2,0,1,36);
			hinhChuNhatRong(850,10,1050,50,7);//shmb add
			thoatKhungNhap(855,35,sohieumb_str,8,2,0,1);
			hinhChuNhatRong(120,220,280,260,7);//ma delete
			thoatKhungNhap(125,245,macb_delete_string,8,2,0,1);
			hinhChuNhatRong(120,360,280,400,7);//ma edit
			thoatKhungNhap(125,385,macb_edit_string,8,2,0,1);
			hinhChuNhatRong(120,430,280,470,7);//time edit
			thoatKhungNhap(125,455,datestart_edit_string,8,2,0,1);
		}
		if(sohieumb) {
			hinhChuNhatRong(1100,10,1350,50,7); // sb den
			thoatKhungNhap(1105,35,sanbayden_add_str,8,2,0,0);
			hinhChuNhatRong(300,10,500,50,7); // ma add
			thoatKhungNhap(305,35,mcb_add_str,8,2,0,0);
			hinhChuNhatRong(550,10,800,50,7);//time add
			thoatKhungNhap(555,35,datestart_str,8,2,0,1);
			hinhChuNhatRong(850,10,1050,50,1);//shmb add
			khungNhap(855,35,sohieumb_str,8,2,0,1,36);
			hinhChuNhatRong(120,220,280,260,7);//ma delete
			thoatKhungNhap(125,245,macb_delete_string,8,2,0,1);
			hinhChuNhatRong(120,360,280,400,7);//ma edit
			thoatKhungNhap(125,385,macb_edit_string,8,2,0,1);
			hinhChuNhatRong(120,430,280,470,7);//time edit
			thoatKhungNhap(125,455,datestart_edit_string,8,2,0,1);
		}
		
		if(mcb_edit) {
			hinhChuNhatRong(1100,10,1350,50,7); // sb den
			thoatKhungNhap(1105,35,sanbayden_add_str,8,2,0,0);
			hinhChuNhatRong(300,10,500,50,7); // ma add
			thoatKhungNhap(305,35,mcb_add_str,8,2,0,0);
			hinhChuNhatRong(550,10,800,50,7);//time add
			thoatKhungNhap(555,35,datestart_str,8,2,0,1);
			hinhChuNhatRong(850,10,1050,50,7);//shmb add
			thoatKhungNhap(855,35,sohieumb_str,8,2,0,1);
			hinhChuNhatRong(120,220,280,260,7);//ma delete
			thoatKhungNhap(125,245,macb_delete_string,8,2,0,1);
			hinhChuNhatRong(120,360,280,400,1);//ma edit
			khungNhap(125,385,macb_edit_string,8,2,0,1,36);
			hinhChuNhatRong(120,430,280,470,7);//time edit
			thoatKhungNhap(125,455,datestart_edit_string,8,2,0,1);
		}
		if(datestart_edit) {
			hinhChuNhatRong(1100,10,1350,50,7); // sb den
			thoatKhungNhap(1105,35,sanbayden_add_str,8,2,0,0);
			hinhChuNhatRong(300,10,500,50,7); // ma add
			thoatKhungNhap(305,35,mcb_add_str,8,2,0,0);
			hinhChuNhatRong(550,10,800,50,7);//time add
			thoatKhungNhap(555,35,datestart_str,8,2,0,1);
			hinhChuNhatRong(850,10,1050,50,7);//shmb add
			thoatKhungNhap(855,35,sohieumb_str,8,2,0,1);
			hinhChuNhatRong(120,220,280,260,7);//ma delete
			thoatKhungNhap(125,245,macb_delete_string,8,2,0,1);
			hinhChuNhatRong(120,360,280,400,7);//ma edit
			thoatKhungNhap(125,385,macb_edit_string,8,2,0,1);
			hinhChuNhatRong(120,430,280,470,1);//time edit
			khungNhap(125,455,datestart_edit_string,8,2,0,1,36);
		}

		if(macb_delete) {
			hinhChuNhatRong(1100,10,1350,50,7); // sb den
			thoatKhungNhap(1105,35,sanbayden_add_str,8,2,0,0);
			hinhChuNhatRong(300,10,500,50,7); // ma add
			thoatKhungNhap(305,35,mcb_add_str,8,2,0,0);
			hinhChuNhatRong(550,10,800,50,7);//time add
			thoatKhungNhap(555,35,datestart_str,8,2,0,1);
			hinhChuNhatRong(850,10,1050,50,7);//shmb add
			thoatKhungNhap(855,35,sohieumb_str,8,2,0,1);
			hinhChuNhatRong(120,220,280,260,1);//ma delete
			khungNhap(125,245,macb_delete_string,8,2,0,1,36);
			hinhChuNhatRong(120,360,280,400,7);//ma edit
			thoatKhungNhap(125,385,macb_edit_string,8,2,0,1);
			hinhChuNhatRong(120,430,280,470,7);//time edit
			thoatKhungNhap(125,455,datestart_edit_string,8,2,0,1);
		}
		if(sbden) {
			hinhChuNhatRong(1100,10,1350,50,1); // sb den
			khungNhap(1105,35,sanbayden_add_str,8,2,0,0,36);
			hinhChuNhatRong(300,10,500,50,7); // ma add
			thoatKhungNhap(305,35,mcb_add_str,8,2,0,0);
			hinhChuNhatRong(550,10,800,50,7);//time add
			thoatKhungNhap(555,35,datestart_str,8,2,0,1);
			hinhChuNhatRong(850,10,1050,50,7);//shmb add
			thoatKhungNhap(855,35,sohieumb_str,8,2,0,1);
			hinhChuNhatRong(120,220,280,260,7);//ma delete
			thoatKhungNhap(125,245,macb_delete_string,8,2,0,1);
			hinhChuNhatRong(120,360,280,400,7);//ma edit
			thoatKhungNhap(125,385,macb_edit_string,8,2,0,1);
			hinhChuNhatRong(120,430,280,470,7);//time edit
			thoatKhungNhap(125,455,datestart_edit_string,8,2,0,1);
		}			
		
		
		if(thoat==2) slideMenu(dsmb,dskh,dscb);
		else if(lui == 2 && soTrang > 1) {
			soTrang--;
			clearManHinhCB();
			xuatDsChuyenBay(dscb,soTrang);
		}
		 else if(toi == 2 && soTrang <(dscb.slcb + 9) /10) {
			soTrang++;
			clearManHinhCB();
			xuatDsChuyenBay(dscb,soTrang);
		}
		 else if(them==2) {	
			if(mcb_add_str==""||sanbayden_add_str==""||datestart_str==""||sohieumb_str=="")
			{
				chuThich(780,660,RED,"   YEU CAU NHAP DAY DU CAC TRUONG   ");
			}else if(check_space(mcb_add_str)) chuThich(780,660,RED,"    MA CHUYEN BAY KH DC CO KHOANG TRONG   ");
			else if(check_space(sohieumb_str)) chuThich(780,660,RED,"   SO HIEU MB KH DC CO KHOANG TRONG   ");
			else if(check_date(datestart_str)!=1)
			{
				switch(check_date(datestart_str))
				{
					case 0:{ 
						chuThich(780,660,RED,"      NHAP TGKH SAI FORMAT      ");
						break;
					}
					case 7:{
						chuThich(780,660,RED,"      KH THE THEM CB TRONG QUA KHU    ");
						break;
					}
					case 3:{
						chuThich(780,660,RED," THANG KH DC LON HON 12 VA NHO HON 1");
						break;
					}
					case 5:{
						chuThich(780,660,RED,"       GIO TRONG KHOAN TU 0-24       ");
						break;
					}
					case 6:{
						chuThich(780,660,RED,"      PHUT TRONG KHOANG 0-60      ");
						break;
					}
					case 4:{
						chuThich(780,660,RED,"     NGAY TRONG KHOANG 1-30       ");
						break; 
					}
				}
			}
			else if(CHECKsh_CB(dscb,mcb_add_str)) chuThich(780,660,RED,"    MA CHUYEN BAY DA TON TAI       ");
			else if(CHECKsh_MB(dsmb,sohieumb_str)) chuThich(780,660,RED,"    SO HIEU MB KH TON TAI        ");
			else if(check_conflict_cb(dscb,sohieumb_str,datestart_str)) chuThich(780,660,RED,"   MAY BAY DANG TH CHUYEN BAY KHAC    ") ;
			else{
				NODEPTR *p= new NODEPTR;
				p->cb.macb=mcb_add_str;
				p->cb.ngaygiokhoihanh=datestart_str;
				p->cb.sanbayden=sanbayden_add_str;
				p->cb.sohieumaybay=sohieumb_str;
				p->cb.slve=0;
				p->cb.trangthai=1;
				p->cb.dsve.innit(get_sochoMB(dsmb,p->cb.sohieumaybay));
				p->cb.dsve.sl=get_sochoMB(dsmb,p->cb.sohieumaybay);
				insert_first(dscb,p);
				clearManHinhCB();
				real_status(dscb);
				xuatDsChuyenBay(dscb,soTrang);
				Ghifile_CB(dscb);
				chuThich(780,660,GREEN,"    THEM CHUYEN BAY THANH CONG       ");
			}	
		}

		else if(xoa==2) {
			if(macb_delete_string=="") chuThich(780,660,RED,"      VUI LONG NHAP MA CB CAN XOA      ");
			else if(check_space(macb_delete_string)) chuThich(780,660,RED,"    MA CHUYEN BAY KH DC CO KHOANG TRONG   ");
			else if(!CHECKsh_CB(dscb,macb_delete_string)) chuThich(780,660,RED,"    MA CHUYEN BAY KHONG TON TAI       ");
			else if(!check_statusCB(dscb,macb_delete_string)) chuThich(780,660,RED,"    KH THE HUY CHUYEN BAY DA HOAN TAT     ");
			else if(!check_slveCB(dscb,macb_delete_string))chuThich(780,660,RED,"      KH THE HUY CHUYEN BAY DA CO HK DK      ");
			else{
				edit_status(dscb,macb_delete_string,0);
				clearManHinhCB();
				xuatDsChuyenBay(dscb,soTrang);
				Ghifile_CB(dscb);
				chuThich(780,660,GREEN,"      HUY CB THANH CONG            ");
			};

		}
		else if(sua==2)
		{
			if(macb_edit_string=="") chuThich(780,660,RED,"      VUI LONG NHAP MA CB CAN SUA      ");
			else if(check_space(macb_edit_string)) chuThich(780,660,RED,"    MA CHUYEN BAY KH DC CO KHOANG TRONG   ");
			else if(!CHECKsh_CB(dscb,macb_edit_string)) chuThich(780,660,RED,"    MA CHUYEN BAY KHONG TON TAI       ");
			else if(check_date(datestart_edit_string)!=1)
			{
				switch(check_date(datestart_str))
				{
					case 0:{ 
						chuThich(780,660,RED,"    NHAP T/G KHOI HANH SAI FORMAT     ");
						break;
					}
					case 7:{
						chuThich(780,660,RED,"      KH THE THEM CB TRONG QUA KHU    ");
						break;
					}
					case 3:{
						chuThich(780,660,RED," THANG KH DC LON HON 12 VA NHO HON 1");
						break;
					}
					case 5:{
						chuThich(780,660,RED,"       GIO TRONG KHOAN TU 0-24       ");
						break;
					}
					case 6:{
						chuThich(780,660,RED,"      PHUT TRONG KHOANG 0-60      ");
						break;
					}
					case 4:{
						chuThich(780,660,RED,"     NGAY TRONG KHOANG 1-30       ");
						break; 
					}
				}
			}else if(get_statusCB(dscb,macb_edit_string)==0) chuThich(780,660,RED,"     KH THE THAY DOI T/G KHOI HANH VI CB DA HUY     ");
			else if(get_statusCB(dscb,macb_edit_string)==3) chuThich(780,660,RED,"     KH THE THAY DOI T/G KHOI HANH VI CB DA HOAN TAT   ");
			else{
				edit_time(dscb,macb_edit_string,datestart_edit_string);
				clearManHinhCB();
				real_status(dscb);
				xuatDsChuyenBay(dscb,soTrang);
				
				Ghifile_CB(dscb);
				chuThich(780,660,GREEN,"      CAP NHAT T/G KHOI HANH THANH CONG       ");
			}
			
		}

	}
}

void slideQLVe(DSMB &dsmb, DS_CB &dscb, KHACHHANG &dskh) {
	cleardevice();
	nutLenh(10,10,60,40,"<");
	tieuDe(20,80,270,130,"QUAN LY VE");
	hinhChuNhatRong(20,220,220,260,7);  
	chuThich(120,290,7,"Nhap Ma Chuyen Bay");
	nutLenh(95,310,160,340,">>");
	nutLenh(1380,85,1460,520,"SO DO>>"); //so do
	chuThich(145,380,RED,"Nhap ma lop roi bam next");
	hinhChuNhatRong(320,0,470,40,7);	//cmnd
	chuThich(395,70,7,"Nhap CMND");
	hinhChuNhatRong(490,0,800,40,7);	//ho
	chuThich(645,70,7,"Ho");
	hinhChuNhatRong(820,0,1050,40,7);	//ten
	chuThich(935,70,7,"Ten");
	hinhChuNhatRong(1070,0,1200,40,7);	//phai
	chuThich(1135,70,7,"Phai");
	hinhChuNhatRong(1220,0,1320,40,7);	//gheso
	chuThich(1270,70,7,"Ghe So");
	nutLenh(520,620,590,660,"THEM");
	nutLenh(610,620,680,660,"XOA");
//	nutLenh(700,620,770,660,"SUA");
	nutLenh(970,620,1020,660,"<");
	nutLenh(1040,620,1090,660,">");

/////////////////////////////////////////BANG DANH SACH SINH VIEN THEO LOP///////////////////////////////////////////////
	tieuDe(320,80,520,120,"SO CMND");
	tieuDe(520,80,720,120,"HO");
	tieuDe(720,80,920,120,"TEN");
	tieuDe(920,80,1120,120,"PHAI");
	tieuDe(1120,80,1320,120,"GHE SO");

	for(int i=1; i<=10; i++) {
		hinhChuNhatRong(320,80+(40*i),520,80+(40*(i+1)),1);
		hinhChuNhatRong(520,80+(40*i),720,80+(40*(i+1)),1);
		hinhChuNhatRong(720,80+(40*i),920,80+(40*(i+1)),1);
		hinhChuNhatRong(920,80+(40*i),1120,80+(40*(i+1)),1);
		hinhChuNhatRong(1120,80+(40*i),1320,80+(40*(i+1)),1);
	}



	int macb=0,socmnd=0,hokh=0,tenkh=0,phaikh=0,gheso=0;
	string macb_str="",socmnd_str="",hokh_str="",tenkh_str="",phaikh_str="",gheso_str="";
	
	while(true) {
		int x=-1;
		int y=-1;
		delay(1);
		int thoat=0,next=0,them=0,xoa=0,sua=0,toi=0,lui=0, sodo=0;
		static int soTrang=1;
		if (ismouseclick(WM_LBUTTONDBLCLK)) {
			getmouseclick(WM_LBUTTONDBLCLK,x, y);
			thoat=((x>=10&&x<=60&&y>=10&&y<=40)? 2: 0);
			next=((x>=95&&x<=160&&y>=310&&y<=340)? 2: 0);
			them=((x>=520&&x<=590&&y>=620&&y<=660)? 2: 0);
			xoa=((x>=610&&x<=680&&y>=620&&y<=660)? 2: 0);
//			sua=((x>=700&&x<=770&&y>=620&&y<=660)? 2: 0);
			lui=((x>=970&&x<=1020&&y>=620&&y<=660)? 2: 0);
			toi=((x>=1040&&x<=1090&&y>=620&&y<=660)? 2: 0);
			sodo=((x>=1380&&x<=1460&&y>=85&&y<=520)? 2: 0);
		}
		
		if (ismouseclick(WM_LBUTTONDOWN)) { //nhan su kien khi click chuot trai
			getmouseclick(WM_LBUTTONDOWN, x, y);
			
			macb=((x>=20&&x<=220&&y>=220&&y<=260)? 1: 0);
			socmnd=((x>=320&&x<=470&&y>=0&&y<=40)? 1: 0);
			hokh=((x>=490&&x<=800&&y>=0&&y<=40)? 1: 0);
			tenkh=((x>=820&&x<=1050&&y>=0&&y<=40)? 1: 0);
			phaikh=((x>=1070&&x<=1200&&y>=0&&y<=40)? 1: 0);
			gheso=((x>=1220&&x<=1320&&y>=0&&y<=40)? 1: 0);


		}
		if(macb) {
//		hinhChuNhatRong(20,220,220,260,7);  
//		hinhChuNhatRong(320,0,470,40,7);	//cmnd
//		hinhChuNhatRong(490,0,800,40,7);	//ho
//		hinhChuNhatRong(820,0,1050,40,7);	//ten
//		hinhChuNhatRong(1070,0,1200,40,7);	//phai
//		hinhChuNhatRong(1220,0,1320,40,7);	//gheso
			hinhChuNhatRong(20,220,220,260,1);
			khungNhap(25,245,macb_str,8,2,0,1,36);
			hinhChuNhatRong(320,0,470,40,7);
			thoatKhungNhap(325,25,socmnd_str,8,2,0,1);
			hinhChuNhatRong(490,0,800,40,7);
			thoatKhungNhap(495,25,hokh_str,8,2,0,1);
			hinhChuNhatRong(820,0,1050,40,7);
			thoatKhungNhap(827,25,tenkh_str,8,2,0,1);
			hinhChuNhatRong(1070,0,1200,40,7);
			thoatKhungNhap(1075,25,phaikh_str,8,2,0,1);
			hinhChuNhatRong(1220,0,1320,40,7);
			thoatKhungNhap(1225,25,gheso_str,8,2,0,1);
		}
		if(socmnd) {
			hinhChuNhatRong(20,220,220,260,7);
			thoatKhungNhap(25,245,macb_str,8,2,0,1);
			hinhChuNhatRong(320,0,470,40,1);
			khungNhap(325,25,socmnd_str,8,2,0,1,36);
			hinhChuNhatRong(490,0,800,40,7);
			thoatKhungNhap(495,25,hokh_str,8,2,0,1);
			hinhChuNhatRong(820,0,1050,40,7);
			thoatKhungNhap(827,25,tenkh_str,8,2,0,1);
			hinhChuNhatRong(1070,0,1200,40,7);
			thoatKhungNhap(1075,25,phaikh_str,8,2,0,1);
			hinhChuNhatRong(1220,0,1320,40,7);
			thoatKhungNhap(1225,25,gheso_str,8,2,0,1);
//			if(macb_str.size()!=0&&macb_str.size()<5) hinhChuNhatRong(20,220,220,260,2);
//			else hinhChuNhatRong(20,220,220,260,7);
		}
		if(hokh) {
			hinhChuNhatRong(20,220,220,260,7);
			thoatKhungNhap(25,245,macb_str,8,2,0,1);
			hinhChuNhatRong(320,0,470,40,7);
			thoatKhungNhap(325,25,socmnd_str,8,2,0,1);
			hinhChuNhatRong(490,0,800,40,1);
			khungNhap(495,25,hokh_str,8,2,0,1,36);
			hinhChuNhatRong(820,0,1050,40,7);
			thoatKhungNhap(827,25,tenkh_str,8,2,0,1);
			hinhChuNhatRong(1070,0,1200,40,7);
			thoatKhungNhap(1075,25,phaikh_str,8,2,0,1);
			hinhChuNhatRong(1220,0,1320,40,7);
			thoatKhungNhap(1225,25,gheso_str,8,2,0,1);
		}
		if(tenkh) {
			hinhChuNhatRong(20,220,220,260,7);
			thoatKhungNhap(25,245,macb_str,8,2,0,1);
			hinhChuNhatRong(320,0,470,40,7);
			thoatKhungNhap(325,25,socmnd_str,8,2,0,1);
			hinhChuNhatRong(490,0,800,40,7);
			thoatKhungNhap(495,25,hokh_str,8,2,0,1);
			hinhChuNhatRong(820,0,1050,40,1);
			khungNhap(827,25,tenkh_str,8,2,0,1,36);
			hinhChuNhatRong(1070,0,1200,40,7);
			thoatKhungNhap(1075,25,phaikh_str,8,2,0,1);
			hinhChuNhatRong(1220,0,1320,40,7);
			thoatKhungNhap(1225,25,gheso_str,8,2,0,1);
		}
		if(phaikh) {
			hinhChuNhatRong(20,220,220,260,7);
			thoatKhungNhap(25,245,macb_str,8,2,0,1);
			hinhChuNhatRong(320,0,470,40,7);
			thoatKhungNhap(325,25,socmnd_str,8,2,0,1);
			hinhChuNhatRong(490,0,800,40,7);
			thoatKhungNhap(495,25,hokh_str,8,2,0,1);
			hinhChuNhatRong(820,0,1050,40,7);
			thoatKhungNhap(827,25,tenkh_str,8,2,0,1);
			hinhChuNhatRong(1070,0,1200,40,1);
			khungNhap(1075,25,phaikh_str,8,2,0,1,36);
			hinhChuNhatRong(1220,0,1320,40,7);
			thoatKhungNhap(1225,25,gheso_str,8,2,0,1);
		}
		if(gheso) {
			hinhChuNhatRong(20,220,220,260,7);
			thoatKhungNhap(25,245,macb_str,8,2,0,1);
			hinhChuNhatRong(320,0,470,40,7);
			thoatKhungNhap(325,25,socmnd_str,8,2,0,1);
			hinhChuNhatRong(490,0,800,40,7);
			thoatKhungNhap(495,25,hokh_str,8,2,0,1);
			hinhChuNhatRong(820,0,1050,40,7);
			thoatKhungNhap(827,25,tenkh_str,8,2,0,1);
			hinhChuNhatRong(1070,0,1200,40,7);
			thoatKhungNhap(1075,25,phaikh_str,8,2,0,1);
			hinhChuNhatRong(1220,0,1320,40,1);
			khungNhap(1225,25,gheso_str,8,2,0,1,3);
		}
		if(sodo==2) {
			if(macb_str=="") chuThich(200,750,RED,"      VUI LONG NHAP MA CHUYEN BAY      ");
			else if(check_space(macb_str)) chuThich(200,750,RED,"    MA CHUYEN BAY KH DC CO KHOANG TRONG   ");
			else if(!CHECKsh_CB(dscb,macb_str)) chuThich(200,750,RED,"    MA CHUYEN BAY KHONG TON TAI       ");
			else{
				slideSD_MayBay(dscb,dsmb,dskh,macb_str);
			}
		};
		if(thoat==2) slideMenu(dsmb,dskh,dscb);
		if(next==2) {
			soTrang=1;
			clear_MHve();
			if(macb_str=="") chuThich(200,750,RED,"      VUI LONG NHAP MA CHUYEN BAY      ");
			else if(check_space(macb_str)) chuThich(200,750,RED,"    MA CHUYEN BAY KH DC CO KHOANG TRONG   ");
			else if(!CHECKsh_CB(dscb,macb_str)) chuThich(200,750,RED,"    MA CHUYEN BAY KHONG TON TAI       ");
			else if(check_empty_tiket(dscb,macb_str)) chuThich(200,750,RED,"   CHUYEN BAY CHUA CO HANH KHACH DANG KY     ");
			else{
				clear_MHve();
				xuatDsVe(dscb,dskh, macb_str,soTrang);
				chuThich(200,750,GREEN,"     TAI DANH SACH VE THANH CONG     ");
			}
		}
		if(them==2) {
			if(macb_str==""||socmnd_str=="" ||hokh_str==""||tenkh_str==""||phaikh_str==""||gheso_str=="") chuThich(200,750,RED,"       VUI LONG NHAP DU CAC TRUONG        ");
			else if(check_space(macb_str)) chuThich(200,750,RED,"    MA CHUYEN BAY KH DC CO KHOANG TRONG   ");
			else if(!CHECKsh_CB(dscb,macb_str)) chuThich(200,750,RED,"    MA CHUYEN BAY KHONG TON TAI       ");
			else if(check_space(socmnd_str)) chuThich(200,750,RED,"     SO CMND KH DC CO KHOANG TRONG    ");
			else if(socmnd_str.length()<9||socmnd_str.length()>9) chuThich(200,750,RED,"       SO CMND PHAI CO 9 KY TU         ");
			else if(is_number(socmnd_str)) chuThich(200,750,RED,"       SCMND  CHI BAO GOM CAC KY TU SO        ");
			else if(check_space(tenkh_str)) chuThich(200,750,RED," TEN KHACH HANG K DUOC CO KHOANG TRONG  ");
			else if(!(phaikh_str=="NAM")&&!(phaikh_str=="NU")&&!(phaikh_str=="KHAC")) chuThich(200,750,RED," PHAI KH HOP LE CHI NHAN GIA TRI( NAM/NU/KHAC ) ");
			else if(check_space(gheso_str)) chuThich(200,750,RED,"          SO GHE  K DUOC CO KHOANG TRONG           ");
			else if(stoi(gheso_str)==0) chuThich(200,750,RED,"          SO GHE PHAI BAT DAU TU 1           ");
			else if(check_ghe(dscb,macb_str,stoi(gheso_str))) chuThich(200,750,RED,"          SO GHE  DA DUOC NGUOI KHAC DAT           ");
			else if(get_sochoMB2(dscb,dsmb,macb_str)<stoi(gheso_str)) chuThich(200,750,RED,"    SO GHE KH DC VUOT QUA SO CHO CUA MB       ");
//			else if(!check_maxslot(dscb,dsmb, macb_str,gheso_str))chuThich(200,750,RED,"      SO GHE KH VUOT QUA SO CHO CUA MAY BAY       ");
			else if(get_statusCB(dscb,macb_str)==0) chuThich(200,750,RED,"       KH THE DAT VE VI CB DA HUY       ");
			else if(get_statusCB(dscb,macb_str)==3) chuThich(200,750,RED,"       KH THE DAT VE VI CB DA HOAN TAT     ");
			else if(get_statusCB(dscb,macb_str)==2) chuThich(200,750,RED,"       KH THE DAT VE VI CB DA HET CHO      ");
			else{
				if(check_clone(dscb,macb_str,socmnd_str)) chuThich(200,750,RED,"     1 CMND KH THE DANG KY 1CB 2 LAN      ");
				else
				{
					if(check_cmnd(dskh,stoi(socmnd_str),hokh_str,tenkh_str,stoi(gheso_str)))
					{
						clear_MHve();
						add_ticket(dscb,macb_str,stoi(socmnd_str),stoi(gheso_str));
						reload_status(dscb,dsmb);
						xuatDsVe(dscb,dskh, macb_str,soTrang);
						Ghifile_CB(dscb);
						chuThich(200,750,GREEN,"         DAT VE THANH CONG           ");
					}
					else
					{
						clear_MHve();
						int gt=0;
						if(phaikh_str=="NAM") gt=1;
						else if(phaikh_str=="NU") gt=2;
						else if(phaikh_str=="KHAC") gt=0;						
						dskh= add_node(dskh,create_node(stoi(socmnd_str),hokh_str,tenkh_str,gt));
						Ghifile_KH(dskh);
						add_ticket(dscb,macb_str,stoi(socmnd_str),stoi(gheso_str));
						reload_status(dscb,dsmb);
						xuatDsVe(dscb,dskh, macb_str,soTrang);
						Ghifile_CB(dscb);
						chuThich(200,750,GREEN,"  DAT VE THANH CONG  : TEN VA CMND CUA BAN DA DC THEM VAO CSDL  ");
					}
				}	
			}
		}
		if(xoa==2) {
			if(macb_str==""||socmnd_str=="")chuThich(200,750,RED,"     VUI LONG NHAP MA CHUYEN BAY VA CMND CAN XOA      ");
			else if(check_space(macb_str)) chuThich(200,750,RED,"    MA CHUYEN BAY KH DC CO KHOANG TRONG   ");
			else if(!CHECKsh_CB(dscb,macb_str)) chuThich(200,750,RED,"    MA CHUYEN BAY KHONG TON TAI       ");
			else if(check_space(socmnd_str)) chuThich(200,750,RED,"     SO CMND KH DC CO KHOANG TRONG    ");
			else if(socmnd_str.length()<9||socmnd_str.length()>9) chuThich(200,750,RED,"      SO CMND PHAI CO 9 KY TU       ");
			else if(is_number(socmnd_str)) chuThich(200,750,RED,"       SCMND  CHI BAO GOM CAC KY TU SO        ");
			else if(get_statusCB(dscb,macb_str)==0) chuThich(200,750,RED,"       KH THE HUY VE VI CB DA HUY       ");
			else if(get_statusCB(dscb,macb_str)==3) chuThich(200,750,RED,"       KH THE HUY VE VI CB DA HOAN TAT     ");
			else if(!check_clone(dscb,macb_str,socmnd_str)) chuThich(200,750,RED,"     KH THE HUY VE KHI CHUA DAT VE      ");
			else{
				clear_MHve();
				delete_ticket(dscb,macb_str,stoi(socmnd_str));
				reload_status(dscb,dsmb);
				Ghifile_CB(dscb);
				xuatDsVe(dscb,dskh, macb_str,soTrang);
				chuThich(200,750,GREEN,"           HUY VE THANH CONG                     ");
//				chuThich(200,750,GREEN,to_string(stoi(socmnd_str)));
			}
		}
//		if(sua==2) {
//		}
		if(lui == 2 && soTrang > 1) {
			soTrang--;
			clear_MHve();
			xuatDsVe(dscb,dskh,macb_str,soTrang);
		}
		if(toi == 2 && soTrang < (get_slve(dscb,macb_str) + 9) /10) {
			soTrang++;
			clear_MHve();
			xuatDsVe(dscb,dskh,macb_str,soTrang);
		}
	}
}

bool checkto(int arr[],int x,int sl)
{
	for(int k=0;k<sl;k++)
	{
		if(x==arr[k]) return true;
		
	}
	return false;
}
void slideSD_MayBay(DS_CB dscb,DSMB dsmb, KHACHHANG dskh, string mcb){
	cleardevice();
	nutLenh(10,10,60,40,"<");
	int socho= get_sochoMB2(dscb,dsmb,mcb);
	int count=1;
	
	int *art=get_slotdk(dscb,dsmb,mcb);
	int arr[art[0]];
	int sl=art[0];
	cout<<" ::::"<<art[0]<<endl;
	for(int i=0;i<art[0];i++)
	{
		arr[i]=art[i+1];
	}	
	nutLenh(600,10,900,50,"SO DO MAY BAY");
	
	for(int i=1; i<=15; i++) {
		for(int j=1;j<=20;j++)
		{
			if(count<=socho){
			if(checkto(arr,count,sl))
			{
				hinhChuNhatDac(200+(50*j),60+(40*i),200+(50*(j+1)),60+(40*(i+1)),2);
				hinhChuNhatRong(200+(50*j),60+(40*i),200+(50*(j+1)),60+(40*(i+1)),1);
				outtextXY(225+(50*j),85+(40*i),to_string(count));
				count++;
			}
			else
			{
				hinhChuNhatDac(200+(50*j),60+(40*i),200+(50*(j+1)),60+(40*(i+1)),7);
				hinhChuNhatRong(200+(50*j),60+(40*i),200+(50*(j+1)),60+(40*(i+1)),1);
				outtextXY(225+(50*j),85+(40*i),to_string(count));
				count++;
			}
			
			}
		}
		

		}
	hinhChuNhatDac(1300,200,1350,240,2);
	chuThich(1420,225,1,"DA DUOC DAT");
	chuThich(1420,325,1,"CON TRONG");
	hinhChuNhatDac(1300,300,1350,340,7);
	while(true) {
		int x=-1;
		int y=-1;
		delay(1);
		int thoat=0;
		static int soTrang=1;
		
		if (ismouseclick(WM_LBUTTONDBLCLK)) {
			getmouseclick(WM_LBUTTONDBLCLK,x, y);
			thoat=((x>=10&&x<=60&&y>=10&&y<=40)? 2: 0);
		}
		
		if(thoat==2) slideQLVe(dsmb,dscb,dskh);
}
}
void slideLOC_ChuyenBay(DSMB &dsmb, DS_CB &dscb, KHACHHANG &dskh)
{
	cleardevice();
	nutLenh(120,400,300,445,">>");
	chuThich(200,390,7,"NGAY KHOI HANH (yyyy/MM/dd)");
	chuThich(200,250,7,"SAN BAY DEN");
	hinhChuNhatRong(120,260,310,300,7);	//
	hinhChuNhatRong(120,330,310,370,7);	// 
	
	
	static int soTrang=1;
	nutLenh(10,10,60,40,"<");
	int sbden=0, datestart=0;
	string sbden_string="" ,datestart_string="";

	while(true) {
		int x=-1;
		int y=-1;
		delay(1);
		//--------------------------------------------- tiêu dê cau bang--------------
	
		tieuDe(450,120,700,160,"MA CHUYEN BAY");
		tieuDe(700,120,1000,160,"NGAY GIO KHOI HANH");
		tieuDe(1000,120,1250,160,"SO VE CON LAI");
		line(0,115,1800,115);
		
		
		
		//---------------------------------------------------full bottom----
		
		nutLenh(1270,620,1320,660,">");
		nutLenh(1200,620,1250,660,"<");
		
		//-----------------------------------------------ve 10 khung cua table---
		for(int i=1; i<=10; i++) {

		
			hinhChuNhatRong(450,120+(40*i),700,120+(40*(i+1)),1);
			hinhChuNhatRong(700,120+(40*i),1000,120+(40*(i+1)),1);
			hinhChuNhatRong(1000,120+(40*i),1250,120+(40*(i+1)),1);

		}
		
		//------------------------------------bat các nut them xoa sua toi lui--------
		int thoat=0,toi=0,lui=0, next=0;
		if (ismouseclick(WM_LBUTTONDBLCLK)) {
			getmouseclick(WM_LBUTTONDBLCLK,x, y);
			next=((x>=120&&x<=300&&y>=400&&y<=445)? 2: 0);
			thoat=((x>=10&&x<=60&&y>=10&&y<=40)? 2: 0);
			toi=((x>=1270&&x<=1320&&y>=620&&y<=660)? 2: 0);
			lui=((x>=1200&&x<=1250&&y>=620&&y<=660)? 2: 0);
		}
		
		
		
		//-------------------------------- bat khi bam vao header khung nhap -----
		if (ismouseclick(WM_LBUTTONDOWN)) {
			getmouseclick(WM_LBUTTONDOWN, x, y);
			

			sbden=((x>=120 && x<=310 && y>=260 && y<=300)? 1: 0);
			datestart=((x>=120 && x<=310 && y>=330 && y<=370)? 1: 0);
		}
//		
		
		if(sbden) {
			hinhChuNhatRong(120,260,310,300,1); // sb den
			khungNhap(125,285,sbden_string,8,2,0,0,36);
			hinhChuNhatRong(120,330,310,370,7);//time add
			thoatKhungNhap(125,355,datestart_string,8,2,0,1);
		
		}
		if(datestart) {
			hinhChuNhatRong(120,260,310,300,7); // sb den
			thoatKhungNhap(125,285,sbden_string,8,2,0,0);
			hinhChuNhatRong(120,330,310,370,1);//time add
			khungNhap(125,355,datestart_string,8,2,0,1,36);
		}
		if(thoat==2) slideMenu(dsmb,dskh,dscb);
		if(next==2)
		{
			if(datestart_string==""||sbden_string=="") chuThich(780,660,RED,"      YEU CAU NHAP DU CAC TRUONG        ");
			else if(!check_fomat_time(datestart_string)) chuThich(780,660,RED,"    NHAP LAI NGAY DUOI DANG YYYY/MM/DD   ");
			else if(!check_placedate_cb(dscb,sbden_string,datestart_string)==0) chuThich(780,660,RED,"    KH CO CHUYEN BAY NAO THOA DK     ");
			else{
				clearDs_find();
				xuatDs_find(dscb,dsmb,datestart_string,sbden_string,soTrang);
				chuThich(780,660,GREEN,"    SO LIEU DC CHAP NHAN   ");
			}
		}
		if(lui == 2 && soTrang > 1) {
			soTrang--;
			clearDs_find();
			xuatDs_find(dscb,dsmb,datestart_string,sbden_string,soTrang);
		}
		if(toi == 2 && soTrang < (get_slcbfind(dscb,datestart_string,sbden_string) + 9) /10) {
			soTrang++;
			clearDs_find();
			xuatDs_find(dscb,dsmb,datestart_string,sbden_string,soTrang);
		}
		
	}
		
}

int main(int argc, char *argv[]) {	

	
	
	initwindow(1800, 800);
	setbkcolor(15);
	DSMB dsmb;
	KHACHHANG dskh= NULL;
	DS_CB    dscb;
	Docfile_MB(dsmb,"DSMAYBAY.txt");	
	Docfile_CB(dscb,dsmb);
	Docfile_KH(dskh);
	real_status(dscb);
//	timenow();

//	NLR(dskh);
//	print_list(dscb);
	slideMenu(dsmb,dskh,dscb);
	return 0;
}

