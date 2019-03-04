
#include "graph.h"
#include "linked_list.h"
#include "binary_tree.h"

void list_of_depths(SinglyList* lists, BinaryTree* bt);
bool check_balance(BinaryTree* bt);
bool validate_bst(BinaryTree* bst);

typedef struct binary_tree_node_dl
{
    int val;
    struct binary_tree_node_dl* left;
    struct binary_tree_node_dl* right;
    struct binary_tree_node_dl* parent;
} BinaryTreeNodeDl;

BinaryTreeNode* successor(BinaryTreeNode* head, int val);

SinglyList* build_dep_list(Graph* dep_graph);
Graph* mk_dep_graph(int* pkgs, int num_pkgs, int pkg_deps[][2], int num_deps);
