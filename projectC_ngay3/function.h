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
void searchStudentByName();
void saveToCSV();
void displaySortMenu();
void sortStudentsAscending();
void sortStudentsDescending();
void pressAnyKeyToExit();

extern Student students[];  
extern int studentCount;
#endif

