#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <unistd.h>
#include <windows.h>
#include <string.h>

 using namespace std;

typedef struct proceso
{
int numero;
string nombre;
string estado;
}estado;

int operacion(int number,int cont, int aleatorio, estado listos[],estado terminados[]);
void inicializa();
 estado listos[5],terminados[20];

int contListos=0, contTerm=0;
void inicializa()
{
    int i;
     for(i=0;i<5;i++)
     {
        listos[i].numero=0;
        listos[i].nombre="NULL";
        listos[i].estado="NULL";
     }
     for(i=0;i<20;i++)
     {
        terminados[i].numero=0;
        terminados[i].nombre="NULL";
        terminados[i].estado="NULL";
     }
}
 main()
{
    int num,number,i,aleatorio;
    char c;
       srand(time(NULL));
       inicializa();
    cout<<"\t\t\tIngrese el Numero de Procesos:     ";fflush(stdin);
    cin>>num;
            cout<<"\nTIEMPO :  SEG\tNumero: \tNombre del Proceso: \tOperacion\tResultado:";
            for(i=1;i<=num;i++)
            {
                number=1+rand()%4;
                aleatorio=1000+rand()%5000;
                c=operacion(number,i,aleatorio,listos,terminados);
                if(c=='s' || c=='S')
                break;
            }


    system("cls");
    cout<<"\n\n\t\t\t REPORTE DE PROCESOS...";
    cout<<"\n\n Procesos Listos";
    for(i=0;i<5;i++)
    { if( listos[i].numero>0)
      cout<<"\n\n"<<listos[i].numero<<"\t"<<listos[i].nombre<<"\t"<<listos[i].estado;
    }

    cout<<"\n\n Procesos Terminados";
    for(i=0;i<20;i++)
    {if( terminados[i].numero>0)
      cout<<"\n\n"<<terminados[i].numero<<"\t"<<terminados[i].nombre<<"\t"<<terminados[i].estado;
    }
getch();
}

int operacion(int number,int cont,int aleatorio,estado listos[],estado terminados[])
{
    int oper;
int num,num2,ti;
char c=0;
string nom;
    ti=aleatorio/1000;
    switch(number)
    {
        case 1:
            num=1+rand()%100;
            num2=1+rand()%100;
            oper=num+num2;
            nom="SUMA";
            cout<<"\n\t"<<ti<<"\t\t"<<cont<<"\tSUMA"<<"\t\t\t"<<num<<"+"<<num2<<"\t\t"<<oper;
            Sleep(aleatorio);

            break;
        case 2:
            num=1+rand()%100;
            num2=1+rand()%100;
            oper=num-num2;
            nom="RESTA";
            cout<<"\n\t"<<ti<<"\t\t"<<cont<<"\tRESTA"<<"\t\t\t"<<num<<"-"<<num2<<"\t\t"<<oper;
            Sleep(aleatorio);

            break;
        case 3:
            num=1+rand()%100;
            num2=1+rand()%100;
            oper=num*num2;
            nom="MULTI";
            cout<<"\n\t"<<ti<<"\t\t"<<cont<<"\tMULTI"<<"\t\t\t"<<num<<"*"<<num2<<"\t\t"<<oper;
            Sleep(aleatorio);
            break;
        case 4:
            num=1+rand()%100;
            num2=1+rand()%100;
            oper=num/num2;
            nom="DIV";
            cout<<"\n\t"<<ti<<"\t\t"<<cont<<"\tDIV"<<"\t\t\t"<<num<<"/"<<num2<<"\t\t"<<oper;
            Sleep(aleatorio);
            break;

    }
    if(kbhit() )
        c=getch();
    if(contListos <5 && c!='e')
    {
        listos[contListos].numero=cont;
        listos[contListos].nombre=nom;
        listos[contListos].estado="OK";
        contListos++;
    }
        else if(c=='e' || contListos>=5)
        {
            terminados[contTerm].numero=cont;
            terminados[contTerm].nombre=nom;
            if(c=='e')
                terminados[contTerm].estado="ERROR";
                else
                terminados[contTerm].estado="OK";
            contTerm++;
        }

        return c;
}

