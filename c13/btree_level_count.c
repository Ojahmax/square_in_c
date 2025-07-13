#include "ft_btree.h"

int btree_level_count(t_btree *root) {
    if (root == NULL) {
        return 0;
    }
    int left_height = btree_level_count(root->left);
    int right_height = btree_level_count(root->right);
    return (left_height > right_height) ? left_height + 1 : right_height + 1;
}
