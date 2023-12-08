    
#pragma once

struct ListNode {
    int val;
    ListNode* next;

    ListNode(int value);
};

ListNode* partition(ListNode* head, int x);
void displayList(ListNode* head);
