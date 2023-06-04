// Experiment No. 15
//(A)WRITE code to perform various operation on file handling
//(b)WRITE code to handle predefined and user defined exceptions

// PROGRAM 15(A):

#include <iostream>
#include <fstream>
using namespace std;
  

int main()
{
    // Creation of ofstream class object
    ofstream fout;
  
    string line="------ Welcome to Govenmwent Polytechnic Pune ------";
  
    
    fout.open("sample.txt");  // opening the file 
       
        fout << line << endl;  // writing in the file

  
    // Close the File
    fout.close();
  

    // Creation of ifstream class object to read the file
    ifstream fin;
  
    fin.open("sample.txt");
  
    // Execute a loop until EOF (End of File)
    while (fin) {
  
        // Read a Line from File
        getline(fin, line);
  
        // Print line in Console
        cout << line << endl;
    }
  
    // Close the file
    fin.close();
  
    return 0;
}




// Program (B -1):
//    // User defined Exception

// #include <iostream>

// using namespace std;

// int main(){
//     int a,b,c;

//     cout<<"Enter two values : ";
//     cin>>a>>b;        //  taking input

//     c=a-b;
//    try{
//        if(c==0){
//            throw (c);  // throwing error
//        }
//            cout<< "Result of a/(a-b) = " <<a/c<<endl;
//      }
//      catch(int exp){    // catching error
//           cout<<"\n\nException Handling\n"
//         << "Cant be Divide by Zero...\n";
//      }


//      return 0;
// }

// Program (B -2):
 
//    // predefined Exception

//  #include <iostream>
// #include <bits/stdc++.h>
// using namespace std;

// int main (void) {

//     int a, b;
    
//      array<int,10> aaaa;

//     cout << "Enter element and Enter position Where you want to enter array : ";
//     cin >> b >> a;
   
//    try {
//      aaaa.at(a)=b;
//    }
//     catch (const out_of_range& error) {
//       cout << "Array size is 10 \nOut of Range error: " << '\n';
//    }
//    return 0;
// }
