#include "StudentManager.h"

int main(){
    StudentManager stu;
    int choice;

    while(true){
        stu.Show_Menu();
        cout<<"please input your choice:"<<endl;
//        cout<<"0:退出系统; 1:录入学生; 2:显示学籍; 3:删除学生; 4:修改学生;"<<endl;
//        cout<<"5:查找学生; 6:学生排序; 7:分类显示; 8:清空系统。"<<endl;
        cin>>choice;
        switch (choice){
            case 0:
                stu.Exit_System();
                break;
            case 1:
                stu.Add_Student();
                break;
            case 2:
                stu.ShowStudent();
                break;
            case 3:
                stu.DeleteStudent();
                break;
            case 4:
                stu.ModStudent();
                break;
            case 5:
                stu.FindStudent();
                break;
            case 6:
                stu.SortStudent();
                break;
            case 7:
                stu.ClassifyStudent();
                break;
            case 8:
                stu.CleanStudent();
                break;
            default:
                cout<<"输入错误，请重新输入！"<<endl;
                system("pause");
                system("cls");
                break;
        }
    }
}