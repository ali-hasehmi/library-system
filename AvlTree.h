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
        Node();

        Node(const T &argData);

        Node(const T &argData, Node *argLeftChild, Node *argRightChild, int argHeight);

        friend AvlTree<T>;
    };


    template<typename U>
    class AvlTree {
        Node<U> *root;
    public:
        AvlTree();

        AvlTree(int dataArray[], int size);

        AvlTree(const LinkedList<U> &argLinkedList);

        Node<U> *rightRotate(Node<U> *y);

        Node<U> *leftRotate(Node<U> *x);

        int getBalance(Node<U> *argNode);

        //returns the new root
        Node<U> *insert(Node<U> *argRoot, U argData);

        void inOrder(Node<U> *argRoot);

        void print();

        Node<U> *recursiveBstSearch(Node<U> *argRoot, const U &target);

        void search(const U &target);

        //overload == and >< and cout
        int max(int a, int b);

        int height(Node<U> *argNode);

        Node<U>* newNode(const U& key);

    };


}


#include "AvlTree.cpp"

#endif //DS_AVLTREE_H
