#include<iostream>
#include<queue>
using namespace std;
class node {
public:
    int val;
    node* left;
    node* right;
    node()
    {
        val = 0;
        left = NULL;
        right = NULL;
    }
};

class BINARY {
public:
    node* root;
    BINARY()
    {
        root = NULL;
    }

    node* smallest(node* temp)
    {
        if (temp->left == NULL) {
            return temp;
        }
        smallest(temp->left);
    }
    void insert(int temp)
    {
        if (root == NULL) {
            root = new node;
            root->val = temp;
            return;
        }
    }
    void insertleft(int temp5)
    {
        if (root->left == NULL) {
            root->left = new node;
            root->left->val = temp5;
            return;
        }
        queue<node*> q;
        q.push(root->left);
        while (!q.empty()) {
            node* temp = q.front();
            q.pop();

            if (temp->left != NULL)
                q.push(temp->left);
            else {
                temp->left = new node;
                temp->left->val = temp5;
                return;
            }

            if (temp->right != NULL)
                q.push(temp->right);
            else {
                temp->right = new node;
                temp->right->val = temp5;
                return;
            }
        }
    }
    void insertright(int arg)
    {
        if (root->right == NULL) {
            root->right = new node;
            root->right->val = arg;
            return;
        }
        queue<node*> q;
        q.push(root->right);
        while (!q.empty()) {
            node* temp = q.front();
            q.pop();

            if (temp->left != NULL)
                q.push(temp->left);
            else {
                temp->left = new node;
                temp->left->val = arg;
                return;
            }

            if (temp->right != NULL)
                q.push(temp->right);
            else {
                temp->right = new node;
                temp->right->val = arg;
                return;
            }
        }
    }
    int countNodes(node* temp)
    {
        if (temp == NULL)
            return (0);
        return (1 + countNodes(temp->left) + countNodes(temp->right));
    }

    bool isCompleteUtil(node* temp, int temp2,int n)
    {
        
        if (temp == NULL)
            return (true);

       
        if (temp2 >= n)
            return (false);

        
        return (isCompleteUtil(temp->left, 2 * temp2 + 1, n) &&isCompleteUtil(temp->right, 2 * temp2 + 2, n));
    }

     
    bool isHeapUtil(node* temp)
    {
        
        if (temp->left == NULL && temp->right == NULL)
            return (true);

        
        if (temp->right == NULL)
        {
            
            return (temp->val >= temp->left->val);
        }
        else
        {
            
            if (temp->val >= temp->left->val && temp->val >= temp->right->val)
                return ((isHeapUtil(temp->left)) &&
                    (isHeapUtil(temp->right)));
            else
                return (false);
        }
    }

    bool isHeap(node* temp)
    { 
        int node_count = countNodes(temp);
        int index = 0;

        if (isCompleteUtil(temp, index, node_count) && isHeapUtil(temp))
            return true;
        return false;
    }

    
   
    void inorder(node* root) {
        if (root == NULL) {
            return;
        }

        inorder(root->left);

        cout << root->val << " ";

        inorder(root->right);
    }
    void preorder(node* root)
    {
        if (root == NULL)
            return;

        cout << root->val << " ";

        preorder(root->left);

        preorder(root->right);
    }
    void postorder(node* root)
    {
        if (root == NULL)
            return;

        postorder(root->left);

        postorder(root->right);

        cout << root->val << " ";
    }
};
int main() {
    BINARY t1;
    bool loopCounter = true;
    int loopInput;
    int input;
    while (loopCounter)
    {
        cout << "Press 1 to insert" << endl;
        cout << "Press 2 to insert Left" << endl;
        cout << "Press 3 to insert Right" << endl;
        cout << "Press 4 to check if it is heap or not" << endl;
        cout << "Press 5 to Inorder Traversal" << endl;
        cout << "Press 6 to end" << endl;
        cin >> loopInput;
        if (loopInput == 1)
        {
            cout << "Enter Value = ";
            cin >> input;
            t1.insert(input);
            cout << endl;
        }
        else if (loopInput == 2)
        {
            cout << "Enter Value = ";
            cin >> input;
            t1.insertleft(input);
            cout << endl;
        }
        else if (loopInput == 3)
        {
            cout << "Enter Value = ";
            cin >> input;
            t1.insertright(input);
        }
        else if (loopInput == 4)
        {
            cout << endl;

            if (t1.isHeap(t1.root) == true)
            {
                cout << endl;
                cout<<"This Binary Tree is a Heap" << endl;
            }
            else
            {
                cout << endl;
                cout << "This Binary Tree is not a Heap" << endl;
            }
        }
        
        else if (loopInput == 5)
        {
            t1.inorder(t1.root);
            cout << endl;
        }
        
        else if (loopInput == 11)
        {
            loopCounter = false;
        }
        system("pause");
        system("cls");
    }
}

