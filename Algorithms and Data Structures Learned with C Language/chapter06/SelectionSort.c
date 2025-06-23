#include<stdio.h>
#define N 8  // データ数

void SelectionSort(int x[],int n);
void InsertionSort(int x[],int n);

int COMP,SWAP,MOVE;

int main(void)
{
   int i;
   int data1[N]={3,2,8,5,7,1,6,4};
   int data2[N];
   for(i=0;i<N;i++)data2[i]=data1[i]; 

   printf("\n並べ替え前\n");
   for(i=0;i<N;i++) printf("%d\t",data1[i]);
   printf("\n");
 
   printf("\n基本選択法\n");
   COMP=SWAP=0;
   SelectionSort(data1,N);  
   printf("比較%d回、交換%d回(移動%d回)\n",COMP,SWAP,SWAP*3);

   printf("\n基本挿入法\n");
   COMP=MOVE=0;
   InsertionSort(data2,N);  
   printf("比較%d回、移動%d回\n",COMP,MOVE); 

   printf("\n並べ替え後\n");
   for(i=0;i<N;i++) printf("%d\t",data1[i]);
   printf("\n");

   return 0;
}

void SelectionSort(int x[],int n)
{
  int i,j,max_id;
  int tmp;

  for(j=n-1;j>0;j--){
    max_id=0;
    for(i=1;i<=j;i++){
      COMP++;
      if(x[max_id]<x[i]) max_id=i;
    }
    tmp=x[j];
    x[j]=x[max_id];
    x[max_id]=tmp;
    SWAP++;
  }
  return;
}

void InsertionSort(int x[],int n)
{
    int i,j;
    int tmp;

    for(j=1;j<n;j++){
        tmp=x[j]; MOVE++;
        for(i=j-1;i>=0;i--){
            COMP++;
            if(x[i]>tmp) { x[i+1]=x[i]; MOVE++;}
            else break;
        }
        x[i+1]=tmp; MOVE++;
    }
    return;
}