/*given a deck of n cards 1 to n from top to bottom. You have to discard the top element and then the new top element , place it to the bottom and continue the process until 1 element is remaining. print the last one element ...
example: n=6, 1,2,3,4,5,6 output: 4*/
#include<bits/stdc++.h>
using namespace std;
template<class T>
class Queue{
public:
    T *arr;
    int front,rear;
    int n;
    Queue(int b)
    {
        n=b;
        arr=new T[1000];
        front=-1;
        rear=-1;
    }
    int size()
    {
        return (rear-front+1);
    }
    bool isFull()
    {
        return (rear-front+1==n);
    }
    bool isEmpty()
    {
        return (rear==-1 || front>rear);
    }
    T pop()
    {
        if(isEmpty())
            return 1;
        return arr[front++];
    }
    void push(T item)
    {
        if(isFull())
            pop();
        if(front==-1)
            front=0;
        arr[++rear]=item;
    }
    T top()
    {
        return (arr[front]);
    }

};

int main()
{
    int p;
    cin>>p;
    Queue<int>q(p);
    while(p--)
    {
        int x;
        cin>>x;
        q.push(x);
    }
    while(q.size()>1)
    {
        q.pop();
        q.push(q.pop());
    }
    cout<<"Ans is: "<<q.top()<<endl;
}
