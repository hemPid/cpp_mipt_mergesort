#ifndef merge_default
#define merge_default
void InsertionSort(std::vector<__int64>::iterator begin, std::vector<__int64>::iterator end);
void MergeSort_default(std::vector<__int64>::iterator b, std::vector<__int64>::iterator e);
void MergeSortInternal(std::vector<__int64>::iterator b, std::vector<__int64>::iterator e, std::vector<__int64>::iterator buf, size_t size);
void Merge(std::vector<__int64>::iterator l_begin, std::vector<__int64>::iterator l_end, std::vector<__int64>::iterator r_begin, std::vector<__int64>::iterator r_end, std::vector<__int64>::iterator buf);
void MergeSort_Insertion(std::vector<__int64>::iterator b, std::vector<__int64>::iterator e);
void MergeSortInternal_Insertion(std::vector<__int64>::iterator b, std::vector<__int64>::iterator e, std::vector<__int64>::iterator buf, size_t size);
#endif