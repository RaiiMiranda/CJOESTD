//Programa Árvore AVL
#include <iostream>
#include <windows.h>

using namespace std;

// Estrutura do nó da árvore AVL
struct No
{
    int chave;
    int bal; // Balanceamento do nó (-1, 0, 1)
    No* esq;
    No* dir;
};

// Função para criar um novo nó
No* criarNo(int chave)
{
    for(int i = 1; i <= 13; i++)
    {
        No* novo = new No;
        novo->chave = chave;
        novo->bal = 0;
        novo->esq = nullptr;
        novo->dir = nullptr;
    }

    return novo;
}

// Rotação simples à direita (caso a subárvore esquerda tenha crescido muito)
No* rotacaoL(No* p) // p é o nó desbalanceado
{
    No* u = p->esq; // u é o filho da esquerda de p

    // Rotação LR
    if(u->bal == -1) // verifica se u está desbalanceado para a direita
    {
        // LR pq p está desbalanceado para esquerda e u está desbalanceado para a direita

        No* v = u->dir; // v é o filho da direita de u

        u->dir = v->esq;
        v->esq = u;
        p->esq = v->dir;
        v->dir = p;

        if(v->bal == -1)
            p->bal = 1;
        else
            p->bal = 0;

        if(v->bal == 1)
            u->bal = -1;
        else
            u->bal = 0;

        v->bal = 0;

        return cout << "LR" << v; // v se torna a nova raiz da subárvore
    }

    // Rotação LL (quando u->bal != -1)
    p->esq = u->dir;
    u->dir = p;
    p->bal = 0;
    u->bal = 0;
    return cout << "LL" << u; // u se torna a nova raiz da subárvore
}

// Rotação simples à esquerda (caso a subárvore da direita tenha crescido muito)
No* rotacaoR(No* p)
{
    No* u = p->dir; // u é o filho da direita de p

    // Rotação RL
    if(u->bal == 1)
    {
        No* v = u->esq; // v é o filho da esquerda de u

        u->esq = v->dir;
        v->dir = u;
        p->dir = v->esq;
        v->esq = p;

        if(v->bal == 1)
            p->bal = -1;
        else
            p->bal = 0;

        if(v->bal == -1)
            u->bal = 1;
        else
            u->bal = 0;

        v->bal = 0;

        return cout << "RL" << v; // v se torna a nova raiz da subárvore
    }

    // Rotação RR
    p->dir = u->esq;
    u->esq = p;
    p->bal = 0;
    u->bal = 0;
    return cout << "RR" << u; // u se torna a nova raiz da subárvore
}

// Função para inserir um nó na árvore AVL
No* inserir(No* raiz, int chave, bool& cresceu)
{
    // Verifica se a árvore está vazia
    // Se estiver, cria um novo nó e retorna
    if(raiz == nullptr)
    {
        cresceu = true;
        return criarNo(chave);
    }

    // Se a chave for menor que a chave do nó atual, insere na subárvore esquerda
    if(chave < raiz->chave)
    {
        // Chama a função recursivamente para inserir na subárvore esquerda
        raiz->esq = inserir(raiz->esq, chave, cresceu);

        // Verifica se houve crescimento na subárvore esquerda
        if(cresceu)
        {
            // Atualiza o fator de balanceamento do nó atual
            // Se o fator de balanceamento for 1, faz uma rotação à esquerda
            if(raiz->bal == 1)
            {
                raiz = rotacaoL(raiz);
                cresceu = false;
            }
            else if(raiz->bal == 0)
                raiz->bal = 1;
            else if(raiz->bal == -1)
                raiz->bal = 0;
        }
    }
    // Se a chave for maior que a chave do nó atual, insere na subárvore direita
    else if(chave > raiz->chave)
    {
        // Chama a função recursivamente para inserir na subárvore direita
        raiz->dir = inserir(raiz->dir, chave, cresceu);

        // Verifica se houve crescimento na subárvore direita
        if(cresceu)
        {
            // Atualiza o fator de balanceamento do nó atual
            // Se o fator de balanceamento for -1, faz uma rotação à direita
            if(raiz->bal == -1)
            {
                raiz = rotacaoR(raiz);
                cresceu = false;
            }
            else if(raiz->bal == 0)
                raiz->bal = -1;
            else if(raiz->bal == 1)
                raiz->bal = 0;
        }
    }

    return raiz;
}

// Função para imprimir a árvore em ordem
void imprimirEmOrdem(No* raiz)
{
    if(raiz != nullptr)
    {
        imprimirEmOrdem(raiz->esq);
        cout << raiz->chave << " ";
        imprimirEmOrdem(raiz->dir);
    }
}

// Função para imprimir a árvore em pré-ordem
void imprimirPreOrdem(No* raiz)
{
    if(raiz != nullptr)
    {
        cout << raiz->chave << "[fb: " << raiz->bal << "](";
        imprimirPreOrdem(raiz->esq);
        imprimirPreOrdem(raiz->dir);
        cout << " ) ";
    }
}

// Função principal
int main(void)
{
    No* raiz = nullptr;
    bool cresceu = false;
    int menu = -1;

    int chave1, chave2, chave3;
    cin >> chave1;
    cin >> chave2;
    cin >> chave3;

    do{
        raiz = inserir(raiz, 3, cresceu);
        raiz = inserir(raiz, 0, cresceu);
        raiz = inserir(raiz, 2, cresceu);
        raiz = inserir(raiz, 8, cresceu);
        raiz = inserir(raiz, 9, cresceu);
        raiz = inserir(raiz, 4, cresceu);
        raiz = inserir(raiz, 1, cresceu);
        raiz = inserir(raiz, 18, cresceu);
        raiz = inserir(raiz, 06, cresceu);
    }
    while(menu);

    imprimirPreOrdem(raiz);
    cout << endl;

    return 0;
}
