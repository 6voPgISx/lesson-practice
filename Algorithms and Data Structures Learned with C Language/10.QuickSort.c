#include <stdio.h>
#define N 8

void GenerateRandomData(int seed, int range, int data[], int num);
void QuickSort(int x[], int min, int max);
void InsertionSort(int x[], int n);
int COMP, SWAP, MOVE;

int main(void){
    int i, seed;
    int data1[N], data2[N];

    printf("Input the seed of the randomData: ");
    scanf("%d", &seed);
    GenerateRandomData(seed, N, data1, N);
    for(i=0; i<N; i++){
        data2[i] = data1[i];
    }

    printf("\n==InsertionSort==\n");
    COMP = SWAP = MOVE = 0;
    InsertionSort(data1, N);
    printf("\n比較回数%d、移動回数%d\n", COMP, MOVE); 

    printf("\n==QuickSort==\n");
    COMP = SWAP = 0;
    QuickSort(data2, 0, N-1);
    printf("\n比較回数%d、移動回数%d\n", COMP, SWAP*3);

    // printf("\n 並 べ 替 え 前\n" );
    // for (i=0;i<N;i++) printf("%d\t" ,data[i]);
    // printf("\n");

    // COMP = SWAP = 0;
    // QuickSort (data,0,N-1) ;
    // printf("\n比較回数%d、交換回数%d\n", COMP, SWAP);

    // printf("\n 並 べ 替 え 後\n ");
    // for (i=0;i<N;i++) printf("%d\t" ,data[i]);
    // printf("\n");

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

void QuickSort(int x[], int min, int max){
    int p, i, j, tmp;

    if(min >= max) return;

    p = (x[min] + x[max])/2;
    i = min;
    j = max;
    while (1){
        while(x[i] < p) {i++; COMP++;}
        COMP++;
        while(x[j] > p) {j--; COMP++;}
        COMP++;
        if(i>=j) break;
        tmp = x[i]; x[i] = x[j]; x[j] = tmp;
        SWAP++;
        i++; j--;
    } 

    QuickSort(x, min, i-1);
    QuickSort(x, j+1, max);

    return;
}

void InsertionSort(int x[], int n){
    int i, j, tmp;

    for(j=1;j<n;j++){
        tmp=x[j]; MOVE++;
        for(i=j-1;i>=0;i--){
            COMP++;
            if(x[i]>tmp) {x[i+1]=x[i]; MOVE++;}
            else break;
        }
        x[i+1]=tmp;
        MOVE++;
    }
    return;
}