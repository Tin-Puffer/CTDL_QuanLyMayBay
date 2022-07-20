#include <graphics.h>
#include <bits/stdc++.h>
using namespace std;
//VE HINH CHU NHAT
int BACKSPACE=8;
void hinhChuNhatRong(int left, int top, int right, int bottom, int color) {
	setcolor(color);//chon mau to cho hinh chu nhat rong
	rectangle(left,top,right,bottom);//ve hinh chu nhat dac
}
//HINH CHU NHAT DAC
void hinhChuNhatDac(int left, int top, int right, int bottom, int color) {
	setfillstyle(SOLID_FILL, color);//chon mau to cho hinh chu nhat dac
	bar(left,top,right,bottom);//ve hinh chu nhat dac
}


//HAM IN CHU LEN TOA DO TREN MAN HINH
void outtextXY(int x, int y, const string &str) {
	char * cstr = new char [(int)str.length()+1];
	strcpy (cstr, str.c_str());
	settextstyle(3, HORIZ_DIR, 1);
	outtextxy(x,y,cstr);
	delete[] cstr;
}
//HAM NHAP VAN BAN ROI IN MAU NEN CHO VAN BAN DO
void vanBan(int x, int y,const string &text, int color, int bkcolor, int font, int charsize, int horiz, int vert) {
	//horiz=0, 1, 2 hieu la van ban xuat hien ben phai, tam, trai con chay
	//vert=0, 1, 2 hieu la van ban xuat hien tren, giua, duoi con chay
	setcolor(color);//chon mau cho van ban
	setbkcolor(bkcolor);//chon mau nen cho van ban
	//chon kieu chu, co chu, HORIZ_DIR(nam ngang) trong chuong trinh nay khong co van ban nam doc
	settextstyle(font, HORIZ_DIR, charsize);
	settextjustify(horiz, vert);//vi tri hien thi cua van ban
	outtextXY(x,y,text);
}
//HAM NHAP 1 NUT TRONG BAI MAU GREEN
void nutLenh(int left,int top,int right,int bottom,const string &text) {
	setcolor(2);
	settextjustify(1,1);
	outtextXY((right+left)/2,((bottom+top)/2)+5,text);
	rectangle(left,top,right,bottom);
}
void chuThich(int x,int y,int color, const string &str) {
	char * cstr = new char [(int)str.length()+1];
	strcpy (cstr, str.c_str());
	settextstyle(8, HORIZ_DIR, 1);
	setcolor(color);
	outtextxy(x,y,cstr);
	delete[] cstr;
}
//HAM NUT TIEU DE MAU BLUE
void tieuDe(int left,int top,int right,int bottom,const string &text) {
	setcolor(1);
	settextjustify(1,1);
	outtextXY((right+left)/2,((bottom+top)/2)+5,text);
	rectangle(left,top,right,bottom);
}
//HAM KHUNG NHAP THONG TIN
void khungNhap(int x, int y, string &text, int font, int charsize, int horiz, int vert, int limit) {
	static int temp=0;//bien co chuc nang trong viec tao dau nhap nhay
	temp=(temp+1)%20;
//	int WHITE=15;
//	int BLACK=0;

	if(kbhit()) {
		char u=getch();
		int v=u;
		if(v==BACKSPACE && text.length()>0) {
			text.push_back(u);
			vanBan(x,y, text, WHITE, WHITE, 8, 2, 0, 1);
			text.pop_back();
			text.pop_back();
			vanBan(x,y, text, BLACK, WHITE, 8, 2, 0, 1);
		} else if(limit==5) {
			if(text.length()<5 && u>='0' && u<='9') {
				text.push_back(u);
				vanBan(x,y, text, BLACK, WHITE, 8, 2, 0, 1);
			}
		} else if(limit>25) {
			if(text.length()<min(68, limit) && u>=32 && u<127) {
				text.push_back(u);
				vanBan(x,y, text, BLACK, WHITE, 8, 2, 0, 1);
			}
		} else if(text.length()<min(68, limit) && ((u>='A' && u<='Z') || u=='_' || u=='-' || (u>='0' && u<='9') || u == ' ')) {
			text.push_back(u);
			vanBan(x,y, text, BLACK, WHITE, 8, 2, 0, 1);
		}
	} else {
		if(temp<=10) {
			text.push_back('|');
			vanBan(x,y,text,BLACK,WHITE,8,2,0,1);
			text.pop_back();
		} else {
			text.push_back(' ');
			vanBan(x,y,text,BLACK,WHITE,8,2,0,1);
			text.pop_back();
			vanBan(x,y,text,BLACK,WHITE,8,2,0,1);
		}
		delay(1);
	}
}
//HAM THOAT KHUNG NHAP
void thoatKhungNhap(int x, int y, string &text, int font, int charsize, int horiz, int vert) {
	text.push_back(' ');
	vanBan(x,y,text,WHITE,WHITE,8,2,0,1);
	text.pop_back();
	vanBan(x,y,text,BLACK,WHITE,8,2,0,1);
}
