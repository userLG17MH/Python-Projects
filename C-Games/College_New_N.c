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

void save_to_file()
{
    char filename[50];
    printf("\nEnter filename to save: ");
    scanf("%s", filename);
    
    FILE *file = fopen(filename, "w");
    if (!file)
    {
        printf("Error saving data!\n");
        return;
    }
    fprintf(file, "%d\n", student_count);
    for (int i = 0; i < student_count; i++)
    {
        fprintf(file, "%s %s %d\n", students[i].name, students[i].department, students[i].year);
    }
    
    fclose(file);
    printf("Data saved successfully!\n");
}

void load_from_file()
{
    char filename[50];
    printf("\nEnter filename to open: ");
    scanf("%s", filename);
    
    FILE *file = fopen(filename, "r");
    if (!file)
    {
        printf("No previous data found.\n");
        return;
    }
    
    fscanf(file, "%d", &student_count);
    for (int i = 0; i < student_count; i++)
    {
        fscanf(file, "%s %s %d", students[i].name, students[i].department, &students[i].year);
    }
    
    fclose(file);
    printf("Data loaded successfully!\n");
}

void set_department_seats()
{
    for (int i = 0; i < MAX_DEPARTMENTS; i++) 
    {
        printf("Enter number of seats for %s: ", departments[i].name);
        scanf("%d", &departments[i].max_seats);
    }
    
    printf("\nDepartment seats set successfully!\n");
}

void add_student() 
{
    if (student_count >= MAX_STUDENTS)
    {
        printf("\nNo more seats available!\n");
        return;
    }
    
    Student s;
    printf("\nEnter Student Name: ");
    scanf("%s", s.name);
    printf("Enter Department (BCA/BBA/HHM/BMLT): ");
    scanf("%s", s.department);
    printf("Enter Year of Admission: ");
    scanf("%d", &s.year);
    
    for (int i = 0; i < MAX_DEPARTMENTS; i++) 
    {
        if (strcmp(departments[i].name, s.department) == 0) 
        {
            if (departments[i].current_students < departments[i].max_seats) 
            {
                students[student_count++] = s;
                departments[i].current_students++;
                printf("\nStudent Added Successfully to %s!\n", s.department);
                return;
            } 
            else 
            {
                printf("\nNo available seats in %s!\n", s.department);
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

void display_seats() 
{
    printf("\nDepartment Seat Availability:\n");
    printf("--------------------------------------------------\n");
    printf("BCA\t|\tBBA\t|\tBMLT\t|\tHHM\n");
    printf("--------------------------------------------------\n");
    printf("%d/%d\t|\t%d/%d\t|\t%d/%d\t|\t%d/%d\n", 
           departments[0].current_students, departments[0].max_seats,
           departments[1].current_students, departments[1].max_seats,
           departments[2].current_students, departments[2].max_seats,
           departments[3].current_students, departments[3].max_seats);
    printf("--------------------------------------------------\n");
    
    printf("\nStudent List:\n");
    for (int i = 0; i < MAX_DEPARTMENTS; i++) 
    {
        printf("%s:\n", departments[i].name);
        for (int j = 0; j < student_count; j++) 
        {
            if (strcmp(students[j].department, departments[i].name) == 0) 
            {
                printf("- %s (Year: %d)\n", students[j].name, students[j].year);
            }
            
        }
        
        printf("\n");
    }
}

int main() 
{
    int ch;
    char choice;
    
    do 
	{
         printf("\n**MENU**");
         printf("\n1. Set Department Seats");
         printf("\n2. Add New Student");
         printf("\n3. Transfer Student");
         printf("\n4. Display Seat Availability");
         printf("\n5. Save & Exit");
         printf("\n6. Open Previous File");
         printf("\nEnter Your Choice: ");
         scanf("%d", &ch);
        
         switch (ch) 
            { 
               case 1: set_department_seats(); 
		  	   break;
			 
               case 2: add_student(); 
			   break;
			 
               case 3: transfer_student(); 
			   break;
			 
               case 4: display_seats(); 
			   break;
			 
               case 5: save_to_file(); 
			   exit(0);
			 
               case 6: load_from_file(); 
			   break;
			 
               default: printf("\n Invalid Choice! Try Again.\n");
            }
         
         printf("\nDo you want to continue? (Y/N): ");
         scanf(" %c", &choice); 
    } 
    
	 while (choice == 'Y' || choice == 'y');
     return 0;
}
