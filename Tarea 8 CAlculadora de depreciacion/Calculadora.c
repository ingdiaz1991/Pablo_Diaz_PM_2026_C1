#include <stdio.h>
#include <stdlib.h>

/* Calculadora de depreciación de vehículos
   - Permite ingresar valor inicial, valor final y tiempo (años).
   - Genera tabla mensual de amortización.
   - Guarda resultados en archivo de texto.
*/

void generarTabla(double valorInicial, double valorFinal, int tiempoAnios, const char *archivo) {
    FILE *fp = fopen(archivo, "w");
    if (!fp) {
        printf("No se pudo crear el archivo.\n");
        return;
    }

    int meses = tiempoAnios * 12;
    double depreciacionMensual = (valorInicial - valorFinal) / meses;
    double valor = valorInicial;

    fprintf(fp, "Tabla de Amortización de Vehículo\n");
    fprintf(fp, "Valor inicial: %.2f\nValor final: %.2f\nTiempo: %d años (%d meses)\n\n",
            valorInicial, valorFinal, tiempoAnios, meses);
    fprintf(fp, "Mes\tValor\n");
    fprintf(fp, "-------------------\n");

    for (int i = 1; i <= meses; i++) {
        valor -= depreciacionMensual;
        fprintf(fp, "%d\t%.2f\n", i, valor);
    }

    fclose(fp);
    printf("Tabla generada en el archivo: %s\n", archivo);
}

int main() {
    double valorInicial, valorFinal;
    int tiempoAnios, opcion;

    printf("Seleccione opción:\n");
    printf("1. Ingresar valor inicial, valor final y tiempo\n");
    printf("2. Ingresar valor inicial y tiempo (valor final = 0)\n");
    scanf("%d", &opcion);

    if (opcion == 1) {
        printf("Ingrese valor inicial: ");
        scanf("%lf", &valorInicial);
        printf("Ingrese valor final: ");
        scanf("%lf", &valorFinal);
        printf("Ingrese tiempo en años: ");
        scanf("%d", &tiempoAnios);
    } else {
        printf("Ingrese valor inicial: ");
        scanf("%lf", &valorInicial);
        printf("Ingrese tiempo en años: ");
        scanf("%d", &tiempoAnios);
        valorFinal = 0.0;
    }

    generarTabla(valorInicial, valorFinal, tiempoAnios, "amortizacion.txt");

    return 0;
}
