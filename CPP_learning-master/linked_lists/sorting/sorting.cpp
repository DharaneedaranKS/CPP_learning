#include <iostream>

using namespace std;

class Node
{
    public:
        int data;
        Node *n;
        Node (int data)
        {
            this->data=data;
            n = NULL;
        }
};

class linkedList {
    private :
         Node *head;
         Node *tail;
         int size;

    public : 
        linkedList()
        {
            head = NULL;
            tail = NULL;
            size = 0;
        }

        int getSize()
        {
            return size;
        }

        void append (int data)
        {
            Node *n = new Node(data);

            if (head == NULL)
            {
                head = n;
                tail = n;
            }

            else
            {
                tail -> n = n;
                tail = n;
            }
            size++;
        }

        void bubbleSort()
        {
            for(int i = 0; i<size; i++)
            {
                Node *prev = head;
                Node *curr = prev->n;
                while (curr != NULL)
                {
                    if(prev->data > curr->data)
                        swap(prev, curr);
                    
                    prev = curr;
                    curr = curr->n;
                }
            }
    
        }

        void insertionSort()
        {
            Node *curr = head;

            while (curr->n != NULL)
            {
                Node *test = curr->n;
                while (test != NULL)
                {
                    if(test->data < curr->data)
                        swap(test, curr);
                    
                    test = test->n;
                }
                curr = curr->n;
            }
        }

        void swap(Node *a, Node *b)
        {
            a->data = a->data + b->data;
            b->data = a->data - b->data;
            a->data = a->data - b->data;
        }

        void displayAll()
        {
            Node *temp = head;
            cout << "The elements of the linked list are : \n";
            while (temp != NULL)
            {
                cout << temp -> data << " ";
                temp = temp -> n;
            }
            cout << "\n";
        }

};



void main()
{
    linkedList list1;
    for (int i=5; i>=-10; i--)
    {
        list1.append(i);
    }
    list1.displayAll();
    list1.bubbleSort();
    list1.displayAll();

    linkedList list2;
    for (int j=10;j >= -5; j--)
        list2.append(j);
    
    list2.displayAll();
    list2.insertionSort();
    list2.displayAll();
}