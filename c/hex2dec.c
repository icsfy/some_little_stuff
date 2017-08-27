#include <stdio.h>

unsigned hex2dec(char *hex)
{
    unsigned dec;
    sscanf(hex, "%x", &dec);
    return dec;
}

int main(int argc, char *argv[])
{
    unsigned num;
    if (argc == 2)
        num = hex2dec(argv[1]);
    else {
        printf("hexadecimal: ");
        scanf("%x", &num);
    }
    printf("decimal: %u\n", num);
    return 0;
}
