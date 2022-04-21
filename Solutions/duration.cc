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

    if (pValue->seconds + other.seconds >=60)
    {
        pValue->seconds = pValue->seconds + other.seconds - 60;
        pValue->minutes ++;
    }
    else
    {
        pValue->seconds = pValue->seconds + other.seconds;
    }

    /*
    An alternative way of doing the above:

    */
}

void roundToMinutes(Duration_t *pValue)
{
    if (pValue->seconds > 30)
    {
        pValue->minutes++;
    }

    pValue->seconds = 0;
}

/* Alternative to the roundToMinute function above but with 
different input and outputs
Duration_t roundToMinutes(Duration_t value)
{

}
*/

int main(int argc, char *argv[])
{
    Duration_t dur1 = {2, 45};
    Duration_t dur2;

    dur2.minutes = 1;
    dur2.seconds = 53;

    Duration_IncrementsBy(&dur2, dur1);
    //alternatively dur2 += dur1;

    roundToMinutes(&dur1);

    cout << "durations 2 " << dur2.minutes << ":" << dur2.seconds << "\n";
    cout << "durations 1 " << dur1.minutes << ":" << dur1.seconds << "\n";
}