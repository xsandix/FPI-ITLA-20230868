#include <stdio.h>

struct Prestamo // Se crea una estructura para agrupar los parametros del prestamo.//
{
    float cantidad;
    float tasa;
    int tiempo;
};

float calcularPagoMensual(struct Prestamo prestamo) // Se calcula el pago mensual del prestamo utilizando la formula de amortizacion que es: p= cantidad * interes/ 1-(1+interes) elevado al tiempo.//
{
    return (prestamo.cantidad * prestamo.tasa) / (1 - 1 / (pow(1 + prestamo.tasa, prestamo.tiempo)));
}

void imprimirTablaAmortizacion(struct Prestamo prestamo)//Declaracion de la funcion para imprimir la tabla.//
 {
    float saldo = prestamo.cantidad; // Declaracion de la variable para ir viendo el saldo restante a medida de que se paga.//
    float pago_mensual = calcularPagoMensual(prestamo); //Calcula el pago mensual y lo guarda en la variable pago_mensual.//
    printf("Mes\tPago\tInteres\t\tCapital\t\tSaldo\n"); //Impresion de la enumeracion de las columnas.//
    for (int mes = 1; mes <= prestamo.tiempo; mes++) //Se inicia un bucle que va desde el mes 1 hasta los meses restantes del prestamo.//
        {
        float interes = saldo * prestamo.tasa; //Calcula el interes.//
        float capital = pago_mensual - interes; //Calcula el capital.//
        saldo -= capital;//Tipo de actualizacion restando el capital pagado en un tiempo ára obtener el saldo restante despues del pago.//
        printf("%d\t%.2f\t%.2f\t\t%.2f\t\t%.2f\n", mes, pago_mensual, interes, capital, saldo);  //Imprime una linea en  la tabla de amortizacion con cada parametro establecido.//
    }
}

void guardarParametros(struct Prestamo prestamo) //Funcion para guardar los datos del prestamo en un archivo txt.//
 {
    FILE *archivo;
    archivo = fopen("parametros.txt", "w");
    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
    }
    fprintf(archivo, "%.2f %.2f %d", prestamo.cantidad, prestamo.tasa, prestamo.tiempo);
    fclose(archivo);
}

int main()
{
    struct Prestamo prestamo;
    int opcion;

    prestamo.cantidad = 10000;
    prestamo.tasa = 0.05;  // Se cargan los parametros predeterminados.//
    prestamo.tiempo = 12;

    do //Bucle do-while para que se ejecute el programa hasta que se seleccione 0-salir.//
        {
        printf("\nMenu:\n");
        printf("0 - Salir\n");
        printf("1 - Cambiar parametros\n");
        printf("2 - Calcular\n");
        printf("3 - Guardar parametros en archivo\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch(opcion) // Se usa un switch para realizar diferentes acciones segun la opcion seleccionada.//
        {
            case 0:
                printf("Saliendo del programa.\n");
                break;
           case 1:
                printf("Ingrese el monto del prestamo: ");
                scanf("%f", &prestamo.cantidad);
                printf("Ingrese la tasa de interes (porcentaje): ");
                scanf("%f", &prestamo.tasa);
                prestamo.tasa /= 100; // Convertir tasa a decimal
                printf("Ingrese el plazo en meses: ");
                scanf("%d", &prestamo.tiempo);
                break;
            case 2:
                printf("\nTabla de Amortizacion:\n");
                imprimirTablaAmortizacion(prestamo);
                break;
            case 3:
                guardarParametros(prestamo);
                printf("Parametros guardados en archivo.\n");
                break;
            default:
                printf("Opcion invalida. Por favor, seleccione una opcion valida.\n");
        }
    } while(opcion != 0);

    return 0;  //El programa se devuelve a 0 indicando que se ha terminado sin errores.//
}
