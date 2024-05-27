#ifndef BST_H

#ifndef BST_ITERATIVE_H
#define BST_ITERATIVE_H

#include "../BinaryNode.h"
#include "../BinaryTree.h"

template<class T>
class BinarySearchTree : public BinaryTree<T> {
  public:

        /**
         * @brief Finds a node that exists
         * @param p_data The data value we are looking for
         * @returns The BinaryNode that it refers to
         * @throws NodeNotFound if a node isn't found
         */
    const T& searchNode(const T& p_data) const;

        /**
         * @brief Adds a node in an appropriate place
         * @param p_data The data we are adding
         * @throws NodeExists If a node already exists
         */
    void insertNode(const T& p_data);

        /**
         * @brief Deletes a node that exists
         * @param p_data The data we are deleting
         * @throws NodeNotFound if a node isn't found
         */
    void deleteNode(const T& p_data);

  private:
    #ifdef BST_RECURSE_H
        /**
         * @brief Finds a node that exists
         * @param p_node the node we're looking for
         * @returns The BinaryNode that it refers to
         */
    const BinaryNode<T>& searchNode(const BinaryNode<T>& p_node, const T& p_data) const;

        /**
         * @brief Finds a node that exists
         * @param p_node the node we're looking for
         * @returns The BinaryNode that it refers to
         */
    BinaryNode<T>& searchNode(const BinaryNode<T>& p_node, const T& p_data);

        /**
         * @brief Adds a node in an appropriate place
         * @param p_node the node we're looking for
         */
    void insertNode(BinaryNode<T>& p_node, const T& p_data);

        /**
         * @brief Deletes a node that exists
         * @param p_node the node we're looking for
         */
    void deleteNode(BinaryNode<T>& p_node, const T& p_data);

    #endif
};

// Call the following class by two names
template<class T>
using Bst = BinarySearchTree<T>;

////////////////////////////////////////////////////////////////////////////////////////////////////


template<class T>
const T& BinarySearchTree<T>::searchNode(const T& p_data) const {
    // The pointer to the node we're looking for
    BinaryNode<T>* ptr = this->m_root;

    // If the pointer is ever nullptr, cancel
    while (ptr != nullptr) {
        // If we're at the node that we're looking for...
        if (ptr->data == p_data) {
            return ptr->data;
        }

        // If the node is bigger
        if (ptr->data > p_data) {
            ptr = ptr->left;
        }

        // If node is smaller
        else if (ptr->data < p_data) {
            ptr = ptr->right;
        }
    }

    // And then throw an error
    throw NodeNotFound();
}

template<class T>
void BinarySearchTree<T>::insertNode(const T& p_data) {
    // Check if the root needs it
    if (this->m_root == nullptr) {
        // Create it
        this->m_root = new BinaryNode<T>();
        this->m_root->data = p_data;
        return;
    }

    // The pointer to the node we're looking for
    BinaryNode<T>* parent = nullptr;
    BinaryNode<T>* child = this->m_root;

    // While the child is not a nullptr
    while (child != nullptr) {
        // If we found the data we're replacing
        if (child->data == p_data) {
            throw NodeExists();
        }
        // If the value at node is bigger than the wanted value
        else if (child->data > p_data) {
            // Set parent to this child
            parent = child;

            // Set child to the left
            child = parent->left;
        }
        // If the value at node is smaller than the wanted value
        else {
            // Set parent to this child
            parent = child;

            // Set child to the right
            child = parent->right;
        }
    }

    // Create the new node
    if (parent->data > p_data) {
        parent->left = new BinaryNode<T>();
        parent->left->data = p_data;
    }
    if (parent->data < p_data) {
        parent->right = new BinaryNode<T>();
        parent->right->data = p_data;
    }

}

template<class T>
void BinarySearchTree<T>::deleteNode(const T& p_data) {
    // Check if the root needs deletion
    if (this->m_root == nullptr) {
        // Create it
        delete this->m_root;
        return;
    }

    // The pointer to the value we're looking for
    BinaryNode<T>* parent = nullptr;
    BinaryNode<T>* child = this->m_root;


    // While the child is not a nullptr
    while (child != nullptr) {
        // If we found the data we're replacing
        if (child->data == p_data) {
            // We need to find this in-terms of the parent...
            if (child == parent->left) {
                delete parent->left;
                parent->left = nullptr;
                return;
            }
            // If it isn't the left path, it needs to be the right.
            delete parent->right;
            parent->right = nullptr;
            return;
        }
        // If the value at node is bigger than the wanted value
        else if (child->data > p_data) {
            // Set parent to this child
            parent = child;

            // Set child to the left
            child = parent->left;
        }
        // If the value at node is smaller than the wanted value
        else {
            // Set parent to this child
            parent = child;

            // Set child to the right
            child = parent->right;
        }
    }

    // Not found
    throw NodeNotFound();
}


#endif
#endif
