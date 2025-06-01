//Programa de Representação de Grafos com Matriz de Adjacência
#include <iostream>
#include <iomanip>
using namespace std;

#define MAX_VERTICES 5

//Estrutura para representar o grafo usando matriz de adjacencia
struct Grafo
{
    int matrizAdjacencia[MAX_VERTICES][MAX_VERTICES];
    int numVertices;
};

//Funcao para criar um grafo com numero especifico de vertices
Grafo* criarGrafo(int V)
{
    Grafo* grafo = new Grafo; //aloca memoria para a estrutura Grafo

    if(grafo == nullptr)
    {
        cout << "Erro de alocacao de memoria!" << endl;
        exit(1);
    }

    grafo->numVertices = V;

    //inicializa todos os elementos da matriz adjacencia como nulo
    for(int i = 0; i < V; i++)
        for(int j = 0; j < V; j++)
            grafo->matrizAdjacencia[i][j] = 0;

    return grafo;
}

//Funcao para adicionar uma aresta a um grafo nao-direcionado
void adicionarAresta(Grafo* grafo, int origem, int destino)
{
    //adiciona uma aresta da origem para o destino
    grafo->matrizAdjacencia[origem][destino] = 1;

    //adiciona uma aresta do destino para a origem
    grafo->matrizAdjacencia[destino][origem] = 1;
}

//Funcao para imprimir a representacao do grafo
void imprimirGrafo(Grafo* grafo)
{
    cout << "Representacao do Grafo \n(Matriz de Adjacencia)\n\n";

    cout << " ";
    for(int i = 0; i < grafo->numVertices; i++)
        cout << setw(2) << i;

    cout << endl;

    for(int i = 0; i < grafo->numVertices; i++)
    {
        cout << i;
        for(int j = 0; j < grafo->numVertices; j++)
            cout << setw(2) << grafo->matrizAdjacencia[i][j];
        cout << endl;
    }
}

//Funcao para liberar a memoria alocada pelo grafo
void liberarGrafo(Grafo* grafo)
{
    delete grafo; //libera a estrutura do grafo
}

//Funcao principal
int main(void)
{
    int numVertices = 5;
    Grafo* grafo = criarGrafo(numVertices);

    adicionarAresta(grafo, 0, 1);
    adicionarAresta(grafo, 0, 4);
    adicionarAresta(grafo, 1, 2);
    adicionarAresta(grafo, 1, 3);
    adicionarAresta(grafo, 1, 4);
    adicionarAresta(grafo, 2, 3);
    adicionarAresta(grafo, 3, 4);

    imprimirGrafo(grafo);

    liberarGrafo(grafo);

    return 0;
}

