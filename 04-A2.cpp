/*Write a menu-driven program to implement a Singly Linked List. The program must repeatedly display a menu and perform the selected operation until the user chooses to exit. When the user presses the corresponding number, the following operation should be performed:

1. Display – Print all elements of the linked list in order.
2. Insert at First – Insert a new value at the First of the list.
3. Conditional Delete Operation:
    Delete every odd element.
4. Exit.*/
#include<iostream>
using namespace std;
class Node{
public:
    int data;
    Node*next;
    Node(int d)
    {
        data=d;
        next=NULL;
    }
};
class LinkedList{
public:
    Node*head;
    LinkedList()
    {
        head=NULL;
    }
    void InsertFirst(int d)
    {
        Node*newnode=new Node(d);
        if(head==NULL)
            head=newnode;
        else
        {
            newnode->next=head;
            head=newnode;
        }

    }
    void Display()
    {
        cout<<"Linked List: ";
        Node*temp=head;
        if(temp==NULL)
        {
            cout<<"Empty\n";
            return ;
        }
        else
        {
            while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
        }
    }
    void ConditionalDelete()
    {
        Node*temp1=head;
        Node*temp2=NULL;
        while(temp1!=NULL)
        {
            if(temp1->data%2!=0)
            {
                if(temp1==head)
                {
                    temp1=temp1->next;
                    delete temp1;
                    temp1=head;
                }
                else
                {
                    temp2->next=temp1->next;
                    delete temp1;
                    temp1=temp2->next;
                }
            }
            else
            {
                temp2=temp1;
                temp1=temp1->next;
            }


        }
        cout<<"Deletion Done\n";
    }
};
int main()
{
    LinkedList ll;
    while(1)
    {
        cout<<"1. Display: Print all elements of the linked list in order.\n"
                <<"2. Insert at First: Insert a new value at the First of the list.\n"
                <<"3. Conditional Delete Operation:\n"
                <<"Delete every odd element.\n"
                <<"4. Exit.\n";
        int x;
        int d;
        cin>>x;
        switch(x)
        {
        case 1:
            ll.Display();
            break;
        case 2:
            cin>>d;
            ll.InsertFirst(d);
            break;
        case 3:
            ll.ConditionalDelete();
            break;
        case 4:
            return 0;
        default:
            return 0;


        }
    }
}
