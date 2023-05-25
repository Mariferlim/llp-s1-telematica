#include <stdlib.h>

typedef struct {
    int dia;
    char mes[30];
    int ano;
    
} Data;

int main() {
    Data data;

    
    printf("Informe o Dia: ");
    scanf("%d", &data.dia);
  
    printf("Informe o Mes: ");  
    scanf("%s", *&data.mes);
  
    printf("Informe o Ano: ");  
    scanf("%d", &data.ano);


    
  
    FILE *arquivo = fopen("dados.txt", "w");
      
  if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    fprintf(arquivo, "Dia: %d\n", data.dia);
    fprintf(arquivo, "Mes: %s\n", data.mes);
    fprintf(arquivo, "Ano: %d", data.ano);
    
    
    

    fclose(arquivo);

    printf("Estrutura gravada no arquivo com sucesso.\n");

    return 0;
}