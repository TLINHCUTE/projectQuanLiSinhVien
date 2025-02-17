// khai bao ham

#ifndef FUNCTION_H
#define FUNCTION_H

void addStudent();
void displayMenu();
void displayStudents();
void deleteStudent();
void EditStudents();
void searchStudent();
void saveToCSV();
void loadFromCsv();
void displaySortMenu();
void sortStudentsAscending();
void sortStudentsDescending();
void pressAnyKeyToExit();
int isValidEmail();
void toLowerCase();
void trimWhitespace();

extern Student students[];  
extern int studentCount;
#endif

