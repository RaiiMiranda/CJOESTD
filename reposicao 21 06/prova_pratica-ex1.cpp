//Implementação de Busca em Largura (BFS) em Grafo - Lista de Adjacência
#include <iostream>
#include <cstdlib> //para malloc e free
using namespace std;

#define MAX_VERTICES 6
#define TAM_FILA 100

// Estrutura de representação de um nó em uma lista encadeada
struct NoLista
{
    int destino;
    NoLista* proximo;
};

// Estrutura para representar o grafo usando lista de adjacência
struct Grafo
{
    NoLista* adjacencias[MAX_VERTICES]; //um array de ponteiros para as 'cabeças' das listas
    int numVertices; //numero real de verices no grafo
};

// Função para criar um nó de lista
NoLista* criarNovoNo(int destino)
{
    NoLista* novoNo = (NoLista*) malloc(sizeof(NoLista)); //aloca memoria

    //verifica se a alocacao foi bem-sucedida
    if(novoNo == nullptr)
    {
        cout << "Erro de alocacao de memoria!" << endl;
        exit(1); //encerra o programa em caso de erro
    }

    novoNo->destino = destino;
    novoNo->proximo = nullptr;
    return novoNo;
}

// Função para criar um grafo com número específico de vértices
Grafo* criarGrafo(int V)
{
    Grafo* grafo = (Grafo*) malloc(sizeof(Grafo)); //aloca memoria para a estrutura Grafo

    if(grafo == nullptr)
    {
        cout << "Erro de alocacao de memoria!" << endl;
        exit(1); //encerra o programa em caso de erro
    }

    grafo->numVertices = V;

    //inicializa todas as listas de adjacencia como vazias
    for(int i = 0; i < V; i++)
        grafo->adjacencias[i] = nullptr;

    return grafo;
}

// Função para adicionar uma aresta a um grafo não-direcionado
void adicionarAresta(Grafo* grafo, int origem, int destino)
{
    //adiciona uma aresta da origem para o destino
    NoLista* novoNo = criarNovoNo(destino);
    novoNo->proximo = grafo->adjacencias[origem]; //o novoNo aponta para o que era o primeiro
    grafo->adjacencias[origem] = novoNo; //e o novoNo se torna o primeiro da lista

    //para grafos nao-direcionados, tbm adiciona a aresta do destino para a origem
    novoNo = criarNovoNo(origem);
    novoNo->proximo = grafo->adjacencias[destino];
    grafo->adjacencias[destino] = novoNo;
}

// Função da Busca em Largura para encontrar o caminho mais curto
void bfs(Grafo* grafo, int verticeInicial, int verticeDestino)
{
    bool visitado[MAX_VERTICES] = {false};
    int pai[MAX_VERTICES];
    int fila[TAM_FILA];
    int inicioFila = 0, fimFila = 0;
    bool encontrado = false;

    for(int i = 0; i < MAX_VERTICES; i++)
        pai[i] = -1;

    visitado[verticeInicial] = true;
    fila[fimFila++] = verticeInicial;

    while(inicioFila < fimFila)
    {
        int atual = fila[inicioFila++];

        if(atual == verticeDestino)
        {
            encontrado = true;
            break;
        }

        NoLista* temp = grafo->adjacencias[atual];
        while(temp != nullptr)
        {
            int vizinho = temp->destino;

            if(!visitado[vizinho])
            {
                visitado[vizinho] = true;
                pai[vizinho] = atual;
                fila[fimFila++] = vizinho;
            }

            temp = temp->proximo;
        }
    }

    if(encontrado)
    {
        int caminho[MAX_VERTICES];
        int tamanho = 0;
        int atual = verticeDestino;

        while(atual != -1)
        {
            caminho[tamanho++] = atual;
            atual = pai[atual];
        }

        cout << "Caminho mais curto de " << verticeInicial << " para " << verticeDestino << ": ";
        for(int i = tamanho - 1; i >= 0; i--)
        {
            cout << caminho[i];
            if(i > 0) cout << " -> ";
        }
        cout << endl;
    }
    else
        cout << "Nao existe caminho de " << verticeInicial << " para " << verticeDestino << "." << endl;
}

// Função para liberar a memória alocada pelo grafo
void liberarGrafo(Grafo* grafo)
{
    for(int i = 0; i < grafo->numVertices; ++i)
    {
        NoLista* atual = grafo->adjacencias[i];

        while(atual != nullptr)
        {
            NoLista* proximo = atual->proximo;
            free(atual); //libera o nó atual
            atual = proximo;
        }
    }

    free(grafo); //libera a estrutura do grafo
}

// Função principal
int main(void)
{
    int numVertices = 6; //grafo com 6 vertices no total
    Grafo* grafo = criarGrafo(numVertices);

    //adiciona 8 arestas
    adicionarAresta(grafo, 0, 1);
    adicionarAresta(grafo, 0, 2);
    adicionarAresta(grafo, 0, 4);
    adicionarAresta(grafo, 1, 2);
    adicionarAresta(grafo, 1, 3);
    adicionarAresta(grafo, 1, 4);
    adicionarAresta(grafo, 2, 3);
    adicionarAresta(grafo, 3, 4);

    bfs(grafo, 0, 3);
    bfs(grafo, 0, 6);

    liberarGrafo(grafo); //liberar a memoria alocada

    return 0;
}
