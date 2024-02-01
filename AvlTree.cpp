#include "AvlTree.h"

namespace AVL {
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
        Node<U> *T2 = y->rightChild;
//        rotations
        x->rightChild = y;
        y->leftChild = T2;

//        update heights
        y->height = std::max(y->leftChild->height, y->rightChild->height + 1);
        x->height = std::max(x->leftChild->height, x->rightChild->height + 1);
//        return new root
        return x;
    }

    template<typename U>
    Node<U> *AvlTree<U>::leftRotate(Node<U> *x) {
        Node<U> *y = x->leftChild;
        Node<U> *T2 = y->leftChild;
//        rotations
        y->leftChild = x;
        x->rightChild = T2;

//        update heights
        x->height = std::max(x->leftChild->height, x->rightChild->height + 1);
        y->height = std::max(y->leftChild->height, y->rightChild->height + 1);
//        return new root
        return y;
    }

    template<typename U>
    int AvlTree<U>::getBalance(Node<U> *argNode) {
        if (argNode == nullptr) {
            return 0;
        }
        return argNode->leftChild->height - argNode->rightChild->height;
    }

//    returns new root
    template<typename U>
    Node<U> *AvlTree<U>::insert(Node<U> *argNewNode, U argData) {
        if (argNewNode == nullptr) {
            return Node<U>(argData);
        }
        if (argData < argNewNode->data) {
            argNewNode->leftChild = insert(argNewNode->leftChild, argData);
        } else if (argData > argNewNode->data) {
            argNewNode->rightChild = insert(argNewNode->rightChild, argData);
        } else { // equal keys
            return argNewNode;
        }
//        update height of ansector node
        argNewNode->height = 1 + std::max(argNewNode->leftChild->height, argNewNode->rightChild->height);

//        get balance
        int balance = getBalance(argNewNode);

//        4 cases if unbalanced

//        ll
        if (balance > 1 && argData < argNewNode->leftChild->data) {
            return rightRotate(argNewNode);
        }
//        rr
        if (balance < -1 && argData > argNewNode->rightChild->data) {
            return leftRotate(argNewNode);
        }
//        lr
        if (balance > 1 && argData > argNewNode->leftChild->data) {
            argNewNode->leftChild = leftRotate(argNewNode->leftChild);
            return rightRotate(argNewNode);
        }
//        rl
        if (balance < -1 && argData > argNewNode->rightChild->data) {
            argNewNode->rightChild = rightRotate(argNewNode->rightChild);
            return leftRotate(argNewNode);
        }

        return argNewNode;
    }

    template<typename U>
    void AvlTree<U>::sortedPrint(Node<U> *argRoot) {
        if (argRoot != nullptr) {
            std::cout << argRoot->data << ' ';
            sortedPrint(root->leftChild);
            sortedPrint(root->rightChild);
        }
    }

//    helper function for search
    template<typename U>
    bool AvlTree<U>::recursiveBstSearch(Node<U> *argRoot, const U &target) {
        if (argRoot == nullptr) {
            return false;
        } else if (root->data == target) {
            return true;
        } else if (argRoot->data > target) {
            bool val = search(argRoot->leftChild, target);
            return val;
        } else {
            bool val = search(argRoot->rightChild, target);
            return val;
        }
    }

//    main search
    template<typename U>
    void AvlTree<U>::search(const U &target) {
        if (recursiveBstSearch(root, target)) {
            std::cout << "\nfound";
        } else {
            std::cout << "\nnot found";
        }

    }


}


