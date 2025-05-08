//Modos de Percorrer Árvore Binária de Busca
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

int contagem(No* raiz)
{
    if(raiz == nullptr)
        return 0;

    return contagem(raiz->esq) + 1 + contagem(raiz->dir);
}

//esq -> raiz -> dir
void emOrdem(No* raiz)
{
    if(raiz == nullptr)
        return;

    emOrdem(raiz->esq);
    cout << raiz->valor << " ";
    emOrdem(raiz->dir);
}

//dir -> raiz -> esq
void emOrdemReversa(No* raiz)
{
    if(raiz == nullptr)
        return;

    emOrdemReversa(raiz->dir);
    cout << raiz->valor << " ";
    emOrdemReversa(raiz->esq);
}

//raiz -> esq -> dir (raiz primeiro)
void emPreOrdem(No* raiz)
{
    if(raiz == nullptr)
        return;

    cout << raiz->valor << " ";
    emPreOrdem(raiz->esq);
    emPreOrdem(raiz->dir);
}

//esq -> dir -> raiz (filhos primeiro)
void emPosOrdem(No* raiz)
{
    if(raiz == nullptr)
        return;

    emPosOrdem(raiz->esq);
    emPosOrdem(raiz->dir);
    cout << raiz->valor << " ";
}

//nivel por nivel
struct NoFila
{
    No* valor;
    NoFila* proximo;
};

struct Fila
{
    NoFila* primeiro = nullptr;
    NoFila* ultimo = nullptr;

    bool vazia()
    {
        return primeiro == nullptr;
    }

    void enfileirar(No* valor)
    {
        NoFila* novoNo = new NoFila{valor, nullptr};

        if(ultimo == nullptr)
            primeiro = ultimo = novoNo;
        else
        {
            ultimo->proximo = novoNo;
            ultimo = novoNo;
        }
    }

    No* desenfileirar()
    {
        if(vazia())
            return nullptr;

        NoFila* temporario = primeiro;
        No* valor = temporario->valor;

        primeiro = primeiro->proximo;

        if(primeiro == nullptr)
            ultimo = nullptr;

        delete temporario;
        return valor;
    }
};

void emLargura(No* raiz)
{
    if(raiz == nullptr)
        return;

    Fila fila;
    fila.enfileirar(raiz);

    while(!fila.vazia())
    {
        No* atual = fila.desenfileirar();
        cout << atual->valor << " ";

        if(atual->esq != nullptr)
            fila.enfileirar(atual->esq);

        if(atual->dir != nullptr)
            fila.enfileirar(atual->dir);
    }
}

int main(void)
{
    No* raiz = nullptr;

    inserir(67, raiz);
    inserir(82, raiz);
    inserir(25, raiz);
    inserir(33, raiz);
    inserir(72, raiz);
    inserir(15, raiz);
    inserir(96, raiz);

    cout << "Em ordem: " << endl;
    emOrdem(raiz);
    cout << "\n\n";

    cout << "Em ordem reversa: " << endl;
    emOrdemReversa(raiz);
    cout << "\n\n";

    cout << "Em pre-ordem: " << endl;
    emPreOrdem(raiz);
    cout << "\n\n";

    cout << "Em pos-ordem: " << endl;
    emPosOrdem(raiz);
    cout << "\n\n";

    cout << "Em largura: " << endl;
    emLargura(raiz);
    cout << "\n";

    return 0;
}
