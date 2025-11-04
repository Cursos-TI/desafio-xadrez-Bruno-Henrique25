#include <stdio.h>

//*** BLOCO DE FUNÇÕES RECURSIVAS PARA A MOVIMENTAÇÃO DAS PEÇAS ***

/*Estas funções serão utilizadas/"chamadas" dentro da função principal (e posteriormente por sí mesmas [funções recursivas]) 
para movimentar as peças de Xadrez, exceto o Cavalo, cuja estrutura de movimento está totalmente inserida na função main()*/

/*Função recursiva para mover a Torre. Sendo a variável "i" igual ao número de casas a serem percorridas pela torre 
para uma direção, cujo valor é dado pela variável "direcao";*/
void mover_Torre(int i, char direcao[20]) 
    {
        if (i > 0) 
            {
                //Imprime a direação para a qual a Torre está se movendo.
                printf("%s\n", direcao);
                //"Chama" novamente a função, removendo uma unidade do valor de casas a percorrer e preservando sua direção.
                mover_Torre(i - 1, direcao);
            };
    };


/*Função recursiva para mover o Bispo em um total de X casas na vertical e horizontal (O valor é o mesmo par ambos), resultando em seu movimento diagonal.
As variáveis do tipo char "vertical" e "horizontal" recebem as direções do bispo (cima e direita; baixo e esquerda etc) para serem impressas pelos loops aninhados da função.

*/
void mover_Bispo(int casas, char vertical[20], char horizontal[20]) 
    {
        //estrutura de decisão "if" que controla a relização dos loops aninhados de movimento, até que o total de casas tenha sido percorrido por inteiro (casas == 0); 
        if (casas > 0)
        {   
            //variável que controla o movimento vertical
            int mover_vertical = 0;
            //variável que controla o movimento horizontal
            int mover_horizontal = 0;
            //Loop para movimento vertical

            /*O loop while (e o loop aninhado for) são ativados uma vez, a cada iteração da função 
            (caso ainda hajam casas a percorrer) imprimindo por meio da função printf(), a direção na qual o Bispo está se deslocando.
            Quando o valor "mover_horizontal" chegar em 1, o loop encerra, sendo executado apenas uma vez, quando este mesmo valor for igual a zero*/
            while (mover_vertical < 1) 
                {
                    //Imprime na tela a movimentação vertical do Bispo
                    printf("%s\n", vertical);

                    //Loop para movimento horizontal. É executado apenas com valor "mover_horizontal" sendo igual a 0. Ao chegar em 1, o loop encerra.
                    for (mover_horizontal; mover_horizontal < 1; mover_horizontal++) 
                        {   
                            //Imprime na tela a movimentação horizontal do bispo, para que usuário fique ciente de sua lógica de movimento diagonal.
                            printf("%s\n", horizontal);

                            /*Incrementa-se o valor do movimento vertical para garantir que não hajam movimentos duplicados.
                            Assim, ao fim do loop "for", tendo as duas printfs, que indicam as posicões vertical e horizontal, cumprido seu papel,
                            o loop while é impedido de continuar a ser executado indefinidamente, sendo acionado novamente se, e somente se,
                            a função for chamada mais uma vez, isto é, se a variável casas for maior que zero, reiniciando a função até que se cumpra o
                            objetivo, que é mover o bispo pelo número de casas diagonais desejado. 
                            */
                            mover_vertical++;

                        };
                };

            /*A função "chama" a sí mesma novamente, passando na função um parâmetro de número de casas menor, em uma unidade, que o valor original.
            Isto garante que o número de casas a ser percorrido seja decrementado a cada iteração e chege eventualmente a 0, onde a função se encerrará.*/
            mover_Bispo(casas - 1, vertical, horizontal);
        };
    };



/*Função recursiva para mover a Rainha. Sendo "X" a variável cujo valor é igual ao número de casas a percorer 
e "Dir" é variável do tipo char que armazena o string contendo a direção do movimento desejado.*/
void mover_Rainha(int X, char Dir[20]) 
    {
        if (X > 0) {
            //Imprime a direção do movimento a ser executado pela Rainha, na forma de string e tendo como valor, a vairável "Dir".
            printf("%s\n", Dir);

            /*"Chama-se" a função novamente, removendo "1" (um) do número de casas a ser percorrido e preservando sua direção.
            Isto permite que a peça "Rainha" continue a se mover na direção especificada até que o número de casas a percorrer acabe (valor 0)*/
            mover_Rainha(X - 1, Dir);
        }
    }





//*** FUNÇÃO PRINCIPAL ***

int main() 
    {
        
        //*** VARIÁVEIS DO NÚMERO DE CASAS QUE CADA PEÇA PODERÁ PERCORRER!***

        /*Cada variável abaixo será utilizada no bloco de movimentação das peças como parâmetros de cada função
        correspendente a cada peça de Xadrez (exceto o Cavalo)*/

        //Número de casas a serem percorridas pela peça "Bispo"
        int casas_Bispo = 5;
        //direção vertical do bispo
        char bispo_vertical[20] = "Cima!";
        //direção horizontal do bispo
        char bispo_horizontal[20] = "Direita!";

        //Número de casas a serem percorridas pela peça "Torre"
        int casas_Torre = 5;
        char direcao_torre[20] = "Direita!";

        //Número de casas a serem percorridas pela peça "Rainha"
        int casas_Rainha = 8;
        char direcao_Rainha[20] = "Esquerda!";




        //Movimento das duas primeiras casas, realizado pelo cavalo (cima, baixo, direita, esquerda)
        int cavalo_Movimento_Inicial = 0;
        //Variável do movimento perpendicular (de uma casa) da pela "Cavalo". Finalizando, assim, seu característico movimento em "L". 
        int cavalo_Movimento_Final = 3;
        
        
        //*** MOVIMENTAÇÃO DAS PEÇAS DE XADREZ ***

        /*Abaixo estão expressas 3 funções printf(), e 3 funções recursivas para movimentar cada peça, 
        sendo cada uma delas organizada/posicionada de maneira intercalada. 
        
        Possibilitando que o usuário possa visualizar qual está se movimentando de maneira coerente e coesa.*/
        
        printf("\n\n\n\t=============== [ Movimentos do Bispo ] ===============\n\n\n");
        mover_Bispo(casas_Bispo, bispo_vertical, bispo_horizontal);

        printf("\n\n\n\t=============== [ Movimentos da Torre ] ===============\n\n\n");
        mover_Torre(casas_Torre, direcao_torre);

        printf("\n\n\n\t=============== [ Movimentos da Rainha ] ===============\n\n\n");
        mover_Rainha(casas_Rainha, direcao_Rainha);
        


        //Movimentação do Cavalo
        printf("\n\n\n\t=============== [ Movimentos do Cavalo ] ===============\n\n\n");
        /*Loop para movimentação do cavalo. são comparados tanto os movimentos realizados em paralelo como perpendicular.
        utiliza-se o operador ou "||" ("OR") para que o loop seja executado enquanto o numero de movimentos não for totalmente
        concluído. 
        
        O valor "cavalo_Movimento_Inicial" é incrementado para que o valor passe, pelo menos, de 0 até 1, garantindo ao menos duas iterações pois, o cavalo, se move 2 casas primeiro.
        Este trabalho (de iterar ao menos duas vezes para as primeiras duas casas) é realizado pelo primeiro loop aninhado, while, que irá imprimir os movimentos das duas primeiras casas quando o valor for 0 ou 1.

        ao fim da primeira condição, ou seja, sendo o valor "cavalo_Movimeto_Inicial" maior ou igual a dois,
        o valor "cavalo_Movimento_Final", que é definido inicialmente como 3 (três), e que será decrementado ao menos duas vezes
        resultando em um valor igual a 1 (um), ainda dará condições para que o loop prossiga.

        Nesta etapa, como dito anteriormente, o valor de "cavalo_Movimento_Final" será igual a 1 (um) ativando o segundo loop while, para impressão da útima casa
        a ser percorrida pelo cavalo, que é perpendicular as outras duas, finalizando assim, o movimento de "L" da peça.

        
        */
        for (
                cavalo_Movimento_Inicial; 
                cavalo_Movimento_Inicial < 2 || cavalo_Movimento_Final > 0 ; 
                cavalo_Movimento_Inicial++, cavalo_Movimento_Final--
            ) 
                {   
                    //Primeiro loop aninhado While para a impressão dos movimentos das primeiras duas casas.
                    while (cavalo_Movimento_Inicial < 2)
                        {
                            //Imprime o valor dos dois primeiros movimentos executados pelo Cavalo.
                            printf("Cima!\n");

                            /*Uso do break para impedir que o loop while seja executado infinitamente,
                            garantindo que o loop mais exterior continue sua iteração até que o segundo loop possa ser ativado*/
                            break;
                        };
                    //Loop para que se imprima a direção do útimo movimento do Cavalo, completandos eu conhecido movimento em "L"
                    while (cavalo_Movimento_Final == 1) 
                        {
                            //Exbibe para qual direção o Cavalo completou seu útimo movimento para formar um "L"
                            printf("Direita!\n");

                            /*Uso do break para impedir que este segundo loop while siga executando infinitamente 
                            permitindo assim que o loop mais exterior, itere novamente para que "cavalo_Movimento_Final
                            seja igual a 0 e, como a variável cavalo_Movimento_Inicial será maior que 2, a condição do loop será
                            perdida, finalizando-o adequadamente após sua tarefa ter sido devidamente concluída" */
                            break;
                        }
                };

        //Uso do return para indicar o fim do programa.            
        return 0;
    }
