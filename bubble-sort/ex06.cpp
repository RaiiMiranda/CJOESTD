//Implementação do algoritmo Bubble Sort - Análise Experimental
#include <iostream>
#include <chrono> //para medir tempo
#include <random> //para gerar arrays aleatorios
using namespace std;

//Funcao bubbleSort - O(n²)
void bubbleSort(int arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n - i - 1; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

//Funcao para gerar array aleatorio
void generateRandomArray(int arr[], int n)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 1000);

    for(int i = 0; i < n; i++)
        arr[i] = dis(gen);
}

//Funcao para medir tempo
double measureTime(int arr[], int n)
{
    auto start = chrono::high_resolution_clock::now();
    bubbleSort(arr, n);
    auto end = chrono::high_resolution_clock::now();

    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    return duration.count() / 1000.0; // retorna em milissegundos
}

//Funcao pra imprimir o array
void printArray(int arr[], int n)
{
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void averageTime(int arr[], int n)
{
    double tempoTotal = 0.0;

    cout << ">> Teste com array de tamanho: " << n << endl;

    for(int i = 0; i < 5; i++)
    {
        generateRandomArray(arr, n);
        double tempoMedido = measureTime(arr, n);

        tempoTotal += tempoMedido;

        cout << "Execucao " << i + 1 << ": " << tempoMedido << " ms\n";
    }

    double tempoMedio = tempoTotal / 5.0;
    cout << "\nTempo medio: " << tempoMedio << " ms\n\n";
}

int main(void)
{
    const int n1 = 100;
    int arr1[n1];
    averageTime(arr1, n1);

    const int n2 = 500;
    int arr2[n2];
    averageTime(arr2, n2);

    const int n3 = 1000;
    int arr3[n3];
    averageTime(arr3, n3);

    const int n4 = 2000;
    int arr4[n4];
    averageTime(arr4, n4);

    return 0;
}
