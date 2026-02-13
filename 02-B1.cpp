//Balanced Parenthesis Checker
#include<bits/stdc++.h>
using namespace std;
template<class T>
class Stack{
public:
    T *arr;
    int top;
    int n;
    Stack(int b)
    {
        n=b;
        arr=new T[n];
        top=-1;
    }

    void push(T item)
    {
        arr[++top]=item;
    }
    T pop()
    {
        return arr[top--];
    }
    bool isEmpty()
    {
        return (top==-1);
    }
};

bool isBalanced(char str[])
{
    Stack<char> st(1000);
    for(int i=0; str[i]!='\0'; i++)
    {
        if(str[i]=='(' || str[i]=='{' || str[i]=='[' )
            st.push(str[i]);
        else
        {
            char c;
            c=st.pop();
            if(c=='(' && str[i]!=')' || c=='{' && str[i]!='}' || c=='[' && str[i]!=']' )
                return false;
        }
    }
    return true;
}
int main()
{
    char str[1000];
    cin.getline(str,1000);
    if(isBalanced(str))
        cout<<"True";
    else
        cout<<"False";
}
