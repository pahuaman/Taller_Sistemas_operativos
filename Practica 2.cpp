#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <windows.h>//para sleep y strcpy
#include <math.h>
#include <iomanip>
#include <conio.h>
#include <stdio.h>

using namespace std;

struct lista{
    int op1, op2, res, tiempo, lote;
    bool ejecutado=false;
    char dulce[10];
    struct lista *sig;
};
typedef struct lista PROCESOS;
PROCESOS *nuevoNodo, *anteriorNodo, *inicialNodo;
int cont_proc=0;

void proceso(int i, int tiemp, int *lote){
    int op1, op2, res, tiempo;
    char dulce[10];
    op1=1;
    op2=0;

    nuevoNodo=(PROCESOS *)malloc(sizeof(PROCESOS));
        res=op1+op2;
        if(tiemp%2==0){
            //cout<<"\t\n\nBolsa de paletas"<<endl;
            strcpy(dulce,"paletas");
        }
        else{
            //cout<<"\t\n\nBolsa de gomitas"<<endl;
            strcpy(dulce,"gomitas");
        }
        //Sleep(tiemp*1000);
        //cout<<"\tProceso "<<i+1<<" terminado. TIEMPO: "<<tiemp<<" s."<<endl;
        op1++;
        op2=i+1;
        if((i+1)%4==0){
                //cout<<"\t\n\n--------------->LOTE: "<<lote;
                *lote=*lote+1;
        }
        tiempo=tiemp;
        nuevoNodo->res=res;
        nuevoNodo->op1=op1;
        nuevoNodo->op2=op2;
        nuevoNodo->tiempo=tiempo;
        strcpy(nuevoNodo->dulce,dulce);
        nuevoNodo->lote=*lote;
        nuevoNodo->sig=NULL;
        cont_proc++;
       if (inicialNodo == NULL) {
           inicialNodo=nuevoNodo;
           anteriorNodo=nuevoNodo;
       }
       else {
           anteriorNodo->sig=nuevoNodo;
           anteriorNodo=nuevoNodo;
       }
}
void mostrarProceso(){
    char c;
    nuevoNodo=inicialNodo;
    while(nuevoNodo != NULL) {
        //if(c!='e'){
            cout<<"\t\n\nEjecutando proceso... \"Bolsa de: "<<nuevoNodo->dulce<<"\""<<endl;
            cout<<"\t(Presione 'S' para salir o 'E' para terminar proceso)"<<endl;
            Sleep(nuevoNodo->tiempo*1000);
            if(kbhit()){
                c=getch();
                if(c=='s'){
                    cout<<"\n\n\tTodos los procesos terminados por el usario (tecla 'S') "<<endl;
                    break;
                }

            }
            if(c!='e'){
                nuevoNodo->ejecutado=true;
                cout<<"Proceso "<<nuevoNodo->op2<<" terminado. TIEMPO: "<<nuevoNodo->tiempo<<" s."<<endl;
                cout<<"\t\n\n--------------->LOTE: "<<nuevoNodo->lote;
                nuevoNodo=nuevoNodo->sig;
                cout<<"\n";
                }else{
                nuevoNodo=nuevoNodo->sig;
                cout<<"\n\n\tERROR!! Proceso terminado por el usario (tecla 'E') "<<endl;
                c='x';
            }

        /*}else{
            nuevoNodo=nuevoNodo->sig;
            cout<<"\n\n\tProceso terminado por el usario (tecla 'E') "<<endl;
            c='x';
        }*/

    }
}
int main()
{

    char c;
    int x, i, tiemp, lote=1;
    int hora = time(NULL);
    srand (hora);
    //cout<<"Inserte cantidad de procesos: ";
    //cin>>x;
    cout<<"¿Iniciar? s/n: ";
    cin>>c;
    if(c=='s'||c=='S')
    {
        x=1+rand()%20;
        //x=20;
        for( i=0; i<x; i++)
        {
            tiemp=(rand()%6)+2;
            proceso(i, tiemp, &lote);

        }
        mostrarProceso();
    }
    int j=0;
    i=0;
    cout<<setw(15)<<"#Proceso:";
    cout<<setw(15)<<"Duracion:";
    cout<<setw(15)<<"Estado:";
    cout<<endl;
    nuevoNodo=inicialNodo;
    for(i=0; i<cont_proc; i++){
        for(j=0; j<3; j++){
            switch(j){
                case 0:
                    cout<<setw(15)<<nuevoNodo->op2;
                    break;
                case 1:
                    cout<<setw(15)<<nuevoNodo->tiempo<<"s.";
                    break;
                case 2:
                    if(nuevoNodo->ejecutado==true)
                        cout<<setw(15)<<"Ejecutado";
                    else
                       cout<<setw(15)<<"No ejecutado";
                    break;
            }
        }
        nuevoNodo=nuevoNodo->sig;
        cout<<endl;
    }
    system("Pause");
    return 0;
}
