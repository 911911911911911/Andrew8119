#include <stdio.h>
#include <stdlib.h>

struct Student {
    char name[50];
    float grade;
    struct Student* left;
    struct Student* right;
};

struct Student* createNode(const char name[], float grade) {
    struct Student* newNode = (struct Student*)malloc(sizeof(struct Student));
    if (newNode != NULL) {
        snprintf(newNode->name, sizeof(newNode->name), "%s", name);
        newNode->grade = grade;
        newNode->left = newNode->right = NULL;
    }
    return newNode;
}

struct Student* insertNode(struct Student* root, const char name[], float grade) {
    if (root == NULL) {
        return createNode(name, grade);
    }

    if (grade < root->grade) {
        root->right = insertNode(root->right, name, grade); // Fix here
    } else if (grade > root->grade) {
        root->left = insertNode(root->left, name, grade);   // Fix here
    }

    return root;
}

struct Student* findMaxNode(struct Student* node) {  // Renamed from findMinNode
    while (node->right != NULL) {
        node = node->right;
    }
    return node;
}

struct Student* deleteNode(struct Student* root, float grade) {
    if (root == NULL) {
        return root;
    }

    if (grade < root->grade) {
        root->right = deleteNode(root->right, grade);
    } else if (grade > root->grade) {
        root->left = deleteNode(root->left, grade);
    } else {
        if (root->left == NULL) {
            struct Student* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Student* temp = root->left;
            free(root);
            return temp;
        }

        struct Student* temp = findMaxNode(root->left);  // Fix here
        snprintf(root->name, sizeof(root->name), "%s", temp->name);
        root->grade = temp->grade;
        root->left = deleteNode(root->left, temp->grade);  // Fix here
    }

    return root;
}

void reverseInorderTraversal(struct Student* root) {
    if (root != NULL) {
        reverseInorderTraversal(root->right);  // Fix here
        printf("Name: %s, Grade: %.2f\n", root->name, root->grade);
        reverseInorderTraversal(root->left);   // Fix here
    }
}

void freeTree(struct Student* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main() {
    struct Student* root = NULL;

    // Додавання студентів
    root = insertNode(root, "John", 85.5);
    root = insertNode(root, "Alice", 92.3);
    root = insertNode(root, "Bob", 78.9);
    root = insertNode(root, "Eve", 95.2);
    root = insertNode(root, "Charlie", 88.7);

    // Виведення студентів у порядку зменшення оцінок
    printf("Students in descending order of grades:\n");
    reverseInorderTraversal(root);

    // Видалення студента з оцінкою 78.9
    float gradeToDelete = 78.9;
    root = deleteNode(root, gradeToDelete);
    printf("\nStudent with grade %.2f deleted.\n", gradeToDelete);

    // Виведення студентів після видалення
    printf("\nStudents after deletion:\n");
    reverseInorderTraversal(root);

    // Очищення пам'яті
    freeTree(root);

    return 0;
}
