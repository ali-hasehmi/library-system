#ifndef AVLTREE_H
#define AVLTREE_H

#include "LinkedList.h"
#include<bits/stdc++.h>

namespace AVL {
    template<typename T>
    class AvlTree;

    template<typename T>
    class Node {
        T data;
        Node *leftChild;
        Node *rightChild;
        int height;
    public:
        Node(const T &argData);

        Node(const T &argData, Node *argLeftChild, Node *argRightChild, int argHeight);

        friend AvlTree<T>;
    };


    template<typename U>
    class AvlTree {
        Node<U> *root;
    public:
        AvlTree(const LinkedList<U>& argLinkedList);

        Node<U> *rightRotate(Node<U> *y);

        Node<U> *leftRotate(Node<U> *x);

        int getBalance(Node<U> *argNode);

        //returns the new root
        Node<U> *insert(Node<U> *argRoot, U argData);

        void sortedPrint(Node<U> *argRoot);

        bool recursiveBstSearch(Node<U> *argRoot, const U &target);

        void search(const U &target);

        //overload == and >< and cout
    };



}


#include "AvlTree.cpp"

#endif //DS_AVLTREE_H
