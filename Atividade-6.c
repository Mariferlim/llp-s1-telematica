#include <stdio.h>
#include <stdlib.h>

int** alocarMatriz(int linhas, int colunas) {
    int** matriz = (int**)malloc(linhas * sizeof(int*));
    for (int i = 0; i < linhas; i++) {
        matriz[i] = (int*)malloc(colunas * sizeof(int));
    }
    return matriz;
}

void liberarMatriz(int** matriz, int linhas) {
    for (int i = 0; i < linhas; i++) {
        free(matriz[i]);
    }
    free(matriz);
}

void inicializarMatriz(int** matriz, int linhas, int colunas, int* valores) {
    int k = 0;
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            matriz[i][j] = valores[k];
            k++;
        }
    }
}

void somarMatrizes(int** matrizA, int** matrizB, int** matrizC, int linhas, int colunas) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            matrizA[i][j] = matrizB[i][j] + matrizC[i][j];
        }
    }
}

void exibirMatriz(int** matriz, int linhas, int colunas) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    int linhas = 3;
    int colunas = 3;

    int valoresB[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int valoresC[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};

    int** matrizA = alocarMatriz(linhas, colunas);
    int** matrizB = alocarMatriz(linhas, colunas);
    int** matrizC = alocarMatriz(linhas, colunas);

    inicializarMatriz(matrizB, linhas, colunas, valoresB);
    inicializarMatriz(matrizC, linhas, colunas, valoresC);

    somarMatrizes(matrizA, matrizB, matrizC, linhas, colunas);

    printf("Matriz A:\n");
    exibirMatriz(matrizA, linhas, colunas);

    printf("Matriz B:\n");
    exibirMatriz(matrizB, linhas, colunas);

    printf("Matriz C:\n");
    exibirMatriz(matrizC, linhas, colunas);

    liberarMatriz(matrizA, linhas);
    liberarMatriz(matrizB, linhas);
    liberarMatriz(matrizC, linhas);

    return 0;
}