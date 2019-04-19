#include "util/Functions.h"

namespace functions
{
    float clamp(float n, float min, float max)
    {
        if (n < min) return min;
        else if (n > max) return max;
        else return n;
    }

    float normalize(float n)
    {
        return clamp(n, -1.0f, 1.0f);
    }
}