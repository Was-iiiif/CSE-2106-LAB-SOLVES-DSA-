#include<iostream>
using namespace std;
class Node{
public:
    string data;
    Node*prev;
    Node*next;
    Node(string s)
    {
        data=s;
        prev=NULL;
        next=NULL;
    }
};
class Gallery{
public:
    Node*head;
    Node*curr;
    Gallery()
    {
        head=NULL;
        curr=NULL;
    }
    void add(string s)
    {
        Node*newnode=new Node(s);
        if(head==NULL)
        {
            head=curr=newnode;
            return;
        }
        newnode->next=curr->next;
        newnode->prev=curr;
        if(curr->next)
        {
            curr->next->prev=newnode;
        }
        curr->next=newnode;
        curr=newnode;
    }

    void next()
    {
        if(curr->next==NULL)
        {
            return;
        }
        else
            curr=curr->next;

    }
    void prev()
    {
        if(curr->prev!=NULL)
        {
            curr=curr->prev;
        }
        else
            return;
    }
    void del()
    {
        Node*temp=curr;
        if(curr->prev==NULL && curr->next==NULL)
            head=curr=NULL;

        else if(curr->prev==NULL)
        {
            head=head->next;
            head->prev=NULL;
            curr=head;

        }
        else if(curr->next==NULL)
        {
            curr=curr->prev;
            curr->next=NULL;
        }
        else
        {
            curr->prev->next=curr->next;
            curr->next->prev=curr->prev;
            curr=curr->next;
        }

    }
    void disp()
    {
        cout<<"Remaining Gallery: ";
        Node*temp=head;
        while(temp!=NULL)
        {
            cout<<temp->data<<", ";
            temp=temp->next;
        }
        cout<<endl;
        cout<<"Currently Viewing: "<<curr->data<<endl;
    }
};
int main()
{
    Gallery g;
    int n;
    cin>>n;
    while(n--)
    {
        string s;
        cin>>s;
        g.add(s);
    }
    while(1)
    {
        string cmd;
        cin>>cmd;
        if(cmd=="NEXT")
        {
            g.next();
            g.disp();
        }

        else if(cmd=="PREV")
        {
            g.prev();
            g.disp();
        }

        else if(cmd=="DELETE")
        {
            g.del();
            g.disp();
        }
        else
            return 0;
    }
}
