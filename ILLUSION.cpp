#include <stdio.h>
#include <dos.h>
#include <graphics.h>
#include <stdlib.h>
#include <conio.h>
class illu
{
  int xmax,ymax;
  int gmode,errorcode,gdriver;
  public:
  illu()
  {
    gdriver=DETECT;
    gmode=0,errorcode=0;
    initgraph(&gdriver,&gmode,"C:\\TURBOC3\\BGI");
    errorcode=graphresult();
    if(errorcode!=grOk)
    {
      printf("Graphics error : %s\n",grapherrormsg(errorcode));
      printf("Press any key to exit\n");
      getch();
      exit(0);
    }
    xmax=getmaxx();
    ymax=getmaxy();
    setcolor(YELLOW);
	settextstyle(1,0,6);
	outtextxy(0,240,"Count the black dots.....");
	sleep(4);
	cleardevice();
  }
  void circ();
  void dot();
};
void illu::circ()
{
	int i;
	for(i=0;i<15;i++)
		circle(320,240,i*10);
	rectangle(240,160,400,320);
}
void illu::dot()
{
	int i,j,of=40,wid=5;
	setcolor(8);
	setfillstyle(1,getcolor());
	for(i=of;i<getmaxx();i+=of)
		bar(i,0,i+wid,getmaxy());

	for(i=of;i<getmaxy();i+=of)
		bar(0,i,getmaxx(),i+wid);

	for(i=of;i<getmaxx();i+=of)
		for(j=of;j<getmaxy();j+=of)
		{
			setcolor(15);
			setfillstyle(1,getcolor());
			circle(i+2,j+2,4);
			floodfill(i+2,j+2,getcolor());
		}

}
int main()
{
    illu z;
    z.dot();
	getch();
	cleardevice();
	settextstyle(1,0,4);
	outtextxy(0,240,"I bet the lines of rectangle are straight.....");
	sleep(4);
	cleardevice();
	z.circ();
	getch();
	closegraph();
    return 0;
}

