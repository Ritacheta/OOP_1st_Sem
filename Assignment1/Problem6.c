#include <stdio.h>
#include <stdlib.h>
typedef struct People{
    int age;
    char name[30];
}people;

void get_input(people *ptr,int n)
{
    printf("Enter the name of the name and age respectively:\n");
    for(int i = 0; i < n; ++i) {
        scanf("%s %d", (ptr + i)->name, &(ptr + i)->age);
    }
}
void sort_age(people *p,int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if((p+i)->age>(p+j)->age)
            {
                people temp = *(p+i);
                *(p+i)=*(p+j);
                *(p+j)=temp;}
        }
    }
}
void print_records(people *ptr, int n)
{
    int i;
    printf("entered values are after sorting:\n");
    for(i=0;i<n;i++)
    {
        printf("%s %d\n",(ptr+i)->name,(ptr+i)->age);
    }
}
int main() {
    people *ptr;
    int i, n;
    printf("Enter the number of records: ");
    scanf("%d", &n);

    // Memory allocation for noOfRecords structures
    ptr = (people*)malloc(n * sizeof(people));
    get_input(ptr,n);
    sort_age(ptr,n);
    print_records(ptr,n);
    return 0;
}