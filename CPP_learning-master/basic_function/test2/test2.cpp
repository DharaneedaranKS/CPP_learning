#include <iostream>

using namespace std;

void swap(int* x, int* y)
{
    int swap;
    swap = *x;
    *x = *y;
    *y = swap;
}

void main()
{

    int x, y;
    cout<<"Enter two numbers : ";
    cin>>x>>y;
    swap(&x, &y);
    cout<<"\n"<<" X is now : "<<x<<" and Y is now "<<y;

}

