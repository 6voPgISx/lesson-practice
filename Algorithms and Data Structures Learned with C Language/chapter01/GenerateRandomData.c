#include <stdio.h>
#include <stdlib.h>
#define N 100

void GenerateRandomData(int seed, int range, int data[], int num);

int main(void) {
    int data[N];
    int seed, range, num;
    
    printf("乱数のタネ:"); scanf("%d", &seed);
    printf("乱数の範囲:"); scanf("%d", &range);
    printf("乱数の個数:"); scanf("%d", &num);
    if (num >= N)
        return 1;

    GenerateRandomData(seed, range, data, num);

    return 0;
}

void GenerateRandomData(int seed, int range, int data[], int num){

    int i;

    srand(seed);
    for (i = 0; i < num; i++) {
        data[i] = rand() % range+1;
        printf("%d\t", data[i]);
}
    printf("\n");

    return;
}