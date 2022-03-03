#include "BBT_FilaD.c"
#include "BBT_PilhaD.c"
#include "BBT_ListaSE.c"
#include "Tabuleiro.c"


/* 
    TODO: mudar nome das fases de acordo com o documento do projeto
 */
int fase_2(Tabuleiro **tabuleiro, Jogador **jogador){

    ComandosPilha aux;
    aux.movimento = 0;
    
    Pilha *ptrPilha;
    inicializarPilha(&ptrPilha);
    
    inicializaTabuleiro( tabuleiro );
    
    strcpy((*tabuleiro)->comandos[0], "F, F, F");
    strcpy((*tabuleiro)->comandos[1], "F, F, D");
    strcpy((*tabuleiro)->comandos[2], "F, F, E");
    imprimeTabuleiro(*tabuleiro, *jogador);
    
    printf("Informe suas jogadas, para finalizar insira -1 no comando a ser utilizado.\n");
    while(aux.movimento != -1){   

        printf("Qual o comando ira utilizar?\n");
        scanf("%d", &aux.movimento);
        if( aux.movimento == -1 ) break;
        
        printf("Quantas vezes ira utilizar o %d comando?\n", aux.movimento);
        scanf("%d", &aux.quantidade);
        
        empilhar(&ptrPilha, aux);
        
        imprimeTabuleiro(*tabuleiro, *jogador);
        
    }
    while (ptrPilha != NULL){

        for (int i = 0; i < ptrPilha->info.quantidade; i++){
            int j = 0;
            while ((*tabuleiro)->comandos[ptrPilha->info.movimento - 1][j] != '\0') {
                executaMovimento( tabuleiro, jogador,(*tabuleiro)->comandos[ptrPilha->info.movimento - 1][j]);
                j++;
            }
        }
        desempilhar(&ptrPilha);
    }

    if ((*jogador)->posicaoH == tam_tabuleiro-1 && (*jogador)->posicaoV == tam_tabuleiro-1) 
        return 0;
    else{
        (*jogador)->vidas -= 1;
        return (*jogador)->vidas;
    } 

}

int fase_1(Tabuleiro **tabuleiro, Jogador **jogador){

    ComandosFila aux;
    aux.movimento = 0;
    
    Fila *ptrFila;
    ptrFila = (Fila *)malloc(sizeof(Fila));
    
    inicializaFila(ptrFila); 
    inicializaTabuleiro( tabuleiro );
    
    strcpy((*tabuleiro)->comandos[0], "F, F, F");
    strcpy((*tabuleiro)->comandos[1], "F, F, D");
    strcpy((*tabuleiro)->comandos[2], "F, F, E");
    imprimeTabuleiro(*tabuleiro, *jogador);

    printf("Informe suas jogadas, para finalizar insira -1 no comando a ser utilizado.\n");
    while(aux.movimento != -1){   

        printf("Qual o comando ira utilizar?\n");
        scanf("%d", &aux.movimento);
        if( aux.movimento == -1 ) break;
        
        printf("Quantas vezes ira utilizar o %d comando?\n", aux.movimento);
        scanf("%d", &aux.quantidade);
        
        enfileirar(ptrFila, aux);
        
        imprimeTabuleiro(*tabuleiro, *jogador);
        
    }

    while (!filaVazia(ptrFila)){

        for (int i = 0; i < ptrFila->inicio->info.quantidade; i++){
            int j = 0;
            while ((*tabuleiro)->comandos[ptrFila->inicio->info.movimento - 1][j] != '\0') {
                executaMovimento( tabuleiro, jogador,(*tabuleiro)->comandos[ptrFila->inicio->info.movimento - 1][j]);
                j++;
            }
        }
        desenfilera(ptrFila);
    }

    if ((*jogador)->posicaoH == tam_tabuleiro-1 && 
        (*jogador)->posicaoV == tam_tabuleiro-1) return 0;
    else{
        (*jogador)->vidas -= 1;
        return (*jogador)->vidas;
    } 

}

int fase_3(Tabuleiro **tabuleiro, Jogador **jogador){

    if ((*jogador)->posicaoH == tam_tabuleiro-1 && 
        (*jogador)->posicaoV == tam_tabuleiro-1) return 0;
    else{
        (*jogador)->vidas -= 1;
        return (*jogador)->vidas;
    } 

}

void executa(Tabuleiro **tabuleiro, Jogador **jogador){

    int continuar;
    
    inicializaJogador(jogador);
    
    while (continuar){
    
        continuar = fase_1( tabuleiro, jogador );
        if (continuar == -3) break;
    
    }
    if (continuar != -3){
    
        system("cls");
        imprimirFraseFinal(1);
        delay(1);
        
        do{
            continuar = fase_2( tabuleiro, jogador );
            if (continuar == -3) break;
        }while (continuar);
    
    }else
    if (continuar != -3){
    
        system("cls");
        imprimirFraseFinal(2);
        delay(1);
    
        do{
            continuar = fase_3( tabuleiro, jogador );
            if (continuar == -3) break;
        }while (continuar);
    
    }else
    if (continuar != -3){
    
        system("cls");
        imprimirFraseFinal(3);
        delay(1);
    
    }else
        imprimirFraseFinal(4);

}

/*
* Função criada para dar pausas durante a execução do programa
*/
void delay(int numSegundos){

    int tempo = 500 * numSegundos;
    clock_t inicio = clock();
    while (clock() < inicio + tempo);

}

void imprimirFase(int fase){

    printf(" -------------------------------------------------\n");
    switch (fase){
        case 1:{
            printf("|            __         _           _             |\n");
            printf("|           /_ |       (_)         | |            |\n");
            printf("|            | |  _ __  ___   _____| |            |\n");
            printf("|            | | | '_ \\| \\ \\ / / _ \\ |            |\n");
            printf("|            | | | | | | |\\ V /  __/ |            |\n");
            printf("|            |_| |_| |_|_|_\\_/ \\___|_|_           |\n");
            printf("|                      | |     (_)   | |       _  |\n");
            printf("|   ___ ___  _ __   ___| |_   _ _  __| | ___  | | |\n");
            printf("|  / __/ _ \\| '_ \\ / __| | | | | |/ _` |/ _ \\ | | |\n");
            printf("| | (_| (_) | | | | (__| | |_| | | (_| | (_) ||_| |\n");
            printf("|  \\___\\___/|_| |_|\\___|_|\\__,_|_|\\__,_|\\___/ (_) |\n");
            printf("|                                                 |\n");
            break;
        }
        case 2:{
            printf("|           ___          _           _           |\n");
            printf("|          |__ \\        (_)         | |          |\n");
            printf("|             ) |  _ __  ___   _____| |          |\n");
            printf("|            / /  | '_ \\| \\ \\ / / _ \\ |          |\n");
            printf("|           / /_  | | | | |\\ V /  __/ |          |\n");
            printf("|          |____| |_| |_|_| \\_/ \\___|_|       _  |\n");
            printf("|                      | |     (_)   | |     | | |\n");
            printf("|   ___ ___  _ __   ___| |_   _ _  __| | ___ | | |\n");
            printf("|  / __/ _ \\| '_ \\ / __| | | | | |/ _` |/ _ \\| | |\n");
            printf("| | (_| (_) | | | | (__| | |_| | | (_| | (_) |_| |\n");
            printf("|  \\___\\___/|_| |_|\\___|_|\\__,_|_|\\__,_|\\___/(_) |\n");
            printf("|                                                |\n");
            break;
        }
        case 3:{
            printf("|           ____          _           _          |\n");
            printf("|          |___ \\        (_)         | |         |\n");
            printf("|            __) |  _ __  ___   _____| |         |\n");
            printf("|           |__ <  | '_ \\| \\ \\ / / _ \\ |         |\n");
            printf("|           ___) | | | | | |\\ V /  __/ |         |\n");
            printf("|          |____/  |_| |_|_| \\_/_\\___|_|      _  |\n");
            printf("|                      | |     (_)   | |     | | |\n");
            printf("|   ___ ___  _ __   ___| |_   _ _  __| | ___ | | |\n");
            printf("|  / __/ _ \\| '_ \\ / __| | | | | |/ _` |/ _ \\| | |\n");
            printf("| | (_| (_) | | | | (__| | |_| | | (_| | (_) |_| |\n");
            printf("|  \\___\\___/|_| |_|\\___|_|\\__,_|_|\\__,_|\\___/(_) |\n");
            printf("|                                                |\n");
            break;
        }
        case 4:{
            printf("|                                                 |\n");
            printf("|                                /\\               |\n");
            printf("|              __   _____   ___ ___               |\n");
            printf("|              \\ \\ / / _ \\ / __/ _ \\              |\n");
            printf("|               \\ V / (_) | (_|  __/              |\n");
            printf("|                \\_/ \\___/ \\___\\___|       _      |\n");
            printf("|                          | |            | |     |\n");
            printf("|        _ __   ___ _ __ __| | ___ _   _  | |     |\n");
            printf("|       | '_ \\ / _ \\ '__/ _` |/ _ \\ | | | | |     |\n");
            printf("|       | |_) |  __/ | | (_| |  __/ |_| | |_|     |\n");
            printf("|       | .__/ \\___|_|  \\__,_|\\___|\\__,_| (_)     |\n");
            printf("|       | |                                       |\n");
            printf("|       |_|                                       |\n");
            break;
        }
        

    }

    printf(" -------------------------------------------------\n");
    printf("Aperte enter para continuar.\n");
    fflush(stdin);
    getc(stdin);
    fflush(stdin);
    system("cls");
                        
}