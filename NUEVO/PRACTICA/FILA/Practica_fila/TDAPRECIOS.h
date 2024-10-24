#ifndef TDAPRECIOS_H_INCLUDED
#define TDAPRECIOS_H_INCLUDED

#include <string.h>
#include <stdlib.h>
//struct
typedef struct{
    int N_pro;
    float price;
}productos;
//init
void Init (productos *a){
    a->N_pro = 0;
    a->price = 0.0;
}
//sets
void Set_N_pro (productos *a,int num_pro){
    a->N_pro = num_pro;
}

void Set_price (productos *a,float price_pro){
    a->price = price_pro;
}
//modifis
void mod_numP(productos *a,int num_pro){
    Set_N_pro(a,num_pro);
}

void mod_price(productos *a,float price_pro){
    Set_price(a,price_pro);
}
//gets
int Get_N_pro (productos a){
    return a.N_pro;
}

float Get_price (productos a){
    return a.price;
}

#endif // TDAPRECIOS_H_INCLUDED
