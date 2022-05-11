#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include <iostream>
#include <vector>

template <typename T> class Vector_t
{
    unsigned capacity;
    unsigned numValues;
    T *pValues;

public:
    Vector_t(unsigned initialCapacity);
    ~Vector_t();

    void PushBack(const T &val);

    unsigned size() const { return numValues; }

    T &getValueAt(unsigned index) const { return pValues[index]; }

    T &operator [] (unsigned index) const { return pValues[index]; }
};

void printValues(const Vector_t<int> &vector)
{
    int j;

    for (j=0; j < vector.size(); ++j)
    {
        printf("%3d", vector[j]);
    }
}

void printValues(const Vector_t<double> &vector)
{
    int j;

    for (j = 0; j < vector.size(); ++j)
    {
        printf("%f", vector[j]);
    }
}

template <typename T> Vector_t<T>::Vector_t(unsigned initialCapacity)
{
    pValues = new T[initialCapacity];

    assert(pValues != NULL);

    capacity = initialCapacity;
    numValues = 0;

    printf("Allocated with initial capacity of %u values\n", initialCapacity);
}

template <typename T> Vector_t<T>::~Vector_t()
{
    delete [] pValues;
}

template <typename T> void Vector_t<T>::PushBack(const T &val)
{
    if (capacity == numValues)
    {
        unsigned newCapacity = (capacity == 0)? 1 : capacity * 2;

        T *pNewValues = new T[newCapacity];
        int j;

        for (j = 0; j < capacity; ++j)
        {
            pNewValues[j] = pValues[j];
        }

        delete [] pValues;
        pValues = pNewValues;
        capacity = newCapacity;

        printf("Reallocated to capacity of %u values\n", newCapacity);
    }

    pValues[numValues++] = val;
}



int main(int argc, char *argv[])
{
    const int iInitialCapacity = (argc > 1)? atoi(argv[1]): 10;
    Vector_t<int> vec1(iInitialCapacity);
    //Vector_t<double> vec2(iInitialCapacity);
    //std::vector<int> vec3(4,99);

    int j =4, k = 6;
    int &ref = j;
    ref = k;

    for (j=0; j < 16; ++j)
    {
        vec1.PushBack(j * 2);
    }

    vec1[3] = 99;

    printValues(vec1);

    printf("\n");
    return 0;
}