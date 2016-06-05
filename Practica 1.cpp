#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
#include <math.h>
using namespace std;

class Practica_1{
private:
int op1=1, op2=1, res, tiempo;
public:
    //Practica_1();
    void proceso(int i, int tiemp);
};

void Practica_1::proceso(int i, int tiemp){
        res=op1+op2;
        cout<<"\t\n\n"<<op1<<" + "<<op2<<" = "<<res<<endl;
        Sleep(tiemp*1000);
        cout<<"\tProceso "<<i+1<<" terminado. TIEMPO: "<<tiemp<<" s."<<endl;
        op1++;
        op2++;
        tiempo=tiemp;
}

int main()
{
    Practica_1 p1;
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
        for( i=0; i<x; i++)
        {
            tiemp=rand()%6;
            p1.proceso(i, tiemp);
            if((i+1)%4==0){
                cout<<"\t\n\n--------------->LOTE: "<<lote;
                lote++;
            }
        }
    }
    cout<<"\t\n\nbye bye!!"<<endl;
    return 0;
}
