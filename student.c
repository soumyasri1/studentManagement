#include <stdio.h>
hashtag#include <stdlib.h>
hashtag#include <string.h>

hashtag#define MAX_STUDENTS 100

struct Student {
 int id;
 char name[50];
 int age;
 float marks;
};

struct Student students[MAX_STUDENTS];
int studentCount = 0;

void addStudent() {
 if (studentCount < MAX_STUDENTS) {
 printf("Enter student details:\n");
 printf("ID: ");
 scanf("%d", &students[studentCount].id);
 printf("Name: ");
 scanf("%s", students[studentCount].name);
 printf("Age: ");
 scanf("%d", &students[studentCount].age);
 printf("Marks: ");
 scanf("%f", &students[studentCount].marks);

 studentCount++;
 printf("Student added successfully.\n");
 } else {
 printf("Maximum student limit reached.\n");
 }
}

void displayStudents() {
 if (studentCount == 0) {
 printf("No students to display.\n");
 } else {
 printf("Student details:\n");
 printf("%-10s %-20s %-10s %-10s\n", "ID", "Name", "Age", "Marks");
 for (int i = 0; i < studentCount; i++) {
 printf("%-10d %-20s %-10d %-10.2f\n", students[i].id, students[i].name, students[i].age, students[i].marks);
 }
 }
}

void searchStudent(int id) {
 int found = 0;
 for (int i = 0; i < studentCount; i++) {
 if (students[i].id == id) {
 printf("Student found:\n");
 printf("ID: %d\n", students[i].id);
 printf("Name: %s\n", students[i].name);
 printf("Age: %d\n", students[i].age);
 printf("Marks: %.2f\n", students[i].marks);
 found = 1;
 break;
 }
 }
 if (!found) {
 printf("Student not found.\n");
 }
}

void updateStudent(int id) {
 for (int i = 0; i < studentCount; i++) {
 if (students[i].id == id) {
 printf("Enter updated details for student ID %d:\n", id);
 printf("Name: ");
 scanf("%s", students[i].name);
 printf("Age: ");
 scanf("%d", &students[i].age);
 printf("Marks: ");
 scanf("%f", &students[i].marks);
 printf("Student details updated successfully.\n");
 return;
 }
 }
 printf("Student not found.\n");
}

void deleteStudent(int id) {
 int found = 0;
 for (int i = 0; i < studentCount; i++) {
 if (students[i].id == id) {
 for (int j = i; j < studentCount - 1; j++) {
 students[j] = students[j + 1];
 }
 studentCount--;
 printf("Student deleted successfully.\n");
 found = 1;
 break;
 }
 }
 if (!found) {
 printf("Student not found.\n");
 }
}

int main() {
 int choice, id;

 do {
 printf("\nStudent Management System Menu:\n");
 printf("1. Add Student\n");
 printf("2. Display Students\n");
 printf("3. Search Student\n");
 printf("4. Update Student\n");
 printf("5. Delete Student\n");
 printf("6. Exit\n");
 printf("Enter your choice: ");
 scanf("%d", &choice);

 switch (choice) {
 case 1:
 addStudent();
 break;
 case 2:
 displayStudents();
 break;
 case 3:
 printf("Enter student ID to search: ");
 scanf("%d", &id);
 searchStudent(id);
 break;
 case 4:
 printf("Enter student ID to update: ");
 scanf("%d", &id);
 updateStudent(id);
 break;
 case 5:
 printf("Enter student ID to delete: ");
 scanf("%d", &id);
 deleteStudent(id);
 break;
 case 6:
 printf("Exiting...\n");
 break;
 default:
 printf("Invalid choice. Please try again.\n");
 }
 } while (choice != 6);

 return 0;
}