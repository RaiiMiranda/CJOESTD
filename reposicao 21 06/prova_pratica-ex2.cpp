//Implementação e Comparação de Algoritmos de Ordenação
#include <iostream>
#include <chrono> //para medir tempo
#include <random> //para gerar arrays aleatorios
using namespace std;

//Funcao pra imprimir o array
void printArray(int arr[])
{
    cout << "[";
    for(int i = 0; i < 20; i++)
    {
        cout << arr[i];
        if(i < 19)
            cout << ", ";
    }
    cout << "]" << endl;
}

//Funcao que implementa o Selection Sort
void selectionSort(int arr[], int n)
{
    int i, j, indice_minimo;

    for(i = 0; i < n - 1; i++)
    {
        indice_minimo = i;

        //para encontrar o menor elemento na parte nao ordenada
        for(j = i + 1; j < n; j++)
            if(arr[j] < arr[indice_minimo])
                indice_minimo = j;

        //troca se for menor
        if(indice_minimo != i)
        {
            int temp = arr[i];
            arr[i] = arr[indice_minimo];
            arr[indice_minimo] = temp;
        }
    }
}

//Funcao Merge (intercalacao)
void merge(int arr[], int inicio, int meio, int fim)
{
    //tamanho dos subarrays
    int n1 = meio - inicio + 1;
    int n2 = fim - meio;

    //cria arrays temporários para as duas metades
    int* L = new int[n1];
    int* R = new int[n2];

    //copia dados das duas metades para os arrays temporários
    for(int i = 0; i < n1; i++)
        L[i] = arr[inicio + i];

    for(int j = 0; j < n2; j++)
        R[j] = arr[meio + 1 + j];

    //mescla os arrays temporarios de volta em arr[inicio..fim]
    int i = 0;      //indice inicial do primeiro subarray
    int j = 0;      //indice inicial do segundo subarray
    int k = inicio; //indice inicial do array mesclado

    //compara os elementos dos dois arrays e os coloca na posicao certa
    while(i < n1 && j < n2)
    {
        if(L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }

        k++;
    }

    //copia os elementos restantes de L[], se houver
    while(i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    //copia os elementos restantes de R[], se houver
    while(j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }

    //libera a memória alocada para os arrays temporarios
    delete [] L;
    delete [] R;
}

//Funcao principal do Merge Sort
void mergeSort(int arr[], int inicio, int fim)
{
    if(inicio < fim)
    {
        //encontra o ponto médio
        int meio = inicio + (fim - inicio) / 2;

        //ordena a primeira e a segunda metade
        mergeSort(arr, inicio, meio);
        mergeSort(arr, meio + 1, fim);

        //mescla as metades ordenadas
        merge(arr, inicio, meio, fim);
    }
}

//Funcao para gerar array aleatorio
void generateRandomArray(int arr[], int n)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 10000); //entre 1 e 10.000

    for(int i = 0; i < n; i++)
        arr[i] = dis(gen);
}

//Funcao para medir tempo
double measureTime(int arr[], int n, bool isSelection)
{
    if(isSelection)
    {
        auto start = chrono::high_resolution_clock::now();
        selectionSort(arr, n);
        auto end = chrono::high_resolution_clock::now();

        auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
        return duration.count() / 1000.0; //retorna em milissegundos
    }
    else
    {
        auto start = chrono::high_resolution_clock::now();
        mergeSort(arr, 0, n - 1);
        auto end = chrono::high_resolution_clock::now();

        auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
        return duration.count() / 1000.0; //retorna em milissegundos
    }

}

void timeExecution(int arr[], int n)
{
    bool isSelection = true;
    generateRandomArray(arr, n);

    int arrCopia[n];
    for(int i = 0; i < n; i++)
        arrCopia[i] = arr[i];

    cout << "Array Original (primeiros 20): "; printArray(arr);

    double timeSelection = measureTime(arr, n, isSelection);
    cout << "\nSelection Sort:" << endl;
    cout << "Array Ordenado (primeiros 20): "; printArray(arr);
    cout << "Tempo de execucao: " << timeSelection << " ms\n\n";

    isSelection = false;
    double timeMerge = measureTime(arrCopia, n, isSelection);
    cout << "Merge Sort:" << endl;
    cout << "Array Ordenado (primeiros 20): "; printArray(arrCopia);
    cout << "Tempo de execucao: " << timeMerge << " ms\n\n";

    // Complexidade de Tempo
    // Selection Sort: O(n²)
    // Merge Sort: O(n log n)

    // Conforme vai aumentando a entrada é possível ver a grande diferença de tempo de execução,
    // sendo o Merge Sort muito mais rápido em comparação com o Selection Sort
}

int main(void)
{
    //array com 1000 elementos
    const int n = 1000;
    int arr[n];
    timeExecution(arr, n);

    return 0;
}
