#ifndef MAPEXCEPTIONS_H
#define MAPEXCEPTIONS_H

    /**
     * @author Cameron Sims
     * @date 17/05/2024
     *
     * @class MapKeyNotFound
     * @brief Thrown if a map key isn't found
     */
class MapKeyNotFound {
  public:
        /**
         * @brief The string representing the error
         * @return A string which details the reason we got thrown
         */
    const char* what() const;
};

#endif // MAPEXCEPTIONS_H
