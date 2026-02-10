/*You are building a text processing engine for a new word game. One of the core mechanics involves identifying “mirror words” (palindromes).
A palindrome is a word, phrase, number, or other sequence of characters that reads the same forward and backward ignoring spaces, punctuation, and capitalization.
Write a function is_palindrome(text) that determines if a given string is a palindrome.
To solve this problem, you must use a STACK.
Input:
A string text containing alphanumeric characters and potentially special characters.
Output:
Return True if the text is a palindrome.
Return False if it is not.*/
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
};
bool isPalindrome(char str[])
{
    Stack<char> st(1000);
    char temp[1000];
    int k=0;
    for(int i=0; str[i]!='\0'; i++)
    {
        if(isalnum(str[i]))
            temp[k++]=tolower(str[i]);
    }
    temp[k]='\0';
    for(int i=0; temp[i]!='\0'; i++)
        st.push(temp[i]);
    for(int i=0; temp[i]!='\0'; i++)
    {
        if(temp[i]!=st.pop())
            return false;
    }
    return true;
}
int main()
{
    char str[1000];
    cin.getline(str,1000);
    if(isPalindrome(str))
        cout<<"True";
    else
        cout<<"False";
}
