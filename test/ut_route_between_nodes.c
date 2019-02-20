
#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"
#include "graph.h"
//#include "ch4.h"

int main(int argc, char** argv)
{
    char* graph_file = argv[1];

    int start = atoi(argv[2]);
    int stop = atoi(argv[3]);

    printf("Graph File: %s\n", graph_file);
    printf("Start Node: %d\n", start);
    printf("Stop Node: %d\n", stop);

    Graph g = graph_from_file(graph_file);

    GraphNode* starting_point = graph_find_node(&g, start);

    bool has_path = graph_has_path_dfs(starting_point, stop);

    if(has_path)
    {
        printf("Graph has path from %d to %d\n", start, stop);
    }
    else
    {
        printf("Graph does not have a path from %d to %d\n", start, stop);
    } 
}
