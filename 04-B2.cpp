/*Write a program to implement a Singly Linked List. The program must repeatedly display a menu and perform the selected operation until the user chooses to exit.
When the user presses the corresponding number, the following operation should be performed:
1. Display – Print all elements of the linked list in order.
2. Insert at Last – Insert a new value at the end of the list.
3. Conditional Insert Operation –
4. Insert value 200 after every odd element.
5. Exit*/
#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node*next;
    Node(int a)
    {
        data=a;
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

    void insertLast(int val)
    {
        Node*newNode=new Node(val);
        if(head==NULL)
        {
            head=newNode;
            return;
        }
        Node*temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newNode;
    }
    void conditionalInsert()
    {
        Node*temp=head;
        while(temp!=NULL)
        {
            if(temp->data%2==0)
            {
                Node*newNode=new Node(200);
                newNode->next=temp->next;
                temp->next=newNode;
                temp=newNode->next;
            }
            else
                temp=temp->next;
        }
        cout<<"conditional Modification Done"<<endl;
    }
    void printList()
    {
        if(head==NULL)
        {
            cout<<"List is Empty";
            return;
        }
        Node*temp=head;
        cout<<"LinkedList: ";
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    }

};
int main() {
    LinkedList ll;
    int choice, value;

    do {
        cout << "\nMenu:\n";
        cout << "1. Display\n";
        cout << "2. Insert at Last\n";
        cout << "3. Conditional Insert Operation\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            ll.printList();
            break;

        case 2:
            cout << "Enter value: ";
            cin >> value;
            ll.insertLast(value);
            break;

        case 3:
            ll.conditionalInsert();
            break;

        case 4:
            cout << "Program terminated.\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 4);

    return 0;
}
