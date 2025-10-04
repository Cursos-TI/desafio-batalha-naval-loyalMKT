#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main() {
    
    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    char linha[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'}; // Definindo variável linha
    int tabuleiro[10][10]; // Matriz do tabuleiro

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            tabuleiro[i][j] = 0; // Preenchimento do tabuleiro com 0 (água)
        }
    }
    
    for (int i = 1; i < 4; i++) // Definição do local do navio 1
    {
        for (int j = 2; j < 5; j++) // Definição do local do navio 2
        {
            tabuleiro[5][j] = 3; // Implementação do navio horizontal
            tabuleiro[i][5] = 3; // Implementação do navio vertical
        }
    }
    
    for (int i = 0; i < 3; i++) // Definição do local do navio 3
    {
        for (int j = 0; j < 3; j++) // Definição do local do navio 4
        {
            tabuleiro[i][9 - i] = 3; // Implementação do navio na diagonal secundária
            tabuleiro[0 + j][j] = 3; // Implementação do navio na diagonal primária
        }
    }
    
    printf(" TABULEIRO BATALHA NAVAL\n"); // Título do tabuleiro

    printf("   "); // Espaçamento

    for (int i = 0; i < 10; i++)
    {
        printf("%c ", linha[i]); // Implementação da linha no tabuleiro
    }
    
    printf("\n"); // Espaçamento

    for (int i = 0; i < 10; i++)
    {
        printf("%2d ", i + 1); // Implementação da coluna numérica no tabuleiro, alocando 2 espaços para alinhamento das casas

        for (int j = 0; j < 10; j++)
        {
            printf("%d ", tabuleiro[i][j]); // Impressão do tabuleiro em si
        }
        printf("\n"); // Espaçamento para casas
    }
    

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    return 0;
}
