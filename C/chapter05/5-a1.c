#include <stdio.h>

int main(void)
{
    int score;

    printf("点数を入力して下さい：");
    scanf("%d", &score);

    if(score == 100) printf("合格\n");
    else printf("不合格\n");

    return 0;
}