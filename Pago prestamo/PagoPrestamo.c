#include <stdio.h>

// Funcion para calcular el pago de un prestamo de interes simple*//

float calcularPagoRestante(float capital, float interes_anual, int tiempo, float pago_actual)
{
    float interes_total = capital * (interes_anual /100) * tiempo;
    float saldo_pendiente = capital + interes_total - pago_actual;
    return saldo_pendiente;
}
int main()
{
    int opcion;
    float capital, interes_anual, pago_actual = 0;
    int tiempo;
    FILE *archivo;
    do
    {
        printf("\n*** Menu ***\n");
        printf("0. Salir\n");
        printf("1. Cambio de parametros\n");
        printf("2. Calcular pago restante\n");
        printf("3. Realizar pago\n");
        printf("4. Guardar en archivo txt\n");
        printf("Ingrese su opcion");
        scanf("%d", &opcion);
        switch(opcion)
        {
            case 0:
            printf("Saliendo del programa.\n");
            break;
            case 1:
                printf("Ingrese el capital:  ");
                scanf("%f", &capital);
                printf("Ingrese el interes anual (en porcentaje): ");
                scanf("%f", &interes_anual);
                printf("Ingrese el tiempo a pagar (en años): ");
                scanf("%d", &tiempo);

                break;
            case 2:
                printf("El pago restante del prestamo es %.2f\n", calcularPagoRestante(capital, interes_anual, tiempo, pago_actual));

                break;
            case 3:
                printf("Ingrese el monto del pago: ");
                float pago;
                scanf("%f", &pago);
                if(pago <= calcularPagoRestante(capital, interes_anual, tiempo, pago_actual));
              {
                 pago_actual += pago;
                  printf("Pago realizado correctamente.\n");
              }
                else
                {
                    printf("El monto de pago excede el saldo pendiente del prestamo. \n");
                }

                break;
            case 4:
                archivo=fopen("prestamo.txt", "w");
                if (archivo == NULL)
                {
                    printf("Error al abrir el archivo.\n");
                }
                else
                {
                    fprintf(archivo, "Capital: %.2f\n", capital);
                    fprintf(archivo, "Interes anual: %.f%%\n", interes_anual);
                    fprintf(archivo, "Tiempo a pagar: %d años\n", tiempo);
                    fprintf(archivo, "Pago total realizado: %.2f\n", pago_actual);
                    fprintf(archivo, "Pago restante del prestamo: %.2f\n", calcularPagoRestante(capital, interes_anual, tiempo, pago_actual));
                    fclose(archivo);
                    printf("Datos guardados en prestamo.txt\n");
                }
                break;
            default:
                printf("Opcion no valida. Por favor, intente de nuevo.\n");
                break;
        }
    }
    while(opcion != 0);
    return 0;
}
