//Implementação do algoritmo Bubble Sort - Visualização do Processo
#include <iostream>
using namespace std;

//Funcao bubbleSort - O(n²)
void bubbleSort(int arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << "Passada " << i + 1 << ":" << endl;

        for(int j = 0; j < n - i - 1; j++)
        {
            cout << "Comparando " << arr[j] << " e " << arr[j + 1] << ": ";

            if(arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                cout << "Troca! -> [";
                for(int r = 0; r < n; r++)
                {
                    cout << arr[r];
                    if(r < n - 1)
                        cout << ", ";
                }
                cout << "]" << endl;
            }
            else
                cout << "Nao troca" << endl;
        }

        cout << "Final da passada " << i + 1 << ": [";
        for(int r = 0; r < n; r++)
        {
            cout << arr[r];
            if(r < n - 1)
                cout << ", ";
        }
        cout << "]\n" << endl;
    }
}

//Funcao pra imprimir o array
void printArray(int arr[], int n)
{
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main(void)
{
    int arr[] = {5, 2, 8, 1, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Array original: ";
    printArray(arr, n);
    cout << endl;

    bubbleSort(arr, n);

    cout << "Array ordenado: ";
    printArray(arr, n);

    return 0;
}
