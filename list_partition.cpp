#include "list_partition.hpp"
#include <iostream>

ListNode::ListNode(int value) : val(value), next(nullptr) {}

ListNode* partition(ListNode* head, int x) {
    ListNode* before = new ListNode(0);
    ListNode* after = new ListNode(0);
    ListNode* beforeCurrent = before;
    ListNode* afterCurrent = after;

    while (head != nullptr) {
        if (head->val < x) {
            beforeCurrent->next = head;
            beforeCurrent = beforeCurrent->next;
        } else {
            afterCurrent->next = head;
            afterCurrent = afterCurrent->next;
        }
        head = head->next;
    }

    beforeCurrent->next = nullptr;
    afterCurrent->next = nullptr;
    beforeCurrent->next = after->next;

    return before->next;
}

void displayList(ListNode* head) {
    while (head != nullptr) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}
