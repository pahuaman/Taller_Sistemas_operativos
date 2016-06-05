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
   void metodo();
};//fin de clase

void Proceso::metodo()
{
  int i,a=1,x;

  for(i=0;i<a;i++)
  {
      cout<<"\t  ";
  }

}//metodo de nuestra clase

int main ()
{
    //nuestras colas...
    vector<Proceso*> listos;
    vector<Proceso*> bloqueados;

    //variables de referencia (procesos)
    Proceso x,y,z;

    int i,j=0,k,l=0,m,n,o,q,a=1,c=0,r,s,p=0;
    int tiempo,hora=time(NULL);
    r=1; //variable que va a controlara los ifs
    q=0;//contara todos los procesos realizados...
    k=0;//contara procesos terminados
    n=0;//contara los procesos interrumpidos
    o=0;//contara los procesos bloqueados

do{
   do{
   //bloque de proceso
   if(r==1)
    {
    //aqui insertamos el proceso a nuestra cola
    listos.push_back(&x);
    x.metodo();
    s=1;
    for(i=0;i<5;i++)
    {
    tiempo=1;
    Sleep(tiempo*1000);
    j++;
    system("cls");
    cout << "PROCESO #  "<< q+1 << " EN EJECUCION:  10 SEG. DE TIEMPO ESTIMADO:      " << j <<endl;
    cout <<""<<endl;
    cout << "PROCESO #  "<< q+2 << " EN ESPERA:      " <<endl;
    cout << "PROCESO #  "<< q+3 << " EN ESPERA:      " <<endl;
    cout << "PROCESO #  "<< q+4 << " EN ESPERA:      " <<endl;
    cout << "PROCESO #  "<< q+5 << " EN ESPERA:      " <<endl;
    if(j==10)
    {
        q++;
        cout << "\tPROCESO  " << q << "  TERMINADO EXITOSAMENTE!  "<<endl;
        r=2;
        k++;
        l=0;
     }//if
    } //for
  } //else if

    //bloque de proceso
    else if(r==2)
    {
    //qui insertamos el proceso a nuestra cola...
    listos.push_back(&y);
    y.metodo();
    s=2;
    for(i=0;i<5;i++)
    {
    tiempo=1;
    Sleep(tiempo*1000);
    l++;
    system("cls");
    cout << "PROCESO #  "<< q+1 << " EN EJECUCION:  10 SEG. DE TIEMPO ESTIMADO:      " << l <<endl;
    cout <<""<<endl;
    cout << "PROCESO #  "<< q+2 << " EN ESPERA:      " <<endl;
    cout << "PROCESO #  "<< q+3 << " EN ESPERA:      " <<endl;
    cout << "PROCESO #  "<< q+4 << " EN ESPERA:      " <<endl;
    cout << "PROCESO #  "<< q+5 << " EN ESPERA:      " <<endl;
    if(l==10)
    {
        q++;
        cout << "\tPROCESO  " << q << "  TERMINADO EXITOSAMENTE!  "<<endl;
        r=3;
        m=0;
        k++;
     }//if
    } //for
 }//else if

   //bloque de proceso
   else if(r==3)
   {
    listos.push_back(&z);
    z.metodo();
    s=3;
    for(i=0;i<5;i++)
    {
    tiempo=1;
    Sleep(tiempo*1000);
    m++;
    system("cls");
    cout << "PROCESO #  "<< q+1 << " EN EJECUCION:  10 SEG. DE TIEMPO ESTIMADO:      " << m <<endl;
    cout <<""<<endl;
    cout << "PROCESO #  "<< q+2 << " EN ESPERA:      " <<endl;
    cout << "PROCESO #  "<< q+3 << " EN ESPERA:      " <<endl;
    cout << "PROCESO #  "<< q+4 << " EN ESPERA:      " <<endl;
    cout << "PROCESO #  "<< q+5 << " EN ESPERA:      " <<endl;
    if(m==10)
    {
        q++;
        cout << "\tPROCESO  " << q << "  TERMINADO EXITOSAMENTE!  "<<endl;
        r=1;
        j=0;
        k++;
     }//if
    } //for
   }//else if
}while(!kbhit()); //este ciclo controla los casos...
        getch();

switch(getch())
{
    case 'e': case 'E':
      cout <<""<<endl;
      cout <<""<<endl;
      cout << "----------------------------------ERROR EN ESTE PROCESO! "<< endl;
      cout << "EL SIGUIENTE PROCESO ESTA POR COMENZAR ESPERE: "<< endl;
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

    case 'z': case 'Z':
      c=0;
      a=1;
      j=0;
      l=0;
      o++;

      if(s==1)
      {
      bloqueados.push_back(&y);
      cout << "----------------------------------EL PROCESO SE BLOQUEO "<< endl;
      cout << "PROCESO #  "<< q+1 << " BLOQUEADO ESPERE:  :      " <<endl;
      tiempo=rand()%8;
      Sleep(tiempo*1000);
      cout << "PROCESO DESBLOQUEDO : " << tiempo <<"SEG. DE RETARDO "<< endl;
      k++;
      r++;
      if(r==4){r=1;}
      }//if

      else if(s==2)
      {
      bloqueados.push_back(&y);
      cout << "----------------------------------EL PROCESO SE BLOQUEO "<< endl;
      cout << "PROCESO #  "<< q+1 << " BLOQUEADO ESPERE:  :      " <<endl;
      tiempo=rand()%8;
      Sleep(tiempo*1000);
      cout << "PROCESO DESBLOQUEDO : " << tiempo <<"SEG. DE RETARDO "<< endl;
      k++;
      r++;
      if(r==4){r=1;}
      }//else if

      else if(s==3)
      {
      bloqueados.push_back(&z);
      cout << "----------------------------------EL PROCESO SE BLOQUEO "<< endl;
      cout << "PROCESO #  "<< q+1 << " BLOQUEADO ESPERE:  :      " <<endl;
      tiempo=rand()%8;
      Sleep(tiempo*1000);
      cout << "PROCESO DESBLOQUEDO: " << tiempo <<"SEG. DE RETARDO "<< endl;
      k++;
      r++;
      if(r==4){r=1;}
      }//else if
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
        cout<<"\t  ";cout<<"\t  "; cout << "PROCESOS QUE SE BLOQUEARON  : "<< o << endl;
        cout <<""<<endl;
        cout<<"\t  ";cout<<"\t  ";cout << "PROCESOS QUE NO SE EJECUTARON : 4 " << endl;
        cout <<""<<endl;
    break;


}//switch

}while(c<a);//do while principal

return 0;

}//main
