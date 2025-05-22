
#include <iostream>
#include <string>
using namespace std;

struct No
{
    string caractere;
    No* prox;
    No* ant;
};


inserir_inicio(No* no, string palavra)
{
    //precisa comparar inicio com fim ate o centro
    //ve caractere por caractere

    No* novoNo = new No{caractere, nullptr, nullptr};

    while(palavra.length)
    {
        for(c : palavra)
        {
            //ultimo cade
            tamanho = palavra.length();

        }
    }

}

inserir_fim(No* no)
{
    //?
}

remover_inicio()
{

}

remover_fim()
{

}

int main(void)
{
    No* no = nullptr;
    string palavra;
    getline(cin, palavra);

    if(palavra.length() % 2 != 0)
    {
        inserir_inicio(no, palavra);
        inserir_fim(no);
    }

    return 0;
}
