
#include <stdbool.h>
#include "linked_list.h"

#define MAX_NUM_NEIGHBORS 5

typedef struct graph_node
{
    int val;
    bool is_visited;
    int num_neighbors;
    struct graph_node* neighbors[MAX_NUM_NEIGHBORS];    
} GraphNode;

typedef struct graph
{
    SinglyList nodes;
} Graph;

Graph graph_from_file(char* filename);

GraphNode* graph_find_node(Graph* g, int val);

bool graph_has_path_dfs(GraphNode* start, int val);

