#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <unistd.h>
#include <windows.h>

 using namespace std;


void operacion(int number,int cont);

 main()
{
    int num,number,i;


   srand(time(NULL));
    cout<<"\t\t\tIngrese el Numero de Procesos:     ";fflush(stdin);
    cin>>num;
    if(num<10)
        cout<<"\n\nEL numero de procesos debe ser mayor a 10 y en multiplos del mismo";
    else
    {
    cout<<"\nTIEMPO : 1 SEG\tNumero: \tNombre del Proceso: \tOperacion\tResultado:";
        for(i=1;i<=num;i++)
        {
            number=1+rand()%4;
            operacion(number,i);
            Sleep(1000);
            if(i>1 && i%10==0)
                cout<<"\n\nLote Numero: "<<i/10<<"\t finalizado...";
        }
    }

}

void operacion(int number,int cont)
{ int oper;
int num,num2;
    switch(number)
    {
        case 1:
            num=1+rand()%100;
            num2=1+rand()%100;
            oper=num+num2;
            cout<<"\n\t\t\t"<<cont<<"\tSUMA"<<"\t\t\t"<<num<<"+"<<num2<<"\t\t"<<oper;
            break;
        case 2:
            num=1+rand()%100;
            num2=1+rand()%100;
            oper=num-num2;
            cout<<"\n\t\t\t"<<cont<<"\tRESTA"<<"\t\t\t"<<num<<"-"<<num2<<"\t\t"<<oper;
            break;
        case 3:
            num=1+rand()%100;
            num2=1+rand()%100;
            oper=num*num2;
            cout<<"\n\t\t\t"<<cont<<"\tMULTI"<<"\t\t\t"<<num<<"*"<<num2<<"\t\t"<<oper;
            break;
        case 4:
            num=1+rand()%100;
            num2=1+rand()%100;
            oper=num/num2;
            cout<<"\n\t\t\t"<<cont<<"\tDIV"<<"\t\t\t"<<num<<"/"<<num2<<"\t\t"<<oper;
            break;

    }

}
