#include <stdio.h>

struct Student
{
    int rollno;
    char name[50];
    float mark1, mark2, mark3;
};

/* ---------- FILE HANDLING ---------- */

void saveStudents(struct Student s[], int count)
{
    FILE *fp;

    fp = fopen("students.dat", "wb");

    if (fp == NULL)
    {
        printf("\nError opening file! ❌\n");
        return;
    }

    fwrite(&count, sizeof(int), 1, fp);
    fwrite(s, sizeof(struct Student), count, fp);

    fclose(fp);
}

int loadStudents(struct Student s[])
{
    FILE *fp;
    int count;

    fp = fopen("students.dat", "rb");

    if (fp == NULL)
    {
        return 0;
    }

    fread(&count, sizeof(int), 1, fp);
    fread(s, sizeof(struct Student), count, fp);

    fclose(fp);

    return count;
}

/* ---------- ADD STUDENT ---------- */

void addStudent(struct Student s[], int *count)
{
    int roll, i;

    printf("\nEnter Roll Number: ");
    scanf("%d", &roll);

    // Check duplicate roll number
    for (i = 0; i < *count; i++)
    {
        if (s[i].rollno == roll)
        {
            printf("\nError! Roll Number already exists! ❌\n");
            return;
        }
    }

    s[*count].rollno = roll;

    printf("Enter Name: ");
    scanf("%s", s[*count].name);

    printf("Enter 3 Marks: ");
    scanf("%f %f %f",
          &s[*count].mark1,
          &s[*count].mark2,
          &s[*count].mark3);

    (*count)++;

    saveStudents(s, *count);

    printf("\nStudent added successfully! ✅\n");
}

/* ---------- DISPLAY STUDENTS ---------- */

void displayStudents(struct Student s[], int count)
{
    int i;
    float total, average;

    if (count == 0)
    {
        printf("\nNo students found!\n");
        return;
    }

    printf("\n--- Student Details ---\n");

    for (i = 0; i < count; i++)
    {
        total = s[i].mark1 + s[i].mark2 + s[i].mark3;
        average = total / 3;

        printf("\nRoll No : %d", s[i].rollno);
        printf("\nName    : %s", s[i].name);

        printf("\n\nSubject 1 Mark : %.2f", s[i].mark1);

        if (s[i].mark1 >= 90)
            printf("\nSubject 1 Grade : O\n");
        else if (s[i].mark1 >= 80)
            printf("\nSubject 1 Grade : A+\n");
        else if (s[i].mark1 >= 70)
            printf("\nSubject 1 Grade : A\n");
        else if (s[i].mark1 >= 60)
            printf("\nSubject 1 Grade : B+\n");
        else if (s[i].mark1 >= 50)
            printf("\nSubject 1 Grade : B\n");
        else if (s[i].mark1 >= 45)
            printf("\nSubject 1 Grade : C\n");
        else
            printf("\nSubject 1 Grade : U\n");

        printf("\n\nSubject 2 Mark : %.2f", s[i].mark2);

        if (s[i].mark2 >= 90)
            printf("\nSubject 2 Grade : O\n");
        else if (s[i].mark2 >= 80)
            printf("\nSubject 2 Grade : A+\n");
        else if (s[i].mark2 >= 70)
            printf("\nSubject 2 Grade : A\n");
        else if (s[i].mark2 >= 60)
            printf("\nSubject 2 Grade : B+\n");
        else if (s[i].mark2 >= 50)
            printf("\nSubject 2 Grade : B\n");
        else if (s[i].mark2 >= 45)
            printf("\nSubject 2 Grade : C\n");
        else
            printf("\nSubject 2 Grade : U\n");

        printf("\n\nSubject 3 Mark : %.2f", s[i].mark3);

        if (s[i].mark3 >= 90)
            printf("\nSubject 3 Grade : O\n");
        else if (s[i].mark3 >= 80)
            printf("\nSubject 3 Grade : A+\n");
        else if (s[i].mark3 >= 70)
            printf("\nSubject 3 Grade : A\n");
        else if (s[i].mark3 >= 60)
            printf("\nSubject 3 Grade : B+\n");
        else if (s[i].mark3 >= 50)
            printf("\nSubject 3 Grade : B\n");
        else if (s[i].mark3 >= 45)
            printf("\nSubject 3 Grade : C\n");
        else
            printf("\nSubject 3 Grade : U\n");

        printf("\n\nTotal   : %.2f", total);
        printf("\nAverage : %.2f\n", average);
    }
}

/* ---------- SEARCH STUDENT ---------- */

void searchStudent(struct Student s[], int count)
{
    int roll, i, found = 0;
    float total, average;

    printf("\nEnter Roll Number to Search: ");
    scanf("%d", &roll);

    for (i = 0; i < count; i++)
    {
        if (s[i].rollno == roll)
        {
            total = s[i].mark1 + s[i].mark2 + s[i].mark3;
            average = total / 3;

            printf("\n--- Student Found ---\n");

            printf("\nRoll No : %d", s[i].rollno);
            printf("\nName    : %s", s[i].name);

            printf("\n\nSubject 1 Mark : %.2f", s[i].mark1);

            if (s[i].mark1 >= 90)
                printf("\nSubject 1 Grade : O\n");
            else if (s[i].mark1 >= 80)
                printf("\nSubject 1 Grade : A+\n");
            else if (s[i].mark1 >= 70)
                printf("\nSubject 1 Grade : A\n");
            else if (s[i].mark1 >= 60)
                printf("\nSubject 1 Grade : B+\n");
            else if (s[i].mark1 >= 50)
                printf("\nSubject 1 Grade : B\n");
            else if (s[i].mark1 >= 45)
                printf("\nSubject 1 Grade : C\n");
            else
                printf("\nSubject 1 Grade : U\n");

            printf("\n\nSubject 2 Mark : %.2f", s[i].mark2);

            if (s[i].mark2 >= 90)
                printf("\nSubject 2 Grade : O\n");
            else if (s[i].mark2 >= 80)
                printf("\nSubject 2 Grade : A+\n");
            else if (s[i].mark2 >= 70)
                printf("\nSubject 2 Grade : A\n");
            else if (s[i].mark2 >= 60)
                printf("\nSubject 2 Grade : B+\n");
            else if (s[i].mark2 >= 50)
                printf("\nSubject 2 Grade : B\n");
            else if (s[i].mark2 >= 45)
                printf("\nSubject 2 Grade : C\n");
            else
                printf("\nSubject 2 Grade : U\n");

            printf("\n\nSubject 3 Mark : %.2f", s[i].mark3);

            if (s[i].mark3 >= 90)
                printf("\nSubject 3 Grade : O\n");
            else if (s[i].mark3 >= 80)
                printf("\nSubject 3 Grade : A+\n");
            else if (s[i].mark3 >= 70)
                printf("\nSubject 3 Grade : A\n");
            else if (s[i].mark3 >= 60)
                printf("\nSubject 3 Grade : B+\n");
            else if (s[i].mark3 >= 50)
                printf("\nSubject 3 Grade : B\n");
            else if (s[i].mark3 >= 45)
                printf("\nSubject 3 Grade : C\n");
            else
                printf("\nSubject 3 Grade : U\n");

            printf("\n\nTotal   : %.2f", total);
            printf("\nAverage : %.2f\n", average);

            found = 1;
            break;
        }
    }

    if (found == 0)
    {
        printf("\nStudent not found! ❌\n");
    }
}

/* ---------- UPDATE STUDENT ---------- */

void updateStudent(struct Student s[], int count)
{
    int roll, i, found = 0;

    printf("\nEnter Roll Number to Update: ");
    scanf("%d", &roll);

    for (i = 0; i < count; i++)
    {
        if (s[i].rollno == roll)
        {
            printf("\nStudent Found! ✅\n");

            printf("Enter New Name: ");
            scanf("%s", s[i].name);

            printf("Enter New 3 Marks: ");
            scanf("%f %f %f",
                  &s[i].mark1,
                  &s[i].mark2,
                  &s[i].mark3);

            saveStudents(s, count);

            printf("\nStudent details updated successfully! ✅\n");

            found = 1;
            break;
        }
    }

    if (found == 0)
    {
        printf("\nStudent not found! ❌\n");
    }
}

/* ---------- DELETE STUDENT ---------- */

void deleteStudent(struct Student s[], int *count)
{
    int roll, i, j, found = 0;

    printf("\nEnter Roll Number to Delete: ");
    scanf("%d", &roll);

    for (i = 0; i < *count; i++)
    {
        if (s[i].rollno == roll)
        {
            for (j = i; j < *count - 1; j++)
            {
                s[j] = s[j + 1];
            }

            (*count)--;

            saveStudents(s, *count);

            printf("\nStudent deleted successfully! 🗑️\n");

            found = 1;
            break;
        }
    }

    if (found == 0)
    {
        printf("\nStudent not found! ❌\n");
    }
}

/* ---------- MAIN ---------- */

int main()
{
    struct Student s[100];
    int count;
    int choice;

    /* Load previously saved students */
    count = loadStudents(s);

    while (1)
    {
        printf("\n\n===== STUDENT MANAGEMENT SYSTEM =====");
        printf("\n1. Add Student");
        printf("\n2. Display Students");
        printf("\n3. Search Student");
        printf("\n4. Update Student");
        printf("\n5. Delete Student");
        printf("\n6. Exit");

        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                addStudent(s, &count);
                break;

            case 2:
                displayStudents(s, count);
                break;

            case 3:
                searchStudent(s, count);
                break;

            case 4:
                updateStudent(s, count);
                break;

            case 5:
                deleteStudent(s, &count);
                break;

            case 6:
                printf("\nThank you! 👋\n");
                return 0;

            default:
                printf("\nInvalid choice!\n");
        }
    }

    return 0;
}