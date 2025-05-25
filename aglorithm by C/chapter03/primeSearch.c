#include <stdio.h>
#define N 100

int prime(int x[]);
int LinearSearch(int x[], int n, int y);
int BinarySearch(int x[], int n, int y);

int COUNT;

int main(void)
{
    int data[N];
    int target, rc;
    int n;

    n = prime(data);
    printf("目標データ(%d未満の数)を入力：", N);
    scanf("%d", &target);

    COUNT = 0;
    printf("\n線形探索\n");
    rc = LinearSearch(data, n, target);
    if(rc == -1)
        printf("素数ではありません\n");
    else
        printf("%d番目の素数です\n", rc+1);
    printf("%d個の素数について調べますた\n", COUNT);

    COUNT = 0;
    printf("\n二分探索\n");
    rc = BinarySearch(data, n, target);
    if(rc == -1)
        printf("素数ではありません\n");
    else
        printf("%d番目の素数です\n", rc+1);
    printf("%d個の素数について調べますた\n", COUNT); 

    return 0;
}

int prime(int x[])
{
    int i,n=0,m=0;

    int p[N];  // チェック表の宣言
    for(i=2;i<N;i++) p[i]=0; // 2以上N未満の数を素数候補とする
    p[0]=p[1]=1;  // 0と1は素数でないため素数候補から除外

    for(n=2;n<N;n++){
        for(i=n*2;i<N;i+=n) p[i]=1; // nの倍数を素数候補から除外
    }

    for(i=2;i<N;i++){
        if(p[i]==0){
            x[m++]=i; //候補から除外されず残ったiを素数として格納
            printf("%d ",i);
        }
    }
    printf("\n");
    return m;  //  素数として格納した個数を返し終了
}

int LinearSearch(int x[], int n, int y)
{
    int i = 0;
    while (i<n)
    {
        COUNT++;
        if(x[i] == y) 
            return i;
        else i++;
    }
    return -1;   
}

int BinarySearch(int x[], int n, int y)
{
    int mid, min, max;
    min = 0;
    max = n-1;
    while (min <= max)
    {
        mid = (min + max)/2;
        COUNT++;
        if(x[mid] < y)
            min = mid + 1;
        else if(x[mid] > y)
            max = mid -1;
        else
            return mid;
    }
    return -1;   
}