/*Write a menu-driven program to implement a Singly Linked List. The program must repeatedly display a menu and perform the selected operation until the user chooses to exit. When the user presses the corresponding number, the following operation should be performed:

1. Display – Print all elements of the linked list in order.
2. Insert at First – Insert a new value at the First of the list.
3. Conditional Insert Operation:
    Insert 400 after every even numbered position value in the list.
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
    void ConditionalInsert()
    {
        Node*temp=head;
        int count=1;
        while(temp!=NULL)
        {
            if(count%2==0)
            {
                Node*newnode=new Node(400);
                newnode->next=temp->next;
                temp->next=newnode;
                temp=newnode->next;
            }
            else
            {
                temp=temp->next;
            }
                count++;
        }
        cout<<"Mod done\n";
    }
};
int main()
{
    LinkedList ll;
    while(1)
    {
        cout<<"1. Display: Print all elements of the linked list in order.\n"
                <<"2. Insert at First: Insert a new value at the First of the list.\n"
                <<"3. Conditional Insert Operation:\n"
                <<"Insert 400 after every even numbered position value in the list.\n"
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
            ll.ConditionalInsert();
            break;
        case 4:
            return 0;
        default:
            return 0;


        }
    }
}
