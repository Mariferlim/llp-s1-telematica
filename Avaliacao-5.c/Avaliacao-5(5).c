#include <stdio.h>

int main() {
    char nomeArquivo[100];
    char caractere;
    FILE *arquivo;
    char ch;
    int contadorCaractere = 0;
    
    printf("Digite o nome do arquivo: ");
    fgets(nomeArquivo, 100, stdin);
    
    if (nomeArquivo[strlen(nomeArquivo) - 1] == '\n')
        nomeArquivo[strlen(nomeArquivo) - 1] = '\0';
    
    arquivo = fopen(nomeArquivo, "r");
    
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }
    
    printf("Digite o caractere: ");
    scanf("%c", &caractere);
    
    while ((ch = fgetc(arquivo)) != EOF) {
        if (ch == caractere)
            contadorCaractere++;
    }
    
    fclose(arquivo);
    
    printf("O caractere '%c' ocorre %d vezes no arquivo.\n", caractere, contadorCaractere);
    
    return 0;
}