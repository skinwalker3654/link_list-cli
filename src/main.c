#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "node.h"

static void help_command(void)
{
    printf("\nCommands:\n\n");
    printf("   add   <value> : adds a value to the list\n");
    printf("   del   <value> : deletes a value from the list\n");
    printf("   count         : counts the list elements\n");
    printf("   print         : prints the list nodes\n");
    printf("   cls           : clears the terminal screen\n");
    printf("   help          : shows you this panel\n");
    printf("   exit          : exits the program\n\n");
}

int main(void) 
{
    Node *head = NULL;

    char input[50];
    char command[10];
    int value;
    
    while(1) {
            //geting input
            printf("skinwalker@> ");
            if(fgets(input,sizeof(input),stdin)==NULL) { 
                    printf("Error: Input failure\n");
                    continue;
            }

            input[strcspn(input,"\n")] = 0;
            if(strlen(input)==0) {continue;}

            //commands check
            int persed = sscanf(input,"%s %d",command,&value);
            if(strcmp(command,"add")==0) {
                    if(persed != 2) {
                            printf("Error: Invalid arguments passed\n");
                            continue;
                    }
                    add_node(&head,value);
            } else if(strcmp(command,"del")==0) {
                    if(persed != 2) {
                            printf("Error: Invalid arguments passed\n");
                            continue;
                    }
                    delete_node(&head,value);
            } else if(strcmp(command, "count")==0) {
                    if(persed != 1) {
                            printf("Error: Invalid arguments passed\n");
                            continue;
                    }
                    count(head);
            } else if(strcmp(command, "print")==0) {
                    if(persed != 1) {
                            printf("Error: Invalid arguments passed\n");
                            continue;
                    } 
                    print(head);
            } else if(strcmp(command, "cls")==0) {
                    if(persed != 1) {
                            printf("Error: Invalid arguments passed\n");
                            continue; 
                    }
                    system("clear"); 
            } else if(strcmp(command, "help")==0) {
                    if(persed != 1) {
                            printf("Error: Invalid arguments passed\n");
                            continue;
                    } 
                    help_command();
            } else if(strcmp(command,"exit")==0) {
                    if(persed != 1) {
                            printf("Error: Invalid arguments passed\n");
                            continue;
                    }
                    printf("Exiting the program...\n");
                    return 0;
                    free_list(head);
            } else {
                    printf("Error: Invalid command '%s'\n",command);
                    continue;
            }
    }
    free_list(head);
}
