#include <stdio.h>

// Desafio de Xadrez - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de movimentação das peças de xadrez.
// O objetivo é utilizar estruturas de repetição e funções para determinar os limites de movimentação dentro do jogo.

int main() {
    
    //*** VARIÁVEIS DO NÚMERO DE CASAS QUE CADA PEÇA PODERÁ PERCORRER!***

    //Número de casas a serem percorridas pela peça "Bispo"
    int casas_Bispo = 5;
    //Número de casas a serem percorridas pela peça "Torre"
    int casas_Torre = 5;
    //Número de casas a serem percorridas pela peça "Rainha"
    int casas_Rainha = 8;
    //Total de movimentos a ser realizado pelo cavalo.
    int cavalo_movimentos_Totais = 0;
    //Variável do movimento perpendicular (de uma casa) da pela "Cavalo". Finalizando, assim, seu característico movimento em "L". 
    int cavalo_Movimento_Final = 0;
    
    
    //*** MOVIMENTAÇÃO DAS PEÇAS DE XADREZ ***


    //Movimentação do Bispo
    printf("O Bispo irá se mover!\n\n");
    for (casas_Bispo; casas_Bispo > 0; casas_Bispo--) 
        {
            printf("Cima direita!\n");
        };


    //Movimentação da Torre
    printf("\nA Torre irá se mover:\n\n");
    while (casas_Torre > 0) 
        {
            printf("Direita!\n");
            casas_Torre--;

        };

    //Movimentação da Rainha
    printf("A rainha irá se mover!\n\n");
    do 
        {
            printf("Esquerda!\n");
            casas_Rainha--;
        } 
    while (casas_Rainha > 0);


    //Movimentação do Cavalo
    printf("\n\nO cavalo irá se mover!\n\n");
    for (cavalo_movimentos_Totais; cavalo_movimentos_Totais < 2; cavalo_movimentos_Totais++) 
        {
            printf("Baixo!\n");
            cavalo_Movimento_Final++;
            while (cavalo_Movimento_Final == 2) {
                printf("Esquerda!\n");
                cavalo_Movimento_Final++;
            }
        };

    return 0;
}
