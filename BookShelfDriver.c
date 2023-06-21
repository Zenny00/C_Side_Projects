// Name: Joshua Comfort
// Date: 6/20/2023
// Description: A virtual console bookshelf program that keeps track of a collection of books using a linked-list and an external file

#include "LinkedList.h"

int main(int argc, char **argv) {
    /*
    // Create book from keyboard input
    struct book *book_node = create_node();
    print_node(book_node);
    destroy_node(book_node);

    // Create book given predefined values
    struct book *book_node_1 = create_node_given_data("The Hitchhiker's Guide to the Galaxy", "Douglas Adams", 1981);
    print_node(book_node_1);
    destroy_node(book_node_1);
    */
    struct book *head = NULL;
    insert(&head);
    print_list(&head);
    insert(&head);
    print_list(&head);
    insert(&head);
    print_list(&head);

    // Debug log
    printf("hi\n");
    return 0;
}