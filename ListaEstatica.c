#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ListaEstatica.h"
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 //Limpa o buffer de teclado

void limpaBuffer(){
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF && ch != 0);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// funÃ§Ã£o para cadastrar o contato

void cadastro(agenda contato[], int *t)//funÃ§Ã£o para cadastrar.
{
    if (*t < TAM) {

        printf("*-----------------------------------------*\n");

        printf("Nome do Contato:");

        limpaBuffer();

        fgets(contato[*t].nome, sizeof(contato[*t].nome), stdin);
        printf("\n");

        printf("Insira o numero do Contato:");

        fgets(contato[*t].telefone, sizeof(contato[*t].telefone), stdin);
        printf("\n");

        printf("Adicionar Email:");

        fgets(contato[*t].email, sizeof(contato[*t].email), stdin);

        printf("*------------------------------------------*\n");
        (*t)++;

        printf("\033[1;32m");
        printf("     Contato adicionado com sucesso!\n");
        printf("\033[1;37m");

        printf("*------------------------------------------*\n");

    } else {

        printf("A lista de contatos estÃ¡ cheia!\n");
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//funÃ§Ã£o para excluir um contato
void excluir(agenda contato[], int *tamanho) {
    char nome[50];
    int i;
    int encontrado = 0;
    
    limpaBuffer();
    
    printf("Digite o nome da pessoa que voce deseja excluir: ");
    
    fgets(nome, sizeof(nome), stdin);
   
    for (i = 0; i < *tamanho; i++) 
    {
        if (strcmp(nome, contato[i].nome) == 0)
        {
            encontrado = 1; // Contato encontrado

            for (int j = i; j < *tamanho - 1; j++) 
            {

                contato[j] = contato[j + 1];
            }
            printf("Contato excluido com sucesso!\n");
            
 	    (*tamanho)--;
            break;
        }
    }

    if (!encontrado) {
        printf("Contato nao encontrado!!\n");
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//funÃ§Ã£o para buscar um contato em uma lista de contatos com base no nome fornecido pelo usuÃ¡rio

void pesquisar(agenda contato[], int *t) {
    char nome[50];
    int i, encontrado = 0;
    
    limpaBuffer();
    
    printf("Digite o nome do contato que voce deseja pesquisar: ");
    
    fgets(nome, sizeof(nome), stdin);
    
    for (i = 0; i < *t; i++) {
        
         if (strcmp(nome, contato[i].nome) == 0) {
            
	    encontrado = 1;
            printf("*------------------------------------------*\n");
            printf("\n");
            
            printf("Contato encontrado com sucesso:\n");

            printf("Nome: %s", contato[i].nome);
            printf("Telefone: %s", contato[i].telefone);
            printf("Email: %s", contato[i].email);

            printf("\n");
            printf("*------------------------------------------*\n");
             
            
            break;
        }
    }
    if (!encontrado) {
        printf("Contato nao encontrado!Tente novamente!\n");
    }
}
 
           
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//funÃ§Ã£o para exibir os contatos cadastrados na agenda
void exibir(agenda contato[], int tamanho) 
{
    // Ordenar os contatos em ordem alfabÃ©tica
    for (int i = 0; i < tamanho - 1; i++) 
    {
        for (int j = 0; j < tamanho - i - 1; j++) 
        {
            if (strcasecmp(contato[j].nome, contato[j + 1].nome) > 0)
            {
                // Trocar os contatos de posiÃ§Ã£o
                agenda temp = contato[j];
                contato[j] = contato[j + 1];
                contato[j + 1] = temp;
            }
        }
    }
    // Exibir os contatos ordenados
    if (tamanho == 0) 
    {
        printf("Nenhum contato cadastrado.\n");
    } 
    else 
    {
        for (int i = 0; i < tamanho; i++) 
        {   printf("*-----------------------------------*\n");
	    printf("\n");

            printf("Contato %d:\n", i + 1);

            printf("Nome: %s", contato[i].nome);
            printf("Telefone: %s", contato[i].telefone);
            printf("Email: %s", contato[i].email);

            printf("\n");
            printf("*-----------------------------------*\n");
        }
    }
}
