#include "BST.h"

int main(int argc, char** argv) {
    BST<int> bst;

    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);

    bst.printTree();

    int* min = bst.getMin();
    int* max = bst.getMax();

    cout << endl << "Min: " << *min << endl;
    cout << "Max: " << *max << endl;

    bool found70 = bst.contains(70);
    bool found90 = bst.contains(90);

    cout << "Found 70? " << found70 << endl;
    cout << "Found 90? " << found90 << endl;

    bool deleted = bst.deleteNode(20);
    cout << "Deleted 20? " << deleted << endl;
    bst.printTree();

    deleted = bst.deleteNode(30);
    cout << "Deleted 30? " << deleted << endl;
    bst.printTree();

    deleted = bst.deleteNode(50);
    cout << "Deleted 50? " << deleted << endl;
    bst.printTree();

    return 0;

}