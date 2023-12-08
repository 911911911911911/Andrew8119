#include "list_partition.hpp"
#include <iostream>
int main() {
    
    ListNode* head1 = new ListNode(1);
    head1->next = new ListNode(4);
    head1->next->next = new ListNode(3);
    head1->next->next->next = new ListNode(2);
    head1->next->next->next->next = new ListNode(5);
    head1->next->next->next->next->next = new ListNode(2);

    std::cout << "Input 1: ";
    displayList(head1);

    int x1 = 3;
    ListNode* result1 = partition(head1, x1);

    std::cout << "Output 1: ";
    displayList(result1);

    
    ListNode* head2 = new ListNode(2);
    head2->next = new ListNode(1);

    std::cout << "Input 2: ";
    displayList(head2);

    int x2 = 2;
    ListNode* result2 = partition(head2, x2);

    std::cout << "Output 2: ";
    displayList(result2);

    return 0;
}
