/* Generate ASCII Values all numbers */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i=0;

    while(i<255)
    {
        printf("\n \a %d = %c ",i,i);
        i=i+1;
    }
    getchar();
    return 0;
}
