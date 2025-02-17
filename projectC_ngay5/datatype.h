// noi khai bao thu vien va struct 
#define DATATYPE_H
#define DATATYPE_H

#define MAX_STUDENTS 100

typedef struct {
    int id;
    char name[50];
    int age;
    char major[50];
    char sdt[15];  // Thêm so dien thoai
    char email[50]; // Thêm email
    
} Student;


extern Student students[MAX_STUDENTS]; 
extern int studentCount;               

