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

TreeNode* Remove(TreeNode **root, TreeNode *node) {
    TreeNode *y = NULL;
    if (node->left == NULL || node->right == NULL) {
        y = node;
    } else {
        y = Successor(node);
    }
    
    TreeNode *x = NULL;
    if (y->left) {
        x = y->left;
    } else {
        x = y->right;
    }
    
    if (x != NULL) {
        x->parent = y->parent;
    }

    if (y->parent == NULL) {
        *root = x;
    } else if (y == y->parent->left) {
        y->parent->left = x;
    } else {
        y->parent->right = x;
    }
    
    if (y != node) {
        node->value = y->value;
    }
    return y;
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
