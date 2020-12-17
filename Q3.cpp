#include <iostream>
using namespace std;

const int TSIZE = 100;



class MinHeap {

    int size;
    int* arr;

public:
    int parent(int i)
    {
        return (i - 1) / 2;
    }

    int left(int i)
    {
        return (2 * i + 1);
    }

    int right(int i)
    {
        return (2 * i + 2);
    }
    void swap(int* x, int* y)
    {
        int temp = *x;
        *x = *y;
        *y = temp;
    }


    MinHeap(int SIZE, int input[])
    {
        size = SIZE;
        arr = input;
        buildHeap();
    }

    void heapify(int i)
    {
        {
            int temp1, temp2;
            temp1 = left(i);
            temp2 = right(i);
            int smallest = i;
            if (temp1 < size && arr[temp1] < arr[i])
                smallest = temp1;
            if (temp2 < size && arr[temp2] < arr[smallest])
                smallest = temp2;
            if (smallest != i)
            {
                swap(&arr[i], &arr[smallest]);
                heapify(smallest);
            }
        }
    }

    void buildHeap()
        {
            for (int i = size / 2 - 1; i >= 0; i--)
            {
                heapify(i);
            }
        }
    void FirstKelements(int arr[], int size, int k)
    {

       

        for (int i = k; i < size; i++) {


            if (arr[0] > arr[i])
                continue;


            else {
                arr[0] = arr[i];
                heapify(0);
            }
        }
        cout << endl;
        cout << "K = "<<k << endl;
        cout << "Array = " << endl;
        for (int i = 0; i < k; i++) {
            cout << arr[i] << " ";
        }
        
    }
    
};




int main()
{


    int loopInput;
    int temp = 0;
    int arr[TSIZE];

    while (1)
    {
        cout << "Press 1 to input data into array " << endl;
        cout << "Press 2 to input k and display its result" << endl;
        cout << "Press 3 to end" << endl;
        cin >> loopInput;
        if (loopInput == 1)
        {
            cout << "Enter value into the array = ";
            cin >> arr[temp];
            temp++;

        }
        else if (loopInput == 2)
        {
            int k;
            cout << "Enter value of k = ";
            cin >> k;
            MinHeap* n = new MinHeap(k, arr);
            n->FirstKelements(arr, TSIZE, k);
        }
        else if (loopInput == 3)
        {
            break;
        }
        system("pause");
        system("cls");
    }

    return 0;
}

