#include <cs50.h>
#include <stdio.h>

void adjpyr(int num)
{
    int i, x = 0, a;
    for (a = num; a > 0; a--)
    {

        for (i = a - 1; i > 0; i--)
        {
            printf(" ");
        }
        for (x = a; x <= num; x++)
        {
            printf("#");
        }
        printf("  ");
        for (x = a; x <= num; x++)
        {
            printf("#");
        }
        printf("\n");
    }
}

int main()
{
    int num;

    do
    {
        num = get_int("Enter Pyramid Height From 1 To 8: ");
    }
    while (num > 8 || num < 1);

    adjpyr(num);

    return (0);
}
