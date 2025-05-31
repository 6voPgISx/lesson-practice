#include <stdio.h>

int main(void)
{

    char moji;
    char mojiretuse[11];

    printf("文字を入力してください：");
    scanf("%c", &moji);
    printf("入力した文字は%cです\n", moji);

    printf("文字列を入力してください：");
    scanf("%s", mojiretuse);
    printf("入力した文字列は%sです\n", mojiretuse);

    return 0;
}