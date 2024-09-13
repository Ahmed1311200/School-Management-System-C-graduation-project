
#include<stdio.h>
#include<stdlib.h>
#include"STUDENT.h"
#include"STD_Types.h"
#include <string.h>


Node* head=NULL;
/***************************************************
 *          ~*~ Student Management Module ~*~      *
 ***************************************************
 * This file is part of the School Management      *
 * System and contains functions related to        *
 * managing student information.                   *
 *                                                 *
 * Functions included in this file:                *
 * 1. NEW_STUDENT()  - Add a new student.          *
 * 2. DELETE_STUDENT() - Delete a student.         *
 * 3. STUDENT_LIST()  - Display student list.      *
 * 4. STUDENT_EDIT()  - Edit student info.         *
 * 5. RANK_STUDENT()  - Rank students by score.    *
 * 6. STUDENT_SCORE() - Update student scores.     *
 ***************************************************/

/**
 * Function to create a new node and set its data.
 * @param student The student data to be stored in the node.
 * @return Pointer to the newly created node.
 **/
Node* create_node(Student student) {
    Node* new_node = (Node*)malloc(sizeof(Node)); // Allocate memory for the node
    if (new_node == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    new_node->student = student; // Assign student data to the node
    new_node->next = NULL;       // Initialize next pointer to NULL
    return new_node;
}

/**
 * Function to insert a new student at the beginning of the list.
 * @param head Pointer to the head of the linked list.
 * @param student The student data to be added.
 **/
void ADD_STUDENT(Node** head, Student student) {
    Node* new_node = create_node(student); // Create the new node
    new_node->next = *head;   // Point new node's next to current head
    *head = new_node;         // Update head to new node
}

/**
 * Function to check if a student ID already exists in the list.
 * @param head Pointer to the head of the linked list.
 * @param ID The ID to check.
 * @return 1 if ID exists, 0 otherwise.
 **/
int ID_EXISTS(Node* head, u32 ID) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->student.id == ID) {
            return 1; // ID exists
        }
        temp = temp->next;
    }
    return 0; // ID does not exist
}

/**
 * Function to prompt the user for student details and add the student to the list.
 * @param head Pointer to the head of the linked list.
 **/
void NEW_STUDENT(Node** head) {
    Student new_student;

    // Input student's name
    printf("Enter student's name: ");
    scanf(" %[^\n]%*c", new_student.name); // Read name including spaces

    // Input student's date of birth
    printf("Enter student's date of birth (YYYY-MM-DD): ");
    scanf(" %[^\n]%*c", new_student.birth); // Read date of birth

    // Input student's ID
    printf("Enter student's ID: ");
    scanf("%u", &new_student.id); // Read ID as an integer

    // Check if the ID already exists
    if (ID_EXISTS(*head, new_student.id)) {
        printf("Error: Student with ID %u already exists.\n", new_student.id);
        printf("Try entering a new student again.\n");
        return; // Exit if ID is already in use
    }

    // Input student's address
    printf("Enter student's address: ");
    scanf(" %[^\n]%*c", new_student.address); // Read address

    // Input student's phone number
    printf("Enter student's phone number: ");
    scanf(" %[^\n]%*c", new_student.phone); // Read phone number

    ADD_STUDENT(head, new_student); // Add new student to the list
}

/**
 * Function to delete a student at a specific position in the list.
 * @param head Pointer to the head of the linked list.
 **/
void DELETE_STUDENT(Node** head) {
    u32 position;
    printf("Enter the position of the student to delete: ");
    scanf("%d", &position);

    // Check if the list is empty
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node* temp = *head;

    // If position is the first one
    if (position == 0) {
        *head = temp->next;  // Move head to the next node
        free(temp);          // Free memory of the removed node
        printf("The student was deleted successfully!\n");
        return;
    }

    // Find the node before the one to be deleted
    for (int i = 0; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }

    // If position is out of range
    if (temp == NULL || temp->next == NULL) {
        printf("Position out of range.\n");
        return;
    }

    // Delete the node at the specified position
    Node* node_to_delete = temp->next;
    temp->next = node_to_delete->next;
    free(node_to_delete);  // Free memory of the removed node

    printf("Student has been successfully deleted.\n");
}


/** Function to sort students alphabetically
**@param head Pointer to the head of the linked list.
**/
void SORT_STUDENTS(Node** head) {
    if (*head == NULL || (*head)->next == NULL) {
        return; // List is empty or contains only one item
    }

    Node* current = *head;
    Node* index = NULL;
    Student temp;

    while (current != NULL) {
        index = current->next;
        while (index != NULL) {
            if (strcmp(current->student.name, index->student.name) > 0) {
                // Swap students
                temp = current->student;
                current->student = index->student;
                index->student = temp;
            }
            index = index->next;
        }
        current = current->next;
    }
}

/**
 * Function to print all elements of the student list.
 * @param head Pointer to the head of the linked list.
 **/
void STUDENT_LIST(Node* head) {
    if (head == NULL) {
        printf("The student list is empty.\n");
        return;
    }
    SORT_STUDENTS(&head);

    Node* temp = head;
    u32 student_number = 1;
    while (temp != NULL) {
        printf("\nStudent #%d\n", student_number);
        printf("Name     : %s\n", temp->student.name);
        printf("Date of Birth: %s\n", temp->student.birth);
        printf("ID       : %u\n", temp->student.id);
        printf("Address  : %s\n", temp->student.address);
        printf("Phone    : %s\n", temp->student.phone);
        printf("-----------------------------\n");

        temp = temp->next;
        student_number++;
    }
}
/**
 * Function to search for a student by ID.
 * @param head Pointer to the head of the linked list.
 * @param ID The ID to search for.
 * @return Pointer to the node containing the student data, or NULL if not found.
 **/
Node* search(Node* head, u32 ID) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->student.id == ID) {
            return temp; // Student found
        }
        temp = temp->next;
    }
    return NULL; // Student not found
}

/**
 * Function to update student information.
 * @param head Pointer to the head of the linked list.
 **/
void STUDENT_EDIT(Node* head) {
    u32 ID;
    printf("Enter the ID of the student to edit: ");
    scanf("%u", &ID);

    Node* student_node = search(head, ID);
    if (student_node != NULL) {
        // Display current student information
        printf("\t \tStudent Found:\n");
        printf("Name: %s\n", student_node->student.name);
        printf("Date of Birth: %s\n", student_node->student.birth);
        printf("ID: %d\n", student_node->student.id);
        printf("Address: %s\n", student_node->student.address);
        printf("Phone Number: %s\n", student_node->student.phone);

        // Allow user to update student information
        printf("\nEnter new name: ");
        scanf(" %[^\n]", student_node->student.name);

        printf("Enter new date of birth (YYYY-MM-DD): ");
        scanf(" %[^\n]", student_node->student.birth);

        printf("Enter new address: ");
        scanf(" %[^\n]", student_node->student.address);

        printf("Enter new phone number: ");
        scanf(" %[^\n]", student_node->student.phone);

        printf("Student information updated successfully!\n");
    } else {
        printf("Student with ID %u not found.\n", ID);
    }
}

/**
 * Function to categorize student performance based on their computer science score.
 * @param score The student's computer science score.
 * @return The grade category as a string.
 **/
const char* determine_grade(f32 score) {
    if (score >= 85) {
        return "Excellent";
    } else if (score >= 75) {
        return "Very Good";
    } else if (score >= 65) {
        return "Good";
    } else if (score >= 50) {
        return "Pass";
    } else {
        return "Fail";
    }
}

/**
 * Function to get a student's computer science score, calculate the grade,
 * and display the student's academic standing.
 * @param head Pointer to the head of the linked list.
 **/
void STUDENT_SCORE(Node* head) {
    u32 ID;
    f32 score;

    printf("Enter the student's ID: ");
    scanf("%u", &ID);

    Node *student_node = search(head, ID);

    if (student_node != NULL) {
        printf("Student Found: %s\n", student_node->student.name);

        // Prompt user for student's computer science score
        printf("Enter the student's score in Computer Science: ");
        if (scanf("%f", &score) != 1) {
            printf("Invalid input! Please enter a numeric score.\n");
            return;
        }

        if (score < 0 || score > 100) {
            printf("Invalid score! Please enter a score between 0 and 100.\n");
            return;
        }

        student_node->grades.computer_science_score = score;
    } else {
        printf("Student with ID %u not found.\n", ID);
    }
}

/**
 * Function to rank students based on their computer science score.
 * @param head Pointer to the head of the linked list.
 **/
void RANK_STUDENT(Node* head) {
    if (head == NULL) {
        printf("The student list is empty.\n");
        return;
    }

    Node* temp = head;
    u32 student_number = 1;

    while (temp != NULL) {
        printf("\nStudent #%d\n", student_number);
        printf("Name     : %s\n", temp->student.name);
        printf("ID       : %u\n", temp->student.id);
        printf("Score in Computer Science: %.2f\n", temp->grades.computer_science_score);
        printf("Grade    : %s\n", determine_grade(temp->grades.computer_science_score));
        printf("---------------------------------\n");

        temp = temp->next;
        student_number++;
    }
}

/**
 * Main menu function for the School Management System.
 * Displays options for various operations and handles user choices.
 **/
void MAIN_MENU() {
    u8 choose;  // Variable for user choice

    while (1) {
        // Display welcome message and options
        printf("\n***************************************************\n");
        printf("*      Welcome to the School Management System     *\n");
        printf("***************************************************\n");

        // Display menu options
        printf("\n Please select an option from the menu below:\n");
        printf("1. Add New Student\n");
        printf("2. Delete Student\n");
        printf("3. View Student List\n");
        printf("4. Edit Student Information\n");
        printf("5. Rank Students by Computer Science Score\n");
        printf("6. Update Student Scores\n");
        printf("7. Exit\n");
        printf("***************************************************\n");

        // User input
        printf("\n Enter your choice (1-7): ");
        scanf("%d", &choose);

        // Handle user choice
        switch (choose) {
            case 1:
                NEW_STUDENT(&head); // Add a new student
                break;
            case 2:
                DELETE_STUDENT(&head);  // Delete a student
                break;
            case 3:
                STUDENT_LIST(head);   // View student list
                break;
            case 4:
                STUDENT_EDIT(head);  // Edit student information
                break;
            case 5:
                RANK_STUDENT(head);  // Rank students by score
                break;
            case 6:
                STUDENT_SCORE(head);  // Update student scores
                break;
            case 7:
                printf("Exiting the system. Goodbye!\n");
                exit(0); // Exit the program
                break;
            default:
                printf("Incorrect entry, please re-enter.\n");
        }
    }
}

