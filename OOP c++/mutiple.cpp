// #include <iostream>
// #include <string>
// using namespace std;

// class Student // based class
// {
//     int total, boys, girls;

// public:
//     void getnum()
//     {
//         cout << "Enter total number of students" << endl;
//         cin >> total;
//         cout << "Enter total number of Boys" << endl;
//         cin >> boys;
//         cout << "Enter total number of girls" << endl;
//         cin >> girls;
//     }

//     void displays()
//     {
//         cout << "There are total " << total << endl;
//         cout << "In Which," << boys << "Boys and" << girls << "girls" << endl;
//     }
// };

// class teacher
// {
//     int trachers;

// public:
//     void gett()
//     {
//         cout << "Enter number of teachers"<< endl;
//         cin >> trachers;
//     }

//     void displayt()
//     {
//         cout << "There are total " << trachers << "teachers";
//     }
// };
// class G2 : public Student, public teacher // derived class from 2 based class
// {
//    public:
//     void getg2()
//     {
//         getnum();
//         gett();
//     }
//     void Display()
//     {
//         cout << "Information of class G2" << endl;
//         displays(); // member function of baesd class
//         displayt();
//     }
// };

// int main()
// {
//     G2 G;
//     G.getg2();
//     cout<<endl<<endl;
//     G.Display();
// }

// int main()
// {
//     int a, b, c;

//     cout << "Enter two values : ";
//     cin >> a >> b;

//     c = a - b;
//     //    try{
//     //        if(c==0){
//     //            throw (c);
//     //        }
//     cout << "Result of a/(a-b) = " << a / c << endl;
//     //  }
//     //  catch(int exp){
//     //       cout<<"\n\nException Handling\n"
//     //     << "Cant be Divide by Zero...\n";
//     //  }

//     return 0;
// }

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main (void) {

    int a, b;
    
     array<int,10> aaaa;

    cout << "Enter element and Enter position Where you want to enter array : ";
    cin >> b >> a;
   
   try {
     aaaa.at(a)=b;
   }
    catch (const out_of_range& error) {
      cout << "Array size is 10 \nOut of Range error: " << '\n';
   }
   return 0;
}