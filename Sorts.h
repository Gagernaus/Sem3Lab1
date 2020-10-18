#ifndef SEM3LAB1_SORTS_H
#define SEM3LAB1_SORTS_H

#include "iostream"
#include "functional"
#include "Sequence.h"

template<class T>
class Sorter {
public:
    virtual void sort(Sequence<T> &sequence) = 0;

private:

};

template<class T>
class quickSort : public Sorter<T> {
public:
    void sort(Sequence<T> &sequence) override {
        if (sequence.getLength() == 0)
            return;
        else {
            int l = 0;
            int r = sequence.getLength() - 1;
            sort(sequence, l, r);
        }
    }

private:
    void sort(Sequence<T> &sequence, int left, int right) {
        int i = left;
        int j = right;
        T p = sequence.get((i + j) / 2);
        T k;
        while (i <= j) {
            while (sequence.get(i) < p)//(compare(sequence.get(i), p))
                i++;
            while (sequence.get(j) > p)//(compare(p, sequence.get(j)))
                j--;
            if (i <= j) {
                k = sequence.get(i);
                sequence.setElem(i, sequence.get(j));
                sequence.setElem(j, k);
                i++;
                j--;
            }
        }
        if (j > left)
            sort(sequence, left, j);
        if (i < right)
            sort(sequence, i, right);
    }
};

template<class T>
class heapSort : public Sorter<T> {
public:
    void sort(Sequence<T> &sequence) override {
        if (sequence.getLength() == 0)
            return;
        for (int i = sequence.getLength() / 2 - 1; i >= 0; i--) {
            heapify(sequence, sequence.getLength(), i);
        }
        for (int i = sequence.getLength() - 1; i >= 0; i--) {
            T k = sequence.get(0);
            sequence.setElem(0, sequence.get(i));
            sequence.setElem(i, k);
            heapify(sequence, i, 0);
        }
    }

private:
    void heapify(Sequence<T> &sequence, int n, int i) {
        int biggest = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        if (l < n && sequence.get(l) > sequence.get(biggest))
            biggest = l;
        if (r < n && sequence.get(r) > sequence.get(biggest))
            biggest = r;
        if (biggest != i) {
            T k = sequence.get(i);
            sequence.setElem(i, sequence.get(biggest));
            sequence.setElem(biggest, k);
            heapify(sequence, n, biggest);
        }
    }
};

template<class T>
class shellSort : public Sorter<T> {
public:
    void sort(Sequence<T> &sequence) {
        if (sequence.getLength() == 0)
            return;
        int n = sequence.getLength();
        for (int g = n / 2; g > 0; g /= 2) {
            for (int i = g; i < n; i++) {
                T k = sequence.get(i);
                int j;
                for (j = i; j >= g && sequence.get(j - g) > k; j = j - g) {
                    sequence.setElem(j, sequence.get(j - g));
                }
                sequence.setElem(j, k);
            }
        }
    }
};


template<class T>
class bubbleSort : public Sorter<T> {
public:
    void sort(Sequence<T> &sequence) {
        if (sequence.getLength() == 0)
            return;
        for (int i = 0; i < sequence.getLength(); i++) {
            //std::cout << i << "\n";
            for (int j = 0; j < sequence.getLength() - 1; j++) {
                if (sequence.get(j + 1) < sequence.get(j)) {
                    T k = sequence.get(j);
                    sequence.setElem(j, sequence.get(j + 1));
                    sequence.setElem(j + 1, k);
                }
            }
        }
    }
};

template<class T>
class choiceSort : public Sorter<T> {
public:
    void sort(Sequence<T> &sequence) {
        if (sequence.getLength() == 0)
            return;
        for (int i = 0; i < sequence.getLength() - 1; i++) {
            T minimum = sequence.get(i);
            int minInd = i;
            for (int j = i + 1; j < sequence.getLength(); j++) {
                if (minimum > sequence.get(j)) {
                    minInd = j;
                    minimum = sequence.get(j);
                }
            }
            sequence.setElem(minInd, sequence.get(i));
            sequence.setElem(i, minimum);
        }
    }
};

template<class T>
class insertSort : public Sorter<T> {
public:
    void sort(Sequence<T> &sequence) {
        if (sequence.getLength() == 0)
            return;
        for (int i = 0; i < sequence.getLength(); i++) {
            for (int j = i; j > 0 && (sequence.get(j - 1) > sequence.get(j)); j--) {
                T k = sequence.get(j);
                sequence.setElem(j, sequence.get(j - 1));
                sequence.setElem(j - 1, k);
            }
        }
    }
};

#endif //SEM3LAB1_SORTS_H
