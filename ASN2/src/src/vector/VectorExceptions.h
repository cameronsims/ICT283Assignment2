#ifndef VECTOREXCEPTIONS_H
#define VECTOREXCEPTIONS_H

class VectorError {
public:
    const char* what() const;
};

class VectorOutOfRange : VectorError {
public:
    const char* what() const;
};

#endif // VECTOREXCEPTIONS_H
