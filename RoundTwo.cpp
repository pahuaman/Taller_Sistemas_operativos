#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <conio.h>

using namespace std;

int main()
{
    int a1=12,a2=17,a3=10,a4=31,a5=9,a6=11,a7=31,a8=21,a9=13;
    int i,j,a=1,e=0,tiempo,c=0,d=1,f1,f2,f3,f4,f5,f6,f7,f8,f9;
    int b1=0,b2=0,b3=0,b4=0,b5=0,b6=0,b7=0,b8=0,b9=0;
    int x[9],z1=1,z2=2,z3=3,z4=4,z5=5,z6=6,z7=7,z8=8,z9=9,z=0;
do{
    for(i=0;i<a;i++)
    {
      if(b1==0)
      {
      cout << a1-e <<endl;
      f1=a1-e;
      }
      if(f1==0||f1<0)
      {

         x[z]=z1;
         z++;
         b1=1;
         f1=0;
         cout << "PROCESO # 1 terminado 0 "<<endl;
      }

      if(b2==0){
      cout << a2-e <<endl;
      f2=a2-e;
      }
      if(f2==0||f2<0)
      {

         x[z]=z2;
         z++;
         b2=1;
         f2=0;
         cout << "PROCESO # 2 terminado 0 "<<endl;
      }
      if(b3==0){
      cout << a3-e <<endl;
      f3=a1-e;
      }
      if(f3==0||f3<0)
      {

         x[z]=z3;
         z++;
         b3=1;
         f3=0;
         cout << "PROCESO # 3 terminado 0 "<<endl;
      }
      if(b4==0){
      cout << a4-e <<endl;
      f4=a4-e;
      }
      if(f4==0||f4<0)
      {

         x[z]=z4;
         z++;
         f4=1;
         a4=0;
         cout << "PROCESO # 4 terminado 0 "<<endl;
      }
      if(b5==0){
      cout << a5-e <<endl;
      f5=a5-e;
      }
      if(f5==0||f5<0)
      {

         x[z]=z5;
         z++;
         b5=1;
         f5=0;
         cout << "PROCESO # 5 terminado 0 "<<endl;
      }
      if(b6==0){
      cout << a6-e <<endl;
      f6=a6-e;
      }
      if(f6==0||f6<0)
      {

         x[z]=z6;
         z++;
         b6=1;
         f6=0;
         cout << "PROCESO # 6 terminado 0 "<<endl;
      }
      if(b7==0){
      cout << a7-e <<endl;
      f7=a7-e;
      }
      if(f7==0||f7<0)
      {

         x[z]=z7;
         z++;
         b7=1;
         f7=0;
         cout << "PROCESO # 7 terminado 0 "<<endl;
      }
      if(b8==0){
      cout << a8-e <<endl;
      f8=a8-e;
      }
      if(f8==0||f8<0)
      {


         x[z]=z8;
         z++;
         b8=1;
         f8=0;
         cout << "PROCESO # 8 terminado 0 "<<endl;
      }
      if(b9==0){
      cout << a9-e <<endl;
      f9=a9-e;
      }
      if(f9==0||f9<0)
      {

         x[z]=z9;
         z++;
         b9=1;
         f9=0;
         cout << "PROCESO # 9 terminado 0 "<<endl;
      }
      tiempo=1;
      Sleep(tiempo*1000);
      system("cls");
      i=0;
      e=e+6;
    }//for principal
   for(j=0;j<9;j++){  cout << x[j] <<endl; }
}while(c<d);
  return 0;
}
