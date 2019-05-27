#include<stdio.h>
#include<malloc.h>

typedef struct node {
    int data;
    struct node *next;
}NODE;

NODE *head = NULL, *prev, *tptr, *newNode;

void insert(int n)   {
    newNode = (NODE*)malloc(sizeof(NODE));
    newNode->data = n;
    newNode->next = NULL;

    if(head==NULL)
        head = newNode;
    else    {
        for(tptr=head; tptr && tptr->data<newNode->data; prev=tptr, tptr=tptr->next);
        if(tptr==head)  {               //insert at the front.
            newNode->next = head;
            head = newNode;
        }
        else  if(tptr==NULL)  {         //insert at the end.
            prev->next = newNode;
        }
        else    {                       //insert in the middle.
            prev->next = newNode;
            newNode->next = tptr;
        }
    }
}

void display()  {
    for(tptr=head; tptr; tptr=tptr->next)
        printf("%d ",tptr->data);
}


int main()  {
    insert(30);
    insert(40);
    insert(10);
    insert(20);
    insert(50);

    display();
}
