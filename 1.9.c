#include <stdio.h>

/* Estancia
El programa, al recibir como dato la superficie de estancia expresada
en acres, la convierte a hectareas.

ECA: vatiable de tipo real*/

int main(void)
{
    float ECA;
    printf("ingrese la extensión de la estancia: ");
    scanf("%f", &ECA);
    ECA = ECA * 4047 / 10000;
    printf("\nExtensión de la estancia en hectareas: %5.2f", ECA);
    return 0;
}
