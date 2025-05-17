//Prova Pr�tica de Revis�o � Estrutura de Dados
#include <iostream>
#include <string>
using namespace std;

//-------------------------------------------------------------------------------------------------------------------------
// EXERC�CIO 01 - Lista Duplamente Encadeada como Fila e Pilha ------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------
//N� em Lista Duplamente Encadeada
struct No
{
    int valor;
    No* proximo;
    No* anterior;
};

//Operar a lista como Fila (FIFO) ------------------------------------------------------------------------------------------
No* primeiro;
No* ultimo;

void inserir_fila(int valor)
{
    No* novoNo = new No{valor, nullptr, nullptr};

    //se a fila estiver vazia
    if(ultimo == nullptr)
        ultimo = primeiro = novoNo; //ent�o insere em primeiro na fila
    else //se n�o estiver vazia
    {
        ultimo->proximo = novoNo; //ent�o conecta o novoNo como pr�ximo do �ltimo n�
        novoNo->anterior = ultimo; //aponta o aterior do novoNo para o n� que antes era o �ltimo
        ultimo = novoNo; //novoNo passa a ser o �ltimo da fila
    }

    cout << valor << " ";
}

void remover_fila()
{
    //se ultimo = nullptr, ent�o a fila est� vazia
    if(ultimo == nullptr)
    {
        cout << "A fila est� vazia, nenhum valor pode ser removido!" << endl;
        return;
    }

    //se n�o estiver vazia
    No* temp = primeiro; //ponteiro tempor�rio para guardar o n� que ser� removido para depois liberar a mem�ria
    cout << temp->valor << " ";

    //primeiro passa a apontar pro pr�ximo n�
    primeiro = primeiro->proximo;

    //se o n� que estava depois do atual ainda existir
    if(primeiro != nullptr)
        primeiro->anterior = nullptr; //ent�o o novo primeiro tem como anterior nulo
    else
        ultimo = nullptr; //se a fila ficou vazia, ent�o o ultimo passa a ser nulo tamb�m

    delete temp; //libera a mem�ria
}

//Operar a lista como Pilha (LIFO) ------------------------------------------------------------------------------------------
No* topo;

void inserir_pilha(int valor)
{
    No* novoNo = new No{valor, nullptr, nullptr};

    //se a pilha estiver vazia
    if(topo == nullptr)
        topo = novoNo; //ent�o insere no topo da pilha
    else //se n�o estiver vazia
    {
        novoNo->anterior = topo; //ent�o anterior do novoNo passa a apontar ao antigo topo
        topo->proximo = novoNo; //antigo topo passa a apontar para o novoNo
        topo = novoNo; //topo da pilha passa a ser o novoNo
    }

    cout << valor << " ";
}

void remover_pilha()
{
    //se o topo for nulo, ent�o a pilha est� vazia
    if(topo == nullptr)
    {
        cout << "A pilha est� vazia, nenhum valor pode ser removido!" << endl;
        return;
    }

    //se n�o estiver vazia
    No* temp = topo;
    cout << temp->valor << " ";

    topo = topo->anterior; //topo passa a apontar para o n� anterior

    //se o topo n�o for nulo
    if(topo != nullptr)
        topo->proximo = nullptr; //ent�o o proximo do topo fica nulo

    delete temp; //libera a mem�ria
}

//---------------------------------------------------------------------------------------------------------------------------
// EXERC�CIO 02 - Estrutura de N�s de �rvores -------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------
//N� em �rvore Bin�ria
struct NoEmBinaria
{
    int chave;
    NoEmBinaria* esq;
    NoEmBinaria* dir;
};

//N� em �rvore N-�ria
struct NoEmNAria
{
    int chave;
    NoEmNAria* primeiro_filho;
    NoEmNAria* proximo_irmao;
};

//N� em �rvore AVL
struct NoEmAVL
{
    int chave;
    int fb;
    NoEmAVL* esq;
    NoEmAVL* dir;
};

//---------------------------------------------------------------------------------------------------------------------------
// EXERC�CIO 03 - Identifica��o de Rota��es em uma �rvore AVL ---------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------

//rota��o LR (rota��o dupla: esquerda-direita)
//ocorre se o filho for menor que a raiz e o neto for maior que seu pai

//rota��o LL (rota��o simples � direita)
//ocorre se o filho for menor que a raiz e o neto for menor que seu pai

//rota��o RL (rota��o dupla: direita-esquerda)
//ocorre se o filho for maior que a raiz e o neto for menor que seu pai

//rota��o RR (rota��o simples � esquerda)
//ocorre se o filho for maior que a raiz e o neto for maior que seu pai

string identificarRotacao(int raiz, int filho, int neto)
{
    //se o filho for menor que a raiz, ent�o est� na esquerda
    if(filho < raiz)
    {
        //se o neto est� a esquerda do filho, ent�o retorna LL
        if(neto < filho) return "LL"; //raiz, filho, neto = 30, 20, 10

        //se o neto est� a direita do filho e na sub�rvore da esquerda, ent�o retorna LR
        if(neto > filho && neto < raiz) return "LR"; //raiz, filho, neto = 30, 10, 20
    }
    else //se n�o o filho est� na direita
    {
        //se o neto est� a direita do filho, ent�o retorna RR
        if(neto > filho) return "RR"; //raiz, filho, neto = 10, 20, 30

        //se o neto est� a esquerda do filho e na sub�rvore da direita, ent�o retorna RL
        if(neto < filho && neto > raiz) return "RL"; //raiz, filho, neto = 10, 30, 20
    }

    //se n�o a �rvore est� balanceada
    return "Nenhuma";
}

int main(void)
{
    setlocale(LC_ALL, "Portuguese_Brazil.1252");

    cout << "------------------------";
    cout << "\n|     EXERC�CIO 01     |" << endl;
    cout << "------------------------\n";
    cout << "\n-------- Fila --------" << endl;
    cout << "Valores inseridos ...:" << endl;
    inserir_fila(5);
    inserir_fila(3);
    inserir_fila(7);
    inserir_fila(8);

    cout << "\n\nValores removidos ...:" << endl;
    remover_fila();
    remover_fila();

    cout << "\n\n-------- Pilha -------" << endl;
    cout << "Valores inseridos ...:" << endl;
    inserir_pilha(5);
    inserir_pilha(3);
    inserir_pilha(7);
    inserir_pilha(8);

    cout << "\n\nValores removidos ...:" << endl;
    remover_pilha();
    remover_pilha();

    cout << "\n\n------------------------";
    cout << "\n|     EXERC�CIO 03     |" << endl;
    cout << "------------------------\n";

    int chave1, chave2, chave3;

    cout << "\n----- �rvore AVL -----\n" << endl;
    cout << "Insira o 1o. valor: "; cin >> chave1;
    cout << "Insira o 2o. valor: "; cin >> chave2;
    cout << "Insira o 3o. valor: "; cin >> chave3;

    string rotacao = identificarRotacao(chave1, chave2, chave3);
    cout << "\nRota��o necess�ria: " << rotacao << endl;

    return 0;
}
