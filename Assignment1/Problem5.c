#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char** allocate_name(int n)
{
    char **name=(char**)malloc(n*sizeof(char*));
    for(int i=0;i<n;i++)
    {
        name[i]=(char*)malloc(20*sizeof(char));
    }
    return name;
}
int* allocate_age(int n)
{
    int *age=(int*)malloc(n*sizeof(int));
    return age;
}

void sort(char** name,int* age,int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(*(age+i)>*(age+j))
            {
                int temp1=*(age+i);
                *(age+i)=*(age+j);
                *(age+j)=temp1;
                char temp[20];
                strcpy(temp,*(name+i));
                strcpy(*(name+i),*(name+j));
                strcpy(*(name+j),temp);           
            }
        }
    }
}
void print_records(char** name, int* age, int n)
{
    printf("after sorting!!\n");
    for(int i=0;i<n;i++)
    {
        printf("%s\t%d\n",*(name+i),*(age+i));
        
    }
}
int main()
{
    int n;
    printf("enter the number of records:\n");
    scanf("%d",&n);
    char** name=allocate_name(n);
    int* age=allocate_age(n);
    printf("enter the records\n");
    printf("name\tage\n");
    for(int i=0;i<n;i++)
    {
        scanf("%s %d",*(name+i),(age+i));

    }
    sort(name,age,n);
    print_records(name,age,n);
    return 0;
}