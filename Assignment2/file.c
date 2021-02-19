#include <stdio.h>
#include <stdlib.h>
struct student
{
    int rollno;
    char name[30];
    float mark[5];
} stud;
//    FUNCTION TO INSERT RECORDS TO THE FILE
void insert()
{
    FILE *fp;
    fp = fopen("Record.dat", "a");
    printf("Enter the Roll no:");
    scanf("%d", &stud.rollno);
    printf("Enter the Name:");
    scanf("%s", stud.name);
    printf("Enter the marks for subject 1:");
    scanf("%f", &stud.mark[0]);
    printf("Enter the marks for subject 2:");
    scanf("%f", &stud.mark[1]);
    printf("Enter the marks for subject 3:");
    scanf("%f", &stud.mark[2]);
    printf("Enter the marks for subject 4:");
    scanf("%f", &stud.mark[3]);
    printf("Enter the marks for subject 5:");
    scanf("%f", &stud.mark[4]);
    fwrite(&stud, sizeof(stud), 1, fp);
    fclose(fp);
}
//    FUNCTION TO DISPLAY RECORDS
void disp()
{
    FILE *fp1;
    fp1 = fopen("Record.dat", "r");
    printf("\nRoll Number\tName\tMark\n\n");
    while (fread(&stud, sizeof(stud), 1, fp1))
    {
        float total = 0;
        for (int i = 0; i < 5; i++)
        {
            total += stud.mark[i];
        }
        printf("  %d\t\t%s\t%.2f\n", stud.rollno, stud.name, total);
    }
    fclose(fp1);
}
//    FUNCTION TO SEARCH THE GIVEN RECORD
void search()
{
    FILE *fp2;
    int r, s, avl;
    printf("\nEnter the Roll no you want to search  :");
    scanf("%d", &r);
    if (avlrollno(r) == 0)
        printf("Roll No %d is not available in the file\n", r);
    else
    {
        fp2 = fopen("Record.dat", "r");
        while (fread(&stud, sizeof(stud), 1, fp2))
        {
            s = stud.rollno;
            if (s == r)
            {
                printf("\nRoll no = %d", stud.rollno);
                printf("\nName    = %s", stud.name);
                printf("\nMark  for subject 1 = %.2f\n", stud.mark[0]);
                printf("\nMark  for subject 2 = %.2f\n", stud.mark[1]);
                printf("\nMark  for subject 3 = %.2f\n", stud.mark[2]);
                printf("\nMark  for subject 4 = %.2f\n", stud.mark[3]);
                printf("\nMark  for subject 5 = %.2f\n", stud.mark[4]);
            }
        }
        fclose(fp2);
    }
}
//    FUNCTION TO DELETE A RECORD
void deletefile()
{
    FILE *fpo;
    FILE *fpt;
    int r, s;
    printf("Enter the Roll no you want to delete :");
    scanf("%d", &r);
    if (avlrollno(r) == 0)
        printf("Roll no %d is not available in the file\n", r);
    else
    {
        fpo = fopen("Record.dat", "r");
        fpt = fopen("TempFile.dat", "w");
        while (fread(&stud, sizeof(stud), 1, fpo))
        {
            s = stud.rollno;
            if (s != r)
                fwrite(&stud, sizeof(stud), 1, fpt);
        }
        fclose(fpo);
        fclose(fpt);
        fpo = fopen("Record.dat", "w");
        fpt = fopen("TempFile.dat", "r");
        while (fread(&stud, sizeof(stud), 1, fpt))
            fwrite(&stud, sizeof(stud), 1, fpo);
        printf("\nRECORD DELETED\n");
        fclose(fpo);
        fclose(fpt);
    }
}
//    FUNCTION TO UPDATE THE RECORD
void update()
{
    int avl;
    FILE *fpt;
    FILE *fpo;
    int s, r, ch;
    printf("Enter roll number to update:");
    scanf("%d", &r);
    avl = avlrollno(r);
    if (avl == 0)
    {
        printf("Roll number %d is not Available in the file", r);
    }
    else
    {
        fpo = fopen("Record.dat", "r");
        fpt = fopen("TempFile.dat", "w");
        while (fread(&stud, sizeof(stud), 1, fpo))
        {
            s = stud.rollno;
            if (s != r)
                fwrite(&stud, sizeof(stud), 1, fpt);
            else
            {
                printf("\n\t1. Update Name of Roll Number %d", r);
                printf("\n\t2. Update Mark of Roll Number %d", r);
                printf("\n\t3. Update both Name and Mark of Roll Number %d", r);
                printf("\nEnter your choice:");
                scanf("%d", &ch);
                switch (ch)
                {
                case 1:
                    printf("Enter Name:");
                    scanf("%s", &stud.name);
                    break;
                case 2:
                    printf("Enter Mark for subject 1: ");
                    scanf("%f", &stud.mark[0]);
                    printf("Enter Mark for subject 2: ");
                    scanf("%f", &stud.mark[1]);
                    printf("Enter Mark for subject 3: ");
                    scanf("%f", &stud.mark[2]);
                    printf("Enter Mark for subject 4: ");
                    scanf("%f", &stud.mark[3]);
                    printf("Enter Mark for subject 5: ");
                    scanf("%f", &stud.mark[4]);
                    break;
                case 3:
                    printf("Enter Name: ");
                    scanf("%s", &stud.name);
                    printf("Enter Mark for subject 1: ");
                    scanf("%f", &stud.mark[0]);
                    printf("Enter Mark for subject 2: ");
                    scanf("%f", &stud.mark[1]);
                    printf("Enter Mark for subject 3: ");
                    scanf("%f", &stud.mark[2]);
                    printf("Enter Mark for subject 4: ");
                    scanf("%f", &stud.mark[3]);
                    printf("Enter Mark for subject 5: ");
                    scanf("%f", &stud.mark[4]);
                    break;
                default:
                    printf("Invalid Selection");
                    break;
                }
                fwrite(&stud, sizeof(stud), 1, fpt);
            }
        }
        fclose(fpo);
        fclose(fpt);
        fpo = fopen("Record.dat", "w");
        fpt = fopen("TempFile.dat", "r");
        while (fread(&stud, sizeof(stud), 1, fpt))
        {
            fwrite(&stud, sizeof(stud), 1, fpo);
        }
        fclose(fpo);
        fclose(fpt);
        printf("RECORD UPDATED");
    }
}
//    FUNCTION TO CHECK GIVEN ROLL NO IS AVAILABLE //
int avlrollno(int rno)
{
    FILE *fp;
    int c = 0;
    fp = fopen("Record.dat", "r");
    while (!feof(fp))
    {
        fread(&stud, sizeof(stud), 1, fp);

        if (rno == stud.rollno)
        {
            fclose(fp);
            return 1;
        }
    }
    fclose(fp);
    return 0;
}
//    FUNCTION TO CHECK THE FILE IS EMPTY OR NOT
int empty()
{
    int c = 0;
    FILE *fp;
    fp = fopen("Record.dat", "r");
    while (fread(&stud, sizeof(stud), 1, fp))
        c = 1;
    fclose(fp);
    return c;
}
//     MAIN PROGRAM
void main()
{
    int c, emp;
    do
    {
        printf("\n\t------Select your choice------\n");
        printf("\n\t1. INSERT\n\t2. DISPLAY\n\t3. SEARCH");
        printf("\n\t4. DELETE\n\t5. UPDATE");
        printf("\n\t6. EXIT");
        printf("\n\n------------------------------------------\n");
        printf("\nEnter your choice:");
        scanf("%d", &c);
        printf("\n");
        switch (c)
        {
        case 1:
            insert();
            break;
        case 2:
            emp = empty();
            if (emp == 0)
                printf("\nThe file is EMPTY\n");
            else
                disp();
            break;
        case 3:
            search();
            break;
        case 4:
            deletefile();
            break;
        case 5:
            update();
            break;
        case 6:
            exit(1);
            break;
        default:
            printf("\nYour choice is wrong\nPlease try again...\n");
            break;
        }
    } while (c != 6);
}