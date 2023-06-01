#include <stdio.h>

int misterio(unsigned n)
{
    if (!n)
        return n;
    return misterio(n >> 1) * 10 + (n & 1);
}

char *hola = "Hola";

int main()
{
    printf("%s", hola);
}