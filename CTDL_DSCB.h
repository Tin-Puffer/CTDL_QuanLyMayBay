#include<iostream>
#include <fstream>
#include<ctime>
#include <sstream> 
#include "CTDL_KH.h"
using namespace std;
string timenow();
struct ve{
	int cmnd;
	int socho;
};
struct danhsachve{
	int sl=0;
	ve *nodes;
	void innit(int _sl){
		sl=_sl;
		nodes= new ve[sl];
	}
};

struct chuyenbay
{
	string macb;
	string   ngaygiokhoihanh;
	string sanbayden;
	int 	trangthai;
	string sohieumaybay;
	int slve=0;
	danhsachve dsve;
};

struct NODEPTR{
	chuyenbay cb;
	NODEPTR  *next;
};
struct DS_CB{
	NODEPTR* first=NULL;
	int slcb=0;
};
void insert_first(DS_CB &x, NODEPTR *p)
{
	if(x.first==NULL) 
	{
		x.first=p;	
		x.slcb=1;
	}
	else{
		p->next=x.first;
		x.first=p;
		x.slcb++;
	}
}
void edit_time(DS_CB &x,string mcb, string time)
{
	NODEPTR *p;
	if(x.first!=NULL)
	{
		p=x.first;
		for(int i=0; i<x.slcb;i++)
		{
			if(p->cb.macb==mcb)
			{
				p->cb.ngaygiokhoihanh=time;
				break;
			}
			p=p->next;
		}
	}
}
void edit_status(DS_CB &x,string mcb, int st)
{
	NODEPTR *p;
	if(x.first!=NULL)
	{
		p=x.first;
		for(int i=0; i<x.slcb;i++)
		{
			if(p->cb.macb==mcb)
			{
				p->cb.trangthai=st;
				break;
			}
			p=p->next;
		}
	}
}
void add_ticket(DS_CB &x, string mcb, int cnmd_, int ghe_)
{
	NODEPTR *p;
	if(x.first!=NULL)
	{
		p=x.first;
		for(int i=0; i<x.slcb;i++)
		{
			if(p->cb.macb==mcb)
			{
				
				int tmpsl=p->cb.slve;	
				p->cb.dsve.nodes[tmpsl].cmnd=cnmd_;
				p->cb.dsve.nodes[tmpsl].socho=ghe_;
				p->cb.slve=p->cb.slve+1;
				break;
			}
			p=p->next;
			
		}
	}
	
}
void delete_ticket(DS_CB &x, string mcb, int cnmd_)
{
	NODEPTR *p;
	if(x.first!=NULL)
	{
		p=x.first;
		for(int i=0; i<x.slcb;i++)
		{
			if(p->cb.macb==mcb)
			{
				for(int j=0;j<p->cb.slve;j++)
				{
					cout<<"cmnd :"<<p->cb.dsve.nodes[j].cmnd<<" so sanh "<<cnmd_<<endl;
					if(p->cb.dsve.nodes[j].cmnd==cnmd_)
					{
//						p->cb.dsve.nodes[j]=p->cb.dsve.nodes[j+1];
//						p->cb.slve-=1;
						for(int k=j;k<p->cb.slve-1;k++)
						{
							p->cb.dsve.nodes[k]=p->cb.dsve.nodes[k+1];
						}
						p->cb.slve-=1;
						break;
					}
				}
			}
			p=p->next;
			
		}
	}
}
void print_list(DS_CB x)
{
	NODEPTR *p;
	if(x.first!=NULL)
	{
		p=x.first;
		cout<<"--------------"<<x.slcb<<"----------------"<<endl;
		for(int i=0; i<x.slcb;i++)
		{
			
			cout<<"macb: "<<p->cb.macb<<endl;
			cout<<"time: "<<p->cb.ngaygiokhoihanh<<endl;
			cout<<"trang thai: "<<p->cb.trangthai<<endl;
			cout<<"so ve cua chuyen bay: "<< p->cb.slve<<endl;
			cout<<"--------------------------------------"<<endl;
		
			if(p->cb.slve!=0)
			{
				for(int j=0;j<p->cb.slve;j++)
				{
					cout<<"|--|so cmnd: "<<p->cb.dsve.nodes[j].cmnd<<" - ghe: "<<p->cb.dsve.nodes[j].socho<<endl;	
				}
				cout<<"=========================================="<<endl;
	
			}
			p=p->next;
		}
	}
}
int check_deleteMB(DS_CB x, string mamb)
{
	NODEPTR *p;
	p=x.first;
	for(int i=0; i<x.slcb;i++)
	{
		
		if(p->cb.sohieumaybay==mamb  )
		{
			if(p->cb.trangthai!=0 && p->cb.trangthai!=3)
			{
				return 1;
				break;	
			}
			
		}
		p=p->next;	
	}
	return 0;
}
void  Ghifile_CB(DS_CB x)
{
	fstream f; 
	f.open("DSCB.TXT", ios::out );
	NODEPTR *p;
	if(x.first!=NULL)
	{
		p=x.first;
		f<<x.slcb<<endl;
		for(int i=0;i<x.slcb;i++)
		{
			f<<p->cb.macb<<endl;
			f<<p->cb.ngaygiokhoihanh<<endl;
			f<<p->cb.sanbayden<<endl;
			f<<p->cb.sohieumaybay<<endl;
			f<<p->cb.trangthai<<endl;
			if(p->cb.slve!=0)
			{
				f<<p->cb.slve<<endl;
				for(int j=0;j<p->cb.slve;j++)
				{
					f<<p->cb.dsve.nodes[j].cmnd<<endl;
					f<<p->cb.dsve.nodes[j].socho<<endl;	
				}
			}
			f<<"*"<<endl;
			p=p->next;
		}
	}
	
	f.close(); // (4)
}
int get_sochoMB(DSMB x, string shmb)
{
	for(int i=0; i<x.sl;i++)
	{
		if(x.MB[i]->SoHieu==shmb)
		{
			return x.MB[i]->SoCho;
		}
	}
}
int get_sochoMB2(DS_CB x,DSMB y, string mcb)
{
	NODEPTR *p;
	if(x.first!=NULL)
	{
		p=x.first;
		for(int i=0; i<x.slcb;i++)
		{
			if(p->cb.macb==mcb)
			{
				return get_sochoMB(y, p->cb.sohieumaybay);
			}
			p=p->next;
		}
		
	}
}
int *get_slotdk(DS_CB x,DSMB y, string mcb)
{
	NODEPTR *p;
	int *slot;
	if(x.first!=NULL)
	{
		p=x.first;
		for(int i=0; i<x.slcb;i++)
		{
			if(p->cb.macb==mcb)
			{
				slot= new int[p->cb.slve+1];
				slot[0]=p->cb.slve;
				for(int j=1;j<=p->cb.slve;j++)
				{
					slot[j]=p->cb.dsve.nodes[j-1].socho;
				}
			}
			p=p->next;
		}
		return slot;
		
	}
}
void Docfile_CB(DS_CB &x,DSMB k){
	ifstream f;
	f.open("DSCB.txt");
	int sl,count;
	string st;
	f>>sl;	
	for(int i=0;i<sl;i++)
	{
		NODEPTR *p= new NODEPTR;
		
		f>>p->cb.macb;
//		p->cb.dsve.innit(100);
		
		p->cb.dsve.sl=get_sochoMB(k,p->cb.sohieumaybay);
		f>>p->cb.ngaygiokhoihanh;
		f >> ws;
		getline(f, p->cb.sanbayden);
		f>>p->cb.sohieumaybay;
		cout<<"ma cb: "<<p->cb.macb<<"  duoc cap phat: "<<get_sochoMB(k,p->cb.sohieumaybay)<<" bo nho"<<endl;
		p->cb.dsve.innit(get_sochoMB(k,p->cb.sohieumaybay));
		f>>p->cb.trangthai;
		f>>st;
		if(st!="*")
		{
			stringstream str2num(st);
			str2num >> count; 
			p->cb.slve=count;
			for(int j=0;j<p->cb.slve;j++)
			{
				
				f>>p->cb.dsve.nodes[j].cmnd;
				f>>p->cb.dsve.nodes[j].socho;
			}
			f>>st;
		}
		p->next=NULL;
		insert_first(x,p);
	}
	f.close();
}
void real_status(DS_CB &x)
{
	NODEPTR *p;
	if(x.first!=NULL)
	{
		p=x.first;
		for(int i=0; i<x.slcb;i++)
		{
			if(p->cb.ngaygiokhoihanh<timenow() && p->cb.trangthai!=0)
			{
				p->cb.trangthai=3;
			}
			p=p->next;
		}
		
	}
}
int check_slveCB(DS_CB x,string ma)
{
	NODEPTR *p;
	if(x.first!=NULL)
	{
		p=x.first;
		for(int i=0; i<x.slcb;i++)
		{
			if(p->cb.macb==ma&& p->cb.slve==0)
			{
				return 1;
			}
			p=p->next;
		}
		return 0;	
	}
}
int check_statusCB(DS_CB x,string ma)
{
	NODEPTR *p;
	if(x.first!=NULL)
	{
		p=x.first;
		for(int i=0; i<x.slcb;i++)
		{
			if(p->cb.macb==ma&& p->cb.trangthai!=3)
			{
				return 1;
			}
			p=p->next;
		}
		return 0;	
	}
}
int get_statusCB(DS_CB x,string ma)
{
	NODEPTR *p;
	if(x.first!=NULL)
	{
		p=x.first;
		for(int i=0; i<x.slcb;i++)
		{
			if(p->cb.macb==ma&& p->cb.trangthai==3)
			{
				return 3;
			}
			else if(p->cb.macb==ma&& p->cb.trangthai==0)
			{
				return 0;
			}
			else if(p->cb.macb==ma&& p->cb.trangthai==2)
			{
				return 2;
			}
			p=p->next;
		}
		return 1;	
	}
}
int check_space(string str)
{
	for(int i=0;i<str.length();i++)
	{
		if(str[i]==' '){
			return 1;
			break;
		}
	}
	return 0;
}
int check_socho( DS_CB x, string mamb)
{
	NODEPTR *p;
	int min = 0;
	if(x.first!=NULL)
	{
		p=x.first;
		for(int i=0; i<x.slcb;i++)
		{
			if(p->cb.sohieumaybay==mamb)
			{
				for(int j=0;j<p->cb.slve;j++)
				{
					if(p->cb.dsve.nodes[j].socho>min)
					{
						min=p->cb.dsve.nodes[j].socho;	
					}
				}
				return min;
			}
			p=p->next;
		}
	}
}
int check_ghe(DS_CB x,string mcb,int soghe)
{
	NODEPTR *p;
	int min = 0;
	if(x.first!=NULL)
	{
		p=x.first;
		for(int i=0; i<x.slcb;i++)
		{
			if(p->cb.macb==mcb)
			{
				for(int j=0;j<p->cb.slve;j++)
				{
					if(p->cb.dsve.nodes[j].socho==soghe)
					{
						min=1;
						return min;
					}
				}
				
			}
			p=p->next;
		}
	}	
	return min;
}
void clearManHinhCB() {
	for(int i=0; i<10; i++) {
		outtextXY(370,185+(40*i),"          ");
		outtextXY(590,185+(40*i),"                                                        ");
		outtextXY(800,185+(40*i),"                                                        ");
		outtextXY(1010,185+(40*i),"                                                        ");
		outtextXY(1260,185+(40*i),"                                                ");
//		outtextXY(1080,185+(40*i),"                                                          ");
//		outtextXY(1150,185+(40*i),"                                                          ");
//		outtextXY(1250,185+(40*i),"                                                                  ");
	}
}
struct dscb_print{
	string macb;
	string time;
	int tt;
	string sh;
	string sbden;
};
void xuatDsChuyenBay(DS_CB &x,int &soTrang) {
	if(x.slcb!=0)
	{	
		NODEPTR *p;
		p=x.first;
		dscb_print prin[x.slcb];
		for(int i=0;i<x.slcb;i++)
		{
			prin[i].macb=p->cb.macb;
			prin[i].time=p->cb.ngaygiokhoihanh;
			prin[i].tt=p->cb.trangthai;
			prin[i].sh=p->cb.sohieumaybay;
			prin[i].sbden=p->cb.sanbayden;
			p=p->next;
		}
		for(int i=10 * (soTrang - 1), j = 0; i< min(10 * soTrang, x.slcb); i++, j++) {
			outtextXY(370,185+(40*j),prin[i].macb);
			outtextXY(590,185+(40*j),prin[i].time);
//			outtextXY(370,185+(40*j),p->cb.macb);
//			outtextXY(590,185+(40*j),p->cb.ngaygiokhoihanh);
			switch(prin[i].tt)
			{
				case 0: {
					outtextXY(800,185+(40*j),"DA HUY");
					break;
				}
				case 1: {
					outtextXY(800,185+(40*j),"CON VE");
					break;
				}
				case 2: {
					outtextXY(800,185+(40*j),"HET VE");
					break;
				}
				case 3: {
					outtextXY(800,185+(40*j),"HOAN TAT");
					break;
				}
			}
			outtextXY(1010,185+(40*j),prin[i].sh);
			outtextXY(1260,185+(40*j),prin[i].sbden);
	}
	}
		
}
string timenow()
{
	time_t baygio = time(0); 
    tm *ltm = localtime(&baygio); 
	string ngay="", thang="", nam="", gio="",phut="";
	string now;
    int ngay_now, thang_now, nam_now, gio_now, phut_now;	
	ngay_now= ltm->tm_mday;
	thang_now=1 + ltm->tm_mon;
	nam_now=1900 + ltm->tm_year;
	gio_now=ltm-> tm_hour;
	phut_now= 1 + ltm->tm_min;
	cout<<"thoi gian hien tai :"<<nam_now<<"/"<<thang_now<<"/"<<ngay_now<<"-"<<gio_now<<":"<<phut_now<<endl;
	stringstream s1;
	s1 << ngay_now;  
 	s1 >> ngay;
 	stringstream s2;
 	s2 << gio_now;  
 	s2 >> gio;
 	stringstream s3;
 	s3 << phut_now;
 	if(phut_now<10)
 	{
 		string tmp;
 		s3 >> tmp;
 		phut= "0" +tmp;
	 }
	 else
	 {
		  
 		s3 >> phut;
	 }

 	stringstream s4;
 	s4 << thang_now;  
 	s4 >> thang;
 	stringstream s5;
 	s5 << nam_now;  
 	s5 >> nam;
 	if(thang.length()<2)
 	{
 		thang.insert(thang.begin()+0, '0');
	 }
	 if(ngay.length()<2)
 	{
 		ngay.insert(ngay.begin()+0, '0');
	 }
	 if(gio.length()<2)
 	{
 		gio.insert(gio.begin()+0, '0');
	 }
	 if(phut.length()<2)
 	{
 		phut.insert(ngay.begin()+0, '0');
	 }
	 now = nam+"/"+thang+"/"+ngay+"-"+gio+":"+phut;
//	cout<<"thoi gian hien tai :"<<nam<<"/"<<thang<<"/"<<ngay<<"-"<<gio<<":"<<phut<<endl;
	return now;
}

int check_date(string d)
{
	timenow();
	if(d.length()==16&&d[4]=='/'&&d[7]=='/'&&d[10]=='-'&&d[13]==':' )
	{
//		2022/05/22-21:23
		string thang = d.substr(5,6);
		string ngay = d.substr(8,9);
		string gio = d.substr(11,12);
		string phut = d.substr(14,15);
		int ngayi,thangi, gioi,phuti;
		stringstream s1;
		s1 << ngay;  
 		s1 >> ngayi;
 		stringstream s2;
 		s2 << gio;  
 		s2 >> gioi;
 		stringstream s3;
 		s3 << phut;  
 		s3 >> phuti;
 		stringstream s4;
 		s4 << thang;  
 		s4 >> thangi;
		if(thangi>12||thangi<1) {
			return 3;
		}
		if(ngayi>30||ngayi<1) {
			return 4;
		}
		if(gioi>23||gioi<0) {
			return 5;
		}
		if(phuti>60||phuti<0) {
			return 6;
		}
		if(d<=timenow())
		{
			return 7;
		}
		d.erase(d.begin() + 4);
		d.erase(d.begin() + 6);
		d.erase(d.begin() + 8);
		d.erase(d.begin() + 10);
		for(int i=0;i<d.length();i++)
		{
			if(d[i]<48||d[i]>57)
			{
				return 0;
			}	
		}
		return 1;
	}
	else return 0;
}
int check_fomat_time(string d)
{
	if(d.length()==10&&d[4]=='/'&&d[7]=='/')
	{
		d.erase(d.begin() + 4);
		d.erase(d.begin() + 6);
		for(int i=0;i<d.length();i++)
		{
			if(d[i]<48||d[i]>57)
			{
				return 0;
			}	
		}
		return 1;
	}
	else return 0;
}
string get_time(string d)
{
	string st=d.substr(0,10);
	cout<<st<<endl;
	return st;
}
int CHECKsh_CB(DS_CB x,string str)
{
	NODEPTR *p;
	if(x.first!=NULL)
	{
		p=x.first;
		for(int i=0; i<x.slcb;i++)
		{
			if(p->cb.macb==str) return 1;
			p=p->next;
		}
	}
	return 0;
}
int get_slve(DS_CB x, string ma)
{
	NODEPTR *p;
	if(x.first!=NULL)
	{
		p=x.first;
		for(int i=0; i<x.slcb;i++)
		{
			if(p->cb.macb==ma) return p->cb.slve;
			p=p->next;
		}
	}
	return 0;	
}
int check_conflict_cb(DS_CB &x, string shmb, string date)
{
	NODEPTR *p;
	if(x.first!=NULL)
	{
		p=x.first;
		for(int i=0; i<x.slcb;i++)
		{
//			cout<<p->cb.sohieumaybay.length()<<" : "<<shmb.length()<<endl;
			if(p->cb.sohieumaybay==shmb&& p->cb.trangthai!=0)
			{
				cout<<"how"<<endl;
				if(get_time(p->cb.ngaygiokhoihanh)==get_time(date))
				return 1;
			}
			p=p->next;
		}
		
	}
	return 0;
}
//-----------------------------------------------------------------------------------------------VE-------------------------------------------------
struct print_ticket{
	int cmnd_tk;
	string ho_tk;
	string ten_tk;
	int phai_tk;
	int soghe_tk;
};
void find_IM(KHACHHANG root,print_ticket &pr)
	{
		if(root!=NULL)
		{
			if(root->cmnd==pr.cmnd_tk)
			{
				pr.ho_tk=root->ho;
				pr.ten_tk=root->ten;
				pr.phai_tk=root->phai;
			}
			find_IM(root->left,pr);
			find_IM(root->right,pr);
		}
	}
void clear_MHve(){

	for(int j=0; j<10; j++) 
	{
					outtextXY(350,148+(40*j),"                       ");
					outtextXY(600,148+(40*j),"                         ");
					outtextXY(800,148+(40*j), "                       ");
					outtextXY(1000,148+(40*j),"                      ");
					outtextXY(1200,148+(40*j), "             ");	
				}
				
	for(int i=1; i<=10; i++) {
		hinhChuNhatRong(320,80+(40*i),520,80+(40*(i+1)),1);
		hinhChuNhatRong(520,80+(40*i),720,80+(40*(i+1)),1);
		hinhChuNhatRong(720,80+(40*i),920,80+(40*(i+1)),1);
		hinhChuNhatRong(920,80+(40*i),1120,80+(40*(i+1)),1);
		hinhChuNhatRong(1120,80+(40*i),1320,80+(40*(i+1)),1);
	}
}
void xuatDsVe(DS_CB &x,KHACHHANG y, string ma,int soTrang){
	NODEPTR *p;	
	if(x.first!=NULL)
	{
		p=x.first;
		for(int i=0; i<x.slcb;i++)
		{
			if(p->cb.macb==ma && p->cb.slve!=0)
			{
				print_ticket dstk[p->cb.slve];
				int list_cmnd[p->cb.slve];
				for(int j=0;j<p->cb.slve;j++)
				{
					dstk[j].cmnd_tk=p->cb.dsve.nodes[j].cmnd;
					dstk[j].soghe_tk=p->cb.dsve.nodes[j].socho;
				}
				for( int j=0;j<p->cb.slve;j++)
				{
					find_IM(y,dstk[j]);
				}
				for(int j=10 * (soTrang - 1), k = 0; j< min(10 * soTrang, p->cb.slve); j++, k++) {

					string cm=to_string(dstk[j].cmnd_tk);
					if(cm.length()==8)
					{
						outtextXY(350,148+(40*k),"0"+to_string(dstk[j].cmnd_tk));
					}
					else outtextXY(350,148+(40*k),to_string(dstk[j].cmnd_tk));
					outtextXY(590,148+(40*k),dstk[j].ho_tk);
					outtextXY(800,148+(40*k),dstk[j].ten_tk);
					if(dstk[j].phai_tk==1) outtextXY(1000,148+(40*k),"NAM");
					else if(dstk[j].phai_tk==2) outtextXY(1000,148+(40*k),"NU");
					else if(dstk[j].phai_tk==0) outtextXY(1000,148+(40*k),"KHAC");
//					outtextXY(1000,148+(40*j),to_string(dstk[j].phai_tk));
					outtextXY(1200,148+(40*k),to_string(dstk[j].soghe_tk));	
				}		
			}
			p=p->next;
		}
		
	}	
}
int is_number(string d)
{
	for(int i=0;i<d.length();i++)
		{
			if(d[i]<48||d[i]>57)
			{
				return 1;
			}	
		}
		return 0;
}
int check_maxslot(DS_CB x,DSMB y,string ma,string ghe )
{
	NODEPTR *p;
	if(x.first!=NULL)
	{
		p=x.first;
		for(int i=0; i<x.slcb;i++)
		{
			if(p->cb.macb==ma)
			{
				for(int j=0;j<y.sl;j++)
				{
					if(y.MB[j]->SoHieu==p->cb.sohieumaybay)
					{
						cout<<"so cho :"<<y.MB[j]->SoCho<<endl;
						if(stoi(ghe)>y.MB[j]->SoCho) return 0;
					}
				}
			}
			p=p->next;
		}
		return 1;		
	}
}
int check_clone(DS_CB &x, string ma,string socmnd)    
{
	NODEPTR *p;
	if(x.first!=NULL)
	{
		p=x.first;
		for(int i=0; i<x.slcb;i++)
		{
			if(p->cb.macb==ma)
			{
				for(int j=0;j<p->cb.slve;j++)
				{
//					cout<<"sl luong ve : "<<p->cb.slve<<endl;
//					cout<<p->cb.dsve.nodes[j].cmnd<<" ::"<<stoi(socmnd)<<endl;
					if(p->cb.dsve.nodes[j].cmnd==stoi(socmnd))
					{
						return 1;
					}
				}
			}
			p=p->next;
		}
		return 0;		
	}
}
void tim_cmnd(KHACHHANG root,int cmnd_i,int &kq)
	{
		if(root!=NULL)
		{
//			cout<<root->cmnd<<" : "<<cmnd_i<<" !ket qua: "<<kq<<endl;
			if(root->cmnd==cmnd_i)
			{
				kq=1;
			}
			tim_cmnd(root->left,cmnd_i,kq);
			tim_cmnd(root->right,cmnd_i,kq);
		}
	}
int check_cmnd(KHACHHANG x,int cmnd_i,string ho_i, string ten_i, int phai_i)
{
	int kq=0;
	tim_cmnd(x,cmnd_i,kq);
	return kq;	
}
void reload_status(DS_CB &x,DSMB y)
{
	NODEPTR *p;
	if(x.first!=NULL)
	{
		p=x.first;
		for(int i=0; i<x.slcb;i++)
		{
			if(p->cb.trangthai!=0  && p->cb.trangthai!=3)
			{
				if(p->cb.slve>=get_sochoMB(y,p->cb.sohieumaybay))
				{
					p->cb.trangthai=2;
				}else if (p->cb.slve<get_sochoMB(y,p->cb.sohieumaybay))	
				{
					p->cb.trangthai=1;
				}
			}
			
			p=p->next;
		}
		
	}
}
string cut_time(string d)
{
	if(d.length()==16)
	{
		d.erase(d.begin() + 15);
		d.erase(d.begin() + 14);
		d.erase(d.begin() + 13);
		d.erase(d.begin() + 12);
		d.erase(d.begin() + 11);
		d.erase(d.begin() + 10);
	}
	return d;
}
int check_empty_tiket(DS_CB x, string mcb)
{
	NODEPTR *p;
	if(x.first!=NULL)
	{
		p=x.first;
		for(int i=0; i<x.slcb;i++)
		{
			if(p->cb.slve==0&&p->cb.macb==mcb)
			{
				return 1;	
			 } 
			
			
			p=p->next;
		}
		return 0;
	}
}
int check_placedate_cb(DS_CB x, string noiden,string ngay)
{
	NODEPTR *p;
	if(x.first!=NULL)
	{
		p=x.first;
		for(int i=0; i<x.slcb;i++)
		{
			if(p->cb.sanbayden==noiden&&cut_time(p->cb.ngaygiokhoihanh)==ngay)
			{
				cout<<p->cb.macb<<endl;
				return 0;	
			 } 
			
			
			p=p->next;
		}
		return 1;
	}
}
struct print_find_cb{
	string mcb;
	string date;
	int ab_slot;
};
void clearDs_find() {
	for(int j=0; j<10; j++) {
		outtextXY(575,185+(40*j),"                          ");
		outtextXY(850,185+(40*j),"                          ");
		outtextXY(1125,185+(40*j),"                           ");
	}
	for(int i=0; i<10; i++) {
			hinhChuNhatRong(450,120+(40*i),700,120+(40*(i+1)),1);
			hinhChuNhatRong(700,120+(40*i),1000,120+(40*(i+1)),1);
			hinhChuNhatRong(1000,120+(40*i),1250,120+(40*(i+1)),1);
	}
}
int get_slcbfind(DS_CB &x, string date, string sbden)
{
	NODEPTR *p;	
	if(x.first!=NULL)
	{
		p=x.first;
		int count=0;
		for(int i=0; i<x.slcb;i++)
		{
			if(p->cb.sanbayden==sbden && cut_time(p->cb.ngaygiokhoihanh)==date && p->cb.trangthai!=3 && p->cb.trangthai!=3)
			{
				count++;
			}
			p=p->next;
		}	
		return count;	
	}else return 0;	
}
void xuatDs_find(DS_CB &x,DSMB y, string date, string sbden ,int soTrang){
	NODEPTR *p;	
	if(x.first!=NULL)
	{
		p=x.first;
		int count=0;
		print_find_cb findlist[get_slcbfind(x,date,sbden)];
		for(int i=0; i<x.slcb;i++)
		{
			if(p->cb.sanbayden==sbden && cut_time(p->cb.ngaygiokhoihanh)==date && p->cb.trangthai!=3 && p->cb.trangthai!=3)
			{
				findlist[count].mcb=p->cb.macb;
				findlist[count].date=p->cb.ngaygiokhoihanh;
				findlist[count].ab_slot=get_sochoMB(y,p->cb.sohieumaybay)-p->cb.slve;
				count++;
			}
			p=p->next;
		}	
		for(int i=10 * (soTrang - 1), j = 0; i< min(10 * soTrang, count); i++, j++) {
		outtextXY(575,185+(40*j),findlist[i].mcb);
		outtextXY(850,185+(40*j),findlist[i].date);
		outtextXY(1125,185+(40*j),to_string(findlist[i].ab_slot));
		}
		
	}	
}

