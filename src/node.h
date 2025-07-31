#ifndef NODE_H
#define NODE_H

//basic structure
typedef struct Node {
    int data;
    struct Node *next;
} Node;

//functions
void add_node(Node **head,int value);
void delete_node(Node **head,int value);
void count(Node *head);
void print(Node *head);
void free_list(Node *head);

#endif
