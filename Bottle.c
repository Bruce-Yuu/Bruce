#include<stdio.h>

void main()
{
    int n;
    int total;
    
    while(scanf("%d", &n) && n)
    {
        total = 0;

        if(n == 1)
            total = 0;
        else if(n == 2)
            total = 1;
        else
        {
            while(n / 3)
            {
                total = total + n / 3;
                n = n / 3 + n % 3;
            }
            if(n % 3 == 2)
                total = total + 1;
        }

        printf("%d\n", total);
    }
}