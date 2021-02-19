#include<stdio.h>

int main()
{
    int i, *p, **pp;
    printf("Enter a number:\n");
    scanf("%d",&i);
    printf("entered number is %d\n",i);
    p=&i;
    pp=&p;
    printf("the pointer to the given integer is %d\n",p);
    printf("the pointer to the pointer to the entered value: %d\n",pp);
    return 0;
}