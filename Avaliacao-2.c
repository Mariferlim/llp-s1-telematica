#include <stdio.h>

void  SomarM (int *matrizA, int *matrizB, int *matrizC) {
    int i, j;
    for (i = 0 ; i < 3; i++) {
        for (j = 0 ; j < 3; j++) {
           *(matrizC + i * 3 + j) = *(matrizA + i * 3 + j) + *(matrizB + i * 3 + j) ;
        }
    }
}

void  resultado (int *mat) {
    int i, j;
    for (i = 0 ; i < 3; i++) {
        for (j = 0 ; j < 3; j++) {
            printf ("%3d" ,*(mat + i * 3 + j));
        }
      printf ("\n");
    }
}


int  main () {

   	int matrizA[3][3] = {{ 2 , 4 , 6 }, { 3 , 5 , 9 }, { 8 , 7 , 1 }};
    int matrizB[3][3] = {{ 7 , 5 , 2 }, { 8 , 1 , 4 }, { 9 , 6 , 3 }};
    int matrizC[3][3];

   

    SomarM ((int *)matrizA, (int *)matrizB, (int *)matrizC);

    printf ("\n Matriz C: \n");
    resultado ((int *)matrizC);

    return  0 ;
}