#include<iostream>
#include<windows.h>
#include<dos.h>
#include<conio.h>
#include<stdlib.h>
using namespace std;
const int w=20;
const int h=20;
int x,y,fruitx,fruity,score=0,i,j;
int gameover=0;
char input;
int taill=1;
int tailX[100],tailY[100];
int userchoice;
void Setup()
{
    x=w/2;
    y=h/2;
    fruitx=rand()%w;
    fruity=rand()%h;
}
void Draw()
{
    if(score<50)
        Sleep(150);
    else if(score<100)
        Sleep(130);
    else if(score<150)
        Sleep(100);
    else if(score<250)
        Sleep(80);
    else
        Sleep(60);
    system("cls");
    for(i=0;i<w+2;i++)
        cout<<"#";
    cout<<endl;
    for(i=0;i<w;i++)
    {
        for(j=0;j<h;j++)
        {
            int checker=0;
            if(j==0)
                cout<<"#";
            if(i==y&&j==x)
            {
                cout<<"0";
                checker++;
            }
            else if(i==fruity&&j==fruitx)
            {
                cout<<"@";
                checker++;
            }
            else
            {
                for(int k=0;k<taill;k++)
                {
                    if(tailX[k]==j&&tailY[k]==i)
                    {
                        cout<<"o";
                        checker++;
                    }
                }
            }
        if(checker==0)
            cout<<" ";
        if(j==h-1)
            cout<<"#";
        }
    cout<<endl;
    }
    for(i=0;i<w+2;i++)
        cout<<"#";
    cout<<endl;
    cout<<"Your Score="<<score;
}
void Input()
{
    if(kbhit())
    {
    input=getch();
    }
    switch(input)
    {
        case 'w':
            y--;
            break;
        case 'a':
            x--;
            break;
        case 'd':
            x++;
            break;
        case 's':
            y++;
            break;
        case 'x':
            gameover=1;
            break;
    }
}
void Logic()
{
    int prevx=tailX[0];
    int prevy=tailY[0];
    tailX[0]=x;
    tailY[0]=y;
    int tx,ty;
    for(i=1;i<taill;i++)
    {
        tx=tailX[i];
        ty=tailY[i];
        tailX[i]=prevx;
        tailY[i]=prevy;
        prevx=tx;
        prevy=ty;
    }
    if((x<0||x>=w||y<0||y>=h)&&userchoice!=1)
    gameover=1;
    if(x<=0)
        x=x+w;
    if(x>=w)
        x=x-w;
    if(y<=0)
        y=y+h;
    if(y>=h)
        y=y-h;
    for(i=2;i<taill;i++)
        if(tailX[i]==x && tailY[i]==y)
            gameover=1;
    if(x==fruitx&&y==fruity)
    {
       score=score+10;
       fruitx=rand()%w;
       fruity=rand()%h;
       taill++;
    }
    if(fruitx>19||fruity>19)
    {
        fruitx=10;
        fruity=5;
    }
}
int main()
{
    system("cls");
    cout<<"WELCOME TO THE SNAKE GAME"<<endl;
    cout<<"Type 1 IF YOU WANT TO RUN THROUGH WALLS 2 IF YOU DONT"<<endl;
    cin>>userchoice;
    cout<<"W=MOVE UP"<<endl;
    cout<<"A=MOVE LEFT"<<endl;
    cout<<"S=MOVE DOWN"<<endl;
    cout<<"D=MOVE RIGHT"<<endl;
    cout<<"YOUR GAME WILL BEGIN IN   ";
    for(i=1;i<=3;i++)
    {
        cout<<i<<"...";
        Sleep(800);
    }
    system("cls");
    Setup();
    while(gameover==0)
    {
        Draw();
        Input();
        Logic();
        cout<<endl;
        cout<<"/***SIMPLE SNAKE GAME USING BASIC C++***/"<<endl;
    }
    cout<<"GAME OVER";
    Sleep(2000);
    getch();
}
