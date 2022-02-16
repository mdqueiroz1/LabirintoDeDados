/**
 * @authors Lucas D Queiroz, Matheus D Queiroz, Rafael C Bernardes
 * @date 02/2022
 * Projeto final da matéria de Estrutura de Dados
 */

#include <stdio.h>
#include "Tabuleiro.c"
#include "Engine.c"

void menuPrincipal(){

    int opcMenu;
    Tabuleiro *tabuleiro;
    Jogador *jogador;

    do{
        printf("1 - Inicializa menu\n");
        scanf("%d", &opcMenu);

        switch (opcMenu){
            case 1:{
                inicializaTabuleiro(&tabuleiro, &jogador);
                imprimeTabuleiro(tabuleiro, jogador);
                break;
            }
                
            
            case 9:{
                printf("Programa finalizado!\n");
            }

            default:{
                printf("Opcao invalida!\nAperte enter para retornar\n");
                fflush(stdin);
                getc(stdin);
                fflush(stdin);
                break;
            }
        }
    } while (opcMenu != 9);

}

int main(){ 

    menuPrincipal();
    
    return 0;
}
