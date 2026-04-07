/*Design the core logic for a single-line text editor using a Doubly Linked List. The editor starts completely empty and tracks the active typing position. You must process a sequence of commands:

TYPE <char>: inserts a character immediately to the left of the cursor.
LEFT: moves the cursor one character backward (does nothing if already at the very beginning).
RIGHT: moves the cursor one character forward (does nothing if already at the very end).
BACKSPACE: deletes the character immediately to the left of the cursor.

Given a list of these operations, output the final resulting string of text and the character that the cursor is currently sitting in front of (or "END" if the cursor is at the far right of the text).*/

#include<iostream>
using namespace std;
class Node{
public:
    char data;
    Node*prev;
    Node*next;
    Node(char s)
    {
        data=s;
        prev=next=NULL;
    }
};
class Editor{
public:
    Node*head;
    Node*curr;
    Editor()
    {
        head=curr=NULL;
    }
    void type(char c)
    {
        Node*newnode=new Node(c);
        if(head==NULL)
            head=curr=newnode;
        else if(curr->next==NULL)
        {
            curr->next=newnode;
            newnode->prev=curr;
            curr=newnode;
        }
        else
        {
            newnode->next=curr->next;
            newnode->prev=curr;
            if(curr->next)
                curr->next->prev=newnode;
            curr->prev=newnode;
            curr=newnode;
        }
    }
    void left()
    {
        if(curr->prev==NULL)
            return;
        else
            curr=curr->prev;
    }
    void right()
    {
        if(curr->next==NULL)
            return;
        else
            curr=curr->next;
    }
    void backspace()
    {
        if(curr->prev==NULL && curr->next==NULL)
            curr=head=NULL;
        else if(curr->prev==NULL)
        {
            head=head->next;
            curr=head;
        }
        else if(curr->next==NULL)
        {
            curr=curr->prev;
            curr->next=NULL;
        }
        else
        {
            curr->next->prev=curr->prev;
            curr->prev->next=curr->next;
            curr=curr->prev;
        }
    }
    void disp()
    {
        cout<<"Final Text: ";
        Node*temp=head;
        while(temp!=NULL)
        {
            cout<<temp->data;
            temp=temp->next;
        }
        cout<<endl;
        cout<<"Cursor is currently at: "<<curr->data<<endl;
    }
};
int main()
{
    Editor e;
    while(1)
    {
        string cmd;
        cin>>cmd;
        if(cmd=="TYPE")
        {
            char c;
            cin>>c;
            e.type(c);
            e.disp();
        }
        else if(cmd=="LEFT")
        {
            e.left();
            e.disp();
        }
        else if(cmd=="RIGHT")
        {
            e.right();
            e.disp();
        }
        else if(cmd=="BACKSPACE")
        {
            e.backspace();
            e.disp();
        }
        else
            return 0;

    }
}
