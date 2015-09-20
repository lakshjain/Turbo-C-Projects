#include <iostream.h>
#include <conio.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <graphics.h>
#include <dos.h>

// colfor movement tracking
#define INF 10

//snake constraints
#define RADIUS 5

int snakeSpeed = 10;

//initakizing graphics
void initgraphics()
	{
		int gd=DETECT,gm;
		initgraph(&gd,&gm,"C:\\TC\\BGI");
	}

struct snake
{
	int x,y;

}p[100];

struct food
{
	int x,y;
	food()
	{
		x=50,y=50;
	}

}f;


int collision(int length)
{
	for(int i=1;i<length;++i)
		{
			if(p[i].x==p[0].x&&p[i].y==p[0].y)
				return 1;
		}
	return 0;
}

int check(int e_x, int e_y)
{
	if(e_y!=INF&&e_x!=INF)
			return 1;
	else
			return 0;
}

int eaten()
{
	if(f.x==p[0].x&&f.y==p[0].y)
		return 1;

	return 0;
}

int collision_wall()
{
	if(p[0].x<=0||p[0].y<=0||p[0].x>=getmaxx()||p[0].y>=getmaxy())
		return 1;
	return 0;

}

void main()
{
	int score = 0;
	initgraphics();
	int e_x=INF,e_y=INF,length=1,tx,ty;
	char move;
	srand((unsigned)time(NULL));
	p[0].x=10;
	p[0].y=10;
	while(1)
	{
			while(!kbhit())
			   {

				gotoxy(70,1);
				cout<<"Score : "<<score;

				if(length>1)
				{
					tx=p[0].x;
					ty=p[0].y;

				}
				if(e_y==1||e_x==1)
					{
						if(e_y==1)

							p[0].y-=snakeSpeed;

						else

							p[0].x-=snakeSpeed;
					}
				else if(e_y==2||e_x==2)
					{
						if(e_y==2)
							p[0].y+=snakeSpeed;
						else
							p[0].x+=snakeSpeed;
					}

				if(eaten())
					{
					f.x=(((rand()%(getmaxx()-20))/10)*10)+10;
					f.y=(((rand()%(getmaxy()-20))/10)*10)+10;
					++length;
					score++;
					}

				delay(50);
				cleardevice();
				rectangle(0,0,getmaxx(),getmaxy());
				setcolor(11);
				circle(f.x,f.y,RADIUS/2);
				setbkcolor(1);
				setcolor(14);
				circle(p[0].x,p[0].y,RADIUS);
				for(int i=length-1,color=1;i>=1;i--)
				{
					if(i==1)
						{
						p[i].x=tx;
						p[i].y=ty;
						}
					else
						{
							p[i].x=p[i-1].x;
							p[i].y=p[i-1].y;
						}

					circle(p[i].x,p[i].y,RADIUS);

				}

				if((collision(length)&&length>=3)||collision_wall())
						break;




			   }

		move=getch();
		cin.sync();
		if(move==119&&e_y!=2)
		{
			e_y=1;
			if(check(e_x,e_y))
				e_x=INF;
		}


		else if(move==115&&e_y!=1)
				{
					e_y=2;
					if(check(e_x,e_y))
						e_x=INF;
				}
		else if(move==97&&e_x!=2)
				{
					e_x=1;
					if(check(e_x,e_y))
						e_y=INF;
				}
		else if(move==100&&e_x!=1)
				{
					e_x=2;
					if(check(e_x,e_y))
						e_y=INF;
				}
		//for debugging
		else if(move==27)
			break;
		else if(move == 43 && length < 99)//button +
			++length;
		else if(move == 108)//button l
			{
			cout<<"l = "<<length;
			getch();
			}
		else if(move == 99)//button c
			{
			cout<<"collision flag = "<<(collision(length)&&length>3);
			getch();
			}
		else if(move == 13)
			{
			//cout<<"Pf Ps = "<<f.x<<" "<<f.y<<" "<<p[0].x<<" "<<p[0].y;
			getch();
			}
		else if(move == 45 && length > 1)
			--length;

		if((collision(length)&&length>=3)||collision_wall())
			{
				break;
			}





	}

	cleardevice();
	gotoxy(10,10);
	cout<<" YOUR SCORE "<<score;
	getch();
	closegraph();
}

