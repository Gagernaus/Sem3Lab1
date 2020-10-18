#ifndef SEM2LAB2_LINKEDLIST_H
#define SEM2LAB2_LINKEDLIST_H

#include <iostream>
#include <stdio.h>


template<class T>
class LinkedList {
private:
    template<class Y>
    class Entry {
    private:
        Y value;
        Entry *next;
    public:
        T getValue() {
            return this->value;
        }

        Entry *getNext() {
            return this->next;
        }

        void setValue(T value) {
            this->value = value;
        }

        void setNext(Entry *next) {
            this->next = next;
        }
    };

    Entry<T> *head;
    unsigned int size;
public:
    LinkedList(T *items, unsigned int count) {
        this->size = count;
        this->head = new Entry<T>;
        this->head->setValue(items[0]);
        if (count > 1) {
            Entry<T> *elem = new Entry<T>;
            this->head->setNext(elem);
            for (unsigned int i = 1; i < count - 1; i++) {
                elem->setValue(items[i]);
                elem->setNext(new Entry<T>);
                elem = elem->getNext();
            }
            elem->setValue(items[count - 1]);
            elem->setNext(nullptr);
        } else {
            this->head->setNext(nullptr);
        }
    }

    LinkedList() {
        this->size = 0;
        this->head = new Entry<T>;
        this->head->setNext(nullptr);
    }

    LinkedList(const LinkedList<T> &list) {
        this->size = list.size;
        this->head = new Entry<T>;
        this->head->setValue(list.head->getValue());
        Entry<T> *newElem = new Entry<T>;
        this->head->setNext(newElem);
        Entry<T> *elem = new Entry<T>;
        elem = list.head->getNext();
        for (unsigned int i = 1; i < list.size - 1; i++) {
            newElem->setValue(elem->getValue());
            newElem->setNext(new Entry<T>);
            newElem = newElem->getNext();
            elem = elem->getNext();
        }
        newElem->setValue(elem->getValue());
        newElem->setNext(nullptr);
    }

    ~LinkedList() {
        if (this->size > 0) {
            Entry<T> *elem;
            elem = this->head;
            Entry<T> *elem1;
            while (elem != nullptr) {
                elem1 = elem;
                elem = elem->getNext();
                delete (elem1);
            }

        }
    }

    unsigned int getSize() const {
        return this->size;
    }

    void setElem(unsigned int index, T value) {
        if (index < 0 || index >= this->size)
            throw -1;
        else {
            if (index == 0)
                this->head->setValue(value);
            else {
                Entry<T> *el = this->head->getNext();
                for (unsigned int i = 1; i < index; i++)
                    el = el->getNext();
                el->setValue(value);
            }
        }
    }

    T getFirst() const {
        if (this->size == 0)
            throw -1;
        else return this->head->getValue();
    }

    T getLast() const {
        if (this->size == 0)
            throw -1;
        else if (this->size == 1)
            return this->head->getValue();
        else {
            Entry<T> *elem = this->head->getNext();
            while (elem->getNext() != nullptr) {
                elem = elem->getNext();
            }
            return elem->getValue();
        }
    }

    T get(unsigned int index) const {
        if (index < 0 || index > this->size)
            throw -1;
        else if (index == 0)
            return this->getFirst();
        else if (index == this->size - 1) {
            return this->getLast();
        } else {
            Entry<T> *elem = this->head->getNext();
            unsigned int i = 0;
            for (i; i < index - 1; i++) {
                elem = elem->getNext();
            }
            return elem->getValue();
        }
    }

    unsigned int getLength() const {
        return size;
    }


    void append(T item) {
        Entry<T> *newHead = new Entry<T>;
        newHead->setValue(item);
        newHead->setNext(this->head);
        this->head = newHead;
        this->size = this->size + 1;
    }

    void prepend(T item) {
        Entry<T> *newElem = new Entry<T>;
        Entry<T> *el;
        newElem->setValue(item);
        newElem->setNext(nullptr);
        el = this->head;
        while (el->getNext() != nullptr) {
            el = el->getNext();
        }
        el->setNext(newElem);
        this->size = this->size + 1;
    }

    LinkedList<T> *getSubList(unsigned int start, unsigned int end) {
        if (start < 0 || end < 0 || start >= this->size || end >= this->size)
            throw -1;
        else {
            if (start > end) {
                unsigned int a = start;
                start = end;
                end = a;
            }
            LinkedList<T> *result = new LinkedList<T>();
            Entry<T> *el = this->head;
            for (unsigned int i = 0; i < start; i++) {
                el = el->getNext();
            }
            result->size = end - start + 1;
            result->head = new Entry<T>;
            result->head->setValue(el->getValue());
            if (end - start + 1 == 1) {
                result->head->setNext(nullptr);
            } else {
                Entry<T> *el1 = new Entry<T>;
                result->head->setNext(el1);
                el = el->getNext();
                for (unsigned int i = 0; i < end - start - 1; i++) {
                    el1->setValue(el->getValue());
                    el = el->getNext();
                    el1->setNext(new Entry<T>);
                    el1 = el1->getNext();
                }
                el1->setValue(el->getValue());
                el1->setNext(nullptr);
            }
            return result;
        }
    }

    void insertAt(T item, unsigned int index) {
        if (index < 0 || index > this->size)
            throw -1;
        else {
            if (index == 0) {
                append(item);
            } else if (index == this->size) {
                prepend(item);
            } else {
                this->size = this->size + 1;
                Entry<T> *el = this->head->getNext();
                Entry<T> *el1 = this->head;
                for (unsigned int i = 0; i < index - 1; i++) {
                    el1 = el;
                    el = el->getNext();
                }
                Entry<T> *newElem = new Entry<T>;
                newElem->setNext(el);
                newElem->setValue(item);
                el1->setNext(newElem);
            }
        }
    }

    void removeAt(unsigned int index) {
        if (index < 0 || index > this->size)
            throw -1;
        else {
            if (index == 0) {
                Entry<T> *el = this->head;
                this->head = this->head->getNext();
                delete[](el);
            } else if (index == this->size) {
                Entry<T> *el = this->head->getNext();
                Entry<T> *el1 = this->head;
                while (el->getNext() != nullptr) {
                    el1 = el;
                    el = el->getNext();
                }
                el1->setNext(nullptr);
                delete[](el);
            } else {
                Entry<T> *el = this->head->getNext();
                Entry<T> *el1 = this->head;
                for (unsigned int i = 1; i < index; i++) {
                    el1 = el;
                    el = el->getNext();
                }
                el1->setNext(el->getNext());
                delete[](el);
            }
            this->size = this->size - 1;
        }
    }

    LinkedList<T> *concat(const LinkedList<T> *list) {
        LinkedList<T> *result = new LinkedList();
        result->size = this->size + list->size;
        this->head->setValue(this->head->getValue());
        Entry<T> *el = new Entry<T>;
        result->head->setNext(el);
        Entry<T> *el1 = this->head->getNext();
        while (el1 != nullptr) {
            el->setValue(el1->getValue());
            el1 = el1->getNext();
            el->setNext(new Entry<T>);
            el = el->getNext();
        }
        el1 = list->head;
        while (el1->getNext() != nullptr) {
            el->setValue(el1->getValue());
            el->setNext(new Entry<T>);
            el1 = el1->getNext();
            el = el->getNext();
        }
        el->setValue(el1->getValue());
        el->setNext(nullptr);
        return result;
    }

    void listOut() const {
        Entry<T> *el = this->head;
        while (el != nullptr) {
            std::cout << el->getValue();
            std::cout << " ";
            el = el->getNext();
        }
        std::cout << "\n";
    }

};


#endif //SEM2LAB2_LINKEDLIST_H
