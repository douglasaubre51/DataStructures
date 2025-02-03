#include <stdio.h>
int bin_search(int z[], int l, int h, int find);
void Display(int s, int e[]);
int main()
{
    int a = 10;
    int sz = 10;
    int result;
    int m[20] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    result = bin_search(m, 0, sz - 1, a);
    Display(sz, m);
    if (result == 11)
    {
        printf("match found!!");
    }
    else if (result == 0)
    {
        printf("match not found!!");
    }
}
void Display(int s, int e[])
{
    for (int i = 0; i < s; i++)
    {
        printf("%d\t", e[i]);
    }
    return;
}
int bin_search(int z[], int l, int h, int find)
{
    int mid;
    if (l > h)
        return 0;
    if (z[mid] == find)
    {
        return 11;
    }
    else
    {
        mid = (l + h) / 2;
        if (z[mid] < find)
        {
            return bin_search(z, mid + 1, h, find);
        }
        else if (z[mid] > find)
        {
            return bin_search(z, l, mid - 1, find);
        }
    }
    return 0;
}
