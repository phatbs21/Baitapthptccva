#include "stdio.h"
int main()
{
    char ai[300000], chu;
    int i, j, k, sum;
    scanf("%s", ai);
    for (i = 0; ai[i] != '\0'; i++)
    {
        sum = 1;
        j = i;
        while (ai[i] == ai[i + 1])
        {
            sum++;
            i++;
        }
        for (k = j + 1; k <= i; k = k + 2)
        {
            chu = 'a';
            ai[k] = chu;
            while (ai[k] == ai[k + 1] || ai[k] == ai[k - 1])
            {
                chu++;
                ai[k] = chu;
            }
        }
    }
    printf("%s\n", ai);
    return 0;
}
