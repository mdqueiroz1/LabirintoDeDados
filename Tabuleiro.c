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
    char comandos[4][20];

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

void executaMovimento(Tabuleiro **tabuleiro, Jogador **jogador, char movimento){

    switch (movimento){

    case 'F':
        movimentaPersonagem(tabuleiro, jogador);
        imprimeTabuleiro(*tabuleiro, *jogador);
        delay(1);
        break;
    
    case 'D':
        giraDir(jogador);
        imprimeTabuleiro(*tabuleiro, *jogador);
        delay(1);
        break;
    
    case 'E':
        giraEsq(jogador);
        imprimeTabuleiro(*tabuleiro, *jogador);
        delay(1);
        break;
    }
    
}

void inicializaJogador(Jogador **jogador){

    *jogador = (Jogador*) malloc (sizeof (Jogador));
    (*jogador)->jogador = player;
    (*jogador)->vidas = 0;
    (*jogador)->jogadorDirecao = jogador_direita;
    (*jogador)->posicaoV = 0;
    (*jogador)->posicaoH = 0;

}

void inicializaTabuleiro(Tabuleiro **tabuleiro){

    *tabuleiro = (Tabuleiro*) malloc (sizeof(Tabuleiro));
    

    for (int i = 0; i < tam_tabuleiro; i++){
        for (int j = 0; j < tam_tabuleiro; j++){
            (*tabuleiro)->local[i][j] = ' ' ;
        }
    }
    
    (*tabuleiro)->local[0][0] = player ;
    (*tabuleiro)->local[tam_tabuleiro-1][tam_tabuleiro-1] = objetivo;

    (*tabuleiro)->local[0][5] = parede;
    (*tabuleiro)->local[0][6] = parede;
    (*tabuleiro)->local[1][0] = parede;
    (*tabuleiro)->local[1][1] = parede;
    (*tabuleiro)->local[1][2] = parede;
    (*tabuleiro)->local[1][6] = parede;
    (*tabuleiro)->local[2][6] = parede;
    (*tabuleiro)->local[3][2] = parede;
    (*tabuleiro)->local[3][3] = parede;
    (*tabuleiro)->local[3][4] = parede;
    (*tabuleiro)->local[5][5] = parede;
    (*tabuleiro)->local[6][5] = parede;
    (*tabuleiro)->local[7][5] = parede;

}

void imprimeTabuleiro(Tabuleiro *tabuleiro, Jogador *jogador){
    // system("cls");
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
                printf("1 - %s\n", tabuleiro->comandos[0]);
                break;
            case 3:
                printf("2 - %s\n", tabuleiro->comandos[1]);
                break;
            case 4:
                printf("3 - %s\n", tabuleiro->comandos[2]);
                break;
            case 5:
                if(tabuleiro->comandos[3] != EOF)
                printf("4 - %s\n", tabuleiro->comandos[3]);
                break;
            default:
                printf("\n");
                break;
        }


    }
    printf("|---|---|---|---|---|---|---|---|\n");

    

}