// khai bao ham

#ifndef FUNCTION_H
#define FUNCTION_H

void addStudent();
void displayMenu();
void displayStudents();
void deleteStudent();
void saveToFile();
void loadFromFile();
void EditStudents();
void displayAddStudentMenu();
void displayEditStudentMenu();
void displayDeleteStudentMenu();

extern Student students[];  
extern int studentCount;
#endif

