/*Design the navigation history system for a web browser using a Doubly Linked List.
The browser starts empty. You must process a stream of user commands:

VISIT <url> loads a new page, adding it immediately after the current page and permanently deleting any "forward" history that existed ahead of it
BACK moves the active view to the previously visited page (doing nothing if at the beginning)
FORWARD moves the active view to the next page in the history (doing nothing if at the end)

Given a list of these operations, output the final sequence of retained history from oldest to newest, along with the URL of the currently active page.*/

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
class Doubly{
public:
    Node*head;
    Node*active;
    Doubly()
    {
        head=NULL;
        active=NULL;
    }
    void VISIT(string s)
    {
        Node*newnode=new Node(s);
        Node*temp=active;
        if(head==NULL)
        {
            head=active=newnode;
            return;
        }

        active->next=newnode;
        newnode->prev=active;
        active=newnode;
    }
    void FORWARD()
    {
        if(active->next!=NULL)
            active=active->next;
        else
            return;
    }
    void BACK()
    {
        if(active->prev!=NULL)
            active=active->prev;
        else
            return;
    }

    void print()
    {
        cout<<"History: ";
        Node*temp=head;
        while(temp!=NULL)
        {
            cout<<temp->data<<", ";
            temp=temp->next;
        }
        cout<<endl;
        cout<<"Current Page: "<<active->data<<endl;
    }

};
int main()
{
    Doubly db;
    while(1)
    {
        string cmd;
        cin>>cmd;
        if(cmd=="VISIT")
        {
            string page;
            cin>>page;
            db.VISIT(page);
            db.print();
        }
        else if(cmd=="FORWARD")
        {
            db.FORWARD();
            db.print();
        }
        else if(cmd=="BACK")
        {
            db.BACK();
            db.print();
        }

        else
            return 0 ;
    }
}
