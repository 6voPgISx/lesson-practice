#include <stdio.h>
#include <string.h>

int main(void)
{

    char name[21], bmi_evaluation[21];
    int age;
    float height, weight, bmi;
    
    printf("名前を入力してください：");
    scanf("%20s", name);
    printf("%sさん年齢を入力してください：", name);
    scanf("%d", &age);
    printf("%sさん身長を入力してください：", name);
    scanf("%f", &height);
    printf("%sさん体重を入力してください：", name);
    scanf("%f", &weight);
    
    bmi = weight*10000/(height*height);

    if(bmi >= 30) strcpy(bmi_evaluation, "ふとりすぎ");
    else if(bmi >= 25) strcpy(bmi_evaluation, "太り気味");
    else if(bmi >= 18.5) strcpy(bmi_evaluation, "標準");
    else if(bmi >= 16) strcpy(bmi_evaluation, "痩せ気味");
    else strcpy(bmi_evaluation, "痩せすぎ");

    printf("*****診断結果*****\n");

    printf("%sさんは%d歳、身長は%.1fcm、体重は%.1fkgですね。\n", name, age, height, weight);
    printf("%sさんの肥満度指数は%.1fです。\n", name, bmi);
    printf("%sさんは[%s]です。\n", name, bmi_evaluation);
    
    return 0;
}