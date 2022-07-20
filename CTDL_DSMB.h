#include<iostream>
#include <fstream>
#include"DoHoa.h"
#define MaxMB 300
using namespace std;
struct MayBay{
	string SoHieu;
	string Loai;
	int SoCho;
};
struct DSMB{
	MayBay *MB[MaxMB];
	int sl;
	DSMB(){
		
		sl=0;
	};
};
void SHOW_DSMB(DSMB &x);
void ADD_MB(DSMB &x,MayBay *y);

string UPDATE_MB(DSMB &x,string sh, string loai,int socho){
	
	for(int i=0;i<x.sl;i++) //0->18
	{
		if(x.MB[i]->SoHieu==sh)	{
			
			x.MB[i]->Loai=loai;
			x.MB[i]->SoCho=socho;
			return "update du lieu thanh cong";
		}
		
	}
	 return "update that bai";
}
void  Ghifile_MB(DSMB x)
{
	fstream f; 
	f.open("DSMAYBAY.txt", ios::out);
	f<<x.sl<<endl;
	for(int i=0;i<x.sl;i++)
	{
		f<<x.MB[i]->SoHieu<<endl;
		f<<x.MB[i]->Loai<<endl;
		f<<x.MB[i]->SoCho<<endl;
	}
	f.close(); // (4)
}
void Docfile_MB(DSMB &x, string name_file)
{
	ifstream f;
	f.open(name_file);
	int sl;
	f>>sl;
	

	for(int i=0;i<sl;i++)
	{
		MayBay *p= new MayBay();
		f>>p->SoHieu;
//		f>>p->Loai;
		f >> ws;
		getline(f, p->Loai);
		f>>p->SoCho;
		ADD_MB(x,p);
	}
	f.close();
}

void ADD_MB(DSMB &x,MayBay *y){
	x.MB[x.sl]= new MayBay();
	x.MB[x.sl]=y;
	x.sl++;
}
void DELETE_MB(DSMB &x,string str)
{
	MayBay *p;
	for(int i=0;i<x.sl;i++) //0->18
	{
		if(x.MB[i]->SoHieu==str)	{
			
			for(int j=i;j<x.sl;j++)
			{
				x.MB[j]=x.MB[j+1];
			}
			p=x.MB[x.sl-1];
			x.sl--;
			break;
		}
	}
}
int CHECKsh_MB(DSMB &x,string str)
{
	for(int i=0;i<x.sl;i++) //0->18
	{
		if(x.MB[i]->SoHieu==str)	{
			return 0;
		}
		
	}
	return 1;
}
void SHOW_DSMB(DSMB &x)
{
	if(x.sl==0) cout<<"k co may bay nao trong trai";
	else{
		for(int i= 0;i<x.sl;i++)
		{
			
			cout<<x.MB[i]->SoHieu<<endl;
			cout<<x.MB[i]->Loai<<endl;
			cout<<x.MB[i]->SoCho<<endl;
		}
	}
}
void xuatDsMayBay(DSMB &x,int &soTrang) {
	if(x.sl!=0)
	{
		for(int i=10 * (soTrang - 1), j = 0; i< min(10 * soTrang, x.sl); i++, j++) {
		outtextXY(300,185+(40*j),x.MB[i]->SoHieu);
		outtextXY(705,185+(40*j),x.MB[i]->Loai);
		outtextXY(1115,185+(40*j),to_string(x.MB[i]->SoCho));
	}
	}
		
}
//void clearManHinhLTC() {
//	for(int i=0; i<10; i++) {
//		outtextXY(160,185+(40*i),"                                                         ");
//		outtextXY(290,185+(40*i),"                                                                 ");
//		outtextXY(585,185+(40*i),"                                                                     ");
//		outtextXY(900,185+(40*i),"                                                                   ");
//		outtextXY(1020,185+(40*i),"                                                        ");
//		outtextXY(1080,185+(40*i),"                                                          ");
//		outtextXY(1150,185+(40*i),"                                                          ");
//		outtextXY(1250,185+(40*i),"                                                                  ");
//	}
//	for(int i=0; i<10; i++) {
//			hinhChuNhatRong(100,120+(40*i),520,120+(40*(i+1)),1);
//			hinhChuNhatRong(520,120+(40*i),920,120+(40*(i+1)),1);
//			hinhChuNhatRong(920,120+(40*i),1320,120+(40*(i+1)),1);
//	}
//}
void clearManHinhMB() {
	for(int i=0; i<10; i++) {
		outtextXY(160,185+(40*i),"                                                         ");
		outtextXY(290,185+(40*i),"                                                                 ");
		outtextXY(585,185+(40*i),"                                                                     ");
		outtextXY(900,185+(40*i),"                                                                   ");
		outtextXY(1020,185+(40*i),"                                                        ");
		outtextXY(1080,185+(40*i),"                                                          ");
		outtextXY(1150,185+(40*i),"                                                          ");
		outtextXY(1250,185+(40*i),"                                                                  ");
	}
//	for(int i=0; i<10; i++) {
//		hinhChuNhatRong(100,120+(40*i),220,120+(40*(i+1)),1);
//		hinhChuNhatRong(220,120+(40*i),370,120+(40*(i+1)),1);
//		hinhChuNhatRong(370,120+(40*i),780,120+(40*(i+1)),1);
//		hinhChuNhatRong(780,120+(40*i),1000,120+(40*(i+1)),1);
//		hinhChuNhatRong(1000,120+(40*i),1050,120+(40*(i+1)),1);
//		hinhChuNhatRong(1050,120+(40*i),1120,120+(40*(i+1)),1);
//		hinhChuNhatRong(1120,120+(40*i),1220,120+(40*(i+1)),1);
//		hinhChuNhatRong(1220,120+(40*i),1320,120+(40*(i+1)),1);
//	}
}







