#include <stdio.h>

#include "insertion_sort.h"
#include "node.h"

// This function inserts a new node into a sorted linked list.
node *sorted_insert(node *sorted_list, node *new_node) {
    // If the sorted list is empty or if the new node's data is smaller or equal to the head of the sorted list,
    // insert the new node at the beginning.
    if (!sorted_list || new_node->data <= sorted_list->data) {
        new_node->next = sorted_list;
        return new_node;
    }

    // Traverse the sorted list to find the correct position to insert the new node.
    node *current = sorted_list;
    while (current->next && current->next->data < new_node->data) {
        current = current->next;
    }

    // Insert the new node after the current node.
    new_node->next = current->next;
    current->next = new_node;

    return sorted_list;
}

// This function performs insertion sort on a linked list.
node *isort(node *head) {
    // Start with an empty list as the sorted list.
    node *sorted_list = NULL;

    // Traverse the original list.
    node *current = head;
    while (current != NULL) {
        // Save the next node because we will modify current->next in sorted_insert.
        node *next = current->next;

        // Insert the current node into the sorted list.
        sorted_list = sorted_insert(sorted_list, current);

        // Move to the next node in the original list.
        current = next;
    }

    // Return the head of the sorted list.
    return sorted_list;
}
