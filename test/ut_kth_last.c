
#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"
#include "ch2.h"

int main(int argc, char **argv)
{
    NODE* head = NULL;
    NODE* tail_node = NULL;

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
        
        tail_node->val = atoi(argv[i]);
        tail_node->next = NULL;
    }

    NODE* kth_node = kth_last(head, atoi(argv[1]));

    printf("%d ", kth_node->val);

    printf("\n");
}
