#include <stdio.h>
#include <ctype.h>

int main() {
    char nomeArquivoEntrada[100];
    char nomeArquivoSaida[100];
    FILE *arquivoEntrada;
    FILE *arquivoSaida;
    char ch;
    
    // Solicita o nome do arquivo de entrada ao usuário
    printf("Digite o nome do arquivo de entrada: ");
    fgets(nomeArquivoEntrada, 100, stdin);
    
    // Remove a quebra de linha do nome do arquivo de entrada
    if (nomeArquivoEntrada[strlen(nomeArquivoEntrada) - 1] == '\n')
        nomeArquivoEntrada[strlen(nomeArquivoEntrada) - 1] = '\0';
    
    // Abre o arquivo de entrada em modo de leitura
    arquivoEntrada = fopen(nomeArquivoEntrada, "r");
    
    // Verifica se o arquivo de entrada foi aberto corretamente
    if (arquivoEntrada == NULL) {
        printf("Erro ao abrir o arquivo de entrada.\n");
        return 1;
    }
    
    // Solicita o nome do arquivo de saída ao usuário
    printf("Digite o nome do arquivo de saída: ");
    fgets(nomeArquivoSaida, 100, stdin);
    
    // Remove a quebra de linha do nome do arquivo de saída
    if (nomeArquivoSaida[strlen(nomeArquivoSaida) - 1] == '\n')
        nomeArquivoSaida[strlen(nomeArquivoSaida) - 1] = '\0';
    
    // Abre o arquivo de saída em modo de escrita
    arquivoSaida = fopen(nomeArquivoSaida, "w");
    
    // Verifica se o arquivo de saída foi aberto corretamente
    if (arquivoSaida == NULL) {
        printf("Erro ao abrir o arquivo de saída.\n");
        return 1;
    }
    
    // Lê o arquivo de entrada caractere por caractere e escreve no arquivo de saída com as vogais substituídas por '*'
    while ((ch = fgetc(arquivoEntrada)) != EOF) {
        ch = tolower(ch);  // Converte o caractere para minúsculo
        
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            ch = '*';
        
        fputc(ch, arquivoSaida);
    }
    
    // Fecha os arquivos
    fclose(arquivoEntrada);
    fclose(arquivoSaida);
    
    printf("Arquivo de saída criado com sucesso.\n");
    
    return 0;
}