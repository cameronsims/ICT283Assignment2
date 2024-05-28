#ifndef BINARYTREE_H
#define BINARYTREE_H

#include "BinaryNode.h"
#include "BinaryTreeExceptions.h"

/// This is the type that a function pointer is
template<class T>
using binaryTreeFunc_t = void(*)(const T&);

/// This is the type that a const function pointer is
template<class T>
using binaryTreeFuncConst_t = void(*)(const T&);

    /**
     * @author Cameron Sims
     * @date 05/05/2024
     *
     * @class BinaryTree
     * @brief A tree class, inheirts from node as well as contains them
     */
template<class T>
class BinaryTree {
  public:
        /**
         * @brief Constructs the class, making all pointers nullptrs
         */
    BinaryTree();

        /**
         * @brief Copys the entire tree
         * @param p_tree The tree we're copying
         */
    BinaryTree(const BinaryTree<T>& p_tree);

        /**
         * @brief Assigns two BinaryNodes to one another, done to deep copy
         * @param p_tree The tree we are copying
         */
	BinaryTree<T>& operator= (const BinaryTree<T>& p_tree);

        /**
         * @brief Destructs the class, freeing all undeleted memory
         */
    virtual ~BinaryTree();


        /**
         * @brief Traverse the tree in order by value
         * @param p_func The function we want to call to make a thing happen with an element (arguments must be of Bst<T>& type)
         */
    void preOrder(binaryTreeFuncConst_t<T> p_func) const;

        /**
         * @brief Traverse the tree in reverse order by value
         */
    void postOrder(binaryTreeFuncConst_t<T> p_func) const;

        /**
         * @brief Traverse the tree in terms of space
         */
    void inOrder(binaryTreeFuncConst_t<T> p_func) const;

  protected:

    /// The root node
    BinaryNode<T>* m_root = nullptr;

  private:
        /**
         * @brief Traverse the tree in order by value
         * @param p_func The function we want to call to make a thing happen with an element (arguments must be of Bst<T>& type)
         * @param p_node The node we're up to
         */
    void preOrder(binaryTreeFuncConst_t<T> p_func, const BinaryNode<T>& p_node) const;

        /**
         * @brief Traverse the tree in reverse order by value
         * @param p_node The node we're up to
         */
    void postOrder(binaryTreeFuncConst_t<T> p_func, const BinaryNode<T>& p_node) const;

        /**
         * @brief Traverse the tree in terms of space
         * @param p_node The node we're up to
         */
    void inOrder(binaryTreeFuncConst_t<T> p_func, const BinaryNode<T>& p_node) const;
};



template<class T>
BinaryTree<T>::BinaryTree() {
    this->m_root = nullptr;
}

template<class T>
BinaryTree<T>::BinaryTree(const BinaryTree<T>& p_tree) {
    // Copy all nodes //
    if (p_tree.m_root == nullptr) {
        this->m_root = nullptr;
        return;
    }

    // Copy all nodes //
    BinaryNode<T> temp = BinaryNode<T>(*p_tree.m_root);

    // Delete
    delete this->m_root;

    // Save to this
    this->m_root = new BinaryNode<T>(temp);
}

template<class T>
BinaryTree<T>& BinaryTree<T>::operator= (const BinaryTree<T>& p_tree) {
    // Copy all nodes //
    if (p_tree.m_root == nullptr) {
        this->m_root = nullptr;
        return *this;
    }

    BinaryNode<T> temp = BinaryNode<T>(*p_tree.m_root);

    // Delete
    delete this->m_root;

    // Save to this
    this->m_root = new BinaryNode<T>(temp);

    // Return
    return *this;
}


template<class T>
BinaryTree<T>::~BinaryTree() {
    if (this->m_root == nullptr) {
        delete this->m_root;
		this->m_root = nullptr;
	}
}

// Consts

template<class T>
void BinaryTree<T>::preOrder(binaryTreeFuncConst_t<T> p_func) const {
    if (this->m_root != nullptr)
        this->preOrder(p_func, *this->m_root);
}

template<class T>
void BinaryTree<T>::postOrder(binaryTreeFuncConst_t<T> p_func) const {
    if (this->m_root != nullptr)
        this->postOrder(p_func, *this->m_root);
}

template<class T>
void BinaryTree<T>::inOrder(binaryTreeFuncConst_t<T> p_func) const {
    if (this->m_root != nullptr)
        this->inOrder(p_func, *this->m_root);
}

template<class T>
void BinaryTree<T>::preOrder(binaryTreeFuncConst_t<T> p_func, const BinaryNode<T>& p_node) const {
    // Do the center
    p_func(p_node.data);

    // Check the left...
    if (p_node.left != nullptr) {
        inOrder(p_func, *(p_node.left));
    }

    // Do the right
    if (p_node.right != nullptr) {
        inOrder(p_func, *(p_node.right));
    }
}

template<class T>
void BinaryTree<T>::postOrder(binaryTreeFuncConst_t<T> p_func, const BinaryNode<T>& p_node) const {
    // Check the left...
    if (p_node.left != nullptr) {
        inOrder(p_func, *(p_node.left));
    }

    // Do the right
    if (p_node.right != nullptr) {
        inOrder(p_func, *(p_node.right));
    }

    // Do the center
    p_func(p_node.data);
}

template<class T>
void BinaryTree<T>::inOrder(binaryTreeFuncConst_t<T> p_func, const BinaryNode<T>& p_node) const {
    // Check the left...
    if (p_node.left != nullptr) {
        inOrder(p_func, *(p_node.left));
    }

    // Do the center
    p_func(p_node.data);

    // Do the right
    if (p_node.right != nullptr) {
        inOrder(p_func, *(p_node.right));
    }
}

#endif
