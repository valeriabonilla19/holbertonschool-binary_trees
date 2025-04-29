#include "binary_trees.h"

/**
* binary_tree_insert_left - Inserts a node as the left-child of another node
* @parent: A pointer to the node to insert the left-child in
* @value: The value to store in the new node
*
* Return: A pointer to the new node, or NULL on failure or if parent is NULL
*/
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
binary_tree_t *new_node;

if (parent == NULL)
return (NULL);

new_node = binary_tree_node(parent, value);  /* Create the new node */
if (new_node == NULL)
return (NULL);

if (parent->left != NULL)
{
new_node->left = parent->left;
parent->left->parent = new_node;  /* Set the parent of the old left-child */
}

parent->left = new_node;  /* Insert the new node as the left-child */
return (new_node);
}
