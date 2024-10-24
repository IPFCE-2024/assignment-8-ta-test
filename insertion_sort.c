#include <stdio.h>

#include "insertion_sort.h"
#include "node.h"


// // This function performs insertion sort on a linked list.
node *isort(node *list) {
    node *sorted_list = NULL;
    node *current = list;
    while (current != NULL) {
        node *next = current->next;
        if (!sorted_list || current->data <= sorted_list->data) {
            current->next = sorted_list;
            sorted_list = current;
        } else {
            node *temp = sorted_list;
            while (temp->next && temp->next->data < current->data) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }
        current = next;
    }
    return sorted_list;
}