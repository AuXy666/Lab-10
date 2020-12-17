#include<iostream>
using namespace std;
int iterate = 0;
class node
{
public:
    int val;
    node* left;
    node* right;
};

class binarySearch_Tree
{
public:
    node* root;
    int arr[100];
    int iCounter;
    binarySearch_Tree()
    {
        for (int i = 0; i < 100; i++)
        {
            arr[i] = -1;
        }
        root = NULL;
        iCounter = 0;
    }
    node* newNode(int item)
    {
        node* temp = new node;
        temp->val = item;
        temp->left = temp->right = NULL;
        return temp;
    }
    void rootInsert(int temp)
    {
        if (root == NULL)
        {
            root = newNode(temp);
        }
    }
    node* insert(node* temp1, int temp2)
    {

        if (temp1 == NULL)
        {
            temp1 = newNode(temp2);
            return temp1;
        }

        if (temp2 < temp1->val)
        {
            temp1->left = insert(temp1->left, temp2);
        }
        else if (temp2 > temp1->val)
        {
            temp1->right = insert(temp1->right, temp2);
        }

        return temp1;
    }
    
    void BSTToMaxHeap(node* temp, int* i)
    {
        if (temp == NULL)
            return;

       
        BSTToMaxHeap(temp->left, i);

        
        BSTToMaxHeap(temp->right, i);

        
        temp->val = arr[++ * i];
    }

    
    void convertToMaxHeapUtil(node* temp)
    {
      
        int i = -1;

        inorderTraversal(root, arr);

       
        BSTToMaxHeap(root, &i);
    }
    void inorderTraversal(node* temp, int arr[])
    {
        if (temp == NULL)
            return;

        inorderTraversal(temp->left, arr);

        arr[iterate] = temp->val;
        iterate++;
        inorderTraversal(temp->right, arr);
    }

    void inorder(node* root)
    {
        if (root == NULL)
        {
            return;
        }

        inorder(root->left);

        cout << root->val << " ";

        inorder(root->right);
    }
    void display()
    {
        cout << endl;
        cout <<"Max Heap = "<< endl;
        for (int i = 0; i < 10; i++)
        {
            if (arr[i] == -1)
            {
                break;
            }
            cout << arr[i]<<" ";
        }
        cout << endl;
    }
    


};


int main()
{
    binarySearch_Tree b1;
    bool loopCounter = true;
    int loopInput;
    int input;
    while (loopCounter)
    {
        cout << "Press 1 to enter Root of Binary Search Tree" << endl;
        cout << "Press 2 to insert into Binary Search tree" << endl;
        cout << "Press 3 to convert BST to Heap" << endl;
        cout << "Press 4 to print Max Heap" << endl;
        cout << "Press 5 to print Inorder Traversal of BST" << endl;
        cout << "Press 6 to end" << endl;
        
        cin >> loopInput;
        if (loopInput == 1)
        {
            cout << "Enter Value = ";
            cin >> input;
            b1.rootInsert(input);
            cout << endl;
        }
        else if (loopInput == 2)
        {
            cout << "Enter Value = ";
            cin >> input;
            b1.insert(b1.root, input);
            cout << endl;
        }
       
        else if (loopInput == 3)
        {
            b1.convertToMaxHeapUtil(b1.root);
            cout << endl;
            cout << "conversion completed" << endl;
           
            
        }
        else if (loopInput == 4)
        {
            b1.display();
            
        }
        else if (loopInput == 5)
        {
            cout << endl;
            cout << "Inorder = " << endl;
            b1.inorder(b1.root);
            cout << endl;
        }
        else if (loopInput == 6)
        {
            break;
        }
        system("pause");
        system("cls");

        
    }
}

