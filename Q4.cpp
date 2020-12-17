#include<iostream> 
using namespace std;

const int Tsize = 100;

class binary_heap
{
public:
    int harr[Tsize];
    int heap_size;
    binary_heap()
    {
        heap_size = 0;
        for (int i = 0; i < Tsize; i++)
        {
            harr[i] = -1;
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

    void swap(int* x, int* y)
    {
        int temp = *x;
        *x = *y;
        *y = temp;
    }

    void insert(int key)
    {
        if (heap_size == Tsize)
        {
            cout << endl;
            cout << "value exceeded maximum size" << endl;
            return;
        }

        heap_size++;
        int i = heap_size - 1;
        harr[i] = key;

        while (i != 0 && harr[parent(i)] < harr[i])
        {
            swap(&harr[i], &harr[parent(i)]);
            i = parent(i);
        }
    }

    void heapify(int i, int tempSize)
    {
        int largest = i;
        int l = left(i);
        int r = right(i);


        if (l < tempSize && harr[l] > harr[largest])
            largest = l;


        if (r < tempSize && harr[r] > harr[largest])
            largest = r;


        if (largest != i) {
            swap(&harr[i], &harr[largest]);


            heapify(tempSize, largest);
        }
    }



    bool isHeap(int i)
    {
        if (i >= (heap_size - 2) / 2)
            return true;

        
        if (harr[i] >= harr[left(i)] &&harr[i] >= harr[right(i)]&& isHeap(left(i))&& isHeap(right(i)))
            return true;

        return false;
    }
    void display()
    {
        for (int i = 0; i < Tsize; i++)
        {
            if (harr[i] == -1)
            {
                break;
            }
            cout << harr[i] << " ";
        }
        cout << endl;
    }

};

int main()
{

    int loopInput;
    binary_heap h;
    while (1)
    {
        cout << "Press 1 to insert into the heap " << endl;
        cout << "Press 2 to check if it is Max Heap " << endl;
        cout << "Press 3 to end " << endl;
        cin >> loopInput;
        if (loopInput == 1)
        {
            int input;
            cout << "Enter key value = ";
            cin >> input;
            h.insert(input);
            cout << endl;
            cout << "Value Inserted" << endl;
        }
        else if (loopInput == 2)
        {
            if (h.isHeap(0) == true)
            {
                cout << endl;
                cout << "It is heap" << endl;

            }
            else
            {
                cout << endl;
                cout << "It is not heap" << endl;
            }
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

