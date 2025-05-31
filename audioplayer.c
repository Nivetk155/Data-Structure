
1).To create a playlist in audio player using player using linked list..
--------------------------------------------------------------------------------------------------------------------------
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
// Create the Structure
struct Node{
    char data[20];
    struct Node *prev;
    struct Node *next;
};
//Declaring the head and tail
struct Node * head=NULL;
struct Node * tail=NULL;
//To insert the data into stack(insertAtBeg)
void push(char *data){
    struct Node * Newnode=(struct Node *)malloc(sizeof(struct Node ));
    strcpy(Newnode->data, data);
    Newnode->prev=NULL;
    Newnode->next=head;
    if(head!=NULL){
        head->prev=Newnode;
    }
    else{
        tail=Newnode;
    }
    head=Newnode;
}
//To delete the data from the stack(deleteAtBeg)
void pop(){
    struct Node * temp=head;
    temp=head;
    head=temp->next;
    free(temp);
}
//To find next song
void peek(){
    printf("The next song is %s\n",head->data);
}
//To check the playlist is empty or not
void isempty(){
    if(head==NULL){
        printf("The playlist is Empty\n");
    }
    else{
        printf("The playlist is not Empty\n ");
    }
}
//To display all the songs in the playlists
void display(){
    struct Node *temp=head;
    while(temp!=NULL){
        printf("%s->",temp->data);
    temp=temp->next;
    }
    printf("NULL");
}
int main()
{
    push("Mother songs");
    push("Father songs");
    push("God songs");
    push("Love songs");
    peek();
    isempty();
    display();
    return 0;
}