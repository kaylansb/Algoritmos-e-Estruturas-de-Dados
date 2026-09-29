#include <stdio.h>
#define TRUE 1 
#define FALSE 0
#define qtdLivros 7
#define maxCaracPorLivro 15

typedef struct {
    char nome[maxCaracPorLivro];
    float preco;
}
biblioteca;

void listarLivrosEmOrdem(biblioteca livro[]);
int trocaValores(int ordem[], int icont, int jcont);
void listarPrecosEmOrdem(biblioteca livro[]);

int main() {
    biblioteca livro[qtdLivros] = {
    {"odisseia\0", 50.30},
    {"frankstein\0", 101.50},
    {"duna\0", 203.90},
    {"alcorao\0", 70.50},
    {"dracula\0", 150.00},
    {"hamlet\0", 160.20},
    {"biblia\0", 100.30}, };

    listarLivrosEmOrdem(livro);
    printf("\n");
    listarPrecosEmOrdem(livro);

    return 0;
}

int trocaValores(int ordem[], int icont, int jcont){
    int ligacao;
    ligacao = ordem[icont];
    ordem[icont] = ordem[jcont];
    ordem[jcont] = ligacao;

    return TRUE;
}

void listarLivrosEmOrdem(biblioteca livro[]){
    int icont, jcont, kcont, lcont, trocou = TRUE;
    int ordem[qtdLivros] = {0, 1, 2, 3, 4, 5, 6};
    for (icont = 0, jcont = 0; icont < qtdLivros - 1 && trocou; icont++){
        trocou = FALSE;
        for (kcont = 0, lcont = 0; kcont < qtdLivros - 1 - icont; kcont++){
            while (livro[ordem[kcont]].nome[jcont] == livro[ordem[kcont + 1]].nome[lcont] && livro[ordem[kcont]].nome[jcont]){
                jcont++;
                lcont++;
            }
            if ((livro[ordem[kcont]].nome[jcont] > livro[ordem[kcont + 1]].nome[lcont]) && (livro[ordem[kcont]].nome[jcont] != '\0' && livro[ordem[kcont + 1]].nome[lcont] != '\0'))
                trocou = trocaValores(ordem, kcont, kcont + 1);

            jcont = 0;
            lcont = 0;
        }
    }

    for (icont = 0; icont < qtdLivros; icont++)
        printf("%s - %.2f\n", livro[ordem[icont]].nome, livro[ordem[icont]].preco);

}

void listarPrecosEmOrdem(biblioteca livro[]){
    int icont, jcont, trocou = TRUE;
    int ordem[qtdLivros] = {0, 1, 2, 3, 4, 5, 6};

    for (icont = 0; icont < qtdLivros - 1 && trocou; icont++){
        trocou = FALSE;
        for (jcont = 0; jcont < qtdLivros - 1 - icont; jcont++){
            if (livro[ordem[jcont]].preco > livro[ordem[jcont + 1]].preco)
                trocou = trocaValores(ordem, jcont, jcont + 1);
        }
    }
     
    for (icont = 0; icont < qtdLivros; icont++)
        printf("%.2f - %s\n", livro[ordem[icont]].preco, livro[ordem[icont]].nome);

}