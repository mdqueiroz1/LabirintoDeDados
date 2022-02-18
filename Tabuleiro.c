#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*Definição de constantes utilizadas no programa */
#define tam_tabuleiro 8
#define player 80 //P
#define objetivo 79 //O
#define parede 88 // X
#define jogador_esquerda 60 // <
#define jogador_direita 62 // >
#define jogador_cima 94 // ^
#define jogador_baixo 118 // v
#define vazio 32 // ' '

typedef struct sJogador{
    
    char jogador, jogadorDirecao;
    int posicaoV, posicaoH, vidas;

}Jogador;


typedef struct sTabuleiro{
    
    char local[tam_tabuleiro][tam_tabuleiro];
    char comandos_1[20], comandos_2[20], comandos_3[20];

}Tabuleiro;

/* * Movimentação do personagem */
void giraEsq(Jogador **jogador){

    if ((*jogador)->jogadorDirecao == jogador_direita) (*jogador)->jogadorDirecao = jogador_baixo; 
    else
    if ((*jogador)->jogadorDirecao == jogador_cima) (*jogador)->jogadorDirecao = jogador_direita; 
    else
    if ((*jogador)->jogadorDirecao == jogador_esquerda) (*jogador)->jogadorDirecao = jogador_cima; 
    else 
    if ((*jogador)->jogadorDirecao == jogador_baixo) (*jogador)->jogadorDirecao = jogador_esquerda; 
    
}

void giraDir( Jogador **jogador ){

    if ((*jogador)->jogadorDirecao == jogador_direita) (*jogador)->jogadorDirecao = jogador_cima; 
    else
    if ((*jogador)->jogadorDirecao == jogador_cima) (*jogador)->jogadorDirecao = jogador_esquerda; 
    else
    if ((*jogador)->jogadorDirecao == jogador_esquerda) (*jogador)->jogadorDirecao = jogador_baixo; 
    else 
    if ((*jogador)->jogadorDirecao == jogador_baixo) (*jogador)->jogadorDirecao = jogador_direita; 

}

void movimentaPersonagem( Tabuleiro **tabuleiro, Jogador **jogador ){

    switch ((*jogador)->jogadorDirecao){

        case jogador_direita:{
            
            if( !((*tabuleiro)->local[(*jogador)->posicaoH][(*jogador)->posicaoV + 1] == parede 
                || (*jogador)->posicaoV + 1 >= tam_tabuleiro) ){

                    (*tabuleiro)->local[(*jogador)->posicaoH][(*jogador)->posicaoV] = vazio;
                    (*jogador)->posicaoV += 1; 
                    (*tabuleiro)->local[(*jogador)->posicaoH][(*jogador)->posicaoV] = player;

                }

            break;
        }
        case jogador_esquerda:{

            if( !((*tabuleiro)->local[(*jogador)->posicaoH][(*jogador)->posicaoV - 1] == parede 
                || (*jogador)->posicaoV - 1 < (tam_tabuleiro-tam_tabuleiro)) ){

                    (*tabuleiro)->local[(*jogador)->posicaoH][(*jogador)->posicaoV] = vazio;
                    (*jogador)->posicaoV -= 1; 
                    (*tabuleiro)->local[(*jogador)->posicaoH][(*jogador)->posicaoV] = player;

                }
            
            break;
        }
        case jogador_cima:{
            
            if( !((*tabuleiro)->local[(*jogador)->posicaoH - 1 ][(*jogador)->posicaoV] == parede 
                || (*jogador)->posicaoH - 1 < (tam_tabuleiro-tam_tabuleiro)) ){

                    (*tabuleiro)->local[(*jogador)->posicaoH][(*jogador)->posicaoV] = vazio;
                    (*jogador)->posicaoH -= 1; 
                    (*tabuleiro)->local[(*jogador)->posicaoH][(*jogador)->posicaoV] = player;

            }
            
            break;
        }
        case jogador_baixo:{

            if( !((*tabuleiro)->local[(*jogador)->posicaoH + 1 ][(*jogador)->posicaoV] == parede 
                || (*jogador)->posicaoH + 1 >= tam_tabuleiro) ){

                    (*tabuleiro)->local[(*jogador)->posicaoH][(*jogador)->posicaoV] = vazio;
                    (*jogador)->posicaoH += 1; 
                    (*tabuleiro)->local[(*jogador)->posicaoH][(*jogador)->posicaoV] = player;

            }
            
            break;
        }
        
    }    
    
}

void inicializaTabuleiro(Tabuleiro **tabuleiro, Jogador **jogador){

    *tabuleiro = (Tabuleiro*) malloc (sizeof(Tabuleiro));
    *jogador = (Jogador*) malloc (sizeof (Jogador));

    for (int i = 0; i < tam_tabuleiro; i++){
        for (int j = 0; j < tam_tabuleiro; j++){
            (*tabuleiro)->local[i][j] = ' ' ;
        }
    }

    (*tabuleiro)->local[0][0] = player ;
    (*tabuleiro)->local[tam_tabuleiro-1][tam_tabuleiro-1] = objetivo;
    (*jogador)->jogador = player;
    (*jogador)->jogadorDirecao = jogador_direita;
    (*jogador)->posicaoV = 0;
    (*jogador)->posicaoH = 0;

}

void imprimeTabuleiro(Tabuleiro *tabuleiro, Jogador *jogador){
    system("cls");
    int i, j;
    for (i = 0; i < tam_tabuleiro; i++){
        printf("|---|---|---|---|---|---|---|---|\n");
        for (j = 0; j < tam_tabuleiro; j++){
            printf("| %c ", tabuleiro->local[i][j]);
        }
        printf("|    ");

        switch (i){
            
            case 0:
                printf("| %c%c |\n", jogador->jogador, jogador->jogadorDirecao);
                break;
            case 1:
                printf("Comandos:\n");
                break;
            case 2:
                printf("1 - Frente, Frente, Direita\n");
                break;
            case 3:
                printf("2 - Frente, Frente, Esquerda\n");
                break;
            case 4:
                printf("3 - Frente, Frente, Frente\n");
                break;
            default:
                printf("\n");
                break;
        }


    }
    printf("|---|---|---|---|---|---|---|---|\n");

    

}