#include <stdio.h>
#include<windows.h>
#include<conio.h>
#include<string.h>
#include<time.h>


int SV[1000];
int DoDai = 2;
int ThucAn;
int Diem;
clock_t t;
int s_e;
int vx;
int vy;
int TocDo=100;

enum TrangThai{TRONGGAME=0,TUYCHON,CAIDAT,TROCHOIKETTHUC,THONGTIN} TrangThai;

int Random(int a, int b)
{
   return a + rand()%(b-a+1);
}

void gotoxy(int x, int y)
{
    static HANDLE  h = NULL;
    if(!h)
        h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD c = {x,y};
    SetConsoleCursorPosition(h,c);
}

// Thêm màu s?c
void VeMau(WORD color)
{ 
    HANDLE Dau_Ra;
    Dau_Ra = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO Thong_Tin_Bo_Dem_Mang_Hinh;
    GetConsoleScreenBufferInfo(Dau_Ra, &Thong_Tin_Bo_Dem_Mang_Hinh);
    WORD Thuoc_Tinh = Thong_Tin_Bo_Dem_Mang_Hinh.wAttributes;
    color &= 0x000f;
    Thuoc_Tinh &= 0xfff0; Thuoc_Tinh |= color;
    SetConsoleTextAttribute(Dau_Ra, Thuoc_Tinh);
}

// thông tin nhóm
void ThongTin()
{
	system("cls");
	VeMau(4);
	gotoxy(10,8);
	printf("Cam on co va cac ban da xem du an game ran san moi nay !!!");
	gotoxy(3,10);
	VeMau(10);
	printf("\t--->An phim enter de tro lai menu");
	gotoxy(27,11);
	VeMau(14);
	printf("----Nhom 4 nguoi----");
	printf("\n\t\t\tLuan ---- Khanh----Cuong----Duc ");
	getchar();
	TrangThai = TUYCHON;
}

// Cài d?t game
void CaiDat()
{
  system("cls");
  gotoxy(0,9);
  VeMau(2);
  printf("An cac phim mui ten ben trai va phai tren ban phim de tang giam toc do, nhan enter de tro ve menu");
  gotoxy(30,11);
  VeMau(9);
  printf("Toc do hien tai : %d",TocDo);
  int key;
  while(TrangThai==CAIDAT)
  {
        if(kbhit())
        {
  		    key = getch();
  		    switch (key)
            {
  			    case 75 :
                    if(TocDo>1)
                    { 
                        TocDo -=1;
                        gotoxy(30,11);
                        printf("toc do hien tai : %d   ",TocDo);
                    }
  			        break;
                case  77 :
                    if(TocDo<100)
                    {
                        TocDo+=1;
                        gotoxy(30,11);
                        printf("toc do hien tai : %d   ",TocDo);
                    }
                    break;
                case 13 :
                    TrangThai = TUYCHON;
                    break;
            }
	    }
    }	
}

// Khung bên ngoài game
void VeKhung()
{
	 int i=0;
        for(i; i < 105; i++)
        {
                printf("=");
        }
        i=0;
        int j=0;
        for(j; j < 25 ; j++)
        {
            printf("\n");
            i=0;
            for(i; i < 105; i++)
            {
                printf((i==0 || i==102)?"||":" ");
            }
        }
        i=0;
        printf("\n");
        for(i ; i < 105; i++)
        {
            printf("=");
        }
}

// Trò choi k?t thúc
void TroChoiKetThuc()
{	
    VeMau(4);
    system("cls");
    gotoxy(30,9);
    VeMau(6);
    printf("....CHUC BAN MAY MAN LAN SAU....");
    gotoxy(15,11);
    VeMau(9);
    printf("Chuc mung ban duoc co %d diem, an enter ki de ve menu",Diem);
    getchar();
    TrangThai = TUYCHON;	
}

// Menu game
void TuyChon()
{
	VeMau(10);
	system("cls");
    gotoxy(25,3);
	printf("Game ran an moi ");
	gotoxy(30,5);
	VeMau(3);
	printf("1.Vao Game");
	gotoxy(30,6);
	printf("2.Tuy Chinh");
	gotoxy(30,7);
	printf("3.Thong Tin");
	int choice = 1;
	int oldChoice = 1;
	int next = 1;
	int key;
	VeMau(14);//Ve mau mui ten luc dau trong tuy chon
	gotoxy(29,5);
	printf("%c",16);
	while(TrangThai==TUYCHON)
    {
		if(kbhit())
        {
			key = getch();
			if(key==80)
            {
			    choice++;
			    if(choice ==4) choice = 1;
			}
			if(key==72)
            {
			    choice --;
			    if(choice == 0) choice = 3;
			}
		    switch (choice)
            {
			    case 1 :
				    if(oldChoice!=choice)
                    {
				        gotoxy(29,6);
				        printf(" ");
				        gotoxy(29,7);
				        printf(" ");
				        oldChoice = 1;
				        gotoxy(29,5);
				        VeMau(13);
				        printf("%c",16);
                    }
				    break;
			    case 2 :
				    if(oldChoice!=choice)
                    {
				        gotoxy(29,5);
				        printf(" ");
				        gotoxy(29,7);
				        printf(" ");
		                gotoxy(29,6);
		                VeMau(12);
				        printf("%c",16);
				        oldChoice = 2;
                    }
				    break;
			    case 3 :
				    if(oldChoice!=choice)
                    {
				        gotoxy(29,6);
				        printf(" ");
				        gotoxy(29,5);
				        printf(" ");
				        gotoxy(29,7);
				        VeMau(11);
				        printf("%c",16);	
				        oldChoice = 3;
                    }
				    break;
            }
		    if(key==13)
            {
		        switch (choice)
                {
		            case 1:			
			            TrangThai = TRONGGAME;
			            break;
		            case 2:
			            TrangThai = CAIDAT;
			            break;
		            case 3 :
		                TrangThai = THONGTIN;
			            break;
                }
		    }
	    }
	}	
}

// Tang d? dài con r?n
void ADD()
{
	system("cls");
	s_e = 200-TocDo;
	t = 0;
	vx = 1;
	vy = 0;
	Diem = 0;
	DoDai = 10;
	SV[0] = 11510;
	SV[1] = 11410;
	SV[2] = 11310;
	SV[3] = 11210;
	SV[4] = 11110;
	SV[5] = 11010;
	SV[6] = 10910;
	SV[7] = 10810;
	SV[8] = 10710;
	SV[9] = 10610;
	ThucAn = 15010;
}

// T?o m?i cho r?n an
void TaoThucAn()
{
	int notok = 1;
	while(notok)
    {
		notok = 0;
		ThucAn = 10000 + Random(1,77)*100 + Random(1,23);
		int i = 0;
		for(i;i<DoDai;i++)
        {
		    if(SV[i]==ThucAn)
            {
			    notok=1;
            }
		}
	}
}

// Ði d?n to?n d? x
int getx(int a)
{
	return (a-10000)/100;
}

// Ði d?n t?a d? y
int gety(int a)
{
	return a%100;
}

// B?ng di?m 
void VeDiem()
{
	VeMau(3);
	gotoxy(105,3);
 	printf("s");
 	gotoxy(105,4);
 	printf("c");
 	gotoxy(105,5);
 	printf("o");
 	gotoxy(105,6);
 	printf("r");
 	gotoxy(105,7);
 	printf("e");
 	gotoxy(105,9); 
 	VeMau(6);
 	printf("0");
 	gotoxy(105,10); 
 	printf("0");
 	gotoxy(105,11);
 	printf("0");
 	gotoxy(105,12); 
 	printf("0");
 	gotoxy(105,13);
 	printf("0");
}

// Tang thêm di?m trong khi dang choi game
void ThemDiem()
{
	VeMau(2);//Khi diem thay doi thi doi mau
	gotoxy(105,9); 
	printf("%d",(Diem%100000)/10000);
 	gotoxy(105,10);
 	printf("%d",(Diem%10000)/1000);
 	gotoxy(105,11);
 	printf("%d",(Diem%1000)/100);
 	gotoxy(105,12);
 	printf("%d",(Diem%100)/10);
 	gotoxy(105,13);
 	printf("%d",Diem%10);
}

// Con r?n
void TrongGame()
{
	int key;
	int i;
	ADD();
	VeMau(11);//Mau Khung
 	VeKhung();
 	VeDiem();
 	TrangThai = TRONGGAME;
 	VeMau(2);//Ve mau thuc an ban dau
 	gotoxy(getx(ThucAn),gety(ThucAn));
 	printf("0");
 	VeMau(8);
 	gotoxy(getx(SV[0]),gety(SV[0]));
	printf("#");
	i = 1;
	VeMau(6);//Ve mau duoi 
 	for(i;i<DoDai;i++)
    {
		gotoxy(getx(SV[i]),gety(SV[i]));
		printf("o");
    }
	while(TrangThai == TRONGGAME)
    {
	    if(kbhit())
        {
			key = getch();
			switch (key)
            {	
				case 72:
					if(vy == 0)
                    {
					    vx = 0;
					    vy = -1;
                    }
					break;
				case 80:
					if(vy == 0)
                    {
					    vx = 0;
					    vy = 1;
                    }
					break;
				case 75:
					if(vx == 0)
                    {
					    vy = 0;
					    vx = -1;
                    }
					break;
				case 77:
					if(vx == 0)
                    {
					    vy = 0;
					    vx = 1;
                    }
					break;
            }						     
}	
	if((clock()-t)>=s_e)
    {
		    if(SV[DoDai-1]!=0)
            {			
		        gotoxy(getx(SV[DoDai-1]),gety(SV[DoDai-1]));
			    printf(" ");
            }
			i=DoDai-1;
			for(i;i>0;i--)
            {
			    SV[i]=SV[i-1];
            }
			VeMau(6);//Ve mau duoi
			gotoxy(getx(SV[0]),gety(SV[0]));
			printf("o");
		        SV[0] += vx*100;
		        SV[0] += vy;	
		    if(SV[0] == ThucAn)
            {
		    	DoDai+= 1;
		    	Diem += (TocDo/10 + 5);
		    	ThemDiem();
		    	TaoThucAn();
		    	VeMau(6);//Ve mau thuc an
		    	gotoxy(getx(ThucAn),gety(ThucAn));
 	                printf("O");
            }
            // Ch?m ranh gi?i c?a trò choi s? ch?t
			if((vx>0)&&(getx(SV[0])==103))
            {
			    system("cls");
			    TrangThai=TROCHOIKETTHUC;
			}   
			if((vx<0)&&(getx(SV[0])==1))
            {
				system("cls");
				TrangThai=TROCHOIKETTHUC;
			}
			if((vy>0)&&(gety(SV[0])==26))
            {
				system("cls");
				TrangThai=TROCHOIKETTHUC;
			}   
			if((vy<0)&&(gety(SV[0])==0))
            {
				system("cls");
				TrangThai=TROCHOIKETTHUC;
			}
			VeMau(11);//Ve mau dau ran
			gotoxy(getx(SV[0]),gety(SV[0]));
				printf("#");
			i = 1;
			for(i;i<DoDai;i++)
            {
				if(SV[i]==SV[0])
                {
					system("cls");					
					TrangThai = TROCHOIKETTHUC;
				}
			}
		        t = clock();  		    
		}	
	}	
}

int main()
{
    TrangThai = TUYCHON;
    TuyChon();
    while(1)
    {
	    switch (TrangThai)
        {
		    case TUYCHON : 
		        TuyChon();
		        break;
		    case TRONGGAME :
		        TrongGame();
	            break;
		    case TROCHOIKETTHUC : 
		        TroChoiKetThuc();
		        break;
		    case THONGTIN :
		        ThongTin();
		        break;
		    case CAIDAT:
		        CaiDat();
		        break;
        } 
    }
}
