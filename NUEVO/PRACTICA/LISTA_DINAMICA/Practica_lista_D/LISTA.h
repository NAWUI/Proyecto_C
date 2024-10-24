#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

struct nodo
{
    Persona vipd;
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

void insertL (Lista *l, int a){
    Nodo *nuevo=(Nodo*)malloc(sezeof(Nodo));

        if (aux != NULL){
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
            l->cur->vipd=a
        }
}
int is_copy(Lista l){
    return l->cur->vipd
}

int is_emptys(Lista *l)
{
    return l->acc == NULL;
}

int is_Full(Lista l){
    Nodo *X=()}
#endif // LISTA_H_INCLUDED
