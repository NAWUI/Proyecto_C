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
}lista_de_turno;

void init_turno(lista_de_turno *l)
{
    l->acc = NULL;
    l->cur = NULL;
    l->aux = NULL;
}

void resetL_turno(lista_de_turno *l){
    l->cur=l->acc;
    l->aux=l->acc;
}

void insertL_turno(lista_de_turno *l, Turno a){
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
Turno copy_turno(lista_de_turno *l){
    return l->cur->vipd;
}

int is_emptys_turno(lista_de_turno *l)
{
    return l->acc == NULL;
}

int is_Full_turno(lista_de_turno l){
    Nodo *X=(Nodo*)malloc(sizeof(Nodo));
        if (X==NULL){
            return 1;
        }else{
            free((void*)X);
            return 0;
        }
}

int is_Oos_turno(lista_de_turno l){
    if(l.cur==NULL){
        return 1;
    }else{
        return 0;
    }
}

void forwards_turno(lista_de_turno *l)
{
    l->aux = l->cur;
    l->cur = l->cur->next;
}

void suppress_turno(lista_de_turno *l)
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

