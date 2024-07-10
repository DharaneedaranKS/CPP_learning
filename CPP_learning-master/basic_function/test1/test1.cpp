#include <iostream>

using namespace std;

// Main() function: where the execution of program begins
int sum(int x, int y)
{
    return x+y;
}

int twice(int x)
{
    return x<<1;
}
int main()
{
    // prints hello world
    int in1, in2;
    cout<<"Enter Two Numbers \n";
    cin>>in1>>in2;

    int out = sum(in1, in2);

    cout<<"The sum is : "<< out<<'\n';

    cout<<"The double : "<<twice(in1);

    return 0;
}