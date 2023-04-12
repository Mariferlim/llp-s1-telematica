#include <stdio.h>

int main() {
  int Matriz1[3][3] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
  int Matriz2[3][3] = {{4, 7, 2}, {3, 1, 9}, {6, 5, 8}};
  int Soma[3][3];

  int i, j;
    for (i = 0; i < 3; i++){
      for (j = 0; j < 3; j++){
        
        Soma[i][j] = Matriz1[i][j] + Matriz2[i][j];
        
        printf("matriz [%d][%d]:%d\n", i, j, Soma[i][j]);
      }
    }
return 0;
}