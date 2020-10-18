#include "DynamicArray.h"
#include <stdio.h>

int main() {
    int *arri = new int[5];
    arri[0] = 12;
    arri[1] = 2;
    arri[2] = -60;
    arri[3] = -23;
    arri[4] = 14;
    int *arri1 = new int[5];
    arri1[0] = -60;
    arri1[1] = -23;
    arri1[2] = 2;
    arri1[3] = 12;
    arri1[4] = 14;
    DynamicArray<int> *dynar = new DynamicArray<int>(arri, 5);
    dynar->bubbleSort();
    bool flag = true;
    for (int i = 0; i < 5; i++) {
        if (arri1[i] != dynar->getElem(i)) {
            flag = false;
            break;
        }
    }
    if (flag) {
        std::cout << "Bubble sort int success\n";
    } else std::cout << "Bubble sort int fail\n";
    float *arrf = new float[5];
    arrf[0] = 10.2;
    arrf[1] = 2.32141;
    arrf[2] = -3;
    arrf[3] = -23.6;
    arrf[4] = 14;
    float *arrf1 = new float[5];
    arrf1[0] = -23.6;
    arrf1[1] = -3;
    arrf1[2] = 2.32141;
    arrf1[3] = 10.2;
    arrf1[4] = 14;
    DynamicArray<float> *dynar1 = new DynamicArray<float>(arrf, 5);
    dynar1->bubbleSort();
    flag = true;
    for (int i = 0; i < 5; i++) {
        if (arrf1[i] != dynar1->getElem(i)) {
            flag = false;
            break;
        }
    }
    if (flag) {
        std::cout << "Bubble sort float success\n";
    } else std::cout << "Bubble sort float fail\n";
    DynamicArray<int> *dynar2 = new DynamicArray<int>(arri, 5);
    dynar2->insertSort();
    flag = true;
    for (int i = 0; i < 5; i++) {
        if (arri1[i] != dynar2->getElem(i)) {
            flag = false;
            break;
        }
    }
    if (flag) {
        std::cout << "Insert sort int success\n";
    } else std::cout << "Insert sort int fail\n";
    DynamicArray<float> *dynar3 = new DynamicArray<float>(arrf, 5);
    dynar3->insertSort();
    flag = true;
    for (int i = 0; i < 5; i++) {
        if (arrf1[i] != dynar3->getElem(i)) {
            flag = false;
            break;
        }
    }
    if (flag) {
        std::cout << "Insert sort float success\n";
    } else std::cout << "Insert sort float fail\n";
    DynamicArray<int> *dynar4 = new DynamicArray<int>(arri, 5);
    dynar4->choiceSort();
    flag = true;
    for (int i = 0; i < 5; i++) {
        if (arri1[i] != dynar4->getElem(i)) {
            flag = false;
            break;
        }
    }
    if (flag) {
        std::cout << "Choice sort int success\n";
    } else std::cout << "Choice sort int fail\n";
    DynamicArray<float> *dynar5 = new DynamicArray<float>(arrf, 5);
    dynar5->choiceSort();
    flag = true;
    for (int i = 0; i < 5; i++) {
        if (arrf1[i] != dynar5->getElem(i)) {
            flag = false;
            break;
        }
    }
    if (flag) {
        std::cout << "Choice sort float success\n";
    } else std::cout << "Choice sort float fail\n";
    dynar->~DynamicArray();
    dynar1->~DynamicArray();
    dynar2->~DynamicArray();
    dynar3->~DynamicArray();
    dynar4->~DynamicArray();
    dynar5->~DynamicArray();
    return 0;
}