#include <iostream.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <dos.h>
#include <stdio.h>
#include <graphics.h>

int alpha(char movie[])
{
	int count=0;
	for(int i=0;i<strlen(movie);++i)
	{

	  if(movie[i]!='a'&&movie[i]!='e'&&movie[i]!='i'&&movie[i]!='o'&&movie[i]!='u'&&movie[i]!=' ')
	  ++count;
	}

	return count;
}

void main()
{
	  int gd=DETECT,gmode;
	  initgraph(&gd,&gmode,"C:\\TC\\BGI");

	  for(int i=35,j=1;i<600;++i)
	 	{
		  textcolor(3);
		  rectangle(21,196,603,213);
		  gotoxy(5,12);
		  cout<<"Loading..";
		  setfillstyle(2,CYAN);
		  bar(25,200,i,210);

		  delay(j++);
		  if(j==10)j=0;
		  //if(i!=599)
		 // cleardevice();
	  	}

	  gotoxy(25,15);

	  cout<<"Press Any Key To Start Game";

	  getch();

	  closegraph();


	 clrscr();
	 FILE *in;
	 char movie[15][30];
	 if ((in = fopen("movies.txt", "rt"))==NULL)
	 {
	 	cout<<"Cannot open input file.\n";
		getch();
	   	return;
	 }
	 int blog=0,mcount=-1,counter=0;
	 char c;
	 in = fopen("movies.txt", "rt");
	 for(int p=0;!feof(in);++p)
	 {
		c=fgetc(in);

		if(blog==0&&c=='[')
		{
			blog=1;
			++mcount;
			counter=0;
			continue;
		}
		if(blog==1&&c==']')
		{
			blog=0;
			movie[mcount][counter]='\0';
			//cout<<temp[mcount]<<"\n";
			continue;

		}
		if(mcount>=0&&(isalnum(c)||c==' '))
		{
		movie[mcount][counter++]=c;
	       //	cout<<movie[mcount][counter-1]<<" : "<<(int)movie[mcount][counter-1]<<"\n";
		}
	}
	    if(mcount>=0)
	   		 movie[mcount][counter]='\0';


	 /*char movie[13][30]={"raju chacha",
			     "3 idiots",
			     "kal ho na ho",
			     "dil waale dulhania le jayenge",
			     "hemlata",
			     "kaho na pyaar hai",
			     "pardes",
			     "manorama six feet under",
			     "victoria no 203",
			     "paheli",
			     "wajjah",
			     "bach ke rehna re baba",
			     "mr ya miss"};*/

	 char  bollywood[10]={"BOLLYWOOD"};
	 int count;


	 textcolor(RED);


	 for(i=0;i<=mcount;++i)
	 {
	  char done_alpha[30]={0};
	  int tries=23,check_pointer=0;
	  int count=alpha(movie[i]);
	  clrscr();

	  for(int j=0;j<10;++j)
			{

				gotoxy(j+23,5);
				cout<<bollywood[j];
			}
		for(j=0;j<strlen(movie[i]);++j)
			{
				if(movie[i][j]!='a'&&movie[i][j]!='e'&&movie[i][j]!='i'&&movie[i][j]!='o'&&movie[i][j]!='u'&&movie[i][j]!=' ')
				 {
					gotoxy((j*2)+20,6);
					cout<<"_";
				      // cout<<movie[i][j];

				 }
				 else
				 {
					if(movie[i][j]==' ')
					{
					gotoxy((j*2)+20,6);
					cout<<"/";
					}
					else
					{
					gotoxy((j*2)+20,6);
					cout<<movie[i][j];
					}

				 }
			}
			while(tries<32&&count>0)
				{
					cout<<done_alpha;
					 gotoxy(3,8);
					 cout<<"Enter Your Alphabet ";
					 char c=getche();
					 c=tolower(c);
					 int flag=0,done=0;
					 if(c!='a'&&c!='e'&&c!='i'&&c!='o'&&c!='u'&&c!=' '&&(isalpha(c)||isdigit(c)))
						{
						  for(int l=0;l<=check_pointer;++l)
									{
									if(c==done_alpha[l])
										{
										++done;
										}
									}
						  for(int k=0;k<strlen(movie[i])&&done==0;++k)
							{

								if(movie[i][k]==c)
									{
										gotoxy((k*2)+20,6);
										cout<<movie[i][k];
										--count;
										++flag;
										done_alpha[++check_pointer]=c;
									}

							}

							if(!flag&&done==0)
							{
								gotoxy(tries,5);
								cout<<"_";
								++tries;
								done_alpha[++check_pointer]=c;
							}
						  }


				}

			if(count==0)
			{
				gotoxy(3,9);
				system("pause");
				clrscr();
				if(mcount-i)
				{
					cout<<mcount-i<<" movies left";
					getch();
				}
			}
			else
			{
				clrscr();
				cout<<"You lost";
				getch();
				return;
			}

		}

	clrscr();
	cout<<"You Win Bollywood Game ";
	getch();
}