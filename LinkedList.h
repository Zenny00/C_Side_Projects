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
int MAX_BOOK_TITLE_LENGTH = 256;
int MAX_AUTHOR_NAME_LENGTH = 256;

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

    // Allocate space for input from console
    // 1 is added to the maximum to leave space for the end of line character '\0'
    new_book->name = (char *)malloc((MAX_AUTHOR_NAME_LENGTH+1)*sizeof(char)); 
    new_book->author = (char *)malloc((MAX_BOOK_TITLE_LENGTH+1)*sizeof(char));

    // If heap is full, exit the program
    if (new_book->name == NULL || new_book->author == NULL) {
        printf("The heap is full, no new space to allocate.\n");
        exit(0);
    }

    // Assign values to book data attributes using the console
    // Ensure user input was correctly received

    // Book title
    printf("Please enter the name of the book: ");
    if (fgets(new_book->name, MAX_BOOK_TITLE_LENGTH, stdin) == NULL) {
        printf("Error getting user input.\n");
        exit(0);
    }

    // Book author
    printf("Please enter the name of the author: ");
    if (fgets(new_book->author, MAX_AUTHOR_NAME_LENGTH, stdin) == NULL) {
        printf("Error getting user input.\n");
        exit(0);
    }

    // Book date
    printf("Please enter the year of publication: ");
    if (scanf("%d", &new_book->date) != 1) {
        printf("Error getting user input.\n");
        exit(0);
    }

    // Next book is initially set to nothing
    new_book->next = NULL;

    printf("The book name is %s\n", new_book->name);
    printf("The book author is %s\n", new_book->author);
    printf("The book publishing date is %d\n", new_book->date);

    free(new_book->name);
    free(new_book->author);
    free(new_book);
}

#endif