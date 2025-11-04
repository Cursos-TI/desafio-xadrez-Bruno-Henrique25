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

    return 0;
}
