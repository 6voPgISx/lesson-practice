// #include <stdio.h>
// #include <stdlib.h>

// int main(void)
// {
//     int ransu, i;

//     printf("0 ~ %d 間の値をランダムに10個表示\n\n", RAND_MAX);

//     i = 1;
//     while (i <= 10)
//     {
//         ransu = rand();
//         printf("%d番目の値%d\n", i, ransu);
//         i++;
//     }

//     return 0;
    
// }

// int main(void)
// {
//     int ransu, i;

//     printf("0 ~ 6 間の値をランダムに10個表示\n\n");

//     i = 1;
//     while (i <= 10)
//     {
//         ransu = rand()%6 + 1;
//         printf("%d番目の値%d\n", i, ransu);
//         i++;
//     }

//     return 0;
    
// }

// #include <stdio.h>
// #include <stdlib.h>

// int main(void)
// {
//     int ransu, i;

//     printf("0 ~ %d 間の値をランダムに10個表示\n\n", RAND_MAX);

//     i = 1;
//     while (i <= 10)
//     {
//         ransu = rand();
//         printf("%d番目の値%d\n", i, ransu);
//         i++;
//     }

//     return 0;
    
// }

// int main(void)
// {
//     int seed, ransu, i;

//     printf("乱数のタネを入力してください：");
//     scanf("%d", &seed);
//     srand(seed);
//     printf("\n%d の値を元にした擬似乱数を計算して表示\n\n", seed);

//     i = 1;
//     while (i <= 10)
//     {
//         ransu = rand()%6 + 1;
//         printf("%d番目の値%d\n", i, ransu);
//         i++;
//     }

//     return 0;
    
// }

// #include <stdio.h>
// #include <stdlib.h>
// #include <time.h>

// int main(void)
// {
//     int ANSWER, num = 0, continue_game = 1;

//     srand(time(NULL));

//     while (continue_game)
//     {
//         printf("\n=== 数当てゲーム ====\n");

//         ANSWER = rand() % 6 + 1;

//         while (1)
//         {
//         printf("\n整数を入力してください：");
//         scanf("%d", &num);

//         if (num == ANSWER)
//         {
//             printf("そう！%dが正解\n", num);
//             break;
//         } 
//         else if (num < ANSWER)
//             printf("はずれ。それより大きいよ\n");
//         else 
//             printf("はずれ。それより小さいよ\n");

//         }

//         printf("\nゲームを続けますか？(続ける：1  終了：0)：");
//         scanf("%d", &continue_game);
//     }

//     printf("\n終了します\n");

//     return 0;
    
// }

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int ANSWER, num = 0, continue_game = 1, i;

    srand(time(NULL));

    while (continue_game)
    {
        printf("\n◇◇ 数当てゲーム ◇◇\n数を当ててね。チャンスは　5回　まで！");

        ANSWER = rand() % 13 + 1;
        i = 1;


        while (1)
        {
            printf("\n＝＝　%d回目のチャレンジ　＝＝\n", i);

            printf("1〜13のどれでしょう：");
            scanf("%d", &num);

            if (i < 5)
            {               
                if(num == ANSWER)
                {
                    printf("当たり。%d回目で正解！\n", i);
                    break;
                } 
                else if (num < ANSWER)
                    printf("はずれ。それより大きいよ\n");
                else 
                    printf("はずれ。それより小さいよ\n");
            }
            else
            {
                if(num == ANSWER)
                {
                    printf("当たり。%d回目で正解！\n", i);
                    break;
                } 
                else
                {   
                    printf("\n残念。5回で当てられなかったのでゲームオーバー。\n答えは「%d」でした。\n", ANSWER);
                    break;
                }    
            }

            i++;           
        }

        printf("\nゲームを続けますか？(続ける：1  終了：0)：");
        scanf("%d", &continue_game);
    }

    printf("\n終了します\n");

    return 0;
    
}