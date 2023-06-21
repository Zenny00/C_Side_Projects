// Name: Joshua Comfort
// Date: 6/20/2023
// Description: Linked list implemented in a separate file to increase driver program clarity

// Needed header files
#include <malloc.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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
    if (!fgets(new_book->name, MAX_BOOK_TITLE_LENGTH, stdin)) {
        // Error geting user input from the console
        printf("Error getting user input.\n");
        exit(0);
    }

    // Trim trailing '\n' character from the input string
    new_book->name[strcspn(new_book->name, "\n")] = 0;

    // Book author
    printf("Please enter the name of the author: ");
    if (!fgets(new_book->author, MAX_AUTHOR_NAME_LENGTH, stdin)) {
        // Error geting user input from the console
        printf("Error getting user input.\n");
        exit(0);
    }

    // Trim trailing '\n' character from the input string
    new_book->author[strcspn(new_book->author, "\n")] = 0;

    // Book date
    printf("Please enter the year of publication: ");
    if (scanf("%d", &new_book->date) != 1) {
        printf("Error getting user input.\n");
        exit(0);
    }

    // Clear buffer
    while ((getchar()) != '\n');

    // Next book is initially set to nothing
    new_book->next = NULL;

    // Return the reference to the newly created node
    return new_book;
}

struct book * create_node_given_data(char *name, char *author, int date) {
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

    // Assign values based on input parameters
    strcpy(new_book->name, name);
    strcpy(new_book->author, author);
    new_book->date = date;

    // Next book is initially set to nothing
    new_book->next = NULL;

    // Return the reference to the newly created node
    return new_book;
}

// Given a pointer to a book node, first free the memory allocated to store the data attributes then free the memory allocated to store the struct
void destroy_node(struct book *book_node) {
    free(book_node->name);
    free(book_node->author);
    free(book_node);
}

// Print the contents of the node, primarily used for debugging
void print_node(struct book *book_node) {
    printf("The name of the book is %s\n", book_node->name);
    printf("The name of the author is %s\n", book_node->author);
    printf("The date of publication is %d\n", book_node->date);
}

// Add a node to the linked list, books are added in order of the titles, sorted in alphabetical order
// Takes in a reference to a pointer to the head of the list as an input parameter
void insert(struct book **head) {
    // Create a new book and a reference to the head of the list
    struct book *new_book = create_node();
    struct book *book_ptr = *head;

    // If the list is empty or the book comes before the head of the list, add the book and return
    if (book_ptr == NULL || strcmp(new_book->name, book_ptr->name) < 0) {
        new_book->next = *head;
        *head = new_book;
        return;
    }

    // While there are still nodes in the list and the name of the book is still in the correct alphabetical order
    while (book_ptr->next != NULL && strcmp(new_book->name, book_ptr->name) > 0) {
        book_ptr = book_ptr->next;
    }

    // Once we find the correct location we need to insert the node
    // Check if we are at the end of the list
    if (book_ptr->next == NULL) {
        book_ptr->next = new_book;
    } else {
        // Otherwise insert into the correct location
        struct book *tmp = book_ptr->next;
        book_ptr->next = new_book;
        new_book->next = tmp;
    }
}

// Free all the nodes in the list
void clear_list(struct book **head) {
    // A pointer to the head and previous node
    struct book *book_ptr = *head;
    struct book *prev_book = NULL;

    // Iterate through the list and clear each node
    while (book_ptr != NULL) {
        prev_book = book_ptr;
        book_ptr = book_ptr->next;
        destroy_node(prev_book);
    }
}

// Print the contents of all the books in the list
void print_list(struct book **head) {
    // A pointer to the head of the list
    struct book *book_ptr = *head;

    // Loop through the linked list
    while (book_ptr != NULL) {
        print_node(book_ptr);
        book_ptr = book_ptr->next;
    }
}

// Find the book that has the value matching the value parameter, if none exists, don't delete anything
void delete(struct book **head, char *value) {
    struct book *book_ptr = *head;
    struct book *prev_book = NULL;

    // Check if the first book contains the value to be deleted
    if (book_ptr != NULL && strcmp(book_ptr->name, value) == 0) {
        *head = book_ptr->next;
        free(book_ptr);
        return;
    }

    // Check the rest of the list if the first book was not the one to be deleted
    while (book_ptr != NULL && strcmp(book_ptr->name, value) != 0) {
        prev_book = book_ptr;
        book_ptr = book_ptr->next;
    }

    // The book requested to be deleted was not present in the list
    if (book_ptr == NULL) {
        return;
    }

    // Otherwise, remove the specified book from the list
    prev_book->next = book_ptr->next;
    free(book_ptr);
}

// Calculate the size of the linked list
int get_list_length(struct book **head) {
    struct book *book_ptr = *head;
    
    int size = 0;
    
    // Count the number of books in the list while iterating through
    while (book_ptr != NULL) {
        book_ptr = book_ptr->next;
        size++;
    }

    return size;
}

// Return the height of the book stored in the list
int get_book_height(struct book *book_ptr) {
    return strlen(book_ptr->name) + 2; // We add two for while space on the top and bottom of the title
}

#endif