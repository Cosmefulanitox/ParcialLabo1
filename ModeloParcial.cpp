#include "ModeloParcial.h"

void ModeloParcial::punto1 ()
{
    int x,y,con=0;

    AgenteArchivo agen;
    Agente *a;
    MultaArchivo mul;
    Multa *m;
    bool ban=false;

    a= new Agente [agen.getCantidadRegistros()];
    m= new Multa [mul.getCantidadRegistros()];

    agen.leer(a,agen.getCantidadRegistros());
    mul.leer(m,mul.getCantidadRegistros());

    for (x=0; x<agen.getCantidadRegistros(); x++)
    {
        ban=false;
        for (y=0; y<mul.getCantidadRegistros(); y++)
        {
            if (a[x].getIdAgente()==m[y].getIDAgente()&&m[y].getFechaMulta().getAnio()==2022&&ban==false)
            {
                ban=true;
                con++;
            }
        }
    }

    std::cout<<"La cantidad de agentes que no hicieron multas en 2022 son "<<agen.getCantidadRegistros()-con<<std::endl;

    delete [] a;
    delete [] m;
}
 void ModeloParcial::punto2 ()
 {
     int x,y,*canM;
     float *monto;
     AgenteArchivo agen;
    Agente *a;
    MultaArchivo mul;
    Multa *m;


    a= new Agente [agen.getCantidadRegistros()];
    m= new Multa [mul.getCantidadRegistros()];
    canM= new int [agen.getCantidadRegistros()]();
    monto= new float [agen.getCantidadRegistros()]();


    agen.leer(a,agen.getCantidadRegistros());
    mul.leer(m,mul.getCantidadRegistros());

    for (x=0; x<agen.getCantidadRegistros(); x++)
    {

        for (y=0; y<mul.getCantidadRegistros(); y++)
        {
            if (a[x].getIdAgente()==m[y].getIDAgente()&&m[y].getFechaMulta().getAnio()==2023)
            {

                canM[x]++;
                monto[x]+=m[y].getMonto();
            }
        }
    }

    std::cout<<"      ID AGENTE          APELLIDOS          NOMBRES          CANTMULTAS          MONTOTOTAL"<<std::endl;
     for (x=0; x<agen.getCantidadRegistros(); x++)
     {
         std::cout<<std::setw(12)<<a[x].getIdAgente()<<"  "<<std::setw(20)<<a[x].getApellidos()<<std::setw(17)<<a[x].getNombres()<<std::setw(15)<<canM[x]<<std::setw(17)<<"$"<<monto[x]<<std::endl;
     }

      delete [] a;
    delete [] m;
     delete [] canM;
    delete [] monto;
 }

