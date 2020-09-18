//
// Created by div on 2020-08-05.
//

#ifndef DIVJOTCHAWLAASSIGN4_BINARYST_H
#define DIVJOTCHAWLAASSIGN4_BINARYST_H

// This is header file which contains all the functions which are described in source file of BSTKartz.c

#define MAX_HEIGHT 1000

typedef struct node {
    int key;
    struct node *left;
    struct node *right;
} Node, *NodePtr;

typedef struct asciiNode {
    struct asciiNode *left, *right;

    //length of the edge from this node to its children
    int edge_length;

    int height;

    int labeling;

    // 0 symbolises root, 1 symbolises right and -1 symbolises left side
    int parent_dir;

    //maximum supported unit is 32, 10 digits maximum
    char label[11];
}
AsciiNode, *AsciiNodePtr;

NodePtr create_node(int num, NodePtr left, NodePtr right);

void insert_node(int num, NodePtr *tree);

void print_ascii_tree(NodePtr root, FILE *fp);

void print_level(AsciiNodePtr node, int x, int level, FILE *fp);

void compute_edge_lengths(AsciiNodePtr node);

AsciiNodePtr build_ascii_tree_recursive(NodePtr t);

AsciiNodePtr build_ascii_tree(NodePtr t);

void free_ascii_tree(AsciiNodePtr node);

void computeLeftProfile(AsciiNodePtr node, int x, int y);

void computeRightProfile(AsciiNodePtr node, int x, int y);


#endif //DIVJOTCHAWLAASSIGN4_BINARYST_H
