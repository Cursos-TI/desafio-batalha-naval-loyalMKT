#include <stdio.h>

#define TAMANHO_TABULEIRO 5

void desenharOctaedro(int tabuleiroOct[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]){ // Código do tabuleiro da habilidade do octaedro

    int centro = 2; // Centro da habilidade

    for (int i = 0; i < TAMANHO_TABULEIRO; i++)
    {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++)
        {
            tabuleiroOct[i][j] = 0; // Definindo tabuleiro vazio
        }    
    }
    
    for (int i = 0; i < TAMANHO_TABULEIRO; i++)
    {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++)
        {
            int distancia_i = centro - i;
            if (distancia_i < 0)
            {
                distancia_i = distancia_i * -1; // Condição para evitar índices negativos e erros
            }

            int distancia_j = centro - j;
            if (distancia_j < 0)
            {
                distancia_j = distancia_j * -1; // Condição para evitar índices negativos e erros
            }
            
            if (distancia_i + distancia_j <= centro)
            {
                tabuleiroOct[i][j] = 5; // Definindo o desenho do octaedro
            }
        }
    }
}

void desenharCone(int tabuleiroCone[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]){ // Código do tabuleiro da habilidade do cone

    int centro = 2; // Centro da habilidade

    for (int i = 0; i < TAMANHO_TABULEIRO; i++)
    {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++)
        {
            tabuleiroCone[i][j] = 0; // Definindo tabuleiro vazio
        }    
    }    

    for (int i = 0; i < TAMANHO_TABULEIRO; i++)
    {
        if (i > 2) break;
        tabuleiroCone[i][centro] = 5; // Definindo a origem da dispersão do cone
        if (i != 0)
        {
            tabuleiroCone[i][centro + 1] = 5; // Expandindo uma vez para um lado
            tabuleiroCone[i][centro - 1] = 5; // Expandindo uma vez para o outro lado
            if (i != 1)
            {
                tabuleiroCone[i][centro + 2] = 5; // Expandindo duas vezes para um lado
                tabuleiroCone[i][centro - 2] = 5; // Expandindo duas vezes para o outro lado            
            }   
        }
    
    }
    
}

void desenharCruz(int tabuleiroCruz[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]){ // Código do tabuleiro da habilidade da cruz

    int centro = 2; // Centro da habilidade

    for (int i = 0; i < TAMANHO_TABULEIRO; i++)
    {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++)
        {
            tabuleiroCruz[i][j] = 0; // Definindo tabuleiro vazio
        }    
    }            


    for (int i = 0; i < TAMANHO_TABULEIRO; i++)
    {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++)
        {
            if (i == centro || j == centro)
            {
                tabuleiroCruz[i][j] = 5; // Definindo o centro da cruz, que se expande para as outras direções
                if (j == 0 || j == 4)
                {
                    tabuleiroCruz[i][j] = 0; // Retirando bordas laterais da cruz
                }
            }
        }
    }
}

int main(){
    char linha[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'}; // Definindo variável linha
    int tabuleiro[10][10]; // Matriz do tabuleiro
    int tabuleiroOct[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]; // Matriz do octaedro
    int tabuleiroCone[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]; // Matriz do cone
    int tabuleiroCruz[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]; // Matriz da cruz

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            tabuleiro[i][j] = 0; // Preenchimento do tabuleiro com 0 (água)         
        }
    }
    
    desenharOctaedro(tabuleiroOct); // Puxando o tabuleiro do octaedro para a função main
    desenharCone(tabuleiroCone); // Puxando o tabuleiro do cone para a função main
    desenharCruz(tabuleiroCruz); // Puxando o tabuleiro da cruz para a função main

    int ponto_origem_iOct = 7; // Ponto de origem "i" do octaedro
    int ponto_origem_jOct = 7; // Ponto de origem "j" do octaedro
    int ponto_origem_iCone = 9; // Ponto de origem "i" do cone
    int ponto_origem_jCone = 2; // Ponto de origem "j" do cone
    int ponto_origem_iCruz = 4; // Ponto de origem "i" da cruz
    int ponto_origem_jCruz = 1; // Ponto de origem "j" da cruz      

    int centro_habilidade = TAMANHO_TABULEIRO / 2; // Definindo o centro das habilidades como metade do tabuleiro de cada uma
    
    for (int i = 0; i < TAMANHO_TABULEIRO; i++)
    {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++)
        {
            if (tabuleiroOct[i][j] == 5)
            {
                int i_tabuleiro = ponto_origem_iOct + (i - centro_habilidade);
                int j_tabuleiro = ponto_origem_jOct + (j - centro_habilidade);     
                
                if (i_tabuleiro >= 0 && i_tabuleiro < 10 && // Condicional para a habilidade não sair para fora do tabuleiro 10x10
                    j_tabuleiro >= 0 && j_tabuleiro < 10)
                {
                    tabuleiro[i_tabuleiro][j_tabuleiro] = 5; // Percorrendo a habilidade do octaedro
                }
            }
        }
    }
    
    for (int i = 0; i < TAMANHO_TABULEIRO; i++)
    {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++)
        {
            if (tabuleiroCone[i][j] == 5)
            {
                int i_tabuleiro = ponto_origem_iCone + (i - centro_habilidade);
                int j_tabuleiro = ponto_origem_jCone + (j - centro_habilidade);     
                
                if (i_tabuleiro >= 0 && i_tabuleiro < 10 && // Condicional para a habilidade não sair para fora do tabuleiro 10x10
                    j_tabuleiro >= 0 && j_tabuleiro < 10)
                {
                    tabuleiro[i_tabuleiro][j_tabuleiro] = 5; // Percorrendo a habilidade do cone
                }
            }
        }
        
    }
    
    for (int i = 0; i < TAMANHO_TABULEIRO; i++)
    {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++)
        {
            if (tabuleiroCruz[i][j] == 5)
            {
                int i_tabuleiro = ponto_origem_iCruz + (i - centro_habilidade);
                int j_tabuleiro = ponto_origem_jCruz + (j - centro_habilidade); 
                
                if (i_tabuleiro >= 0 && i_tabuleiro < 10 && // Condicional para a habilidade não sair para fora do tabuleiro 10x10
                    j_tabuleiro >= 0 && j_tabuleiro < 10)
                {
                    tabuleiro[i_tabuleiro][j_tabuleiro] = 5; // Percorrendo a habilidade do cone
                }
            }
            
        }
        
    }
    

    printf(" TABULEIRO BATALHA NAVAL\n"); // Título do tabuleiro

    printf("   "); // Espaçamento

    for (int i = 0; i < 10; i++)
    {
        printf("%c ", linha[i]); // Implementação da linha no tabuleiro
    }
    
    printf("\n"); // Espaçamento

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

    for (int i = 0; i < 10; i++)
    {
        printf("%2d ", i + 1); // Implementação da coluna numérica no tabuleiro, alocando 2 espaços para alinhamento das casas

        for (int j = 0; j < 10; j++)
        {
            printf("%d ", tabuleiro[i][j]); // Impressão do tabuleiro em si
        }
        printf("\n"); // Espaçamento para casas
    }
    
    return 0;
}

