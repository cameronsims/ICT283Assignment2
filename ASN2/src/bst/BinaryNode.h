#ifndef BINARYNODE_H
#define BINARYNODE_H

    /**
     * @author Cameron Sims
     * @date 01/05/2024
     *
     * @class BinaryNode
     * @brief A node that holds at most two pointers to other nodes
     */
template<class T>
struct BinaryNode {
  public:
        /**
         * @brief Constructs the class, making all pointers nullptrs
         */
    BinaryNode();

        /**
         * @brief Constructs the class, making all pointers nullptrs and adding a value for the data
         * @param p_data The data we are manually assigning the class with
         */
    BinaryNode(const BinaryNode<T>& p_node);

        /**
         * @brief Assigns two BinaryNodes to one another, done to deep copy
         * @param p_node The node we are copying
         */
	BinaryNode<T>& operator= (const BinaryNode<T>& p_node);

        /**
         * @brief Destructs the class, freeing all undeleted memory
         */
    ~BinaryNode();


    /**
     * The payload the node refers to, we do not care about
     * unrestricted access to this as it can be any data without
     * without ruining the integrity of the data structure.
     * Therefore, if a user where to get pointers from this class due
     * to pointer schenanigans, that is the fault of the user and not
     * of the data structutre
     */
    T data;

    /// The lower half
    BinaryNode<T>* left;

    /// The upper half
    BinaryNode<T>* right;


};

// The reason we have added functionality into the struct, is because it should not be the
//    tree's responsibility to handle when the node goes out of scope. The destructor ENSURES
//    that safe memory allocation is used.

template<class T>
BinaryNode<T>::BinaryNode() : data(), left(nullptr), right(nullptr) {}

template<class T>
BinaryNode<T>::BinaryNode(const BinaryNode<T>& p_node) : data(p_node.data), left(nullptr), right(nullptr) {
    // Copy left
    if (p_node.left != nullptr) {
		// Recurse
		BinaryNode* temp = new BinaryNode(*this->left);

		// Kill the old value
		delete this->left;

		// Set this pointer to the left after we've recursed
		this->left = temp;
    }

    // Copy right
    if (p_node.right != nullptr) {
		// Recurse
		BinaryNode* temp = new BinaryNode(*this->right);

		// Kill the old value
		delete this->right;

		// Set this pointer to the left after we've recursed
		this->right = temp;
    }
}

template<class T>
BinaryNode<T>& BinaryNode<T>::operator= (const BinaryNode<T>& p_node) {
	// Copys the binary tree over
	BinaryNode cpy = BinaryNode(p_node);

	// Copy into class
	*this = cpy;

	// Return
	return *this;
}

template<class T>
BinaryNode<T>::~BinaryNode() {
    // Need to point to nullptr, as other wise might call an error!
    this->left = nullptr;
    this->right = nullptr;
}


#endif // BINARYNODE_H
