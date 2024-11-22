#include <stdio.h>
#include <string.h>

#define MAX_EMPLOYEES 100

struct Employee {
    char name[50];
    char dob[15];
    int id;
    char department[50];
    float salary;
};

struct Employee employees[MAX_EMPLOYEES];
int count = 0;

void addEmployee() {
    if (count >= MAX_EMPLOYEES) {
        printf("Employee list is full.\n");
        return;
    }
    printf("Enter Name: ");
    scanf(" %[^\n]", employees[count].name);
    printf("Enter DOB: ");
    scanf("%s", employees[count].dob);
    printf("Enter ID: ");
    scanf("%d", &employees[count].id);
    printf("Enter Department: ");
    scanf(" %[^\n]", employees[count].department);
    printf("Enter Salary: ");
    scanf("%f", &employees[count].salary);
    count++;
}

void displayEmployees() {
    for (int i = 0; i < count; i++) {
        printf("Name: %s, DOB: %s, ID: %d, Department: %s, Salary: %.2f\n",
               employees[i].name, employees[i].dob, employees[i].id,
               employees[i].department, employees[i].salary);
    }
}

void deleteEmployee() {
    int id;
    printf("Enter Employee ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (employees[i].id == id) {
            for (int j = i; j < count - 1; j++) {
                employees[j] = employees[j + 1];
            }
            count--;
            printf("Employee deleted successfully.\n");
            return;
        }
    }
    printf("Employee not found.\n");
}

int main() {
    int choice;
    do {
        printf("1. Add Employee\n2. Delete Employee\n3. Display Employees\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: addEmployee(); break;
            case 2: deleteEmployee(); break;
            case 3: displayEmployees(); break;
            case 4: break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 4);
    return 0;
}