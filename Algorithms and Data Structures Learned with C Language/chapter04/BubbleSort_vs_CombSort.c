#include <stdio.h>
#include <stdlib.h>
#define N 8  // データ数

void GenerateRandomData(int seed, int range, int data[], int num);
void BubbleSort(int x[],int n);
void BubbleSort_ver2(int x[],int n);
void CombSort(int x[], int n);

int COMP;
int SWAP;

int main(void)
{
    int data1[N], data2[N], data3[N];
    int i, seed;

    printf("乱数のタネを入力：");
    scanf("%d", &seed);
    GenerateRandomData(seed, N, data1, N);
    for(i=0; i<N; i++){
        data2[i] = data1[i];
        data3[i] = data1[i];
    }

    printf("\n=バブルソット=\n");
    COMP=SWAP=0;
    BubbleSort(data1, N);
    printf("比較：%d回、交換：%d回\n", COMP, SWAP);

    printf("\n=バブルソットver2=\n");
    COMP=SWAP=0;
    BubbleSort_ver2(data2, N);
    printf("比較：%d回、交換：%d回\n", COMP, SWAP);

    printf("\n=コムソット=\n");
    COMP=SWAP=0;
    CombSort(data3, N);
    printf("比較：%d回、交換：%d回\n", COMP, SWAP);

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

void BubbleSort(int x[],int n)
{
    int i,j,tmp;

    for(j=n-1;j>0;j--){
        for(i=0;i<j;i++){
            if(x[i]>x[i+1]){
                tmp=x[i];
                x[i]=x[i+1];
                x[i+1]=tmp;
                SWAP++;
            }
            COMP++;
        }
    }
    return;
}

void BubbleSort_ver2(int x[],int n)
{
    int i,j,tmp,flg=1;

    for(j=n-1;flg==1;j--){
        flg=0;
        for(i=0;i<j;i++){
            if(x[i]>x[i+1]){
                tmp=x[i];
                x[i] =x[i+1];
                x[i+1]=tmp;
                flg=1;
                SWAP++;
            }
            COMP++;
        }
    }
    return;
}

void CombSort(int x[],int n)
{
    int i,j,tmp,gap,flg=1;

    gap=n;
    while(gap>1 || flg==1){
        gap=gap*10/13;
        if(gap<1) gap=1;
        flg=0;
        for(i=0;i+gap<n;i++){
            if( x[i]>x[i+gap]){
                tmp=x[i];
                x[i]=x[i+gap];
                x[i+gap]=tmp;
                flg=1;
                SWAP++;
            }
            COMP++;
        }
    }
    return;
}