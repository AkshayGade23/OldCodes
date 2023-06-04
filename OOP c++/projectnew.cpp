#include <iostream>
#include <fstream>
#include <string>
using namespace std;
// void gotoxy(int x, int y)
// {
//     printf("%c[%d;%df", 0x1B, y, x);
// }
class login
{
private:
    string user_id;  //user id
    string password; // password
public:
    void create_login(void) // to create id password
    {

        cout << "\ncreate user id:";
        cin >> user_id;
        cout << "\ncreate password:";
        cin >> password;
    }
    int log_in() // to log in
    {
        string s1, s2;
        cout << "\nEnter user id:";
        cin >> s1;
        cout << "\nEnter password:";
        cin >> s2;
        if (s1 == user_id && s2 == password)
        {
            cout << "You are successfully logged in";
            return 1;
        }

        return 0;
    }
};
class Display_Seats
{
public:
    void display_trains()
    {
        cout << "";
    }
};

class Train
{
public:
    int Tno[3] = {1001, 1002, 1003};
   const  char *source[3] = {"Pune", "Pune", "Pune"};
   const  char *dest[3] = {"Mumbai", "Nagpur", "Chennai"};
    const char *Atime[3] = {"9:10 AM", "8:10 AM", "7:10 AM"};
    //  Tno[0]=1001 ;
    //  Tno[1]=1002 ;
    //  Tno[2]=1003 ;
    int total_seats = 60;
    int fbooked[3] = {0, 0, 0};
    int sbooked[3] = {0, 0, 0};
    int fclass_rs[3] = {100, 150, 450};
    int sclass_rs[3] = {50, 75, 225};

    void display_train()
    {
        cout << endl
             << endl
             << "        **-----------------    Train Details     ----------------** \n";
        for (int i = 0; i < 3; i++)
        {
            cout << endl
                 << "\t\tTrain number :\t" << Tno[i] << endl
                 << "\t\tSource       : \t" << source[i] << endl
                 << "\t\tDestination  :\t" << dest[i] << endl
                 << "\t\tArrival time : \t" << Atime[i] << endl
                 << "\t\tFirst Class  :  30 seats     Booked : " << fbooked[i] << " seats" << endl
                 << "\t\tSecond Class :  30 seats     Booked : " << sbooked[i] << " seats" << endl
                 << endl
                 << endl;
        }
    }
    void Fbook(int rt_no, int b)
    {
        int i = check_train(rt_no);
        fbooked[i] = fbooked[i] + b;
    }

    void Sbook(int rt_no, int b)
    {
        int i = check_train(rt_no);
        sbooked[i] = sbooked[i] + b;
    }

    int check_train(int rt_no)
    {
        if (rt_no == Tno[0])
            return 0;

        else if (rt_no == Tno[1])
            return 1;

        else
            return 2;
    }

    int check_Fbook(int b, int rt_no)
    {
        int i = check_train(rt_no);

        int remaining = (total_seats / 2) - fbooked[i];

        if (b < remaining)
        {
            return 1;
        }
        cout << "Not enought seats available " << endl;
        return 0;
    }

    int check_Sbook(int b, int rt_no)
    {
        int i = check_train(rt_no);

        int remaining = (total_seats / 2) - sbooked[i];

        if (b < remaining)
        {
            return 1;
        }
        cout << "Not enought seats available " << endl;
        return 0;
    }
};

class Reservation : public Train
{
public:
    int rt_no, b;

    void TotalPrice(int rt_no, int b, char ch)
    {
        int price;
        int i = check_train(rt_no);
        if (ch == 'F')
        {
            price = fclass_rs[i] * b;
            cout << "Total Booked Tickets :" << b << endl;
            cout << "Class : First Class" << endl;
            cout << "Total Cost :" << price << endl;
        }
        else
        {
            price = sclass_rs[i] * b;
            cout << "Total Booked Tickets :" << b << endl;
            cout << "Class : Second Class" << endl;
            cout << "Total Cost :" << price << endl;
        }
    }

    int  res() //to reserve ticket
    {  int q;
        do
        {
            cout << "Enter train number:";
            cin >> rt_no;

            if (rt_no != Tno[0] && rt_no != Tno[1] && rt_no != Tno[2])
            {
                cout << "wrong Train number entered";
             q = 1;
            }
        }while(q==1);

        {
            char ch;
            do
            {
                cout << "Choose Class" << endl;
                cout << "F- First Class" << endl
                     << "S- Second Class" << endl;
                cin >> ch;

                switch (ch)
                {
                case 'F':
                    cout << "Enter number of tickets you want to book:";
                    cin >> b;
                    if (!check_Fbook(b, rt_no))
                    {
                        return 0;
                    }
                    TotalPrice(rt_no, b, ch);
                    Fbook(rt_no, b);
                    break;

                case 'S':
                    cout << "Enter number of tickets you want to book:";
                    cin >> b;
                    if (!check_Sbook(b, rt_no))
                    {
                        return 0;
                    }

                    TotalPrice(rt_no, b, ch);
                    Sbook(rt_no, b);
                    break;

                default:
                    cout << "Invalid Input" << endl;
                }
            } while (ch != 'F' && ch != 'S');
        }

        cout << "Your ticket booked successfully!!" << endl;
        return 1;
    }
};

class Ticket
{
public:
    int PNR;     //ticket no.
    string name; // booker name
    string time; //time
};
int main()
{
   // fstream f;
    // for (int i = 0; i < 21; i++)
    //     {
    //         gotoxy(9, i);
    //         cout << "|";
    //         gotoxy(75, i);
    //         cout << "|";
    //     }
   int x;
    Reservation t;
  //   getchar();
    x= t.res();
    t.display_train();
    return 0;
}
