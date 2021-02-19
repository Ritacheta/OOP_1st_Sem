#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct list
{
    int roll;
    char name[30];
    int score;
    struct list *next;
} student;

student *create_node(int roll, char name[], int score)
{
    student *temp = (student *)malloc(sizeof(student));
    temp->roll = roll;
    strcpy(temp->name, name);
    temp->score = score;
    temp->next = NULL;
    return temp;
}

student *get_record()
{
    int roll, score;
    char name[30];
    printf("Enter roll:");
    scanf("%d", &roll);
    printf("Enter name:");
    scanf("%s", name);
    printf("Enter score:");
    scanf("%d", &score);
    return create_node(roll, name, score);
}

int check_empty_list(student *HEAD)
{
    if (HEAD == NULL)
    {
        printf("List Empty!\n");
        return 1;
    }
    return 0;
}

student *add_record(student *HEAD)
{
    student *new_record = get_record(), *temp = HEAD;
    if (HEAD == NULL)
    {
        HEAD = new_record;
    }
    else
    {
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = new_record;
    }
    return HEAD;
}

student *delete_record(student *HEAD)
{
    int roll;
    printf("Enter the roll:");
    scanf("%d", &roll);
    student *temp = HEAD;
    if (HEAD->roll == roll)
    {
        student *temp = HEAD->next;
        free(HEAD);
        return temp;
    }
    if (HEAD->next == NULL)
    {
        if (HEAD->roll == roll)
        {
            free(HEAD);
            return NULL;
        }
        else
            printf("Student Record not found\n");
        return HEAD;
    }
    while (temp->next->roll != roll)
    {
        temp = temp->next;
        if (temp->next == NULL)
        {
            printf("Student Record not found\n");
            return HEAD;
        }
    }
    free(temp->next);
    temp->next = NULL;
    return HEAD;
}

void print_list(student *HEAD)
{
    student *temp = HEAD;
    printf("The list contains the following records:\n");
    printf("ROLL\tName\tScore\n");
    while (temp != NULL)
    {
        printf("%d\t%s\t%d\t\n", temp->roll, temp->name, temp->score);
        temp = temp->next;
    }
}

int main()
{
    student *HEAD = NULL;
    int c;
    do
    {
        printf("\n\t------Select your choice------\n");
        printf("\n\t1. INSERT A RECORD AT THE END");
        printf("\n\t2. DELETE\n\t3. PRINT");
        printf("\n\t0. EXIT");
        printf("\n\n------------------------------------------\n");
        printf("\nEnter your choice:");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            HEAD = add_record(HEAD);
            break;
        case 2:
            if (check_empty_list(HEAD))
                break;
            HEAD = delete_record(HEAD);
            break;
        case 3:
            if (check_empty_list(HEAD))
                break;
            print_list(HEAD);
            break;
        case 0:
            break;
        default:
            printf("Wrong Option Choosen!\n");
            break;
        }
    } while (c != 0);
    return 0;
}