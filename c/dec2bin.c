#include <stdio.h>

void dec2bin(int num);

int main()
{
    int num;
    printf("decimal: ");
    scanf("%d", &num);

    printf("binary: ");
    dec2bin(num);

    printf("\nhexadecimal: 0x%2X\n", num);

    return 0;
}

void dec2bin(int num)
{
    if(num) {
        dec2bin(num / 2);
        printf("%d", num % 2);
    }
}