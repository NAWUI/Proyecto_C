#include <stdio.h>
#include <stdlib.h>

int main()
{
    float numero1 = 7.3;
    float numero2;
    float *fPtr;

    fPtr = &numero1;

    numero2 = *fPtr;

    printf("%f", numero2);

}
