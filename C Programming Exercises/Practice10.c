#include <stdio.h>

// int main(void){
//     int hensu;
//     int* p_hensu;
    
//     p_hensu = &hensu;
    
//     printf("==the address of hensu==\n");
//     printf("%p\n\n", &hensu);

//     hensu = 100;

//     printf("==hensuの値　参照\n");
//     printf("普通の変数　%d\n", hensu);
//     printf("ポインタで　%d\n\n", *p_hensu);

//     *p_hensu = 200;

//     printf("==hensuの値　参照\n");
//     printf("普通の変数　%d\n", hensu);
//     printf("ポインタで　%d\n\n", *p_hensu);
    
//     return 0;
// }

// void swap(int* px, int* py);

// int main(void){
//     int x = 1, y = 50;
//     printf("X は%d\nY は %d", x, y);
//     swap(&x, &y);

//     printf("X is %d\n Y is %d", x, y);

//     return 0;
// }

// void swap(int* px, int* py){
//     int tmp;

//     tmp = *px;
//     *px = *py;
//     *py = tmp;

//     return;
// }
