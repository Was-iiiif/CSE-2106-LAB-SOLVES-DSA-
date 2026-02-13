/*Implement a class MovingAverage that calculates the average of a stream of integers within a sliding window of size N.
The class should have a constructor to define the window size and a method next(val) that adds a new integer to the stream.
If the number of integers in the window exceeds N, the oldest integer (the one added first) must be removed to maintain the window size;
the method should then return the average of the elements currently in the window.*/
#include<bits/stdc++.h>
using namespace std;
template<class T>
class MovingAverage{
public:
    T *arr;
    int front,rear;
    int n;
    MovingAverage(int b)
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
    void pop()
    {
        if(isEmpty())
            return;
        front++;
    }
    void next(T item)
    {
        if(isFull())
            pop();
        if(front==-1)
            front=0;
        arr[++rear]=item;
    }

    T sum()
    {
        T count=0.0;
        for(int i= front; i<=rear; i++)
            count+=arr[i];
        return count;
    }

};

int main()
{
    int p;
    cin>>p;
    MovingAverage<double>m(p);
    while(1)
    {
        double x;
        cin>>x;
        m.next(x);
        cout<<"Average: "<<m.sum()/m.size()<<endl;
    }
}
