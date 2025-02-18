#include "datatype.h" 

//ham sinh vien 
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

// Khai b�o c�c h�m ��?c s? d?ng ? file kh�c (�? ��?c �?nh ngh?a trong Utils.c)
extern int isDuplicateID();       // H�m ki?m tra ID c� b? tr�ng kh�ng
extern int isValidEmail();        // H�m ki?m tra �?nh d?ng email h?p l?
extern void toLowerCase();        // H�m chuy?n �?i chu?i th�nh ch? th�?ng
extern void trimWhitespace();     // H�m lo?i b? kho?ng tr?ng �?u v� cu?i chu?i
extern void pressAnyKeyToExit();  // H�m d?ng m�n h?nh v� y�u c?u nh?n ph�m b?t k? �? ti?p t?c

extern Student students[];  // Khai bao bien students la mang cac sinh vien, mang nay duoc khai bao o file khac
extern int studentCount;  // Khai bao bien studentCount, bien dem so luong sinh vien, duoc khai bao o file khac


//ham giao vien 
void addTeacher();
void displayMenuTeachers();
void displayTeachers();
void deleteTeacher();
void EditTeachers();
void searchTeacher();
void saveToTeacherCSV();
void loadFromTeacherCsv();
void displaySortMenuTeachers();
void sortTeachersAscending();
void sortTeachersDescending();

// Khai b�o c�c h�m ��?c s? d?ng ? file kh�c (�? ��?c �?nh ngh?a trong Utils.c)
extern int isDuplicateID();       // H�m ki?m tra ID c� b? tr�ng kh�ng
extern int isValidEmail();        // H�m ki?m tra �?nh d?ng email h?p l?
extern void toLowerCase();        // H�m chuy?n �?i chu?i th�nh ch? th�?ng
extern void trimWhitespace();     // H�m lo?i b? kho?ng tr?ng �?u v� cu?i chu?i
extern void pressAnyKeyToExit();  // H�m d?ng m�n h?nh v� y�u c?u nh?n ph�m b?t k? �? ti?p t?c

extern Teacher teachers[];
extern int teacherCount;



//ham tien ich 
int isDuplicateID();
int isValidEmail();
void toLowerCase();
void trimWhitespace();
void pressAnyKeyToExit();


