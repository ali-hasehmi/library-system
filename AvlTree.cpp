#include "AvlTree.h"

namespace AVL
{
    template <typename T>
    Node<T>::Node() : leftChild(nullptr),
                      rightChild(nullptr),
                      height(1)
    {
    }

    template <typename T>
    Node<T>::Node(const T &argData) : data(argData),
                                      leftChild(nullptr),
                                      rightChild(nullptr),
                                      height(1)
    {
    }

    template <typename T>
    Node<T>::Node(const T &argData, Node *argLeftChild, Node *argRightChild, int argHeight) : data(argData),
                                                                                              leftChild(argLeftChild),
                                                                                              rightChild(argRightChild),
                                                                                              height(argHeight)
    {
    }

    template <typename U>
    AvlTree<U>::AvlTree() : root(nullptr)
    {
    }

    template <typename U>
    AvlTree<U>::AvlTree(const LinkedList<U> &argLinkedList) : root(nullptr)
    {
        //            construct tree
        std::cout << "AvlTree<U>::AvlTree(const LinkedList<U> &argLinkedList): started\n";
        std::cout << "List Size: " << argLinkedList.size() <<std::endl;
        for (auto &i : argLinkedList)
        {
            std::cout << "inLOOP1\n";
            root = insert(root, i);
            std::cout << "inLoop2\n";
        }
        std::cout << "AvlTree<U>::AvlTree(const LinkedList<U> &argLinkedList): ended\n";
    }

    template <typename U>
    Node<U> *AvlTree<U>::rightRotate(Node<U> *y)
    {
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

    template <typename U>
    Node<U> *AvlTree<U>::leftRotate(Node<U> *x)
    {
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

    template <typename U>
    int AvlTree<U>::getBalance(Node<U> *argNode)
    {
        if (argNode == nullptr)
        {
            return 0;
        }
        return height(argNode->leftChild) - height(argNode->rightChild);
    }

    //    returns new root
    template <typename U>
    Node<U> *AvlTree<U>::insert(Node<U> *argNode, U argData)
    {

        std::cout << "Node<U> *AvlTree<U>::insert(Node<U>* , U ) : started\n";

        if (argNode == nullptr)
        {
            std::cout << "Node<U> *AvlTree<U>::insert(Node<U>* , U ) : nullptr\n";

            return newNode(argData);
        }

        if (argData < argNode->data)
        {
            std::cout << "Node<U> *AvlTree<U>::insert(Node<U>* , U ) : smaller\n";

            argNode->leftChild = insert(argNode->leftChild, argData);
        }
        else if (argData > argNode->data)
        {
            std::cout << "Node<U> *AvlTree<U>::insert(Node<U>* , U ) : bigger\n";

            argNode->rightChild = insert(argNode->rightChild, argData);
        }
        else
        { // equal keys
            std::cout << "Node<U> *AvlTree<U>::insert(Node<U>* , U ) : equal\n";

            return argNode;
        }

        std::cout << "Node<U> *AvlTree<U>::insert(Node<U>* , U ) : updateHeight\n";

        //        update height of ansector node
        if(argNode != nullptr)
        argNode->height = 1 + max(height(argNode->leftChild), height(argNode->rightChild));

        std::cout << "Node<U> *AvlTree<U>::insert(Node<U>* , U ) : getBalance\n";

        //        get balance
        int balance = getBalance(argNode);

        //        4 cases if unbalanced

        std::cout << "Node<U> *AvlTree<U>::insert(Node<U>* , U ) : beforeRotations\n";
        //        ll
        if (balance > 1 && argData < argNode->leftChild->data)
        {
            std::cout << "Node<U> *AvlTree<U>::insert(Node<U>* , U ) : rightRotate\n";
            return rightRotate(argNode);
        }
        //        rr
        if (balance < -1 && argData > argNode->rightChild->data)
        {
            std::cout << "Node<U> *AvlTree<U>::insert(Node<U>* , U ) : leftRotate\n";

            return leftRotate(argNode);
        }
        //        lr
        if (balance > 1 && argData > argNode->leftChild->data)
        {
            std::cout << "Node<U> *AvlTree<U>::insert(Node<U>* , U ) : left -right Rotate\n";

            argNode->leftChild = leftRotate(argNode->leftChild);
            return rightRotate(argNode);
        }
        //        rl
        if (balance < -1 && argData < argNode->rightChild->data)
        {
            std::cout << "Node<U> *AvlTree<U>::insert(Node<U>* , U ) : right -left Rotate\n";
            argNode->rightChild = rightRotate(argNode->rightChild);
            return leftRotate(argNode);
        }

        std::cout << "Node<U> *AvlTree<U>::insert(Node<U>* , U ) : finished\n";

        return argNode;
    }

    template <typename U>
    void AvlTree<U>::inOrder(Node<U> *argRoot)
    {
        if (argRoot == nullptr)
        {
            return;
        }
        inOrder(argRoot->leftChild);
        std::cout << argRoot->data << ' ';
        inOrder(argRoot->rightChild);
    }

    //    helper function for search
    template <typename U>
    Node<U> *AvlTree<U>::recursiveBstSearch(Node<U> *argRoot, const U &target)
    {
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
        if (argRoot == nullptr)
        {
            return nullptr;
        }
        if (argRoot->data == target)
        {
            return argRoot;
        }
        else if (argRoot->data < target)
        {
            return recursiveBstSearch(argRoot->rightChild, target);
        }
        else if (argRoot->data > target)
        {
            return recursiveBstSearch(argRoot->leftChild, target);
        }
    }

    template <typename U>
    void AvlTree<U>::print()
    {
        inOrder(root);
    }

    // change bool to u*
    // make comparator for search
    // pointer to function
    //    main search
    // make pointer to function in class itself
    template <typename U>
    U *AvlTree<U>::search(const U &target)
    {
        /*if (recursiveBstSearch(root, target) == nullptr) {
//            std::cout << "\nBook is found";
        } else {
//            std::cout << "\nBook is not found";
        }
*/
        return &recursiveBstSearch(root, target)->data;
    }

    template <typename U>
    AvlTree<U>::AvlTree(int dataArray[], int size)
    {
        root = nullptr;
        for (int i = 0; i < size; ++i)
        {
            //            std::cout << dataArray[i] << std::endl;
            root = insert(root, dataArray[i]);
        }
    }

    template <typename U>
    int AvlTree<U>::max(int a, int b)
    {
        return (a > b) ? a : b;
    }

    template <typename U>
    int AvlTree<U>::height(Node<U> *argNode)
    {
        if (argNode == nullptr)
        {
            return 0;
        }
        else
        {
            return argNode->height;
        }
    }

    template <typename U>
    Node<U> *AvlTree<U>::newNode(const U &key)
    {
        std::cout << "Node<U> *AvlTree<U>::newNode(const U &key) : started\n";
        Node<U> *node = new Node<U>;
        node->data = key;
        node->rightChild = nullptr;
        node->leftChild = nullptr;
        node->height = 1;
        std::cout << "Node<U> *AvlTree<U>::newNode(const U &key) : finished\n";

        return node;
    }

}
