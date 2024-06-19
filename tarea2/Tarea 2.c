#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int num1, num2, userNum1, userNum2, choice;
    float betAmount;
    srand(time(NULL));  // Inicializa el generador de numeros aleatorios//

    num1 = rand() % 41;
    num2 = rand() % 41;  // Generar dos numeros aleatorios entre 0 y 40//

    printf("Bienvenido al juego de loteria!\n");
    printf("1 - Jugar con un numero\n");
    printf("2 - Jugar con dos numeros\n");
    printf("Seleccione una opcion: ");
    scanf("%d", &choice);

    if (choice == 1)
        {
            printf("Ingrese su numero (0-40): ");
    scanf("%d", &userNum1);
    printf("Ingrese la cantidad de dinero que quiere jugar: ");
    scanf("%f", &betAmount);

    if (userNum1 == num1 || userNum2 == num2)
    {
        printf("Felicidades! Usted ha ganado $%.2f\n", betAmount * 2);
    }
    else
    {
        printf("Lo siento, usted a perdido. Los numeros ganadores eran %d y %d\n", num1, num2);
    }
        }
        else if (choice == 2)
        {
            printf("Ingrese su primer numero (0-40): ");
            scanf("%d", &userNum1);
            printf("Ingrese su segundo numero (0-40): ");
            scanf("%d", &userNum2);
            printf("Ingrese la cantidad de dinero que quiere jugar : ");
            scanf("%f", &betAmount);

            if ((userNum1 == num1 || userNum1 == num2) && (userNum2 == num1 || userNum2 == num2))
            {
                printf("Felicidades! Usted ha ganado $%.2f\n", betAmount *4);
            }
            else if (userNum1 == num1 || userNum1 == num2 || userNum2 == num1 || userNum2 == num2)
            {
                printf("Felicidades! Usted ha ganado $%.2f\n", betAmount * 2);
            }
            else
            {
                printf("Lo siento, usted ha perdido. Los numeros ganadores eran %d y %d\n", num1, num2);
            }
        }
        else
        {
            printf("Opcion invalida.\n");
        }

        return 0;
}
