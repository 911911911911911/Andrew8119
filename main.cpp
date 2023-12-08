#include <iostream>
using namespace std;

struct Book {
    string title;
    string author;
    int year;
    Book* left;
    Book* right;

    // Конструктор для зручного створення об'єкта книги
    Book(string t, string a, int y) : title(t), author(a), year(y), left(nullptr), right(nullptr) {}
};

// Функція для додавання нової книги до дерева
Book* Insert(Book* root, string title, string author, int year) {
    if (root == nullptr) {
        return new Book(title, author, year);
    }

    if (year < root->year) {
        root->left = Insert(root->left, title, author, year);
    } else if (year > root->year) {
        root->right = Insert(root->right, title, author, year);
    }

    return root;
}

// Функція для пошуку книги за роком видання
Book* Search(Book* root, int year) {
    if (root == nullptr || root->year == year) {
        return root;
    }

    if (year < root->year) {
        return Search(root->left, year);
    }

    return Search(root->right, year);
}

// Функція для знаходження найменшої книги у дереві
Book* minValueNode(Book* node) {
    Book* current = node;
    while (current->left != nullptr) {
        current = current->left;
    }
    return current;
}

// Функція для видалення книги за роком видання
Book* Delete(Book* root, int key) {
    if (root == nullptr) {
        return root;
    }

    if (key < root->year) {
        root->left = Delete(root->left, key);
    } else if (key > root->year) {
        root->right = Delete(root->right, key);
    } else {
        if (root->left == nullptr) {
            Book* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            Book* temp = root->left;
            delete root;
            return temp;
        }

        Book* temp = minValueNode(root->right);
        root->title = temp->title;
        root->author = temp->author;
        root->year = temp->year;
        root->right = Delete(root->right, temp->year);
    }

    return root;
}

// Функція для виведення книг у впорядкованому порядку
void InOrderTraversal(Book* root) {
    if (root != nullptr) {
        InOrderTraversal(root->left);
        cout << "Title: " << root->title << endl;
        cout << "Author: " << root->author << endl;
        cout << "Year: " << root->year << endl;
        cout << endl;
        InOrderTraversal(root->right);
    }
}

int main() {
    Book* root = nullptr;

    int numBooks;
    cout << "Enter the initial number of books in your library: ";
    while (true) {
        cin >> numBooks;
        if (numBooks > 0) {
            break;
        }
        cout << "Try again.\n";
    }

    string title, author;
    int year;

    // Додавання початкових книг у бібліотеку
    for (int i = 0; i < numBooks; i++) {
        cout << "Enter title: ";
        cin >> title;
        cout << "Enter author: ";
        cin >> author;
        cout << "Enter publication year: ";
        cin >> year;
        root = Insert(root, title, author, year);
    }

    int choice, searchYear;
    while (true) {
        // Виведення меню опцій користувача
        cout << "Choose an operation:\n"
             << "1 - to insert a new book into the library\n"
             << "2 - to delete a book from the library\n"
             << "3 - to find a book by publication year\n"
             << "4 - to print the library\n"
             << "5 - exit: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            // Додавання нової книги
            cout << "Enter title: ";
            cin >> title;
            cout << "Enter author: ";
            cin >> author;
            cout << "Enter publication year: ";
            cin >> year;
            root = Insert(root, title, author, year);
            break;
        }
        case 2: {
            // Видалення книги
            cout << "Enter publication year to delete: ";
            cin >> year;
            root = Delete(root, year);
            break;
        }
        case 3: {
            // Пошук книги за роком видання
            cout << "Enter publication year to search: ";
            cin >> searchYear;
            Book* foundBook = Search(root, searchYear);
            if (foundBook != nullptr) {
                cout << "Book found:\n";
                cout << "Title: " << foundBook->title << endl;
                cout << "Author: " << foundBook->author << endl;
                cout << "Year: " << foundBook->year << endl;
            } else {
                cout << "Book not found.\n";
            }
            break;
        }
        case 4:
            // Виведення всіх книг у бібліотеці
            cout << "Library:\n";
            InOrderTraversal(root);
            break;
        case 5:
            // Вихід з програми
            return 0;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
