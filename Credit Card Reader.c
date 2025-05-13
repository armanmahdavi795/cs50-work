#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int main()
{
    int dsum = 0, nsum = 0, totsum, x, a, front = 0, result; // visa 1, master 2, amex 3, invalid
                                                             // 4//
    long int crd, i;

    printf("Hello!\n");

    do
    {
        crd = get_long("Please Enter your Credit Card Number Below: ");
        if (!crd)
            result = 5;
        else
            result = 4;
        // integers for some 10^x had to be typed due to many errors coming from use of the pow
        // function//
        if (crd >= 1000000000000 && crd < 10000000000000 && crd / 1000000000000 == 4)
        {
            result = 1;
        }
        else if (crd >= 100000000000000 && crd < 1000000000000000)
        {
            a = crd / pow(10, 13);
            if (a == 34 || a == 37)
                result = 3;
            else
            {
                result = 4;
            }
        }
        else if (crd >= pow(10, 15) && crd < pow(10, 16))
        {
            front = crd / pow(10, 14);
            if (front == 51 || front == 52 || front == 53 || front == 54 || front == 55)
                result = 2;
            else if (front >= 40 && front < 50)
                result = 1;
            else
                result = 4;
        }

        //---------------------------------------------------//
        if (result == 1 || result == 2 || result == 3)
        {
            for (x = 15; x >= 0; x--)
            {
                i = pow(10, x);
                if (x % 2 == 0)
                {
                    nsum = nsum + (crd / i);
                }
                else
                {
                    dsum = dsum + (2 * (crd / i)) / 10 + (2 * (crd / i)) % 10;
                }
                crd = crd % i;
            }
            totsum = dsum + nsum;
        }

        if (totsum % 10 != 0)
            result = 4;
    }
    while (result == 5);

    if (result == 1)
        printf("VISA\n");
    else if (result == 2)
        printf("MASTERCARD\n");
    else if (result == 3)
        printf("AMEX\n");
    else if (result == 4)
        printf("INVALID\n");
    else
        printf("ERROR\n");

    return (0);
}
