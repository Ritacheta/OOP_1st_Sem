#include<stdio.h>

int main()
{
    int i, n;
    int *arr;
    printf("enter the size of the array:\n");
    scanf("%d",&n);
    arr = (int*)malloc(n * sizeof(int));
    printf("enter the values:\n");
    for(i=0;i<n;i++)
    scanf("%d",arr+i);
    printf("entered values are:\n");
    for(i=0;i<n;i++)
    printf("%d, ",*(arr+i));
    return 0;
}