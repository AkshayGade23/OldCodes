// Write aprogram to implement pointers.

#include <iostream>
#include <string>
using namespace std;

class Student   
{
    int id;
    string name;

public:
   void getvalues(){
       cout<<"Enter id of Student"<<endl;
       cin>>id;
       cout<<"Enter name of Student"<<endl;
       cin>>name;
    }

    void display(){
        cout<<"ID = "<<id <<endl;
        cout<<"NAME = "<<name <<endl;
    }
};


int main()
{
    Student *ptr= new(Student);    //pointe rof clas student

    ptr->getvalues();              // calling function with pointer
    cout<< endl;
    ptr->display();
    
}