#ifndef SORT_H
#define SORT_H
#include "IO.h"
#include "DBLlist.h"

class Sort {
    public:
        Sort(DblList<double> unsortedDoubles);
        ~Sort();
        void mergeSort();
        void quickSort();
        


    private:
        DblList<double> mergeSortHelper(const DblList<double>& list);
        DblList<double> merge(const DblList<double>& left, const DblList<double>& right);
        void quickSortHelper(DblList<double>& list, int low, int high);
        int partition(DblList<double>& list, int low, int high);
        void swap(DblList<double>& list, int index1, int index2);




        DblList<double> mUnsortedDoubles1;
        DblList<double> mUnsortedDoubles2;
        DblList<double> mUnsortedDoubles3;
        DblList<double> mUnsortedDoubles4;
        DblList<double> mUnsortedDoubles5;
};

#endif