#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    int i, lvl;
    double lavg, savg, gindex, lcount = 0, wcount = 1, scount = 0;

    printf("Hello!\n");
    string txt = get_string("Please enter your text below: \n");
    for (i = 0; i <= strlen(txt); i++)
    {
        if (txt[i] == ' ')
            wcount++;
        else if (txt[i] == '.' || txt[i] == '!' || txt[i] == '?')
            scount++;
        else if (isalpha(txt[i]))
            lcount++;
    }

    lavg = lcount / (wcount / 100);
    savg = scount / (wcount / 100);

    gindex = 0.0588 * lavg - 0.296 * savg - 15.8;

    lvl = round(gindex);

    if (lvl < 1)
        printf("\nBefore Grade 1\n");
    else if (lvl > 16)
        printf("\nGrade 16+\n");
    else
        printf("\nGrade %i\n", lvl);

    return 0;
}
