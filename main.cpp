#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include <math.h>
#include <fstream>
#include "merge_default.h"

using i64 = int64_t;
using Array = std::vector<i64>;

void test(i64 n) {
    Array a1(n);
    Array a2(n);
    Array a3(n);
    Array a4(n);
    Array a5(n);
    std::ofstream def, ins;
    def.open("default.txt", std::ios::app);
    ins.open("insert.txt", std::ios::app);
    auto rnd = std::default_random_engine {};
    for (i64 i = 0; i < n; ++i)
    {
        a1[i] = i;
        a2[i] = i;
        a3[i] = i;
        a4[i] = i;
        a5[i] = i;
    }
    std::shuffle(a1.begin(), a1.end(), rnd);
    a2 = a1;
    a3 = a1;
    a4 = a1;
    a5 = a1;
    auto start = std::chrono::steady_clock::now();
    MergeSort_default(a1.begin(), a1.end());
    MergeSort_default(a2.begin(), a2.end());
    MergeSort_default(a3.begin(), a3.end());
    MergeSort_default(a4.begin(), a4.end());
    MergeSort_default(a5.begin(), a5.end());
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;
    if (def.is_open())
    {
        def << n << " " << elapsed_seconds.count()/5 << std::endl;
    }
    std::shuffle(a1.begin(), a1.end(), rnd);
    a2 = a1;
    a3 = a1;
    a4 = a1;
    a5 = a1;
    start = std::chrono::steady_clock::now();
    MergeSort_Insertion(a1.begin(), a1.end());
    MergeSort_Insertion(a2.begin(), a2.end());
    MergeSort_Insertion(a3.begin(), a3.end());
    MergeSort_Insertion(a4.begin(), a4.end());
    MergeSort_Insertion(a5.begin(), a5.end());
    end = std::chrono::steady_clock::now();
    elapsed_seconds = end-start;
    if (ins.is_open())
    {
        ins << n << " " << elapsed_seconds.count()/5 << std::endl;
    }
    def.close();
    ins.close();
}

int main() {
    i64 from = 0;
    i64 to = 0;
    i64 d = 0;
    std::cin >> from >> to >> d;
    for (i64 i = from; i <= to; i+=d)
    {
        test(i);
    }
    return 0;
}