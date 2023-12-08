#include <iostream>
using namespace std;

// Структура для представления узла дерева
struct Node {
    int data;
    Node* left;
    Node* right;
    int height;
};

// Функция для вычисления максимума из двух чисел
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Функция для получения высоты узла в дереве
int height(Node* node) {
    if (node == nullptr) {
        return 0;
    }
    return node->height;
}

// Функция для получения баланса узла в дереве
int getBalance(Node* node) {
    if (node == nullptr) {
        return 0;
    }
    return height(node->left) - height(node->right);
}

// Функция для правого поворота поддерева с корнем y
Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = 1 + max(height(y->left), height(y->right));
    x->height = 1 + max(height(x->left), height(x->right));

    return x;
}

// Функция для левого поворота поддерева с корнем x
Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = 1 + max(height(x->left), height(x->right));
    y->height = 1 + max(height(y->left), height(y->right));

    return y;
}

// Функция для вставки нового узла с ключом data в AVL дерево с корнем node
Node* insert(Node* node, int data) {
    // Если дерево пусто, создаем новый узел
    if (node == nullptr) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->left = nullptr;
        newNode->right = nullptr;
        newNode->height = 1;
        return newNode;
    }

    // Рекурсивно вставляем ключ в поддерево
    if (data < node->data) {
        node->left = insert(node->left, data);
    } else if (data > node->data) {
        node->right = insert(node->right, data);
    } else {
        // Если ключ уже присутствует, ничего не делаем
        return node;
    }

    // Обновляем высоту текущего узла
    node->height = 1 + max(height(node->left), height(node->right));

    // Получаем баланс узла
    int balance = getBalance(node);

    // Если дерево несбалансировано, применяем соответствующие повороты

    // Левый поворот
    if (balance > 1 && data < node->left->data) {
        return rightRotate(node);
    }

    // Правый поворот
    if (balance < -1 && data > node->right->data) {
        return leftRotate(node);
    }

    // Левый-правый поворот
    if (balance > 1 && data > node->left->data) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Правый-левый поворот
    if (balance < -1 && data < node->right->data) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    // Возвращаем неизмененный узел, если дерево сбалансировано
    return node;
}

// Функция для обхода дерева в префиксном порядке и вывода узлов
void preOrder(Node* root) {
    if (root != nullptr) {
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

// Главная функция
int main() {
    Node* root = nullptr;
    int data[] = {12, 8, 7, 9, 14, 11, 10, 50, 70, 90, 25, 20, 30, 80, 25, 48, 77, 16, 10, 20, 62};
    int n = sizeof(data) / sizeof(data[0]);

    // Вставляем каждый элемент массива в AVL дерево
    for (int i = 0; i < n; i++) {
        root = insert(root, data[i]);
    }

    // Выводим узлы дерева в префиксном порядке
    cout << "Preorder traversal of the constructed AVL tree is \n";
    preOrder(root);

    return 0;
}


/* #include <iostream>
 #include <stack>
 #include <cctype>
 using namespace std;

 struct TreeNode {
     char data;
     TreeNode* left;
     TreeNode* right;
 };

 bool isOperator(char c) {
     return (c == '+' || c == '-' || c == '*' || c == '/');
 }

 TreeNode* createExpressionTree(string prefix) {
     stack<TreeNode*> st;
     int length = prefix.length();

     for (int i = length - 1; i >= 0; i--) {
         if (isalnum(prefix[i])) {
             TreeNode* newNode = new TreeNode;
             newNode->data = prefix[i];
             newNode->left = nullptr;
             newNode->right = nullptr;
             st.push(newNode);
         } else if (isOperator(prefix[i])) {
             TreeNode* newNode = new TreeNode;
             newNode->data = prefix[i];
             newNode->left = st.top();
             st.pop();
             newNode->right = st.top();
             st.pop();
             st.push(newNode);
         }
     }

     return st.top();
 }

 void inOrder(TreeNode* root) {
     if (root != nullptr) {
         inOrder(root->left);
         cout << root->data << " ";
         inOrder(root->right);
     }
 }

 int main() {
     string prefixExpression = "*+AB-CD";
     TreeNode* root = createExpressionTree(prefixExpression);

     cout << "Inorder traversal of the constructed expression tree is \n";
     inOrder(root);

     return 0;
 }
*/
