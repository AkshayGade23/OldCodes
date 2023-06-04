// 1906025 Akshay Gade
// Experiment No. 17

//code to perform various operation on file handling
#include <iostream>
#include <fstream>
using namespace std;
  
class matrix 
{
 int s[10][3];

 public:
   void set(){
       int k ;
       cin>>k;
       for(int i=0; i<10;i++){
           for(int j=0;j<3;j++)
             s[i][j]=k;
       }
   }
   void putt(){
       for(int i=0; i<10;i++){
           for(int j=0;j<3;j++)
            cout<< " "<< s[i][j];

            cout<<endl;
       }
       
   }

};

int main()
{
    // Creation of ofstream class object
    ofstream fout;
    matrix m;
    m.set();

  
    // string line="------ Welcome to Govenmwent Polytechnic Pune ------";
  
    
    fout.open("sample.txt",ios::app);  // opening the file 
       fout.write((char*)&m,sizeof(m));
       // fout << line << endl;
       m.set();

  fout.write((char*)&m,sizeof(m));
    // Close the File
    fout.close();
  

    // Creation of ifstream class object to read the file
    ifstream fin;
  
    fin.open("sample.txt");
     fin.read((char*)&m,sizeof(m));
     while(!fin.eof()){
         m.putt();
          fin.read((char*)&m,sizeof(m));

     }
    // Execute a loop until EOF (End of File)
    // while (fin) {
  
    //     // Read a Line from File
    //    // getline(fin, line);
  
    //     // Print line in Console
    //    // cout << line << endl;
    // }
  
    // Close the file
    fin.close();
  
    return 0;
}