#pragma once
#include <iostream>

template <typename T>
class AVL_Node
{
private:
    T data;
    int height;
    AVL_Node *left;
    AVL_Node *right;

public:
    AVL_Node(T);
    ~AVL_Node();

    AVL_Node *&get_left();
    AVL_Node *&get_right();
    T get_data();
    int get_height();

    void set_left(AVL_Node *);
    void set_right(AVL_Node *);
    void set_data(T);
    void set_height(int);
};

template <typename T>
AVL_Node<T>::AVL_Node(T data)
{
    this->data = data;
    this->height = 1;
    this->left = nullptr;
    this->right = nullptr;
}
template <typename T>
AVL_Node<T>::~AVL_Node()
{
    delete this->left;
    delete this->right;
    this->left = this->right = nullptr;
}
template <typename T>
AVL_Node<T> *&AVL_Node<T>::get_left()
{
    return this->left;
}
template <typename T>
AVL_Node<T> *&AVL_Node<T>::get_right()
{
    return this->right;
}
template <typename T>
T AVL_Node<T>::get_data()
{
    return this->data;
}
template <typename T>
int AVL_Node<T>::get_height()
{
    return this->height;
}

template <typename T>
void AVL_Node<T>::set_left(AVL_Node *left)
{
    this->left = left;
}
template <typename T>
void AVL_Node<T>::set_right(AVL_Node *right)
{
    this->right = right;
}
template <typename T>
void AVL_Node<T>::set_data(T data)
{
    this->data = data;
}
template <typename T>
void AVL_Node<T>::set_height(int height)
{
    this->height = height;
}

template <typename T>
class AVL_Tree
{
private:
    AVL_Node<T> *root;

public:
    AVL_Tree();
    ~AVL_Tree();

    AVL_Node<T> *&get_root();
    void set_root(AVL_Node<T> *);

    int get_height(AVL_Node<T> *);
    int get_balance_factor(AVL_Node<T> *&);
    int get_max(int a, int b);

    void right_rotate(AVL_Node<T> *&);
    void left_rotate(AVL_Node<T> *&);

    void insert(AVL_Node<T> *&, T);
    bool exists(AVL_Node<T> *&, T);
};

template <typename T>
AVL_Tree<T>::AVL_Tree()
{
    this->root = nullptr;
}
template <typename T>
AVL_Tree<T>::~AVL_Tree()
{
    delete this->root;
    root = nullptr;
}

template <typename T>
AVL_Node<T> *&AVL_Tree<T>::get_root()
{
    return root;
}
template <typename T>
void AVL_Tree<T>::set_root(AVL_Node<T> *root)
{
    this->root = root;
}

template <typename T>
int AVL_Tree<T>::get_height(AVL_Node<T> *node)
{
    if (node == nullptr)
        return 0;
    return node->get_height();
}
template <typename T>
int AVL_Tree<T>::get_balance_factor(AVL_Node<T> *&node)
{
    if (node == nullptr)
        return 0;
    return get_height(node->get_left()) - get_height(node->get_right());
}
template <typename T>
int AVL_Tree<T>::get_max(int a, int b)
{
    return (a > b) ? a : b;
}

template <typename T>
void AVL_Tree<T>::right_rotate(AVL_Node<T> *&current)
{
    AVL_Node<T> *left_of_current = current->get_left();
    AVL_Node<T> *t2 = left_of_current->get_right();

    left_of_current->set_right(current);
    current->set_left(t2);

    current->set_height(get_max(get_height(current->get_left()), get_height(current->get_right())) + 1);
    left_of_current->set_height(get_max(get_height(left_of_current->get_left()), get_height(left_of_current->get_right())) + 1);

    current = left_of_current;
}

template <typename T>
void AVL_Tree<T>::left_rotate(AVL_Node<T> *&current)
{
    AVL_Node<T> *right_of_current = current->get_right();
    AVL_Node<T> *t2 = right_of_current->get_left();

    right_of_current->set_left(current);
    current->set_right(t2);

    current->set_height(get_max(get_height(current->get_left()), get_height(current->get_right())) + 1);
    right_of_current->set_height(get_max(get_height(right_of_current->get_left()), get_height(right_of_current->get_right())) + 1);

    current = right_of_current;
}

template <typename T>
void AVL_Tree<T>::insert(AVL_Node<T> *&node, T data)
{
    if (node == nullptr)
    {
        node = new AVL_Node<T>(data);
        return;
    }
    if (data < node->get_data())
        insert(node->get_left(), data);
    else if (data > node->get_data())
        insert(node->get_right(), data);
    else
        return;

    node->set_height(1 + get_max(get_height(node->get_left()), get_height(node->get_right())));

    int balance_factor = this->get_balance_factor(node);

    // LL
    if (balance_factor > 1 && data < node->get_left()->get_data())
        right_rotate(node);
    // RR
    else if (balance_factor < -1 && data > node->get_right()->get_data())
        left_rotate(node);
    // LR
    else if (balance_factor > 1 && data > node->get_left()->get_data())
    {
        left_rotate(node->get_left());
        right_rotate(node);
    }
    // RL
    else if (balance_factor < -1 && data < node->get_right()->get_data())
    {
        right_rotate(node->get_right());
        left_rotate(node);
    }
}
template <typename T>

bool AVL_Tree<T>::exists(AVL_Node<T> *&node, T data)
{
    if (node == nullptr)
        return false;
    if (data < node->get_data())
        return exists(node->get_left(), data);
    else if (data > node->get_data())
        return exists(node->get_right(), data);
    else if (data == node->get_data())
        return true;
}