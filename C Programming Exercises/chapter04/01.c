#include <stdio.h>

int main(void)
{
    int a = 5;
    int b, c;
    
    b = ++a;
    printf("%d\n", b);
    
    c = a++;
    printf("%d\n", c);

    return 0;
}
