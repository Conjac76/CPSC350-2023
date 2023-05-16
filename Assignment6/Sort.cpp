#include "Sort.h"

Sort::Sort(DblList<double> unsortedDoubles) {
    for(int i = 0; i < unsortedDoubles.getSize(); i++) {
        mUnsortedDoubles1.insertBack(unsortedDoubles.getAt(i));
        mUnsortedDoubles2.insertBack(unsortedDoubles.getAt(i));
        mUnsortedDoubles3.insertBack(unsortedDoubles.getAt(i));
        mUnsortedDoubles4.insertBack(unsortedDoubles.getAt(i));
        mUnsortedDoubles4.insertBack(unsortedDoubles.getAt(i));
    }
}

Sort::~Sort() {

}

void Sort::quickSort() {
    std::clock_t start, end;
    start = std::clock();

    
    quickSortHelper(mUnsortedDoubles2, 0, mUnsortedDoubles2.getSize() - 1);

    end = std::clock();

    std::cout << "Quicksort Start Time: " << start << "\nQuickSort End Time: "<< end << std::endl;
}

void Sort::quickSortHelper(DblList<double>& list, int low, int high) {
    if (low < high) {
        int pivotIndex = partition(list, low, high);

        quickSortHelper(list, low, pivotIndex - 1);
        quickSortHelper(list, pivotIndex + 1, high);
    }
}

int Sort::partition(DblList<double>& list, int low, int high) {
    double pivot = list.getAt(high); 
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (list.getAt(j) <= pivot) {
            i++;
            swap(list, i, j);
        }
    }

    swap(list, i + 1, high);  
    return i + 1;
}

void Sort::swap(DblList<double>& list, int index1, int index2) {
    double temp = list.getAt(index1);
    list.getAt(index1) = list.getAt(index2);
    list.getAt(index2) = temp;
}




void Sort::mergeSort() {
    std::clock_t start, end;
    start = std::clock();

    mUnsortedDoubles1 = mergeSortHelper(mUnsortedDoubles1);

    end = std::clock();

    std::cout << "Merge Sort Start Time: " << start << "\n" << "Merge Sort End Time: " << end << std::endl;
}

DblList<double> Sort::mergeSortHelper(const DblList<double>& list) {
    if (list.getSize() <= 1) {
        return list;
    }

    int mid = list.getSize() / 2;
    DblList<double> leftHalf;
    DblList<double> rightHalf;

    for (int i = 0; i < mid; i++) {
        leftHalf.insertBack(list.getAt(i));
    }
    for (int i = mid; i < list.getSize(); i++) {
        rightHalf.insertBack(list.getAt(i));
    }

    leftHalf = mergeSortHelper(leftHalf);
    rightHalf = mergeSortHelper(rightHalf);

    return merge(leftHalf, rightHalf);
}

DblList<double> Sort::merge(const DblList<double>& left, const DblList<double>& right) {
    DblList<double> mergedList;

    int leftIndex = 0;
    int rightIndex = 0;

    // Merge the two sorted lists
    while (leftIndex < left.getSize() && rightIndex < right.getSize()) {
        double leftValue = left.getAt(leftIndex);
        double rightValue = right.getAt(rightIndex);

        if (leftValue <= rightValue) {
            mergedList.insertBack(leftValue);
            leftIndex++;
        } else {
            mergedList.insertBack(rightValue);
            rightIndex++;
        }
    }

    while (leftIndex < left.getSize()) {
        mergedList.insertBack(left.getAt(leftIndex));
        leftIndex++;
    }

    while (rightIndex < right.getSize()) {
        mergedList.insertBack(right.getAt(rightIndex));
        rightIndex++;
    }

    return mergedList;
}
