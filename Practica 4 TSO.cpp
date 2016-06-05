#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <math.h>
#include <conio.h>
#include <time.h>


struct estr{int vacio;
            int bloq;
            int opc;
            int oper1;
            int oper2;
            int ID;
            int TME;
            int TT;
            int TR;
            int fin;
            int lleg;
            int resp;
            int ejec;
            char res[10];
            char oper[15];};

typedef estr Estr;

void gotoxy(int x, int y)
{
  COORD coord;
  coord.X = x;
  coord.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void clean(){
                                        gotoxy(0,2); printf("               ");
                                        gotoxy(0,3); printf("               ");
                                        gotoxy(0,4); printf("               ");
                                        gotoxy(0,5); printf("               ");//Tentativo a borrar
                                        gotoxy(0,7); printf("               ");
                                        gotoxy(0,8); printf("               ");
                                        gotoxy(0,9); printf("               ");
                                        gotoxy(0,10); printf("               ");
                                        gotoxy(26,2); printf("               ");
                                        gotoxy(26,3); printf("               ");
                                        gotoxy(26,4); printf("               ");
                                        gotoxy(26,5); printf("               ");
                                        gotoxy(26,6); printf("                      ");

     }

void clean2(int y,int numproc){
     while (y<=(numproc+1)){
                                     gotoxy(0,y+10); printf("                                                                                          ");
                                     y++;
           }//while

     }

int asignaID(FILE *fptr){
    int bandID,ID,ID2;
    char a[10],b[10],c[10],d[10],e[10],f[15],g[15];
                           do
                                {
                                  bandID=0;
                                  ID=(rand()%99)+1;
                                  rewind(fptr);
                                  while(!feof(fptr)){
                                  fscanf(fptr,"%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|\n",a,b,c,d,e,f,g);
                                  ID2=atoi(d);
                                  if(ID==ID2)bandID++;
                                    }
                                  }while(bandID!=0);
                                  return (ID);
    }

void impresion(int y, Estr procesos){//int x=0; if (procesos.ID<10) x=1;
                                     //gotoxy(58,y); printf("ID %d %s=%s",procesos.ID,procesos.oper,procesos.res);
                                     gotoxy(0,11); printf("EDO FINAL         ID TME  OPERACION         ");
                                     gotoxy(0,y+10); printf("Terminado");
                                     gotoxy(13,y+10); printf("%d  %d",procesos.ID,procesos.TME);
                                     gotoxy(21,y+10);printf("%s=%s",procesos.oper,procesos.res);

     }

void imprimir2(FILE *fptr,int y,int numproc){
      Estr procesos;
      int contp=0,opc1,oper1,oper2,bandID=0,ID,ID2,TME,resultado;
      char a[10],b[10],c[10],d[10],e[10],f[10],g[10];
      rewind(fptr);
      while (contp!=numproc)
                                     {fscanf(fptr,"%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|\n",a,b,c,d,e,f,g); contp++;}
      while(!feof(fptr)&&!feof(fptr)){
      fscanf(fptr,"%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|\n",a,b,c,d,e,procesos.res,procesos.oper);
     opc1=atoi(a);
     procesos.opc=opc1;
     oper1=atoi(b);
     procesos.oper1=oper1;
     oper2=atoi(c);
     procesos.oper2=oper2;
     ID=atoi(d);
     procesos.ID=ID;
     TME=atoi(e);
     procesos.TME=TME;
      gotoxy(0,y+10); printf("Nuevo");
                                     gotoxy(13,y+10); printf("%d  %d",procesos.ID,procesos.TME);
                                     gotoxy(21,y+10);printf("%s",procesos.oper);
      y++;

      }//fin while
     }//fin funcion

int asigna(FILE *fptr, int anterior){
    int opc1,eflag=0,oper1,oper2,bandID=0,ID,ID2,TME,resultado,cont1,cont2;
    char Cada[15],Cadb[15],Res[10],Fin[15],car;
    rewind(fptr);
    do{
     opc1=rand()%(6-1+1)+1;}while (opc1==anterior);
                        anterior=opc1;
                        switch(opc1){case 1:
                                  do{
                                  eflag=0;
                                  oper1=(rand()%15)+1;
                                  oper2=(rand()%15)+1;

                                  ID=asignaID(fptr);

                                  if (eflag==0){
                                  TME=(rand()%15)+1;
                                  }
                                   }while(eflag!=0);
                                     itoa(oper1,Cada,10);
                                     itoa(oper2,Cadb,10);
                                     resultado=oper1+oper2;
                                     itoa(resultado,Res,10);
                                     cont1=0; cont2=0;
                                      while(Cada[cont2]!='\0')
                                     {Fin[cont1]=Cada[cont2];
                                      cont1++; cont2++;       }
                                     cont2=0;
                                     Fin[cont1]='+'; cont1++;
                                     while(Cadb[cont2]!='\0')
                                     {Fin[cont1]=Cadb[cont2];
                                      cont1++; cont2++;        }
                                     Fin[cont1]='\0'; cont1++;
                                  fprintf(fptr,"%d|%d|%d|%d|%d|%s|%s|\n",opc1,oper1,oper2,ID,TME,Res,Fin);
                                  break;
                                  case 2:
                                  do{
                                  eflag=0;
                                  oper1=(rand()%15)+1;
                                  oper2=(rand()%15)+1;
                                  ID=asignaID(fptr);
                                  if (eflag==0){
                                  TME=(rand()%15)+1;
                                  }
                                   }while(eflag!=0);
                                   itoa(oper1,Cada,10);
                                   itoa(oper2,Cadb,10);
                                   resultado=oper1-oper2;
                                     itoa(resultado,Res,10);
                                     cont1=0; cont2=0;
                                     while(Cada[cont2]!='\0')
                                     {Fin[cont1]=Cada[cont2];
                                      cont1++; cont2++;       }
                                     cont2=0;
                                     Fin[cont1]='-'; cont1++;
                                     while(Cadb[cont2]!='\0')
                                     {Fin[cont1]=Cadb[cont2];
                                      cont1++; cont2++;        }
                                      Fin[cont1]='\0'; cont1++;
                                      fprintf(fptr,"%d|%d|%d|%d|%d|%s|%s|\n",opc1,oper1,oper2,ID,TME,Res,Fin);
                                  break;
                                  case 3:
                                  do{
                                  eflag=0;
                                  oper1=(rand()%15)+1;
                                  oper2=(rand()%15)+1;
                                  ID=asignaID(fptr);
                                  if (eflag==0){
                                  TME=(rand()%10)+1;
                                  }
                                   }while(eflag!=0);
                                   itoa(oper1,Cada,10);
                                   itoa(oper2,Cadb,10);
                                   resultado=oper1*oper2;
                                     itoa(resultado,Res,10);
                                     cont1=0; cont2=0;
                                     while(Cada[cont2]!='\0')
                                     {Fin[cont1]=Cada[cont2];
                                      cont1++; cont2++;       }
                                     cont2=0;
                                     Fin[cont1]='*'; cont1++;
                                     while(Cadb[cont2]!='\0')
                                     {Fin[cont1]=Cadb[cont2];
                                      cont1++; cont2++;        }
                                      Fin[cont1]='\0'; cont1++;
                                  fprintf(fptr,"%d|%d|%d|%d|%d|%s|%s|\n",opc1,oper1,oper2,ID,TME,Res,Fin);
                                  break;
                                  case 4:
                                  do{
                                  eflag=0;
                                  do{oper1=(rand()%30)+1;
                                  oper2=(rand()%10)+1;}while(oper1<=oper2);
                                  ID=asignaID(fptr);
                                  if (eflag==0){
                                  TME=(rand()%15)+1;
                                  }
                                   }while(eflag!=0);
                                   itoa(oper1,Cada,10);
                                   itoa(oper2,Cadb,10);
                                   resultado=oper1/oper2;
                                     itoa(resultado,Res,10);
                                     cont1=0; cont2=0;
                                     while(Cada[cont2]!='\0')
                                     {Fin[cont1]=Cada[cont2];
                                      cont1++; cont2++;       }
                                     cont2=0;
                                     Fin[cont1]='/'; cont1++;
                                     while(Cadb[cont2]!='\0')
                                     {Fin[cont1]=Cadb[cont2];
                                      cont1++; cont2++;        }
                                      Fin[cont1]='\0'; cont1++;
                                  fprintf(fptr,"%d|%d|%d|%d|%d|%s|%s|\n",opc1,oper1,oper2,ID,TME,Res,Fin);
                                  break;
                                  case 5:
                                  do{
                                  eflag=0;
                                  do{oper1=(rand()%30)+1;
                                  oper2=(rand()%10)+1;}while(oper1<=oper2);
                                  ID=asignaID(fptr);
                                  if (eflag==0){
                                  TME=(rand()%5)+1;
                                  }
                                   }while(eflag!=0);
                                   itoa(oper1,Cada,10);
                                   itoa(oper2,Cadb,10);
                                   resultado=oper1%oper2;
                                     itoa(resultado,Res,10);
                                     cont1=0; cont2=0;
                                     while(Cada[cont2]!='\0')
                                     {Fin[cont1]=Cada[cont2];
                                      cont1++; cont2++;       }
                                     cont2=0;
                                     Fin[cont1]='%'; cont1++;
                                     while(Cadb[cont2]!='\0')
                                     {Fin[cont1]=Cadb[cont2];
                                      cont1++; cont2++;        }
                                      Fin[cont1]='\0'; cont1++;
                                  fprintf(fptr,"%d|%d|%d|%d|%d|%s|%s|\n",opc1,oper1,oper2,ID,TME,Res,Fin);
                                  break;
                                  case 6:
                                  do{
                                  eflag=0;
                                  oper1=(rand()%15)+1;
                                  oper2=(rand()%15)+1;
                                  ID=asignaID(fptr);
                                  if (eflag==0){
                                  TME=(rand()%15)+1;
                                  }
                                   }while(eflag!=0);
                                   itoa(oper1,Cada,10);
                                   itoa(oper2,Cadb,10);
                                   resultado=sqrt(oper1);
                                     sprintf(Res,"%f",resultado);
                                     cont1=0; cont2=0;
                                     Fin[cont1]='r'; cont1++;
                                     Fin[cont1]='a'; cont1++;
                                     Fin[cont1]='i'; cont1++;
                                     Fin[cont1]='z'; cont1++;
                                     Fin[cont1]=' '; cont1++;
                                     cont2=0;
                                     while(Cada[cont2]!='\0')
                                     {Fin[cont1]=Cada[cont2];
                                      cont1++; cont2++;       }
                                      Fin[cont1]='\0'; cont1++;
                                  fprintf(fptr,"%d|%d|%d|%d|%d|%s|%s|\n",opc1,oper1,oper2,ID,TME,Res,Fin);
                                  break;
                                  }//switch
                                  return (anterior);
     }

Estr leer(FILE *fptr,int reloj){
     Estr procesos;
     char a[10],b[10],c[10],d[10],e[10];
     int opc1,eflag=0,oper1,oper2,bandID=0,ID,TME;
     fscanf(fptr,"%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|\n",a,b,c,d,e,procesos.res,procesos.oper);
     procesos.vacio=1;
     opc1=atoi(a);
     procesos.opc=opc1;
     oper1=atoi(b);
     procesos.oper1=oper1;
     oper2=atoi(c);
     procesos.oper2=oper2;
     ID=atoi(d);
     procesos.ID=ID;
     TME=atoi(e);
     procesos.TME=TME;
     procesos.TR=TME;
     procesos.lleg=reloj;
     procesos.TT=0;
     procesos.ejec=0;
     procesos.bloq=0;
     procesos.resp=-1;
     return(procesos);
     }


int main (void){

    int band4=0,dif,numproc=0,y2,quantum,valq;
    int i,contp=0,reloj=0,resultado,y=2,bandfin=0,banderr=0,band1=0,bandb=0,ejec=0,bandw=0,band2=0;
    int nump,proceso=0,anterior=0,eflag,opc1,oper1,oper2,bandID=0,ID,ID2,TME;
    char a[10],b[10],c[10],d[10],e[10],f[15],g[15],Cada[15],Cadb[15],Res[10],Fin[15],car;

    Estr dummy[2];
    Estr procesos[5];
    Estr bloqs[5];
                   bloqs[4].ID=0;
                   bloqs[4].TME=0;
                   bloqs[4].TT=0;
                   strcpy(bloqs[4].oper," ");
                   bloqs[4].TR=0;
                   bloqs[4].vacio=0;
                   bloqs[4].bloq=0;
                   bloqs[4].TT=0;
                   bloqs[4].ejec=0;
                   bloqs[4].resp=-1;
    while(contp<5){procesos[contp].ID=0;
                   procesos[contp].TME=0;
                   procesos[contp].TT=0;
                   strcpy(procesos[contp].oper," ");
                   procesos[contp].TR=0;
                   procesos[contp].vacio=0;
                   procesos[contp].bloq=0;
                   procesos[contp].TT=0;
                   procesos[contp].ejec=0;
                   procesos[contp].resp=-1;
                   bloqs[contp].vacio=0;
                   bloqs[contp].ejec=0;
                   bloqs[contp].bloq=0;
                   contp++;
                   }
    FILE *fptr,*fptr2;
    srand(time(NULL));
    fptr=fopen("Procesos.txt","w+");
    printf("PRACTICA No.4 TSO\n");
    printf("INGRESA # DE PROCESOS:\n");
    scanf("%d",&nump);
    valq=5;
   system("cls");
    quantum=valq;
    while(proceso<nump){
                        anterior=asigna(fptr,anterior);
                        proceso++;
                         }
                        rewind(fptr);
                                    while(!feof(fptr)||bandfin==0){
                                     clean();
                                     banderr=0; band2=0;
                                     dif=0;
                                     contp=0;
                                     rewind(fptr);
                                     while(contp<4){if (procesos[contp].vacio!=0)dif++;
                                                    if (bloqs[contp].vacio!=0)dif++;
                                                    contp++;
                                             }
                                     if(dif<4){
                                     contp=0;
                                     while (contp!=numproc)
                                     {fscanf(fptr,"%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|\n",a,b,c,d,e,f,g); contp++;}
                                     contp=0;//Inicio while que comprueba que todos esten llenos
                                     while(contp<4&&!feof(fptr)&&dif<4/*&&bandb==0*/){if (procesos[contp].vacio==0){
                                                    proceso--;
                                                    procesos[contp]=leer(fptr,reloj);
                                                     dif++;
                                                     numproc++;
                                                     bandw=0;}
                                                    contp++;
                                                      }
                                                      }//if
                                     gotoxy(0,0); printf("Procesos nuevos:%d\t\t\t\t\t  ",proceso); gotoxy(58,0); printf("Reloj: %d\n",reloj);
                                     gotoxy(0,1); printf("Procesos en espera:\t  "); printf("Procesos en ejecucion:\t  ");// printf("Procesos finalizados:\n");
                                     if (procesos[1].vacio!=0&&procesos[1].bloq==0){gotoxy(0,2); printf("ID: %d TME: %d",procesos[1].ID,procesos[1].TME);}
                                     if (procesos[2].vacio!=0&&procesos[2].bloq==0){gotoxy(0,3); printf("ID: %d TME: %d",procesos[2].ID,procesos[2].TME);}
                                     if (procesos[3].vacio!=0&&procesos[3].bloq==0){gotoxy(0,4); printf("ID: %d TME: %d",procesos[3].ID,procesos[3].TME);}

                                     if(procesos[0].resp==-1)procesos[0].resp=reloj-procesos[0].lleg;
                                     //Inicio While de proceso
                               while(procesos[0].TR>=0&&banderr==0||bandw!=0)
                                       {
                                                        if (quantum<0){
                                                                         contp=0;
                                                                         dummy[0]=procesos[0];
                                                                         while(procesos[contp].vacio!=0&&contp<3){
                                                                         procesos[contp]=procesos[contp+1];
                                                                         contp++;
                                                                            }
                                                                         if (procesos[contp-1].vacio!=0/*contp==3*/){
                                                                         procesos[contp]=dummy[0];}
                                                                          else {procesos[contp-1]=dummy[0];}



                                                                          quantum=valq;
                                                                          if (procesos[1].vacio!=0&&procesos[1].bloq==0){gotoxy(0,2); printf("ID: %d TME: %d",procesos[1].ID,procesos[1].TME);}
                                                                          if (procesos[2].vacio!=0&&procesos[2].bloq==0){gotoxy(0,3); printf("ID: %d TME: %d",procesos[2].ID,procesos[2].TME);}
                                                                          if (procesos[3].vacio!=0&&procesos[3].bloq==0){gotoxy(0,4); printf("ID: %d TME: %d",procesos[3].ID,procesos[3].TME);}
                                                                          gotoxy(26,2); printf("ID: %d ",procesos[0].ID);
                                                                          gotoxy(26,3); printf("Ope %s",procesos[0].oper);
                                                                          gotoxy(26,4); printf("TME: %d",procesos[0].TME);
                                                                          gotoxy(26,5); printf("TT: %d TR: %d",procesos[0].TT,procesos[0].TR);

                                                                         //checkpoint
                                                                         }


                                       //PROTOTIPO
                                      dif=0;
                                      contp=0;
                                      rewind(fptr);
                                      while(contp<4){if (procesos[contp].vacio!=0)dif++;
                                                     if (bloqs[contp].vacio!=0)dif++;
                                                     contp++;
                                              }
                                      if(dif<4){
                                      contp=0;
                                      while (contp!=numproc)
                                      {fscanf(fptr,"%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|\n",a,b,c,d,e,f,g); contp++;}
                                      contp=0;//Inicio while que comprueba que todos esten llenos
                                      while(contp<4&&!feof(fptr)&&dif<4/*&&bandb==0*/){if (procesos[contp].vacio==0){
                                                    proceso--;
                                                    procesos[contp]=leer(fptr,reloj);
                                                     dif++;
                                                     numproc++;
                                                     bandw=0;}
                                                    contp++;
                                                      }
                                                      }//if
                                        //Fin Prototipo
                                        if(procesos[0].resp==-1)procesos[0].resp=reloj-procesos[0].lleg;
                                        clean();
                                        if (procesos[1].vacio!=0&&procesos[1].bloq==0){gotoxy(0,2); printf("ID: %d TME: %d",procesos[1].ID,procesos[1].TME);}
                                        if (procesos[2].vacio!=0&&procesos[2].bloq==0){gotoxy(0,3); printf("ID: %d TME: %d",procesos[2].ID,procesos[2].TME);}
                                        if (procesos[3].vacio!=0&&procesos[3].bloq==0){gotoxy(0,4); printf("ID: %d TME: %d",procesos[3].ID,procesos[3].TME);}
                                        if (bandw==0) {
                                        gotoxy(26,2); printf("ID: %d ",procesos[0].ID);
                                        gotoxy(26,3); printf("Ope %s",procesos[0].oper);
                                        gotoxy(26,4); printf("TME: %d",procesos[0].TME);
                                        gotoxy(26,5); printf("TT: %d TR: %d",procesos[0].TT,procesos[0].TR);
                                        gotoxy(26,6); printf("Tiempo de turno:%d",quantum);}//fin IF
                                        gotoxy(0,6); printf("Bloqueados:");
                                        if (bloqs[0].vacio!=0){gotoxy(0,7); printf("ID: %d TR: %d",bloqs[0].ID,bloqs[0].bloq);}
                                        if (bloqs[1].vacio!=0){gotoxy(0,8); printf("ID: %d TR: %d",bloqs[1].ID,bloqs[1].bloq);}
                                        if (bloqs[2].vacio!=0){gotoxy(0,9); printf("ID: %d TR: %d",bloqs[2].ID,bloqs[2].bloq);}
                                        if (bloqs[3].vacio!=0){gotoxy(0,10); printf("ID: %d TR: %d",bloqs[3].ID,bloqs[3].bloq);}
                                        gotoxy(0,11); printf("EDO         ID TME  OPERACION         ");
                                        gotoxy(58,0); printf("Reloj: %d\n",reloj);

                                        if(bloqs[0].bloq==0&&bandb==1) {contp=0; band1=0; band2=0;
                                          while(contp<4&&band1==0&&band2==0){if(procesos[contp].ID==procesos[contp-1].ID)band2++;
                                                                   if(procesos[contp].vacio==0||procesos[contp].bloq!=0&&band2==0)
                                                                                              {procesos[contp]=bloqs[0];//antes se copiaba campo por campo
                                                                                              band1++;
                                                                                              procesos[contp].vacio=1;
                                                                                              procesos[contp].bloq=0;
                                                                                                }
                                                         contp++;
                                                         }
                                          if(band2==0){//if
                                          contp=0;band1=0;
                                          while(contp<4&&band1==0){
                                          if(procesos[contp].bloq!=0&&procesos[contp].ID!=0){procesos[contp].bloq=0; band1++;}
                                          contp++;
                                           }
                                          }//if
                                          band1=0;
                                          bloqs[0]=bloqs[1];
                                          bloqs[1]=bloqs[2];
                                          bloqs[2]=bloqs[3];
                                          if (bloqs[0].vacio!=0){band1++;}
                                          if (bloqs[1].vacio!=0){ band1++;}
                                          if (bloqs[2].vacio!=0){ band1++;}
                                          if (bloqs[3].vacio!=0){ band1++; bloqs[3]=bloqs[4];}
                                          if (band1==0){bandb=0;}
                                           if(bandw!=0)
                                           {bandw=0; band2++;}
                                          }//while
                                         for(i=0;i<10;i++){//principio for
                                          Sleep(100);
                                        if(kbhit()){
                                                    car=getch();

                                                    if (car=='e'){banderr=1;
                                                                  strcpy(procesos[0].res,"Error");
                                                                            }
                                                    if (car=='p') {
																  gotoxy(0,27);printf("\t\t Procesamiento pausado, presiona (c) para continuar ...");
                                                                  for(;car!='c';){if(kbhit())
                                                                  gotoxy(0,15); car=getch();
                                                                  gotoxy(0,27);printf("\t\t                                                       ");
                                                                  }//fin for
                                                                }//fin if
                                                    if (car=='b'&&bandw==0){contp=0; band1=0; quantum=valq+1;
                                                                  while(contp<4&&band1==0){
                                                                  if (bloqs[contp].vacio==0)
                                                                  {
                                                                      band1++; bandb=1; //bloqs[contp].bloq=6;
                                                                      bloqs[contp]=procesos[0];//aqui antes se copiaba campo por campo
                                                                      bloqs[contp].bloq=6;
                                                                      bloqs[0].ejec=procesos[contp].ejec;
                                                                      bloqs[contp].vacio++;
                                                                        }
                                                                  contp++;
                                                                   }//while
                                                                   if(procesos[1].vacio==0&&bandw==0)
                                                                   {procesos[0]=procesos[5]; bandw=1; }
                                                                   procesos[0]=procesos[1];
                                                                   procesos[1]=procesos[2];
                                                                   procesos[2]=procesos[3]; procesos[3].vacio=0;
                                                                  }//fin 'i'
                                                    /*if (car=='n'){asigna(fptr,anterior);
                                                                  proceso++;
                                                                  gotoxy(0,0); printf("Procesos nuevos:%d",proceso);
                                                                  nump++;
                                                              }*/
                                                    if (car=='s'){;

                                                                  }// imprime estados al press s
                                                             }// fin if kbhit()
                                                            }// fin for
                                                             reloj++; procesos[0].ejec++;
                                                         if (bloqs[0].vacio!=0&&bloqs[0].bloq>0) bloqs[0].bloq--;

                                        if(banderr==0&&bandw==0){procesos[0].TT++; procesos[0].TR--;  quantum--;

                                        }

                                           }//NO BORRAR fin While de proceso
                                      if (procesos[0].ID!=0){//inicio bandw
                                           quantum=valq;
                                           ejec=0; procesos[0].ejec--;
                                           clean();
                                           procesos[0].fin=reloj;
                                           impresion(y,procesos[0]);
                                           y++;
                                           if(procesos[3].vacio!=0){procesos[0]=procesos[1]; procesos[1]=procesos[2]; procesos[2]=procesos[3]; procesos[3].vacio=0;}
                                            else if(procesos[2].vacio!=0/*no bloqueo*/){procesos[0]=procesos[1]; procesos[1]=procesos[2]; procesos[2].vacio=0;}
                                             else if(procesos[1].vacio!=0/*no bloqueo*/){procesos[0]=procesos[1]; procesos[1].vacio=0;}
                                               else if(procesos[0].vacio!=0&&bandb==0){procesos[0].vacio=0; bandfin=1; } else if(procesos[0].vacio!=0&&bandb!=0){bandw=1; procesos[0]=procesos[4];
                                               }
                                           }//if bandw!=0
                                       }
                                    gotoxy(10,37); getch();
                                     fclose(fptr);
                                  }
