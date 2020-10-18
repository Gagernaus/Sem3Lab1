#include "Sequence.h"
#include "ArraySequence.h"

int main() {
    int *arr = new int[3];
    arr[0] = 0;
    arr[1] = 1;
    arr[2] = 2;
    ArraySequence<int> ars1 = ArraySequence<int>(arr, 3);
    bool flag = true;
    for (int i = 0; i < 3; i++) {
        if (arr[i] != ars1.get(i)) {
            flag = false;
            break;
        }
    }
    if (flag)
        printf("Array sequence created 1\n");
    else printf("Array sequence creation failed 1\n");
    DynamicArray<int> dynar = DynamicArray<int>(arr, 3);
    ArraySequence<int> ars2 = ArraySequence<int>(dynar);
    flag = true;
    for (int i = 0; i < 3; i++) {
        if (arr[i] != ars2.get(i)) {
            flag = false;
            break;
        }
    }
    if (flag)
        printf("Array sequence created 2\n");
    else printf("Array sequence creation failed 2\n");
    Sequence<int> *ars3 = ars1.getSubsequence(0, 1);
    flag = true;
    for (int i = 0; i < 2; i++) {
        if (i != ars3->get(i)) {
            flag = false;
            break;
        }
    }
    if (flag)
        printf("Get sub sequence success\n");
    else printf("Get sub sequence failed\n");
    ars3->prepend(2);
    if (ars3->getLast() == 2)
        printf("Prepend success\n");
    else printf("Prepend failed\n");
    ars1.append(3);
    if (ars1.getFirst() == 3)
        printf("Append success\n");
    else printf("Append fail\n");
    ars2.insertAt(1, 3);
    if (ars2.get(1) == 3)
        printf("Insert success\n");
    else printf("Insert fail\n");
    ars1.removeAt(0);
    flag = true;
    for (int i = 0; i < 3; i++) {
        if (arr[i] != ars1.get(i)) {
            flag = false;
            break;
        }
    }
    if (flag)
        printf("Remove first success\n");
    else printf("Remove first failed 1\n");
    ars3->removeAt(2);
    flag = true;
    for (int i = 0; i < 2; i++) {
        if (i != ars3->get(i)) {
            flag = false;
            break;
        }
    }
    if (flag)
        printf("Remove last success\n");
    else printf("Remove last failed 1\n");
    ars2.removeAt(1);
    flag = true;
    for (int i = 0; i < 3; i++) {
        if (arr[i] != ars2.get(i)) {
            flag = false;
            break;
        }
    }
    if (flag)
        printf("Remove at success\n");
    else printf("Remove at failed 1\n");
    ars1.remove(0);
    if (ars1.getFirst() != 0)
        printf("Remove success\n");
    else printf("Remove failed\n");
    Sequence<int> *ars4 = ars2.copy();
    flag = true;
    for (int i = 0; i < 3; i++) {
        if (ars4->get(i) != ars2.get(i)) {
            flag = false;
            break;
        }
    }
    if (flag)
        printf("Copy success\n");
    else printf("Copy failed 1\n");
    Sequence<int> *ars5 = ars2.concat(&ars2);
    flag = true;
    for (int i = 0; i < 6; i++) {
        if (ars5->get(i) != ars2.get(i % 3)) {
            flag = false;
            break;
        }
    }
    if (flag) {
        printf("Concat success\n");
    } else printf("Concat failed 1\n");
    ars1.setElem(0, 4);
    if (ars1.get(0) != 4)
        printf("Set failed\n");
    else printf("Set success\n");
    ars3->~Sequence();
    ars4->~Sequence();
    ars5->~Sequence();
    delete[](arr);

    return 0;
}
