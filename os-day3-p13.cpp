#include <stdio.h>
#include <stdlib.h>

#define FILENAME "employee.dat"
#define RECORD_SIZE sizeof(struct Employee)

struct Employee {
    int id;
    char name[50];
    float salary;
};

void addEmployee();
void displayEmployee();
void modifyEmployee();

int main() {
    int choice;

    while (1) {
        printf("\nEmployee Database\n");
        printf("1. Add Employee\n");
        printf("2. Display Employee\n");
        printf("3. Modify Employee\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEmployee();
                break;
            case 2:
                displayEmployee();
                break;
            case 3:
                modifyEmployee();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}

void addEmployee() {
    FILE *file = fopen(FILENAME, "ab");
    if (file == NULL) {
        perror("Error opening file");
        exit(1);
    }

    struct Employee employee;

    printf("Enter Employee ID: ");
    scanf("%d", &employee.id);

    printf("Enter Employee Name: ");
    scanf(" %[^\n]", employee.name);

    printf("Enter Employee Salary: ");
    scanf("%f", &employee.salary);

    fseek(file, 0, SEEK_END);
    fwrite(&employee, RECORD_SIZE, 1, file);

    fclose(file);

    printf("Employee added successfully.\n");
}

void displayEmployee() {
    FILE *file = fopen(FILENAME, "rb");
    if (file == NULL) {
        perror("Error opening file");
        exit(1);
    }

    struct Employee employee;

    printf("\nEmployee Details:\n");

    while (fread(&employee, RECORD_SIZE, 1, file) == 1) {
        printf("ID: %d\n", employee.id);
        printf("Name: %s\n", employee.name);
        printf("Salary: %.2f\n", employee.salary);
        printf("----------------------\n");
    }

    fclose(file);
}

void modifyEmployee() {
    FILE *file = fopen(FILENAME, "rb+");
    if (file == NULL) {
        perror("Error opening file");
        exit(1);
    }

    int targetId;
    printf("Enter the ID of the employee to modify: ");
    scanf("%d", &targetId);

    struct Employee employee;

    int found = 0;
    while (fread(&employee, RECORD_SIZE, 1, file) == 1) {
        if (employee.id == targetId) {
            found = 1;

            printf("Enter new Employee Name: ");
            scanf(" %[^\n]", employee.name);

            printf("Enter new Employee Salary: ");
            scanf("%f", &employee.salary);

            fseek(file, -RECORD_SIZE, SEEK_CUR);
            fwrite(&employee, RECORD_SIZE, 1, file);

            printf("Employee modified successfully.\n");
            break;
        }
    }

    if (!found) {
        printf("Employee with ID %d not found.\n", targetId);
    }

    fclose(file);
}

