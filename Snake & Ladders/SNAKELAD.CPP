#include <iostream.h>
#include <conio.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <graphics.h>
#include <dos.h>

void initgraphics()
	{
		int gd=DETECT,gm;
		initgraph(&gd,&gm,"C:\\TC\\BGI");
	}


struct player
{
	int pos_x, pos_y;
	player()
	{
		pos_x=-7;
	}
}p[2];
void ladders()
{

	for(int m=0,c=0;m<=250;m+=250,c++)
	for(int n=0;n<=m;n+=250)
	{
		if(!(m==250&&n==250))
		{

		setcolor(DARKGRAY);
		line(53+m,57+n,55+m,55+n);
		line(53+m,57+n,133+m,137+n);
		line(55+m,55+n,135+m,135+n);
		line(133+m,137+n,135+m,135+n);
		if(c)
			setfillstyle(SOLID_FILL, LIGHTMAGENTA);
		else
			setfillstyle(SOLID_FILL, LIGHTBLUE);
		floodfill(55+m,58+n,DARKGRAY);
		line(68+m,42+n,70+m,40+n);
		line(68+m,42+n,148+m,122+n);
		line(70+m,40+n,150+m,120+n);
		line(148+m,122+n,150+m,120+n);
		floodfill(70+m,43+n,DARKGRAY);
		line(65+m,65+n,78+m,52+n);
		line(68+m,68+n,81+m,55+n);
		floodfill(79+m,54+n,DARKGRAY);
		line(75+m,75+n,88+m,62+n);
		line(78+m,78+n,91+m,65+n);
		floodfill(89+m,64+n,DARKGRAY);
		line(85+m,85+n,98+m,72+n);
		line(88+m,88+n,101+m,75+n);
		floodfill(99+m,74+n,DARKGRAY);
		line(95+m,95+n,108+m,82+n);
		line(98+m,98+n,111+m,85+n);
		floodfill(109+m,84+n,DARKGRAY);
		line(105+m,105+n,118+m,92+n);
		line(108+m,108+n,121+m,95+n);
		floodfill(119+m,94+n,DARKGRAY);
		line(115+m,115+n,128+m,102+n);
		line(118+m,118+n,131+m,105+n);
		floodfill(129+m,104+n,DARKGRAY);
		line(125+m,125+n,138+m,112+n);
		line(128+m,128+n,141+m,115+n);
		floodfill(139+m,114+n,DARKGRAY);
		}
	}
	int p,q=0; //bottom ladder
	for(p=0,c=0;p<=180;p+=150,c++)
	{
		if(c)
			setfillstyle(SOLID_FILL, CYAN);
		else
			setfillstyle(SOLID_FILL, 14);
		line(100+p,330-q,140+p,290-q);
		line(100+p,330-q,102+p,332-q);
		line(102+p,332-q,142+p,292-q);
		line(142+p,292-q,140+p,290-q);
		floodfill(141+p,292-q,8);
		line(115+p,345-q,155+p,305-q);
		line(115+p,345-q,117+p,347-q);
		line(117+p,347-q,157+p,307-q);
		line(157+p,307-q,155+p,305-q);
		floodfill(155+p,307-q,8);
		line(112+p,322-q,125+p,335-q);
		line(114+p,320-q,127+p,333-q);
		floodfill(125+p,334-q,8);
		line(122+p,312-q,135+p,325-q);
		line(124+p,310-q,137+p,323-q);
		floodfill(135+p,324-q,8);
		line(132+p,302-q,145+p,315-q);
		line(134+p,300-q,147+p,313-q);
		floodfill(145+p,314-q,8);
		q+=85;
	}
}

void snakes()
{
	int x,y=0,h=5;
	for(x=0;x<=200;x+=125,y+=230,h-=3)
	{

		arc(120+x,110+y,10,85,60);
		arc(258+x,85+y,190,240,80);
		arc(112+x,118+y,10,80,60);
		arc(250+x,93+y,190,290,80);
		arc(275+x,100+y,250,270,70);
		line(250+x,170+y,250+x,165+y);
		line(250+x,165+y,230+x,160+y);
		line(230+x,160+y,218+x,155+y);
		line(130+x,50+y,115+x,47+y);
		line(121+x,59+y,106+x,52+y);
		line(106+x,52+y,114+x,48+y);
		circle(114+x,52+y,1);
		setfillstyle(1,h);
		floodfill(116+x,52+y,8);

		}

	arc(130,220,150,180,40);// 2 snake
	arc(130,220,180,253,40);
	arc(105,328,273,80,70);
	arc(143,220,150,180,40);
	arc(143,215,180,230,40);
	arc(112,328,265,50,75);
	arc(80,354,45,72,115);
	line(102,400,104,402);
	line(102,400,107,399);
	line(95,200,110,185);
	line(110,185,109,200);
	line(110,185,111,182);
	circle(104,198,1);
	setfillstyle(1,12);
	floodfill(103,199,8);

	arc(155,20,320,0,70);//snake curves
	arc(165,20,305,0,70);
	line(209,65,206,78);//line for joing curve
	line(225,20,229,5);//snakes head
	line(228,7,235,20);
	line(228,7,229,0);
	circle(229,19,1);
	setfillstyle(1,3);
	floodfill(229,21,DARKGRAY);
}


void loading()
	{
		int stangle = 45, endangle = 135;
		setbkcolor(RED);
		setcolor(YELLOW);
		for(int i=0;i<1000;++i)
		{

			delay(2);
			cleardevice();
			arc(300,150,stangle-i,endangle-i,30);
			arc(300,150,stangle+i,endangle+i,20);
			arc(300,150,stangle+10+i,endangle+10+i,40);
			arc(300,150,stangle+10-i,endangle+10-i,50);
			outtextxy(250, 220, "Loading Game..");

		}
		cleardevice();
		outtextxy(130, 200, "Loading Complete.. Press any key to continue");
	}
void board()
{

	setbkcolor(4);
	cleardevice();
	for(int col=0;col<400;col+=40)
		for(int i=0;i<400;i+=40)
			rectangle(0,0,40+col,40+i);

	ladders();
	snakes();
	setcolor(WHITE);
	outtextxy(480,80,"Player 1 : ");
	setfillstyle(1, YELLOW);
	fillellipse(565, 83, 3, 3);
	setcolor(WHITE);
	outtextxy(480,90,"Player 2 : ");
	setfillstyle(1, 1);
	fillellipse(565, 93, 3, 3);
	setcolor(WHITE);
	char z[3];
	i=1;
	int invert=0;
	for(int y=365;y>0;y-=40)
	{
		if(!invert)
		{
			for(int x=17;x<415;x+=40)
			{
				itoa(i++,z,10);
				outtextxy(x,y,z);
			}
			invert=1;
		}
		else
		{
			for(int x=376;x>15;x-=40)
			{
				itoa(i++,z,10);
				outtextxy(x,y,z);
			}
				invert=0;
		}
	}

	for(int c=0,h=0;c<2;++c,h=13)
	{
		setfillstyle(1, YELLOW-h);
		fillellipse(p[c].pos_x,p[c].pos_y,3,3);


	}
	setcolor(WHITE);

}
int iswin(player p)
{
	if(p.pos_x==33&&(p.pos_y==20||p.pos_y==30))
		return 1;
	else
		return 0;

}
int revert(int pos)
{

	if(pos==20||pos==100||pos==180||pos==260||pos==340||pos==30||pos==110||pos==190||pos==270||pos==350)
	       return 1;
	return 0;

}
void on_Ladders(int &posx, int &posy)
{
	if (posx==113&&(posy==340||posy==350)) //for ladder 18-24
	{
		posx = 153;
		posy -= 40;
	}
	else if (posx==273&&(posy==260||posy==270)) //for ladder 34 - 48
	{
		posx = 313;
		posy -= 40;
	}
	else if (posx==153&&(posy==140||posy==150))//ladder 64-82
	{
		posx = 73;
		posy -= 80;
	}
	else if (posx==393&&(posy==140||posy==150))//ladder 70-88
	{
		posx = 313;
		posy -= 80;
	}
}
void on_Snake(int& posx, int& posy)
{
	if (posx==233&&(posy==300||posy==310)) //for Snake 26-10
	{
		posx = 393;
		posy += 80;
	}
	else if (posx==113&&(posy==180||posy==190)) //for Snake 58-3
	{
		posy += 200;
	}
	else if (posx==113&&(posy==60||posy==70))//for Snake 83-54
	{
		posx = 273;
		posy += 120;
	}
	else if (posx==233&&(posy==20||posy==30))//for snake 95-86
	{
		posy+=40;
	}

}

int rolldice()
{
	int move;
	srand((unsigned)time(NULL));
	for(int i=0;i<60;++i)
	{
		move = rand() % 6 + 1;
		delay(i);
		gotoxy(66,14);

		cout<<move;
	}
	getch();
	return move;
}



void move_player(int player)
{

	gotoxy(53 , 12);
	cout<<"Press any key to Roll Dice";
	gotoxy(57,13);
	cout<<"    Player : "<<player+1;
	getch();
	cleardevice();
	board();
	setcolor(BLUE);
	setfillstyle(11, LIGHTBLUE);
	bar3d(500, 190, 545,237, 8, 1);
	int move = 0,move_temp = 0 ,stop=0;
	int magicCount = 0;
	int tempPosX = p[player].pos_x , tempPosY = p[player].pos_y;


	do
	{
		move = rolldice();
		move_temp = move;

	while(move)
			{
				if(tempPosY != 20 || tempPosY !=30)
				{
					if(tempPosX+pow(-1,revert(tempPosY))*40>0 && tempPosX+pow(-1,revert(tempPosY))*40<=393)
						{
							tempPosX += pow(-1,revert(tempPosY))*40;
							move--;
						}
					else
						{
							tempPosY -= 40;
							move--;
						}
				}
				else if(tempPosX+pow(-1,revert(tempPosY))*move*40>=33)
					{
						tempPosX += pow(-1,revert(tempPosY))*move*40;
						break;
					}
				else
					{
						break;
					}



			}
	if(tempPosY<20) break;
	}while (move_temp == 6);

	if(tempPosY >= 20)
		{
			p[player].pos_y = tempPosY;
			p[player].pos_x = tempPosX;
		}


	on_Snake(p[player].pos_x,p[player].pos_y);
	on_Ladders(p[player].pos_x,p[player].pos_y);
	gotoxy(55,10);
	//cout<<p[player].pos_x<<" "<<p[player].pos_y;
	setcolor(WHITE);

	}
void main()
{
	p[0].pos_y = 380;
	p[1].pos_y = 390;
	int i=0;
	clrscr();
	initgraphics();
	loading();
	getch();
	setbkcolor(NULL);
	setcolor(WHITE);
	cleardevice();
	while(1)
	{
		board();
		move_player(i);
		char c=getch();
		if((int)c==32 || iswin(p[i]))
			break;
		board();
		i=!i;
	}
	cleardevice();
	cout<<"Player : "<<i+1<<" won ";
	getch();
}
