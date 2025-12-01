#include <stdlib.h>
typedef struct ListaArvores{
    struct TreeNode **arvores;
    int tamanho;
    int capacidade;
} ListaArvores;
ListaArvores* gerarFBT(int n, ListaArvores** dp);

struct TreeNode* criarNo(){
    struct TreeNode* no = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    no->val = 0;
    no->left = NULL;
    no->right = NULL;
    return no;
}

ListaArvores* criarListaArvores(int capacidade){
    ListaArvores* lista = (ListaArvores*)malloc(sizeof(ListaArvores));
    lista->arvores = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * capacidade);
    lista->tamanho = 0;
    lista->capacidade = capacidade;
    return lista;
}

void inserirArvore(ListaArvores* lista, struct TreeNode* arvore){
    if (lista->tamanho >= lista->capacidade){
        lista->capacidade *= 2;
        lista->arvores = (struct TreeNode**)realloc(
            lista->arvores,
            sizeof(struct TreeNode*) * lista->capacidade
        );
    }
    lista->arvores[lista->tamanho++] = arvore;
}

struct TreeNode** allPossibleFBT(int n, int* returnSize){
    ListaArvores* dp[21] = {0};
    ListaArvores* resultado = gerarFBT(n, dp);
    *returnSize = resultado->tamanho;
    return resultado->arvores;
}

ListaArvores* gerarFBT(int n, ListaArvores** dp){
    if (n % 2 == 0) return criarListaArvores(0);
    if (dp[n] !=NULL) return dp[n];
    ListaArvores* resultado = criarListaArvores(10);
    if (n ==1) {
        inserirArvore(resultado, criarNo());
        dp[1] =resultado; 
        return resultado;
    }
    for (int nosEsq = 1; nosEsq < n; nosEsq++){
        int nosDir = n -1 -nosEsq;   
        ListaArvores* arvoresEsq = gerarFBT(nosEsq, dp);
        ListaArvores* arvoresDir = gerarFBT(nosDir, dp);
        for (int i = 0; i < arvoresEsq->tamanho; i++){
            for (int j = 0; j < arvoresDir->tamanho; j++){
                struct TreeNode* raiz = criarNo();
                raiz->left = arvoresEsq->arvores[i];
                raiz->right = arvoresDir->arvores[j];
                inserirArvore(resultado, raiz);
            }
        }
    }
    dp[n] =resultado;
    return resultado;
}
