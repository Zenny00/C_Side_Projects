// Name: Joshua Comfort
// Date: 6/20/2023
// Description: Linked list implemented in a separate file to increase driver program clarity

// Needed header files
#include <malloc.h>
#include <stdlib.h>
#include <stdio.h>

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

// Constants for book attributes

// Nodes in this linked list will represent books, they will have the following information
// Name: The name of the book represented as a string
// Author: The author of the book represented as a string
// Date: The year the book was published represented as an int
// Next: The following book on the shelf, pointer to a book
struct book {
    char *name;
    char *author;
    int date;
    struct book *next;
};

// Create node function one function given the input parameters the other will prompt the user for input from the keyboard

struct book * create_node() {
    struct book *new_book = (struct book*)malloc(sizeof(struct book)); // Create a new book on the heap

    // Guard clause for full heap
    if (new_book == NULL) {
        // Heap is full
        printf("The heap is full, no new space to allocate.\n");
        exit(0);
    }

    //new_book->name = (char *)malloc(())
}

#endif