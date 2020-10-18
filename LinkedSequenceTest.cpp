#include "Sequence.h"
#include "LinkedSequence.h"

int main() {
    int *arr = new int[3];
    arr[0] = 0;
    arr[1] = 1;
    arr[2] = 2;
    LinkedSequence<int> lsq1 = LinkedSequence<int>(arr, 3);
    bool flag = true;
    for (int i = 0; i < 3; i++) {
        if (arr[i] != lsq1.get(i)) {
            flag = false;
            break;
        }
    }
    if (flag)
        printf("Linked sequence created 1\n");
    else printf("Linked sequence creation failed 1\n");
    LinkedList<int> ll = LinkedList<int>(arr, 3);
    LinkedSequence<int> lsq2 = LinkedSequence<int>(ll);
    flag = true;
    for (int i = 0; i < 3; i++) {
        if (ll.get(i) != lsq2.get(i)) {
            flag = false;
            break;
        }
    }
    if (flag)
        printf("Linked sequence created 2\n");
    else printf("Linked sequence creation failed 2\n");
    lsq1.append(4);
    if (lsq1.getFirst() != 4)
        printf("Append fail\n");
    else printf("Append success\n");
    lsq2.prepend(4);
    if (lsq2.getLast() != 4)
        printf("Prepend fail\n");
    else printf("Prepend success\n");
    LinkedSequence<int> *lsq3 = lsq2.getSubsequence(0, 1);
    flag = true;
    for (int i = 0; i < 2; i++) {
        if (lsq3->get(i) != i) {
            flag = false;
            break;
        }
    }
    if (flag)
        printf("Get subsequence success\n");
    else printf("Get subsequence failed \n");
    lsq1.insertAt(1, 5);
    if (lsq1.get(1) != 5)
        printf("Insert failed\n");
    else printf("Insert success\n");
    lsq1.removeAt(1);
    if (lsq1.get(1) != 0)
        printf("Remove at failed\n");
    else printf("Remove at success\n");
    lsq1.remove(4);
    if (lsq1.get(0) != 0)
        printf("Remove failed\n");
    else printf("Remove success\n");
    Sequence<int> *lsq4 = lsq1.concat(&lsq1);
    flag = true;
    for (int i = 0; i < 6; i++) {
        if (lsq4->get(i) != i % 3) {
            flag = false;
            break;
        }
    }
    if (flag)
        printf("Get subsequence success\n");
    else printf("Get subsequence failed \n");
    LinkedSequence<int> *lsq5 = lsq1.copy();
    flag = true;
    for (int i = 0; i < 3; i++) {
        if (lsq5->get(i) != lsq1.get(i)) {
            flag = false;
            break;
        }
    }
    if (flag)
        printf("Copy success\n");
    else printf("Copy failed \n");
    lsq1.setElem(0, 4);
    if (lsq1.get(0) != 4)
        printf("Set failed\n");
    else printf("Set success\n");
    delete[](arr);
    lsq3->~LinkedSequence();
    lsq4->~Sequence();
    lsq5->~LinkedSequence();

    return 0;
}