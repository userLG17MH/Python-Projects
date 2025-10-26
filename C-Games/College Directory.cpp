#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DEPARTMENTS 4
#define MAX_STUDENTS 100

typedef struct 
{
    char name[50];
    char department[10];
    int year;
} Student;

typedef struct 
{
    char name[10];
    int max_seats;
    int current_students;
} Department;

Student students[MAX_STUDENTS];
int student_count = 0;

Department departments[MAX_DEPARTMENTS] =
{
    {"BCA", 0, 0},
    {"BBA", 0, 0},
    {"HHM", 0, 0},
    {"BMLT", 0, 0}
};

void set_department_seats()
{
    for (int i = 0; i < MAX_DEPARTMENTS; i++) 
    {
        printf("Enter number of seats for %s: ", departments[i].name);
        scanf("%d", &departments[i].max_seats);
    }
    printf("\nDepartment seats set successfully!\n");
}

void add_student() {
    if (student_count >= MAX_STUDENTS)
    {
        printf("\nNo more seats available!\n");
        return;
    }
    Student s;
    char dept[10];
    printf("\nEnter Student Name: ");
    scanf("%s", s.name);
    printf("Enter Department (BCA/BBA/HHM/BMLT): ");
    scanf("%s", dept);
    printf("Enter Year of Admission: ");
    scanf("%d", &s.year);
    
    for (int i = 0; i < MAX_DEPARTMENTS; i++) 
    {
        if (strcmp(departments[i].name, dept) == 0) 
        {
            if (departments[i].current_students < departments[i].max_seats) 
            {
                students[student_count++] = s;
                departments[i].current_students++;
                printf("\nStudent Added Successfully to %s!\n", dept);
                return;
            } else {
                printf("\nNo available seats in %s!\n", dept);
                return;
            }
        }
    }
    printf("\nInvalid Department!\n");
}

void transfer_student() 
{
    if (student_count == 0) 
    {
        printf("\nNo students available to transfer!\n");
        return;
    }
    char name[50];
    printf("\nEnter Student Name to Transfer: ");
    scanf("%s", name);
    
    int found = -1;
    for (int i = 0; i < student_count; i++) 
    {
        if (strcmp(students[i].name, name) == 0) 
        {
            found = i;
            break;
        }
    }
    
    if (found != -1)
    {
        for (int i = 0; i < MAX_DEPARTMENTS; i++)
        {
            if (strcmp(departments[i].name, students[found].department) == 0)
            {
                departments[i].current_students--;
                break;
            }
        }
        for (int i = found; i < student_count - 1; i++)
        {
            students[i] = students[i + 1];
        }
        student_count--;
        printf("\nStudent Transferred Successfully!\n");
    }
  else
    {
        printf("\nStudent Not Found!\n");
    }
}

void display_students() 
{
    if (student_count == 0) 
    {
        printf("\nNo students added yet!\n");
        return;
    }
    printf("\nList of Students:\n");
    for (int i = 0; i < student_count; i++) {
        printf("%d. Name: %s, Department: %s, Year: %d\n", i + 1, students[i].name, students[i].department, students[i].year);
    }
}

void display_seats() 
{
    printf("\nDepartment Seat Availability:\n");
    printf("--------------------------------------------------\n");
    printf("BCA\t|	BBA\t|	BMLT\t|	HHM\n");
    printf("--------------------------------------------------\n");
    printf("%d/%d\t|	%d/%d\t|	%d/%d\t|	%d/%d\n", 
           departments[0].current_students, departments[0].max_seats,
           departments[1].current_students, departments[1].max_seats,
           departments[2].current_students, departments[2].max_seats,
           departments[3].current_students, departments[3].max_seats);
    printf("--------------------------------------------------\n");
}

int main() 
{
    int ch;
    char choice;
    
    do {
        printf("\n**MENU**");
        printf("\n1. Set Department Seats");
        printf("\n2. Add New Student");
        printf("\n3. Transfer Student");
        printf("\n4. Display Students");
        printf("\n5. Display Seat Availability");
        printf("\n6. Exit");
        printf("\nEnter Your Choice: ");
        scanf("%d", &ch);
        
        switch (ch) {
            case 1:
                set_department_seats();
                break;
            case 2:
                add_student();
                break;
            case 3:
                transfer_student();
                break;
            case 4:
                display_students();
                break;
            case 5:
                display_seats();
                break;
            case 6:
                printf("\nExiting...\n");
                exit(0);
            default:
                printf("\nInvalid Choice! Try Again.\n");
        }
        
        printf("\nDo you want to continue? (Y/N): ");
        scanf(" %c", &choice);
    } while (choice == 'Y' || choice == 'y');
    
    return 0;
}
