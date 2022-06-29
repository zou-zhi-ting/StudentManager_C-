//
// Created by SailingBoat on 2022/6/28.
//

#ifndef DEMO_STUDENT_STUDENT_H
#define DEMO_STUDENT_STUDENT_H

#include <iostream>
using namespace std;
#include<string>

class Student {
public:
    /**
     * 显示个人信息
     */
    virtual void Show_Info()=0;

    /**
     * 获取年级名称
     * @return
     */
    virtual string Get_Grade()=0;
    int m_id;
    string m_name;
    string m_sex;
    int m_grade;
    string m_class;
    int m_age;
};


#endif //DEMO_STUDENT_STUDENT_H
