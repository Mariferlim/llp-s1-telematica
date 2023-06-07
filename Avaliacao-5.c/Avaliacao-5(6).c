#include <stdio.h>
#include <ctype.h>

int main() {
    char nomeArquivo[100];
    FILE *arquivo;
    int contadorLetras[26] = {0};  
    char ch;

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
        ch = tolower(ch);  
        
        if (isalpha(ch)) {
            int indice = ch - 'a';  
            
            contadorLetras[indice]++;
        }
    }
    

    fclose(arquivo);
    

    printf("Contagem de letras:\n");
    
    for (int i = 0; i < 26; i++) {
        char letra = 'a' + i; 
        
        printf("%c: %d\n", letra, contadorLetras[i]);
    }
    
    return 0;
}