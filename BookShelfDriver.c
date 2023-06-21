// Name: Joshua Comfort
// Date: 6/20/2023
// Description: A virtual console bookshelf program that keeps track of a collection of books using a linked-list and an external file

#include "LinkedList.h"

int main(int argc, char **argv) {
    struct book *book_node = create_node();
    print_node(book_node);
    destroy_node(book_node);
    printf("hi\n");
    return 0;
}