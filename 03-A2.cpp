/*You are given a single-line string that contains normal text mixed with arithmetic expressions. Each arithmetic expression is written in infix notation and is enclosed inside curly braces { }. Your task is to: Extract all infix expressions enclosed inside { }. Convert each extracted infix expression into postfix notation using a stack-based algorithm. Use separate functions for each operation. Display: The total number of expressions found The extracted infix expressions Their corresponding postfix expressions Input: The value of {A+B*C} is stored and {X-Y/Z} is printed. Output: Total Expressions Found: 2 Extracted Infix Expressions: 1. A+B*C 2. X-Y/Z Postfix Expressions: 1. ABC*+ 2. XYZ/- */
#include<iostream>
using namespace std;

template <class T>
class Stack{
public:
    T arr[10000];
    int n;
    Stack() { n = -1; }

    bool isEmpty() { return n == -1; }
    bool isFull() { return n == 9999; }

    void push(T item)
    {
        if (!isFull())
            arr[++n] = item;
    }

    void pop()
    {
        if (!isEmpty())
            n--;
    }

    T top()
    {
        return arr[n];
    }

    int size()
    {
        return n + 1;
    }
};

int prec(char c)
{
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return -1;
}

string InfixToPostfix(string s)
{
    Stack<char> st;
    string res;

    for (char c : s)
    {
        if (isalnum(c))
        {
            res += c;
        }
        else
        {
            while (!st.isEmpty() && prec(st.top()) >= prec(c))
            {
                res += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    while (!st.isEmpty())
    {
        res += st.top();
        st.pop();
    }

    return res;
}

Stack<string> extractExpressions(string& text)
{
    Stack<string> exp;
    string temp;
    bool inside = false;

    for (char ch : text)
    {
        if (ch == '{')
        {
            temp.clear();
            inside = true;
        }
        else if (ch == '}' && inside)
        {
            exp.push(temp);
            inside = false;
        }
        else if (inside)
        {
            temp += ch;
        }
    }
    return exp;
}

int main()
{
    string input;
    getline(cin, input);
    Stack<string> infixStack = extractExpressions(input);
    Stack<string> orderedStack;
    while (!infixStack.isEmpty())
    {
        orderedStack.push(infixStack.top());
        infixStack.pop();
    }
    cout << "Total Expressions Found: " << orderedStack.size() << endl;
    cout << "Extracted Infix Expressions:" << endl;
    Stack<string> tempStack = orderedStack;
    int i = 1;
    while (!tempStack.isEmpty())
    {
        cout << i++ << ". " << tempStack.top() << endl;
        tempStack.pop();
    }
    cout << "\nPostfix Expressions:" << endl;
    i = 1;
    while (!orderedStack.isEmpty())
    {
        cout << i++ << ". "
             << InfixToPostfix(orderedStack.top()) << endl;
        orderedStack.pop();
    }

    return 0;
}
