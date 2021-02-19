#include<stdio.h>
#include<stdlib.h>

int get_dimension(int *row)
{
    printf("enter the size of the 1d array:\n");
    scanf("%d", row);
}
int* allocate(int row)
{
    int i;
    int *arr = (int *)malloc(row*sizeof(int*));
    return arr;
}
int* get_input(int* arr,int row)
{
    int i,j;
    printf("enter the values for the array:\n");
    for(i=0;i<row;i++)
    {
            scanf("%d",(arr+i));
    }
    return arr;
}
void print_array(int* arr,int row)
{
    int i,j;
    printf("the given matrix is:\n");
    for(i=0;i<row;i++)
    {
       printf("%d, ",arr[i]);
    }

}
int main()
{
    int m;
    get_dimension(&m);
    int *mat = allocate(m);
    mat = get_input(mat, m);
    print_array(mat,m);
}