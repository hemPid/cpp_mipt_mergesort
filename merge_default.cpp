#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <math.h>

using i64 = int64_t;
using Array = std::vector<int64_t>;



void Merge(Array::iterator l_begin, Array::iterator l_end, Array::iterator r_begin, Array::iterator r_end, Array::iterator buf) {
    while ((l_begin != l_end) && (r_begin != r_end))
    {
        if (*l_begin < *r_begin)
        {
            *buf = *l_begin;
            ++l_begin;
        } else {
            *buf = *r_begin;
            ++r_begin;
        }
        ++buf;
    }
    while (l_begin != l_end) {
        *buf = *l_begin;
        ++l_begin;
        ++buf;
    }
    while (r_begin != r_end) {
        *buf = *r_begin;
        ++r_begin;
        ++buf;
    }
}

void MergeSortInternal(Array::iterator b, Array::iterator e, Array::iterator buf, size_t size) {
    if ((size==0) || (size==1)) {
        return;
    }
    if (size==2) {
        if (*b > *(b+1))
        {
            std::swap(*b, *(b+1));
        }
        return;
    }
    MergeSortInternal(b, b + size/2, buf, size/2);
    MergeSortInternal(b + size/2, e, buf + size / 2, size - size/2);
    Merge(b, b + size/2, b + size/2, e, buf);
    for (size_t i = 0; i < size; i++)
    {
        *(b+i) = buf[i];
    }
    
}

void MergeSort_default(Array::iterator b, Array::iterator e) {
    size_t size = e-b;
    Array buf(size);
    MergeSortInternal(b, e, buf.begin(), size);
}

void InsertionSort(Array::iterator begin, Array::iterator end) {
    size_t n = end - begin;
    for (size_t i = 0; i < n; ++i)
    {
        for (int j = i; j > 0 && *(begin + j - 1) > *(begin + j) ; --j)
        {
            std::swap(*(begin + j - 1), *(begin + j));
        }
        
    }
    
}


void MergeSortInternal_Insertion(Array::iterator b, Array::iterator e, Array::iterator buf, size_t size) {
    if ((size==0) || (size==1)) {
        return;
    }
    if (size < 10) {
        InsertionSort(b,e);
        return;
    }
    MergeSortInternal_Insertion(b, b + size/2, buf, size/2);
    MergeSortInternal_Insertion(b + size/2, e, buf + size / 2, size - size/2);
    Merge(b, b + size/2, b + size/2, e, buf);
    for (size_t i = 0; i < size; i++)
    {
        *(b+i) = buf[i];
    }
    
}

void MergeSort_Insertion(Array::iterator b, Array::iterator e) {
    size_t size = e-b;
    Array buf(size);
    MergeSortInternal_Insertion(b, e, buf.begin(), size);
}