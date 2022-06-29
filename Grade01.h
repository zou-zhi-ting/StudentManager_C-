//
// Created by SailingBoat on 2022/6/28.
//

#ifndef DEMO_STUDENT_GRADE01_H
#define DEMO_STUDENT_GRADE01_H
#include "Student.h"

class Grade01 :public Student{
public:
    void Show_Info() override;

    string Get_Grade() override;

    Grade01(int id,string name,int grade,string sex,string m_class,int age);
};


#endif //DEMO_STUDENT_GRADE01_H
