#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<alloc.h>
#include<process.h>
#include<time.h>
#include<graphics.h>
#include<dos.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
struct details{
	       int eno;
	       char fname[15];
	       char lname[15];
	       int rk;
	      }d;
struct applied{
	       int en1,rk1;
	       struct applied *n1,*b1;
	      }*ap,*temp1,*first1=NULL;
struct colleges{
		char col[40];
		char br[20];
		struct colleges *n2,*b2;
	       }*co,*temp2,*first2=NULL,*sec,*high,*last1,*first3=NULL,*temp3,*sec1,*co1,*last2,*sec2;
struct queue{
	     int front1,rear1;
	     int en2[200],rk2[200];
	    }qu;
struct seat{
	    char cn[40],bn[20];
	    int ase;
	    struct seat *n3;
	   }*temp4,*se,*first4=NULL;
struct councelling
	{
	 char name[20],surname[20],branch[5];
	 int rank,enroll,dd;
	 char status;
	}c;
char t[200][20]={'\0'};
void bk_gr()
	{
	 long int i;
	 setbkcolor(0);
	 setcolor(7);
	}

int menu();
void rank();
void info();
void tree();
void tree_rec(int i,int d,int flag,int a);
void seats_vacant();
void open_rank();
void close_rank();
void branch();
void colbranch();
void process();
void hostel();
void queries();
void front();
char* list()
	{
	 int a;
	 bk_gr();
	 settextstyle(SANS_SERIF_FONT,HORIZ_DIR,1);
	 setcolor(CYAN);
	 outtextxy(240,120,"1-JAYPEE");
	 outtextxy(240,140,"2-IIIT ALLAHABAD");
	 outtextxy(240,160,"3-IIIT HYDERABAD");
	 outtextxy(240,180,"4-NIT ALLAHABAD");
	 outtextxy(240,200,"5-NIT JAMSHEDPUR");
	 outtextxy(240,220,"6-NIT KURUKSHETRA");
	 outtextxy(240,240,"7-NIT NAGPUR");
	 outtextxy(240,260,"8-NIT ROURKELA");
	 outtextxy(240,280,"9-NIT SURAT");
	 outtextxy(240,300,"10-NIT SURATHKAL");
	 outtextxy(240,320,"11-NIT WARANGAL");
	 outtextxy(240,340,"12-THAPPAR PUNJAB");
	 outtextxy(170,377,"Enter your choice");
	 gotoxy(45,25);
	 scanf("%d",&a);
	 switch(a)
		{
		 case 1:return "JIIT(NOI";
		 case 2:return "IIIT(ALL";
		 case 3:return "IIIT(HYD";
		 case 4:return "NIT(ALLA";
		 case 5:return "NIT(JAMS";
		 case 6:return "NIT(KURU";
		 case 7:return "NIT(NAGP";
		 case 8:return "NIT(ROUR";
		 case 9:return "NIT(SURA";
		 case 10:return "NIT(SURK";
		 case 11:return "NIT(WARA";
		 case 12:return "THAPPAR";
		}
	 return 0;
	}
void push(int en3,int rk3)
	{
	 if(qu.rear1==199)
		{
		 printf("Stack is full");
		}
	 else
		{
		 qu.rear1++;
		 qu.en2[qu.rear1]=en3;
		 qu.rk2[qu.rear1]=rk3;
		}
	}
void pop()
	{
	 if(qu.rear1==-1)
		{
		 printf("Stack empty");
		}
	 else
		{
		 qu.front1++;
		}
	}
void ingraph()
	{
	 int gdriver = DETECT, gmode,errorcode;
	 initgraph(&gdriver, &gmode, "C:\\TC\\Bgi");
	}
void bk_gr1(int col)
	{
	 long int i;
	 setbkcolor(15);
	 setcolor(col);
	 for(i=0;i<4000;i++)
		{
		 circle(getmaxx()/2,getmaxy()/2,random(400));
		}
	}
void schedule()
	{
	 FILE *fp1;
	 char sar[70];
	 int i;
	 cleardevice();
	 bk_gr1(5);
	 settextstyle(SANS_SERIF_FONT,HORIZ_DIR,2);
	 setcolor(BLUE);
	 strcpy(sar,"\0");
	 fp1=fopen("schedule.txt","r");
	 i=0;
	 while(fscanf(fp1,"%s",sar)!=EOF)
		{
		 outtextxy(70,150+(50*i),sar);
		 i++;
		}
	 getch();
	}
void process()
	{
	 FILE *fp;
	 char ch[20];
	 bk_gr1(7);
	 settextstyle(SANS_SERIF_FONT,HORIZ_DIR,2);
	 setcolor(5);
	 outtextxy(180,20,"## AIEEE Counselling ##");
	 settextstyle(1,0,1);
	 outtextxy(40,50,"# The counselling procedure includes filling of form -1 online:-");
	 outtextxy(40,70,"  In accorind to the choices submitted by the student seat will");
	 outtextxy(40,90,"  be alloted to the student.");
	 outtextxy(40,110," The branch will be allotetd later by the institution");
	 outtextxy(40,130," where admittedwith due consideration of the merit among");
	 outtextxy(40,150," the students joining it.");
	 getch();
	 fcloseall();
	}
void screen1()
	{
	 setbkcolor(0);
	 setfillstyle(SOLID_FILL,7);
	 bar(0,0,getmaxx(),24);
	 bar(0,442,getmaxx(),466);
	 setcolor(8);
	 settextstyle(7,0,2);
	 outtextxy(180,0,"SUBMIT PREFERENCES");
	 outtextxy(150,442,"PRESS  ESC  TO  SAVE & EXIT");
	 setfillstyle(SOLID_FILL,15);
	 bar(0,38,getmaxx(),430);
	 setfillstyle(SOLID_FILL,7);
	 bar((getmaxx()/2)-5,38,(getmaxx()/2)+5,430);
	 bar(0,38,getmaxx(),42);
	 bar(getmaxx()-4,42,getmaxx(),430);
	 bar(0,426,getmaxx(),430);
	 bar(0,38,4,430);
	}
int compare_time(int seconds,int minutes,int hours,int date,int month,int day)
	{
	 int el;
	 FILE *fp;
	 time_t t1;
	 struct tm t;
	 char dy[4],mon[4],c,h;
	 int dt,hr,secs,min,year,m_no;
	 fp=fopen("Time.txt","w");
	 time(&t1);
	 fprintf(fp,"%s",ctime(&t1));
	 fclose(fp);
	 fp=fopen("Time.txt","r");
	 t.tm_sec    = seconds;
	 t.tm_min    = minutes;
	 t.tm_hour   = hours;
	 t.tm_mday   = date;
	 t.tm_mon    = month;
	 t.tm_year   = 109;
	 t.tm_wday   = day;
	 fscanf(fp,"%s %s %d %d %c %d %c %d %d",dy,mon,&dt,&hr,&c,&min,&h,&secs,&year);
	 if(strcmp(mon,"Jan")==0)
		{
		 m_no=0;
		}
	 else if(strcmp(mon,"Feb")==0)
		{
		 m_no=1;
		}
	 else if(strcmp(mon,"Mar")==0)
		{
		 m_no=2;
		}
	 else if(strcmp(mon,"Apr")==0)
		{
		 m_no=3;
		}
	 else if(strcmp(mon,"May")==0)
		{
		 m_no=4;
		}
	 else if(strcmp(mon,"Jun")==0)
		{
		 m_no=5;
		}
	 else if(strcmp(mon,"Jul")==0)
		{
		 m_no=6;
		}
	 else if(strcmp(mon,"Aug")==0)
		{
		 m_no=7;
		}
	 else if(strcmp(mon,"Sep")==0)
		{
		 m_no=8;
		}
	 else if(strcmp(mon,"Oct")==0)
		{
		 m_no=9;
		}
	 else if(strcmp(mon,"Nov")==0)
		{
		 m_no=10;
		}
	 else
		{
		 m_no=11;
		}
	 if(m_no<t.tm_mon)
		{
		 el=1;
		}
	 else if(m_no==t.tm_mon)
		{
		 if(dt<t.tm_mday)
			{
			 el=1;
			}
		 else if(dt==t.tm_mday)
			{
			 if(hr<t.tm_hour)
				{
				 el=1;
				}
			 else if(hr==t.tm_hour)
				{
				 if(min<t.tm_min)
					{
					 el=1;
					}
				 else if(min==t.tm_min)
					{
					 if(secs<t.tm_sec)
						{
						 el=1;
						}
					 else
						{
						 el=0;
						}
					}
				 else
					{
					 el=0;
					}
				}
			 else
				{
				 el=0;
				}
			}
		 else
			{
			 el=0;
			}
		}
	 else
		{
		 el=0;
		}
	 fcloseall();
	 remove("Time.txt");
	 return(el);
	}
void ap_link()
	{
	 FILE *p2;
	 int z1,z2;
	 p2=fopen("Applied.txt","r");
	 while((fscanf(p2,"%d %d",&z1,&z2))!=EOF)
		{
		 temp1=(struct applied*)malloc(sizeof(struct applied));
		 temp1->en1=z1;
		 temp1->rk1=z2;
		 temp1->n1=NULL;
		 temp1->b1=NULL;
		 if(first1==NULL)
			{
			 first1=temp1;
			 ap=first1;
			}
		 else
			{
			 ap->n1=temp1;
			 temp1->b1=ap;
			 ap=temp1;
			}
		}
	 fclose(p2);
	}
void se_link()
	{
	 FILE *p3;
	 int as;
	 char nc[40],nb[20];
	 p3=fopen("Seats.txt","r");
	 while((fscanf(p3,"%s %s %d\n",&nc,&nb,&as))!=EOF)
		{
		 temp4=(struct seat*)malloc(sizeof(struct seat));
		 strcpy(temp4->cn,nc);
		 strcpy(temp4->bn,nb);
		 temp4->ase=as;
		 temp4->n3=NULL;
		 if(first4==NULL)
			{
			 first4=temp4;
			 se=temp4;
			}
		 else
			{
			 se->n3=temp4;
			 se=temp4;
			}
		}
	 fclose(p3);
	}
void ap_file()
	{
	 FILE *p2;
	 ap=first1;
	 p2=fopen("Applied.txt","w");
	 while(ap!=NULL)
		{
		 fprintf(p2,"%d %d\n",ap->en1,ap->rk1);
		 ap=ap->n1;
		}
	 fclose(p2);
	}
void se_file()
	{
	 FILE *p1;
	 p1=fopen("Seats.txt","w");
	 se=first4;
	 while(se!=NULL)
		{
		 fprintf(p1,"%s %s %d\n",se->cn,se->bn,se->ase);
		 se=se->n3;
		}
	 fclose(p1);
	}
void preferences(int a,int b,int c,int e,int f,int g)
	{
	 FILE *p1,*p2,*p3;
	 int flag1=0,e_n,flag2=0,i,pr,j=0,com,k,h;
	 char st[10],c_n[40],ch,c_b[20],buffer[40];
	 p1=fopen("Rank.txt","r");
	 bk_gr1(12);
	 setcolor(4);
	 settextstyle(1,0,0);
	 setusercharsize(7,8,2,4);
	 outtextxy(105,200,"Enter your enrollment number");
	 gotoxy(40,16);
	 scanf("%d",&e_n);
	 first2=NULL;
	 first3=NULL;
	 cleardevice();
	 while(((fscanf(p1,"%d %s %s %d",&d.eno,d.fname,d.lname,&d.rk))!=EOF)&&(flag1==0))
		{
		 if(e_n==d.eno)
			{
			 cleardevice();
			 bk_gr1(7);
			 setcolor(4);
			 flag1=1;
			 settextstyle(1,0,0);
			 setusercharsize(10,7,4,4);
			 outtextxy(110,60,"APPLICANT DETAILS");
			 settextstyle(1,0,1);
			 sprintf(buffer, "Enrollment number: %d", d.eno);
			 outtextxy(200,170,buffer);
			 sprintf(buffer, "First name: %s", d.fname);
			 outtextxy(200,200,buffer);
			 sprintf(buffer, "Last name: %s", d.lname);
			 outtextxy(200,230,buffer);
			 sprintf(buffer, "Rank: %d", d.rk);
			 outtextxy(200,260,buffer);
			 getch();
			 cleardevice();
			 com=compare_time(a,b,c,e,f,g);
			 if(com==1)
				{
				 clrscr();
				 if(first1==NULL)
					{
					 temp1=(struct applied*)malloc(sizeof(struct applied));
					 temp1->en1=d.eno;
					 temp1->rk1=d.rk;
					 temp1->n1=NULL;
					 temp1->b1=NULL;
					 first1=temp1;
					 ap=first1;
					}
				 ap=first1;
				 while((ap!=NULL)&&(flag2==0))
					{
					 if(d.rk<=ap->rk1)
						{
						 if(d.rk==ap->rk1)
							{
							 flag2=1;
							}
						 else
							{
							 temp1=(struct applied*)malloc(sizeof(struct applied));
							 temp1->en1=d.eno;
							 temp1->rk1=d.rk;
							 temp1->n1=NULL;
							 temp1->b1=NULL;
							 flag2=1;
							 if(ap==first1)
								{
								 ap->b1=temp1;
								 temp1->n1=ap;
								 first1=temp1;
								 ap=first1;
								}
							 else
								{
								 temp1->n1=ap;
								 temp1->b1=ap->b1;
								 ap->b1->n1=temp1;
								 ap->b1=temp1;
								}
							}
						}
					 else
						{
						 ap=ap->n1;
						}
					}
				 if(flag2==0)
					{
					 temp1=(struct applied*)malloc(sizeof(struct applied));
					 temp1->en1=d.eno;
					 temp1->rk1=d.rk;
					 temp1->n1=NULL;
					 ap=first1;
					 while(ap->n1!=NULL)
						{
						 ap=ap->n1;
						}
					 ap->n1=temp1;
					 temp1->b1=ap;
					 ap=temp1;
					}
				 st[0]='\0';
				 while(e_n>0)
					{
					 st[j]=(e_n%10)+'0';
					 e_n=e_n/10;
					 j++;
					}
				 st[j]='\0';
				 strrev(st);
				 strcat(st,".txt");
				 p3=fopen(st,"w");
				 p2=fopen("Colleges.txt","r");
				 i=0;
				 while((fscanf(p2,"%s %s\n",c_n,c_b))!=EOF)
					{
					 temp2=(struct colleges*)malloc(sizeof(struct colleges));
					 strcpy(temp2->col,c_n);
					 strcpy(temp2->br,c_b);
					 temp2->n2=NULL;
					 temp2->b2=NULL;
					 if(first2==NULL)
						{
						 first2=temp2;
						 co=temp2;
						}
					 else
						{
						 co->n2=temp2;
						 temp2->b2=co;
						 co=temp2;
						 if(i<=13)
							{
							 sec=co;
							}
						}
					 i++;
					}
				 last1=co;
				 fclose(p2);
				 h=1;
				 high=first2;
				 {
				  setbkcolor(0);
				  cleardevice();
				  a1:
				  screen1();
				  co=first2;
				  i=90;
				  k=0;
				  while((co!=sec->n2)&&(co!=NULL))
					{
					 settextstyle(1,0,1);
					 if(high==co)
						{
						 if(h==1)
							{
							 setcolor(RED);
							 moveto(20,i);
							 outtext(co->col);
							 outtext(co->br);
							}
						 else
							{
							 setcolor(8);
							 moveto(20,i);
							 outtext(co->col);
							 outtext(co->br);
							}
						}
					 else
						{
						 setcolor(8);
						 moveto(20,i);
						 outtext(co->col);
						 outtext(co->br);
						}
					 i=i+20;
					 co=co->n2;
					 k++;
					}
				  co1=first3;
				  i=90;
				  j=0;
				  while((co1!=sec1->n2)&&(co1!=NULL))
					{
					 settextstyle(1,0,1);
					 if(high==co1)
						{
						 if(h==2)
							{
							 setcolor(RED);
							 moveto((getmaxx()/2)+20,i);
							 outtext(co1->col);
							 outtext(co1->br);
							}
						 else
							{
							 setcolor(8);
							 moveto((getmaxx()/2)+20,i);
							 outtext(co1->col);
							 outtext(co1->br);
							}
						}
					 else
						{
						 setcolor(8);
						 moveto((getmaxx()/2)+20,i);
						 outtext(co1->col);
						 outtext(co1->br);
						}
					 i=i+20;
					 if(co1->n2==NULL)
						{
						 last2=co1;
						}
					 co1=co1->n2;
					 j++;
					}
				  ch=getche();
				  switch(ch)
					{
					 case '1':if(h==1)
							{
							 if(high!=first2)
								{
								 high=high->b2;
								}
							 else
								{
								 if(first2->b2!=NULL)
									{
									 first2=first2->b2;
									 sec=sec->b2;
									 high=high->b2;
									}
								}
							}
						  else
							{
							 if(high!=first3)
								{
								 high=high->b2;
								}
							 else
								{
								 if(first3->b2!=NULL)
									{
									 first3=first3->b2;
									 sec1=sec1->b2;
									 high=high->b2;
									}
								}
							}
						  cleardevice();
						  goto a1;
					 case '2':if(h==1)
							{
							 if(high!=sec)
								{
								 high=high->n2;
								}
							 else
								{
								 if(sec->n2!=NULL)
									{
									 sec=sec->n2;
									 first2=first2->n2;
									 high=high->n2;
									}
								}
							}
						  else
							{
							 if(high!=sec1)
								{
								 high=high->n2;
								}
							 else
								{
								 if(sec1->n2!=NULL)
									{
									 sec1=sec1->n2;
									 first3=first3->n2;
									 high=high->n2;
									}
								}
							}
						  cleardevice();
						  goto a1;
					 case 9:if(h==1)
							{
							 if(first3!=NULL)
								{
								 high=first3;
								 h=2;
								}
							}
						else
							{
							 if(first2!=NULL)
								{
								 high=first2;
								 h=1;
								}
							}
						cleardevice();
						goto a1;
					 case 13:if(h==1)
							{
							 temp3=(struct colleges*)malloc(sizeof(struct colleges));
							 temp3->n2=NULL;
							 temp3->b2=NULL;
							 strcpy(temp3->col,high->col);
							 strcpy(temp3->br,high->br);
							 if(first3==NULL)
								{
								 first3=temp3;
								 sec1=first3;
								 sec2=first3;
								}
							 else
								{
								 last2->n2=temp3;
								 temp3->b2=last2;
								 last2=temp3;
								 if(j<=13)
									{
									 sec1=temp3;
									}
								}
							 if(high==first2)
								{
								 if(first2->b2==NULL)
									{
									 first2=first2->n2;
									 first2->b2=NULL;
									 high=first2;
									 if(sec->n2!=NULL)
										{
										 sec=sec->n2;
										}
									 if(first2==NULL)
										{
										 high=first3;
										 h=2;
										}
									}
								 else
									{
									 first2->b2->n2=first2->n2;
									 first2->n2->b2=first2->b2;
									 first2=first2->b2;
									 high=first2;
									}
								}
							 else if(high==sec)
								{
								 if(sec->n2==NULL)
									{
									 sec=sec->b2;
									 sec->n2=NULL;
									 high=sec;
									 last1=sec;
									 if(first2->b2!=NULL)
										{
										 first2=first2->b2;
										}
									}
								 else
									{
									 sec->b2->n2=sec->n2;
									 sec->n2->b2=sec->b2;
									 sec=sec->n2;
									 high=sec;
									}
								}
							 else
								{
								 high->b2->n2=high->n2;
								 high->n2->b2=high->b2;
								 high=high->n2;
								 if(sec->n2!=NULL)
									{
									 sec=sec->n2;
									}
								 else if(first2->b2!=NULL)
									{
									 first2=first2->b2;
									}
								}
							}
						 else
							{
							 temp2=(struct colleges*)malloc(sizeof(struct colleges));
							 temp2->n2=NULL;
							 temp2->b2=NULL;
							 strcpy(temp2->col,high->col);
							 strcpy(temp2->br,high->br);
							 if(first2==NULL)
								{
								 first2=temp2;
								 sec=first2;
								 last1=first2;
								}
							 else
								{
								 last1->n2=temp2;
								 temp2->b2=last1;
								 last1=temp2;
								 if(k<=13)
									{
									 sec=temp2;
									}
								}
							 if(high==first3)
								{
								 if(first3->b2==NULL)
									{
									 first3=first3->n2;
									 first3->b2=NULL;
									 high=first3;
									 if(sec1->n2!=NULL)
										{
										 sec1=sec1->n2;
										}
									 if(first3==NULL)
										{
										 high=first2;
										 h=1;
										}
									}
								 else
									{
									 first3->b2->n2=first3->n2;
									 first3->n2->b2=first3->b2;
									 first3=first3->b2;
									 high=first3;
									}
								}
							 else if(high==sec1)
								{
								 if(sec1->n2==NULL)
									{
									 sec1=sec1->b2;
									 sec1->n2=NULL;
									 high=sec1;
									 if(first3->b2!=NULL)
										{
										 first3=first3->b2;
										}
									}
								 else
									{
									 sec1->b2->n2=sec1->n2;
									 sec1->n2->b2=sec1->b2;
									 sec1=sec1->n2;
									 high=sec1;
									}
								}
							 else
								{
								 high->b2->n2=high->n2;
								 high->n2->b2=high->b2;
								 high=high->n2;
								 if(sec1->n2!=NULL)
									{
									 sec1=sec1->n2;
									}
								 else if(first3->b2!=NULL)
									{
									 first3=first3->b2;
									}
								}
							}
						 cleardevice();
						 goto a1;
					 case 27:co1=sec2;
						 while(co1!=NULL)
							{
							 fprintf(p3,"%s %s\n",co1->col,co1->br);
							 co1=co1->n2;
							}
						 fcloseall();
						 break;
					 default:goto a1;
					}
				 }
				}
			 else
				{
				 bk_gr1(7);
				 setcolor(4);
				 settextstyle(1,0,1);
				 outtextxy(10,230,"Now you can't submit preferences neither can make changes in it");
				 getch();
				}
			}
		}
	 if(flag1==0)
		{
		 bk_gr1(7);
		 setcolor(4);
		 settextstyle(1,0,3);
		 outtextxy(110,220,"You are not eligible for counselling");
		 getch();
		}
	 fcloseall();
	 cleardevice();
	}
void c1_allot()
	{
	 FILE *p1,*p2,*p3;
	 char c_n[40],c_b[20],st[10];
	 int flag1=0,as,flag2=0,e_n,j=0;
	 p1=fopen("Allotted.txt","w");
	 qu.front1=0;
	 qu.rear1=-1;
	 ap=first1;
	 while(ap!=NULL)
		{
		 push(ap->en1,ap->rk1);
		 ap=ap->n1;
		}
	 while(qu.front1<=qu.rear1)
		{
		 flag1=0;
		 j=0;
		 st[0]='\0';
		 e_n=qu.en2[qu.front1];
		 while(e_n>0)
			{
			 st[j]=(e_n%10)+'0';
			 e_n=e_n/10;
			 j++;
			}
		 st[j]='\0';
		 strrev(st);
		 strcat(st,".txt");
		 p2=fopen(st,"r");
		 while(((fscanf(p2,"%s %s\n",&c_n,&c_b))!=EOF)&&flag1==0)
			{
			 se=first4;
			 flag2=0;
			 while(se!=NULL&&flag2==0)
				{
				 if((strcmp(se->cn,c_n)==0)&&(strcmp(se->bn,c_b)==0))
					{
					 flag2=1;
					 if(se->ase>0)
						{
						 flag1=1;
						 se->ase=se->ase-1;
						 fprintf(p1,"%d %d %s %s\n",qu.en2[qu.front1],qu.rk2[qu.front1],se->cn,se->bn);
						}
					}
				 se=se->n3;
				}
			}
		 fclose(p2);
		 pop();
		}
	 fcloseall();
	}
void allot_check(int tim1,int tim2,int tim3)
	{
	 FILE *p1,*p2,*p3;
	 int e_n,flag1=0,flag2=0,flag3=0,se2,sr2;
	 char sc[40],sb[20],buffer[40];
	 if(tim1==0&&tim2==1)
		{
		 p1=fopen("Rank.txt","r");
		 bk_gr1(12);
		 setcolor(4);
		 settextstyle(1,0,0);
		 setusercharsize(7,8,2,4);
		 outtextxy(105,200,"Enter your enrollment number");
		 gotoxy(40,16);
		 scanf("%d",&e_n);
		 cleardevice();
		 while(((fscanf(p1,"%d %s %s %d",&d.eno,d.fname,d.lname,&d.rk))!=EOF)&&(flag1==0))
			{
			 if(e_n==d.eno)
				{
				 flag1=1;
				 ap=first1;
				 while(ap!=NULL&&flag2==0)
					{
					 if(ap->en1==e_n)
						{
						 flag2=1;
						 p2=fopen("Allotted.txt","r");
						 while((fscanf(p2,"%d %d %s %s",&se2,&sr2,&sc,&sb))!=EOF&&flag3==0)
							{
							 if(e_n==se2)
								{
								 flag3=1;

								 setcolor(4);
								 settextstyle(1,0,1);
								 sprintf(buffer, "Allotted College: %s",sc);
								 outtextxy(185,205,buffer);
								 sprintf(buffer, "Allotted Branch: %s",sb);
								 outtextxy(185,245,buffer);
								}
							}
						 if(flag3==0)
							{
							 bk_gr1(7);
							 setcolor(4);
							 settextstyle(1,0,2);
							 outtextxy(60,220,"No college is allotted to you from your preferences");
							 if(tim3==1)
								{
								 outtextxy(260,250,"Fill form 2");
								}
							}
						}
					 ap=ap->n1;
					}
				 if(flag2==0)
					{
					 bk_gr1(7);
					 setcolor(4);
					 settextstyle(1,0,3);
					 outtextxy(108,220,"You have not applied for counselling");
					}
				}
			}
		 if(flag1==0)
			{
			 bk_gr1(7);
			 setcolor(4);
			 settextstyle(1,0,3);
			 outtextxy(110,220,"You were not eligible for counselling");
			}
		}
	else if(tim1==1)
		{
		 if(tim3==1)
			{
			 bk_gr1(7);
			 setcolor(4);
			 settextstyle(1,0,3);
			 outtextxy(132,220,"Check your status after 1st June");
			}
		 else
			{
			 bk_gr1(7);
			 setcolor(4);
			 settextstyle(1,0,3);
			 outtextxy(132,220,"Check your status after 1st July");
			}
		}
	else
		{
		 bk_gr1(7);
		 setcolor(4);
		 settextstyle(1,0,0);
		 setusercharsize(9,8,2,4);
		 outtextxy(115,230,"NO DETAILS AVAILABLE");
		}
	getch();
	fcloseall();
       }
void regist(int tim1,int tim2)
	{
	 FILE *p1,*p2,*p3,*p6;
	 int e_n,flag1=0,flag2=0,flag3=0,se2,sr2,flag4=0,se1,sr1,draf;
	 char sc[40],sb[20],sc1[40],ho,ho1;
	 if(tim1==0&&tim2==1)
		{
		 p2=fopen("Allotted.txt","r");
		 p1=fopen("Register.txt","a+");
		 cleardevice();
		 bk_gr1(12);
		 setcolor(4);
		 settextstyle(1,0,0);
		 setusercharsize(7,8,2,4);
		 outtextxy(105,200,"Enter your enrollment number");
		 gotoxy(40,16);
		 scanf("%d",&e_n);
		 cleardevice();
		 while((fscanf(p1,"%d %d",&se1,&sr1))!=EOF&&flag1==0)
			{
			 if(e_n==se1)
				{
				 flag1=1;
				}
			}
		 if(flag1==0)
			{
			 while((fscanf(p2,"%d %d %s %s",&se2,&sr2,&sc,&sb))!=EOF&&flag3==0)
				{
				 if(e_n==se2)
					{
					 flag3=1;
					 strcpy(sc1,sc);
					 strcat(sc1,".txt");
					 p3=fopen(sc1,"a+");
					 p6=fopen("Rank.txt","r");
					 flag2=0;
					 fseek(p6,0,SEEK_SET);
					 while(((fscanf(p6,"%d %s %s %d",&d.eno,d.fname,d.lname,&d.rk))!=EOF)&&(flag2==0))
						{
						 if(e_n==d.eno)
							{
							 flag2=1;
							 while(flag4==0)
								{
								 cleardevice();
								 bk_gr1(12);
								 setcolor(4);
								 settextstyle(1,0,1);
								 outtextxy(150,205,"Want to take hostel (Y or N): ");
								 flushall();
								 gotoxy(56,14);
								 scanf("%c",&ho);
								 if(ho=='y'||ho=='Y'||ho=='n'||ho=='N')
									{
									 flag4=1;
									}
								 else
									{
									 outtextxy(205,235,"Enter correct choice");
									 getch();
									}
								}
							 if(ho=='y'||ho=='Y')
								{
								 ho1='H';
								}
							 else
								{
								 ho1='D';
								}
							 outtextxy(150,235,"Enter draft number: ");
							 gotoxy(46,16);
							 scanf("%d",&draf);
							 cleardevice();
							 fprintf(p3,"%d %s %s %d %s %c %d\n",d.eno,d.fname,d.lname,d.rk,sb,ho1,draf);
							 fprintf(p1,"%d %d\n",d.eno,d.rk);
							 bk_gr();
							 setcolor(4);
							 settextstyle(1,0,0);
							 setusercharsize(8,8,2,3);
							 outtextxy(64,230,"You have successfully registered");
							}
						}
					}
				}
			 if(flag3==0)
				{
				 cleardevice();
				 bk_gr1(7);
				 setcolor(1);
				 settextstyle(1,0,3);
				 outtextxy(90,220,"You are not on the list, can't register");
				}
			}
		 else
			{
			 cleardevice();
			 bk_gr1(7);
			 setcolor(1);
			 settextstyle(1,0,3);
			 outtextxy(156,220,"You have already registered");
			}
		}
	 else
		{
		 cleardevice();
		 bk_gr1(7);
		 setcolor(1);
		 settextstyle(1,0,3);
		 outtextxy(185,220,"You can't register now");
		}
	 fcloseall();
	 getch();
	}
void main()
{
int choice;
int tim1,tim2,tim3,tim4;
ap_link();
se_link();
front();
tim3=compare_time(0,0,1,1,5,1);
tim4=compare_time(0,2,1,1,5,1);
if(tim3==0&&tim4==1)
	{
	 c1_allot();
	}
tim3=compare_time(0,0,0,15,5,5);
tim4=compare_time(0,5,0,15,5,5);
if(tim3==0&&tim4==1)
	{

	}
tim3=compare_time(0,0,1,1,6,1);
tim4=compare_time(0,2,1,1,6,1);
if(tim3==0&&tim4==1)
	{
	 c1_allot();
	}
tim3=compare_time(0,0,0,15,6,5);
tim4=compare_time(0,5,0,15,6,5);
if(tim3==0&&tim4==1)
	{

	}
do
	{
	 t5:
	 choice=menu();
	 switch(choice)
		{
		 case 1:ingraph();
			cleardevice();
			process();
			cleardevice();
			closegraph();
			break;
		 case 2:ingraph();
			schedule();
			cleardevice();
			closegraph();
			break;
		 case 3:ingraph();
			queries();
			cleardevice();
			closegraph();
			break;
		 case 4:ingraph();
			tim3=compare_time(0,0,1,15,5,2);
			if(tim3==1)
				{
				 preferences(0,59,23,31,4,0);
				}
			else
				{
				 preferences(0,59,23,30,5,2);
				}
			cleardevice();
			closegraph();
			break;
		 case 5:ingraph();
			tim3=compare_time(0,0,1,15,5,2);
			if(tim3==1)
				{
				 tim1=compare_time(0,0,1,2,4,2);
				 tim2=compare_time(0,59,23,14,5,5);
				}
			else
				{
				 tim1=compare_time(0,0,1,2,6,4);
				 tim2=compare_time(0,59,23,14,6,0);
				}
		       allot_check(tim1,tim2,tim3);
			cleardevice();
			closegraph();
			break;
		 case 6:ingraph();
			tim3=compare_time(0,0,1,15,4,2);
			if(tim3==1)
				{
				 tim1=compare_time(0,0,1,2,4,2);
				 tim2=compare_time(0,59,23,14,5,5);
				}
			else
				{
				 tim1=compare_time(0,0,1,2,6,4);
				 tim2=compare_time(0,59,23,14,6,0);
				}
			regist(tim1,tim2);
			cleardevice();
			closegraph();
			break;
		 case 7:ingraph();
			info();
			cleardevice();
			closegraph();
			break;
		 case 8:ap_file();
			se_file();
			exit(0);
		 default:goto t5;
		}
	}
while(choice!=8);
}
void queries()
{
int n,m,k,l;
t2:
bk_gr();
settextstyle(SANS_SERIF_FONT,HORIZ_DIR,2);
setcolor(RED);
outtextxy(120,170,"1. Queries Before Ist Cuncelling");
outtextxy(120,200,"2. Queries After Ist Councelling");
outtextxy(120,230,"3. Queries After IInd Councelling/Registration");
outtextxy(120,260,"4- Go back to main menu");
outtextxy(140,300,"Enter your choice: ");
gotoxy(44,20);
scanf("%d",&n);
cleardevice();
switch(n)
{	case 1:    t1:
		   bk_gr1(2);
		   settextstyle(SANS_SERIF_FONT,HORIZ_DIR,1);
		   setcolor(5);
		   outtextxy(100,130,"1. Number of seats in a college--");
		   outtextxy(100,160,"2. Previous year opening and closing rank--");
		   outtextxy(100,190,"3. Go back to previous menu");
		   outtextxy(120,250,"Enter your choice: ");
		   gotoxy(42,17);
		   scanf("%d",&m);
		   cleardevice();
		   switch(m)
		       {
			case 1: tree();
				cleardevice();
				goto t1;
			case 2: rank();
				cleardevice();
				goto t1;
			case 3: goto t2;
			default:goto t1;
		       }
	case 2: t3:
		bk_gr1(2);
		settextstyle(SANS_SERIF_FONT,HORIZ_DIR,1);
		setcolor(5);
	       outtextxy(100,100,"1. Number of seats filled");
	       outtextxy(100,130,"2. No of seats vacant");
	       outtextxy(100,160,"3. Opening rank of this year");
	       outtextxy(100,190,"4. Go back to previous menu");
	       outtextxy(120,250,"Enter your choice:");
	       gotoxy(42,17);
	       scanf("%d",&m);
	       cleardevice();
	       switch(m)
			{
			 case 1:branch();
				cleardevice();
				goto t3;
			case 2: seats_vacant();
			       cleardevice();
				goto t3;
			case 3: open_rank();
				cleardevice();
				goto t3;
			case 4: goto t2;
			default:goto t3;
		       }
	case 3: t4:
		bk_gr1(2);
		settextstyle(SANS_SERIF_FONT,HORIZ_DIR,2);
		setcolor(BLACK);
		outtextxy(100,100,"1. Closing rank");
		outtextxy(100,130,"2. Statistics of hostelers and dayscholars");
		outtextxy(100,160,"3. Number of students in a branch");
		outtextxy(100,190,"4. Go back to previous menu");
		outtextxy(120,250,"Enter your choice: ");
		gotoxy(42,17);
		scanf("%d",&m);
		cleardevice();
		switch(m)
		    {
		     case 1:close_rank();
			    cleardevice();
			    goto t4;
		     case 2:hostel();
			    cleardevice();
			    goto t4;
		     case 3:colbranch();
			    cleardevice();
			    goto t4;
		     case 4:goto t2;
		     default:goto t4;
		    }
	case 4:menu();
	       break;
	default:goto t2;
	}
}
void rank()
{
	FILE *fp,*fp3;
	int open,close,i=0;
	char coll[10],br[10],str1[50],str2[50],a[10],bran[20];
	fp3=fopen("branch.txt","r");
	cleardevice();
	bk_gr1(3);
	i=0;
	while(fscanf(fp3,"%s",bran)!=EOF)
	{       flushall();
		settextstyle(SANS_SERIF_FONT,HORIZ_DIR,2);
		setcolor(8);
		outtextxy(100,100+(10*i),bran);
		i=i+3;
	}
	outtextxy(130,326,"Enter code of the branch: ");
	gotoxy(54,22);
	gets(a);
	fp=fopen("rank12.txt","r");
	cleardevice();
	bk_gr1(6);
	i=0;
	settextstyle(SANS_SERIF_FONT,HORIZ_DIR,1);
	setcolor(BLACK);
	flushall();
	while(fscanf(fp,"%s %s %d %d",coll,br,&open,&close)!=EOF)
	{
	  if(strcmp(a,br)==0)
		{
			outtextxy(30,20+(30*i),coll);
			outtextxy(130,20+(30*i),br);
			sprintf(str1,"Opening Rank:%d",open);
			outtextxy(230,20+(30*i),str1);
			sprintf(str2,"Closing Rank:%d",close);
			outtextxy(440,20+(30*i),str2);
			i++;
		}
	}
	fcloseall();
	getch();
}
void tree()
 {
 FILE *fp;
 int i=0,d=4,a=0,j,flag=1;
 char colname[20],str1[100];
 fp=fopen("col2.txt","r");
 while(fscanf(fp,"%s",colname)!=EOF)
{  strcpy(t[i],colname);
    i++;
}
 i=0;
 flag=2;
 cleardevice();
 bk_gr1(3);
 settextstyle(4,HORIZ_DIR,3);
 setcolor(1);
 outtextxy(200,150,t[i]);
 tree_rec(i,d,flag,a);
 getch();
 fcloseall();
 }
void tree_rec(int i,int d,int flag,int a)
 {
 int count,j,k,n=0;
 char str1[20],str2[20];
 setcolor(BLACK);
 settextstyle(SANS_SERIF_FONT,HORIZ_DIR,1);
 if(flag==d)
 {	if(i==1)
	{
		for(j=1;j<=a;j++)
		n=((8*i)+j)+(8*(1+j))-(j-1);
		for(k=0;k<8;k++)
		{
		if(strcmp(t[n+k],"NONE")!=0)
		outtextxy(140,200+(50*k),t[n+k]);
		}
	}
	else
	{
		for(j=1;j<=a;j++)
		n=((8*i)+j)+(8*(8+j))-(j-1);
		for(k=0;k<8;k++)
		{if(strcmp(t[n+k],"NONE")!=0)
		outtextxy(140,200+(50*k),t[n+k]);
		}
	}
getch();
 }
 else
 {	for(j=1;j<8;j++)
		{flushall();
		if(strcmp(t[(8*i)+j],"NONE")!=0)
			{	sprintf(str1,"%d.)    %s",j,t[(8*i)+j]);
				outtextxy(100,200+(25*j),str1);
			 }
		}
 outtextxy(100,200+(24*j),"Enter your choice : ");
 gotoxy(40,26);
 scanf("%d",&a);
 flag++;
	if(flag==4)
	{
	cleardevice();
	bk_gr1(5);
	tree_rec(i,d,flag,a);
	}
	else
	{
	cleardevice();
	bk_gr1(4);
	i=(2*i)+a;
	tree_rec(i,d,flag,a);
	}
   fcloseall();
 }
}
void branch()
{
  FILE *fp,*fp1,*fp2;
   int i=0,rank,x=0,y,z;
   int cnt[15]={0},seat;
   char a[5],file[20],colname[20],branch1[20],str[20],bran[20];
   char arr[20][25],f[20],b[20],arr1[20][25]={'\0'},st[20];
   fp1=fopen("col1.txt","r");
   while(fscanf(fp1,"%s",f)!=EOF)
   {
	strcpy(arr[i],f);
	i++;
  }
   x=i;
   cleardevice();
   bk_gr1(4);
   settextstyle(SANS_SERIF_FONT,HORIZ_DIR,1);
   setcolor(BLACK);
   i=0;
   fp=fopen("branch.txt","r");
   while(fscanf(fp,"%s",bran)!=EOF)
   {
   flushall();
   outtextxy(100,100+(20*i),bran);
   i++;
   }
   outtextxy(150,375,"Enter the Branch: ");
   flushall();
   gotoxy(45,25);
   gets(a);
   i=0;
   while(i<x)
   {
       flushall();
	strcpy(file,arr[i]);
	strcat(file,".txt");
	fp1=fopen(file,"r");
		while(fscanf(fp1,"%d %s %s %d %s %c %d",&c.enroll,c.name,c.surname,&c.rank,c.branch,&c.status,&c.dd)!=EOF)
		{
		if(strcmp(c.branch,a)==0)
		cnt[i]++;
		}
	i++;
   }
   fclose(fp);
   fclose(fp1);
   fp2=fopen("COL12.TXT","r");
   i=0;
	while(fscanf(fp2,"%s",str)!=EOF)
		{
		strcpy(arr1[i],str);
		i++;
		}
  cleardevice();
  bk_gr1(2);
  settextstyle(SANS_SERIF_FONT,HORIZ_DIR,2);
  setcolor(8);
  outtextxy(170,50,"SEATS FILLED");
 for(i=0;i<x;i++)
   {
    settextstyle(SANS_SERIF_FONT,HORIZ_DIR,1);
   setcolor(BLACK);
   outtextxy(25+(50*i),350+(20*(i%2)),arr1[i]);
   flushall();
   sprintf(st,"%d",cnt[i]);
   outtextxy(25+(50*i),150,st);
   bar(25+(50*i),300,25+(50*i)+20,300-(cnt[i]*20));
   setfillstyle(1,3+i);
   getch();
   }
  fcloseall();
}
void seats_vacant()
{
FILE *fp,*fp1;
int i=0,seat=0,cnts=0,cnt=0;
char colname[20],branch[5],str1[40],a[40],file[20],b[6];
   flushall();
   strcpy(a,list());
   strcpy(file,a);
   strcat(file,".txt");
   fp=fopen(file,"r");
   fp1=fopen("seats12.txt","r");
   cleardevice();
   bk_gr1(13);
   settextstyle(SANS_SERIF_FONT,HORIZ_DIR,2);
   setcolor(5);
   while(fscanf(fp1,"%s %s %d",colname,branch,&seat)!=EOF)
   {
	if(strcmp(colname,a)==0)
	{	outtextxy(150,200+(40*i),branch);
		i++;
	}
   }
   outtextxy(150,377,"Enter the Branch: ");
   flushall();
   gotoxy(45,25);
   gets(b);
   fclose(fp1);
   fp1=fopen("seats.txt","r");
   while(fscanf(fp1,"%s %s %d",colname,branch,&seat)!=EOF)
   {
	if(strcmp(colname,a)==0&&strcmp(branch,b)==0)
	{
	cnts=seat;
	break;
	}
   }
   cnt=0;
   while(fscanf(fp,"%d %s %s %d %s %c %d",&c.enroll,c.name,c.surname,&c.rank,c.branch,&c.status,&c.dd)!=EOF)
   {
	if(strcmp(c.branch,b)==0)
	cnt++;
   }
cleardevice();
bk_gr1(5);
settextstyle(SANS_SERIF_FONT,HORIZ_DIR,2);
setcolor(RED);
sprintf(str1,"seats vacant %d",cnts-cnt);
outtextxy(150,250,str1);
fcloseall();
getch();
}
void open_rank()
{
FILE *fp;
int min=0,temp;
char str1[40],a[20],file[20];
   flushall();
   strcpy(a,list());
   strcpy(file,a);
   strcat(file,".txt");
   fp=fopen(file,"r");
   fscanf(fp,"%d %s %s %d %s %c %d",&c.enroll,c.name,c.surname,&c.rank,c.branch,&c.status,&c.dd);
    min=c.rank;
	   while(fscanf(fp,"%d %s %s %d %s %c %d",&c.enroll,c.name,c.surname,&c.rank,c.branch,&c.status,&c.dd)!=EOF)
   {
	if(c.rank<min)
	min=c.rank;
   }
   sprintf(str1,"Opening Rank %d",min);
   cleardevice();
   bk_gr1(5);
   settextstyle(SANS_SERIF_FONT,HORIZ_DIR,2);
   setcolor(10);
   outtextxy(100,200,str1);
   getch();
}
void close_rank()
{
 FILE *fp;
int max=0;
char str1[40],a[20],file[20];
   flushall();
   strcpy(a,list());
   strcpy(file,a);
   strcat(file,".txt");
   fp=fopen(file,"r");
   while(fscanf(fp,"%d %s %s %d %s %c %d",&c.enroll,c.name,c.surname,&c.rank,c.branch,&c.status,&c.dd)!=EOF)
   {
	if(c.rank>max)
	max=c.rank;
   }
   sprintf(str1,"Closing Rank %d",max);
   cleardevice();
   bk_gr1(6);
   settextstyle(SANS_SERIF_FONT,HORIZ_DIR,2);
   setcolor(10);
   outtextxy(100,200,str1);
   getch();
}
void hostel()
{
  FILE *fp;
     int midx, midy, i;
   int stangle, endangle;
   int xrad = 100, yrad = 100,rank,x,y;
   float cnt1=0,cnt2=0,cnt=0;
   char a[20],file[20];
   midx = getmaxx() / 2;
   midy = getmaxy() / 2;
  flushall();
  strcpy(a,list());
  strcpy(file,a);
   strcat(file,".txt");
   fp=fopen(file,"r");
      while(fscanf(fp,"%d %s %s %d %s %c %d",&c.enroll,c.name,c.surname,&c.rank,c.branch,&c.status,&c.dd)!=EOF)
   {
	if(c.status=='H')
	cnt1++;
	else
	cnt2++;
  }
   cleardevice();
     bk_gr1(6);
     cnt=cnt1+cnt2;
   x=((cnt1/cnt)*100);
   stangle=0;
   endangle=(360/100)*x;
   setfillstyle(1,GREEN);
   sector(midx, midy, stangle, endangle, xrad, yrad);
   settextstyle(SANS_SERIF_FONT,HORIZ_DIR,1);
   setcolor(CYAN);
   outtextxy(midx+150,midy-50,"Hosteller");
   stangle=endangle;
   endangle=360;
   setfillstyle(1,YELLOW);
   sector(midx, midy, stangle, endangle, xrad, yrad);
   settextstyle(SANS_SERIF_FONT,HORIZ_DIR,1);
   setcolor(CYAN);
   outtextxy(midx-120,midy+120,"Day Scholar");
   fcloseall();
   getch();
}
void colbranch()
{
   FILE *fp;
   int midx, midy, i;
   int stangle, endangle;
   float cnt=0;
   int xrad = 100, yrad = 100,rank,x,y,z,z1,z2,z3;
   int cnt1=0,cnt2=0,count=0,cnt3=0,cnt4=0,cnt5=0,cnt6=0;
   char a[20],file[20],str1[100],str2[100];
   midx = getmaxx() / 2;
   midy = getmaxy() / 2;
   strcpy(a,list());
   strcpy(file,a);
   strcat(file,".txt");
   fp=fopen(file,"r");
   while(fscanf(fp,"%d %s %s %d %s %c %d",&c.enroll,c.name,c.surname,&c.rank,c.branch,&c.status,&c.dd)!=EOF)
   {
	if(strcmp(c.branch,"CS")==0)
	cnt1++;
	else if(strcmp(c.branch,"ECE")==0)
	cnt2++;
	else if(strcmp(c.branch,"EEE")==0)
	cnt3++;
	else if(strcmp(c.branch,"ME")==0)
	cnt4++;
	else if(strcmp(c.branch,"CIVIL")==0)
	cnt5++;
	else if(strcmp(c.branch,"IT")==0)
	cnt6++;
   }
   cleardevice();
   bk_gr1(6);
   settextstyle(SANS_SERIF_FONT,HORIZ_DIR,2);
   setcolor(BLACK);
   sprintf(str1,"CS:%d     ECE:%d        EEE:%d ",cnt1,cnt2,cnt3);
   sprintf(str2,"ME:%d     CIVIL:%d      IT:%d",cnt4,cnt5,cnt6);
   outtextxy(50,50,str1);
   outtextxy(50,100,str2);
   count=cnt1+cnt2+cnt3+cnt4+cnt5+cnt6;
   cnt=(float)count;
   x=((cnt1/cnt)*100);
   if(x!=0)
   {
   stangle=0;
   endangle=(360/100)*x;
   sector(midx, midy, stangle, endangle, xrad, yrad);
   setfillstyle(1,1);
   getch();
   }
   y=(cnt2/cnt)*100;
   if(y!=0)
   {
   stangle=endangle;
   endangle=stangle+(360/100)*y;
   sector(midx, midy, stangle, endangle, xrad, yrad);
   setfillstyle(1,3);
   getch();
   }
   z=(cnt3/cnt)*100;
   if(z!=0)
   {
   stangle=endangle;
   endangle=stangle+(360/100)*z;
   sector(midx, midy, stangle, endangle, xrad, yrad);
   setfillstyle(1,4);
   getch();
   }
   z1=(cnt4/cnt)*100;
   if(z1!=0)
   {
   stangle=endangle;
   endangle=stangle+(360/100)*z1;
   sector(midx, midy, stangle, endangle, xrad, yrad);
   setfillstyle(1,5);
   getch();
   }
   z2=(cnt5/cnt)*100;
   if(z2!=0)
   {
   stangle=endangle;
   endangle=stangle+(360/100)*z2;
   sector(midx, midy, stangle, endangle, xrad, yrad);
   setfillstyle(1,6);
   getch();
   }
   z3=(cnt6/cnt)*100;
   if(z3!=0)
   {
   stangle=endangle;
   endangle=stangle+(360/100)*z3;
   sector(midx, midy, stangle, endangle, xrad, yrad);
   setfillstyle(1,7);
   getch();
   }
   else
   {
   stangle=endangle;
   endangle=360;
   setcolor(BLACK);
   sector(midx, midy, stangle, endangle, xrad, yrad);
   setfillstyle(1,8);
   getch();
   }
   fcloseall();
}
void info()
{
FILE *fp;
char a[20],file[20],str1[30],str2[30],str3[30],str4[30],str5[30],str6[30],str7[30];
int e;
strcpy(a,list());
strcpy(file,a);
strcat(file,".txt");
fp=fopen(file,"r");
cleardevice();
bk_gr1(6);
settextstyle(SANS_SERIF_FONT,HORIZ_DIR,2);
setcolor(BLACK);
outtextxy(100,150,"Enter Your Enrollment Number");
gotoxy(28,14);
scanf("%d",&e);
while(fscanf(fp,"%d %s %s %d %s %c %d",&c.enroll,c.name,c.surname,&c.rank,c.branch,&c.status,&c.dd)!=EOF)
{	if(e==c.enroll)
	{
	cleardevice();
	bk_gr1(3);
	settextstyle(SANS_SERIF_FONT,HORIZ_DIR,1);
	setcolor(MAGENTA);
	sprintf(str1,"Enrollment no.: %d",c.enroll);
	sprintf(str2,"Name :         %s",c.name);
	sprintf(str3,"Last name :    %s ",c.surname);
	sprintf(str4,"Rank :          %d",c.rank);
	sprintf(str5,"Branch :        %s",c.branch);
	sprintf(str6,"Hostel/Day :    %c",c.status);
	sprintf(str7,"DD No :         %d",c.dd);
	outtextxy(150,50,str1);
	outtextxy(150,70,str2);
	outtextxy(150,90,str3);
	outtextxy(150,110,str4);
	outtextxy(150,130,str5);
	outtextxy(150,150,str6);
	outtextxy(150,170,str7);
	break;
	}
}
getch();
fcloseall();
}
void front()
{
int i,j;
ingraph();
settextstyle(0,0,1);
setcolor(15);
for(i=0;i<250;i++)
	{
	 outtextxy(random(640),random(480),".");
	}
setcolor(1);
for(i=0;i<250;i++)
	{
	 outtextxy(random(640),random(480),".");
	}
for(i=0,j=300;i<=150;i+=5,j-=5)
	{
	 settextstyle(1,0,7);
	 setcolor(10);
	 outtextxy(i,150,"A     I ");
	 outtextxy(j,150,"   E     E");
	 setcolor(0);
	 //sound(200+j*10);
	 delay(50);
	 outtextxy(i,150,"A     I ");
	 outtextxy(j,150,"   E     E");
	}
setcolor(14);
settextstyle(1,0,7);
nosound();
outtextxy(j-40,100,"A  I  E  E  E");
settextstyle(1,0,2);
for(i=305,j=305;i<=540;i+=5,j-=5)
	{
	 outtextxy(i,160,"Í");
	 outtextxy(j,160,"Í");
	 delay(150);
	}
settextstyle(1,0,5);
outtextxy(215,200,"COUNSELLING");
settextstyle(2,0,9);
outtextxy(60,280,"SUBMITTED BY:->");
settextstyle(2,0,7);
outtextxy(320,320,"AYUSH KUMAR SINGH  10103485");
outtextxy(320,340,"ANIRUDH GOEL  10103488");
outtextxy(320,360,"SHUBHAM JAIN  10103489");
getch();
cleardevice();
closegraph();
}
int menu()
	{
	 int choice,tim3;
	 ingraph();
	 cleardevice();
	 bk_gr();
	 setcolor(4);
	 settextstyle(1,0,0);
	 setusercharsize(4,3,1,1);
	 outtextxy(130,100,"AIEEE COUNSELLING");
	 settextstyle(1,0,1);
	 outtextxy(90,160,"1- Process of Counselling");
	 outtextxy(90,182,"2- Counselling Schedule");
	 outtextxy(90,204,"3- Queries");
	 tim3=compare_time(0,0,1,15,5,2);
	 if(tim3==0)
		{
		 outtextxy(90,226,"4- Submission of preferences for 2nd counselling");
		 outtextxy(90,248,"5- Status after 2nd counselling");
		}
	 else
		{
		 outtextxy(90,226,"4- Submission of preferences for 1st counselling");
		 outtextxy(90,248,"5- Status after 1st counselling");
		}
	 outtextxy(90,270,"6- Registeration");
	 outtextxy(90,292,"7- Details of applicant");
	 outtextxy(90,314,"8- Exit");
	 outtextxy(216,360,"Enter your choice:  ");
	 gotoxy(51,24);
	 scanf("%d",&choice);
	 cleardevice();
	 closegraph();
	 return(choice);
	}


