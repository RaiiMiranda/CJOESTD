//Implementação de Tabela Hash
#include <iostream>
#include <cmath>
using namespace std;

const int TAMANHO = 17; //tamanho de 17

//estrutura dos elementos da lista encadeada
struct Elemento
{
    char valor[50];
    Elemento* prox; //para casos de colisao ai vai pro proximo
};

//estrutura da tabela hash
struct TabelaHash
{
    Elemento* tabela[TAMANHO];
};

//funcao que cria a tabela hash
TabelaHash* criarTabela()
{
    //aloca memoria para a tabela hash
    TabelaHash* th = (TabelaHash*) malloc(sizeof(TabelaHash));

    //inicializando todas as posicoes como vazias
    for(int i = 0; i < TAMANHO; i++)
        th->tabela[i] = nullptr;

    return th;
}

//funcao hash por divisao com processamento incremental de caracteres
int hashFunction(const char* chave)
{
    int vh = 0;
    int soma = 0;

    for(int i = 0; chave[i] != '\0'; i++)
    {
        vh = (vh * pow(7,i) * chave[i]);
        soma += vh;
    }

    vh = soma % TAMANHO;

    return vh;
}

void inserir(string th[], const char* valor)
{
    int vh = hashFunction(valor); //calcula o indice usando a funcao hash
    cout << "Tentando inserir: \"" << valor << "\" -> indice " << vh << endl;

    Elemento* novo = (Elemento*) malloc(sizeof(Elemento));
    strcpy(novo->valor, valor);  //copia o valor da chave

    cout << "Colisao ao inserir " << novo->valor << " na posicao " << vh << "." << endl;
    novo->prox = th->tabela[vh]; //insere o novo elemento no inicio da lista da posicao vh
    th->tabela[vh] = novo;       //atualiza o ponteiro da tabela
}

void imprimirTabela(string tabela[])
{
    for(int i = 0; i < TAMANHO; i++)
    {
        cout << i << " ";
        Elemento* atual = th->tabela[i];
        while(atual != nullptr)
        {
            cout << atual->valor << " - ";
            atual = atual->prox;
        }
    }
}

int main(void)
{
    TabelaHash* th = criarTabela();

    //inserindo 12 nomes
    inserir(th, "raiane");
    inserir(th, "rufus");
    inserir(th, "roberto");
    inserir(th, "roberta");
    inserir(th, "robson");
    inserir(th, "rubia");
    inserir(th, "rubia");
    inserir(th, "rana");
    inserir(th, "recson");
    inserir(th, "raissa");

    cout << "Tabela Hash Final:" << endl;
    imprimirTabela(th);

    return 0;
}
