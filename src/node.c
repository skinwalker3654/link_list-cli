#include <stdlib.h>
#include <stdio.h>
#include "node.h"

void add_node(Node **head,int value) 
{
    //Allocating memory for the new node
    Node *new_node = malloc(sizeof(Node));
    if(!new_node) {
            fprintf(stderr,"Allocation failed\n"); 
            return;
    }

    //passing values to the node
    new_node->data = value;
    new_node->next = NULL;

    //puting the first node
    if(*head == NULL) {
            *head = new_node;
            printf("Value %d added succesfuly\n",value);
            return;
    }

    //checking for the correct position to put the next node
    Node *temp = *head;
    while(temp-> next != NULL) 
            temp = temp->next;
    
    temp->next = new_node;
    printf("Value %d added succesfuly\n",value);
}




void delete_node(Node **head, int value) 
{
    //checking if list is empty
    if(*head == NULL) {
            printf("List is empty\n");
            return;
    }

    //checking if value is the first node
    Node *temp = *head, *prev = NULL;
    if(temp != NULL && temp->data == value) {
            *head = temp->next;
            free(temp);
            printf("Value %d deleted succesfuly\n",value);
            return;
    }

    //finding wich node is equal to the value
    while(temp != NULL && temp->data != value) {
            prev = temp;
            temp = temp->next;
    }
    
    //if didnt find the value
    if(temp == NULL) {
            printf("Value %d not found\n",value);
            return;
    }

    //deleting the value
    prev->next = temp->next;
    free(temp);
    
    printf("Value %d deleted succesfuly\n",value);
}




void print_nodes(Node *head) 
{
    //checking if list is empty
    if(head == NULL) {
            printf("List is empty\n");
            return;
    }

    //printing the nodes till it hits a NULL
    while(head != NULL) {
            printf("%d -> ",head->data);
            head = head->next;
    }

    printf("NULL\n");
}




void count_nodes(Node *head) 
{
    //checking if list is empty
    if(head == NULL) {
            printf("List is empty\n");
            return;
    }

    //counting the elements
    int count = 0;
    while(head != NULL) {
            count++;
            head = head->next;
    }

    printf("Elements count: %d\n",count);
}




void free_list(Node *head) 
{
    if(head == NULL) return;
    
    //starts freeying the memory
    Node *temp;
    while(head != NULL) {
            temp = head;
            head = head->next;
            free(temp);
    }
}
