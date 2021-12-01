#include <stdio.h>
#include <string.h>

#define MOD 1021

int hashFunction(const char* string)
{
    const p = 67;
    const length = strlen(string);
    long long hash = 0;
    for (int i = 0; i < length; i++)
    {
        hash = (hash * p + string[i]) % MOD;
    }
    return abs(hash);
}

int main()
{
    printf("%d", hashFunction("фффф"));
}