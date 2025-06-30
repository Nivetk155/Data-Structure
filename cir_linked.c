// To get a string as input frome the user via command line argument and check whether it is palindrome or not...
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
struct Node{
    char data;
    struct Node *next;
    struct Node *prev;
};
struct Node *head=NULL;
struct Node *temp=NULL;
struct Node *t=NULL;
int count=0;
void push(char data){
  struct Node *new=(struct Node *)malloc(sizeof(struct Node)); 
 new->data=data;
 if(head==NULL){
     new->next=new;
     new->prev=new;
     head=new;
     t=head;
     return;
 }
 new->next=head;
 new->prev=t;
 head->prev=new;
 t->next=new;
 head=new;
 return ;
}
void rev(){
    temp=head;
   do{
        if(temp->data==t->data){
            temp=temp->next;
            t=t->prev;
            count++;
        }
        else{
            return ;
        }
        }while(temp->next!=head);
    
}
void display(){
    temp=head;
    do{
        printf("%c ",temp->data);
        temp=temp->next;
    }while(temp!=head);
    
}



int main(int argc,char *argv[])
{
    if (argc < 2) {
        printf("Usage: %s <name>\n", argv[0]);
}

int n = strlen(argv[1]);
 char str[n+1];
    strcpy(str, argv[1]);
   for(int i=0;str[i]!='\0';i++){
       push(str[i]);
   }
  rev();
  if(count+1==n){
      printf("Palindrome");
  }
  else{
      printf("Not a palindrome");
  }
  
    return 0;
}
