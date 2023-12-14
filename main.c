#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct employee {
    char name[50];
    int employee_id;
    char position[50];
    float salary;
    struct employee* next;
};

struct employee* head = NULL;

// This function creates a new employee and returns a pointer to the new employee.
struct employee* createEmployee(char name[50], int id, char position[50], float salary) {
    // Allocate memory for a new employee struct.
    struct employee* newEmployee = (struct employee*)malloc(sizeof(struct employee));

    // Copy the name into the new employee struct.
    strcpy(newEmployee->name, name);

    // Set the employee ID.
    newEmployee->employee_id = id;

    // Copy the position into the new employee struct.
    strcpy(newEmployee->position, position);

    // Set the salary.
    newEmployee->salary = salary;

    // Initialize the next pointer to NULL.
    newEmployee->next = NULL;

    // Return the pointer to the new employee.
    return newEmployee;
}


// This function checks if an employee with the given name already exists in the linked list.
int checkDuplicate(char name[50]) {
    // Start from the head of the linked list.
    struct employee* temp = head;

    // Traverse the linked list.
    while (temp != NULL) {
        // If an employee with the same name is found, return 1.
        if (strcmp(temp->name, name) == 0) {
            return 1;
        }

        // Move to the next node in the linked list.
        temp = temp->next;
    }

    // If no employee with the same name is found, return 0.
    return 0;
}


// This function adds a new employee to the linked list.
void addEmployee(char name[50], int id, char position[50], float salary) {
    // Create a new employee.
    struct employee* newEmployee = createEmployee(name, id, position, salary);

    // Check if an employee with the same name already exists.
    if (checkDuplicate(newEmployee->name)){
        // If so, print a message and return.
        printf("Already this employee exists!\n");
        printf("--------------------\n");
        return;
    }

    // If the linked list is empty, make the new employee the head of the list.
    if (head == NULL) {
        head = newEmployee;
    } else {
        // Otherwise, traverse the list to the last node.
        struct employee* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        // Add the new employee at the end of the list.
        temp->next = newEmployee;
    }
}


// This function deletes an employee from the linked list.
void deleteEmployee(char name[50]) {
    // If the linked list is empty, print a message and return.
    if (head == NULL) {
        printf("The list is empty.\n");
        printf("--------------------\n");
        return;
    }

    // Start from the head of the linked list.
    struct employee* temp = head;
    struct employee* prev = NULL;

    // Traverse the linked list.
    while (temp != NULL) {
        // If an employee with the same name is found...
        if (strcmp(temp->name, name) == 0) {
            // If the employee is at the head of the list, move the head to the next node.
            if (prev == NULL) {
                head = temp->next;
            } else {
                // Otherwise, bypass the node to be deleted.
                prev->next = temp->next;
            }
            // Free the memory allocated for the employee to be deleted.
            free(temp);
            return;
        }
        // Move to the next node in the linked list.
        prev = temp;
        temp = temp->next;
    }

    // If no employee with the same name is found, print a message.
    printf("Employee not found.\n");
    printf("--------------------\n");
}


// This function searches for an employee in the linked list.
void searchEmployee(char name[50]) {
    // Start from the head of the linked list.
    struct employee* temp = head;

    // Traverse the linked list.
    while (temp != NULL) {
        // If an employee with the same name is found...
        if (strcmp(temp->name, name) == 0) {
            // Print the employee's details.
            printf("Name: %s\n", temp->name);
            printf("Employee ID: %d\n", temp->employee_id);
            printf("Position: %s\n", temp->position);
            printf("Salary: %.2f\n", temp->salary);
            printf("--------------------\n");
            return;
        }
        // Move to the next node in the linked list.
        temp = temp->next;
    }

    // If no employee with the same name is found, print a message.
    printf("Employee not found.\n");
    printf("--------------------\n");
}


// This function displays the details of all employees in the linked list.
void displayEmployees() {
    // Start from the head of the linked list.
    struct employee* temp = head;

    // Traverse the linked list.
    while (temp != NULL) {
        // Print the details of the current employee.
        printf("Name: %s\n", temp->name);
        printf("Employee ID: %d\n", temp->employee_id);
        printf("Position: %s\n", temp->position);
        printf("Salary: %.2f\n", temp->salary);
        printf("--------------------\n");

        // Move to the next node in the linked list.
        temp = temp->next;
    }
}


int main()
{
    // Initialize the employee ID to 100.
    int id = 100;

    // Start an infinite loop.
    while(1){
            int control;
            char name[50];
            char position[50];
            float salary;

            // Display the menu.
            printf("--------------------\n");
            printf("1. Add Employee\n");
            printf("2. Delete Employee\n");
            printf("3. Search Employee\n");
            printf("4. Display Employee\n");
            printf("5. Exit\n");
            printf("What do you want? (number): ");

            // Read the user's choice.
            scanf("%d",&control);
            getchar(); // Clear the newline character left in the buffer by scanf.
            printf("--------------------\n");

            // Perform the appropriate action based on the user's choice.
            if(control==1){
                    // If the user chose to add an employee...
                    printf("Please enter the information.\n");
                    printf("Name: ");
                    fgets(name, 50, stdin);
                    name[strcspn(name, "\n")] = '\0'; // Clear the newline character left in the buffer by fgets.

                    printf("Position: ");
                    fgets(position, 50, stdin);
                    position[strcspn(position, "\n")] = '\0'; // Clear the newline character left in the buffer by fgets.

                    printf("Salary: ");
                    scanf("%f",&salary);
                    getchar(); // Clear the newline character left in the buffer by scanf.

                    // Add the new employee.
                    addEmployee(name,id,position,salary);

                    // Increment the employee ID for the next employee.
                    id = id + 1;

            }
            else if(control==2){
                    // If the user chose to delete an employee...
                    printf("Deleting for(name): ");
                    fgets(name, 50, stdin);
                    name[strcspn(name, "\n")] = '\0'; // Clear the newline character left in the buffer by fgets.

                    // Delete the employee.
                    deleteEmployee(name);
            }
            else if(control==3){
                    // If the user chose to search for an employee...
                    printf("Searching for(name): ");
                    fgets(name, 50, stdin);
                    name[strcspn(name, "\n")] = '\0'; // Clear the newline character left in the buffer by fgets.

                    // Search for the employee.
                    searchEmployee(name);
            }
            else if(control==4){
                    // If the user chose to display all employees...
                    displayEmployees();
            }
            else if(control==5){
                    // If the user chose to exit...
                    printf("Exitting...");
                    break;
            }
            else{
                    // If the user entered an invalid choice...
                    printf("Please make a correct entry!\n");
            }
    }

    return 0;
}
