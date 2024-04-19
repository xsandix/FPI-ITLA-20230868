#include <stdio.h>

/* Alumnos.
El programa lee bloques —variables de tipo estructura alumno— de un archivo
de acceso directo. */

typedef struct /* Declaración de la estructura alumno. */

{
    int matricula;
    char nombre[20];
    int carrera;
    float promedio;
} alumno;
void lee(FILE *); /* Prototipo de función. */
void main(void)
{
    FILE *ar;
    if ((ar = fopen("ad1.dat", "r")) != NULL)
        escribe(ar);
    else
        printf("\nEl archivo no se puede abrir");
    fclose(ar);
}
void lee(FILE *ap)
/* Esta función se utiliza para leer bloques de un archivo de acceso directo. */
{
    alumno alu;
    fread(&alu, sizeof(alumno), 1, ap);

    while (!feof(ap))
    {
        printf("\nMatrícula: %d", alu.matricula);
        printf("\tCarrera: %d", alu.carrera);
        printf("\tPromedio: %f\t ", alu.promedio);
        puts(alu.nombre);
        fread(&alu, sizeof(alumno), 1, ap);
    }
}