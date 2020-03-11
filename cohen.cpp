#include<graphics.h>
#include<math.h>
#include<dos.h>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void kod( int xw1, int yw1,int xw2, int yw2, int x, int y, int b[],int &b10 )
{
    for( int i=0;i<4;i++)
    b[i]=0;
    if(x<xw1) b[0]=1;
    if(x>xw2) b[1]=1;
    if(y<yw1) b[2]=1;
    if(y>yw2) b[3]=1;

    b10=b[3]*8+b[2]*4+b[1]*2+b[0];
}
void cohen(int xw1, int yw1, int xw2, int yw2, int xa, int ya, int xb, int yb)
{
    bool ketthuc=false;
    int A[4],B[4];
    int A10,B10;
    while(!ketthuc)
    {
        kod(xw1,yw1,xw2,yw2,xa,ya,A,A10);
        kod(xw1,yw1,xw2,yw2,xb,yb,B,B10);
        if((A10==0)&&(B10==0))   //TH1
        {
            line(xa,ya,xb,yb);
            ketthuc=true;
        }
        else
            if((A10&B10)!=0)  //TH2
        {
            ketthuc=true;
        }
        else
        {
            //TH3
            if (A10==0)
            {
                int tg=xa;xa=xb;xb=tg;
                    tg=ya;ya=yb;yb=tg;
                    kod(xw1,yw1,xw2,yw2,xa,ya,A,A10);

            }
            float m=(float)(yb-ya)/(xb-xa);
            if (A[0]==1)
            {
                ya=(int)(m*(xw1-xa)+ya+0.5);
                xa=xw1;
            } else
            if (A[1]==1)
            {
                ya=(int)(m*(xw2-xa)+ya+0.5);
                xa=xw2;
            } else
            if (A[2]==1)
            {
                xa=(int)((1/m)*(yw1-ya)+xa+0.5);
                ya=yw1;
            } else
            if (A[3]==1)
            {
                xa=(int)((1/m)*(yw2-ya)+xa+0.5);
                ya=yw2;
            }
        }
    }
}
int main()
{
    int gd=0,gm;
    initgraph(&gd,&gm,"");
    //truoc khi cat
    setcolor(4);
	rectangle(100,100,300,250);
	//sau khi cat
    setcolor(0);
    line(100,50,400,300);
    setcolor(YELLOW);
    cohen(100,100,300,250,100,50,400,300);
    getch();
}


