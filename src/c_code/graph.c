#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "graph.h"

void graph_init(Graph* g)
{
    ll_init(&g->nodes);
}

GraphNode* graph_init_node(int val)
{
    GraphNode* new_node = (GraphNode*) malloc(sizeof(GraphNode));
    new_node->val = val;
    new_node->is_visited = false;
    new_node->num_incoming = 0;
    ll_init(&new_node->neighbors);

    return new_node;
}

void graph_add_neighbor(GraphNode* gn, GraphNode* neighbor)
{
    ll_push_back(&gn->neighbors, (void*) neighbor);
}

void graph_reset_dfs(GraphNode* gn)
{
    if(gn == NULL || gn->is_visited == false)
    {
        return;
    }

    gn->is_visited = false;
    
    ListNode* cur_neighbor = gn->neighbors.head;
    while(cur_neighbor != NULL)
    {
        graph_reset_dfs((GraphNode*) cur_neighbor->val);
        cur_neighbor = cur_neighbor->next;
    }
}

GraphNode* graph_dfs(GraphNode* gn, int search_val)
{
    if(gn == NULL || gn->is_visited)
    {
        return NULL;
    }

    gn->is_visited = true;
    if(gn->val == search_val)
    {
        return gn;
    }

    
    ListNode* cur_neighbor = gn->neighbors.head;
    while(cur_neighbor != NULL)
    {
        GraphNode* fgn = graph_dfs((GraphNode*) cur_neighbor->val, search_val);
        cur_neighbor = cur_neighbor->next;
        if(fgn != NULL)
        {
            return fgn;
        }
    }
    
    return NULL;
}

bool graph_has_path_dfs(GraphNode* start, int val)
{
    if(start == NULL)
    {
        return false;
    }

    GraphNode* found_node = graph_dfs(start, val);
    graph_reset_dfs(start);

    return found_node != NULL && found_node->val == val;
}

void graph_reset_visited(Graph* g)
{
    if(g == NULL)
        return;

    for(ListIter iter = ll_init_iter(&g->nodes); iter != NULL; iter = ll_next_iter(iter))
    {
        GraphNode* node = (GraphNode*) iter->val;
        node->is_visited = false;
    }
}

bool graph_node_cmp(void* v1, void* v2)
{
    GraphNode* gn = (GraphNode*) v1;
    return gn->val == *(int*)v2;
}

GraphNode* graph_find_node(Graph* g, int val)
{
    ListNode* found_node = ll_find(&g->nodes, (void*)&val, &graph_node_cmp);
    if(found_node == NULL)
    {
        return NULL;
    }

    return (GraphNode*) found_node->val;
}

Graph graph_from_file(char* filename)
{
    FILE* fid = fopen(filename, "r");
    char fbuff[64] = "";

    Graph g;
    graph_init(&g);

    while(fgets(fbuff, 64, fid) != NULL)
    {
        //Get node to process
        GraphNode* cur_node = NULL;
        char* tok = strtok(fbuff, ",");
        int val = atoi(tok);

        //if node doesn't exist then init it
        cur_node = graph_find_node(&g, val);
        if(cur_node == NULL)
        {
            cur_node = graph_init_node(val);
            ll_push_back(&g.nodes, (void*)cur_node);
        }

        // add all the neighbors of current node
        tok = strtok(NULL, ",");
        while(tok != NULL)
        {
            int neighbor_val = atoi(tok);
            //check if neighbor exists already 
            GraphNode* neighbor_node = graph_find_node(&g, neighbor_val);
            if(neighbor_node == NULL)
            {
                neighbor_node = graph_init_node(neighbor_val);
                ll_push_back(&g.nodes, (void*)neighbor_node);
            }

            //add neighbor node to neighbors list
            graph_add_neighbor(cur_node, neighbor_node);

            tok = strtok(NULL, ",");
        }
    }

    fclose(fid);

    return g;
}
