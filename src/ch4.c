
#include "graph.h"
#include "ch4.h"


bool route_between_nodes(Graph* g, int end_point)
{
    return has_path(g, end_point) != NULL;
}   
