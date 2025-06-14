#include <stdio.h>

int mian(void)
{
    int num = 0;

    while (num != 7)
    {
        printf("\n整数を入力してください：");
        scanf("%d", &num);

        if (num == 7) printf("7が入力されました\n");
        else if (num < 7) printf("7より小さいですね\n");
        else printf("7より大きいですね\n");
    }

    printf("\n終了します\n");

    return 0;
    
}