//Remover Iterativamente Nós em Árvore Binária de Busca
#include <iostream>
using namespace std;

struct No
{
    int valor;
    No* esq;
    No* dir;
};

void inserir(int valor, No*& raiz)
{
    if(raiz == nullptr)
        raiz = new No{valor, nullptr, nullptr};
    else
        if(valor < raiz->valor)
            inserir(valor, raiz->esq);
        else
            inserir(valor, raiz->dir);
}

void emOrdem(No* raiz)
{
    if(raiz == nullptr)
        return;

    emOrdem(raiz->esq);
    cout << raiz->valor << " ";
    emOrdem(raiz->dir);
}

No* buscarNo(int valor, No* raiz, No*& pai)
{
    No* atual = raiz;
    pai = nullptr;

    while(atual)
    {
        if(valor == atual->valor)
            return atual;

        pai = atual;

        if(valor < atual->valor)
            atual = atual->esq;
        else
            atual = atual->dir;
    }

    return nullptr;
}

void remover(int valor, No*& raiz)
{
    No* pai = nullptr;
    No* noRem = buscarNo(valor, raiz, pai);

    if (noRem == nullptr)
    {
        cout << "Valor nao encontrado." << endl;
        return;
    }

    cout << "Removendo o valor ..: " << noRem->valor << endl;

    //se ele so tiver um filho
    if(noRem->esq == nullptr || noRem->dir == nullptr)
    {
        No* filho = nullptr;

        if(noRem->esq != nullptr)
            filho = noRem->esq;
        else
            filho = noRem->dir;

        if(pai == nullptr)
        {
            delete raiz;
            raiz = filho;
        }
        else
        {
            if(pai->esq == noRem)
                pai->esq = filho;
            else
                pai->dir = filho;

            delete noRem;
        }
    }
    else //se ele tiver os dois filhos
    {
        No* paiSub = noRem;
        No* sub = noRem->esq;

        while(sub->dir != nullptr)
        {
            paiSub = sub;
            sub = sub->dir;
        }

        noRem->valor = sub->valor;

        if(paiSub != noRem)
            paiSub->dir = sub->esq;
        else
            paiSub->esq = sub->esq;

        delete sub;
    }

    cout << "Arvore Atual .......: ";
    emOrdem(raiz);
    cout << "\n\n";
}

int main(void)
{
    No* raiz = nullptr;

    inserir(67, raiz);
    inserir(94, raiz);
    inserir(25, raiz);
    inserir(21, raiz);
    inserir(99, raiz);
    inserir(48, raiz);
    inserir(66, raiz);

    cout << "---------------------------" << endl;
    cout << "| Arvore Antes da Remocao |" << endl;
    cout << "---------------------------" << endl;
    emOrdem(raiz);
    cout << "\n\n";

    remover(21, raiz);
    remover(94, raiz);
    remover(25, raiz);

    cout << "----------------" << endl;
    cout << "| Arvore Final |" << endl;
    cout << "----------------" << endl;
    emOrdem(raiz);
    cout << "\n";

    return 0;
}
