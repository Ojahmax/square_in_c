#include "ft_btree.h"

void *btree_search_item(t_btree *root, void *data_ref, int (*cmpf)(void *, void *)) {
    void *result;

    if (root == NULL) {
        return NULL;
    }
    result = btree_search_item(root->left, data_ref, cmpf);
    if (result != NULL) {
        return result;
    }
    if (cmpf(root->item, data_ref) == 0) {
        return root->item;
    }
    return btree_search_item(root->right, data_ref, cmpf);
}
