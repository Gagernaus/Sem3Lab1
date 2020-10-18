#ifndef SEM2LAB2_ARRAYSEQUENCE_H
#define SEM2LAB2_ARRAYSEQUENCE_H

#include "Sequence.h"
#include "DynamicArray.h"


template<class T>
class ArraySequence : public Sequence<T> {
private:
    DynamicArray<T> *items;

public:
    ArraySequence(T *items, int count) {
        this->items = new DynamicArray<T>(items, count);
    }

    ArraySequence(int count) {
        this->items = new DynamicArray<T>(count);
    }

    ArraySequence() {
        this->items = new DynamicArray<T>(0);
    }

    ArraySequence(const DynamicArray<T> &array) {
        this->items = new DynamicArray<T>(array);
    }

    ~ArraySequence() {
        this->items->~DynamicArray();
    }

    void setElem(int index, T value) {
        if (index < 0 || index >= this->items->getSize())
            throw -1;
        else {
            this->items->setElem(index, value);
        }
    }

    T getFirst() const {
        if (this->items->getSize() == 0)
            throw -1;
        else return this->items->getElem(0);
    }

    T getLast() const {
        if (this->items->getSize() == 0)
            throw -1;
        else {
            return this->items->getElem(this->items->getSize() - 1);
        }
    }

    int getLength() const {
        return this->items->getSize();
    }

    T get(int index) const {
        if (index < 0 || index > this->items->getSize() - 1) {
            throw -1;
        } else if (!this->items->getSet(index))
            return 0;
        else
            return this->items->getElem(index);
    }

    ArraySequence<T> *getSubsequence(int start, int end) const {
        if (start < 0 || end < 0 || start >= this->items->getSize() || end >= this->items->getSize())
            throw -1;
        else {
            if (start > end) {
                int a = end;
                end = start;
                start = a;
            }
            ArraySequence<T> *result = new ArraySequence<T>(end - start + 1);
            for (int i = 0; i < end - start + 1; i++) {
                result->items->setElem(i, this->items->getElem(start + i));
            }
            return result;
        }
    }

    void append(T item) {
        this->items->resize(this->items->getSize() + 1);
        for (int i = this->items->getSize() - 1; i > 0; i--) {
            this->items->setElem(i, this->items->getElem(i - 1));
        }
        this->items->setElem(0, item);
    }

    void prepend(T item) {
        this->items->resize(this->items->getSize() + 1);
        this->items->setElem(this->items->getSize() - 1, item);
    }

    void insertAt(int index, T item) {
        if (index < 0 || index > this->items->getSize() - 1)
            throw -1;
        else {
            this->items->resize(this->items->getSize() + 1);
            for (int i = this->items->getSize() - 1; i > index; i--)
                this->items->setElem(i, this->items->getElem(i - 1));
            this->items->setElem(index, item);
        }
    }

    void removeAt(int index) {
        if (index < 0 || index > this->items->getSize() - 1)
            throw -1;
        else {
            if (index == items->getSize() - 1) {
                this->items->resize(items->getSize() - 1);
            } else if (index == 0) {
                T last = this->getLast();
                this->items->resize(this->items->getSize() - 1);
                for (int i = 0; i < this->items->getSize() - 1; i++)
                    this->items->setElem(i, this->items->getElem(i + 1));
                this->items->setElem(this->items->getSize() - 1, last);
            } else {
                T last = this->getLast();
                this->items->resize(items->getSize() - 1);
                for (int i = index; i < items->getSize() - 1; i++)
                    this->items->setElem(i, this->items->getElem(i + 1));
                this->items->setElem(this->items->getSize() - 1, last);
            }
        }
    }

    void remove(T value) {
        bool flag = false;
        int i;
        for (i = 0; i < this->items->getSize(); i++) {
            if (this->items->getElem(i) == value) {
                flag = true;
                break;
            }
        }
        if (flag)
            this->removeAt(i);
    }

    Sequence<T> *concat(Sequence<T> *other) {
        T *arr = new T[this->getLength() + other->getLength()];
        for (int i = 0; i < this->getLength(); i++)
            arr[i] = this->get(i);
        for (int i = 0; i < other->getLength(); i++)
            arr[i + this->getLength()] = other->get(i);
        Sequence<T> *result = new ArraySequence<T>(arr, this->getLength() + other->getLength());
        delete[](arr);
        return result;
    }

    Sequence<T> *copy() {
        Sequence<T> *result = new ArraySequence<T>(*this->items);
        return result;
    }

    void out() const {
        this->items->arrayOut();
    }

    void outTo(unsigned int num) const {
        if (num < 0)
            throw -1;
        if (num > items->getSize()) {
            this->out();
            return;
        } else if (num <= items->getSize()) {
            for (unsigned int i = 0; i < num; i++)
                std::cout << items->getElem(i) << " ";
            std::cout << "\n";
        }
    }

};


#endif //SEM2LAB2_ARRAYSEQUENCE_H
