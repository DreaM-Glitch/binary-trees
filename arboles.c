
#include <stdlib.h>
#include <stdio.h>
#include "string.h"

///ESTRUCTURAS ARBOL BINARIO DE BUSQUEDA

typedef struct
{
    int legajo;
    char nombre[20];
    int edad;
} persona;

typedef struct
{
    persona dato;
    struct nodoArbol * izquierda;
    struct nodoArbol * derecha;
} nodoArbol;

///ESTRUCTURA PARA EL MANEJO DE LA LISTA SIMPLEMENTE ENLAZADA
typedef struct
{
    persona dato;
    struct nodo* siguiente;
} nodo;
///PROTOTIPADO DE FUNCIONES PARA CARGAR ESTRUCTURA.
persona cargarPersonas();

///PROTOTIPADO FUNCIONES ARBOLES BINARIOS DE BUSQUEDA (ABB).
nodoArbol* inicArbol();
nodoArbol* crearNodoArbol(persona a);
nodoArbol * insertar(nodoArbol* arbol, persona a);
nodoArbol* buscaLegajo(nodoArbol* arbol, int legajo, nodoArbol* aux);
nodoArbol* buscaNombre(nodoArbol* arbol, char nombre[], nodoArbol* aux);

///PROTOTIPADO DE FUNCIONES DE LISTAS SIMPLEMENTE ENLAZADA
nodo* iniclista();
nodo* crearNodo(persona a);
nodo* agregarPrincipio(nodo*lista, nodo* nuevonodo);
nodo* agregarFinal(nodo* lista, nodo* nuevo);
nodo* pasarALista(nodoArbol* arbol, nodo* lista);



///PROTOTIPADO FUNCIONES VOID.
void inorden(nodoArbol *arbol);
void escribir(nodo* aux);
void recorrerYmostrar(nodo* lista);
void mostrarPersona(persona personita);

///PROTOTIPADO FUNCIONES INT.
int retornarLegajo(nodoArbol* arbol, int legajo);
int calculaAltura(nodoArbol* arbol);
int cantidadHojas(nodoArbol* arbol);



int main ()
{
    persona personita;
    int opc, legajo,respuesta, altura, hojas;
    nodoArbol * arbol = inicArbol();
    nodoArbol * aux;
    nodoArbol * aux2;
    nodo* lista = iniclista();
    char eleccion = 's', nombre[20];

    printf("-------------------------ELIJA UNA OPCION-----------------------\n");
    fflush(stdin);
    scanf("%d", &opc);


    switch(opc)
    {
    case 1:
        while(eleccion=='s')
        {
            personita = cargarPersonas();
            arbol = insertar(arbol, personita);
            printf("Desea cargar otra persona en el arbol? (s/n)\n");
            fflush(stdin);
            scanf(" %c", &eleccion);
        }

        inorden(arbol);



        break;

    case 2:
        while(eleccion=='s')
        {
            personita = cargarPersonas();
            arbol = insertar(arbol, personita);
            printf("Desea cargar otra persona en el arbol? (s/n)\n");
            fflush(stdin);
            scanf(" %c", &eleccion);
        }

        inorden(arbol);

        break;

    case 3:
        while (eleccion == 's')
        {
            personita = cargarPersonas();
            arbol = insertar(arbol, personita);
            lista = pasarALista(arbol, lista);
            printf("desea cargar otra persona al arbol? \n");
            fflush(stdin);
            scanf(" %c", &eleccion);

        }
        recorrerYmostrar(lista);

        break;

    case 4:
        while(eleccion=='s')
        {
            personita = cargarPersonas();
            arbol = insertar(arbol, personita);
            printf("desea cargar otra persona al arbol? \n");
            fflush(stdin);
            scanf(" %c", &eleccion);
        }
        printf("ingrese el legajo a buscar en el arbol\n");
        fflush(stdin);
        scanf("%i", &legajo);

        aux = buscaLegajo(arbol, legajo, aux);

        if(aux != NULL)
        {
            printf("\nNODO DE DICHO LEGAJO: \n");
            mostrarPersona(aux->dato);
        }
        else
        {

            printf("DICHO LEGAJO NO SE ENCUENTRA DENTRO DEL ARBOL\n");
        }



        break;

    case 5:
        while(eleccion=='s')
        {
            personita = cargarPersonas();
            arbol = insertar(arbol, personita);
            printf("desea cargar otra persona al arbol? \n");
            fflush(stdin);
            scanf(" %c", &eleccion);
        }
        printf("ingrese el nombre a buscar en el arbol: \n");
        fflush(stdin);
        gets(nombre);
        aux2 = buscaNombre(arbol, nombre, aux);

        if(aux2!=NULL)
        {
            mostrarPersona(aux2->dato);
        }
        else
        {
            printf("la persona no existe.\n");
        }

        break;


    case 6:
          while(eleccion=='s')
        {
            personita = cargarPersonas();
            arbol = insertar(arbol, personita);
            printf("desea cargar otra persona al arbol? \n");
            fflush(stdin);
            scanf(" %c", &eleccion);
        }

        altura = calculaAltura(arbol);
        printf("la altura del arbol es: %i\n", altura);


        break;

    case 7:

        break;

    case 8:
         while(eleccion=='s')
        {
            personita = cargarPersonas();
            arbol = insertar(arbol, personita);
            printf("desea cargar otra persona al arbol? \n");
            fflush(stdin);
            scanf(" %c", &eleccion);
        }
         hojas = cantidadHojas(arbol);
         printf("La cantidad de nodos hoja en el arbol son: %i\n", hojas);

        break;


    }



    return 0;
}



///--------------------------------------------FUNCIONES--------------------------------------------------


///hacer una función que muestre el contenido de un ABB de números enteros de manera ordenada (menor a mayor), considerar cuál recorrido es el más conveniente.
void inorden(nodoArbol *arbol)
{
    if (arbol!=NULL)
    {

        inorden(arbol->izquierda);
        printf("El LEGAJO DE LA PERSONA ES: %i\n", arbol->dato.legajo);
        printf("EL NOMBRE DE LA PERSONA ES: %s\n", arbol->dato.nombre);
        printf("LA EDAD DE LA PERSONA ES: %i\n", arbol->dato.edad);
        inorden(arbol->derecha);

    }
}
///Codifique las funciones básicas correspondientes al ABB (de personas).
persona cargarPersonas()
{
    persona a;


    printf("ingrese el legajo de la persona: \n");
    fflush(stdin);
    scanf("%i", &a.legajo);
    printf("ingrese la edad de la persona: \n");
    fflush(stdin);
    scanf("%i", &a.edad);
    printf("ingrese el nombre de la persona: \n");
    fflush(stdin);
    gets(a.nombre);




    return a;
}


///PUNTO 1
nodoArbol* inicArbol()
{
    return NULL;
}
nodoArbol* crearNodoArbol(persona a)
{

    nodoArbol * aux = (nodoArbol*)malloc(sizeof(nodoArbol));
    aux->dato.legajo = a.legajo;
    strcpy( a.nombre,aux->dato.nombre);
    aux->dato.edad = a.edad;
    aux->izquierda = NULL;
    aux->derecha = NULL;
    return aux;
}


nodoArbol * insertar(nodoArbol* arbol, persona a)
{
    if(arbol==NULL)
    {
        arbol = crearNodoArbol(a);
    }
    else
    {

        if(a.legajo<arbol->dato.legajo)
        {
            arbol->izquierda = insertar(arbol->izquierda,a);
        }
        else
        {
            arbol->derecha = insertar(arbol->derecha,a);
        }
    }
    return arbol;
}


///PUNTO 2

//void inorden(nodoArbol *arbol)
//{
//    if (arbol!=NULL)
//    {
//
//        inorden(arbol->izquierda);
//        printf("-%i-", arbol->dato.legajo);
//        inorden(arbol->derecha);
//
//    }
//}

///-------------------------------FUNCIONES LISTAS SIMPLEMENTE ENLAZADAS--------------------------
///PUNTO 3
nodo* iniclista()
{
    return NULL;
}

nodo* crearNodo(persona a)
{
    nodo* aux = (nodo*)malloc(sizeof(nodo));
    aux->dato.legajo = a.legajo;
    aux->dato.edad = a.edad;
    strcpy(a.edad,aux->dato.edad);
    aux->siguiente = NULL;

    return aux;
}

nodo* agregarPrincipio(nodo*lista, nodo* nuevonodo)
{
    if(lista==NULL)
    {
        lista = nuevonodo;
    }

    if(lista!=NULL)
    {
        nuevonodo->siguiente = lista;
        lista = nuevonodo;
    }
    return lista;
}

nodo* agregarFinal(nodo* lista, nodo* nuevo)
{
    nodo* aux = lista;
    if(aux)
    {
        while(aux->siguiente)
        {
            aux = aux->siguiente;
        }
        aux->siguiente = nuevo;
    }
    else
    {
        lista = nuevo;
    }

    return lista;
}

nodo* pasarALista(nodoArbol* arbol, nodo* lista)
{
    nodo* nodoAux;
    nodoArbol* aux = arbol;
    if(aux!=NULL)
    {
        lista = pasarALista(aux->izquierda, lista);
        nodoAux = crearNodo(arbol->dato);
        lista = agregarFinal(lista, nodoAux);
        lista = pasarALista(aux->derecha, lista);
    }
    return lista;
}


void recorrerYmostrar(nodo* lista)
{
    nodo* seguidora = lista;

    while(seguidora!=NULL)
    {
        escribir(seguidora);
        seguidora = seguidora->siguiente;

    }

}


void escribir(nodo* aux)
{
    printf("el legajo de la persona es: %i\n", aux->dato.legajo);
    printf("la edad de la persona es: %i\n", aux->dato.edad);
    printf("el nombre de la persona es: %s \n", aux->dato.nombre);

}


///PUNTO 4
nodoArbol* buscaLegajo(nodoArbol* arbol, int legajo, nodoArbol* aux)
{
    if(arbol)
    {
        aux = buscaLegajo(arbol->izquierda, legajo, aux);
        aux = buscaLegajo(arbol->derecha, legajo, aux);

        if (arbol->dato.legajo == legajo)
        {
            aux = arbol;
        }
    }
    return aux;
}

void mostrarPersona(persona personita)
{
    printf("NOMBRE: %s\n", personita.nombre);
    printf("EDAD: %i\n", personita.edad);
    printf("LEGAJO: %i\n\n", personita.legajo);

}



///PUNTO 5


nodoArbol* buscaNombre(nodoArbol* arbol, char nombre[], nodoArbol* aux)
{
    if(arbol!=NULL)
    {
        aux = buscaNombre(arbol->izquierda, nombre, aux);
        aux = buscaNombre(arbol->derecha, nombre, aux);

        if(strcmp(nombre, arbol->dato.nombre) == 0)
        {
            aux = arbol;
        }
    }

    return aux;
}

///PUNTO 6
int calculaAltura(nodoArbol* arbol)
{
    int i = 0;
    int alturaIzq = 0;
    int alturaDer = 0;
    if(arbol!=NULL)
    {
        i++;
        if(arbol->izquierda!=NULL)
        {
            alturaIzq += calculaAltura(arbol->izquierda);
        }
        if(arbol->derecha!=NULL)
        {
            alturaDer += calculaAltura(arbol->derecha);
        }
        if(alturaDer < alturaIzq)
        {
            i += alturaIzq;
        }
        else
        {
            i += alturaDer;
        }
    }
    return i;
}

///PUNTO 7



///PUNTO 8
int cantidadHojas(nodoArbol *arbol)
{
if (arbol==NULL)
{
return 0; ///esto quiere decir que el arbol esta vacio. por lo tanto no tiene hojas

}
else if (arbol->izquierda == NULL && arbol->derecha==NULL)
{
return 1; /// esto quiere decir que el nodo es una hoja

}

int hojaIzquierda = cantidadHojas(arbol->izquierda);
int hojaDerecha = cantidadHojas (arbol->derecha);

return hojaIzquierda + hojaDerecha;
}
