#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n,m,i,j;
    printf("enter the size of the two dimensional array:\n");
    scanf("%d %d",&m, &n);
    int **arr = (int **)malloc(m*sizeof(int*));
    for(i=0;i<m;i++)
    {
        *(arr+i)=(int*)malloc(n*sizeof(int));
    }
    printf("enter the values of the two dimensional array of integer:\n");
    for(i=0;i<m;i++)
    {for(j=0;j<n;j++)
           { 
               scanf("%d",&arr[i][j]);
           }
    }
    printf("the given values are:\n");
    for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                printf("%d,",*(*(arr+i)+j));
            }
           printf("\n"); 
        }
    return 0; 
    
}