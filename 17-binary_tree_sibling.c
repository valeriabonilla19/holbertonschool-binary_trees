#include "binary_trees.h"

/**
* binary_tree_sibling - Finds the sibling of a node in a binary tree
* @node: Pointer to the node to find the sibling for
*
* Return: A pointer to the sibling node, or NULL if node is NULL,
*         parent is NULL, or node has no sibling
*/
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
if (node == NULL || node->parent == NULL)
return (NULL);

/* If the node is the left child, return the right sibling, and vice versa */
if (node->parent->left == node)
return (node->parent->right);
else
return (node->parent->left);
}
