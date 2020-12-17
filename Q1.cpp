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
    { return (i - 1) / 2;
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
        if (heap_size == Tsize)
        {
            cout << endl;
            cout << "value exceeded maximum size" << endl;
            return;
        }

        heap_size++;
        int i = heap_size - 1;
        harr[i] = key;

        while (i != 0 && harr[parent(i)] > harr[i])
        {
            swap(&harr[i], &harr[parent(i)]);
            i = parent(i);
        }
    }

    void Delete(int i)
    {
        decreaseKey(i, -1);
        extractMin();
    }

    int extractMin()
    {
        if (heap_size <= 0)
            return 0;
        if (heap_size == 1)
        {
            heap_size--;
            return harr[0];
        }

        int root = harr[0];
        harr[0] = harr[heap_size - 1];
        heap_size--;
        MinHeapify(0);

        return root;
    }
  
    void decreaseKey(int i, int key)
    {
        harr[i] = key;
        while (i != 0 && harr[parent(i)] > harr[i])
        {
            swap(&harr[i], &harr[parent(i)]);
            i = parent(i);
        }
    }
  
    int getMin()
    {
        return harr[0];
    }

   void MinHeapify(int i)
    {
        int temp1,temp2;
        temp1= left(i);
        temp2 = right(i);
        int smallest = i;
        if (temp1 < heap_size && harr[temp1] < harr[i])
            smallest = temp1;
        if (temp2 < heap_size && harr[temp2] < harr[smallest])
            smallest = temp2;
        if (smallest != i)
        {
            swap(&harr[i], &harr[smallest]);
            MinHeapify(smallest);
        }
    }


    void swap(int* x, int* y)
    {
        int temp = *x;
        *x = *y;
        *y = temp;
    }
    bool search(int key)
    {
        bool checker = false;
        for (int i = 0; i < Tsize; i++)
        {
            if (key == harr[i])
            {
                checker = true;
            }
        }
        return checker;
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
        cout << "Press 2 to delete from the heap " << endl;
        cout << "Press 3 to show root element of the Heap " << endl;
        cout << "Press 4 to remove minimum element from the Heap " << endl;
        cout << "Press 5 to decrease a key " << endl;
        cout << "Press 6 to end " << endl;
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
            int input;
            cout << "Enter key index = ";
            cin >> input;
            h.Delete(input);
            cout << endl;
            cout << "Value Deleted" << endl;
            
        }
        else if (loopInput == 3)
        {
            cout << endl;
            cout << "Min value = "<< h.getMin() << " " << endl;
        }
        else if (loopInput == 4)
        {
            int value;
            value = h.extractMin();
            cout << endl;
            cout << "Minimum value = " << value << " removed" << endl;
            
        }
        else if (loopInput == 5)
        {
            int input, input2;
            cout << "Enter index value = ";
            cin >> input;
            cout << "Enter the value by which you want to decrease = ";
            cin >> input2;
            h.decreaseKey(input, input2);
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

