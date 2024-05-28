#ifndef ITERATOR_H
#define ITERATOR_H

    /**
     * @author Cameron Sims
     * @date 17/05/2024
     * @brief Map's iterator
     *
     * @class iterator
     * @tparam The data structure we're iterating over
     *
     */
template<class T>
class Iterator {
  public:
        /**
         * @brief The constructor that will instanciate the iterator
         * @param p_payload The payload that we want this iterator to have
         */
    Iterator(const T& p_payload);

        /**
         * @brief The destructor to be called when class does out of scope.
         */
    ~Iterator();

        /**
         * @brief Used to 'de-reference' the pointer
         * @returns The data refered inside the iterator
         */
    T& operator*();

        /**
         * @brief Used to 'de-reference' the pointer
         * @returns The data refered inside the iterator
         */
    T* operator->();

        /**
         * @brief Used to increment the position of the iterator
         * @returns The next iterator
         */
    Iterator<T>& operator++(int);

  private:

    /// The data the iterator refers to
    T* m_payload;
};

    /**
     * @author Cameron Sims
     * @date 17/05/2024
     * @brief Map's iterator
     *
     * @class IteratorConst
     * @tparam The data structure we're iterating over
     *
     */
template<class T>
class IteratorConst {
  public:
        /**
         * @brief The constructor that will instanciate the iterator
         * @param p_payload The payload that we want this iterator to have
         */
    IteratorConst(const T& p_payload);

        /**
         * @brief The destructor to be called when class does out of scope.
         */
    ~IteratorConst();

        /**
         * @brief Used to 'de-reference' the pointer
         * @returns The data refered inside the iterator
         */
    const T& operator*() const;

        /**
         * @brief Used to 'de-reference' the pointer
         * @returns The data refered inside the iterator
         */
    const T* operator->() const;

  private:

    /// The data the iterator refers to
    const T* const m_payload;
};




















template<class T>
Iterator<T>::Iterator(const T& p_payload) : m_payload(&p_payload) {

}


template<class T>
Iterator<T>::~Iterator() {
    // Set reference to nullptr
    m_payload = nullptr;
}

template<class T>
T& Iterator<T>::operator*() {
    // De-Reference + Return
    return *(m_payload);
}

template<class T>
Iterator<T>& Iterator<T>::operator++(int) {
    // Increase where we're going (assumes linear)
    this->m_payload = this->m_payload + sizeof(T) * 8;

    // Return self
    return *(this);
}






































// Const Iterator


template<class T>
IteratorConst<T>::IteratorConst(const T& p_payload) : m_payload(&p_payload) {

}


template<class T>
IteratorConst<T>::~IteratorConst() {
    // Set reference to nullptr
    m_payload = nullptr;
}

template<class T>
const T& IteratorConst<T>::operator*() const {
    // De-Reference + Return
    return *(m_payload);
}


#endif // ITERATOR_H
