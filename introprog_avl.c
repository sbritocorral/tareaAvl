/* === INTROPROG ABGABE ===
 * Blatt 11, Aufgabe 2
 * Tutorium: t09
 * Gruppe: g19
 * Gruppenmitglieder:
 *  - Sebastian Brito
 *  - Jose Castillo
 * ========================
 */

#include <stdlib.h>
#include <stdio.h>    //Ein- / Ausgabe
#include <math.h>     //Für die Berechnungen der Ausgabe
#include "avl.h"

// Gibt den gesamten AVL Baum in "in-order" Reihenfolge aus.


void AVL_in_order_walk_node(AVLNode* node)
{
	if (node != NULL)
	{
		AVL_in_order_walk(node->left);

		printf("%d\n", node->value);

		AVL_in_order_walk(node->right);
	}   
}

void AVL_in_order_walk(AVLTree* avlt)
{
	if (avlt != NULL)
	{
		AVL_in_order_walk(avlt->root);
	}    
}


/*int node_balanced_height(AVLNode * node){

	int height_left = 0;
	int height_right = 0;

	if (node->left)
	{
		height_left = node_balanced_height(node->left);
	}

	if (node->right)
	{
		height_right = node_balanced_height(node->right);
	}

	
	

	return ((height_left - height_right == 0) || (height_right - height_left == 0))

}*/


// Diese Funktion führt eine Linksrotation auf dem angegebenen Knoten aus.
// Beachtet: Die Höhen der entsprechenden Teilbäume müssen (lokal) 
// angepasst werden.
void AVL_rotate_left(AVLTree* avlt, AVLNode* x)
{
   	AVLNode * y = x->right; 

   	x->right = y->left;

   	if (y->left != NULL)	
   	{
   		y->left->parent = x;
   	}
   	y->parent = x->parent;

   	if (x->parent != NULL)
   	{
   		avlt->root = y;
   	}
   	else if (x == x->parent->left)
   	{
   		x->parent->left = y; 
   	}
   	else
   	{
   		x->parent->right = y;
   	}


   	y->left = x;
   	x->parent = y;



}

// Diese Funktion führt eine Rechtsrotation auf dem angegebenen Knoten aus.
// Beachtet: Die Höhen der entsprechenden Teilbäume müssen (lokal) 
// angepasst werden.
void AVL_rotate_right(AVLTree* avlt, AVLNode* y)
{
    







}

//Balanciere den Teilbaum unterhalb von node.
void AVL_balance(AVLTree* avlt, AVLNode* node)
{
    
}


void init_elem(AVLNode * node){

	new_elem->left = NULL;
	new_elem->parent = NULL;
	new_elem->right = NULL;
	new_elem->value = 0;
	new_elem->height = 0;

}



// Fügt der Wert value in den Baum ein.
// Die Implementierung muss sicherstellen, dass der Baum nach dem Einfügen
// immer noch balanciert ist!
void AVL_insert_value(AVLTree* avlt, int value)
{
	
	AVLNode * new_elem = malloc(sizeof(AVLNode));

	init_elem(new_elem);

	if (avlt == NULL)
	{
		new_elem->value = value;
		avlt->root = new_elem;
	}
	else if (new_elem->value <= avlt->root->value)
	{
		AVL_insert_value(avlt->root->left, value);
	}
	else if (new_elem->value > avlt->root->value)
	{
		AVL_insert_value(avlt->root->right, x);
	}
	else
	{
		return;
	} 

	avlt->root->height = 1 + max(avlt->root->left->height, avlt->root->right->height);
    
}


// Löscht den gesamten AVL-Baum und gibt den Speicher aller Knoten frei.
void AVL_remove_all_elements(AVLTree* avlt)
{
    //Hier Code implementieren!
}














































