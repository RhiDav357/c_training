#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <assert.h>

using namespace std;

typedef int Value_t;

typedef struct VarArray
{
    unsigned capacity;
    Value_t *pValues;
} VarArray_t;

void printValues(VarArray_t *pVarArray)
{
 int i;
 for (i=0; i < pVarArray->capacity; i++)
 {
    cout << *(pVarArray->pValues + i) << "\n";
 }
}

void VarArray_Create(VarArray_t *pVarArray, unsigned numValues)
{
    pVarArray->pValues = (Value_t *) malloc(numValues * sizeof(Value_t));

    assert(pVarArray->pValues != NULL);

    pVarArray->capacity = numValues;
}

void VarArray_Destroy(VarArray_t *pVarArray)
{
    free(pVarArray->pValues);
    pVarArray->pValues = NULL;
    pVarArray->capacity = 0;
}

void subtractThree(int *piValue)
{
    *piValue -= 3;
}

int main(int argc, char *argv[])
{
    const int iArraySize = (argc > 1)? atoi(argv[1]): 16;
    VarArray_t varray;
    int i;

    varray.capacity = 0;
    varray.pValues = NULL;

    VarArray_Create(&varray, iArraySize);

    for (i = 0; i < varray.capacity; i++)
    {
        varray.pValues[i] = 2 * i;
    }

    for (i = 0; i < varray.capacity; i++)
    {
        subtractThree(&varray.pValues[i]);
    }

    printValues(&varray);

    VarArray_Destroy(&varray);

    return 0;
}