#include <iostream>
#include <chrono>
#include <stdlib.h>
#include "Sequence.h"
#include "ArraySequence.h"
#include "LinkedSequence.h"
#include "Sorts.h"

using namespace std::chrono;

/*
 * Сделать массив sorter и массив назвыний сортировок, заменить систему с case на систему через массивы
 * Зациклить меню
 * Сделать выбор типа данных: linkedSequence или arraySequence
 */

int main() {
    unsigned int amount;
    int choice = -1;
    int type;
    unsigned int maxAmount;
    Sorter<int> *sorts[6];
    std::string sortNames[6];
    bubbleSort<int> bs{};
    insertSort<int> ins{};
    choiceSort<int> chs{};
    quickSort<int> qs{};
    heapSort<int> hs{};
    shellSort<int> shs{};
    sorts[0] = &bs;
    sorts[1] = &ins;
    sorts[2] = &chs;
    sorts[3] = &qs;
    sorts[4] = &hs;
    sorts[5] = &shs;
    sortNames[0] = "Bubble sort";
    sortNames[1] = "Insert sort";
    sortNames[2] = "Choice sort";
    sortNames[3] = "Quick sort";
    sortNames[4] = "Heap sort";
    sortNames[5] = "Shell sort";
    std::cout << "Input maximum amount of elements for printing:\n";
    std::cin >> maxAmount;
    while (choice != 0) {
        std::cout << "Choose sort type:\n";
        std::cout << "1 - Bubble sort\n";
        std::cout << "2 - Insert sort\n";
        std::cout << "3 - Choice sort\n";
        std::cout << "4 - Quick sort\n";
        std::cout << "5 - Heap sort\n";
        std::cout << "6 - Shell sort\n";
        std::cout << "0 - Exit\n";
        std::cin >> choice;
        if (choice == 0)
            break;
        std::cout << "Input element amount:\n";
        std::cin >> amount;
        int *randomArray = new int[amount];
        for (int i = 0; i < amount; i++) {
            randomArray[i] = rand();
        }
        if (amount < maxAmount) {
            for (int i = 0; i < amount; i++) {
                std::cout << randomArray[i] << " ";
            }
            std::cout << "\n";
        } else {
            for (int i = 0; i < maxAmount; i++) {
                std::cout << randomArray[i] << " ";
            }
            std::cout << "\n";
        }
        std::cout << "\n";
        Sequence<int> *seq;
        std::cout << "Choose sequence type:\n";
        std::cout << "1 - Array sequence\n";
        std::cout << "2 - Linked list sequence\n";
        std::cin >> type;
        std::string name;
        if (type == 1) {
            seq = new ArraySequence<int>(randomArray, amount);
            name = "array sequence";
        } else if (type == 2) {
            seq = new LinkedSequence<int>(randomArray, amount);
            name = "linked sequence";
        }
        steady_clock::time_point begin = steady_clock::now();
        sorts[choice - 1]->sort(*seq);
        steady_clock::time_point end = steady_clock::now();

        std::cout << sortNames[choice - 1] << " for " << name << " took "
                  << duration_cast<milliseconds>(end - begin).count() << " milliseconds ("
                  << duration_cast<microseconds>(end - begin).count() << ") microseconds)\n";
        if (amount < maxAmount) {
            seq->out();
        } else {

        }
        delete (seq);
    }
}
