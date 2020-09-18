//
// Created by div on 2020-08-05.
//
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include "BinaryST.h"
//
int leftProfile[MAX_HEIGHT];
int rightProfile[MAX_HEIGHT];

//adjust the gap between left and right nodes
int gap = 3;

//used for printing next node in the same level.
int print_next;

// This is insert_node method will insert the node
void insert_node(int num, NodePtr *tree) {
    if ((*tree) == NULL) {
        (*tree) = create_node(num, NULL, NULL);
        return;
    } else {
        if (num <= (*tree)->key) {
            insert_node(num, &((*tree)->left));
        } else {
            insert_node(num, &((*tree)->right));
        }

    }

}

// This function create_node will create a node
NodePtr create_node(int num, NodePtr left, NodePtr right) {
    NodePtr ptr = (NodePtr) malloc(sizeof(Node));
    if (ptr == NULL) {
        printf("memory not available");
        exit(1);
    } else {
        ptr->key = num;
        ptr->left = left;
        ptr->right = right;
    }
    return ptr;
}

// This function will print ASCII tree for given TREE structure
void print_ascii_tree(NodePtr t, FILE *fp) {
    AsciiNodePtr parentNode;
    int xMin, i;
    if (t == NULL) return;
    parentNode = build_ascii_tree(t);
    compute_edge_lengths(parentNode);
    for (i = 0; i < parentNode->height && i < MAX_HEIGHT; i++) {
        leftProfile[i] = INT_MAX;
    }
    computeLeftProfile(parentNode, 0, 0);
    xMin = 0;
    for (i = 0; i < parentNode->height && i < MAX_HEIGHT; i++) {
        if (xMin > leftProfile[i]) {
            xMin = leftProfile[i];
        }
    }
    for (i = 0; i < parentNode->height; i++) {
        print_next = 0;
        print_level(parentNode, -xMin, i, fp);
        printf("\n");
        fprintf(fp, "%s", "\n");
    }
    if (parentNode->height >= MAX_HEIGHT) {
        printf("(This tree is taller than %d, and may be drawn incorrectly.)\n",
               MAX_HEIGHT);
    }
    free_ascii_tree(parentNode);
}

//This function prints the given level of the  tree, assuming that the node has been given x co-ordinate.
void print_level(AsciiNodePtr node, int x, int level, FILE *fp) {
    int i, isLeft;
    if (node == NULL) return;
    isLeft = (node->parent_dir == -1);
    if (level == 0) {
        for (i = 0; i < (x - print_next - ((node->labeling - isLeft) / 2)); i++) {
            printf(" ");
            fprintf(fp, "%s", " ");
        }
        print_next += i;
        printf("%s", node->label);
        fprintf(fp, "%s", node->label);
        print_next += node->labeling;
    } else if (node->edge_length >= level) {
        if (node->left != NULL) {
            for (i = 0; i < (x - print_next - (level)); i++) {
                printf(" ");
                fprintf(fp, "%s", " ");
            }
            print_next += i;
            printf("/");
            fprintf(fp, "%s", "/");
            print_next++;
        }
        if (node->right != NULL) {
            for (i = 0; i < (x - print_next + (level)); i++) {
                printf(" ");
                fprintf(fp, "%s", " ");
            }
            print_next += i;
            printf("\\");
            fprintf(fp, "%s", "\\");
            print_next++;
        }
    } else {
        print_level(node->left,
                    x - node->edge_length - 1,
                    level - node->edge_length - 1, fp);
        print_level(node->right,
                    x + node->edge_length + 1,
                    level - node->edge_length - 1, fp);
    }
}


//This function fills in the edge_length and height fields of the specified tree.
void compute_edge_lengths(AsciiNodePtr node) {
    int h, heightMin, i, delta;
    if (node == NULL) return;
    compute_edge_lengths(node->left);
    compute_edge_lengths(node->right);

    // This will fill the edge_length of the node
    if (node->right == NULL && node->left == NULL) {
        node->edge_length = 0;
    } else {
        if (node->left != NULL) {
            for (i = 0; i < node->left->height && i < MAX_HEIGHT; i++) {
                rightProfile[i] = INT_MIN;
            }
            computeRightProfile(node->left, 0, 0);
            heightMin = node->left->height;
        } else {
            heightMin = 0;
        }
        if (node->right != NULL) {
            for (i = 0; i < node->right->height && i < MAX_HEIGHT; i++) {
                leftProfile[i] = INT_MAX;
            }
            computeLeftProfile(node->right, 0, 0);
            if (node->right->height < heightMin) {
                heightMin = node->right->height;
            }
        } else {
            heightMin = 0;
        }
        delta = 4;
        for (i = 0; i < heightMin; i++) {
            if (delta < (gap + 1 + rightProfile[i] - leftProfile[i])) {
                delta = gap + 1 + rightProfile[i] - leftProfile[i];
            }

        }

        //If the node has two children with height= 1, then we allow the two leaves to be within 1, instead of 2
        if (((node->left != NULL && node->left->height == 1) ||
             (node->right != NULL && node->right->height == 1)) && delta > 4) {
            delta--;
        }

        node->edge_length = ((delta + 1) / 2) - 1;
    }

    //This will fill in the height of the node
    h = 1;
    if (node->left != NULL) {
        if ((node->left->height + node->edge_length + 1) > h) {
            h = (node->left->height + node->edge_length + 1);
        }
    }
    if (node->right != NULL) {
        if ((node->right->height + node->edge_length + 1) > h) {
            h = (node->right->height + node->edge_length + 1);
        }
    }
    node->height = h;
}

AsciiNodePtr build_ascii_tree_recursive(NodePtr t) {
    AsciiNodePtr node;

    if (t == NULL) return NULL;

    node = malloc(sizeof(AsciiNode));
    node->left = build_ascii_tree_recursive(t->left);
    node->right = build_ascii_tree_recursive(t->right);

    if (node->left != NULL) {
        node->left->parent_dir = -1;
    }

    if (node->right != NULL) {
        node->right->parent_dir = 1;
    }

    sprintf(node->label, "%d", t->key);
    node->labeling = strlen(node->label);

    return node;
}

//Copy the tree into the ASCII node structure
AsciiNodePtr build_ascii_tree(NodePtr t) {
    AsciiNodePtr node;
    if (t == NULL) return NULL;
    node = build_ascii_tree_recursive(t);
    node->parent_dir = 0;
    return node;
}

// Freeing all the nodes of the given tree
void free_ascii_tree(AsciiNodePtr node) {
    if (node == NULL) return;
    free_ascii_tree(node->left);
    free_ascii_tree(node->right);
    free(node);
}

/*
* The following function fills in the LEFT PROFILE array for the given tree.
* It assumes that the center of the label of the root of this tree is located at a position (x, y).
* It assumes that the edge_length fields have already been computed for this tree.
*/
void computeLeftProfile(AsciiNodePtr node, int x, int y) {
    int i, isLeft;
    if (node == NULL) return;
    isLeft = (node->parent_dir == -1);
    if (leftProfile[y] > (x - ((node->labeling - isLeft) / 2))) {
        leftProfile[y] = x - ((node->labeling - isLeft) / 2);
    }

    if (node->left != NULL) {
        for (i = 1; i <= node->edge_length && y + i < MAX_HEIGHT; i++) {
            if (leftProfile[y + i] > (x - i)) {
                leftProfile[y + i] = x - i;
            }

        }
    }
    computeLeftProfile(node->left, x - node->edge_length - 1, y + node->edge_length + 1);
    computeLeftProfile(node->right, x + node->edge_length + 1, y + node->edge_length + 1);
}

/*
* The following function fills in the RIGHT PROFILE array for the given tree.
* It assumes that the center of the label of the root of this tree is located at a position (x, y).
* It assumes that the edge_length fields have already been computed for this tree.
*/
void computeRightProfile(AsciiNodePtr node, int x, int y) {
    int i, notLeft;
    if (node == NULL) return;
    notLeft = (node->parent_dir != -1);
    if (rightProfile[y] < (x + ((node->labeling - notLeft) / 2))) {
        rightProfile[y] = x + ((node->labeling - notLeft) / 2);
    }
    if (node->right != NULL) {
        for (i = 1; i <= node->edge_length && y + i < MAX_HEIGHT; i++) {
            if (rightProfile[y + i] < (x + i)) {
                rightProfile[y + i] = x + i;
            }
        }
    }
    computeRightProfile(node->left, x - node->edge_length - 1, y + node->edge_length + 1);
    computeRightProfile(node->right, x + node->edge_length + 1, y + node->edge_length + 1);
}

