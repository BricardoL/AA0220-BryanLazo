
// C++ program for insertion sort
#include <iostream>
using namespace std;

/* Function to sort an array using insertion sort*/
void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        /* Move elements of arr[0..i-1], that are  
        greater than key, to one position ahead  
        of their current position */
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void insertionSortDesc(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        /* Move elements of arr[0..i-1], that are  
        greater than key, to one position ahead  
        of their current position */
        while (j >= 0 && arr[j] < key) //unique change to desc sort!!!
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// A utility function to print an array of size n
void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

/* Driver code */
int main()
{
    int a;
    cout<<"INSERTION SORT\n";
    cout<<"Ingrese cantidad de numeros a ingresar: ";
    cin>>a;
    int arr[a];
    for (int i = 0; i < a; i++)
    {
        int b;
        cout<<"Ingrese numero: ";
        cin>>b;
        arr[i] = b;
    }

    cout<<"Entered matrix: ";
    for (int i = 0; i<a; i++)
    {
        cout<<arr[i]<<" ";
    }
    

    int n = sizeof(arr) / sizeof(arr[0]);
    insertionSort(arr, n);
    cout << "\nSorted array asc: \n";
    printArray(arr, n);
    cout <<"\nSorted array desc: \n";
    insertionSortDesc(arr, n);
    printArray(arr, n);
    
    return 0;
}

// This is code is contributed by rathbhupendra
