//
// Created by SailingBoat on 2022/6/28.
//

#include "StudentManager.h"

StudentManager::StudentManager() {
    this->FileIsEmpty=false;
    ifstream ifs;
    ifs.open(FILENAME,ios::in);
    if(!ifs.is_open()){
        this->Student_num=0;
        this->FileIsEmpty=true;
        this->Student_Array= nullptr;
        ifs.close();
        return;
    }

    char ch;
    ifs>>ch;
    if(ifs.eof()){
        this->Student_num=0;
        this->FileIsEmpty= true;
        this->Student_Array= nullptr;
        ifs.close();
        return;
    }

    int num=this->get_StudentNum();
    this->Student_num=num;
    this->Student_Array=new Student*[this->Student_num];
    this->InitStudent();

}

StudentManager::~StudentManager() {

}

void StudentManager::Show_Menu() {
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "~~~~~~~~~~~~~~~~Student Manage System~~~~~~~~~~~~~~~~~~" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "******************(0) Exit System**********************" << endl;
    cout << "******************(1) Add Student**********************" << endl;
    cout << "******************(2) Show Info************************" << endl;
    cout << "******************(3) Delete Student*******************" << endl;
    cout << "******************(4) Modify Student*******************" << endl;
    cout << "******************(5) Find Student*********************" << endl;
    cout << "******************(6) Sort Student*********************" << endl;
    cout << "******************(7) Classify Student*****************" << endl;
    cout << "******************(8) Clear System*********************" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
}

void StudentManager::Exit_System() {
    cout << "Welcome next using..." << endl;
    system("pause");
    exit(0);
}

void StudentManager::Add_Student() {
    cout << "please input adding numbers" << endl;
    int addnum;
    cin >> addnum;
    if(addnum>0){
        int newsize=this->Student_num+addnum;
        Student** newspace=new Student*[newsize];
        if(nullptr==newspace){
            cout<<"Add failed!!"<<endl;
            system("pause");
            system("cls");
        }
        if(this->Student_Array!= nullptr){
            for(int i=0;i<this->Student_num;i++){
                newspace[i]=this->Student_Array[i];
            }
        }
        for(int i=0;i<addnum;i++){
            int id;
            string name;
            int select;
            string sex;
            string m_class;
            int m_age;
            cout<<"please input the "<<i+1<<" student id"<<endl;

            while(true){
                int flag=0;
                cin>>id;
                for(int i=0;i<this->Student_num;i++){
                    if(id==this->Student_Array[i]->m_id){
                        flag=1;
                        break;
                    }
                }
                if(!flag){
                    break;
                }else{
                    cout<<"the student exist, please input again"<<endl;
                }
            }
            cout << "please input the " << i + 1 << " student name" << endl;
            cin >> name;
            cout << "please input the " << i + 1 << " student grade" << endl;
            cout << "1 grade1" << endl;
            cout << "2 grade2" << endl;
            cout << "3 grade3" << endl;
            cout << "4 grade4" << endl;
            cin >> select;
            cout << "please input the " << i + 1 << " student sex" << endl;
            cin >> sex;
            cout << "please input the " << i + 1 << " student class" << endl;
            cin >> m_class;
            cout << "please input the " << i + 1 << " student age" << endl;
            cin >> m_age;
            Student* student= nullptr;
            switch(select){
                case 1:
                    student=new Grade01(id,name,1,sex,m_class,m_age);
                    break;
                case 2:
                    student=new Grade02(id,name,2,sex,m_class,m_age);
                    break;
                case 3:
                    student=new Grade03(id,name,3,sex,m_class,m_age);
                    break;
                case 4:
                    student=new Grade01(id,name,4,sex,m_class,m_age);
                    break;
                default:
                    break;
            }
            newspace[this->Student_num+i]=student;
        }
        delete[] this->Student_Array;
        this->Student_Array=newspace;
        this->Student_num=newsize;
        this->FileIsEmpty=false;
        cout<<"Add success "<<addnum<<" students"<<endl;
        this->Save();
    }else{
        cout<<"input error"<<endl;
    }
//    system("pause");
//    system("cls");
}

int StudentManager::get_StudentNum() {
    ifstream ifs;
    ifs.open(FILENAME,ios::in);
    int id;
    string name;
    int grade;
    string sex;
    string m_class;
    int m_age;
    int num=0;
    while(ifs>>id&&ifs>>name&&ifs>>grade&&ifs>>sex&& ifs >> m_class && ifs >> m_age){
        num++;
    }
    ifs.close();
    return num;
}

void StudentManager::Save() {
    ofstream ofs;
    ofs.open(FILENAME,ios::out);
    for(int i=0;i<this->Student_num;i++){
        ofs<<this->Student_Array[i]->m_id<<" "
            <<this->Student_Array[i]->m_name<<" "
            <<this->Student_Array[i]->m_grade<<" "
            <<this->Student_Array[i]->m_sex<<" "
            <<this->Student_Array[i]->m_class<<" "
            <<this->Student_Array[i]->m_age<<" "<<endl;
    }

}

void StudentManager::InitStudent() {
    ifstream ifs;
    ifs.open(FILENAME, ios::in);
    int id;
    string name;
    int grade;
    int index = 0;
    string sex;
    string m_class;
    int m_age;
    while (ifs >> id && ifs >> name && ifs >> grade && ifs >> sex && ifs >> m_class && ifs >> m_age)
    {
        Student* student = nullptr;//�����꼶����PSTU�Ķ���
        if (grade == 1)
        {
            student = new Grade01(id, name, grade, sex, m_class, m_age);
        }
        else if (grade == 2)
        {
            student = new Grade02(id, name, grade, sex, m_class, m_age);
        }
        else if (grade == 3)
        {
            student = new Grade03(id, name, grade, sex, m_class, m_age);
        }
        else
        {
            student = new Grade04(id, name, grade, sex, m_class, m_age);
        }
        //�����������
        this->Student_Array[index] = student;
        index++;

    }

}

void StudentManager::ShowStudent() {
    if (this->FileIsEmpty)
    {
        cout << "file is null or not exist" << endl;
    }
    else
    {
        for (int i = 0; i < this->Student_num; i++)
        {
            //���ö�̬���ýӿ�
            this->Student_Array[i]->Show_Info();
        }
    }
//    system("pause");
//    system("cls");
}

void StudentManager::DeleteStudent() {
    if(this->FileIsEmpty){
        cout<<"file is null or not exist"<<endl;
    }else{
        cout<<"please input delete student id"<<endl;
        int id=0;
        cin>>id;
        int index=this->IsExist(id);
        if(index!=-1){
            for(int i=index;i<this->Student_num-1;i++){
                this->Student_Array[i]=this->Student_Array[i+1];
            }
            this->Student_num--;
            this->Save();
            cout<<"delete success"<<endl;
        }else{
            cout<<"delete failed, can not find the student"<<endl;
        }
    }
//    system("pause");
//    system("cls");
}

int StudentManager::IsExist(int id) {
    int index = -1;
    for (int i = 0; i < this->Student_num; i++)
    {
        if (this->Student_Array[i]->m_id == id)
        {
            index = i;
            break;
        }
    }
    return index;
}

void StudentManager::FindStudent() {
    if(this->FileIsEmpty){
        cout<<"file is null or not exist"<<endl;
    }else{
        cout<<"please input find method"<<endl;
        cout<<"1 find with id"<<endl;
        cout<<"2 find with name"<<endl;

        int select=0;
        cin>>select;
        if(select==1){
            int id;
            cout<<"please input student id"<<endl;
            cin>>id;
            int ret=this->IsExist(id);
            if(ret!=-1){
                cout<<"find success, the information is:"<<endl;
                this->Student_Array[ret]->Show_Info();
            }else{
                cout<<"find failed, can not find"<<endl;
            }
        }else if(select==2){
            string name;
            cout<<"please input student name"<<endl;
            cin>>name;
            bool flag=false;
            for(int i=0;i<this->Student_num;i++){
                if(this->Student_Array[i]->m_name==name){
                    cout<<"find success, the information is:"<<endl;
                    flag=true;
                    this->Student_Array[i]->Show_Info();
                }
            }
            if(flag==false){
                cout<<"find failed, can not find"<<endl;
            }
        }else{
            cout<<"input error"<<endl;
        }
    }
//    system("pause");
//    system("cls");
}

void StudentManager::ModStudent() {
    if(this->FileIsEmpty){
        cout<<"file is null or not exist"<<endl;
    }else{
        cout<<"please input student id"<<endl;
        int id;
        cin>>id;
        int ret=this->IsExist(id);
        if(ret!=-1){
            delete this->Student_Array[ret];
            int newid=0;
            string newname="";
            int select=0;
            string newsex;
            string newclass;
            int newage;
            cout<<"find the "<<id<<" student,please input new id"<<endl;
            cin>>newid;
            cout<<"please input new name"<<endl;
            cin>>newname;
            cout<<"please input new grade"<<endl;
            cout << "1 grade1" << endl;
            cout << "2 grade2" << endl;
            cout << "3 grade3" << endl;
            cout << "4 grade4" << endl;
            cin>>select;
            cout<<"please input new sex"<<endl;
            cin>>newsex;
            cout<<"please input newclass"<<endl;
            cin>>newclass;
            cout<<"please input new age"<<endl;
            cin>>newage;
            Student* student= nullptr;
            switch(select){
                case 1:
                    student=new Grade01(id,newname,1,newsex,newclass,newage);
                    break;
                case 2:
                    student=new Grade02(id,newname,2,newsex,newclass,newage);
                    break;
                case 3:
                    student=new Grade03(id,newname,3,newsex,newclass,newage);
                    break;
                case 4:
                    student=new Grade04(id,newname,4,newsex,newclass,newage);
                    break;
                default:
                    break;
            }
            this->Student_Array[ret]=student;
            cout<<"Modify success"<<endl;
            this->Save();
        }else{
            cout<<"Modify failed, can not find the student"<<endl;
        }
    }
}

void StudentManager::CleanStudent() {
    cout << "ensure clear? " << endl;
    cout << "1 ok" << endl;
    cout << "2 return" << endl;
    int select = 0;
    cin >> select;
    if (select == 1)
    {
        //打开模式ios::trunc如果存在就删除文件并重新创建
        ofstream ofs(FILENAME, ios::trunc);
        ofs.close();
        if (this->Student_Array != NULL)
        {
            for (int i = 0; i < this->Student_num; i++)
            {
                if (this->Student_Array[i] != NULL)
                {
                    delete this->Student_Array[i];
                }
            }
            this->Student_num = 0;
            delete[] this->Student_Array;
            this->Student_Array = NULL;
            this->FileIsEmpty = true;
        }
        cout << "clear success" << endl;
    }
}

void StudentManager::SortStudent() {
    if (this->FileIsEmpty)
    {
        cout << "file not exist or is null" << endl;
//        system("pause");
//        system("cls");

    }
    else
    {
        cout << "please select sorted method" << endl;
        cout << "1 increased" << endl;
        cout << "2 decreased" << endl;

        int select = 0;
        cin >> select;

        for (int i = 0; i < this->Student_num; i++)
        {
            int minOrmax = i;
            for (int j = i + 1; j < this->Student_num; j++)
            {
                if (select == 1)
                {
                    if (this->Student_Array[minOrmax]->m_id > this->Student_Array[j]->m_id)
                    {
                        minOrmax = j;
                    }
                }
                else
                {
                    if (this->Student_Array[minOrmax]->m_id < this->Student_Array[j]->m_id)
                    {
                        minOrmax = j;
                    }
                }
            }
            if (i != minOrmax)
            {
                Student* temp = this->Student_Array[i];
                this->Student_Array[i] = this->Student_Array[minOrmax];
                this->Student_Array[minOrmax] = temp;
            }
        }
        cout << "sorted success" << endl;
        this->Save();
//        system("pause");
//        system("cls");
    }
}

void StudentManager::ClassifyStudent() {
    if (this->FileIsEmpty)
    {
        cout << "file is not exist or is null" << endl;
    }
    else {

        cout << "Grade 1" << endl;
        for (int i = 0; i < this->Student_num; i++)
        {
            if (this->Student_Array[i]->m_grade == 1)
            {
                this->Student_Array[i]->Show_Info();
            }
        }
        cout << endl;
        cout << "Grade 2" << endl;
        for (int i = 0; i < this->Student_num; i++)
        {
            if (this->Student_Array[i]->m_grade == 2)
            {
                this->Student_Array[i]->Show_Info();
            }
        }
        cout << endl;
        cout << "Grade 3" << endl;
        for (int i = 0; i < this->Student_num; i++)
        {
            if (this->Student_Array[i]->m_grade == 3)
            {
                this->Student_Array[i]->Show_Info();
            }
        }
        cout << endl;
        cout << "Grade 4" << endl;
        for (int i = 0; i < this->Student_num; i++)
        {
            if (this->Student_Array[i]->m_grade == 4)
            {
                this->Student_Array[i]->Show_Info();
            }
        }
    }
}

