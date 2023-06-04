//inline functon
#include <iostream> //header file
using namespace std;
inline int sum(int a, int b) // inline function
{
    return a + b;
}
int main() // main function
{
    int a, b; // declaring variables
    cout << "Enter two numbers " << endl;
    cin >> a >> b;
    cout << "Sum of " << a << " and " << b
         << " is " << sum(a, b) << endl; // calling inline function
    return 0;
}

// //-------------friend function

// #include <iostream> //header file
// using namespace std;
// class rectangle
// {
// public:
//     int lgnt, bdth; // declaring variables
//     rectangle() {}
//     rectangle(int l, int b)
//     {
//         lgnt = l;
//         bdth = b;
//     }
//     friend void Area(rectangle); // declaration of friend function
//     void perimeter(void)         // member function
//     {
//         cout << "Perimeter of Rectangle is " << 2 * (lgnt + bdth) << endl;
//     }
// };

// void Area(rectangle R) // defining friend funtion
// {
//     cout << "Area of Rectangle is " << R.lgnt * R.bdth << endl;
// }

// int main() // main function
// {
//     rectangle R(20, 30); // declare object
//     R.perimeter();       // calling member function
//     Area(R);             // calling friend function
//     return 0;
// }

//--------------- static
// #include <iostream> //header file
// using namespace std;
// class sqre
// {
// public:
//     int len;             // declaring variable
//     static int objCount; // declareing static variable
//     sqre() {}
//     sqre(int l) //constructor
//     {
//         cout << "Constructor Called " << endl;
//         len = l;
//         objCount++;
//     }
//     void Area(void)
//     {
//         cout << "AREA IS " << len * len;
//     }
//     static int count(void) // static function
//     {
//         return objCount;
//     }
// };
// int sqre ::objCount = 0; //Initializing static variable
// int main()               // main function
// {
//     cout << "Initial count " << sqre::count() << endl; // calling satic function
//     sqre A(10);
//     sqre B(20);
//     sqre C(30);
//     cout << "Final count " << sqre::count() << endl; // calling satic function
//     return 0;
// }

// ----------------object as function argument and returning object

// #include <iostream> //header file
// using namespace std;
// class rectangle
// {
// public:
//     int lgnt, bdth, area; // declaring variables
//     rectangle() {}
//     rectangle(int l, int b)
//     {
//         lgnt = l;
//         bdth = b;
//     }
//     friend rectangle Area(rectangle); // declaration of friend function
//     void perimeter(void)              // member function
//     {
//         cout << "Perimeter of Rectangle is " << 2 * (lgnt + bdth) << endl;
//     }
// };
// rectangle Area(rectangle R) // object as function argument and returning object
// {
//     R.area = R.lgnt * R.bdth;
//     return R;
// }
// int main() // main function
// {
//     rectangle R(20, 30), R1; // declare object
//     R.perimeter();           // calling member function
//     R1 = Area(R);            // calling friend function
//     cout << "Area of REactagle is " << R1.area << endl;
//     return 0;
// }