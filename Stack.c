/*****************************************************************************
Stack with midvalue
*******************************************************************************/
#include <stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *prev;
    struct Node *next;
};
struct Node * head=NULL;
struct Node * tail=NULL;
int count=0;
//Insertatbeg
void push(int data){
    struct Node * Newnode=(struct Node *)malloc(sizeof(struct Node ));
    Newnode->data=data;
    Newnode->prev=NULL;
    Newnode->next=head;
    if(head!=NULL){
        head->prev=Newnode;
    }
    else{
        tail=Newnode;
    }
    head=Newnode;
    count++;
}
//delete at beg
void pop(){
    struct Node * temp=head;
    temp=head;
    head=temp->next;
    free(temp);
}
// to find head(top) value
void peek(){
    printf("%d\n",head->data);
}
// to check whether the stack is empty or not
void isempty(){
    if(head==NULL){
        printf("The stack is Empty\n");
    }
    else{
        printf("The stack is not Empty\n ");
    }
}
//to find mid value
void middisplay(){
    struct Node *temp=tail;
    struct Node *temp1=tail;
    l1:if(temp==NULL){
        printf("%d",temp1->data);
    }
    else{
        temp=temp->prev->prev;
        temp1=temp1->prev;
    goto l1;
}
    
}
// To display
void display(){
    struct Node *temp=head;
    while(temp!=NULL){
        printf("%d->",temp->data);
    temp=temp->next;
    }
    printf("NULL");
}
// reverse display
void revdisplay(){
    struct Node *temp=tail;
    while(temp!=NULL){
        printf("%d->",temp->data);
    temp=temp->prev;
    }
    printf("NULL");
}
int main()
{
    push(10);
    push(20);
    push(30);
    push(40);
    peek();
    isempty();
    display();
    printf("\n");
    middisplay();
    printf("\n");
    revdisplay();
    return 0;
}