#include <stdio.h>
#include <graphics.h>
#define Mx getmaxx()
#define My getmaxy()

int main()
{
    printf("\n\n\n\n");
    printf("\t   dMMMMMP  dMP dMP  dMMMMMMMMb   dMMMMb   dMP  dMMMMb  .aMMMMP        dMMMMMP  .aMMMb  .aMMMb   dMP dMP     \n");
    printf("\t      dMP  dMP dMP  dMP dMP dMP  dMP.dMP  amr  dMP dMP dMP                dMP  dMP dMP dMP VMP  dMP.dMP      \n");
    printf("\t     dMP  dMP dMP  dMP dMP dMP  dMMMMP   dMP  dMP dMP dMP MMP            dMP  dMMMMMP dMP      dMMMMK        \n");
    printf("\tdK .dMP  dMP.aMP  dMP dMP dMP  dMP      dMP  dMP dMP dMP.dMP        dK  dMP  dMP dMP dMP.aMP  dMP AMF        \n");
    printf("\tVMMMP'   VMMMP'  dMP dMP dMP  dMP      dMP  dMP dMP  VMMMP          VMMMP   dMP dMP  VMMMP   dMP dMP         \n");
    printf("\n\n\n\n");

    int gd,gm,i=0,h=0;

    L:detectgraph(&gd,&gm);
    initgraph(&gd,&gm,NULL);
    getch();

    int x=Mx-20,y=Mx;
    char ch;
    void *left,*right,*up;

    //Creating Images
    circle(100,100,7);
    rectangle(92,107,107,128);
    rectangle(92-5,110,92,120);
    rectangle(107,110,112,120);
    rectangle(93,128,98,145);
    rectangle(101,128,106,135);
    left = malloc(imagesize(92-6,92,113,146));
    getimage(92-6,92,113,146,left);
    cleardevice();

    circle(100,100,7);
    rectangle(92,107,107,128);
    rectangle(92-5,110,92,120);
    rectangle(107,110,112,120);
    rectangle(93,128,98,135);
    rectangle(101,128,106,145);
    right = malloc(imagesize(92-6,92,113,146));
    getimage(92-6,92,113,146,right);
    cleardevice();

    circle(100,100,7);
    rectangle(92,107,107,128);
    rectangle(92-5,110,92,100);
    rectangle(107,110,112,100);
    rectangle(93,128,98,145);
    rectangle(101,128,106,145);
    up = malloc(imagesize(92-6,92,113,146));
    getimage(92-6,92,113,146,up);
    cleardevice();

    void *object[3];                                        //images loaded in array

    while(i<3)
    {
        cleardevice();
        setcolor(WHITE);
        rectangle(1,137,10+10*i,145);
        setfillstyle(1,4+i);
        floodfill(2,138,WHITE);
        object[i]=malloc(imagesize(0,136,10+10*i+1,146));
        getimage(0,136,10+10*i+1,146,object[i]);
        i++;
    }

    printf("\n\t\t\t\t---------------------START---------------------");

    int jump=0,j=0;
    i=0;

    while(1)
    {
        cleardevice();

        char a[10]="";
        itoa(i,a,10);
            outtextxy(400,100,a);                                       //Score

        itoa(h,a,10);
        outtextxy(450,100,a);                                          //HighScore

        if(x<=0)
        {
            x=Mx-20;
            y=Mx;
            j++;
            j%=3;
        }

        line(0,146,Mx,146);

        if(kbhit())
        {
            ch = getch();

            if(ch==' ')
            {
                jump=1;
            }
        }

        if(jump==1)
        {
            int p=92;

            while(p>20)
            {
                putimage(86,p,up,XOR_PUT);
                putimage(x,135,object[j],XOR_PUT);
                delay(0.1);
                putimage(86,p--,up,XOR_PUT);
                putimage(x,135,object[j],XOR_PUT);
                if(p%8==1)
                {
                    x-=4;
                    y-=4;
                }
            }

            while(p<92)
            {
                putimage(86,p,up,XOR_PUT);
                putimage(x,135,object[j],XOR_PUT);
                delay(0.1);
                putimage(86,p++,up,XOR_PUT);
                putimage(x,135,object[j],XOR_PUT);
                if(p%8==1)
                {
                    x-=4;
                    y-=4;
                }
            }
            jump=0;
        }

        else if(i%2==0)
        {
            putimage(86,92,left,XOR_PUT);
            putimage(x,135,object[j],XOR_PUT);
            if(!jump)delay(50);
            putimage(86,92,left,XOR_PUT);
            putimage(x,135,object[j],XOR_PUT);
            x-=8;
            y-=8;
        }

        else
        {
            putimage(86,92,right,XOR_PUT);
            putimage(x,135,object[j],XOR_PUT);
            if(!jump)delay(50);
            putimage(86,92,right,XOR_PUT);
            putimage(x,135,object[j],XOR_PUT);
            x-=8;
            y-=8;
        }

        if(x>=80&&y<=120&&jump==0)
        {
            closegraph();
            printf("\n\t\t\t\t\t\tYour Score was - %d",i);

            if(i>h)
            {
                h=i;
                printf("\n\n\t\t\t\t\t\tHighScore!!!!");
            }

            int d;
            printf("\n\n\tDo You Want to play Again : ");
            scanf("%d",&d);

            if(d==1)
                goto L;
            else
                break;
        }

        i++;
        j%=5;
    }
    return 0;
}
