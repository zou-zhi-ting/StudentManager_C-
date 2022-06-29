//
// Created by SailingBoat on 2022/6/28.
//

#include "Grade01.h"

void Grade01::Show_Info() {
    cout<<"id: "<<this->m_id<<" "
        <<"name: "<<this->m_name<<" "
        <<"Grade: "<<this->Get_Grade()<<" "
        <<"sex: "<<this->m_sex<<" "
        <<"class: "<<this->m_class<<" "
        <<"age: "<<this->m_age<<" "<<endl;
}

string Grade01::Get_Grade() {
    return (string)"Grade 1";
}

Grade01::Grade01(int id, string name, int grade, string sex, string m_class, int age) {
    this->m_id=id;
    this->m_name=name;
    this->m_grade=grade;
    this->m_sex=sex;
    this->m_age=age;
    this->m_class=m_class;
}
