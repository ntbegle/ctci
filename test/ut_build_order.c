
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ch4.h"
#include "graph.h"
#include "linked_list.h"

int main(int argc, char** argv)
{
    if(argc != 2)
    {
        printf("Bad arguments\n");
        return -1;
    }

    FILE* fid = fopen(argv[1], "r");
    if(fid == NULL)
    {
        printf("Bad filename\n");
        return -1;
    }

    char fbuff[64];
    int pkgs[64];
    int deps[64][2];

    if(fgets(fbuff, 64, fid) == NULL)
    {
        printf("File empty\n");
        return -1;
    }

    char* tok = strtok(fbuff, " ");
    int num_pkgs;
    for(num_pkgs = 0; num_pkgs < 64 && tok != NULL; ++num_pkgs)
    {
        pkgs[num_pkgs] = atoi(tok);
        tok = strtok(NULL, " ");
    }
    
    int num_deps = 0;
    while(fgets(fbuff, 64, fid) != NULL && num_deps < 64)
    {
        deps[num_deps][0] = atoi(strtok(fbuff, " "));
        deps[num_deps][1] = atoi(strtok(NULL, " "));
        ++num_deps;
    }

    fclose(fid);

    Graph* dep_graph = mk_dep_graph(pkgs, num_pkgs, deps, num_deps);

    SinglyList* dep_list = build_dep_list(dep_graph);

    if(dep_list->len != dep_graph->nodes.len)
    {
        printf("ERROR: Circular dependency\n");
    }
    else
    {
        printf("Dependency List: ");
        for(ListIter iter = ll_init_iter(dep_list); iter != NULL; iter = ll_next_iter(iter))
        {
            GraphNode* cur_node = (GraphNode*) iter->val;
            printf("%d ", cur_node->val);
        }

        printf("\n");
    }
}
