#include <stdio.h>
#include <string.h>

int COUNT = 0;

int SimpleSearch(char text[],char key[]);
int KMPSearch(char text[], char key[]);

int main(void)
{
   char text[]="She sells seashells by the seashore.";
   char key[]="shore";
   int  rc;
 
   printf("テキスト  ：%s\n",text);
   printf("キーワード：%s\n",key);
 
   printf("\n==SimpleSearch==\n");
   COUNT = 0;
   rc = SimpleSearch(text,key);
   printf("Compare times: %d times\n", COUNT);
   printf("検索結果  ：");
   if(rc!=-1){
      printf("キーワードは %d 文字目にあります\n",rc+1);
   }else{
      printf("キーワードはありません\n");
   }

   printf("\n==KMPSearch==\n");
   COUNT = 0;
   rc = KMPSearch(text, key);
   printf("Compare times: %d times\n", COUNT);
   printf("検索結果  ：");
   if(rc!=-1){
      printf("キーワードは %d 文字目にあります\n",rc+1);
   }else{
      printf("キーワードはありません\n");
   }
    return 0;
}

int SimpleSearch(char text[],char key[])
{
    int  i,j,n,m;

    m=strlen(key);
    n=strlen(text);

    for(i=0;i<=n-m;i++){
        for(j=0;j<m;j++){
            COUNT++;
            if(text[i+j] != key[j]) break;
        }
        if(j==m) return i;
   }
   return -1;
}

int KMPSearch(char text[ ], char key[])
{
    int i,j,k,l,m,n;
    int table[64];
 
    m=strlen(key);
    n=strlen(text);

    //表の作成
    table[0]=table[1]=0;
    k=1; l=0;
    while(k<m){
        if(key[k]==key[l]){
            k++;l++;
            table[k]=l;
        }else if(l>0){
            l=table[l];
        }else{
            k++;
            table[k]=0;
        }
    }

    //表の表示
    printf("作成した表：");
    for(i=0;i<m;i++) printf("%d",table[i]);
    printf("\n");

    //検索開始
    i=0;j=0;
    while(i<=n-m){
        COUNT++;
        if(text[i+j]==key[j]){
            j++;
            if(j==m)return i;
        }else{
            if(j==0)i++;
            else i=i+j-table[j];
            j=table[j];
        }
    }
    return(-1);
}