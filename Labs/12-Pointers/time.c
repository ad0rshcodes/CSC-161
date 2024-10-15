#include <stdio.h>

/**
 * Take in a total number of seconds and split it up into parts
 *
 * \param total_seconds The input number of seconds
 * \param days    Output: the number of whole days in total_seconds
 * \param hours   Output: the number of whole hours in total_seconds
 * \param minutes Output: the number of whole minutes in total_seconds
 * \param seconds Output: the remaining seconds
 */

void split_time(unsigned long total_seconds, unsigned int *days, unsigned int *hours, unsigned int *minutes, unsigned int *seconds)
{
    *days = total_seconds / (24 * 3600);
    total_seconds %= 24 * 3600;

    *hours = total_seconds / 3600;
    total_seconds %= 3600;

    *minutes = total_seconds / 60;
    *seconds = total_seconds % 60;
}

int main()
{
    unsigned int days, hours, minutes, seconds;

    // Example 1: 90061 seconds
    split_time(90061, &days, &hours, &minutes, &seconds);
    printf("90061 seconds = %u days, %u hours, %u minutes, %u seconds\n",
           days, hours, minutes, seconds);

    // Example 2: 1 full day
    split_time(86400, &days, &hours, &minutes, &seconds);
    printf("86400 seconds = %u days, %u hours, %u minutes, %u seconds\n",
           days, hours, minutes, seconds);

    // Example 3: 1 hour, 1 minute, 1 second
    split_time(3661, &days, &hours, &minutes, &seconds);
    printf("3661 seconds = %u days, %u hours, %u minutes, %u seconds\n",
           days, hours, minutes, seconds);

    return 0;
}
