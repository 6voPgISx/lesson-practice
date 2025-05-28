#include <stdio.h>

int main(void)
{

    char name[21];
    int age;
    float height;
    float weight;
    
    printf("名前を入力してください：");
    scanf("%s", name);
    printf("%sさん年齢を入力してください：", name);
    scanf("%d", &age);
    printf("%sさん身長を入力してください：", name);
    scanf("%f", &height);
    printf("%sさん体重を入力してください：", name);
    scanf("%f", &weight);

    printf("**********\n");
    
    printf("%sさんは%d歳、身長は%.1fcm、体重は%.1fkgですね。\n", name, age, height, weight);
    printf("%sさんの肥満度指数は%.1fです。\n", name, (weight*10000)/(height*height));
    
    return 0;
}