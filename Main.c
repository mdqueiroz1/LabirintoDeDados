/**
 * @authors Lucas D Queiroz, Matheus D Queiroz, Rafael C Bernardes
 * @date 02/2022
 * Projeto final da matéria de Estrutura de Dados
 */

#include <stdio.h>
#include "Engine.c"

void menuPrincipal(){

    int opcMenu;
    Tabuleiro *tabuleiro;
    Jogador *jogador;

    do{

        printf(" _           _     _      _       _        \n");
        printf("| |         | |   (_)    (_)     | |       \n");
        printf("| |     __ _| |__  _ _ __ _ _ __ | |_ ___  \n");
        printf("| |    / _` | '_ \\| | '__| | '_ \\| __/ _ \\ \n");
        printf("| |___| (_| | |_) | | |  | | | | | || (_) |\n");
        printf("|______\\__,_|_.__/|_|_|  |_|_| |_|\\__\\___/ \n");
        printf("      _        _____            _           \n");                                                                                      
        printf("     | |      |  __ \\          | |          \n");                                                                        
        printf("   __| | ___  | |  | | __ _  __| | ___  ___ \n");
        printf("  / _` |/ _ \\ | |  | |/ _` |/ _` |/ _ \\/ __|\n");
        printf(" | (_| |  __/ | |__| | (_| | (_| | (_) \\__ \\\n");
        printf("  \\__,_|\\___| |_____/ \\__,_|\\__,_|\\___/|___/\n");

        printf("1 - Iniciar Jogo\n");
        printf("2 - Instrucoes\n");
        printf("3 - Creditos\n");
        printf("9 - Finalizar Jogo\n");
        scanf("%d", &opcMenu);

        switch (opcMenu){
            case 1:{
                executa(&tabuleiro, &jogador);
                break;
            }
            case 2:{
                giraDir(&jogador);
                imprimeTabuleiro(tabuleiro, jogador);
                break;
            }
            case 3:{
                comando_1(&tabuleiro, &jogador);
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
