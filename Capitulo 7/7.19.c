#include <stdio.h>
#include <string.h>
#include <ctype.h>
/* Cuenta palabras.
El programa calcula el número de palabras que hay en la cadena de caracteres. */
int cuentap(char *);
int main(void)
{
    int i;
    char fra[50];
    printf("\nIngrese la línea de texto: ");
    gets(fra);
    /* Prototipo de función. */
    strcat(fra, " "); /* Se agrega un espacio en blanco al final de la ➥cadena. */
    i = cuentap(fra);
    printf("\nLa línea de texto tiene %d palabras", i);
    return 0;
}
int cuentap(char *cad)
{
    /* La función cuenta el número de palabras que hay en la cadena de ➥caracteres. */
    char *cad0 = "";
    int i = 0;
    cad0 = strstr(cad, " ");
    while (strcmp(cad, " "))
    {
        strcpy(cad, cad0);
        i++;
        cad0 = strstr(cad + 1, " ");
        /* Se busca un espacio en blanco a partir de la siguiente posición. */
    }
    return (i);
}