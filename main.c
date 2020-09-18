#include <stdio.h>
#include <stdlib.h>
#include "BinaryST.h"
#include  <string.h>

/*
 * Author: Divjot Chawla
 * Description: This code takes a serialized text file of a tree upto 32 nodes and builds its stick diagram in the
 * console and output.txt file.
 */

// main method asks for the input file name and then prints all the data in the file in a serialized tree both in output and console.
int main() {
    char filename[40];
    char str[120];

    int val;
    NodePtr root = NULL; // creates the root of a BST
    printf("Enter File Name (input1/ input2): \n");
    scanf("%s", filename);
    FILE *in = fopen(filename, "r"); // input text file, mode read
    if (in == NULL) {
        printf("\n There is NO SUCH FILE FOUND. Please enter a valid input file name. \n");
        return 0;
    }

    while (fscanf(in, "%s", str) == 1) {
        if (strcmp(str, "@") == 0) {
            continue;
        }
        val = atoi(str);
        insert_node(val, &root);
    }
    fclose(in);

    FILE *out = fopen("output.txt", "w");   // output text file, mode write
    if (out != NULL) {
        print_ascii_tree(root, out);
        fclose(out);
    }
    return 0;
}
