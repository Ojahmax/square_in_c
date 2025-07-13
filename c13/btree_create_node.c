#include <stdlib.h>

typedef struct s_btree {
    void *item;
    struct s_btree *left;
    struct s_btree *right;
} t_btree;

t_btree *btree_create_node(void *item) {
    t_btree *node = malloc(sizeof(t_btree));
    if (node == NULL) {
        return NULL;
    }
    node->item = item;
    node->left = NULL;
    node->right = NULL;
    return node;
}
