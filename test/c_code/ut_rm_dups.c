
#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"
#include "ch2.h"

int main(int argc, char **argv)
{
    NODE* head = NULL;
    NODE* tail_node = NULL;

    for(int i=1; i < argc; ++i)
    {
        printf("adding val %d to list\n", atoi(argv[i]));
        if(i == 1)
        {
            head = (NODE*) malloc(sizeof(NODE));
            tail_node = head;
        }
        else
        {
            tail_node->next = (NODE*) malloc(sizeof(NODE));
            tail_node = tail_node->next;
        }
        
        tail_node->val = atoi(argv[i]);
        tail_node->next = NULL;
    }

    remove_dups(head);

    while(head != NULL)
    {
        printf("%d ", head->val);
        head = head->next;
    }

    printf("\n");
}
