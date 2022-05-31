#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

/* 获取系统当前时间用于记录日志 */
void getSysRealTime(void)
{
    time_t current_time;
    struct tm* now_time;
    char cur_time[100];

    current_time = time(NULL);
    now_time = localtime(&current_time);

    strftime(cur_time, sizeof(cur_time), "%Y-%m-%d %H:%M:%S", now_time);

    printf("%s: ", cur_time);
}

//交换两个数的位置
void swap(int* x, int* y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}

//对生成的随机数进行排序
void Bubble_Sort(int Arr[], int Len) {
	int Count1 = 0, Count2 = 0;
	int flag = 1;//交换标记，如果一趟排序过程没有发生交换则退出排序

	for (Count1 = 0; Count1 < Len - 1; Count1++) {
		flag = 1;
		for (Count2 = 0; Count2 < Len - Count1 - 1; Count2++) {
			if (Arr[Count2] > Arr[Count2 + 1]) {
				swap(&Arr[Count2], &Arr[Count2 + 1]);
				flag = 0;
			}
		}
		if (flag == 1) {
			break;
		}
	}
}

int main()
{
    int i, j, k, first_do;
    int lottery[5][7];
    FILE *out;
    char once_again, ch;

    getSysRealTime();
    printf("恭喜您获得人民币500万元,系统正在为您打款...\n");

    first_do = 1;//设置第一次运行为真
    once_again = 'N';//默认程序只运行一次
    do{
        //产生随机数并去重
        memset(lottery, 0, sizeof(lottery));
        for (i = 0; i < 5; i++) {
            srand((unsigned)time(NULL));
            for (j = 0; j < 6; j++) {
                lottery[i][j] = rand() % 33 + 1;
                if (j > 0) {//去重
                    k = j;
                    while (k > 0) {
                        if (lottery[i][j] == lottery[i][k - 1]) {
                            lottery[i][j] = rand() % 33 + 1;
                            k = j; //把k重置为传入时的j的值全部进行重新比较
                        } else {
                            k--;
                        }
                    }
                }
            }
            lottery[i][j] = rand() % 16 + 1;
            sleep(3);
        }

        for (i = 0; i < 5; i++) {
            Bubble_Sort(lottery[i], 6);
        }

        //打开小陈和小喻中了500万.txt文件
        if (first_do == 1) {
            out = fopen("小陈和小喻中了500万.txt", "w");
        } else {
            out = fopen("小陈和小喻中了500万.txt", "a");
        }
        if (out == NULL) {
            getSysRealTime();
            printf("Error: 打开文件失败,程序退出。\n");
            return -1;
        }

        //将结果写入文件小陈和小喻中了500万.txt
        for (i = 0; i < 5; i++) {
            for (j = 0; j < 5; j++) {
                fprintf(out, "%-2d\t", lottery[i][j]);
            }
            fprintf(out, "%-2d---%-2d\n", lottery[i][j], lottery[i][j + 1]);
        }
        for (i = 0; i < 25; i++) {
            fprintf(out, "-");
        }
        fprintf(out, "\n");

        getSysRealTime();
        printf("第%d个500万元人民币已到账,请在\"小陈和小喻中了500万.txt\"中查看结果。\n", first_do);

        //关闭文件小陈和小喻中了500万.txt
        fclose(out);
        getSysRealTime();
        printf("请问需要再打500万元给您么？\n");
        getSysRealTime();
        printf("请输入您的选择...\n");
        getSysRealTime();
        printf("Y---实在是还差点儿\tN---我知足了\n");
        scanf("%c", &once_again);
        while ((ch = getchar()) != EOF && ch != '\n') {
            ;
        }
        if (once_again == 'Y') {
            if (first_do % 5 == 0) {
                getSysRealTime();
                printf("已向您打款%d个500万,真的不够么？知足常乐哦!!!\n", first_do);
                getSysRealTime();
                printf("请确认您的选择: Y---实在是还差点儿\tN---我知足了\n");
                scanf("%c", &once_again);
                 while ((ch = getchar()) != EOF && ch != '\n') {
                    ;
                 }
                if (once_again == 'Y') {
                    first_do++;
                } else {
                    getSysRealTime();
                    printf("您是一个知足惜福的人,福报必厚。\n");
                    getSysRealTime();
                    printf("3秒后程序将自动退出。\n");
                }
            } else {
                first_do++;
            }
        } else {
            getSysRealTime();
            printf("您是一个知足惜福的人,福报必厚。\n");
            getSysRealTime();
            printf("3秒后程序将自动退出。\n");
        }
    } while(once_again == 'Y');

    sleep(3);

    return 0;
}
