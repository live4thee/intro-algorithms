#ifndef SORTING_H__
#define SORTING_H__

#include <assert.h>
#include <time.h>
#include <stdlib.h>

namespace sorting {

template<typename T>
void qsort(T* base, size_t nmemb,
           int (*compare)(const T& lhs, const T& rhs));

static unsigned this_seed = (unsigned)time(NULL);

/**
 * The partitioning step, returning the final index of the pivot.
 *
 * Prerequisite: nmemb >= 1
 */
template<typename T>
size_t qs_partition(T* base, size_t nmemb,
                    int (*compare)(const T& lhs, const T& rhs))
{
    const size_t pidx = rand_r(&this_seed) % nmemb;
    const T     pivot = base[pidx];

    assert(nmemb >= 1);
    // move the pivot to the last element
    std::swap(base[nmemb - 1], base[pidx]);

    size_t i = -1;
    for (size_t j = 0; j < nmemb - 1; ++j)
    {
        if (compare(base[j], pivot) < 0)
        {
            i += 1;
            std::swap(base[i], base[j]);
        }
    }

    const size_t pividx = i + 1;
    std::swap(base[pividx], base[nmemb - 1]);
    assert(base[pividx] == pivot);

    return pividx;
}

template<typename T>
void qsort(T* base, size_t nmemb,
           int (*compare)(const T& lhs, const T& rhs))
{
    if (nmemb > 1)
    {
        size_t p = qs_partition(base, nmemb, compare);
        if (p > 1)
        {
            qsort(base, p, compare);
        }
        qsort(base+p+1, nmemb-p-1, compare);
    }
}

}

#endif

/* vim: set ts=4 sw=4 cin et: */
