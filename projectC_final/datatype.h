// noi khai bao thu vien va struct 
#define DATATYPE_H
#define DATATYPE_H

#define MAX_STUDENTS 100
#define MAX_TEACHERS 100 
//cau truc sinh vien 
typedef struct {
    int id;
    char name[50];
    int age;
    char major[50];
    char sdt[15];  // Thêm so dien thoai
    char email[50]; // Thêm email
    
} Student;

extern Student students[];  // Khai bao bien students la mang cac sinh vien, mang nay duoc khai bao o file khac
extern int studentCount;  // Khai bao bien studentCount, bien dem so luong sinh vien, duoc khai bao o file khac

//cau truc giao vien 
typedef struct {
    int id;
    char name[50];
    int age; 
    char major[50];
    char email[50];
    char sdt[15];
} Teacher;

extern Teacher teachers[];
extern int teacherCount;
 
//
               

