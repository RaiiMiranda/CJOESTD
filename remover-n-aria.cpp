//Programa de Remoção Recursiva em Árvore N-Ária
#include <iostream>
using namespace std;

struct No
{
    int chave;
    No* primeiro_filho;
    No* proximo_irmao;
};

No* criar_no(int chave)
{
    No* novo_no = new No{chave, nullptr, nullptr};
    return novo_no;
}

void inserir(No* pai, int chave)
{
    No* novo_no = criar_no(chave);

    if(pai->primeiro_filho == nullptr)
        pai->primeiro_filho = novo_no;
    else
    {
        No* irmao = pai->primeiro_filho;

        while(irmao->proximo_irmao != nullptr)
            irmao = irmao->proximo_irmao;

        irmao->proximo_irmao = novo_no;
    }
}

No* buscar(No* raiz, int chave)
{
    if (raiz == nullptr) return nullptr;

    if (raiz->chave == chave) return raiz;

    No* encontrado = buscar(raiz->primeiro_filho, chave);
    if (encontrado != nullptr) return encontrado;

    return buscar(raiz->proximo_irmao, chave);
}

void liberarMemoria(No* raiz)
{
    if(raiz == nullptr) return;

    liberarMemoria(raiz->primeiro_filho);
    liberarMemoria(raiz->proximo_irmao);
    delete raiz;
}

void remover(No*& raiz, int noRem)
{
    //se a raiz estiver vazia nao remove nada
    if(raiz == nullptr) return;

    //se noRem for a raiz remove ele
    if(noRem == raiz->chave)
    {
        liberarMemoria(raiz);
        raiz = nullptr;
        return;
    }

    //se nao, procura entre os filhos diretos da raiz
    No* atual = raiz->primeiro_filho;
    No* anterior = nullptr;

    while(atual != nullptr)
    {
        if(atual->chave == noRem)
        {
            if(anterior == nullptr)
                raiz->primeiro_filho = atual->proximo_irmao;
            else
                anterior->proximo_irmao = atual->proximo_irmao;

            atual->proximo_irmao = nullptr;
            liberarMemoria(atual);
            return;
        }


        anterior = atual;
        atual = atual->proximo_irmao;
    }

    //se nao achar entre os filhos diretos, tenta remover recursivamente nos filhos
    atual = raiz->primeiro_filho;
    while(atual != nullptr)
    {
        remover(atual, noRem);
        atual = atual->proximo_irmao;
    }
}

void exibir(No* raiz, int nivel)
{
    if(raiz == nullptr) return;

    for(int i = 0; i < nivel; i++)
        cout << "  ";
    cout << raiz->chave << endl;

    exibir(raiz->primeiro_filho, nivel + 1);
    exibir(raiz->proximo_irmao, nivel);
}

int main(void)
{
    No* raiz = criar_no(1);

    inserir(raiz, 2);
    inserir(raiz, 3);
    inserir(raiz, 4);

    No* no2 = buscar(raiz, 2);
    if (no2 != nullptr)
    {
        inserir(no2, 5);
        inserir(no2, 6);
    }

    No* no3 = buscar(raiz, 3);
    if (no3 != nullptr)
    {
        inserir(no3, 7);
        inserir(no3, 8);
    }

    cout << "---------------------------" << endl;
    cout << "| Arvore Antes da Remocao |" << endl;
    cout << "---------------------------" << endl;
    exibir(raiz, 0);
    cout << endl;

    cout << "Removendo o no 2..." << endl;
    remover(raiz, 2);
    cout << "Arvore Atual:" << endl;
    exibir(raiz, 0);
    cout << endl;

    cout << "Removendo o no 8..." << endl;
    remover(raiz, 8);
    cout << "Arvore Atual:" << endl;
    exibir(raiz, 0);
    cout << endl;

    cout << "Removendo o no 1..." << endl;
    remover(raiz, 1);
    cout << "Arvore Atual:" << endl;
    exibir(raiz, 0);
    cout << endl;

    cout << "----------------" << endl;
    cout << "| Arvore Final |" << endl;
    cout << "----------------" << endl;
    if(raiz == nullptr)
        cout << "Arvore vazia." << endl;
    else
        exibir(raiz, 0);
    cout << endl;

    liberarMemoria(raiz);
    return 0;
}
