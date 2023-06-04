#include<iostream>
 using namespace std;

class base{
    int id;
    static int count;
    public : 
    base(){
        count++;
        id=count;
        count <<"c"<<id<<endl;
    }
    ~base(){
        count++;
        id=count;
        count <<"d"<<id<<endl;
    }
};
int base:: cout =0;

int main (){
  
base a[2];
   


     return 0;
}