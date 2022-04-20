#include <iostream>

using namespace std;

typedef int value_t;

void printValues(int aiVals[], int numVals)
{
    int j;

    for (j = 0; j < numVals; ++j)
    {
        cout << aiVals[j] << " ";
    }
}

void addThree(int aiVals[], int numVals)
{
    int j;

    for (j = 0; j < numVals; j++)
    {
        aiVals[j] += 3;
    }
}

void addFour(int *pValues, unsigned numValues)
{
    int j;

    for (j = 0; j < numValues; j++)
    {
        *(pValues + j) += 4;
    }
}

void subtractSix(int *piVal)
{
    *piVal -= 6;
}

int main( int argc, char *argv[])
{
    const int NUM_VALUES = 10;
    int aiValues[NUM_VALUES];
    int j;

    for (j = 0; j < NUM_VALUES; ++j)
    {
        aiValues[j] = j * 2;
    }

    addThree(aiValues, NUM_VALUES);

    for (j = 0; j < NUM_VALUES; ++j)
    {
        subtractSix(&aiValues[j]);
    }

    addFour(aiValues, NUM_VALUES);

    printValues(aiValues, NUM_VALUES);

    cout << "\n";
    return 0;
}

