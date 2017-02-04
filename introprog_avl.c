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
#include <stdio.h> //Ein- / Ausgabe
#include <math.h>  //Für die Berechnungen der Ausgabe
#include "avl.h"

// Gibt den gesamten AVL Baum in "in-order" Reihenfolge aus.

void AVL_in_order_walk_node(AVLNode *node)
{
    if (node != NULL)
    {
        AVL_in_order_walk_node(node->left);

        printf("%d ", node->value);
        printf("SetHeight: %d\n", node->height);

        AVL_in_order_walk_node(node->right);
    }
}

void AVL_in_order_walk(AVLTree *avlt)
{
    if (avlt != NULL)
    {
        AVL_in_order_walk_node(avlt->root);
        printf("\n");
    }
}

int max(int x, int y)
{

    if (x > y)
        return x;
    return y;
}

int height(AVLNode *node)
{
    if (node == NULL)
    {
        return -1;
    }
    if (node->left == NULL && node->right == NULL)
    {
        return 0;
    }
    else if (node->left == NULL)
    {
        return 1 + height(node->right);
    }
    else if (node->right == NULL)
    {
        return 1 + height(node->left);
    }
    else
    {
        return 1 + max(height(node->left), height(node->right));
    }
}

void setHeight(AVLNode *node)
{
    node->height = height(node->right) - height(node->left);
}

// Diese Funktion führt eine Linksrotation auf dem angegebenen Knoten aus.
// Beachtet: Die Höhen der entsprechenden Teilbäume müssen (lokl)
// angepasst werden.
void AVL_rotate_left(AVLTree *avlt, AVLNode *x)
{
    AVLNode *y = x->right;

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
// Beachtet: Die Höhen der entsprechenden Teilbäume müssen (lokl)
// angepasst werden.
void AVL_rotate_right(AVLTree *avlt, AVLNode *y)
{

    AVLNode *x = y->left;

    y->left = x->right;

    if (x->right != NULL)
    {
        x->right->parent = y;
    }
    x->parent = y->parent;

    if (y->parent != NULL)
    {
        avlt->root = x;
    }
    else if (y == y->parent->left)
    {
        y->parent->right = x;
    }
    else
    {
        y->parent->left = x;
    }

    x->left = y;
    y->parent = x;
}

//Balanciere den Teilbaum unterhalb von node.
/*void AVL_balance(AVLTree *avlt, AVLNode *node)
{
    AVLNode *y = node;

    setHeight(node);

    if (y->left->height > y->right->height + 1)
    {
        if (y->left->left->height < y->left->right->height)
        {
            AVL_rotate_left(avlt, y->left);
        }
        AVL_rotate_right(avlt, y);
    }
    else if (y->right->height > y->left->height + 1)
    {
        if (y->right->right->height < y->right->left->height)
        {
            AVL_rotate_right(avlt, y->right);
        }
        AVL_rotate_left(avlt, y);
    }
}*/
void init_elem(AVLNode *node)
{

    node->left = NULL;
    node->parent = NULL;
    node->right = NULL;
    node->value = 0;
    node->height = 0;
}

void AVL_insert_node(AVLNode *root, AVLNode *node)
{
    if (node->value < root->value)
    {
        if (root->left == NULL)
        {
            root->left = node;
            node->parent = root;
            //setHeight(root);
            return;
        }
        AVL_insert_node(root->left, node);
    }
    else if (node->value > root->value)
    {
        if (root->right == NULL)
        {
            root->right = node;
            node->parent = root;
            //setHeight(root);
            return;
        }
        AVL_insert_node(root->right, node);
    }
}

// Fügt der Wert value in den Baum ein.
// Die Implementierung muss sicherstellen, dass der Baum nach dem Einfügen
// immer noch balanciert ist!
void AVL_insert_value(AVLTree *avlt, int value)
{

    AVLNode *new_elem = malloc(sizeof(AVLNode));

    init_elem(new_elem);
    new_elem->value = value;

    if (avlt->root == NULL)
    {
        avlt->root = new_elem;
        avlt->numberOfNodes++;
    }
    else
    {
        AVL_insert_node(avlt->root, new_elem);
        avlt->numberOfNodes++;
        //int s =  height(avlt->root);
        //printf("Esto es height: %d\n", s)
    }

    //avlt->root->height =  ;
}

void free_elems(AVLNode *node)
{

    if (node != NULL)
    {
        free_elems(node->left);
        free_elems(node->right);

        free(node);
    }
}

// Löscht den gesamten AVL-Baum und gibt den Speicher aller Knoten frei.
void AVL_remove_all_elements(AVLTree *avlt)
{
    free_elems(avlt->root);
}
