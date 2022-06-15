#include <stdio.h>
#include <stdlib.h>

#include <assert.h>

#ifndef NDEBUG // in debug mode
#define DEBUG
#endif

// #define USE_ASSERT

int function(int val)
{
    return val * 2;
}

int main()
{
#if defined(DEBUG) && defined(USE_ASSERT)
    // #ifdef DEBUG
    assert(function(2) == 5);
#endif

    return 0;
}
