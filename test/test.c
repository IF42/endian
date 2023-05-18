#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include <limits.h>
#include <stdbool.h>

#include "../src/endian.h"

#define TEST_CYCLE 1000

void
int16_test(void)
{
    uint16_t value = rand() % USHRT_MAX;

    printf("endian_swap_int16 - ");

    for(size_t i = 0; i < TEST_CYCLE; i++)
    {
        uint16_t double_swap_value = endian_swap(endian_swap(value));

        if(value != double_swap_value)
        {
            printf("FAIL (%ld) %x != %x\n", i, value, double_swap_value);
            return;
        }
    }

    printf("PASS\n");
}


void
int32_test(void)
{
    uint32_t value = rand() % UINT_MAX;

    printf("endian_swap_int32 - ");

    for(size_t i = 0; i < TEST_CYCLE; i++)
    {
        uint32_t double_swap_value = endian_swap(endian_swap(value));

        if(value != double_swap_value)
        {
            printf("FAIL (%ld) %x != %x\n", i, value, double_swap_value);
            return;
        }
    }

    printf("PASS\n");
}


void
float_test(void)
{
    float value = rand() % UINT_MAX;

    printf("endian_swap_int32 (float) - ");

    for(size_t i = 0; i < TEST_CYCLE; i++)
    {
        float double_swap_value = endian_swap(endian_swap(value));

        if(value != double_swap_value)
        {
            printf("FAIL (%ld) %x != %x\n", i, (uint32_t) value, (uint32_t) double_swap_value);
            return;
        }
    }

    printf("PASS\n");
}


void
int64_test(void)
{
    uint64_t value = rand() % ULONG_MAX;

    printf("endian_swap_int64 - ");

    for(size_t i = 0; i < TEST_CYCLE; i++)
    {
        uint64_t double_swap_value = endian_swap(endian_swap(value));

        if(value != double_swap_value)
        {
            printf("FAIL (%ld) %lx != %lx\n", i, value, double_swap_value);
            return;
        }
    }

    printf("PASS\n");
}


void
double_test(void)
{
    double value = rand() % ULONG_MAX;

    printf("endian_swap_int64 (double) - ");

    for(size_t i = 0; i < TEST_CYCLE; i++)
    {
        double double_swap_value = endian_swap(endian_swap(value));

        if(value != double_swap_value)
        {
            printf("FAIL (%ld) %lx != %lx\n", i, (uint64_t) value, (uint64_t) double_swap_value);
            return;
        }
    }

    printf("PASS\n");
}


int
main(void)
{
    float t = 10.1;

    //printf("%f : %f : %f\n", t, (float)endian_swap_int32((int32_t)t), (float)endian_swap_int32(endian_swap_int32((int)(t))));
    
    printf("%f : %f : %f\n", t, (float) endian_swap(t), (float)endian_swap(endian_swap(t)));

    int16_test();
    int32_test();
    float_test();
    int64_test();
    double_test();

    return EXIT_SUCCESS;
}
