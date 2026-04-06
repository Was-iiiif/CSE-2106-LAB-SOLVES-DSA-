/*Design the core playback queue for a music application using a Doubly Linked List.
The system starts empty and must process a stream of user commands:

ADD <song> inserts a new song immediately after the currently playing track and automatically switches playback to this new song (if the playlist is empty, it becomes the first playing song).
NEXT moves playback forward to the following song.
PREV moves playback backward to the previous song.
REMOVE deletes the currently playing song, automatically shifting playback to the next available track (or the previous track if you just removed the very last song in the list).

Given a list of these operations, output the final sequence of the playlist and the name of the track that is currently playing.*/

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
    Node*playback;
    Doubly()
    {
        head=NULL;
        playback=NULL;
    }
    void ADD(string s)
    {
        Node*newnode=new Node(s);
        if(head==NULL)
        {
            head=playback=newnode;
            return;
        }
        newnode->next=playback->next;
        newnode->prev=playback;
        if(playback->next)
            playback->next->prev=newnode;
        playback->next=newnode;
        playback=newnode;

    }
    void NEXT()
    {
        if(playback->next!=NULL)
            playback=playback->next;
        else
            cout<<"Last Song\n";
    }
    void PREV()
    {
        if(playback->prev!=NULL)
            playback=playback->prev;
        else
            cout<<"First Song\n";
    }
    void REMOVE()
    {
        Node*temp=playback;
        if(playback->next==NULL)
        {
            playback=playback->prev;
            delete temp;
        }
        else
        {
            playback->prev->next=playback->next;
            playback->next->prev=playback->prev;
            playback=playback->next;
            delete temp;
        }

    }
    void print()
    {
        cout<<"Playlist: ";
        Node*temp=head;
        while(temp!=NULL)
        {
            cout<<temp->data<<", ";
            temp=temp->next;
        }
        cout<<endl;
        cout<<"Currently Playing: "<<playback->data<<endl;
    }

};
int main()
{
    Doubly db;
    while(1)
    {
        string cmd;
        cin>>cmd;
        if(cmd=="ADD")
        {
            string song;
            cin>>song;
            db.ADD(song);
            db.print();
        }
        else if(cmd=="NEXT")
        {
            db.NEXT();
            db.print();
        }
        else if(cmd=="PREV")
        {
            db.PREV();
            db.print();
        }
        else if(cmd=="REMOVE")
        {
            db.REMOVE();
            db.print();
        }
        else
            return 0 ;
    }
}
