//Implementação de Tabela Hash
#include <iostream>
#include <cstring> //para strcpy() e strcmp()
#include <cstdlib> //para malloc() e free()

const int TAMANHO = 10; //tamanho fixo da tabela hash

//estrutura dos elementos da lista encadeada
struct Elemento
{
    char valor[50];
    Elemento* prox; //para casos de colisao
};

//estrutura da tabela hash
struct TabelaHash
{
    Elemento* tabela[TAMANHO];
};

//funcao que cria a tabela hash
TabelaHash* criarTabela()
{
    //aloca memória para a tabela hash
    TabelaHash* th = (TabelaHash*) malloc(sizeof(TabelaHash));

    //inicializando todas as posicoes como vazias
    for(int i = 0; i < TAMANHO; i++)
        th->tabela[i] = nullptr;

    return th;
}

//funcao hash por divisao com processamento incremental de caracteres
int hashFunction(const char* chave)
{
    //indice da tabela
    int vh = 0;

    //multiplica o valor atual por 3, soma o codigo ASCII do caractere atual
    //e aplica o modulo para manter o valor dentro dos limites da tabela
    for(int i = 0; chave[i] != '\0'; i++)
        vh = (vh * 3 + chave[i]) % TAMANHO; //converte a chave[i] para o seu valor ASCII automaticamente

    //chave = 'uva'
    //vh = (0 * 3 + 117) % 10) = 7
    //vh = (7 * 3 + 118) % 10) = 9
    //vh = (9 * 3 + 97) % 10) = 4
    //chave[3] == '\0' sai do for

    //retorna o indice da tabela (entre 0 e TAMANHO-1)
    return vh;
}

//funcao que insere um valor na tabela hash (usa encadeamento para tratar colisoes)
void inserir(TabelaHash* th, const char* valor)
{
    int vh = hashFunction(valor); //calcula o indice usando a funcao hash

    Elemento* novo = (Elemento*) malloc(sizeof(Elemento));

    strcpy(novo->valor, valor);  //copia o valor da chave
    novo->prox = th->tabela[vh]; //insere o novo elemento no inicio da lista da posicao vh
    th->tabela[vh] = novo;       //atualiza o ponteiro da tabela
}

//funcao que busca um valor na tabela hash
Elemento* buscar(TabelaHash* th, const char* valor)
{
    int vh = hashFunction(valor);     //calcula o indice
    Elemento* atual = th->tabela[vh]; //comeca na lista da posicao vh

    while(atual != nullptr)
    {
        if(strcmp(atual->valor, valor) == 0)
            return atual; //encontrou
        atual = atual->prox; //continua a lista
    }

    return nullptr; //nao encontrou
}

//funcao que remove um elemento da tabela hash
void remover(TabelaHash* th, const char* valor)
{
    int vh = hashFunction(valor);     //calcula o indice
    Elemento* atual = th->tabela[vh]; //comeca na lista da posicao vh
    Elemento* anterior = nullptr;

    while(atual != nullptr)
    {
        if(strcmp(atual->valor, valor) == 0)
        {
            if(anterior == nullptr)
                th->tabela[vh] = atual->prox; //remove o primeiro elemento
            else
                anterior->prox = atual->prox; //remove elementos no meio ou fim da lista

            free(atual); //libera a memoria
            std::cout << "Valor removido com sucesso!\n";
            return;
        }

        anterior = atual;
        atual = atual->prox;
    }

    std::cout << "Valor nao encontrado.\n";
}

//funcao que imprime a tabela hash atual
void imprimir(TabelaHash* th)
{
    for(int i = 0; i < TAMANHO; i++)
    {
        std::cout << "[" << i << "]: ";
        Elemento* atual = th->tabela[i];
        while(atual != nullptr)
        {
            std::cout << atual->valor << " -> ";
            atual = atual->prox;
        }
        std::cout << "NULL\n";
    }
}

int main(void)
{
    TabelaHash* th = criarTabela();

    inserir(th, "tangerina");
    inserir(th, "uva");
    inserir(th, "mirtilo");
    inserir(th, "pessego");
    inserir(th, "pera");

    std::cout << "-------- Tabela Hash ---------\n";
    std::cout << "\nTabela apos insercoes:\n";
    imprimir(th);

    std::cout << "\nBuscando 'mirtilo': ";
    std::cout << (buscar(th, "mirtilo") ? "Encontrado\n" : "Nao encontrado\n");
    std::cout << "Buscando 'pneu': ";
    std::cout << (buscar(th, "pneu") ? "Encontrado\n" : "Nao encontrado\n");

    std::cout << "\nRemovendo 'pneu'\n";
    remover(th, "pneu");

    std::cout << "\nRemovendo 'pera'\n";
    remover(th, "pera");

    std::cout << "Tabela apos remocao:\n";
    imprimir(th);

    return 0;
}
