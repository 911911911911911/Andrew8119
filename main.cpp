#include <iostream>

// Structure for a linked list node
struct Node {
    int data; // node data
    Node* next; // pointer to the next node

    // Constructor to initialize a node with given data
    Node(int value) : data(value), next(nullptr) {}
};

// Function for recursively inserting a node into a sorted list
Node* insertRecursive(Node* node, int data) {
    if (node == nullptr) {
        return new Node(data);
    }

    if (data < node->data) {
        Node* newNode = new Node(data);
        newNode->next = node;
        return newNode;
    } else {
        node->next = insertRecursive(node->next, data);
        return node;
    }
}

// Function for recursively deleting a node from the list
Node* deleteRecursive(Node* node, int data) {
    if (node == nullptr) {
        return nullptr;
    }

    if (node->data == data) {
        Node* temp = node->next;
        delete node;
        return temp;
    } else {
        node->next = deleteRecursive(node->next, data);
        return node;
    }
}

// Function for recursively displaying the list
void displayRecursive(Node* node) {
    if (node != nullptr) {
        std::cout << node->data << " ";
        displayRecursive(node->next);
    }
}

// Function to create an ordered list
Node* createOrderedList() {
    Node* orderedList = nullptr;
    int element;
    std::cout << "Enter elements separated by spaces: ";
    while (std::cin >> element) {
        orderedList = insertRecursive(orderedList, element);
    }
    return orderedList;
}

int main() {
    Node* orderedList = nullptr;
    int choice, element;

    while (true) {
        std::cout << "\n1. Create Ordered List"
                  << "\n2. Insert Element"
                  << "\n3. Delete Element"
                  << "\n4. Display List"
                  << "\n5. Exit"
                  << "\nEnter your choice: ";

        std::cin >> choice;

        switch (choice) {
            case 1:
                orderedList = createOrderedList();
                break;
            case 2:
                std::cout << "Enter element to insert: ";
                std::cin >> element;
                orderedList = insertRecursive(orderedList, element);
                break;
            case 3:
                std::cout << "Enter element to delete: ";
                std::cin >> element;
                orderedList = deleteRecursive(orderedList, element);
                break;
            case 4:
                std::cout << "Ordered List: ";
                displayRecursive(orderedList);
                std::cout << std::endl;
                break;
            case 5:
                return 0;
            default:
                std::cout << "Invalid choice. Please enter a valid option." << std::endl;
        }
    }

    return 0;
}
