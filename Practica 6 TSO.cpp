
/*
HUMBERTO SEBASTIAN MUÑOZ ALONSO
206696783
Práctica 5
Taller de Sistemas Operativos*/

#include <stdio.h>
#include<conio.h>
#include <windows.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include<fstream>
#include<iostream>

using namespace std;

struct barberos{
  int estado;
  int nocliente;
  int TT;
};

struct cliente{
       int codigo;
       int atendido;
       int TME;
       struct cliente *sig;
};

struct sespera{
       int estado;
       int nocliente;
       int TT;
};

typedef struct barberos bar;
typedef struct cliente clt;
typedef struct sespera esp;

int main(){
    int p;//procesos
    int total=0;//tiempo global
    int i,j,h,k,m;
    int pps=0;//tecla s
    int ca=0;//clientes atendidos
    int ce=0;//clientes en espera
    int cna=0;//clientes no atendidos
    int cc=0;//clientes cancelados
    int tb1;
    int tb2;
    int tb3;
    int pn;
    int horario=0;
    char x;
    bar b1,b2,b3;
    clt *nodoinicial, *nodoanterior, *l,*nodonuevo, *aux,*actual;
    esp e1,e2,e3,e4,e5,e6;
   	nodoinicial=NULL;
   	b1.estado=0;
   	b1.TT=0;
   	b2.estado=0;
   	b2.TT=0;
   	b3.estado=0;
   	b3.TT=0;
   	e1.estado=0,e2.estado=0,e3.estado=0,e4.estado=0,e5.estado=0,e6.estado=0;
   	p=(rand()%9)+1;

/*************************captura**********************************************/

   	for(i=0;i<p;i++){
        l=(clt*)malloc(sizeof(clt));
        l->codigo=i+1;
   		l->TME=(rand()%9)+2;
        l->atendido=0;
        l->sig=NULL;
        if (nodoinicial == NULL) {
            nodoinicial=l;
            nodoanterior=l;
        }
        else {
            nodoanterior->sig=l;
            nodoanterior=l;
        }
        l=l->sig;
   	}

   	l=nodoinicial;
   	while(l!=NULL){
          if(b1.estado==0){
             b1.estado=1;
             b1.TT=l->TME;
             b1.nocliente=l->codigo;
             tb1=l->TME;
             nodoinicial=l->sig;
             free(l);
          }
          else if(b2.estado==0){
                  b2.estado=1;
                  b2.TT=l->TME;
                  b2.nocliente=l->codigo;
                  tb2=l->TME;
                  nodoinicial=l->sig;
             free(l);
          }
          else if(b3.estado==0){
                  b3.estado=1;
                  b3.TT=l->TME;
                  b3.nocliente=l->codigo;
                  tb3=l->TME;
                  nodoinicial=l->sig;
             free(l);
          }
          else if(e1.estado==0){
               e1.estado=1;
               e1.nocliente=l->codigo;
               e1.TT=l->TME;
               nodoinicial=l->sig;
             free(l);
             ce++;
          }
          else if(e2.estado==0){
               e2.estado=1;
               e2.nocliente=l->codigo;
               e2.TT=l->TME;
               nodoinicial=l->sig;
             free(l);
             ce++;
          }
          else if(e3.estado==0){
               e3.estado=1;
               e3.nocliente=l->codigo;
               e3.TT=l->TME;
               nodoinicial=l->sig;
             free(l);
             ce++;
          }
          else if(e4.estado==0){
               e4.estado=1;
               e4.nocliente=l->codigo;
               e4.TT=l->TME;
               nodoinicial=l->sig;
             free(l);
             ce++;
          }
          else if(e5.estado==0){
               e5.estado=1;
               e5.nocliente=l->codigo;
               e5.TT=l->TME;
               nodoinicial=l->sig;
             free(l);
             ce++;
          }
          else{
               cna++;
               nodoinicial=l->sig;
             free(l);
          }

          l=l->sig;
    }



/****************************muestra*******************************************/
//nodoinicial=NULL;
    l=nodoinicial;
    for(i=1;i>-1;i++){//controla los procesos que se muestran
        system("cls");
        system("color f3");
         printf("\n\n\t\t-----------------PRACTICA No.6 TSO------------------");
        printf("\n\n\t\t----------HUMBERTO SEBASTIAN MUNOZ ALONSO-----------");
        printf("\n\t\t__________________________________________________");
        printf("\n\t\t| Bienvenido a la Barberia con horario Infinito   |");
        printf("\n\t\t|_________________________________________________|\n\t\t");
        printf("Solo cerramos cuando tu lo deseas y precionas la tecla 'S'\n");
        printf("\n\t\t\t Tiempo De Servicio: %i\n\n\n",total);
        if(b1.estado==0)
           printf("Barbero 1 esta dormido\n");
        else if(tb1>=0)
                printf("Barbero 1 atiende a cliente %i durante %i segundos\n\n",b1.nocliente,b1.TT);
        if(b2.estado==0)
           printf("Barbero 2 esta dormido\n");
        else if(tb2>=0)
                printf("Barbero 2 atiende a cliente %i durante %i segundos\n\n",b2.nocliente,b2.TT);
        if(b3.estado==0)
           printf("Barbero 3 esta dormido\n");
        else if(tb3>=0)
                printf("Barbero 3 atiende a cliente %i durante %i segundos\n\n",b3.nocliente,b3.TT);
        printf("\nSALA DE ESPERA\n\n");
        if(e1.estado==0)
           printf("Silla 1 vacia\n");
        else //if(tb1>=0)
                printf("Silla 1 cliente %i \n",e1.nocliente);
        if(e2.estado==0)
           printf("Silla 2 vacia\n");
        else if(tb1>=0)
                printf("Silla 2 cliente %i \n",e2.nocliente);
        if(e3.estado==0)
           printf("Silla 3 vacia\n");
        else if(tb1>=0)
                printf("Silla 3 cliente %i \n",e3.nocliente);
        if(e4.estado==0)
           printf("Silla 4 vacia\n");
        else //if(tb1>=0)
                printf("Silla 4 cliente %i \n",e4.nocliente);
        if(e5.estado==0)
           printf("Silla 5 vacia\n");
        else if(tb1>=0)
                printf("Silla 5 cliente %i \n",e5.nocliente);
        Sleep(970);
        total++;
        tb1--;
        tb2--;
        tb3--;
        if(tb1==0){
           b1.estado=0;
           ca++;
           }
        if(tb2==0){
           b2.estado=0;
           ca++;
           }
        if(tb3==0){
           b3.estado=0;
           ca++;
           }
        if(i!=0 && i%10==0){//crea clientes nuevos cada 10 seg
           pn=(rand()%9)+1;
       //    nodoinicial=NULL;
   	       for(j=0;j<pn;j++){
               l=(clt*)malloc(sizeof(clt));
               l->codigo=p+1;
   		       l->TME=(rand()%9)+2;
               l->atendido=0;
               l->sig=NULL;
               if(nodoinicial == NULL) {
                  nodoinicial=l;
                  nodoanterior=l;
               }
               else {
                    nodoanterior->sig=l;
                    nodoanterior=l;
               }
               l=l->sig;
               p++;
           }
        }
        if(b1.estado==0 ){//checa si los barberos están disponibles
       	   if(e1.estado==1){
       	      b1.estado=1;
       	      b1.TT=e1.TT;
                  b1.nocliente=e1.nocliente;
                  tb1=e1.TT;
                  e1=e2;
                  e2=e3;
                  e3=e4;
                  e4=e5;
                  e5=e6;
              }

        }

        if( b2.estado==0 ){//checa si los barberos están disponibles
              	   if(e1.estado==1){
       	      b2.estado=1;
       	      b2.TT=e1.TT;
                  b2.nocliente=e1.nocliente;
                  tb2=e1.TT;
                  e1=e2;
                  e2=e3;
                  e3=e4;
                  e4=e5;
                  e5=e6;
              }

        }

        if(b3.estado==0){//checa si los barberos están disponibles

       	   if(e1.estado==1){
       	      b3.estado=1;
       	      b3.TT=e1.TT;
                  b3.nocliente=e1.nocliente;
                  tb3=e1.TT;
                  e1=e2;
                  e2=e3;
                  e3=e4;
                  e4=e5;
                  e5=e6;
              }

        }
        l=nodoinicial;
   	while(l!=NULL){
          if(b1.estado==0){
             b1.estado=1;
             b1.TT=l->TME;
             b1.nocliente=l->codigo;
             tb1=l->TME;
             nodoinicial=l->sig;
             free(l);
          }
          else if(b2.estado==0){
                  b2.estado=1;
                  b2.TT=l->TME;
                  b2.nocliente=l->codigo;
                  tb2=l->TME;
                  nodoinicial=l->sig;
             free(l);
          }
          else if(b3.estado==0){
                  b3.estado=1;
                  b3.TT=l->TME;
                  b3.nocliente=l->codigo;
                  tb3=l->TME;
                  nodoinicial=l->sig;
             free(l);
          }
          else if(e1.estado==0){
               e1.estado=1;
               e1.nocliente=l->codigo;
               e1.TT=l->TME;
               nodoinicial=l->sig;
             free(l);
             ce++;
          }
          else if(e2.estado==0){
               e2.estado=1;
               e2.nocliente=l->codigo;
               e2.TT=l->TME;
               nodoinicial=l->sig;
             free(l);
             ce++;
          }
          else if(e3.estado==0){
               e3.estado=1;
               e3.nocliente=l->codigo;
               e3.TT=l->TME;
               nodoinicial=l->sig;
             free(l);
             ce++;
          }
          else if(e4.estado==0){
               e4.estado=1;
               e4.nocliente=l->codigo;
               e4.TT=l->TME;
               nodoinicial=l->sig;
             free(l);
             ce++;
          }
          else if(e5.estado==0){
               e5.estado=1;
               e5.nocliente=l->codigo;
               e5.TT=l->TME;
               nodoinicial=l->sig;
             free(l);
             ce++;
          }
          else{
               cna++;
               nodoinicial=l->sig;
             free(l);
          }

          l=l->sig;
    }
/************************teclas************************************************/

        if(kbhit()){
           x=getch();
           switch(x){
                     case 'p': case'P':
                                printf("\nPaused...");
                                while(x!='c'||x!='C'){
                                      if(kbhit()){
                                         x=getch();
                                         if(x=='c'||x=='C')
                                            break;
                                      }
                               }
                               break;
                     case 's':case 'S':
                                printf("\nTerminado por el usuario\n");
                                pps=1;
                                if(b1.estado==1)
                                   cc++;
                                   if(b2.estado==1)
                                   cc++;
                                   if(b3.estado==1)
                                   cc++;
                                   if(e1.estado==1)
                                   cc++;
                                   if(e2.estado==1)
                                   cc++;
                                   if(e3.estado==1)
                                   cc++;
                                   if(e4.estado==1)
                                   cc++;
                                   if(e5.estado==1)
                                   cc++;
                                break;
           }
        }//if kkbhit

/**********************************fin teclas**********************************/

        if(pps==1)
           break;

   }
                                   if(b1.estado==1)
                                   cc++;
                                   if(b2.estado==1)
                                   cc++;
                                   if(b3.estado==1)
                                   cc++;
                                   if(e1.estado==1)
                                   cc++;
                                   if(e2.estado==1)
                                   cc++;
                                   if(e3.estado==1)
                                   cc++;
                                   if(e4.estado==1)
                                   cc++;
                                   if(e5.estado==1)
                                   cc++;
/*******************************fin muestra************************************/
        system("cls");

        printf("\n\n\n\t\t__________________________________________________");
        printf("\n\t\t|           LO SENTIMOS YA CERRAMOS.              |");
        printf("\n\t\t|_________________________________________________|\n\t\t");



printf("\nClientes Atendidos %i\n\n",ca);
//printf("Clientes en Espera %i\n\n",ce);
printf("Clientes no Antendidos %i\n\n",cna);
printf("Clientes Cancelados %i\n\n",cc);

   printf("\n\n");
   //system("PAUSE");
   return 0;
}
