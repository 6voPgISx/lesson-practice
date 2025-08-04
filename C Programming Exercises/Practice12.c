# include <stdio.h>

struct Body
{
    int age;
    double height;
    double weight;
};

int main(void){
    struct Body data = {18, 188.8, 88.8};

    printf("\nage\theight\tweight\n");
    printf("%dyears old", data.age);
    printf("%.1fcm\t", data.height);
    printf("%.1fkg\n", data.weight);

    return 0;
}