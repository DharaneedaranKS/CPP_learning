#include <iostream>

using namespace std;

class Node
{
    public : 
        int data;
        Node *prev;
        Node *next;
        Node (int data){
            this->data = data;
            prev = NULL;
            next  = NULL;
        }

};

class doublyLinkedList
{
    private : 
        Node *header;
        Node *tail;
        int size;
    
    public : 

        doublyLinkedList() {
            header = NULL;
            tail = NULL;
            size = 0;
        }

        void append(int data){
            Node *n = new Node(data);
            if (header == NULL)
            {
                header = n;
                tail = n;
            }

            else 
            {
                Node *temp = tail;
                n-> prev = temp;
                temp -> next = n;
                tail = n;
            }

            size ++;
        }

        void addFront(int data)
        {
            Node *n = new Node(data);
            if (header == NULL)
            {
                header = n;
                tail = n;
            }
            else {
                Node *temp = header;
                temp->prev = n;
                n->next = temp;
                header = n;
            }

            size ++;
        }

        void removePos(int pos)
        {
            if(pos > size)
            {
                cout << "Invalid action \n";
            }

            else{
                Node *curr = header;

                for (int i = 1; i< pos; i++)
                {
                    curr = curr-> next;
                }

                Node *p = curr->prev;
                Node* n = curr->next;

                p->next = n;
                n->prev = p;
                delete curr;
                size --;
            }
        }

        void displayFront()
        {
            Node *temp = header;
            cout << "The following are the elements : ";
            while (temp != NULL)
            {
                cout<<temp->data<< " ";
                temp = temp -> next;
            }
            cout << "\n";
        }

        void displayBack()
        {
            Node *temp = tail;
            cout << "The following is the linked list reversed : ";
            while (temp != NULL)
            {
                cout << temp->data <<" ";
                temp = temp->prev;
            }

            cout << "\n";
        }

        int getSize()
        {
            return size;
        }


};


void main()
{
    doublyLinkedList list1;
    list1.append(10);
    list1.append(11);
    list1.append(12);
    list1.append(13);
    list1.addFront(20);
    cout<<list1.getSize()<<"\n";
    list1.displayFront();
    list1.displayBack();
    list1.removePos(2);
    list1.displayFront();
}