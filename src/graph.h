
#ifndef GRAPH_H
#define GRAPH_H

#include <stdbool.h>
#include "linked_list.h"

#define MAX_NUM_NEIGHBORS 5

typedef struct graph_node
{
    int val;
    bool is_visited;
    SinglyList neighbors;
    int num_incoming;
} GraphNode;

typedef struct graph
{
    SinglyList nodes;
} Graph;

Graph graph_from_file(char* filename);
void graph_add_neighbor(GraphNode* gn, GraphNode* neighbor);

GraphNode* graph_find_node(Graph* g, int val);

bool graph_has_path_dfs(GraphNode* start, int val);

void graph_init(Graph* g);
GraphNode* graph_init_node(int val);

#endif
