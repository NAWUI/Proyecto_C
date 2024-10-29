#ifndef LISTAD__TURNO_H_INCLUDED
#define LISTAD__TURNO_H_INCLUDED


#include <stdlib.h>
#include <stdio.h>
#include "turno.h"

struct nodo
{
    Turno vipd;
    struct  nodo *next;
};

typedef struct nodo Nodo;


typedef struct
{
    Nodo *acc;  // Acceso al primer nodo
    Nodo *cur;  // Cursor actual
    Nodo *aux;  // Cursor auxiliar (anterior al actual)
} Lista;

void init(Lista *l)
{
    l->acc = NULL;
    l->cur = NULL;
    l->aux = NULL;
}

void resetL(Lista *l){
    l->cur=l->acc;
    l->aux=l->acc;
}

void insertL (Lista *l, Turno a){
    Nodo *nuevo=(Nodo*)malloc(sizeof(Nodo));

            if((l->cur)==(l->acc)){
                l->acc=nuevo;
                (*nuevo).next=l->cur;
                l->cur=l->acc;
                l->aux=l->acc;
            }else{
                l->aux->next = nuevo;
                (*nuevo).next=l->cur;
                l->cur=nuevo;
            }
            l->cur->vipd=a;
}
Turno is_copy(Lista *l){
    return l->cur->vipd;
}

int is_emptys(Lista *l)
{
    return l->acc == NULL;
}

int is_Full(Lista l){
    Nodo *X=(Nodo*)malloc(sizeof(Nodo));
        if (X==NULL){
            return 1;
        }else{
            free((void*)X);
            return 0;
        }
}

int is_Oos(Lista l){
    if(l.cur==NULL){
        return 1;
    }else{
        return 0;
    }
}

void forwards(Lista *l)
{
    l->aux = l->cur;
    l->cur = l->cur->next;
}

void suppress(Lista *l)
    {
        if (l->cur == l->acc)
        {
            l->acc = l->cur->next;
            free(l->cur);
            l->cur = l->acc;
            l->aux = l->acc;

        }
        else
        {
            l->aux->next = l->cur->next;
            free(l->cur);
            l->cur = l->aux->next;
        }

    }
/*
void imprimir(Lista l){
    Nodo *actual =l.acc;
    while(actual != NULL){
        printf("nuevo\n");
        actual = actual->next;
    }
}
*/


#endif // LISTAD__TURNO_H_INCLUDED
