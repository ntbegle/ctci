
#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"
#include "ch2.h"

int main(int argc, char **argv)
{
    NODE* head = NULL;
    NODE* tail_node = NULL;
    NODE* del_node = NULL;
    int del_node_idx = atoi(argv[1]);

    for(int i=2; i < argc; ++i)
    {
        printf("adding val %d to list\n", atoi(argv[i]));
        if(i == 2)
        {
            head = (NODE*) malloc(sizeof(NODE));
            tail_node = head;
        }
        else
        {
            tail_node->next = (NODE*) malloc(sizeof(NODE));
            tail_node = tail_node->next;
        }

        if((i-2) == del_node_idx)
        {
            del_node = tail_node;
        }
        
        tail_node->val = atoi(argv[i]);
        tail_node->next = NULL;
    }

    delete_mid(del_node);

    while(head != NULL)
    {
        printf("%d ", head->val);
        head = head->next;
    }

    printf("\n");
}
