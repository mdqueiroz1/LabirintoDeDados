#include <stdio.h>
#include <stdlib.h>

/*Definição de constantes utilizadas no programa */
#define tam_tabuleiro 8
#define player 80
#define jogador_esquerda 60
#define jogador_direita 62
#define jogador_cima 94
#define jogador_baixo 118

typedef struct sJogador{
    
    char jogador, jogadorDirecao;
    int posicaoV, posicaoH;

}Jogador;


typedef struct sTabuleiro{
    
    char local;

}Tabuleiro;

/*
    *Movimentação do personagem
*/
void movimentaF(){
    
}

void movimentaE(){

}

void movimentaD(){

}

void inicializaTabuleiro(){

   Tabuleiro tabuleiro[tam_tabuleiro][tam_tabuleiro];

    for (int i = 0; i < tam_tabuleiro; i++){
        for (int j = 0; j < tam_tabuleiro; j++){
            tabuleiro[i][j].local = ' ';
        }
        
    }

    Jogador jogador;
    jogador.jogador = player;
    jogador.jogadorDirecao = jogador_direita;
    jogador.posicaoV = 0;
    jogador.posicaoH = 0;

}

void imprimeTabuleiro(){

}