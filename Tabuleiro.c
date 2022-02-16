#include <stdio.h>
#include <stdlib.h>

/*Definição de constantes utilizadas no programa */
#define tam_tabuleiro 8
#define player 80 //P
#define jogador_esquerda 60 // <
#define jogador_direita 62 // >
#define jogador_cima 94 // ^
#define jogador_baixo 118 // v

typedef struct sJogador{
    
    char jogador, jogadorDirecao;
    int posicaoV, posicaoH;

}Jogador;


typedef struct sTabuleiro{
    
    char local[tam_tabuleiro][tam_tabuleiro];

}Tabuleiro;

/* * Movimentação do personagem */
void movimentaF(){
    
}

void movimentaE(){

}

void movimentaD(){

}

void inicializaTabuleiro(Tabuleiro **tabuleiro, Jogador **jogador){

    *tabuleiro = (Tabuleiro*) malloc (sizeof(Tabuleiro));
    *jogador = (Jogador*) malloc (sizeof (Jogador));

    for (int i = 0; i < tam_tabuleiro; i++){
        for (int j = 0; j < tam_tabuleiro; j++){
            (*tabuleiro)->local[i][j] = ' ' ;
        }
    }

    (*tabuleiro)->local[0][0] = 'P' ;
    (*jogador)->jogador = player;
    (*jogador)->jogadorDirecao = jogador_direita;
    (*jogador)->posicaoV = 0;
    (*jogador)->posicaoH = 0;

}

void imprimeTabuleiro(Tabuleiro *tabuleiro, Jogador *jogador){
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
                printf("1 - \n");
                break;
            case 3:
                printf("2 - \n");
                break;
            case 4:
                printf("3 - \n");
                break;
            default:
                printf("\n");
                break;
        }


    }
    printf("|---|---|---|---|---|---|---|---|\n");

    

}