#include <iostream>
#include <conio.h>
#include <ctime>
#include "windows.h"
#include <fstream>
#include <ctime>
using namespace std;


int secim=0; //secime göre ok yazýlcak
int yuksekskor=0;
int renk=2;
int zorluluk=10;
int ses=1;
int kac=0;
//<<<<<<<<<<<<<<<<<< gotoxy için koordinat api tanýmlamasý >>>>>>>>>>>>>>>>>>>>>>>>>

void gotoxy(short x,short y)
{
COORD pos={x,y};
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}
int y=6;
int imlec()
{
	switch(secim)
	{
		case 0:{gotoxy(25,y);break;}
		case 1:{gotoxy(25,y+2);break;}
		case 2:{gotoxy(25,y+4);break;}
		case 3:{gotoxy(25,y+6);break;}
		case 4:{gotoxy(25,y+8);break;}
			
	
	}		
	cout<<"--->";


}

 int tema() 
 {
 	
	setlocale(LC_ALL,"Turkish");
	system("CLS");
	switch(renk)
	{	
		case 0:{system("color 4"); break;}
		case 1:{system("color 1"); break;}
		case 2:{system("color 2"); break;}
		case 3:{system("color 7"); break;}	
	}
	gotoxy(15,2);
	for(int i=0;i<49;i++)cout<<"_";
gotoxy(30,3);
std::cout<<"Maminin  Puzzle"<<std::endl;
gotoxy(15,4);
cout.width(50);
cout.fill('=');
cout<<" ";
for (int y=3;y<20;y++)
{
gotoxy(15,y);
cout<<"|";
gotoxy(64,y);
cout<<"|";
}
for(int x=15;x<65;x++)
{
gotoxy(x,20);
cout<<"+";
}
for(int x=16;x<64;x++)
{
gotoxy(x,18);
cout<<"=";
}

}


int anamenu()
{
	system("cls");
	tema();
	int y=6;
	gotoxy(34,y);
cout<<"Yeni Oyun";
	gotoxy(34,y+2);
cout<<"Yüksek Puan";
	gotoxy(34,y+4);
cout<<"Ayarlar";
gotoxy(34,y+6);
cout<<"Hakkýnda";
gotoxy(34,y+8);
cout<<"Çýkýþ";

imlec();
}
int oyun()
{
	system("cls");
	tema();
	clock_t zaman;
	zaman=clock();
	
	int bitir=1;
	int hamle=0;
	int a=3; //deðiþgen kaça kaçlýk olduðu
	int p[a][a]{{3,7,8},{4,6,5},{1,0,2}};
	int b=1;
	int cozum=0;
	int sure=0;
	int coz=0;
	int c[100]{77,72,75,75,80,77,80,75,72,77,77,80,75,72,72,75,80,77,72,77,80,75,72};
	int n=23;
	int  i1,j1, randomcu=0, secim;
	srand (time(NULL));
if(ses==1)PlaySound("tema.wav", NULL, SND_FILENAME|SND_ASYNC);	
	
/*	for(int i=0;i<a;i++)//1-9 a kadar doldurma
		{
			for(int j=0;j<a;j++){ if(b==9)b=0;
			p[i][j]=b; b++;}
		}
	
	*/
	
	
	while(1)
	{
	//cozum kontroluu
	if(p[0][0]==1)
		if(p[0][1]==2)
			if(p[0][2]==3)
				if(p[1][0]==8)
					if(p[1][1]==0)
						if(p[1][2]==4)
							if(p[2][0]==7)
								if(p[2][1]==6)bitir=0;
	
		gotoxy(28,7);
		for(int i=0,y=7;i<3;i++)//ekrana yazdýrma
		{
			y+=3;
			for(int j=0;j<3;j++) printf("%5d",p[i][j]); gotoxy(28,y);
					
		}
 		
	{	 //alt konsol
	gotoxy(52,19);
	printf("Hamle:%d",hamle);
	sure=(clock()-zaman)/ CLOCKS_PER_SEC;
	gotoxy(20,19);
	printf("Süre: %d:%d",sure/60,sure%60);
		}
	
		for(int i=0;i<3;i++)//0 bulma
		{
			for(int j=0;j<3;j++)
			{
				if(p[i][j]==0) {i1=i; j1=j; }
				
			} 
			
		}
		
		{
			gotoxy(70,5);
		cout<<"Nasýl oynanýr";
		gotoxy(70,7);
		cout<<"Ok tuþlarý ile 0 sayýsýný ";
		gotoxy(70,8);
		cout<<"hareket ettirerek ";
		gotoxy(70,9);
		cout<<"1	2 3 ";
		gotoxy(70,10);
		cout<<"8 0 4";
		gotoxy(70,11);
		cout<<"7 6 5 ";
		gotoxy(70,12);
		cout<<"þekline getin ";
		
		gotoxy(70,15);
		cout<<"Bilgisayardan Yardým almak Ýçin F1 e basýn.";
		
		
						
		}
		if(bitir==0){Sleep(1000);break;
		}
		else if(coz==1){n--;secim=c[n];}
		
				else if(randomcu<zorluluk) 
		{
			
	
			randomcu++; 
			switch(rand()%4)
			{
				case 0: {secim=72;
					break;}
				case 1: {secim=75;
					break;}
				case 2: {secim=80;
					break;}
				case 3: {secim=77;
					break;}
				}
				hamle=0;
			}
			
		
					else if (kbhit()) secim=getch(); //klavye giriþi olursa giriþi secime baðlasýn
							else {Sleep(200); continue;} //biraz gecikme --surekli yazýnca ekranda parazit olusuyor
		
		
		switch(secim)
		{
			case 72  : {if(i1-1<0)continue;
				p[i1][j1]=p[i1-1][j1];
				p[i1-1][j1]=0;
				
				break;
			}
				
			case 75: {if(j1-1<0)continue;
				p[i1][j1]=p[i1][j1-1];
				p[i1][j1-1]=0;
				
				break;
			}
			case 80: {if(i1+1==a)continue;
				p[i1][j1]=p[i1+1][j1];
				p[i1+1][j1]=0;
				
				break;
			}
			case 77: {if(j1+1==a)continue;
				p[i1][j1]=p[i1][j1+1];
				p[i1][j1+1]=0;break;}
				
			case 59:{coz=1; continue;}
				
			case 27:{kac=1;	
				break;
			}
				
			
			default:continue;
			
			
			
		}//switch sonu
	
								
								
	
	if(secim==72)secim=80;
	else if(secim==80)secim=72;
		else if(secim==77)secim=75;
		 else if(secim==75)secim=77;
	if(coz==0){c[n]=secim;
	}
	
	hamle++;
	if(coz==0)n++;
									
	
	if(coz==1)getch();
	if(bitir==0) break;
	
	if(kac==1)break;
	}//while sonu

	if(bitir==0) 
	{
		/* system("cls");
		tema();
		gotoxy(28,7);
		for(int i=0,y=7;i<3;i++)//ekrana yazdýrma
		{
			y+=3;
			for(int j=0;j<3;j++) printf("%5d",p[i][j]); gotoxy(28,y);
		}
		for(int i=0;i<3;i++)//Flash Skor
		{
		Sleep(1000);
		system("cls");
		tema();
		Sleep(500);
		
		gotoxy(28,7);
		for(int i=0,y=7;i<3;i++)//ekrana yazdýrma
		{
			y+=3;
			for(int j=0;j<3;j++) printf("%5d",p[i][j]); gotoxy(28,y);
		}
		}*/
	system("cls");
	tema();
	int skor=1000000-(hamle*160)-(sure*20);
	if(yuksekskor<skor)yuksekskor=skor;
	ofstream dosya;
	dosya.open ("skor.txt");
	dosya << yuksekskor << endl;
	dosya.close();
	gotoxy(34,8);
	printf("Skor:%d",skor);
	gotoxy(30,10);
	if(n==0)printf("Ýþlem baþarýyla tamamlandý.");
	gotoxy(30,11);
	if(coz==1)printf("Bilgisayara Tebrikler!!");
	else printf("Size Tebrikler!!");
if(ses==1)	PlaySound("tebrikler.wav", NULL, SND_FILENAME|SND_ASYNC); 
	gotoxy(25,13);
	printf("Süre:%d:%d",sure/60,sure%60);
	gotoxy(45,13);
	printf("Hamle:%d",hamle-1);
	Sleep(3000);
	kac=1;
	
	}


}
int skor()
{
	system("cls");
	tema();
	fstream dosya;
	dosya.open("skor.txt");
	dosya>>yuksekskor;
	gotoxy(28,9);
	cout<<"Yüksek Skor: "<<yuksekskor;
	getch();
}
int ayar(){
	while(1){
	tema();
	
	imlec();
	gotoxy(31,6);
	cout<<"[1]Kýrmýzý";
	gotoxy(31,8);
	cout<<"[2]Mavi";
	gotoxy(31,10);
	cout<<"[3]Yeþil";
	gotoxy(31,12);
	cout<<"[4]Beyaz";
	gotoxy(31,14);
	cout<<"Bir Renk Seçiniz ";
switch(getch())
{
	case 80:{if(secim==3)secim=-1;secim++;if(ses==1)PlaySound("menu.wav", NULL, SND_FILENAME|SND_ASYNC); break;}
	case 72:{if(secim==0)secim=4;secim--;if(ses==1)PlaySound("menu.wav", NULL, SND_FILENAME|SND_ASYNC); break;}
	case 13:{switch(secim)
	{
		case 0:{renk=0;
			break;
		}
		case 1:{renk=1;
			break;
		}
		case 2:{renk=2;
			break;
		}
		case 3:{renk=3;
			break;
		}
		
	}
		break;
	}
	/*case 27:{kac=1;
		break;
	}*/
}
return 0;
//if(kac==1)break;
}//while sonu

}
int info()
{
tema();
gotoxy(17,5);
cout<<"Maminin Puzzle V1.0";
gotoxy(17,12);
cout<<"Bülent Ecevit Üniversitesi";
gotoxy(17,14);
cout<<"'177106109001' Numaralý Öðrencisi";
gotoxy(17,16);
cout<<"Muhammed Sertkaya tarafýndan kodlanmýþtýr.";
gotoxy(17,19);
cout<<"Eðitmen: M. Ozan Ýncetaþ";
getch();
}
int zorluk()
{
while(1){
tema();
gotoxy(30,6);
cout<<"Zorluk Seçiniz";
gotoxy(28,8);
cout<<"[1]Kolay";
gotoxy(28,10);
cout<<"[2]Orta";
gotoxy(28,12);
cout<<"[3]Zor";

int y=8;

switch(secim)
	{
		case 0:{gotoxy(23,y);break;}
		case 1:{gotoxy(23,y+2);break;}
		case 2:{gotoxy(23,y+4);break;}
	
		
			
	
	}		
	cout<<"--->";

switch(getch())
{
	case 80:{if(secim==2)secim=-1;secim++;if(ses==1)PlaySound("menu.wav", NULL, SND_FILENAME|SND_ASYNC); break;}
	case 72:{if(secim==0)secim=3;secim--;if(ses==1)PlaySound("menu.wav", NULL, SND_FILENAME|SND_ASYNC); break;}
	case 13:{
				if(ses==1)PlaySound("enter.wav", NULL, SND_FILENAME|SND_ASYNC); 
				Sleep(200);
	if(secim==0){zorluluk=10;oyun();
		break;
	}
	if(secim==1){zorluluk=50;oyun();
		break;
	}
	if(secim==2)zorluluk=100; oyun();
		break;
	}
	case 27:kac=1;
	default:break;
}
if(kac==1)break;
};

}
int main()
{
	
do{
kac=0;
tema ();
anamenu();
gotoxy(18,19);
cout<<"Yön=Ok tuslarý";
gotoxy(50,19);
if(ses==0)cout<<"M=Ses Aç "; else cout<<"M=Ses Kapat ";
switch(getch())
{
	case 'm':{if(ses==1)ses=0; else ses=1;
		break;
	}
	case 'M':{if(ses==1)ses=0;else ses=1;
		break;
	}

	case 80:{if(secim==4)secim=-1;secim++;if(ses==1)PlaySound("menu.wav", NULL, SND_FILENAME|SND_ASYNC|SND_NOSTOP); break;}
	case 72:{if(secim==0)secim=5;secim--;if(ses==1)PlaySound("menu.wav", NULL, SND_FILENAME|SND_ASYNC); break;}
	case 27:{if(ses==1)PlaySound("kapanis.wav", NULL, SND_FILENAME|SND_ASYNC); Sleep(1000);exit(1);break;}
	case 13:{
			if(ses==1)	PlaySound("enter.wav", NULL, SND_FILENAME|SND_ASYNC); 
				
				switch(secim)
				{
			
				case 0:{zorluk();break;}
				case 1:{skor();break;}
				case 2:{ayar();break;}
				case 3:{info();	break;}
				case 4:{if(ses==1)PlaySound("kapanis.wav", NULL, SND_FILENAME|SND_ASYNC); Sleep(1000);exit(1);break;}
				
				}
	
				break;
			}

}
}while(1);
}
	
	
	

