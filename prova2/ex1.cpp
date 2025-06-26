//Programa de Busca em Profundidade (DFS) em Grafos - Lista de Adjacência
#include <iostream>
using namespace std;

#define BRANCO 0   //o vertice ainda nao foi visitado
#define AMARELO 1  //o vertice é descoberto na busca
#define VERMELHO 2 //ja olhou toda a adjacencia do vertice

struct Adjacencia
{
    int vertice;
    Adjacencia *proximo;
};

struct Vertice
{
    int chave;
    Adjacencia *cabeca;
};

struct Grafo
{
    int vertices;
    Vertice *adj;
};

Grafo* criarGrafo(int V)
{
    //aloca memoria para a estrutura grafo
    Grafo* grafo = new Grafo;

    if(grafo == nullptr)
    {
        cout << "Erro de alocacao de memoria!" << endl;
        exit(1);
    }

    grafo->vertices = V; //total de vertices do grafo

    //aloca memoria para o vetor de vertices
    grafo->adj = new Vertice[V];

    if(grafo->adj == nullptr)
    {
        cout << "Erro de alocacao de memoria!" << endl;
        exit(1);
    }

    //inicializa as listas de adjacencia
    for(int i = 0; i < V; i++)
    {
        grafo->adj[i].chave = i; //identificador de cada vertice
        grafo->adj[i].cabeca = nullptr; //nao tem nenhum vertice conectado a esse por enquanto, a lista esta vazia
    }

    return grafo;
}

void adicionarAresta(Grafo* grafo, int origem, int destino)
{
    //adiciona uma aresta da origem para o destino
    Adjacencia* novaAdj = new Adjacencia;

    novaAdj->vertice = destino;
    novaAdj->proximo = grafo->adj[origem].cabeca;
    grafo->adj[origem].cabeca = novaAdj;

    //para grafos nao-direcionados, tambem adiciona a aresta do destino para a origem
    novaAdj = new Adjacencia;

    novaAdj->vertice = origem;
    novaAdj->proximo = grafo->adj[destino].cabeca;
    grafo->adj[destino].cabeca = novaAdj;
}

//Funcao de busca em profundidade a partir do vertice u
bool buscaEmProfundidade(Grafo *grafo, int u, int *cor, int chaveProcurada)
{
    cor[u] = AMARELO; //vertice atual é descoberto na busca
    cout << "Vertice visitado: " << u << endl;

    //se a chave do vertice for igual a chave procurada
    if(grafo->adj[u].chave == chaveProcurada)
        return true; //entao retorna que achou

    //se nao for
    //entao visita recursivamente a adjacencia do vertice u
    Adjacencia *v = grafo->adj[u].cabeca; //pega a adjacencia do vertice atual

    //enquanto tiver as adjacencias vai visitando todas elas
    while(v)
    {
        //se a cor for branca quer dizer que o vertice ainda nao foi visitado
        if(cor[v->vertice] == BRANCO)
            if(buscaEmProfundidade(grafo, v->vertice, cor, chaveProcurada)) //se o caminho percorrido retornar true, entao achou a chave procurada
                return true; //achou a chave procurada na recursao

        v = v->proximo; //terminou de visitar os filhos, vai para a proxima adjacencia do pai
    }

    cor[u] = VERMELHO; //acabou as adjacencias de u, entao nao tem mais o que visitar e finaliza ele
    return false; //nao achou a chave procurada em nenhum caminho
}

//Funcao que inicializa as cores e inicia busca DFS a partir de todos os vertices que ainda nao foram visitados
bool profundidade(Grafo *grafo, int chave)
{
    int cor[grafo->vertices]; //array que armazena a cor de cada vertice para marcar o estado de cada um

    //inicializa todos os vertices em branco
    for(int u = 0; u < grafo->vertices; u++)
        cor[u] = BRANCO;

    //para quando precisar reiniciar a busca e começar por outro vertice nao visitado
    //percorre todos os vertices do grafo
    for(int u = 0; u < grafo->vertices; u++)
        if(cor[u] == BRANCO) //se o vertice ainda nao foi visitado
            if(buscaEmProfundidade(grafo, u, cor, chave)) //entao visita em profundidade
                return true; //se achar a chave procurada, entao retorna que achou

    return false; //nao achou a chave procurada em nenhum vertice
}

bool ehConectado(Grafo* grafo)
{
    //verificar se todos os vertices estao conectados
    if(todos conectados do grafo)
        return true;
    else
        return false;
}

void liberarGrafo(Grafo* grafo)
{
    for(int i = 0; i < grafo->vertices; ++i)
    {
        Adjacencia* atual = grafo->adj[i].cabeca;

        while(atual != nullptr)
        {
            Adjacencia *proximo = atual->proximo;
            delete atual; //libera o no atual
            atual = proximo;
        }
    }

    delete [] grafo->adj; //libera o vetor de vertices
    delete grafo;         //libera a estrutura do grafo
}

int main(void)
{
    int numVertices = 7; //7 vertices
    Grafo* grafo = criarGrafo(numVertices);

    //adicionar as 9 arestas (grafo nao direcionado conectado)
    adicionarAresta(grafo, 0, 1);
    adicionarAresta(grafo, 0, 4);
    adicionarAresta(grafo, 1, 2);
    adicionarAresta(grafo, 1, 3);
    adicionarAresta(grafo, 1, 4);
    adicionarAresta(grafo, 2, 3);
    adicionarAresta(grafo, 3, 4);
    adicionarAresta(grafo, 0, 2);
    adicionarAresta(grafo, 3, 0);

    if(ehConectado)
        cout << "Grafo 1: Conectado? Sim" << endl;
     else
        cout << "Grafo 1: Conectado? Nao" << endl;

    liberarGrafo(grafo);

    //adicionar as 9 arestas (grafo nao direcionado nao conectado)
    adicionarAresta(grafo, 1, 4);
    adicionarAresta(grafo, 22, 11);
    adicionarAresta(grafo, 33, 44);
    adicionarAresta(grafo, 66, 77);
    adicionarAresta(grafo, 9, 88);
    adicionarAresta(grafo, 99, 6);
    adicionarAresta(grafo, 23, 45);
    adicionarAresta(grafo, 34, 79);
    adicionarAresta(grafo, 988, 654);

    if(ehConectado)
        cout << "Grafo 2: Conectado? Sim" << endl;
     else
        cout << "Grafo 2: Conectado? Nao" << endl;

    liberarGrafo(grafo);

    return 0;
}
