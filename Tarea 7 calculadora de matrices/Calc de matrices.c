#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Función para crear matriz dinámica */
int **crearMatriz(int filas, int cols) {
    int **matriz = (int **)malloc(filas * sizeof(int *));
    for (int i = 0; i < filas; i++)
        matriz[i] = (int *)malloc(cols * sizeof(int));
    return matriz;
}

/* Función para liberar memoria */
void liberarMatriz(int **matriz, int filas) {
    for (int i = 0; i < filas; i++)
        free(matriz[i]);
    free(matriz);
}

/* Leer matriz desde teclado */
void leerMatrizTeclado(int **matriz, int filas, int cols) {
    printf("Ingrese los valores de la matriz (%d x %d):\n", filas, cols);
    for (int i = 0; i < filas; i++)
        for (int j = 0; j < cols; j++)
            scanf("%d", &matriz[i][j]);
}

/* Leer matriz desde archivo CSV */
void leerMatrizArchivo(int **matriz, int filas, int cols, const char *nombreArchivo) {
    FILE *fp = fopen(nombreArchivo, "r");
    if (!fp) {
        printf("No se pudo abrir el archivo.\n");
        return;
    }
    char linea[1024];
    for (int i = 0; i < filas; i++) {
        if (fgets(linea, sizeof(linea), fp)) {
            char *token = strtok(linea, ",");
            for (int j = 0; j < cols && token != NULL; j++) {
                matriz[i][j] = atoi(token);
                token = strtok(NULL, ",");
            }
        }
    }
    fclose(fp);
}

/* Imprimir matriz */
void imprimirMatriz(int **matriz, int filas, int cols) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < cols; j++)
            printf("%d\t", matriz[i][j]);
        printf("\n");
    }
}

/* Operaciones */
int **sumarMatrices(int **A, int **B, int filas, int cols) {
    int **C = crearMatriz(filas, cols);
    for (int i = 0; i < filas; i++)
        for (int j = 0; j < cols; j++)
            C[i][j] = A[i][j] + B[i][j];
    return C;
}

int **restarMatrices(int **A, int **B, int filas, int cols) {
    int **C = crearMatriz(filas, cols);
    for (int i = 0; i < filas; i++)
        for (int j = 0; j < cols; j++)
            C[i][j] = A[i][j] - B[i][j];
    return C;
}

int **multiplicarMatrices(int **A, int filasA, int colsA, int **B, int filasB, int colsB) {
    if (colsA != filasB) {
        printf("No se pueden multiplicar: dimensiones incompatibles.\n");
        return NULL;
    }
    int **C = crearMatriz(filasA, colsB);
    for (int i = 0; i < filasA; i++)
        for (int j = 0; j < colsB; j++) {
            C[i][j] = 0;
            for (int k = 0; k < colsA; k++)
                C[i][j] += A[i][k] * B[k][j];
        }
    return C;
}

/* Programa principal */
int main() {
    int filas, cols;
    printf("Ingrese filas y columnas de la matriz: ");
    scanf("%d %d", &filas, &cols);

    int **A = crearMatriz(filas, cols);
    int **B = crearMatriz(filas, cols);

    int opcion;
    printf("¿Cómo desea ingresar las matrices?\n1. Teclado\n2. Archivo CSV\nOpción: ");
    scanf("%d", &opcion);

    if (opcion == 1) {
        leerMatrizTeclado(A, filas, cols);
        leerMatrizTeclado(B, filas, cols);
    } else {
        leerMatrizArchivo(A, filas, cols, "matrizA.csv");
        leerMatrizArchivo(B, filas, cols, "matrizB.csv");
    }

    printf("\nMatriz A:\n");
    imprimirMatriz(A, filas, cols);
    printf("\nMatriz B:\n");
    imprimirMatriz(B, filas, cols);

    int **C = sumarMatrices(A, B, filas, cols);
    printf("\nSuma de matrices:\n");
    imprimirMatriz(C, filas, cols);
    liberarMatriz(C, filas);

    C = restarMatrices(A, B, filas, cols);
    printf("\nResta de matrices:\n");
    imprimirMatriz(C, filas, cols);
    liberarMatriz(C, filas);

    C = multiplicarMatrices(A, filas, cols, B, filas, cols);
    if (C != NULL) {
        printf("\nMultiplicación de matrices:\n");
        imprimirMatriz(C, filas, cols);
        liberarMatriz(C, filas);
    }

    liberarMatriz(A, filas);
    liberarMatriz(B, filas);

    return 0;
}
