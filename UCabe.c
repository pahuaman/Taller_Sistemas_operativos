#include <conio.h>
#include <stdio.h>
int main()
{
    //clrscr(); funcion = int kbhit(void);
    /* for(;;){
        printF("bla bla");
        if(kbhit())
        break;
       }
    */

     printf( "Ejemplo de kbhit\r\n\r\n" );
     printf( "El programa esta a la espera de registrar una tecla pulsada.\r\n");

     while( !kbhit() );
     printf( "El caracter es %c\n", getch() );
     printf( "Pulsa una tecla para continuar..." );
     getch();

     return 0;
}
