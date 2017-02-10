#ifndef BINARY_TREE_H_5J
#define BINARY_TREE_H_5J

typedef struct TreeNode_ {
    int value;
    struct TreeNode_ *left;
    struct TreeNode_ *rigth;
    struct TreeNode_ *parent;
} TreeNode;

TreeNode* Min(TreeNode *node) {
    while (node && node->left) {
        node = node->left;
    }
    return node;
}

TreeNode* Max(TreeNode *node) {
    while (node && node->right) {
        node = node->right;
    }
    return node;
}

TreeNode* Remove(TreeNode *root, TreeNode *node) {
    return NULL;
}

TreeNode* Successor(TreeNode *node) {
    if (node == NULL) {
        return NULL;
    } else if (node->right) {
        return Min(node->right);
    } else {
        TreeNode* p = node->parent;
        while (p && node == p->right) {
            node = p;
            p = p->parent;
        }
        return node;
    }
}

TreeNode* Predeccessor(TreeNode *node) {
    if (node == NULL) {
        return NULL;
    } else if (node->left) {
        return Max(node->left);
    } else {
        TreeNode *p = node->parent;
        while (p && node == p->left) {
            node = p;
            p = p->parent;
        }
        return node;
    }
}

#endif
