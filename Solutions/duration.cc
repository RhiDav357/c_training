#include <iostream>

using namespace std;

typedef struct Duration Duration_t;

struct Duration
{
    int minutes;
    int seconds;
};

void Duration_IncrementsBy(Duration_t *pValue, Duration_t other)
{
    pValue->minutes = pValue->minutes + other.minutes;


}