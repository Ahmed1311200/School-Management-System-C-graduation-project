#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED


#include <stdio.h>
#include"stdlib.h"
#include"STD_Types.h"


// ---------------------------------------------------
// Student Structure
// ---------------------------------------------------
// This structure represents a student and includes
// the following details:
// - name: Student's full name
// - birth: Date of birth in the format "YYYY-MM-DD"
// - id: Unique identifier for the student
// - address: Student's home address
// - phone: Student's phone number
//
// Each field is a character array of appropriate size
// to store the relevant information.
typedef struct {
    u8 name[100];    // Student's full name
    u8 birth[11];      // Date of birth (YYYY-MM-DD)
    u32 id;            // Unique student ID as an integer
    u8 address[200]; // Home address
    u8 phone[15];    // Phone number
} Student;


// ---------------------------------------------------
// Grades Structure
// ---------------------------------------------------
// This structure stores information about a student's
// computer science score, along with their unique ID.
typedef struct {
    u8 id;
    f32 computer_science_score;
} Grades;


// ---------------------------------------------------
// Definition of a Node in the Linked List
// ---------------------------------------------------
// This structure represents a node in a linked list,
// which contains student data and grades, and a pointer
// to the next node in the list.
typedef struct Node {
    Student student;       // Data structure to store student information
    Grades grades;         // Data structure to store student grades
    struct Node* next;     // Pointer to the next node in the list
} Node;


// ---------------------------------------------------
// Declaration of the Global Head Pointer
// ---------------------------------------------------
// External declaration of the head pointer used globally
extern Node* head;


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
Node* create_node(Student student);

/**
 * Function to insert a new student at the beginning of the list.
 * @param head Pointer to the head of the linked list.
 * @param student The student data to be added.
 **/
void ADD_STUDENT(Node** head, Student student);

/**
 * Function to check if a student ID already exists in the list.
 * @param head Pointer to the head of the linked list.
 * @param ID The ID to check.
 * @return 1 if ID exists, 0 otherwise.
 **/
int ID_EXISTS(Node* head, u32 ID);

// Function to add a new node at the beginning of the list
void ADD_NODE(Node** head, Student student);

/**
 * Function to prompt the user for student details and add the student to the list.
 * @param head Pointer to the head of the linked list.
 **/
void NEW_STUDENT(Node** head);

/**
 * Function to delete a student at a specific position in the list.
 * @param head Pointer to the head of the linked list.
 **/
void DELETE_STUDENT(Node** head);

/**
 * Function to print all elements of the student list.
 * @param head Pointer to the head of the linked list.
 **/
void STUDENT_LIST(Node* head);

/**
 * Function to search for a student by ID.
 * @param head Pointer to the head of the linked list.
 * @param ID The ID to search for.
 * @return Pointer to the node containing the student data, or NULL if not found.
 **/
Node* search(Node* head, u32 ID);


/**
 * Function to update student information.
 * @param head Pointer to the head of the linked list.
 **/
void STUDENT_EDIT(Node* head);

/**
 * Function to categorize student performance based on their computer science score.
 * @param score The student's computer science score.
 * @return The grade category as a string.
 **/
const char* determine_grade(f32 score);

/**
 * Function to get a student's computer science score, calculate the grade,
 * and display the student's academic standing.
 * @param head Pointer to the head of the linked list.
 **/
void STUDENT_SCORE(Node* head);

/**
 * Function to rank students based on their computer science score.
 * @param head Pointer to the head of the linked list.
 **/
void RANK_STUDENT(Node* head);

/**
 * Main menu function for the School Management System.
 * Displays options for various operations and handles user choices.
 **/
void MAIN_MENU();
#endif // STUDENT_H_INCLUDED
