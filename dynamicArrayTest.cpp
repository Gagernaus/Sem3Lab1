#include "DynamicArray.h"

int main() {
    int *arr = new int[3];
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 3;
    DynamicArray<int> *dynar = new DynamicArray<int>(arr, 3);
    bool flag = true;
    for (int i = 0; i < 3; i++) {
        if (dynar->getElem(i) != arr[i]) {
            flag = false;
            break;
        }
    }
    if (flag)
        printf("Array created 1\n");
    else printf("Array creation error 1\n");
    flag = true;
    DynamicArray<int> *dynar1 = new DynamicArray<int>(3);
    for (int i = 0; i < 3; i++) {
        dynar1->setElem(i, i);
        if (dynar1->getElem(i) != i)
            flag = false;
    }
    if (flag)
        printf("Array created 2\n");
    else printf("Array creation error 2\n");
    DynamicArray<int> *dynar2 = new DynamicArray<int>(*dynar1);
    flag = true;
    for (int i = 0; i < 3; i++) {
        if (dynar2->getElem(i) != i) {
            flag = false;
        }
    }
    if (flag) {
        printf("Array created 3\n");
    } else printf("Array creation error 3\n");
    if (dynar2->getSize() != 3) {
        printf("Get size error\n");
    }
    dynar2->resize(2);
    flag = true;
    for (int i = 0; i < 2; i++) {
        if (dynar2->getElem(i) != i) {
            flag = false;
        }
    }
    if (flag) {
        printf("Array resize success\n");
    } else printf("Array resize error\n");
    dynar1->setElem(0, 4);
    if (dynar1->getElem(0) != 4)
        printf("Set failed\n");
    else printf("Set success\n");
    dynar2->~DynamicArray();
    dynar1->~DynamicArray();
    dynar->~DynamicArray();
    return 0;
}