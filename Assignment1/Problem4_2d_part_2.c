#include<stdio.h>
#include<stdlib.h>

int get_dimension(int *row, int* col)
{
    printf("enter the size of the 2d array:\n");
    scanf("%d %d", row, col);
}
int* allocate(int row, int col)
{
    int* mat=(int*)malloc(row*col*sizeof(int));
    return mat;
}

int* get_input(int* arr,int row,int col)
{
    int i,j;
    printf("enter the values for the array:\n");
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            scanf("%d",arr+i*col+j);
        }
    }
    return arr;
}
void print_array(int* arr,int row,int col)
{
    int i,j;
    printf("the given matrix is:\n");
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            printf("%d, ",*(arr+i*col+j));
        }
        printf("\n");
    }

}
int main()
{
    int m,n;
    get_dimension(&m, &n);
    int *mat = allocate(m,n);
    mat = get_input(mat, m, n);
    print_array(mat,m,n);
}