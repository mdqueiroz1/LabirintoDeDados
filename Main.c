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

    do{
        printf("1 - Inicializa menu");
        scanf("%d", &opcMenu);

        switch (opcMenu){
            case 1:{
                inicializaTabuleiro();
                break;
            }
                
            
            default:{
                printf("Opcao invalida!\nAperte enter para retornar\n");
                getc(stdin);
                fflush(stdin);
                break;
            }
        }
    } while (opcMenu != 9);
    
}

int main(){ 

    menuPrincipal();
    printf("Programa finalizado!\n");
    return 0;
}
