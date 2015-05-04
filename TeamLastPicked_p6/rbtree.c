#include "rbtree.h"

void * getElement(node * root, int id)
{
	if (id > root->id)
	{
		return getElement(root->right, id);
	}
	else if (id < root->id)
	{
		return getElement(root->left, id);
	}
	else
	{
		return root->payload;
	}
}

void insertElement(node * root, void * payload, int id)
{
	// First, malloc a new node.
	node * new = (node *) malloc(sizeof(node));
	if (new == NULL)
	{
		perror("Cannot malloc new node");
		return;
	}
	
	// Set to safe values.
	new->payload = payload;
	new->id = id;
	new->parent = NULL;
	new->left = NULL;
	new->right = NULL;
	// New node is initially red
	new->color = RED;
	
	// Find its spot in the tree.
	node * parent = root;
	if (parent == NULL)
	{
		// This is the first node. Color it black, and we're done.
		new->color = BLACK;
	}
	else
	{
		// Not the first node. 
		// Find its spot in the tree.
		while(1)
		{
			if (id > parent->id)
			{
				if (parent->right == NULL)
				{
					parent->right = new;
					break;
				}
				else
					parent = parent->right;
			}
			else
			{
				if (parent->left == NULL)
				{
					parent->left = new;
					break;
				}
				else
					parent = parent->left;
			}
		}
		// Found the right spot.
		new->parent = parent;
	}
	
	// At this point, we have to determine if we do any tree rotations.
	
	
}

void deleteElement(node * root, int id)
{
	
}

/**
 * Gets the grandparent of the node.
 * @param n node to get grandparent of
 * @return node's grandparent, NULL if its parent or grandparent doesn't exist
 */
node * getGrandparent(node * n)
{
	if (n->parent != NULL)
	{
		return n->parent->parent;
	}
	else
		return NULL;
}

/**
 * This gets the uncle node to the current node.
 * @param n node to get uncle of
 * @return n's uncle, NULL if it doesn't have one.
 */
node * getUncle(node * n)
{
	if (n->parent != NULL)
	{
		if (n->parent->left == n)
			return n->parent->right;
		else
			return n->parent->left;
	}
	return NULL;
}