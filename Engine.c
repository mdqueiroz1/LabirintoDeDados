#include "BBT_FilaD.c"
#include "BBT_PilhaD.c"
#include "BBT_ListaSE.c"
#include "Tabuleiro.c"


/* comando 1 - frente frente vira a direita*/
void comando_1(Tabuleiro **tabuleiro, Jogador **jogador){

    movimentaPersonagem(tabuleiro, jogador);
    delay(1);
    imprimeTabuleiro( *tabuleiro, *jogador );
    movimentaPersonagem( tabuleiro, jogador );
    delay(1);
    imprimeTabuleiro( *tabuleiro, *jogador );
    giraDir(jogador);
    delay(1);
    imprimeTabuleiro( *tabuleiro, *jogador );

}

void comando_2(Tabuleiro **tabuleiro, Jogador **jogador){

    movimentaPersonagem(tabuleiro, jogador);
    delay(1);
    imprimeTabuleiro( *tabuleiro, *jogador );
    movimentaPersonagem(tabuleiro, jogador);
    delay(1);
    imprimeTabuleiro( *tabuleiro, *jogador );
    giraEsq(jogador);
    delay(1);
    imprimeTabuleiro( *tabuleiro, *jogador );

}

void comando_3(Tabuleiro **tabuleiro, Jogador **jogador){

    movimentaPersonagem(tabuleiro, jogador);
    delay(1);
    imprimeTabuleiro( *tabuleiro, *jogador );
    movimentaPersonagem(tabuleiro, jogador);
    delay(1);
    imprimeTabuleiro( *tabuleiro, *jogador );
    movimentaPersonagem(tabuleiro, jogador);
    delay(1);
    imprimeTabuleiro( *tabuleiro, *jogador );

}

int fase_1(Tabuleiro **tabuleiro, Jogador **jogador){

    inicializaTabuleiro(tabuleiro,jogador);

    if ((*jogador)->posicaoH == tam_tabuleiro-1 && 
        (*jogador)->posicaoV == tam_tabuleiro-1) return 1;
    else return 0;

}

int fase_2(Tabuleiro **tabuleiro, Jogador **jogador){

    if ((*jogador)->posicaoH == tam_tabuleiro-1 && 
        (*jogador)->posicaoV == tam_tabuleiro-1) return 1;
    else return 0;

}

int fase_3(Tabuleiro **tabuleiro, Jogador **jogador){

    if ((*jogador)->posicaoH == tam_tabuleiro-1 && 
        (*jogador)->posicaoV == tam_tabuleiro-1) return 1;
    else return 0;

}

void executa(Tabuleiro **tabuleiro, Jogador **jogador){

    int continuar;

    while (continuar){
    
        continuar = fase_1(tabuleiro,jogador);
        if (continuar == -3) break;
    
    }
    if (continuar != -3){
    
        system("cls");
        printf("Voce concluiu a primeira fase!\n");
        delay(1);
        
        while (continuar){
            continuar = fase_2(tabuleiro, jogador);
            if (continuar == -3) break;
        }
    
    }else
    if (continuar != -3){
    
        system("cls");
        printf("Voce concluiu a segunda fase!\n");
        delay(1);
    
        while (continuar){
            continuar = fase_3(tabuleiro, jogador);
            if (continuar == -3) break;
        }
    
    }else
    if (continuar != -3){
    
        system("cls");
        printf("Voce concluiu a terceira fase!\n");
        delay(1);
    
    }else
        printf("Voce perdeu todas as suas vidas!\n\n");

}

void delay(int numSegundos){

    int miliSegundos = 1000 * numSegundos;
    clock_t inicio = clock();
    while (clock() < inicio + miliSegundos);

}