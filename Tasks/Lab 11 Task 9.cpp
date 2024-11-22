#include <stdio.h>
#include <string.h>

#define MAX_DEPARTMENTS 10
#define MAX_COURSES 10
#define MAX_STUDENTS 50


struct Student {
    char name[50];
    int studentID;
};

struct Course {
    char courseID[10];
    char courseName[50];
    char instructorName[50];
    int credits;
    struct Student students[MAX_STUDENTS];
    int studentCount;
};

struct Department {
    char departmentName[50];
    struct Course courses[MAX_COURSES];
    int courseCount;
};

struct University {
    struct Department departments[MAX_DEPARTMENTS];
    int departmentCount;
};


struct University university = {0};


void addDepartment() {
    if (university.departmentCount >= MAX_DEPARTMENTS) {
        printf("Cannot add more departments.\n");
        return;
    }

    printf("Enter Department Name: ");
    scanf(" %[^\n]", university.departments[university.departmentCount].departmentName);
    university.departments[university.departmentCount].courseCount = 0;
    university.departmentCount++;
}

void addCourse() {
    char deptName[50];
    printf("Enter Department Name: ");
    scanf(" %[^\n]", deptName);

    for (int i = 0; i < university.departmentCount; i++) {
        if (strcmp(university.departments[i].departmentName, deptName) == 0) {
            if (university.departments[i].courseCount >= MAX_COURSES) {
                printf("Cannot add more courses to this department.\n");
                return;
            }

            struct Course *course = &university.departments[i].courses[university.departments[i].courseCount];
            printf("Enter Course ID: ");
            scanf("%s", course->courseID);
            printf("Enter Course Name: ");
            scanf(" %[^\n]", course->courseName);
            printf("Enter Instructor Name: ");
            scanf(" %[^\n]", course->instructorName);
            printf("Enter Credits: ");
            scanf("%d", &course->credits);
            course->studentCount = 0;

            university.departments[i].courseCount++;
            printf("Course added successfully.\n");
            return;
        }
    }
    printf("Department not found.\n");
}

void addStudent() {
    char deptName[50], courseID[10];
    printf("Enter Department Name: ");
    scanf(" %[^\n]", deptName);
    printf("Enter Course ID: ");
    scanf("%s", courseID);

    for (int i = 0; i < university.departmentCount; i++) {
        if (strcmp(university.departments[i].departmentName, deptName) == 0) {
            for (int j = 0; j < university.departments[i].courseCount; j++) {
                if (strcmp(university.departments[i].courses[j].courseID, courseID) == 0) {
                    struct Course *course = &university.departments[i].courses[j];

                    if (course->studentCount >= MAX_STUDENTS) {
                        printf("Cannot add more students to this course.\n");
                        return;
                    }

                    struct Student *student = &course->students[course->studentCount];
                    printf("Enter Student Name: ");
                    scanf(" %[^\n]", student->name);
                    printf("Enter Student ID: ");
                    scanf("%d", &student->studentID);

                    course->studentCount++;
                    printf("Student added successfully.\n");
                    return;
                }
            }
            printf("Course not found.\n");
            return;
        }
    }
    printf("Department not found.\n");
}

void displayDetails() {
    for (int i = 0; i < university.departmentCount; i++) {
        printf("Department: %s\n", university.departments[i].departmentName);
        for (int j = 0; j < university.departments[i].courseCount; j++) {
            struct Course *course = &university.departments[i].courses[j];
            printf(" Course ID: %s, Name: %s, Instructor: %s, Credits: %d\n",
                   course->courseID, course->courseName, course->instructorName, course->credits);
            printf(" Students:\n");
            for (int k = 0; k < course->studentCount; k++) {
                printf(" Name: %s, ID: %d\n", course->students[k].name, course->students[k].studentID);
            }
        }
    }
}

void calculateTotalCredits() {
    char deptName[50];
    printf("Enter Department Name: ");
    scanf(" %[^\n]", deptName);

    for (int i = 0; i < university.departmentCount; i++) {
        if (strcmp(university.departments[i].departmentName, deptName) == 0) {
            int totalCredits = 0;
            for (int j = 0; j < university.departments[i].courseCount; j++) {
                struct Course *course = &university.departments[i].courses[j];
                totalCredits += course->credits * course->studentCount;
            }
            printf("Total Credits for Department '%s': %d\n", deptName, totalCredits);
            return;
        }
    }
    printf("Department not found.\n");
}


int main() {
    int choice;

    do {
        printf("\nUniversity Management System\n");
        printf("1. Add Department\n");
        printf("2. Add Course\n");
        printf("3. Add Student\n");
        printf("4. Display Details\n");
        printf("5. Calculate Total Credits\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addDepartment(); break;
            case 2: addCourse(); break;
            case 3: addStudent(); break;
            case 4: displayDetails(); break;
            case 5: calculateTotalCredits(); break;
            case 6: printf("Exiting...\n"); break;
            default: printf("Invalid choice. Try again.\n");
        }
    } while (choice != 6);

    return 0;
}