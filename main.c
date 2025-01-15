/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//gcc main.c -o main.exe
//./main.exe
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ListaEstatica.c"

//funÃ§Ã£o principal
int main() {

    agenda contato[TAM];
    int t = 0;
    int opc;

    do {
        system("cls");

        printf("___________________________\n");
        printf("|                         |\n");
        printf("|          AGENDA         |\n");
        printf("|                         |\n");
        printf("| Escolha uma alternativa |\n");
        printf("|                         |\n");
        printf("|   1-Cadastrar contato   |\n");
        printf("|   2-Excluir contato     |\n");
        printf("|   3-Pesquisar contato   |\n");
        printf("|   4-Exibir contatos     |\n");
        printf("|   5-Sair da agenda      |\n");
        printf("|_________________________|\n");
        printf("\n");
        printf("--> Digite sua escolha: ");
        printf("\n");
        scanf("%d", &opc);
        printf("\n");

        switch (opc) {
            case 1:
                cadastro(contato, &t);
                break;
                
            case 2:
                excluir(contato, &t);
                break;
            case 3:
                pesquisar(contato, &t);
                break;
            case 4:
                exibir(contato, t);
                break;

            case 5:
                printf("\033[1;32m");
                printf("Saindo da Agenda!!\n");
                printf("\033[1;37m");
		return 0;
                break;
            default:
                printf("\033[1;31m"); 
                printf("Opcao invalida.Tente outra!!\n");
                printf("\033[1;37m");

                break;
        }
            getchar(); // captura o '\n' pendente apÃ³s o scanf
            getchar(); // espera que o usuÃ¡rio pressione Enter

    } while (opc != 6); // Continua atÃ© que o usuÃ¡rio escolha sair da agenda 

    return 0;
}

