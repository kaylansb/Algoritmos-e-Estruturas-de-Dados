#define TRUE 1 
#define FALSE 0
#define qtdLivros 6
#define maxCaracPorLivro 15

typedef struct {
    char nome[maxCaracPorLivro];
    float preco;
    int lancamento;
}
biblioteca;

biblioteca livro[qtdLivros] = {
    {"duna\0", 60.90, 1965},
    {"frankenstein\0", 79.90, 1818},
    {"dracula\0", 20.00, 1897},
    {"odisseia\0", 49.99, -700},
    {"biblia\0", 25.50, 400},
    {"alcorao\0", 52.80, 650}, };

void ordenarAlfabeto(int *ordem);
void ordenarPreco(int *ordem);
void ordenarLancamento(int *ordem);
int trocaValores(int ordem[], int icont, int jcont);


int trocaValores(int ordem[], int icont, int jcont){
    int ligacao;
    ligacao = ordem[icont];
    ordem[icont] = ordem[jcont];
    ordem[jcont] = ligacao;

    return TRUE;
}

void ordenarAlfabeto(int *ordem){
    int icont, jcont, kcont, lcont, trocou = TRUE;

    for (icont = 0; icont < qtdLivros; icont++)
        ordem[icont] = icont;

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

}

void ordenarPreco(int *ordem){
    int icont, jcont, trocou = TRUE;

    for (icont = 0; icont < qtdLivros; icont++)
        ordem[icont] = icont;

    for (icont = 0; icont < qtdLivros - 1 && trocou; icont++){
        trocou = FALSE;
        for (jcont = 0; jcont < qtdLivros - 1 - icont; jcont++){
            if (livro[ordem[jcont]].preco > livro[ordem[jcont + 1]].preco)
                trocou = trocaValores(ordem, jcont, jcont + 1);
        }
    }
    
}

void ordenarLancamento(int *ordem){
    int icont, jcont, trocou = TRUE;

    for (icont = 0; icont < qtdLivros; icont++)
        ordem[icont] = icont;

    for (icont = 0; icont < qtdLivros - 1 && trocou; icont++){
        trocou = FALSE;
        for (jcont = 0; jcont < qtdLivros - 1 - icont; jcont++){
            if (livro[ordem[jcont]].lancamento > livro[ordem[jcont + 1]].lancamento)
                trocou = trocaValores(ordem, jcont, jcont + 1);
        }
    }
    
}
