#include <stdio.h>
#include <stdlib.h>

int main()
{
#include<stdio.h>
int calcula (int, int); /* Prototipo */
void main(){
int a1,a2, a3;
printf("Ingrese Numero entero mayor a 0: ");
scanf("%d", &a1);
printf("Ingrese Numero entero mayor a 0: ");
scanf("%d", &a2);
a3=calcula(a1,a2);
printf("El resultado es: %d\n",a3);
getchar();
}
int calcula (int x, int y){
int cont=0;
if (x<y) return cont;
else {
while (x>=y)
{ cont++ ;
x - = y; };
}
return cont;
}
