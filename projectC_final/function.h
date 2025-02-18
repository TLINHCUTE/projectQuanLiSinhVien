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

// Khai báo các hàm ðý?c s? d?ng ? file khác (ð? ðý?c ð?nh ngh?a trong Utils.c)
extern int isDuplicateID();       // Hàm ki?m tra ID có b? trùng không
extern int isValidEmail();        // Hàm ki?m tra ð?nh d?ng email h?p l?
extern void toLowerCase();        // Hàm chuy?n ð?i chu?i thành ch? thý?ng
extern void trimWhitespace();     // Hàm lo?i b? kho?ng tr?ng ð?u và cu?i chu?i
extern void pressAnyKeyToExit();  // Hàm d?ng màn h?nh và yêu c?u nh?n phím b?t k? ð? ti?p t?c

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

// Khai báo các hàm ðý?c s? d?ng ? file khác (ð? ðý?c ð?nh ngh?a trong Utils.c)
extern int isDuplicateID();       // Hàm ki?m tra ID có b? trùng không
extern int isValidEmail();        // Hàm ki?m tra ð?nh d?ng email h?p l?
extern void toLowerCase();        // Hàm chuy?n ð?i chu?i thành ch? thý?ng
extern void trimWhitespace();     // Hàm lo?i b? kho?ng tr?ng ð?u và cu?i chu?i
extern void pressAnyKeyToExit();  // Hàm d?ng màn h?nh và yêu c?u nh?n phím b?t k? ð? ti?p t?c

extern Teacher teachers[];
extern int teacherCount;



//ham tien ich 
int isDuplicateID();
int isValidEmail();
void toLowerCase();
void trimWhitespace();
void pressAnyKeyToExit();


