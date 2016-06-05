 #include <stdlib.h>
#include <stdio.h>
#include<windows.h>

typedef struct _nodo3 {
   int valor3;
   struct _nodo3 *siguiente3;
} tipoNodo3;

typedef tipoNodo3 *pNodo3;

void Anadir3(pNodo3 *primero3, pNodo3 *ultimo3, int v3);
int Leer3(pNodo3 *primero3, pNodo3 *ultimo3);




typedef struct _nodo2 {
   int valor2;
   struct _nodo2 *siguiente2;
} tipoNodo2;

typedef tipoNodo2 *pNodo2;

void Anadir2(pNodo2 *primero2, pNodo2 *ultimo2, int v2);
int Leer2(pNodo2 *primero2, pNodo2 *ultimo2);



typedef struct _nodo {
   int valor;
   struct _nodo *siguiente;
} tipoNodo;

typedef tipoNodo *pNodo;

/* Funciones con colas: */
void Anadir(pNodo *primero, pNodo *ultimo, int v);
int Leer(pNodo *primero, pNodo *ultimo);
 
int main()
{
	  pNodo3 primero3 = NULL, ultimo3 = NULL;
	
	  int cincoseg=0;
	  pNodo2 primero2 = NULL, ultimo2 = NULL;
	  int bloqueado;
   
      
	
   	pNodo primero = NULL, ultimo = NULL;
   	int tobolsas,i=1,b=1,decidedulce,retardo,f,duracion[100],primeroscinco=0;
   	char d,c,estado[100];
      srand(time(0));
      tobolsas=rand()%100;

        do
        {                                 
            decidedulce=rand()%4+1;
            if(primeroscinco==0)
            {
            	Anadir(&primero, &ultimo, decidedulce);
            	decidedulce=rand()%4+1;
            	Anadir(&primero, &ultimo, decidedulce);
            	decidedulce=rand()%4+1;
            	Anadir(&primero, &ultimo, decidedulce);
            	decidedulce=rand()%4+1;
            	Anadir(&primero, &ultimo, decidedulce);
            	decidedulce=rand()%4+1;
            	Anadir(&primero, &ultimo, decidedulce);
            	decidedulce=rand()%4+1;
            }
            else
            	Anadir(&primero, &ultimo, decidedulce);
            	
			primeroscinco++;
            
            retardo=rand()%8;
            duracion[i]=retardo;
            f=0;
            d='g';
			do
			{
				if(f==retardo)
				{
					d='e';
					
				}
				else
				{
						Sleep(1000);
				}
				
				if(i==tobolsas)
                {
                        c='t';
                }
                if(f!=retardo)
                {
                	estado[i]='z';
				}
                if(f==retardo)
                {
                	estado[i]='y';
				}
			
				if(kbhit())
				d=getch();
				if(d=='t')
				{
					c=d;
				}
            	f++;
    		}while(d!='e');
    		if(primeroscinco==1)
    		{
    			Anadir2(&primero2, &ultimo2, Leer(&primero, &ultimo) );
    			Anadir2(&primero2, &ultimo2, Leer(&primero, &ultimo) );
    			Anadir2(&primero2, &ultimo2, Leer(&primero, &ultimo) );
    			Anadir2(&primero2, &ultimo2, Leer(&primero, &ultimo) );
    			Anadir2(&primero2, &ultimo2, Leer(&primero, &ultimo) );
    		}
    		else 
    		Anadir2(&primero2, &ultimo2, Leer(&primero, &ultimo) );
    	
                              
            switch(Leer2(&primero2, &ultimo2))    
    		{
    			case 1:
    				printf("Bolsa # %d\n",i);
            		printf("Tiempo de llenado de los dulces. %d unidades de tiempo\n",retardo);
            		printf("Resultado bolsa llena con 10 dulces de menta. \n\n");
                break;
    			case 2:
                    printf("Bolsa # %d\n",i);
            		printf("Tiempo de llenado de los dulces. %d unidades de tiempo\n",retardo);
            		printf("Resultado bolsa llena con 10 dulces chocolate. \n\n");
                break;
                case 3:
    				printf("Bolsa # %d\n",i);
            		printf("Tiempo de llenado de los dulces. %d unidades de tiempo\n",retardo);
            		printf("Resultado bolsa llena con 10 dulces fresa. \n\n");
                break;
    			case 4:
                    printf("Bolsa #%d\n",i);
            		printf("Tiempo de llenado de los dulces. %d unidades de tiempo\n",retardo);
            		printf("Resultado bolsa llena con 10 dulces piña. \n\n");
                break;
    			}    			
               i++;
       }while(c!='t');  
       printf("\tProcesos terminados\n");
       printf("#Proceso.\tDuracion\tEstado\t\t\n");
	
       for(i=1;i<=tobolsas;i++)
       {
       	if(estado[i]=='z')
       	{
       		printf("%d\t\t  %d\t\tError\n",i,duracion[i]);
		}
	   else
	   		if(estado[i]=='y')
	   		{
	   			printf("%d\t\t  %d\t\tEjecutado\n",i,duracion[i]);
	   		}
	   		else
	   		printf("%d\t\t  0\t\tNo Ejecutado\n",i);
	   		
	   }



   system("PAUSE");
   return 0;
}



void Anadir2(pNodo2 *primero2, pNodo2 *ultimo2, int v2)
{
   pNodo2 nuevo2;
 
   /* Crear un nodo nuevo */
   nuevo2 = (pNodo2)malloc(sizeof(tipoNodo2));
   nuevo2->valor2 = v2;
   /* Este será el último nodo, no debe tener siguiente */
   nuevo2->siguiente2 = NULL;
   /* Si la cola no estaba vacía, añadimos el nuevo a continuación de ultimo */
   if(*ultimo2) (*ultimo2)->siguiente2 = nuevo2;
   /* Ahora, el último elemento de la cola es el nuevo nodo */
   *ultimo2 = nuevo2;
   /* Si primero es NULL, la cola estaba vacía, ahora primero apuntará también al nuevo nodo */
   if(!*primero2) *primero2 = nuevo2;
}

int Leer2(pNodo2 *primero2, pNodo2 *ultimo2)
{
   pNodo2 nodo2; /* variable auxiliar para manipular nodo */
   int v2;      /* variable auxiliar para retorno */
   
   /* Nodo apunta al primer elemento de la pila */
   nodo2 = *primero2;
   if(!nodo2) return 0; /* Si no hay nodos en la pila retornamos 0 */
   /* Asignamos a primero la dirección del segundo nodo */
   *primero2 = nodo2->siguiente2;
   /* Guardamos el valor de retorno */
   v2 = nodo2->valor2; 
   /* Borrar el nodo */
   free(nodo2);
   /* Si la cola quedó vacía, ultimo debe ser NULL también*/
   if(!*primero2) *ultimo2 = NULL;
   return v2;
}





void Anadir3(pNodo3 *primero3, pNodo3 *ultimo3, int v3)
{
   pNodo3 nuevo3;
 
   /* Crear un nodo nuevo */
   nuevo3 = (pNodo3)malloc(sizeof(tipoNodo3));
   nuevo3->valor3 = v3;
   /* Este será el último nodo, no debe tener siguiente */
   nuevo3->siguiente3 = NULL;
   /* Si la cola no estaba vacía, añadimos el nuevo a continuación de ultimo */
   if(*ultimo3) (*ultimo3)->siguiente3 = nuevo3;
   /* Ahora, el último elemento de la cola es el nuevo nodo */
   *ultimo3 = nuevo3;
   /* Si primero es NULL, la cola estaba vacía, ahora primero apuntará también al nuevo nodo */
   if(!*primero3) *primero3 = nuevo3;
}

int Leer3(pNodo3 *primero3, pNodo3 *ultimo3)
{
   pNodo3 nodo3; /* variable auxiliar para manipular nodo */
   int v3;      /* variable auxiliar para retorno */
   
   /* Nodo apunta al primer elemento de la pila */
   nodo3 = *primero3;
   if(!nodo3) return 0; /* Si no hay nodos en la pila retornamos 0 */
   /* Asignamos a primero la dirección del segundo nodo */
   *primero3 = nodo3->siguiente3;
   /* Guardamos el valor de retorno */
   v3 = nodo3->valor3; 
   /* Borrar el nodo */
   free(nodo3);
   /* Si la cola quedó vacía, ultimo debe ser NULL también*/
   if(!*primero3) *ultimo3 = NULL;
   return v3;
}





void Anadir(pNodo *primero, pNodo *ultimo, int v)
{
   pNodo nuevo;
 
   /* Crear un nodo nuevo */
   nuevo = (pNodo)malloc(sizeof(tipoNodo));
   nuevo->valor = v;
   /* Este será el último nodo, no debe tener siguiente */
   nuevo->siguiente = NULL;
   /* Si la cola no estaba vacía, añadimos el nuevo a continuación de ultimo */
   if(*ultimo) (*ultimo)->siguiente = nuevo;
   /* Ahora, el último elemento de la cola es el nuevo nodo */
   *ultimo = nuevo;
   /* Si primero es NULL, la cola estaba vacía, ahora primero apuntará también al nuevo nodo */
   if(!*primero) *primero = nuevo;
}

int Leer(pNodo *primero, pNodo *ultimo)
{
   pNodo nodo; /* variable auxiliar para manipular nodo */
   int v;      /* variable auxiliar para retorno */
   
   /* Nodo apunta al primer elemento de la pila */
   nodo = *primero;
   if(!nodo) return 0; /* Si no hay nodos en la pila retornamos 0 */
   /* Asignamos a primero la dirección del segundo nodo */
   *primero = nodo->siguiente;
   /* Guardamos el valor de retorno */
   v = nodo->valor; 
   /* Borrar el nodo */
   free(nodo);
   /* Si la cola quedó vacía, ultimo debe ser NULL también*/
   if(!*primero) *ultimo = NULL;
   return v;
}


