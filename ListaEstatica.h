#define TAM 100
//struct do contato
typedef struct
{
    char nome[50];
    char telefone[15];
    char email[30];
}agenda;

void limpaBuffer();
void cadastro(agenda contato[], int *t); //funÃ§Ã£o para cadastro.
void excluir(agenda contato[], int *t); //funÃ§Ã£o para excluir.
void pesquisar(agenda contato[], int *t); // funÃ§Ã£o para pesquisar pelo nome.
void exibir(agenda contato[], int t); //funÃ§Ã£o para mostrar todos os contatos.
