#include "AvlTree.h"

namespace AVL {
    template<typename T>
    Node<T>::Node():leftChild(nullptr),
                    rightChild(nullptr),
                    height(1) {
    }


    template<typename T>
    Node<T>::Node(const T &argData) :
            data(argData),
            leftChild(nullptr),
            rightChild(nullptr),
            height(1) {
    }

    template<typename T>
    Node<T>::Node(const T &argData, Node *argLeftChild, Node *argRightChild, int argHeight) :
            data(argData),
            leftChild(argLeftChild),
            rightChild(argRightChild),
            height(argHeight) {
    }

    template<typename U>
    AvlTree<U>::AvlTree():
            root(nullptr) {
    }

    template<typename U>
    AvlTree<U>::AvlTree(const LinkedList<U> &argLinkedList):
            root(nullptr) {
//            construct tree
        for (auto &i: argLinkedList) {
            root = insert(root, i);
        }
    }


    template<typename U>
    Node<U> *AvlTree<U>::rightRotate(Node<U> *y) {
        Node<U> *x = y->leftChild;
        Node<U> *T2 = x->rightChild;
//        rotations
        x->rightChild = y;
        y->leftChild = T2;

//        update heights
        y->height = max(height(y->leftChild), height(y->rightChild)) + 1;
        x->height = max(height(x->leftChild), height(x->rightChild)) + 1;
//        return new root
        return x;
    }

    template<typename U>
    Node<U> *AvlTree<U>::leftRotate(Node<U> *x) {
        Node<U> *y = x->rightChild;
        Node<U> *T2 = y->leftChild;
//        rotations
        y->leftChild = x;
        x->rightChild = T2;

//        update heights
        x->height = max(height(x->leftChild), height(x->rightChild)) + 1;
        y->height = max(height(y->leftChild), height(y->rightChild)) + 1;
//        return new root
        return y;
    }

    template<typename U>
    int AvlTree<U>::getBalance(Node<U> *argNode) {
        if (argNode == nullptr) {
            return 0;
        }
        return height(argNode->leftChild) - height(argNode->rightChild);
    }

//    returns new root
    template<typename U>
    Node<U> *AvlTree<U>::insert(Node<U> *argNode, U argData) {
        if (argNode == nullptr) {
            return newNode(argData);
        }

        if (argData < argNode->data) {
            argNode->leftChild = insert(argNode->leftChild, argData);
        } else if (argData > argNode->data) {
            argNode->rightChild = insert(argNode->rightChild, argData);
        } else { // equal keys
            return argNode;
        }
//        update height of ansector node
        argNode->height = 1 + max(height(argNode->leftChild), height(argNode->rightChild));

//        get balance
        int balance = getBalance(argNode);

//        4 cases if unbalanced

//        ll
        if (balance > 1 && argData < argNode->leftChild->data) {
            return rightRotate(argNode);
        }
//        rr
        if (balance < -1 && argData > argNode->rightChild->data) {
            return leftRotate(argNode);
        }
//        lr
        if (balance > 1 && argData > argNode->leftChild->data) {
            argNode->leftChild = leftRotate(argNode->leftChild);
            return rightRotate(argNode);
        }
//        rl
        if (balance < -1 && argData < argNode->rightChild->data) {
            argNode->rightChild = rightRotate(argNode->rightChild);
            return leftRotate(argNode);
        }

        return argNode;
    }

    template<typename U>
    void AvlTree<U>::inOrder(Node<U> *argRoot) {
        if (argRoot == nullptr) {
            return;
        }
        inOrder(argRoot->leftChild);
        std::cout << argRoot->data << ' ';
        inOrder(argRoot->rightChild);
    }

//    helper function for search
    template<typename U>
    Node<U> *AvlTree<U>::recursiveBstSearch(Node<U> *argRoot, const U &target) {
//        if (argRoot == nullptr) {
//            return false;
//        } else if (root->data == target) {
//            return true;
//        } else if (argRoot->data > target) {
//            bool val = search(argRoot->leftChild, target);
//            return val;
//        } else {
//            bool val = search(argRoot->rightChild, target);
//            return val;
//        }
        if (argRoot == nullptr) {
            return nullptr;
        }
        if (argRoot->data == target) {
            return argRoot;
        } else if (argRoot->data < target) {
            return recursiveBstSearch(argRoot->rightChild, target);
        } else if (argRoot->data > target) {
            return recursiveBstSearch(argRoot->leftChild, target);
        }

    }

    template<typename U>
    void AvlTree<U>::print() {
        inOrder(root);
    }

// change bool to u*
// make comparator for search
// pointer to function
//    main search
//make pointer to function in class itself
    template<typename U>
    U *AvlTree<U>::search(const U &target) {
        /*if (recursiveBstSearch(root, target) == nullptr) {
//            std::cout << "\nBook is found";
        } else {
//            std::cout << "\nBook is not found";
        }
*/
        return &recursiveBstSearch(root, target)->data;
    }

    template<typename U>
    AvlTree<U>::AvlTree(int dataArray[], int size) {
        root = nullptr;
        for (int i = 0; i < size; ++i) {
//            std::cout << dataArray[i] << std::endl;
            root = insert(root, dataArray[i]);
        }
    }

    template<typename U>
    int AvlTree<U>::max(int a, int b) {
        return (a > b) ? a : b;
    }

    template<typename U>
    int AvlTree<U>::height(Node<U> *argNode) {
        if (argNode == nullptr) {
            return 0;
        } else {
            return argNode->height;
        }

    }

    template<typename U>
    Node<U> *AvlTree<U>::newNode(const U &key) {
        Node<U> *node = new Node<U>;
        node->data = key;
        node->rightChild = nullptr;
        node->leftChild = nullptr;
        node->height = 1;
        return node;
    }


}


