#include "linkedList.h"

int main() {
    int *arr = new int[3];
    arr[0] = 0;
    arr[1] = 1;
    arr[2] = 2;
    LinkedList<int> list1(arr, 3);
    bool flag = true;
    if (list1.getFirst() != 0)
        printf("Get first error\n");
    else printf("Get first success\n");
    if (list1.getLast() != 2)
        printf("Get last error\n");
    else printf("Get last success\n");
    if (list1.get(1) != 1)
        printf("Get error\n");
    else printf("Get success\n");
    if (list1.getLength() != 3)
        printf("Get length error\n");
    else printf("Get length success\n");
    for (int i = 0; i < 3; i++) {
        if (i != list1.get(i))
            flag = false;
    }
    if (flag) {
        printf("List created 1\n");
    } else printf("List creation failed 1\n");
    LinkedList<int> list2(list1);
    flag = true;
    for (int i = 0; i < 3; i++) {
        if (i != list2.get(i)) {
            flag = false;
        }
    }
    if (flag) {
        printf("List created 2\n");
    } else printf("List creation failed 2\n");
    list1.append(4);
    if (list1.getLength() != 4) {
        printf("Append resize error\n");
    } else printf("Append resize success\n");
    if (list1.getFirst() != 4) {
        printf("Append add error\n");
    } else printf("Append add success\n");
    list2.prepend(4);
    if (list2.getLength() != 4) {
        printf("Prepend resize error\n");
    } else printf("Prepend resize success\n");
    if (list2.getLast() != 4) {
        printf("Prepend add error\n");
    } else printf("Prepend add success\n");
    LinkedList<int> *list3;
    list3 = list2.getSubList(0, 1);
    flag = true;
    for (int i = 0; i < 2; i++) {
        if (list3->get(i) != i) {
            flag = false;
        }
    }
    if (flag) {
        printf("Get sublist success\n");
    } else printf("Get sublist error\n");
    LinkedList<int> *list4;
    list4 = list2.getSubList(1, 0);
    flag = true;
    for (int i = 0; i < 2; i++) {
        if (list4->get(i) != i) {
            flag = false;
        }
    }
    if (flag) {
        printf("Get sublist w/reversed index success\n");
    } else printf("Get sublist w/reversed index error\n");
    LinkedList<int> *list5;
    list5 = list2.getSubList(0, 0);
    if (list5->getFirst() != 0) {
        printf("Get sublist of 1 error\n");
    } else printf("Get sublist of 1 success\n");
    LinkedList<int> lista(arr, 3);
    LinkedList<int> listb(arr, 3);
    LinkedList<int> *listc = lista.concat(&listb);
    flag = true;
    for (int i = 0; i < 6; i++) {
        if (arr[i % 3] != listc->get(i))
            flag = false;
    }
    if (flag)
        printf("Concat success\n");
    else printf("Concat fail\n");
    lista.insertAt(1, 0);
    lista.insertAt(2, 1);
    lista.insertAt(5, 5);
    if (lista.get(0) != 1 || lista.get(1) != 2 || lista.get(5) != 5)
        printf("Insert error\n");
    else printf("Insert success\n");
    delete arr;
    list1.removeAt(0);
    if (list1.getFirst() != 0)
        printf("Remove at failed\n");
    else printf("Remove at success\n");
    list1.setElem(0, 4);
    if (list1.getFirst() != 4)
        printf("Set failed\n");
    else printf("Set success\n");
    listc->~LinkedList();
    list5->~LinkedList();
    list4->~LinkedList();
    list3->~LinkedList();
    //list2->~LinkedList();
    //list1->~LinkedList();

}