#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <conio.h>

using namespace std;

int main()
{
    int a[9]={12,17,10,31,9,11,31,21,13} ,b[9]={0,0,0,0,0,0,0,0,0};
    int i,c=0,d=1,tiempo,e=0,j;
do{
   do{
    for(i=0;i<9;i++)
    {
     cout <<a[i]-e<<endl;
     b[i];
     if(a[i]==0||a[i]<0)
     {
         a[i]=b[i];
         cout <<b[i];
         cout <<"proceso(s) terminado(s)"<<endl;
     }
    }cout <<""<<endl;
    tiempo=1;
    Sleep(tiempo*1000);
    system("cls");

    e=e+6;//quantum of solam
    i=0;


  }while(!kbhit());//este ciclo controla los casos...
         getch();

   switch(getch())
   {

         case 'a': case 'A':
         a[0]+e;
         break;
    }//switch
}while(c<d);
 return 0;
}
