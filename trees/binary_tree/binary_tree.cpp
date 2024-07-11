#include <iostream>

using namespace std;

class Node{
    public :
        int data;
        Node *left;
        Node *right;

        Node (int data)
        {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
};

class binaryTree{
    private :
        Node *root;
    
    public : 
        binaryTree (){
            root = NULL;
        }

        int isEmpty ()
        {
            if (root==NULL)
                return 1;
            else 
                return 0;
        }

        void insertNode (int data)
        {
            if (root == NULL)
            {
                root = new Node(data);
            }

            else{
                Node *pres;
                Node *check;
                check = root;

                do
                {
                    pres = check;
                    if (pres->data < data)
                        check = pres->left;
                    
                    else
                        check = pres->right;
                }while(check != NULL);

                check = new Node(data);
            }
        }

        void print2DUtil(Node *n, int space)
        {
        if (n == NULL)
            return;

        space += 10;

        print2DUtil(n->right, space);
        for (int i = 10; i < space; i++)
            cout << " ";
        
        cout << n->data << "\n";

        print2DUtil(n->left, space);
        }

        void printTree()
        {
            print2DUtil(root, 0);
        }

        
};

void main()
{
    binaryTree tree1;
    tree1.insertNode(3.5);
    for(float i = 0.3; i< 6; i=i+0.3)
        tree1.insertNode(i);

    tree1.printTree();

}