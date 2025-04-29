#include "binary_trees.h"

/**
* binary_tree_depth - Measures the depth of a node in a binary tree
* @tree: Pointer to the node to measure the depth
*
* Return: Depth of the node
*/
size_t binary_tree_depth(const binary_tree_t *tree)
{
size_t depth = 0;

while (tree && tree->parent)
{
tree = tree->parent;
depth++;
}

return (depth);
}

/**
* is_perfect_recursive - Helper function to check if the tree is perfect
* @tree: Pointer to the root node of the tree
* @depth: Depth of the tree
* @level: Current level of the node
*
* Return: 1 if tree is perfect, 0 otherwise
*/
int is_perfect_recursive(const binary_tree_t *tree, size_t depth, size_t level)
{
if (tree == NULL)
return (1);

/* If it's a leaf node, check if it's at the correct depth */
if (tree->left == NULL && tree->right == NULL)
return (level == depth);

/* If it has only one child, it's not perfect */
if (tree->left == NULL || tree->right == NULL)
return (0);

/* Recursively check the left and right subtrees */
return (is_perfect_recursive(tree->left, depth, level + 1) &&
is_perfect_recursive(tree->right, depth, level + 1));
}

/**
* binary_tree_is_perfect - Checks if a binary tree is perfect
* @tree: Pointer to the root node of the tree to check
*
* Return: 1 if the tree is perfect, 0 otherwise
*/
int binary_tree_is_perfect(const binary_tree_t *tree)
{
size_t depth;

if (tree == NULL)
return (0);

/* Get the depth of the leftmost leaf */
depth = binary_tree_depth(tree);

/* Use the helper function to check if the tree is perfect */
return (is_perfect_recursive(tree, depth, 0));
}
