#ifndef MAP_H
#define MAP_H

#include <map> // Used for the map
#include "MapExceptions.h"
//#include "../Iterator.h"


// "Error: need 'typename'before std::map<T1,T2>::iterator because 'std::map<T1,T2>' is a depedent scope"
template<class T1, class T2>
using MapIterator = typename std::map<T1, T2>::iterator;

template<class T1, class T2>
using MapIteratorConst = typename std::map<T1, T2>::const_iterator;

    /**
     * @author Cameron Sims
     * @date 08/05/2024
     * @brief Map class
     *
     * @class Map
     * @tparam T1 class we are using for the key
     * @tparam T2 class we are using for the value
     *
     */
template<class T1, class T2>
class Map {
  public:
        /**
         * @brief Constructs the class
         */
    Map();

        /**
         * @brief Gets an element that exists in the map
         * @param p_key The key we're going to return the value for
         * @returns The value of some key
         */
    const T2& operator[](const T1& p_key) const;

        /**
         * @brief Gets an element that exists in the map
         * @param p_key The key we're going to return the value for
         * @returns The value of some key
         */
    T2& operator[](const T1& p_key);

//        /**
//         * @brief Starts at beginning of map, used to iterate it
//         * @returns Iterator the first element
//         */
//   MapIterator<T1, T2> begin();
//
//        /**
//         * @brief Ends after the last element
//         * @returns Iterator for past the last element
//         */
//    MapIterator<T1, T2> end();

        /**
         * @brief Starts at beginning of map, used to iterate it
         * @returns Iterator the first element
         */
    MapIteratorConst<T1, T2> begin() const;

        /**
         * @brief Ends after the last element
         * @returns Iterator for past the last element
         */
    MapIteratorConst<T1, T2> end() const;

  private:

    /// This is what our class encapsulates.
    std::map<T1, T2> m_data;
};

// Implementation

template<class T1, class T2>
Map<T1, T2>::Map() : m_data(std::map<T1, T2>()) {}

template<class T1, class T2>
const T2& Map<T1, T2>::operator[](const T1& p_key) const {
    // Check if the key exists
    if ( this->m_data.find(p_key) == this->m_data.end() ) {
        // if it doesn't
        throw MapKeyNotFound();
    }

    // If it does, return it
    return this->m_data.at(p_key);
}

template<class T1, class T2>
T2& Map<T1, T2>::operator[](const T1& p_key) {
    // If it does, return it
    return this->m_data[p_key];
}


/*template<class T1, class T2>
MapIterator<T1, T2> Map<T1, T2>::begin() {
    return this->m_data.begin();
}

template<class T1, class T2>
MapIterator<T1, T2> Map<T1, T2>::end() {
    return this->m_data.end();
}*/

template<class T1, class T2>
MapIteratorConst<T1, T2> Map<T1, T2>::begin() const {
    return this->m_data.begin();
}

template<class T1, class T2>
MapIteratorConst<T1, T2> Map<T1, T2>::end() const {
    return this->m_data.end();
}

#endif // MAP_H#include <map> // Used for the map
