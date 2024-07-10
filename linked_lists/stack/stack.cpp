#include <iostream>

using namespace std;

class Node {
    public :
        int data;
        Node *next;
        Node (int data){
            this->data = data;
            next = NULL;
        }
};

class Stack{
    private :
        Node *head;
        Node *tail;
        int size;
    
    public :
        Stack()
        {
            head = NULL;
            tail = NULL;
            size = 0;
        }

        void push (int data)
        {
            Node *n = new Node(data);

            if (head == NULL)
            {  
                head = n;
                tail = n;
            }

            else 
            {
                Node *temp = head;
                head = n;
                n->next = temp;
            }

            size ++;
        }

        void pop ()
        {
            if (head == NULL)
            {
                cout << "N/A";
            }
            else {
                Node *temp = head;
                head =  temp->next;
                delete temp;
                size -- ;
            }
        }

        int isEmpty()
        {
            return (size == 0)? 1:0;
        }

        int peek(int pos)
        {
            Node *prev = head;
            Node *curr;

            for(int i = 1; i < pos; i++)
            {
                prev = prev -> next;
                curr = prev -> next;
            }

            return prev->data;
        }

        int count()
        {
            return size;
        }

        void change(int pos, int data)
        {
            Node *prev = head;
            Node *curr;

            for(int i = 1; i < pos; i++)
            {
                prev = prev -> next;
                curr = prev -> next;
            }

            prev->data = data;           
        }

        void display()
        {
            Node *prev = head;
            cout << "The following is the elements : \n";
            for(int i = 1; i <= size; i++)
            {
                cout << prev->data << " ";
                prev = prev -> next;
            } 
            cout <<"\n";
        }
};


void main ()
{
    Stack a;
    a.push(1);
    a.push(2);
    a.push(3);
    a.push(4);
    a.push(5);
    a.push(6);
    a.display();
    a.pop();
    a.display();
    cout << "At position 3 : " << a.peek(3) << "\n";
    a.change(3, 10);
    cout << "Changed position 3 : " << a.peek(3) << "\n";
}