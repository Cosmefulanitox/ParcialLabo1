#include <iostream>
#include "AgenteArchivo.h"
#include "MultaArchivo.h"
#include "ModeloParcial.h"
using namespace std;

int main()
{

    ModeloParcial m;
    int selec;
    do
    {
        cout<<"Ingrese 1 para punto 1"<<endl;
        cout<<"Ingrese 2 para punto 2"<<endl;
        cout<<"Ingrese 3 para punto 3"<<endl;
        cout<<"Ingrese 4 para punto 4"<<endl;
        cout<<"Ingrese 0 para para salir"<<endl;
        cin>>selec;

        switch(selec)
        {
        case 1:
                m.punto1();

            break;
        case 2:
            m.punto2();

            break;
        case 3:
            m.punto3();
            break;
             case 4:
                 m.punto4();
            break;
        default:
             cout<<"Parametro incorrecto"<<endl;
            break;
        }










    }
    while(selec=!0);





    return 0;
}
