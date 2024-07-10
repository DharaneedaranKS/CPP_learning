#include <iostream>

using namespace std;

class Node
{
    public:
        int data;
        Node *next;
        Node (int data)
        {
            this->data=data;
            next = NULL;
        }
};

class LinkedList
{
    private : 
        Node *header;
        Node *tail;
        int size;
    
    public : 

        LinkedList()
        {
            header = NULL;
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

            if (header == NULL)
            {
                header = n;
                tail = n;
            }

            else
            {
                tail -> next = n;
                tail = n;
            }

            size++;
        }

        void prepend(int data)
        {
            Node *n = new Node(data);

            if (tail == NULL)
            {
                header = n;
                tail = n;
            }

            else 
            {
                Node *temp = header;
                header = n;
                n -> next = temp;
            }

            size++;

        }

        void displayAll()
        {
            Node *temp = header;
            cout << "The elements of the linked list are : \n";
            while (temp != NULL)
            {
                cout << temp -> data << " ";
                temp = temp -> next;
            }
            cout << "\n";
        }

        void removeFirst()
        {
            if (header != NULL)
            {
                Node *temp = header;
                header = header -> next;
                delete temp;
                size --;
            }
            
        }

        void removeLast()
        {
            if (header->next == NULL)
            {
                removeFirst();
            }

            else
            {
                Node *prev = header;
                Node *curr = header -> next;

                while (curr->next != NULL){
                    prev = curr;
                    curr = curr->next;
                }

                tail = prev;
                prev->next = NULL;
                delete curr;
                size --;
            }
        }

};

void main()
{
    LinkedList list1;
    list1.append(5);
    list1.append(8);
    list1.append(10);
    list1.append(25);
    list1.displayAll();
    list1.removeLast();
    list1.removeFirst();
    list1.displayAll();
    cout << "Size is : "<<list1.getSize();
}