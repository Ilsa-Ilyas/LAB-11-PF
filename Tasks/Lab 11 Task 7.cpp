#include <stdio.h>
#include <string.h>
struct Course {
    char courseID[10];
    char courseName[50];
    char instructorName[50];
    int credits;
};
struct Department {
    char departmentName[50];
    struct Course courses[10];
    int courseCount;
};
struct Department departments[10];
int departmentCount = 0;
void addDepartment() {
    if (departmentCount >= 10) {
        printf("Cannot add more departments.\n");
        return;
    }
    printf("Enter Department Name: ");
    scanf(" %[^\n]", departments[departmentCount].departmentName);
    departments[departmentCount].courseCount = 0;
    departmentCount++;
}
void addCourse() {
    char deptName[50];
    printf("Enter Department Name: ");
    scanf(" %[^\n]", deptName);
    for (int i = 0; i < departmentCount; i++) {
        if (strcmp(departments[i].departmentName, deptName) == 0) {
            if (departments[i].courseCount >= 10) {
                printf("Cannot add more courses to this department.\n");
                return;
            }
            struct Course *course = &departments[i].courses[departments[i].courseCount];
            printf("Enter Course ID: ");
            scanf("%s", course->courseID);
            printf("Enter Course Name: ");
            scanf(" %[^\n]", course->courseName);
            printf("Enter Instructor Name: ");
            scanf(" %[^\n]", course->instructorName);
            printf("Enter Credits: ");
            scanf("%d", &course->credits);
            departments[i].courseCount++;
            return;
        }
    }
    printf("Department not found.\n");
}
void displayDetails() {
    for (int i = 0; i < departmentCount; i++) {
        printf("Department: %s\n", departments[i].departmentName);
        for (int j = 0; j < departments[i].courseCount; j++) {
            struct Course *course = &departments[i].courses[j];
            printf(" Course ID: %s, Name: %s, Instructor: %s, Credits: %d\n",
                   course->courseID, course->courseName, course->instructorName, course->credits);
        }
    }
}
int main() {
    int choice;
    do {
        printf("1. Add Department\n2. Add Course\n3. Display Details\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: addDepartment(); break;
            case 2: addCourse(); break;
            case 3: displayDetails(); break;
            case 4: break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 4);
    return 0;
}