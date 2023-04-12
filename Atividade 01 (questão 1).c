#include <stdio.h>

int main () {
	int matriz[3][3] = {{3, 5, 1}, {2, 4, 7}, { 1, 8, 1}};

	int i, j;
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++) {
			if (i==j)
				printf("matriz[%d][%d]=%d ",i, j, matriz[i][j]);
		}
		  printf("\n");


 	 return 0;
  }