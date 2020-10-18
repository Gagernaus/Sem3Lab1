#include "Sequence.h"
#include "ArraySequence.h"
#include "LinkedSequence.h"
#include "Sorts.h"


int main() {
    int size = 5;
    int arr[5] = {10, 32, 44, 2, 4};
    int arrf[5] = {2, 4, 10, 32, 44};
    ArraySequence<int> seq = ArraySequence<int>(arr, size);
    //--------------------------------------------------------
    quickSort<int> qs{};
    qs.sort(seq);
    bool flag = true;
    for (int i = 0; i < size; i++) {
        if (arrf[i] != seq.get(i)) {
            flag = false;
            break;
        }
    }
    if (flag)
        std::cout << "Quick sort int array sequence success\n";
    else std::cout << "Quick sort int array sequence failed\n";
    LinkedSequence<int> seq1 = LinkedSequence<int>(arr, size);
    qs.sort(seq1);
    flag = true;
    for (int i = 0; i < size; i++) {
        if (arrf[i] != seq1.get(i)) {
            flag = false;
            break;
        }
    }
    if (flag)
        std::cout << "Quick sort int linked sequence success\n";
    else std::cout << "Quick sort int linked sequence failed\n";
    float arr1[5] = {10.4, 32, 44, -2, 4};
    float arr1f[5] = {-2, 4, 10.4, 32, 44};
    ArraySequence<float> seq2 = ArraySequence<float>(arr1, size);
    quickSort<float> qsf{};
    qsf.sort(seq2);
    flag = true;
    for (int i = 0; i < size; i++) {
        if (arr1f[i] != seq2.get(i)) {
            flag = false;
            break;
        }
    }
    if (flag)
        std::cout << "Quick sort float array sequence success\n";
    else std::cout << "Quick sort float array sequence failed\n";
    LinkedSequence<float> seq3 = LinkedSequence<float>(arr1, size);
    qsf.sort(seq3);
    flag = true;
    for (int i = 0; i < size; i++) {
        if (arr1f[i] != seq3.get(i)) {
            flag = false;
            break;
        }
    }
    if (flag)
        std::cout << "Quick sort float linked sequence success\n";
    else std::cout << "Quick sort float linked sequence failed\n";
    //--------------------------------------------------------------
    heapSort<int> hs{};
    ArraySequence<int> seq4 = ArraySequence<int>(arr, size);
    hs.sort(seq4);
    flag = true;
    for (int i = 0; i < size; i++) {
        if (arrf[i] != seq4.get(i)) {
            flag = false;
            break;
        }
    }
    if (flag)
        std::cout << "Heap sort int array sequence success\n";
    else std::cout << "Heap sort int array sequence failed\n";
    LinkedSequence<int> seq5 = LinkedSequence<int>(arr, size);
    hs.sort(seq5);
    flag = true;
    for (int i = 0; i < size; i++) {
        if (arrf[i] != seq5.get(i)) {
            flag = false;
            break;
        }
    }
    if (flag)
        std::cout << "Heap sort int linked sequence success\n";
    else std::cout << "Heap sort int linked sequence failed\n";
    ArraySequence<float> seq6 = ArraySequence<float>(arr1, size);
    heapSort<float> hsf{};
    hsf.sort(seq6);
    flag = true;
    for (int i = 0; i < size; i++) {
        if (arr1f[i] != seq6.get(i)) {
            flag = false;
            break;
        }
    }
    if (flag)
        std::cout << "Heap sort float array sequence success\n";
    else std::cout << "Heap sort float array sequence failed\n";

    LinkedSequence<float> seq7 = LinkedSequence<float>(arr1, size);
    hsf.sort(seq7);
    flag = true;
    for (int i = 0; i < size; i++) {
        if (arr1f[i] != seq7.get(i)) {
            flag = false;
            break;
        }
    }
    if (flag)
        std::cout << "Heap sort float linked sequence success\n";
    else std::cout << "Heap sort float linked sequence failed\n";
    //---------------------------------------------------------------
    shellSort<int> shs{};
    ArraySequence<int> seq8 = ArraySequence<int>(arr, size);
    shs.sort(seq8);
    flag = true;
    for (int i = 0; i < size; i++) {
        if (arrf[i] != seq8.get(i)) {
            flag = false;
            break;
        }
    }
    if (flag)
        std::cout << "Shell sort int array sequence success\n";
    else std::cout << "Shell sort int array sequence failed\n";
    LinkedSequence<int> seq9 = LinkedSequence<int>(arr, size);
    shs.sort(seq9);
    flag = true;
    for (int i = 0; i < size; i++) {
        if (arrf[i] != seq9.get(i)) {
            flag = false;
            break;
        }
    }
    if (flag)
        std::cout << "Shell sort int linked sequence success\n";
    else std::cout << "Shell sort int linked sequence failed\n";
    ArraySequence<float> seq10 = ArraySequence<float>(arr1, size);
    shellSort<float> shsf{};
    shsf.sort(seq10);
    flag = true;
    for (int i = 0; i < size; i++) {
        if (arr1f[i] != seq10.get(i)) {
            flag = false;
            break;
        }
    }
    if (flag)
        std::cout << "Shell sort float array sequence success\n";
    else std::cout << "Shell sort float array sequence failed\n";
    LinkedSequence<float> seq11 = LinkedSequence<float>(arr1, size);
    shsf.sort(seq11);
    flag = true;
    for (int i = 0; i < size; i++) {
        if (arr1f[i] != seq11.get(i)) {
            flag = false;
            break;
        }
    }
    if (flag)
        std::cout << "Shell sort float linked sequence success\n";
    else std::cout << "Shell sort float linked sequence failed\n";
    //-------------------------------------------------------------
    insertSort<int> ins{};
    ArraySequence<int> seq12 = ArraySequence<int>(arr, size);
    ins.sort(seq12);
    flag = true;
    for (int i = 0; i < size; i++) {
        if (arrf[i] != seq12.get(i)) {
            flag = false;
            break;
        }
    }
    if (flag)
        std::cout << "Insert sort int array sequence success\n";
    else std::cout << "Insert sort int array sequence failed\n";
    LinkedSequence<int> seq13 = LinkedSequence<int>(arr, size);
    ins.sort(seq13);
    flag = true;
    for (int i = 0; i < size; i++) {
        if (arrf[i] != seq13.get(i)) {
            flag = false;
            break;
        }
    }
    if (flag)
        std::cout << "Insert sort int linked sequence success\n";
    else std::cout << "Insert sort int linked sequence failed\n";
    ArraySequence<float> seq14 = ArraySequence<float>(arr1, size);
    insertSort<float> insf{};
    insf.sort(seq14);
    flag = true;
    for (int i = 0; i < size; i++) {
        if (arr1f[i] != seq14.get(i)) {
            flag = false;
            break;
        }
    }
    if (flag)
        std::cout << "Insert sort float array sequence success\n";
    else std::cout << "Insert sort float array sequence failed\n";
    LinkedSequence<float> seq15 = LinkedSequence<float>(arr1, size);
    insf.sort(seq15);
    flag = true;
    for (int i = 0; i < size; i++) {
        if (arr1f[i] != seq15.get(i)) {
            flag = false;
            break;
        }
    }
    if (flag)
        std::cout << "Insert sort float linked sequence success\n";
    else std::cout << "Insert sort float linked sequence failed\n";
    //-----------------------------------------------------------------
    choiceSort<int> chs{};
    ArraySequence<int> seq16 = ArraySequence<int>(arr, size);
    chs.sort(seq16);
    flag = true;
    for (int i = 0; i < size; i++) {
        if (arrf[i] != seq16.get(i)) {
            flag = false;
            break;
        }
    }
    if (flag)
        std::cout << "Choice sort int array sequence success\n";
    else std::cout << "Choice sort int array sequence failed\n";
    LinkedSequence<int> seq17 = LinkedSequence<int>(arr, size);
    chs.sort(seq17);
    flag = true;
    for (int i = 0; i < size; i++) {
        if (arrf[i] != seq17.get(i)) {
            flag = false;
            break;
        }
    }
    if (flag)
        std::cout << "Choice sort int linked sequence success\n";
    else std::cout << "Choice sort int linked sequence failed\n";
    ArraySequence<float> seq18 = ArraySequence<float>(arr1, size);
    choiceSort<float> chsf{};
    chsf.sort(seq18);
    flag = true;
    for (int i = 0; i < size; i++) {
        if (arr1f[i] != seq18.get(i)) {
            flag = false;
            break;
        }
    }
    if (flag)
        std::cout << "Choice sort float array sequence success\n";
    else std::cout << "Choice sort float array sequence failed\n";
    LinkedSequence<float> seq19 = LinkedSequence<float>(arr1, size);
    chsf.sort(seq19);
    flag = true;
    for (int i = 0; i < size; i++) {
        if (arr1f[i] != seq19.get(i)) {
            flag = false;
            break;
        }
    }
    if (flag)
        std::cout << "Choice sort float linked sequence success\n";
    else std::cout << "Choice sort float linked sequence failed\n";
    //-------------------------------------------------------------
    bubbleSort<int> bbs{};
    ArraySequence<int> seq20 = ArraySequence<int>(arr, size);
    bbs.sort(seq20);
    flag = true;
    for (int i = 0; i < size; i++) {
        if (arrf[i] != seq20.get(i)) {
            flag = false;
            break;
        }
    }
    if (flag)
        std::cout << "Bubble sort int array sequence success\n";
    else std::cout << "Bubble sort int array sequence failed\n";
    LinkedSequence<int> seq21 = LinkedSequence<int>(arr, size);
    bbs.sort(seq21);
    flag = true;
    for (int i = 0; i < size; i++) {
        if (arrf[i] != seq21.get(i)) {
            flag = false;
            break;
        }
    }
    if (flag)
        std::cout << "Bubble sort int linked sequence success\n";
    else std::cout << "Bubble sort int linked sequence failed\n";
    ArraySequence<float> seq22 = ArraySequence<float>(arr1, size);
    bubbleSort<float> bbsf{};
    bbsf.sort(seq22);
    flag = true;
    for (int i = 0; i < size; i++) {
        if (arr1f[i] != seq22.get(i)) {
            flag = false;
            break;
        }
    }
    if (flag)
        std::cout << "Bubble sort float array sequence success\n";
    else std::cout << "Bubble sort float array sequence failed\n";
    LinkedSequence<float> seq23 = LinkedSequence<float>(arr1, size);
    bbsf.sort(seq23);
    flag = true;
    for (int i = 0; i < size; i++) {
        if (arr1f[i] != seq23.get(i)) {
            flag = false;
            break;
        }
    }
    if (flag)
        std::cout << "Bubble sort float linked sequence success\n";
    else std::cout << "Bubble sort float linked sequence failed\n";
    return 0;
};
