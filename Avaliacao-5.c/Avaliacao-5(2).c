#include <stdio.h>

int main() {
    char nomeArquivo[100];
    FILE *arquivo;
    char ch;
    int numeroLinhas = 0;
    
    printf("Digite o nome do arquivo: ");
    fgets(nomeArquivo, 100, stdin);
    
    if (nomeArquivo[strlen(nomeArquivo) - 1] == '\n')
        nomeArquivo[strlen(nomeArquivo) - 1] = '\0';
    
    arquivo = fopen(nomeArquivo, "r");
    
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }
    
    while ((ch = fgetc(arquivo)) != EOF) {
        if (ch == '\n')
            numeroLinhas++;
    }
    
    fclose(arquivo);
    
    printf("O arquivo possui %d linhas.\n", numeroLinhas);
    
    return 0;
}