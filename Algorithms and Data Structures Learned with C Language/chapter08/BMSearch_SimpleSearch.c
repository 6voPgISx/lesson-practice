#include <stdio.h>
#include <string.h>

int COUNT = 0;

int SimpleSearch(char text[],char key[]);
int BMSearch(unsigned char text[], unsigned char key[]);

int main(void){
    char text[] = "She sells seashells by the seashore.";
    char key[64];
    int rc;

    printf("Text: %s\n", text);
    printf("Keyword: ");
    scanf("%s", key);

    printf("\n==SimpleSearch==\n");
    COUNT = 0;
    rc = SimpleSearch(text, key);
    printf("Compare times: %d\n", COUNT);
    printf("Search result: ");
    if(rc != -1)
        printf("The keyword is located at character number %d.\n", rc + 1);
    else
        printf("The keyword does not exist.\n");

    printf("\n==BMSearch==\n");
    COUNT = 0;
    rc = BMSearch(text, key);
    printf("Compare times: %d\n", COUNT);
    printf("Search result: ");
    if(rc != -1)
        printf("The keyword is located at character number %d.\n", rc + 1);
    else
        printf("The keyword does not exist.\n");

    return 0;
}

int BMSearch(unsigned char text[], unsigned char key[]){
    char table[256];
    int nt, nk, i, t, k;

    nt = strlen(text);
    nk = strlen(key);

    for(i = 0; i < 256; i++) table[i] = nk;
    for(i = 0; i < nk; i++) table[key[i]] = nk - i - 1;

    t = k = nk - 1;
    while (t < nt){
        COUNT++;
        if(text[t] == key[k]){
            if(k == 0) return t;
            t--;
            k--;
        }
        else{
            if(table[text[t]] <= nk - 1 - k) t = t + nk - k;
            else t = t + table[text[t]];
            k = nk - 1;
        }
    }
    return(-1);
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