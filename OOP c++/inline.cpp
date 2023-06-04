#include<iostream>
using namespace std;

class subtraction{
    public:
       inline void  subtract(int a ,int b){
           cout<< "subtraction is : " <<a - b <<endl; 
         }
};

class factorial{
    int a;

    public:
    int  takevalue(){
        int v;
        cout << "ENTER THE VALUE FOR FACTORIAL"<< endl;
        cin >> v;        
        return  v;
    }

   void  factor(){
       int i;
        a=takevalue();

        for(i=a-1;i>=1;i--){
            a= a *i;
         }
         cout<< "FACTORIAL IS "<<a;
   }
};

int main(){
 
  subtraction s;
 s.subtract(11,5);

factorial f;
f.factor();
    return 0;
}