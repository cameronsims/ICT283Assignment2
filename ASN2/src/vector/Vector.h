// Vector Header

// IF WE HAVE INCLUDED THE STANDARD VECTOR
// DO NOT IMPLEMENT THE FILE

#ifndef STL_VECTOR_H

#ifndef VECTOR_H
#define VECTOR_H

#include "VectorExceptions.h"
#include <stdlib.h> // size_t

    /**
     * @author Cameron Sims
     * @date 08/04/2024
     * @brief Dynamic Array class
     *
     * @class Vector
     * @tparam T classwe are using for the vector
     *
     */
template<class T>
class Vector {
  public:
       /**
        * @author Cameron Sims
        * @date 25/03/2024
        * @brief To construct the vector class with no arguments
        */
    Vector();

	   /**
        * @author Cameron Sims
        * @date 09/04/2024
        * @brief To construct the vector class with a size argument
        * @throw Throws unsigned int if invalid size (under 1)
		*
		* @param p_size The size we want the vector to be
 		*
        */
    explicit Vector(long long p_size);

       /**
        * @author Cameron Sims
        * @date 25/03/2024
        * @brief Create a copy of the vector
        */
    Vector(const Vector<T>& p_vector);

		/**
		* @author Cameron Sims
		* @date 25/03/2024
		* @brief To be called when the class terminates
		*/
    ~Vector();

		/**
		* @author Cameron Sims
		* @date 25/03/2024
		* @brief To get the size of the vector
		*/
    size_t size() const;

		/**
		* @author Cameron Sims
		* @date 25/03/2024
		* @brief Adds new value at the end of the vector
		*
		* @param The value we are adding to the end of the array
		*/
    void push(const T& p_value);

	//	/**
	//	* @author Cameron Sims
	//	* @date 25/03/2024
	//	* @brief Deletes end value
	//	*/
    //void pop();

		/**
		* @author Cameron Sims
		* @date 25/03/2024
		* @brief To check a certain value, returns at index
		* @throw Throws access violation if inproper index
		*/
	T& operator[](size_t p_index);

		/**
		* @author Cameron Sims
		* @date 25/03/2024
		* @brief To check a certain value, returns at index
		* @throw Throws access violation if inproper index
		*/
	const T& operator[](size_t p_index) const;

		/**
		* @author Cameron Sims
		* @date 25/03/2024
		* @brief Set to another Vector
		*/
	Vector<T>& operator= (const Vector<T>& p_vector);
  private:
		/**
		* @author Cameron Sims
		* @date 25/03/2024
		* @brief To change the size of the array
		*
		* @param p_size The size we are changing it to
		*/
	void resize(size_t p_size);

		/**
		* @author Cameron Sims
		* @date 25/03/2024
		* @brief Copy from an array into the vector
		*
		* @param p_array The array we are copying into
		* @param p_size The size we are changing it to
		*/
	void copy(T* p_array, size_t p_size);

		/**
		* @author Cameron Sims
		* @date 25/03/2024
		* @brief The values that the vector has (in a stack array)
		*/
	T* m_array = nullptr;

		/**
		* @author Cameron Sims
		* @date 25/03/2024
		* @brief The size of the vector (in actuallity)
		*/
	size_t m_allocatedSize = 0;

		/**
		* @author Cameron Sims
		* @date 25/03/2024
		* @brief The size of the vector (to the user)
		*/
	size_t m_size = 0;
};














////////////////////////////////////////////////////////////////////////////////////
//                                     /////////////////////////////////////////////
//                                     /////////////////////////////////////////////
// Vector Implementation (OUR OWN)     /////////////////////////////////////////////
//                                     /////////////////////////////////////////////
//                                     /////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

#define VECTOR_RESIZE_DEFAULT 2*this->size()

template<class T>
Vector<T>::Vector() {
    m_allocatedSize = 1;
    m_size = 0;
    m_array = new T[m_allocatedSize];
}

template<class T>
Vector<T>::Vector(long long p_size) {
    // If invalid size
    if (p_size < 1) {
        throw VectorOutOfRange();
    }
    // Otherwise just make normal values
    m_allocatedSize = p_size;
    m_size = 0;
    m_array = new T[m_allocatedSize];
}

template<class T>
Vector<T>::Vector(const Vector<T>& p_vector) {
    // Copy both sizes
    this->m_allocatedSize = p_vector.m_allocatedSize;
    this->m_size = p_vector.m_size;
    // Copy all the data over
    this->copy(p_vector.m_array, p_vector.m_size);
}

template<class T>
Vector<T>::~Vector() {
    delete[] m_array;
}

template<class T>
size_t Vector<T>::size() const {
    return this->m_size;
}

template<class T>
void Vector<T>::push(const T& p_value) {
    if (this->m_size == this->m_allocatedSize) {
        this->resize(VECTOR_RESIZE_DEFAULT);
    }
    // Set a new value at the end
    T& newValue = this->m_array[this->m_size];
    newValue = p_value;
    // Increase the size
    this->m_size++;
}


template<class T>
T& Vector<T>::operator[](size_t p_index) {
    // Check if the index is lower than 0
    //if (p_index < 0) {
    //    // Throw an exception
    //    throw VectorOutOfRange();
    //}

    // If the index is bigger than the size
    if (this->m_allocatedSize <= p_index) {
        // Resize the vector
        this->resize(VECTOR_RESIZE_DEFAULT);
    }
    // If the index is bigger than the user expected size
    if (this->m_size <= p_index) {
        // Change the value of the size to the p_index value
        this->m_size = p_index + 1;
    }
    // Return the specific part of the array
    return this->m_array[p_index];
}

template<class T>
const T& Vector<T>::operator[](size_t p_index) const {
    // TODO: Check if it is a valid index, if it is THROW AN ERROR
    if (p_index >= this->m_size) {
        // Throw access violation
        throw VectorOutOfRange();
    }

    return this->m_array[p_index];
}

template<class T>
Vector<T>& Vector<T>::operator=(const Vector<T>& p_vector) {
    // Get the size of the vector
    this->resize(p_vector.m_allocatedSize);
    // Deep copy
    for (size_t i = 0; i < this->m_size; i++) {
		this->m_array[i] = p_vector[i];
	}

	// Return self
	return *this;
}

template<class T>
void Vector<T>::resize(size_t p_size) {
    // Create temporary value to store the values in
    T* temp = new T[p_size];
    // Get the smallest size
    const size_t smallerSize = (this->m_allocatedSize < p_size) ? this->m_allocatedSize : p_size;
    // Add values into the array
    for (size_t i = 0; i < smallerSize; i++) {
		// Add into the array
		temp[i] = this->m_array[i];
	}
    // Recreate the array
    this->m_allocatedSize = p_size;
    // If the new size is lower than the user expected size
    if (this->m_size > m_allocatedSize) {
        this->m_size = m_allocatedSize;
    }
	// Redefine the array
	this->copy(temp, p_size);
    // Delete temporary values
    delete[] temp;
}


template<class T>
void Vector<T>::copy(T* p_array, size_t p_size) {
    // Redefine the array
    this->m_array = new T[this->m_allocatedSize];
    // Save values into the old array location
	for (size_t i = 0; i < p_size; i++) {
		// Add into the array
		this->m_array[i] = p_array[i];
	}
}






#endif // VECTOR_H
#endif // STL_VECTOR_H
