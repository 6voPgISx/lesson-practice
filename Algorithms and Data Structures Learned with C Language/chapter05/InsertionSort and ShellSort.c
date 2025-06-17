#include <stdio.h>
#include <stdlib.h>
#define N 8  // データ数

void GenerateRandomData(int seed, int range, int data[], int num);
void InsertionSort(int x[],int n);
void InsertionSort_ver2(int x[],int n);
void ShellSort(int x[], int n);
void ShellSort_ver2(int x[], int n);

int COMP, MOVE;

int main(void)
{
    int data1[N], data2[N], data3[N], data4[N];
    int i, seed;

    printf("Input the seed of the randomData: ");
    scanf("%d", &seed);
    GenerateRandomData(seed, N, data1, N);
    for(i=0; i<N; i++){
        data2[i]=data1[i];
        data3[i]=data1[i];
        data4[i]=data1[i];
    }

    // printf("\n並べ替え前\n");
    // for(i=0;i<N;i++) printf("%d\t",data[i]);
    // printf("\n");

    printf("\n基本挿入法\n");
    COMP=MOVE=0;
    InsertionSort(data1,N);
    printf("compare %d times, move %d times.\n", COMP, MOVE);

    printf("\n改良基本挿入法\n");
    COMP=MOVE=0;
    InsertionSort_ver2(data2,N);
    printf("compare %d times, move %d times.\n", COMP, MOVE);

    printf("\nシェルソート\n");
    COMP=MOVE=0;
    ShellSort(data3,N);
    printf("compare %d times, move %d times.\n", COMP, MOVE);

    printf("\n改良シェルソート\n");
    COMP=MOVE=0;
    ShellSort_ver2(data4,N);
    printf("compare %d times, move %d times.\n", COMP, MOVE);
 

    // printf("\n並べ替え後\n");
    // for(i=0;i<N;i++) printf("%d\t",data[i]);
    // printf("\n");

    return 0;
}

void ShellSort(int x[], int n){
    int i, j, k, tmp, gap;

    gap=n/2;
    while(gap>0){
        for(k=0; k<gap; k++){
            for(j=k+gap; j<n; j=j+gap){
                tmp=x[j];
                MOVE++;
                for(i=j-gap; i>=0; i=i-gap){
                    COMP++;
                    if(x[i]>tmp){
                        x[i+gap]=x[i];
                        MOVE++;
                    }
                    else break;
                }
                x[i+gap]=tmp;
                MOVE++;
            }
        }
        gap=gap/2;
    }
   return; 
}

void ShellSort_ver2(int x[], int n){
    int i, j, k, tmp, gap;

    gap=1;
    while (n>gap){
        gap=3*gap+1;
    }
    gap=(gap-1)/3;
    
    while(gap>0){
        for(k=0; k<gap; k++){
            for(j=k+gap; j<n; j=j+gap){
                tmp=x[j];
                MOVE++;
                for(i=j-gap; i>=0; i=i-gap){
                    COMP++;
                    if(x[i]>tmp){
                        x[i+gap]=x[i];
                        MOVE++;
                    }
                    else break;
                }
                x[i+gap]=tmp;
                MOVE++;
            }
        }
        gap=(gap-1)/3;
    }
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

void InsertionSort_ver2(int x[],int n){
   
    int i,j,tmp,min,max,mid;
 
    for(j=1;j<n;j++){
        tmp=x[j];
        MOVE++;
        min=0; max=j;
        while(min<max){
            mid=(min+max)/2;
            COMP++;
            if(x[mid]<=tmp) min=mid+1;
            else max=mid;
      }
        for(i=j-1;i>=min;i--){
            x[i+1]=x[i];
            MOVE++;
        }
        x[min]=tmp;
        MOVE++;
    }
    return;
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