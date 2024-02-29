#include <stdio.h>

/* Arreglo sin elementos repetidos.
El programa, al recibir como datos un arreglo unidimensional desordenado de N
elementos, ontiene como salida ese mismo arreglo pero sin los elementos repetidos. */

void Lectura(int *, int);
void Imprime(int *, int);
void Elimina(int *, int);
/* Observa que en el prototipo de Elimina, el segundo parametro es por referencia.
Esto, porque el tama�o del arreglo puede disminuir. */

void main(void)
{
    int TAM, ARRE[100]; /* Se escribe un do-while para verificar que el tama�o del
    arreglo que se ingresa sea correcto. */

    do
    {
        printf("Ingrese el tama�o del arreglo: ");
        scanf("%d", &TAM);
    }
    while (TAM > 100 || TAM < 1);
    Lectura(ARRE, TAM);
    elimina(ARRE, &TAM); /* Observa que el tama�o del arreglo se pasa por referencia. */
    Imprime(ARRE, TAM);
}

void Lectura(int A[], int T) /* La funcion Lectura se utiliza para leer un arreglo unidimensional
de T elementos de tipo entero. */
{
    printf("\n");
    int I;
    for (I = 0; I < T; I++)
    {
        printf("Ingrese el elemento %d: ", I + 1);
        scanf("%d", &A[I]);
    }
}

void Imprime(int A[], int T) /* La funcion Imprime se utiliza para escribir un arreglo unidimensional,
sin repeticiones, de T elementos de tipo entero. */

{
    int I;
    for (I = 0; I < T; I++)
    printf("\nA[%d]: %d", I, A[I]);
}

void elimina(int A[], int *T) /* Esta funcion se utiliza para eliminar elementos repetidos de un arreglo
unidimensional de T elementos de tipo entero. */

{
    int I = 0, K, L;
    while (I < (*T-1))
    {
        K = I + 1;
        while (K <=  (*T-1))
        {
            if (A[I] == A[K])
            {
                for (L = K; L < (*T-1); L++)
                    A[L] = A[L + 1];
                *T = *T - 1;
            }
            else
                K++;
        }
        I++;
    }
}
