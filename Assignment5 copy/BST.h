#ifndef BST_H
#define BST_H
#include <fstream>
#include <iostream>
using namespace std;

template<class T>
class TreeNode {
    public:
        TreeNode();
        TreeNode(T data);
        virtual ~TreeNode();
        TreeNode(const TreeNode& other); // copy constructor
        TreeNode& operator=(const TreeNode& other);
        T getValue();


        //data;
        T key;
        TreeNode<T> *left;
        TreeNode<T> *right;
};

template<class T>
TreeNode<T>::TreeNode(T k) {
    left = NULL;
    right = NULL;
    key = k;
}

template<class T>
TreeNode<T>::TreeNode() {
    left = NULL;
    right = NULL;
}

template<class T>
TreeNode<T>::~TreeNode() {
    left = NULL;
    right = NULL;
}

template<class T>
T TreeNode<T>::getValue() {
    return key;
}

template<class T>
TreeNode<T>::TreeNode(const TreeNode& other) {
    key = other.key;
    if (other.left != NULL) {
        left = new TreeNode<T>(*other.left); // recursively copy left subtree
    } else {
        left = NULL;
    }
    if (other.right != NULL) {
        right = new TreeNode<T>(*other.right); // recursively copy right subtree
    } else {
        right = NULL;
    }
}

template<class T>
TreeNode<T>& TreeNode<T>::operator=(const TreeNode& other) {
    if (this != &other) {
        key = other.key;
        if (other.left != NULL) {
            delete left;
            left = new TreeNode<T>(*other.left); // recursively copy left subtree
        } else {
            left = NULL;
        }
        if (other.right != NULL) {
            delete right;
            right = new TreeNode<T>(*other.right); // recursively copy right subtree
        } else {
            right = NULL;
        }
    }
    return *this;
}

template<class T>
class BST {
    public:
        BST();
        virtual ~BST();
        BST(const BST<T>& other);

        void insert(T value);
        bool contains(T value);
        bool deleteNode(T k);
        bool isEmpty();
        TreeNode<T>* get(T value);
        void printTreeToFile(const string& filename);
        void studentPrintToFile(TreeNode<T> *node, ofstream& outFile);
 

        T* getMin();
        T* getMax();
        
        TreeNode<T>* getSuccessor(TreeNode<T>* d); // d represents the node we are going to delete
        void replace(T oldValue, T newValue);
        void printTree();
        void recPrint(TreeNode<T> *node);
        void studentPrint(TreeNode<T> *node);
        void studentPrinter();
        TreeNode<T> *getRoot();
        TreeNode<T>* searchByID(int studentID);

        BST<T>& operator=(const BST<T>& other) {
        if (this != &other) {
            TreeNode<T>* new_root = NULL;
            if (other.root != NULL) {
                new_root = new TreeNode<T>(*(other.root));
            }
            delete root;
            root = new_root;
        }
        return *this;
        }

    private:
        TreeNode<T> *root;
};

template<class T>
BST<T>::BST() {
    root = NULL;
}

template<class T>
BST<T>::~BST() {
    //research it
}

template<class T>
BST<T>::BST(const BST<T>& other) {
    if (other.root == NULL) {
        root = NULL;
    } else {
        root = new TreeNode<T>(*(other.root));
    }
}


template<class T>
TreeNode<T>* BST<T>::getRoot() {
    return root;
}

template<class T>
TreeNode<T>* BST<T>::get(T value) {
    if (isEmpty()) {
        return NULL;
    }

    TreeNode<T> *current = root;
    while (current != NULL) {
        if (current->key == value) {
            return current;
        } else if (value < current->key) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    return NULL; // key not found
}

template<class T>
void BST<T>::recPrint(TreeNode<T> *node) {
    if(node == NULL) {
        return;
    }
    recPrint(node->left);
    cout << node->key << " ";
    recPrint(node->right);
}

template<class T>
void BST<T>::printTree() {
    recPrint(root); //Prints entire tree - root down.
}

template<class T>
bool BST<T>::isEmpty() {
    return (root == NULL);
}

template<class T>
T* BST<T>::getMin() {
    if(isEmpty()) {
        return NULL;
    }
    TreeNode<T> *current = root;
    while(current->left != NULL) {
        current = current->left;
    }
    return &(current->key);
}

template<class T>
T* BST<T>::getMax() {
    if(isEmpty()) {
        return NULL;
    }
    TreeNode<T> *current = root;
    while(current->right != NULL) {
        current = current->right;
    }
    return &(current->key);
}

template<class T>
void BST<T>::insert(T value) {
    TreeNode<T> *node = new TreeNode<T>(value);

    if(isEmpty()) {
        root = node;
    } else {
        TreeNode<T> *current = root;
        TreeNode<T> *parent = NULL;
        while(true) {
            parent = current;
            if(value < current->key) {
                current = current->left;
                if(current == NULL) {
                    parent->left = node;
                    break;
                }
            } else {
                current = current->right;
                if(current == NULL) {
                    parent->right = node;
                    break;
                }
            }
        }
    }
}

template<class T>
TreeNode<T>* BST<T>::searchByID(int studentID) {
    if (isEmpty()) {
        return NULL;
    }
    TreeNode<T> *current = root;
    while (current != NULL) {
        if (current->getValue().getID() == studentID) {
            return current;
        } else if (studentID < current->getValue().getID()) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    return NULL;
}

template <class T>
bool BST<T>::contains(T value) {

    if(isEmpty()) {
        return false;
    }

    TreeNode<T> *current = root;
    while(current != nullptr) {
        if(current->key == value) {
            return true;
        } else if(value < current->key) {
            if(current->left == nullptr) {
                return false;
            }
            current = current->left;
        } else {
            if(current->right == nullptr) {
                return false;
            }
            current = current->right;
        }
    }

    return false; // This line will only be reached if the tree is empty
}

template<class T>
void BST<T>::replace(T oldValue, T newValue) {
    TreeNode<T>* node = get(oldValue);
    if (node != NULL) {
        node->key = newValue;
    }
}

template<class T>
bool BST<T>::deleteNode(T k) {
    if (isEmpty()) {
        return false;
    }

    TreeNode<T> *current = root;
    TreeNode<T> *parent = root;
    bool isLeft = true;

    while (current->key != k) {
        parent = current;
        if (k < current->key) {
            current = current->left;
            isLeft = true;
        } else {
            current = current->right;
            isLeft = false;
        }
        if (current == NULL) {
            return false;
        }
    }

    if (current->left == NULL && current->right == NULL) {
        if (current == root) {
            root = NULL;
        } else if (isLeft) {
            parent->left = NULL;
        } else {
            parent->right = NULL;
        }
    } else if (current->right == NULL) {
        if (current == root) {
            root = current->left;
        } else if (isLeft) {
            parent->left = current->left;
        } else {
            parent->right = current->left;
        }
    } else if (current->left == NULL) {
        if (current == root) {
            root = current->right;
        } else if (isLeft) {
            parent->left = current->right;
        } else {
            parent->right = current->right;
        }
    } else {
        TreeNode<T> *successor = getSuccessor(current);
        if (current == root) {
            root = successor;
        } else if (isLeft) {
            parent->left = successor;
        } else {
            parent->right = successor;
        }
        successor->left = current->left;
    }
    delete current;
    return true;
}

template<class T>
TreeNode<T>* BST<T>::getSuccessor(TreeNode<T>* d) {
    //d represents the node to be deleted
    TreeNode<T> *sp = d;
    TreeNode<T> *successor = d;
    TreeNode<T> *current = d->right;

    while(current != NULL) {
        sp = successor;
        successor = current;
        current = current->left;
    }

    if(successor != d->right) {
        sp->left = successor->right;
        successor->right = d->right;
    } 

    return successor;
}

template<class T>
void BST<T>::studentPrint(TreeNode<T> *node) {
    if(node == NULL) {
        return;
    }
    studentPrint(node->left);
    node->key.print();
    studentPrint(node->right);
}

template<class T>
void BST<T>::studentPrinter() {
    studentPrint(root); 
}

#endif