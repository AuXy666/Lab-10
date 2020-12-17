#include <iostream>
using namespace std;

const int Tsize = 100;

class binary_Min_heap
{
public:
    int minArr[Tsize];
    int heap_size1;
    binary_Min_heap()
    {
        heap_size1 = 0;
        for (int i = 0; i < Tsize; i++)
        {
            minArr[i] = -1;
        }
    }

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

    void insert(int key)
    {
        if (heap_size1 == Tsize)
        {
            cout << endl;
            cout << "value exceeded maximum size" << endl;
            return;
        }

        heap_size1++;
        int i = heap_size1 - 1;
        minArr[i] = key;

        while (i != 0 && minArr[parent(i)] > minArr[i])
        {
            swap(&minArr[i], &minArr[parent(i)]);
            i = parent(i);
        }
    }





    void decreaseKey(int i, int key)
    {
        minArr[i] = key;
        while (i != 0 && minArr[parent(i)] > minArr[i])
        {
            swap(&minArr[i], &minArr[parent(i)]);
            i = parent(i);
        }
    }



    void MinHeapify(int i)
    {
        int temp1, temp2;
        temp1 = left(i);
        temp2 = right(i);
        int smallest = i;
        if (temp1 < heap_size1 && minArr[temp1] < minArr[i])
            smallest = temp1;
        if (temp2 < heap_size1 && minArr[temp2] < minArr[smallest])
            smallest = temp2;
        if (smallest != i)
        {
            swap(&minArr[i], &minArr[smallest]);
            MinHeapify(smallest);
        }
    }


    void swap(int* x, int* y)
    {
        int temp = *x;
        *x = *y;
        *y = temp;
    }

    void display()
    {
        for (int i = 0; i < Tsize; i++)
        {
            if (minArr[i] == -1)
            {
                break;
            }
            cout << minArr[i] << " ";
        }
        cout << endl;
    }

};

class binary_Max_heap
{
public:
    int* maxArr;
    int heap_size2;
    binary_Max_heap()
    {
        heap_size2 = 0;
        maxArr = NULL;
    }

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

    void Maxheapify(int arr[],int i, int tempSize)
    {
        int largest = i;
        int l = left(i);
        int r = right(i);


        if (l < tempSize && arr[l] > arr[largest])
            largest = l;


        if (r < tempSize && arr[r] > arr[largest])
            largest = r;


        if (largest != i) {
            swap(&arr[i], &arr[largest]);


            Maxheapify(arr,tempSize, largest);                                                                        
        }
    }

    void convertMaxHeap(int arr[],int n)
    {

        for (int i = (n - 2) / 2; i >= 0; --i)
            Maxheapify(arr,i, n);
    }

    void display(int arr[])
    {
        for (int i = 0; i < Tsize; i++)
        {
            if (arr[i] == -1)
            {
                break;
            }
            cout << arr[i] << " ";
        }
        cout << endl;
    }

};




int main()
{

    int loopInput;
    binary_Min_heap h1;
    binary_Max_heap h22;
    while (1)
    {
        cout << "Press 1 to insert into the heap " << endl;
        cout << "Press 2 to convert Min Heap into Max heap " << endl;
        cout << "Press 3 to print Max Heap " << endl;
        cout << "Press 4 to end " << endl;
        cin >> loopInput;
        if (loopInput == 1)
        {
            int input;
            cout << "Enter key value = ";
            cin >> input;
            h1.insert(input);
            cout << endl;
            cout << "Value Inserted" << endl;
        }
        if (loopInput == 2)
        {
            h22.convertMaxHeap(h1.minArr, h1.heap_size1);
        }
        else if (loopInput == 3)
        {
            cout << endl;
            cout << "Max Heap = " << endl;
            h22.display(h1.minArr);
        }
        else if (loopInput == 4)
        {
            cout << endl;
            cout << "Min Heap = " << endl;
            h1.display();
        }
        else if (loopInput == 6)
        {
            break;
        }
        system("pause");
        system("cls");
    }
    return 0;
}


