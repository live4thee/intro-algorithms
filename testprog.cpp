#include <iostream>
#include "sorting.h"

#ifndef ARRAY_SIZE
#define ARRAY_SIZE(a) (sizeof(a)/sizeof(a[0]))
#endif

template<typename T>
void print_array(const T* base, size_t nmemb)
{
    for (size_t i = 0; i < nmemb; ++i)
        std::cout << base[i] << ' ';
    std::cout << std::endl;
}

static int cmp(const int& a, const int& b)
{
    if (a < b) return -1;
    if (a > b) return 1;
    return 0;
}

template <typename T>
static void sort_and_show(T* a, size_t nmemb,
                          int (*cmp)(const T&, const T&))
{
    print_array(a, nmemb);
    sorting::qsort(a, nmemb, cmp);
    print_array(a, nmemb);
}

int main(void)
{
    int a[] = { 2, 7, 5, 8, 9, 6, 3, 4, 1 };
    int b[] = { 2, 7 };
    int c[] = { 2 };

    sort_and_show<int>(a, ARRAY_SIZE(a), cmp);
    sort_and_show<int>(b, ARRAY_SIZE(b), cmp);
    sort_and_show<int>(c, ARRAY_SIZE(c), cmp);

    return 0;
}

/* vim: set ts=4 sw=4 cin et: */
