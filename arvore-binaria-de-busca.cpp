// Programa Árvore Binária de Busca
#include <iostream>
#include <string>
using namespace std;

struct No
{
    string mes;
    No* esq;
    No* dir;
};

void inserir(string mes, No*& raiz)
{
    if(raiz == nullptr)
        raiz = new No{mes, nullptr, nullptr};
    else
    {
        if(mes < raiz->mes)
            inserir(mes, raiz->esq);
        else
            inserir(mes, raiz->dir);
    }
}

void exibir_em_ordem(No* raiz)
{
    if(raiz == nullptr)
        return;

        exibir_em_ordem(raiz->esq);
        cout << raiz->mes << " ";
        exibir_em_ordem(raiz->dir);
}

void exibir_em_pre_ordem(No* raiz)
{
    if(raiz == nullptr)
        return;

        cout << raiz->mes << " ";
        exibir_em_pre_ordem(raiz->esq);
        exibir_em_pre_ordem(raiz->dir);
}

int main(void)
{
    No* no = nullptr;

    inserir("abril", no);
    inserir("marco", no);
    inserir("outubro", no);
    inserir("janeiro (parabens pra mim)", no);
    exibir_em_ordem(no);
    exibir_em_pre_ordem(no);

    return 0;
}

