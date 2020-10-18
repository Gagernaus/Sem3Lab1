#ifndef SEM2LAB2_LINKEDSEQUENCE_H
#define SEM2LAB2_LINKEDSEQUENCE_H

#include "Sequence.h"
#include "linkedList.h"

template<class T>
class LinkedSequence : public Sequence<T> {
private:
    LinkedList<T> *items;
public:
    LinkedSequence(T *items, int count) {
        this->items = new LinkedList<T>(items, count);
    }

    LinkedSequence() {
        this->items = new LinkedList<T>();
    }

    LinkedSequence(const LinkedList<T> &list) {
        this->items = new LinkedList<T>(list);
    }

    ~LinkedSequence() {
        this->items->~LinkedList();
    }

    void setElem(int index, T value) {
        if (index < 0 || index >= this->items->getSize())
            throw -1;
        else {
            this->items->setElem(index, value);
        }
    }

    int getLength() const {
        return this->items->getSize();
    }

    T getFirst() const {
        if (this->items->getSize() == 0)
            throw -1;
        else {
            this->items->getFirst();
        }
    }

    T getLast() const {
        if (this->items->getSize() == 0)
            throw -1;
        else {
            this->items->getLast();
        }
    }

    T get(const int index) const {
        if (index < 0 || index > this->items->getSize() - 1)
            throw -1;
        else {
            return this->items->get(index);
        }
    }

    LinkedSequence<T> *getSubsequence(const int start, const int end) const {
        LinkedSequence<T> *result = new LinkedSequence<T>();
        result->items = this->items->getSubList(start, end);
        return result;
    }

    void append(T value) {
        this->items->append(value);
    }

    void prepend(T value) {
        this->items->prepend(value);
    }

    void insertAt(int index, T value) {
        if (index < 0 || index > this->items->getSize())
            throw -1;
        else {
            this->items->insertAt(value, index);
        }
    }

    void removeAt(int index) {
        if (index < 0 || index > this->items->getSize())
            throw -1;
        else {
            this->items->removeAt(index);
        }
    }

    void remove(T value) {
        bool flag = false;
        int i;
        for (i = 0; i < this->items->getLength(); i++) {
            if (value == this->items->get(i)) {
                flag = true;
                break;
            }
        }
        if (flag) {
            this->removeAt(i);
        }
    }

    Sequence<T> *concat(Sequence<T> *other) {
        T *arr = new T[this->items->getLength() + other->getLength()];
        for (int i = 0; i < this->getLength(); i++)
            arr[i] = this->items->get(i);
        for (int i = 0; i < other->getLength(); i++)
            arr[i + this->getLength()] = other->get(i);
        Sequence<T> *result = new LinkedSequence<T>(arr, this->items->getLength() + other->getLength());
        delete[](arr);
        return result;
    }

    LinkedSequence<T> *copy() {
        T *arr = new T[this->items->getLength()];
        for (int i = 0; i < this->items->getLength(); i++)
            arr[i] = this->items->get(i);
        LinkedSequence<T> *result = new LinkedSequence<T>(arr, this->items->getLength());
        delete[](arr);
        return result;
    }

    void out() const {
        this->items->listOut();
    }

    void outTo(unsigned int num) const {
        if (num < 0)
            throw -1;
        if (num > items->getSize()) {
            this->out();
            return;
        } else if (num <= items->getSize()) {
            for (unsigned int i = 0; i < num; i++)
                std::cout << items->get(i) << " ";
            std::cout << "\n";
        }
    }

};


#endif //SEM2LAB2_LINKEDSEQUENCE_H
