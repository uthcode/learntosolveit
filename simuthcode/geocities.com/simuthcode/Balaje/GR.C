#include<graphics.h>
#include<math.h>
gr()
{
int gd=DETECT,gm;
initgraph(&gd,&gm,"");
}
cir(int a,int b,int r)
{
float x,y,z;
int i,j;
for(i=0;i<=360;i++)
{
z=i*(3.14/180);
x=r*cos(z)+a;
y=r*sin(z)+b;
putpixel(x,y,10);
}
}

ell(int a,int b,int a1,int b1,float th)
{
static m,n;
float x,y,x1,y1,z;
int i,j;
setlinestyle(1,1,1);
for(i=0;i<=360;i++)
{
z=i*(3.14/180);
x=a1*sin(z);
y=b1*cos(z);
z=th*(3.14/180);
x1=x*cos(z)-y*sin(z)+a;
y1=x*sin(z)+y*cos(z)+b;

//
//x=*cos(th);//+y*sin(th)+1;
//y=y*sin(th);//+x*cos(th)+1;
//z=(i+1)*(18//0/3.14);
//x1=a1*cos(z)+a;
//y1=b1*sin(z)+b;

putpixel(x1,y1,10);
//line(x1,y1,x,y);
}
}

