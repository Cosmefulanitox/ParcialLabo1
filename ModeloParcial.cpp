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
            if (a[x].getIdAgente()==m[y].getIDAgente()&&m[y].getFechaMulta().getAnio()==2022&&ban==false&&m[y].getEliminado()==0)
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
            if (a[x].getIdAgente()==m[y].getIDAgente()&&m[y].getFechaMulta().getAnio()==2023&&m[y].getEliminado()==0)
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

void ModeloParcial::punto3 ()
{

    int x,y, canM[10]= {};
    MultaArchivo mul;
    Multa *m;

    m= new Multa [mul.getCantidadRegistros()];

    mul.leer(m,mul.getCantidadRegistros());

   for (x=0; x<10; x++)
    {

        for (y=0; y<mul.getCantidadRegistros(); y++)
        {
            if (m[y].getTipoInfraccion()==x+1&&m[y].getEliminado()==0)
            {

                canM[x]++;

            }
        }
    }

    for (x=0; x<10; x++)
    {
        std::cout<<"El ID "<<x+1<<" tiene un total de multas: "<<canM[x]<<std::endl;

    }

    delete [] m;


}

void ModeloParcial::punto4()
{
    int y=0,x;
    MultaArchivo mule("MultasPagadas2022.dat");
    MultaArchivo mul;

    Multa *m;
    Multa aux;

    m= new Multa [mul.getCantidadRegistros()];

    mul.leer(m,mul.getCantidadRegistros());

    for (y=0;y<mul.getCantidadRegistros();y++)
    {
        if (m[y].getPagada()==1&&m[y].getFechaMulta().getAnio()==2022)
        {
            x= mule.buscar(m[y].getIDMulta());
            if(x==-1)
            {
                mule.guardar(m[y]);
            }


             }

    }
    std::cout<<"ID multa"<<"         "<<"Estado de pago"<<"          "<<"Tipo de infracciones"<<"          "<<"Estado eliminado"<<"          "<<"Fecha multa"<<std::endl;
    for(x=0;x<mule.getCantidadRegistros();x++)
    {
        aux = mule.leer(x);


         std::cout<<std::setw(5)<<aux.getIDMulta()<<std::setw(20)<<aux.getPagada()<<std::setw(25)<<aux.getTipoInfraccion()<<std::setw(30)<<aux.getEliminado()<<std::setw(27)<<aux.getFechaMulta().toString()<<std::endl;
    }



}


