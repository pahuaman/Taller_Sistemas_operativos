#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

struct rgto{
  int posi, cod, no1,no2,res,oper,tmax,tt,error,salir;
  struct rgto *sig;
};

struct lto{
       int cod, tmax;
       struct lto *sig;
};

struct nvo{
      int cod, tmax;
       struct nvo *sig;
};

struct blq{
       int cod, tmax;
       struct blq *sig;
};

typedef struct rgto rgt;
typedef struct lto listo;
typedef struct nvo nuevo;
typedef struct blq bloqueado;

int main(){
    int p, total=0, i,j,h,k,m,pps=0, ppi=0, ppe=0, nuevos=0, bloq=0;
    char x;
    rgt *nodoinicial, *nodoanterior, *l,*nodonuevo, *aux,*actual;
    listo *linicial,*lanterior,*r;
    nuevo *ninicial,*nanterior,*n;
    bloqueado *binicial,*banterior,*b;

    printf("PRACTICA No.5 \n");
    printf("INGRESA # DE PROCESOS: ");
   	scanf("%i",&p);
   	rgt ord[p];
   	rgt buffer;
   	nodoinicial=NULL;
   	linicial=NULL;
   	ninicial=NULL;
   	binicial=NULL;
for(i=0;i<p;i++){
   l=(rgt*)malloc(sizeof(rgt));
   l->posi=i;
   l->cod=i+1;
   int repe;
    l->oper=(rand()%4)+1;
    do{
    repe=0;
     if(l->oper==1 || l->oper==2 || l->oper==3){
     l->no1=(rand()%100);
     l->no2=(rand()%100);
}
    else if(l->oper==4 || l->oper==5){
     l->no1=(rand()%100);
     l->no2=(rand()%100)+1;
}
}while(repe!=0);
   if(l->oper==1)
    l->res=(l->no1+l->no2);
   else if(l->oper==2)
    l->res=(l->no1-l->no2);
   else if(l->oper==3)
    l->res=(l->no1*l->no2);
   else if(l->oper==4)
    l->res=(l->no1/l->no2);
   else if(l->oper==5)
    l->res=(l->no1%l->no2);
    l->tmax=(rand()%9)+2;
    l->tt=l->tmax;
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
    l=nodoinicial;
    for(i=0;i<p;i++){
       ord[i].posi=l->posi;
       ord[i].cod=l->cod;
       ord[i].no1=l->no1;
       ord[i].no2=l->no2;
       ord[i].res=l->res;
       ord[i].oper=l->oper;
       ord[i].tmax=l->tmax;
       ord[i].tt=l->tt;
       ord[i].error=l->error;
       ord[i].salir=l->salir;
       l=l->sig;
}
/* ****************************burbuja **********************************/
for(i = 0; i < p; i++){
   for(j = 0; j < i; j++){
      if(ord[i].tmax < ord[j].tmax){
       buffer = ord[j];
       ord[j] = ord[i];
       ord[i] = buffer;
       if (i==p-5)
       break;
       }
   }
}
/* ****************************burbuja **********************************/
l=nodoinicial;
   for(i=0;i<p;i++){
    l->posi=ord[i].posi;
    l->cod=ord[i].cod;
    l->no1=ord[i].no1;
    l->no2=ord[i].no2;
    l->res=ord[i].res;
    l->oper=ord[i].oper;
    l->tmax=ord[i].tmax;
    l->tt=ord[i].tt;
    l->error=ord[i].error;
    l->salir=ord[i].salir;
    l=l->sig;
}
    l=nodoinicial;
    for(h=0;h<p;h++){
     l->posi=h;
     l=l->sig;
}
/* ****************Asignar primeros nuevos y listos***********************/
   	 l=nodoinicial;
    while(l!=NULL)
            {
             if(l->posi<6)
             {
              r=(listo*)malloc(sizeof(listo));
              r->cod=l->cod;
              r->tmax=l->tmax;
              r->sig=NULL;
                  if (linicial == NULL)
                  {
                      linicial=r;
                      lanterior=r;
                  }
                     else
                      {
                          lanterior->sig=r;
                          lanterior=r;
                      }
             }
             else{
              n=(nuevo*)malloc(sizeof(nuevo));
              n->cod=l->cod;
              n->tmax=l->tmax;
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
/* **************************************************************/
l=nodoinicial;
int flag=0;
for(i=0;i<p+nuevos;i++){
   if(i==p||i>p)
    bloq--;
    aux=l;
    actual=l;
    for(j=0;j<=l->tt;j++){
    system("cls");
    ppe=0;
    ppi=0;
    r=linicial->sig;
    n=ninicial;
    b=binicial;
    printf("\n\n******************************************************************************\n");
    printf("\n\t\t\t\t Tiempo Global: %i\n\n",total);
    printf("_____________________________________________________________________________\n");
    printf("\t\t\tB = Bloquear   S = Salir   E=error \n");
    printf("\t\t\tMENOR TIEMPO RESTANTE PRIMERO");
    printf("\n******************************************************************************\n");
    printf("\nProcesos Listos: \nCodigo\tT.Maximo\n\n");
     while(r!=NULL){
      printf("%i\t%i\n",r->cod,r->tmax);
      r=r->sig;
      }
      printf("\t\t\tProcesos Nuevos: \n\t\t\tCodigo\tT.Maximo\n");
      while(n!=NULL){
       printf("\t\t\t");
       printf("%i\t%i\n",n->cod,n->tmax);
       n=n->sig;
       }
       printf("\n\t\t\t\t\t\tProcesos bloqueados: \n\t\t\t\t\t\tCodigo\tT.Maximo\n");
       while(b!=NULL){
           printf("\t\t\t\t\t\t");
       printf("%i\t%i\n",b->cod,b->tmax);
       b=b->sig;
            }
     printf("\n\n\t\t\tProceso en Ejecucion:\n\n\n");
      if(l->oper==1)
     printf("Codigo: %i\t Operacion:[%i+%i]\tT. Max: %i\n",l->cod,l->no1,l->no2,l->tmax);
      else if(l->oper==2)
     printf("Codigo: %i\t Operacion:[%i-%i]\tT. Max: %i\n",l->cod,l->no1,l->no2,l->tmax);
      else if(l->oper==3)
     printf("Codigo: %i\t Operacion:[%i*%i]\tT. Max: %i\n",l->cod,l->no1,l->no2,l->tmax);
      else if(l->oper==4)
     printf("Codigo: %i\t Operacion:[%i/%i]\tT. Max: %i\n",l->cod,l->no1,l->no2,l->tmax);
      else if(l->oper==5)
     printf("Codigo: %i\t Operacion:[%imod%i]\tT. Max: %i\n",l->cod,l->no1,l->no2,l->tmax);
      else
     printf("Codigo: %i\t RAIZ de %i\tT. Max: %i\n",l->cod,l->no1,l->tmax);
     printf("T.Total: %i\n",j);
     printf("T.Restante: %i\n\n",l->tt-j);
Sleep(900);
if((l->tmax-j)==0)
total=total;
else
total++;
/*****************************KBHIT**********************************/
    if(kbhit())
    {
        x=getch();
         switch(x)
         {
          case 'B': case'b':
                   nuevos++;
                   bloq++;
                   ppi=1;
                   b=(bloqueado*)malloc(sizeof(bloqueado));
                   b->cod=l->cod;
                   b->tmax=l->tt-j;
                   b->sig=NULL;
                       if (binicial == NULL)
                       {
                           binicial=b;
                           banterior=b;
                       }
                          else
                          {
                               banterior->sig=b;
                               banterior=b;
                          }


                      if(l==nodoinicial)
                      {
                           nodonuevo=(rgt*)malloc(sizeof(rgt));
                           nodonuevo->cod=l->cod;
                           nodonuevo->no1=l->no1;
                           nodonuevo->no2=l->no2;
                           nodonuevo->res=l->res;
                           nodonuevo->oper=l->oper;
                           nodonuevo->tmax=l->tmax;
                           nodonuevo->tt=l->tt-j;
                           nodonuevo->sig=NULL;
                           nodoanterior->sig=nodonuevo;
                           nodoanterior=nodonuevo;
                           nodoinicial=l->sig;
                           free(l);
                      }
                          else
                          {
                               nodonuevo=(rgt*)malloc(sizeof(rgt));
                               nodonuevo->cod=l->cod;
                               nodonuevo->no1=l->no1;
                               nodonuevo->no2=l->no2;
                               nodonuevo->res=l->res;
                               nodonuevo->oper=l->oper;
                               nodonuevo->tmax=l->tmax;
                               nodonuevo->tt=l->tt-j;
                               nodonuevo->error=l->error;
                               nodonuevo->salir=l->salir;
                               nodonuevo->sig=NULL;
                               nodoanterior->sig=nodonuevo;
                               nodoanterior=nodonuevo;
                               l=nodoinicial;

                                   while(l!=NULL)
                                   {
                                        if(l->posi==aux->posi-1){
                                        l->sig=aux->sig;
                                        free(aux);
                                        }
                                        l=l->sig;
                                   }
                         }
        break;

           case 'p': case'P':
            printf("\nPausado, (c)=continuar...");
             while(x!='c'||x!='C')
             {
                  if(kbhit())
                  {
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
            }
    }
   if(pps==1)break;
   if(ppe==1)break;
   if(ppi==1)break;
   } // fin del for interno

   /*******************asignacion de lugares de los procesos bloqueados***************/
   if(pps==1)break;
   else{
    l=actual;
    r=linicial;
     if(r!=NULL){
      linicial=r->sig;
      free(r);
}
   n=ninicial;

   b=binicial;
    if(l->sig!=NULL){
     if(ppi==1)
     {
      if(b!=NULL)
       b=b;
     }
      else{
       if(b!=NULL)
       {
                r=(listo*)malloc(sizeof(listo));
                r->cod=b->cod;
                r->tmax=b->tmax;
                r->sig=NULL;
                if (linicial == NULL)
                    {
                         linicial=r;
                         lanterior=r;
                     }
                    else
                        {
                             lanterior->sig=r;
                             lanterior=r;
                        }

            binicial=b->sig;
            free(b);
            flag=1;
        }
}
}
   if(n!=NULL && flag!=1){
     r=(listo*)malloc(sizeof(listo));
     r->cod=n->cod;
     r->tmax=n->tmax;
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
   l=nodoinicial;
    for(h=0;h<p;h++){
     l->posi=h;
     l=l->sig;
     }
     l=actual;
     l=l->sig;
     }
}
   l=nodoinicial;
   while(l!=NULL){
    if(l->salir==1)
     printf("\nCodigo: %i  Resultado: NO EJECUTADO",l->cod);
    else if(l->error==1)
     printf("\nCodigo: %i  Resultado: ERROR",l->cod);
    else
     printf("\nCodigo: %i  Resultado: %i ",l->cod,l->res);
     l=l->sig;
}
   printf("\n\n");
   system("PAUSE");
   return 0;
}

