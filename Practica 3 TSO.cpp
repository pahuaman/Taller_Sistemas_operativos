//Práctica 3 FCFS
//Taller de Sistemas Operativos

#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

struct registro{
  int posicion;
  int codigo;
  int num1;
  int num2;
  int res;
  int oper;
  int TME;
  int TT;
  int error;
  int salir;
  struct registro *sig;
};

struct ready{
       int codigo;
       int TME;
       struct ready *sig;
};

struct nw{
       int codigo;
       int TME;
       struct nw *sig;
};

struct blq{
       int codigo;
       int TME;
       struct blq *sig;
};

typedef struct registro rgt;
typedef struct ready listo;
typedef struct nw nuevo;
typedef struct blq bloqueado;

    int p;//procesos
    int total=0;//tiempo global
    int i,j,h,k,m;
    int pps=0;//tecla s
    int ppi=0;//tecla i
    int ppe=0;//tecla e
    int nuevos=0;
    int bloq=0;
    char x;
    rgt *nodoinicial, *nodoanterior, *l,*nodonuevo, *aux,*actual;
    listo *linicial,*lanterior,*r;
    nuevo *ninicial,*nanterior,*n;
    bloqueado *binicial,*banterior,*b;


void creaLista(int numproc)
{
   	for(i=0;i<p;i++){
        l=(rgt*)malloc(sizeof(rgt));
        l->posicion=i;
        l->codigo=i+1;
    	int repe;
    	l->oper=(rand()%4)+1;
    	do{
    		repe=0;
    		if(l->oper==1 || l->oper==2 || l->oper==3)
    		{
    			l->num1=(rand()%100);
    			l->num2=(rand()%100);
 		    }
    		else if(l->oper==4 || l->oper==5)
    		{
                    l->num1=(rand()%100);
    			    l->num2=(rand()%100)+1;
           }
    	}while(repe!=0);
    	if(l->oper==1)
           l->res=(l->num1+l->num2);
        else if(l->oper==2)
                l->res=(l->num1-l->num2);
        else if(l->oper==3)
                l->res=(l->num1*l->num2);
        else if(l->oper==4)
                l->res=(l->num1/l->num2);
        else if(l->oper==5)
                l->res=(l->num1%l->num2);
   		l->TME=(rand()%9)+2;
        l->TT=l->TME;
        l->error=0;
        l->salir=0;
        l->sig=NULL;
        if (nodoinicial == NULL) {
            nodoinicial=l;
            nodoanterior=l;
        }
        else {
            nodoanterior->sig=l;
            nodoanterior=l;
        }
   	}
}

int main(){
    system("color 3");

    printf("Ingresa Numero de Procesos FCFS\npara comenzar: ");
    scanf("%i",&p);
   	nodoinicial=NULL;
   	linicial=NULL;
   	ninicial=NULL;
   	binicial=NULL;

   	creaLista(p);

/***********************************************************************/



   	l=nodoinicial;
    while(l!=NULL){
          if(l->codigo<7){
             r=(listo*)malloc(sizeof(listo));
             r->codigo=l->codigo;
             r->TME=l->TME;
             r->sig=NULL;
             if (linicial == NULL) {
                 linicial=r;
                 lanterior=r;
             }
          else {
            lanterior->sig=r;
            lanterior=r;
          }
          }
          else{
               n=(nuevo*)malloc(sizeof(nuevo));
               n->codigo=l->codigo;
               n->TME=l->TME;
               n->sig=NULL;
               if (ninicial == NULL) {
                   ninicial=n;
                   nanterior=n;
               }
               else {
                    nanterior->sig=n;
                    nanterior=n;
               }
          }
          l=l->sig;
    }

/****************************************************************/

    l=nodoinicial;

/***********************************************************************/
int flag=0;
    for(i=0;i<p+bloq;i++){//controla los procesos que se muestran
            system("color 3");
        if(i==p||i>p)
           bloq--;
        aux=l;
        actual=l;
        for(j=0;j<=l->TT;j++){//controla el TME qu se muestra
            system("cls");
            ppe=0;
            ppi=0;
            r=linicial->sig;
            n=ninicial;
            b=binicial;
            printf("\n\t\t TIME: %i\n\n",total);
            printf("B   =   Bloquear\nS   =   Salir \n");
            printf("E   =   error\n\n");
            printf("\n_______________________________________________________\n");
            printf("\n\nLISTOS: \nID\tTIME\n");
            while(r!=NULL){
                  printf("%i\t%i\n",r->codigo,r->TME);
                  r=r->sig;
            }
            printf("\n\nNUEVOS: \nID\tTIME\n");
            while(n!=NULL){
                  printf("%i\t%i\n",n->codigo,n->TME);
                  n=n->sig;
            }
            printf("\nBLOQUEADOS: \nID\tTIME\n");
            while(b!=NULL){
                  printf("%i\t%i\n",b->codigo,b->TME);
                  b=b->sig;
            }
          printf("\n\t\t\t\t:::::PROCESANDO:::::\n");
          if(l->oper==1)
             printf("\t\t\tNo. %i\n\t\t\tOp %i+%i\n\t\t\tTIME: %i\n",l->codigo,l->num1,l->num2,l->TME);
          else if(l->oper==2)
                  printf("\t\t\tNo. %i\n\t\t\tOp %i-%i\n\t\t\tTIME: %i\n",l->codigo,l->num1,l->num2,l->TME);
                else if(l->oper==3)
                        printf("\t\t\tNo. %i\n\t\t\tOp %ix%i\n\t\t\tTIME: %i\n",l->codigo,l->num1,l->num2,l->TME);
                     else if(l->oper==4)
                             printf("\t\t\tNo. %i\n\t\t\tOp %i/%i\n\t\t\tTIME: %i\n",l->codigo,l->num1,l->num2,l->TME);
                          else if(l->oper==5)
                                  printf("\t\t\tNo. %i\n\t\t\tOp %imod%i\n\t\t\tTIME: %i\n",l->codigo,l->num1,l->num2,l->TME);
                               else
                                   printf("\t\t\tNo. %i\n\t\t\tOp RAIZ de %i\n\t\t\tTIME: %i\n",l->codigo,l->num1,l->TME);
          printf("\t\t\tTiempo Total: %i\n",j);
          printf("\t\t\tTiempo Restante: %i\n\n",l->TT-j);
          Sleep(1000);
          if((l->TME-j)==0)
              total=total;
          else
              total++;

/************************teclas************************************************/

          if(kbhit()){
             x=getch();
             switch(x){
                       case 'b': case'B': //captura nuevo
                       if(l->sig==NULL)
                       break;
                       else{
                                nuevos++;
                                bloq++;
                                ppi=1;

                                b=(bloqueado*)malloc(sizeof(bloqueado));//crea el nodo para mostrar en bloqueados
                                b->codigo=l->codigo;
                                b->TME=l->TME;
                                b->sig=NULL;
                                if (binicial == NULL) {
                                    binicial=b;
                                    banterior=b;
                                }
                                else {
                                     banterior->sig=b;
                                     banterior=b;
                                }

                                if(l==nodoinicial){//crea nuevo nodo con el tiempo restante y lo manda a la cola, después elimina el nodo actual
                                   nodonuevo=(rgt*)malloc(sizeof(rgt));
                                   nodonuevo->codigo=l->codigo;
                                   nodonuevo->num1=l->num1;
                                   nodonuevo->num2=l->num2;
                                   nodonuevo->res=l->res;
    	                           nodonuevo->oper=l->oper;
	                               nodonuevo->TME=l->TME;
                                   nodonuevo->TT=l->TT-j;
                                   nodonuevo->sig=NULL;
                                   nodoanterior->sig=nodonuevo;
                                   nodoanterior=nodonuevo;
                                   nodoinicial=l->sig;
                                   free(l);
                                }
                                else{
                                     nodonuevo=(rgt*)malloc(sizeof(rgt));
                                     nodonuevo->codigo=l->codigo;
                                     nodonuevo->num1=l->num1;
                                     nodonuevo->num2=l->num2;
                                     nodonuevo->res=l->res;
    	                             nodonuevo->oper=l->oper;
	                                 nodonuevo->TME=l->TME;
                                     nodonuevo->TT=l->TT-j;
                                     nodonuevo->error=l->error;
                                     nodonuevo->salir=l->salir;
                                     nodonuevo->sig=NULL;
                                     nodoanterior->sig=nodonuevo;
                                     nodoanterior=nodonuevo;
                                     l=nodoinicial;
                                     while(l!=NULL){
                                           if(l->posicion==aux->posicion-1){
                                              l->sig=aux->sig;
                                              free(aux);
                                           }
                                           l=l->sig;
                                     }
                                }
                                }
                                break;
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
                                m=i;
                                while(l!=NULL){
                                      l->salir=1;
                                      l=l->sig;
                                }
                                break;
                       case 'e':case'E':
                                ppe=1;
                                l->error=1;
                                break;

                      case 'n':case'N':
                                break;

             }
           }//if kkbhit

/**********************************fin teclas**********************************/

           if(pps==1)
              break;
           if(ppe==1)
              break;
           if(ppi==1)
              break;
        }//for j
        if(pps==1)
           break;
        else{
             l=actual;
             r=linicial;
             if(r!=NULL){
                linicial=r->sig;
                free(r);
             }
             n=ninicial;

            /****************************************************************/
           b=binicial;
           if(l->sig!=NULL){
           if(ppi==1){
              if(b!=NULL)
                 b=b;
           }
           else{
             if(b!=NULL){
              // if (n==NULL){
               r=(listo*)malloc(sizeof(listo));
               r->codigo=b->codigo;
               r->TME=b->TME;
               r->sig=NULL;
               if (linicial == NULL) {
                   linicial=r;
                   lanterior=r;
               }
               else {
                    lanterior->sig=r;
                    lanterior=r;
               }
               //}


                binicial=b->sig;
                free(b);
                flag=1;
             }
             }
             }
             if(n!=NULL && flag!=1){
     r=(listo*)malloc(sizeof(listo));
     r->codigo=n->codigo;
     r->TME=n->TME;
     r->sig=NULL;
      if (linicial == NULL) {
       linicial=r;
       lanterior=r;
       }
      else {
       lanterior->sig=r;
       lanterior=r;
       }
       ninicial=n->sig;
       free(n);
    }
    flag=0;
           /*****************************************************************/
             l=nodoinicial;
        for(h=0;h<p;h++){
            l->posicion=h;
            l=l->sig;
        }
        l=actual;
        l=l->sig;
        }
   }

/*******************************fin muestra************************************/
system("color 3");
system("cls");

printf("\n\n\t\t\t::::: RESULTADO DEL PROCESAMIENTO :::::\n");
printf("\t\t\t_______________________________________\n\n");
   l=nodoinicial;
   while(l!=NULL){
         if(l->salir==1)
            printf("\nNo.: %i  Resultado: NO EJECUTADO",l->codigo);
         else if(l->error==1)
                 printf("\nNo.: %i  Resultado: ERROR",l->codigo);
              else
                  printf("\nNo.: %i  Resultado: %i ",l->codigo,l->res);
         l=l->sig;
   }
   printf("\n\n");
   system("PAUSE");
   return 0;
}
