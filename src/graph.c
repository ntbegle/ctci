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
    new_node->num_neighbors = 0;
    new_node->val = val;
    new_node->is_visited = false;

    return new_node;
}

void graph_add_neighbor(GraphNode* gn, GraphNode* neighbor)
{
    gn->neighbors[gn->num_neighbors++] = neighbor;
}

void graph_reset_dfs(GraphNode* gn)
{
    if(gn == NULL || gn->is_visited == false)
    {
        return;
    }

    gn->is_visited = false;
    
    for(int i=0; i < gn->num_neighbors; ++i)
    {
        graph_reset_dfs(gn->neighbors[i]);
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

    for(int i=0; i < gn->num_neighbors; ++i)
    {
        GraphNode* fgn = graph_dfs(gn->neighbors[i], search_val);
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
        for(int i=0; i < MAX_NUM_NEIGHBORS && tok != NULL; ++i)
        {
            int neighbor_val = atoi(tok);
            //check if neighbor exists already 
            GraphNode* neighbor_node = graph_find_node(&g, neighbor_val);
            if(neighbor_node == NULL)
            {
                neighbor_node = graph_init_node(neighbor_val);
                ll_push_back(&g.nodes, (void*)neighbor_node);
            }

            //add neighbor node to neighbors array
            graph_add_neighbor(cur_node, neighbor_node);

            tok = strtok(NULL, ",");
        }
    }

    fclose(fid);

    return g;
}
