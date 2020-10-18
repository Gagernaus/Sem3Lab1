#ifndef SEM2LAB2_SEQUENCE_H
#define SEM2LAB2_SEQUENCE_H


template<class T>
class Sequence {
public:
    virtual int getLength() const = 0;

    virtual T getFirst() const = 0;

    virtual T getLast() const = 0;

    virtual T get(const int i) const = 0;

    virtual Sequence<T> *getSubsequence(const int start, const int end) const = 0;

public:
    virtual void out() const = 0;

    virtual void setElem(int index, T value) = 0;

    virtual void append(T value) = 0;

    virtual void prepend(T value) = 0;

    virtual void insertAt(const int index, T value) = 0;

    virtual void removeAt(const int index) = 0;

    virtual void remove(T value) = 0; // Удаляет первое вхождение value
    //virtual void RemoveAll(T value) = 0;

    virtual Sequence<T> *concat(Sequence<T> *other) = 0;

    virtual Sequence<T> *copy() = 0;

//    virtual Sequence<T> *CopyTo(Sequence<T> *target, int startIndex) = 0;

public:
    virtual ~Sequence() {}
};


#endif //SEM2LAB2_SEQUENCE_H
