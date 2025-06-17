// #include <stdio.h>

// int main(void)
// {
//     int i;

//     for(i = 1; i <= 10; i++)
//     {
//         printf("%d ", i);
//     }

//     printf("\nfor文の繰り返し終了\n");

//     return 0;
// }

// #include <stdio.h>

// int main(void)
// {
//     int yi, xi;

//     for(yi = 1; yi <= 9; yi++)
//     {
//         printf("%dの段 |", yi);

//         for(xi = 1; xi <= 9; xi++)
//         {
//             printf("%dx%d = %d ", yi, xi, yi*xi);
//         }
//         printf("\n");
//     }

//     printf("\n\t\t\t==== 掛け算　九九表 ===\n");

//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int level, ANSWER, num = 0, continue_game = 1, i;
    srand(time(NULL));

    while (1)
    {
        printf("◇◇ 数当てゲーム ◇◇\n");
        printf("1：初級 サイコロ数当て\n");
        printf("2：中級 トランプ数当て\n");
        printf("3：上級 百までの数当て\n");
        printf("レベルを選んでね(1~3以外で終了)：");

        scanf("%d", &level);

        switch (level)
        {
        case 1:
            continue_game = 1;
            while (continue_game)
            {
                printf("\n◇◇ 初級 サイコロ数当て ◇◇\n数を当ててね。チャンスは 3回 まで！");

                ANSWER = rand() % 6 + 1;
                i = 1;


                while (i <= 3)
                {
                    printf("\n＝＝　%d回目のチャレンジ　＝＝\n", i);

                    printf("1〜6のどれでしょう：");
                    scanf("%d", &num);
                    
                    if(num == ANSWER)
                    {
                        printf("当たり。%d回目で正解！\n", i);
                        break;
                    } 
                    else if (num < ANSWER)
                        printf("はずれ。それより大きいよ\n");
                    else 
                        printf("はずれ。それより小さいよ\n");

                    i++;
                }
                
                if(i > 3)
                {
                    printf("\n残念。3回で当てられなかったのでゲームオーバー。\n答えは「%d」でした。\n", ANSWER);
                }    
            
                printf("\n初級 サイコロ数当てゲームを続けますか？(続ける：1  終了：0)：");
                scanf("%d", &continue_game);
            }

            break;
        case 2:
            continue_game = 1;
            while (continue_game)
            {
                printf("\n◇◇ 中級 トランプ数当て ◇◇\n数を当ててね。チャンスは 5回 まで！");

                ANSWER = rand() % 13 + 1;
                i = 1;


                while (i <= 5)
                {
                    printf("\n＝＝　%d回目のチャレンジ　＝＝\n", i);

                    printf("1〜13のどれでしょう：");
                    scanf("%d", &num);
                    
                    if(num == ANSWER)
                    {
                        printf("当たり。%d回目で正解！\n", i);
                        break;
                    } 
                    else if (num < ANSWER)
                        printf("はずれ。それより大きいよ\n");
                    else 
                        printf("はずれ。それより小さいよ\n");

                    i++;
                }
                
                if(i > 5)
                {
                    printf("\n残念。5回で当てられなかったのでゲームオーバー。\n答えは「%d」でした。\n", ANSWER);
                }    
            
                printf("\n中級 トランプ数当てゲームを続けますか？(続ける：1  終了：0)：");
                scanf("%d", &continue_game);
            }
            
            break;

        case 3:
            continue_game = 1;
            while (continue_game)
            {
                printf("\n◇◇ 上級 百までの数当て ◇◇\n数を当ててね。チャンスは 7回 まで！");

                ANSWER = rand() % 100 + 1;
                i = 1;

                while (i <= 7)
                {
                    printf("\n＝＝　%d回目のチャレンジ　＝＝\n", i);

                    printf("1〜100のどれでしょう：");
                    scanf("%d", &num);
                    
                    if(num == ANSWER)
                    {
                        printf("当たり。%d回目で正解！\n", i);
                        break;
                    } 
                    else if (num < ANSWER)
                        printf("はずれ。それより大きいよ\n");
                    else 
                        printf("はずれ。それより小さいよ\n");

                    i++;
                }
                
                if(i > 7)
                {
                    printf("\n残念。7回で当てられなかったのでゲームオーバー。\n答えは「%d」でした。\n", ANSWER);
                }    
            
                printf("\n上級 百までの数当てゲームを続けますか？(続ける：1  終了：0)：");
                scanf("%d", &continue_game);
            }

            break;

        default:
            printf("\nゲームを終了しました");
            return 0;
        }
    }

    return 0;
}