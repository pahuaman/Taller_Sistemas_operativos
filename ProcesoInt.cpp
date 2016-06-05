#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <vector>
#include <conio.h>

using namespace std;

class Proceso
{
public: //metodo publico
   void dulces();
};//fin de clase

void Proceso::dulces()
{
  int i,a=1,x;

  for(i=0;i<a;i++)
  {
      cout<<"\t  ";cout<<"DULCES  "; cout<<"DULCES  ";
  }
}//metodo de nuestra clase


int main()
{
    //cola o lista, vector
    vector<Proceso*> pro;
    Proceso p,x,z;

    int i,j,k,l,m,n,o,q,a,c,tiempo,r, hora=time(NULL);
    srand(hora);
    a=1;
    r=1;
    j=0;//contador proceso 1
    l=0;//contador proceso 2
    m=0;//contador proceso 3
    k=0;//contara procesos terminados
    n=0;//contara los procesos interrumpidos
    q=0;//contara todos los procesos realizados, interrumpidos y que faltaron

do{
    do{
    //bloque del primer proceso
    if(r==1)
    {
    o=3;
    if(j==0){cout << "NUEVO PROCESO : "<< endl;}//if
    //aqui insertamos el proceso a nuestra cola
    pro.push_back(&p);

    for(c=0;c<a;c++)
    {
    p.dulces();
    tiempo=1;
    Sleep(tiempo*1000);
    cout <<""<<endl;
    j++;
    if(j==20)
    {
      cout << "PROCESO TERMINADO EXITOSAMENTE: "<< endl;
      cout <<""<<endl;
      r=2;
      q++;
      k++;
      l=0;
    }//if
  }//for
} //else if

//bloque del segundo proceso
    else if(r==2)
    {
    o=2;
    if(l==0){cout << "NUEVO PROCESO : "<< endl;}//if
    //aqui insertamos el proceso a nuestra cola
    pro.push_back(&x);

    for(c=0;c<a;c++)
    {
    x.dulces();
    tiempo=1;
    Sleep(tiempo*1000);
    cout <<""<<endl;
    l++;
    if(l==20)
    {
      cout << "PROCESO TERMINADO EXITOSAMENTE: "<< endl;
      cout <<""<<endl;
      r=3;
      k++;
      q++;
      m=0;
    }//if
  }//for
}//else if

    //bloque del tercer proceso
    else if(r==3)
    {
    o=1;
    if(m==0){cout << "NUEVO PROCESO : "<< endl;}//if
    //aqui insertamos el proceso a nuestra cola
    pro.push_back(&z);

    for(c=0;c<a;c++)
    {
    z.dulces();
    tiempo=1;
    Sleep(tiempo*1000);
    cout <<""<<endl;
    m++;
    if(m==20)
    {
      cout << "PROCESO TERMINADO EXITOSAMENTE: "<< endl;
      cout <<""<<endl;
      r=1;
      j=0;
      q++;
      k++;
    }//if
  }//for
}//else if

} while( !kbhit() );
    //variable que controla los casos
      getch();
    switch(getch())
    {
        case 'e': case 'E':
        cout << "----------------------------------ERROR EN ESTE PROCESO! "<< endl;
        cout << "EL SIGUIENTE PROCESO ESTA POR COMENZAR ESPERE: "<< endl;
        cout <<""<<endl;
        cout <<""<<endl;
        tiempo=rand()%8;
        Sleep(tiempo*1000);
        cout << "PROCESO NUEVO: " << tiempo <<"SEG. DE RETARDO "<< endl;
        c=0;
        a=1;
        j=0;
        l=0;
        m=0;
        q++;
        r++;
        n++;
        if(r==4){r=1;}
        break;

        case 't': case 'T':
        cout << "------------------SISTEMA TERMINADO: "<< endl;
        cout <<""<<endl;
        c=0;
        a=0;

       cout<<"\t  ";cout<<"\t  "; cout << "PROCESOS TERMINADOS : "<< k << endl;
       cout <<""<<endl;
       cout<<"\t  ";cout<<"\t  ";cout << "PROCESOS INTERRUMPIDOS O CON ERROR : "<< n << endl;
       cout <<""<<endl;

             if(o==1){cout<<"\t  ";cout<<"\t  ";cout << "PROCESOS QUE NO SE EJECUTARON: 1"<< endl;cout <<""<<endl;
                      cout<<"\t  ";cout<<"\t  ";cout << "TOTAL DE PROCESOS : "<< q+1 << endl;cout <<""<<endl;}
        else if(o==2){cout<<"\t  ";cout<<"\t  ";cout << "PROCESOS QUE NO SE EJECUTARON: 2"<< endl;cout <<""<<endl;
                      cout<<"\t  ";cout<<"\t  ";cout << "TOTAL DE PROCESOS : "<< q+2 << endl;cout <<""<<endl;}
        else if(o==3){cout<<"\t  ";cout<<"\t  ";cout << "PROCESOS QUE NO SE EJECUTARON: 3"<< endl;cout <<""<<endl;
                      cout<<"\t  ";cout<<"\t  ";cout << "TOTAL DE PROCESOS : "<< q+3 << endl;cout <<""<<endl;}
        break;

        default:
        cout << "CARACTER NO VALIDO :"<< endl;
        cout <<""<<endl;
        c=0;
        a=1;
        break;

    }//switch

 }while(c<a);//do while principal
}//Main
