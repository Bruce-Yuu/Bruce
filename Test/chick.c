/*
***公元前五世纪，我国古代数学家张丘建在《算经》一书
***中提出了“百鸡问题”：鸡翁一值钱五，鸡母一值钱三，
***鸡雏三值钱一。百钱买百鸡，问鸡翁、鸡母、鸡雏各几何？
*/
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