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
void count_nodes(Node *head);
void print_nodes(Node *head);
void free_list(Node *head);

#endif
