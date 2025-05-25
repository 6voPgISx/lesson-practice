#include <stdio.h>
#define N 8

int LinearSearch(int x[], int n, int y);
int BinarySearch(int x[], int n, int y);

int main(void)
{
    int data[N] = {11,22,33,44,55,66,77,88,};
    int target, rc;

    printf("目標データを入力：");
    scanf("%d", &target);

    printf("\n線形探索\n");
    rc = LinearSearch(data, N, target);
    if(rc == -1)
        printf("見つかりません\n");
    else
        printf("要素番号%dのデータです\n", rc);

    printf("\n二分探索\n");
    rc = BinarySearch(data, N, target);
    if(rc == -1)
        printf("見つかりません\n");
    else
        printf("要素番号%dのデータです\n", rc);

    return 0;
}

int LinearSearch(int x[], int n, int y)
{
    int i = 0;
    while (i<n)
    {
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
        if(x[mid] < y)
            min = mid + 1;
        else if(x[mid] > y)
            max = mid -1;
        else
            return mid;
    }
    return -1;   
}