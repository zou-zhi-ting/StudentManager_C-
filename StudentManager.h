//
// Created by SailingBoat on 2022/6/28.
//

#ifndef DEMO_STUDENT_STUDENTMANAGER_H
#define DEMO_STUDENT_STUDENTMANAGER_H
#include<iostream>
using namespace std;
#include<string>
#include<fstream>
#include "Student.h"
#include "Grade01.h"
#include "Grade02.h"
#include "Grade03.h"
#include "Grade04.h"
#define FILENAME "empFile.txt"
class StudentManager {
public:
    int Student_num;

    Student** Student_Array;

    StudentManager();

    void Show_Menu();

    void Add_Student();

    void Save();

    void Exit_System();

    bool FileIsEmpty;

    int get_StudentNum();

    void InitStudent();

    void ShowStudent();

    void DeleteStudent();

    int IsExist(int id);

    void FindStudent();

    void ModStudent();

    void SortStudent();

    void CleanStudent();

    void ClassifyStudent();

    virtual ~StudentManager();
};


#endif //DEMO_STUDENT_STUDENTMANAGER_H
