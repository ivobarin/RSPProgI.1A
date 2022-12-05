//Ivo Barinstein
#include <stdio.h>
#include "string.h"
#include "ctype.h"
#include <stdlib.h>
//1.Dada la estructura eVehiculo crear una función constructora base y una parametrizada
//2. Dada la estructura del punto anterior declarar una variable con valores y guardarla en un archivo de texto.
//3. Dada la estructura del punto anterior declarar una variable con valores y guardarla en un archivo binario
typedef struct{
int id;
char marca[20];
int tipo;
float peso;
}eVehiculo;

eVehiculo* vehiculo_new();
eVehiculo* vehiculo_new_param(int id, char marca[], int tipo, float peso);
int vehiculoSetID(eVehiculo* p, int id);
int vehiculoSetMarca(eVehiculo* p, char marca[]);
int vehiculoSetTipo(eVehiculo* p, int tipo);
int vehiculoSetPeso(eVehiculo* p, float peso);

int main()
{
//PUNTO 2
    FILE* arc = fopen("examen.txt","w");
    eVehiculo harcodeo = {1,"Toyota",2,50.2};
    if(arc != NULL)
    {
        fprintf(arc,"%d %s %d %f\n",harcodeo.id,harcodeo.marca,harcodeo.tipo,harcodeo.peso);
        printf("El programa se sobreescribio con exito!\n");
    }
    fclose(arc);

//PUNTO 3
//    FILE* arc = fopen("examenBin.txt","wb");
//    eVehiculo harcodeo = {1,"Toyota",2,50.2};
//    if(arc != NULL)
//    {
//        fwrite(&harcodeo,sizeof(int),1,arc);
//        printf("el archivo binario se creo con exito!\n");
//    }
//    fclose(arc);
//    return 0;


}

eVehiculo* vehiculo_new()
{
    eVehiculo* p = (eVehiculo*)malloc(sizeof(eVehiculo));
    if(p != NULL)
    {
        p->id = 0;
        *(p->marca) = '\0';
        p->peso= 0;
        p->tipo = 0;
    }
    return p;
}

eVehiculo* vehiculo_new_param(int id, char marca[], int tipo, float peso)
{
    eVehiculo* p = vehiculo_new();
    if(p != NULL && !(vehiculoSetID(p,id) && vehiculoSetMarca(p, marca) && vehiculoSetTipo(p, tipo) && vehiculoSetPeso(p, peso)))
    {
        free(p);
        p = NULL;
    }
    return p;
}


int vehiculoSetID(eVehiculo* p, int id)
{
    int retorno = 0;

    if(p != NULL && id >= 1 && id <= 100)
    {
        p->id = id;
        retorno = 1;
    }

    return retorno;
}

int vehiculoSetMarca(eVehiculo* p, char marca[])
{
    int retorno = 0;
    int nombreNumero;
    int maxCadena = 20;
    if(p != NULL && (int)strlen(marca) > 0)
    {
        nombreNumero = (int)strlen(marca);
        if(nombreNumero < maxCadena)
        {
            strcpy(p->marca, marca);
            strlwr(p->marca);//funcion que convierte la cadena en minusculas
            p->marca[0] = toupper(p->marca[0]);//convertimos el primer elemento en mayuscula
            retorno = 1;
        }
    }
    return retorno;
}

int vehiculoSetTipo(eVehiculo* p, int tipo)
{
    int retorno = 0;
    if(p != NULL && tipo > 0)
    {
        p->tipo = tipo;
        retorno = 1;
    }
    return retorno;
}

int vehiculoSetPeso(eVehiculo* p, float peso)
{
    int retorno = 0;

    if(p != NULL && peso > 0)
    {
        p->peso = peso;
        retorno = 1;
    }
    return retorno;
}
