#include<stdio.h>

int main()
{
    int Cockerel, Hen, Chick;
    int Number;
    
    while(scanf("%d", &Number) != EOF)
    {
        for(Cockerel = 0; Cockerel <= 20; Cockerel++)
            for(Hen = 0; Hen <= 33; Hen++)
                for(Chick = 0; Chick <= 100; Chick += 3)
                {
                    if((Cockerel + Hen + Chick == 100) && (5 * Cockerel + 3 * Hen + Chick / 3 == 100))
                        printf("%d %d %d\n", Cockerel, Hen, Chick);
                }
    }
    
    return 0;
}