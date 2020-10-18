#ifndef SEM2LAB2_DYNAMICARRAY_H
#define SEM2LAB2_DYNAMICARRAY_H

#include <iostream>
#include <stdio.h>


template<class T>
class DynamicArray {
private:
    unsigned int arraySize;
    bool *isSet;
    T *items;


public:
    DynamicArray(T *items, unsigned int count) {
        this->arraySize = count;
        this->items = new T[count];
        this->isSet = new bool[count];
        for (unsigned int i = 0; i < count; i++) {
            setElem(i, items[i]);
        }
    }

    DynamicArray(const unsigned int size) {
        if (size < 0)
            throw -1;
        this->items = new T[size];
        this->arraySize = size;
        this->isSet = new bool[size];
        for (unsigned int i = 0; i < size; i++)
            this->isSet[i] = false;
    }

    DynamicArray(const DynamicArray<T> &array) {
        this->arraySize = array.arraySize;
        this->items = new T[this->arraySize];
        this->isSet = new bool[this->arraySize];
        for (unsigned int i = 0; i < this->arraySize; i++) {
            if (array.isSet[i]) {
                setElem(i, array.items[i]);
            } else {
                this->isSet[i] = false;
            }
        }
    }

    ~DynamicArray() {
        delete[](this->items);
        delete[](this->isSet);
    }

    T getElem(unsigned int index) {
        if (index < 0 || index >= this->arraySize || !this->isSet[index])
            throw -1;
        else return this->items[index];
    }

    unsigned int getSize() {
        return arraySize;
    }


    void setElem(unsigned int index, T value) {
        if (index < 0 || index >= this->arraySize)
            throw -1;
        else {
            this->items[index] = value;
            this->isSet[index] = true;
        }
    }

    void resize(unsigned int newSize) {
        T *newItems = new T[newSize];
        bool *newIsSet = new bool[newSize];
        if (newSize < this->getSize()) {
            for (unsigned int i = 0; i < newSize; i++) {
                if (i >= this->arraySize - 1) {
                    break;
                }
                if (this->isSet[i]) {
                    newItems[i] = getElem(i);
                    newIsSet[i] = true;
                } else {
                    newIsSet[i] = false;
                }
            }
        } else {
            for (unsigned int i = 0; i < newSize; i++) {
                if (i >= this->arraySize) {
                    break;
                }
                if (this->isSet[i]) {
                    newItems[i] = getElem(i);
                    newIsSet[i] = true;
                } else
                    newIsSet[i] = false;
            }
        }
        delete[] (this->items);
        delete[] (this->isSet);
        this->items = newItems;
        this->isSet = newIsSet;
        this->arraySize = newSize;
    }

    void arrayOut() {
        for (unsigned int i = 0; i < this->getSize(); i++) {
            if (this->isSet[i]) {
                std::cout << this->getElem(i);
                std::cout << " ";
            } else {
                std::cout << "NS ";//NS = not set
            }
        }
        std::cout << "\n";
    }

    bool getSet(unsigned int index) {
        if (index < 0 || index > this->arraySize)
            throw -1;
        else
            return this->isSet[index];
    }
    

};


#endif //SEM2LAB2_DYNAMICARRAY_H
