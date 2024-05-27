#ifndef BINARYTREEEXCEPTIONS
#define BINARYTREEEXCEPTIONS

    /**
     * @author Cameron Sims
     * @date 17/05/2024
     *
     * @class NodeError
     * @brief The class exists to be thrown if there is some issue with the Node
     */
class NodeError {
  public:
        /**
         * @brief The string representing the error
         * @return A string which details the reason we got thrown
         */
    const char* what() const;
};

    /**
     * @author Cameron Sims
     * @date 17/05/2024
     *
     * @class NodeExists
     * @brief The class exists to be thrown if a node exists when we don't expect it to.
     */
class NodeExists : NodeError {
  public:
        /**
         * @brief The string representing the error
         * @return A string which details the reason we got thrown
         */
    const char* what() const;
};

    /**
     * @author Cameron Sims
     * @date 17/05/2024
     *
     * @class NodeNotFound
     * @brief The class doesn't exist when we want it to
     */
class NodeNotFound : NodeError {
  public:
        /**
         * @brief The string representing the error
         * @return A string which details the reason we got thrown
         */
    const char* what() const;
};

    /**
     * @author Cameron Sims
     * @date 17/05/2024
     *
     * @class NodeCantDelete
     * @brief The node exists to be thrown when we can't delete
     */
class NodeCantDelete : NodeError {
  public:
        /**
         * @brief The string representing the error
         * @return A string which details the reason we got thrown
         */
    const char* what() const;
};

#endif // BINARYTREEEXCEPTIONS
