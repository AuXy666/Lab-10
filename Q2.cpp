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

    void heapify( int i,int tempSize)
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

   
    void heapSort()
    {
        
        for (int i = heap_size / 2 - 1; i >= 0; i--)
            heapify(heap_size, i);

        
        for (int j = heap_size - 1; j > 0; j--) {

            swap(&harr[0], &harr[j]);
  
            heapify(0,j);
        }
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
        cout << "Press 2 to perform sorting " << endl;
        cout << "Press 3 to display " << endl;
        cout << "Press 4 to end " << endl;
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
            h.heapSort();
            
        }
        else if (loopInput == 3)
        {
            h.display();
        }
        else if (loopInput == 4)
        {
            break;
        }
        system("pause");
        system("cls");
    }
    return 0;
}

