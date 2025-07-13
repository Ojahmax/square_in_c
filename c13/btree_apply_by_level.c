#include "ft_btree.h"
#include <stdlib.h>

int btree_level_count(t_btree *root) {
    if (root == NULL)
        return 0;
    int left_height = btree_level_count(root->left);
    int right_height = btree_level_count(root->right);
    return (left_height > right_height) ? left_height + 1 : right_height + 1;
}

void process_level(t_btree *root, int level, int current_level, void (*applyf)(void *, int, int), int *is_first) {
    if (root == NULL)
        return;
    if (current_level == level) {
        applyf(root->item, level, *is_first);
        *is_first = 0;
        return;
    }
    process_level(root->left, level, current_level + 1, applyf, is_first);
    process_level(root->right, level, current_level + 1, applyf, is_first);
}

void btree_apply_by_level(t_btree *root, void (*applyf)(void *, int, int)) {
    if (root == NULL)
        return;
    int height = btree_level_count(root);
    for (int level = 0; level < height; level++) {
        int is_first = 1;
        process_level(root, level, 0, applyf, &is_first);
    }
}
