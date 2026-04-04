#include <stdio.h>
int recur(int n);

int main()
{
    int n = 5;
    printf("%d",recur(n));
}

int recur(int n)
{
    if(n <= 1)
    {
        return n;
    }
    else
    {
        return n + recur(n-2) ;
    }
}