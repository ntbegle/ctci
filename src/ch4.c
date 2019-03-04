
#include <limits.h>
#include <stdlib.h>
#include <stdio.h>

#include "graph.h"
#include "queue.h"
#include "linked_list.h"
#include "ch4.h"

void list_of_depths_recurse(SinglyList* lists, BinaryTreeNode* btn, int level)
{
    if(btn == NULL)
        return;

    printf("Cur Level %d\n", level);
    ll_push_back(&lists[level], (void*) btn);
    list_of_depths_recurse(lists, btn->left, level+1);
    list_of_depths_recurse(lists, btn->right, level+1);
}

void list_of_depths(SinglyList* lists, BinaryTree* bt)
{
    if(bt == NULL || lists == NULL)
        return;
    
    list_of_depths_recurse(lists, bt->head, 0);
}

int check_balance_recurse(BinaryTreeNode* btn)
{
    if(btn == NULL)
        return 0;

    int num_nodes_left = check_balance_recurse(btn->left);
    int num_nodes_right = check_balance_recurse(btn->right);
    if(num_nodes_left < 0 || num_nodes_right < 0 || abs(num_nodes_left - num_nodes_right) > 1)
    {
        return -1;
    }
    
    return num_nodes_left + num_nodes_right + 1;
}

bool check_balance(BinaryTree* bt)
{
    if(bt == NULL)
        return true;

    return check_balance_recurse(bt->head) >= 0;
}

bool validate_bst_recurse(BinaryTreeNode* bstn, int* last)
{
    if(bstn == NULL)
        return true;

    if(!validate_bst_recurse(bstn->left, last))
    {
        return false;
    }

    if(bstn->val <= *last)
    {
        return false;
    }

    *last = bstn->val;

    if(!validate_bst_recurse(bstn->right, last))
    {
        return false;
    }        

    return true;
}

bool validate_bst(BinaryTree* bst)
{
    if(bst == NULL)
        return true;

    int last = INT_MIN;
    return validate_bst_recurse(bst->head, &last); 
}

BinaryTreeNode* successor_recurse(BinaryTreeNode* head, int val, bool* found)
{
    if(head == NULL)
        return NULL;

    BinaryTreeNode* left_ret = successor_recurse(head->left, val, found);
    if(left_ret != NULL)
    {
        return left_ret;
    }

    if(*found == true)
    {
        return head;
    }

    if(head->val == val)
    {
        *found = true;
    }
    BinaryTreeNode* right_ret = successor_recurse(head->right, val, found);
    if(right_ret != NULL)
    {
        return right_ret;
    }

    return NULL;
}

BinaryTreeNode* successor(BinaryTreeNode* head, int val)
{
    bool found = false;

    BinaryTreeNode* node = successor_recurse(head, val, &found);

    return node;
}



Graph* mk_dep_graph(int* pkgs, int num_pkgs, int pkg_deps[][2], int num_deps)
{
    Graph* g = (Graph*) malloc(sizeof(Graph));
    graph_init(g);

    for(int i = 0; i < num_pkgs; ++i)
    {
        GraphNode* cur_node = graph_find_node(g, pkgs[i]);
        if(cur_node == NULL)
        {
            cur_node = graph_init_node(pkgs[i]);
            ll_push_front(&g->nodes, (void*)cur_node);
        }
        
        for(int j = 0; j < num_deps; ++j)
        {
            if(pkgs[i] == pkg_deps[j][0])
            {    
                GraphNode* neighbor_node = graph_find_node(g, pkg_deps[j][1]);
                if(neighbor_node == NULL)
                {
                    neighbor_node = graph_init_node(pkg_deps[j][1]);
                    ll_push_front(&g->nodes, (void*)neighbor_node);
                }
                
                neighbor_node->num_incoming += 1;
                graph_add_neighbor(cur_node, neighbor_node);
            }
        }
    }

    return g;
}

void add_dep_to_list(GraphNode* parent, SinglyList* dep_list)
{
    Queue q;
    queue_init(&q);
    GraphNode* cur_node = parent;

    while(cur_node != NULL)
    {
        if(!cur_node->is_visited && cur_node->num_incoming == 0)
        {
            ll_push_back(dep_list, cur_node);
            cur_node->is_visited = true;

            for(ListIter iter = ll_init_iter(&cur_node->neighbors); iter != NULL; iter = ll_next_iter(iter))
            {
                ((GraphNode*)iter->val)->num_incoming -= 1;
                queue_add(&q, iter->val);
            }
        }

        cur_node = queue_remove(&q);
    }
}

SinglyList* build_dep_list(Graph* dep_graph)
{
    SinglyList* dep_list = (SinglyList*) malloc(sizeof(SinglyList));
    ll_init(dep_list);

    for(ListIter iter = ll_init_iter(&dep_graph->nodes); iter != NULL; iter = ll_next_iter(iter))
    {
        GraphNode* gnode = (GraphNode*) iter->val;

        if(gnode->num_incoming == 0 && !gnode->is_visited)
        {
            add_dep_to_list(gnode, dep_list);
        }
    }

    return dep_list;
} 
