#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <stdlib.h>

using namespace std;

//function declaraton
void UserLogin(void);
void AdminLogin(void);
void UserMenu(void);

// class Declaration
class trainn;
class Reservation;
class login;

fstream file_Ticket;
int Index;

class login
{
private:
    char user_id[20];  //user id
    char password[20]; // password
public:
    fstream f;
    friend void UserLogin(void);
    void create_login() // to create id password
    {
        cout << "\n\n          -----------------    Creating Account     ---------------- \n\n"
             << "\n                     Create USER ID  : ";
        cin >> user_id;
        cout << "\n                     Create PASSWORD : ";
        cin >> password;
    }
};

class trainn
{
public:
    fstream f;
    int max_T = 4;
    int added_train = 2;
    int Tno[4] = {1002, 1003};
    char source[4][10] = {"Pune", "Pune", "Pune", "Pune"};
    char dest[4][50] = {"Nagpur", "Chennai", "pune", "pune"};
    char Atime[4][50] = {"8:10 AM", "7:10 AM", "12:00 AM", "12:00 AM"};

    int total_seats = 60;

    int fbooked[4] = {0, 0, 0, 0};
    int sbooked[4] = {0, 0, 0, 0};
    
    int fclass_rs[4] = {100, 150};
    int sclass_rs[4] = {50, 75};
    
    void add_train() //adding new trains
    {
        if (added_train == 4) //checking if train entry is full
        {
            cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
             << "\t\t\t\t --X-- No more trains can be added --X--" << endl;
            system("pause");
            system("cls");
        }
        else
        {
            cout << "\n\n\n\n\n\n\n\n\n\n\n\n";
            cout << "\t\t\t\t\t       *----------* Adding Trains *----------*    " << endl;
            //taking input
            cout << endl
                 << endl
                 << "\t\t\t\t\t             Enter the TRAIN NUMBER : ";
            cin >> Tno[added_train];

            cout << "\n\t\t\t\t\t             Enter SOURCE of the train : ";
            scanf("%s", &source[added_train][0]);

            cout << "\t\t\t\t\t             Enter DESTINATION of the train : ";
            scanf("%s", &dest[added_train][0]);

            cout << "\n\t\t\t\t\t             Enter ARRIVAL TIME of the train : ";
            scanf("%s", &Atime[added_train][0]);

            cout << "\n\t\t\t\t\t             Enter F-Class seat price : ";
            cin >> fclass_rs[added_train];

            cout << "\t\t\t\t\t             Enter S-Class seat price : ";
            cin >> sclass_rs[added_train];

            cout << endl;
            added_train++;
        }
    }
    void display_train()
    {
        cout << endl<< endl
             << "\t\t\t\t      **-----------------    Train Details     ----------------** \n\n";
        for (int i = 0; i < added_train; i++)
        {
            cout << "\n\t\t\t\t            Train number :\t" << Tno[i] << endl;
            printf("\t\t\t\t            Source       :\t");
            puts(source[i]);
            printf("\t\t\t\t            Destination  :\t%s \n", dest[i]);
            printf("\t\t\t\t            Arrival Time :\t%s \n", Atime[i]);
            cout << "\t\t\t\t            First Class  :  30 seats        Booked : " << fbooked[i] << " seats" << endl
                 << "\t\t\t\t            Second Class :  30 seats        Booked : " << sbooked[i] << " seats" << endl
                 << endl<< endl;
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
        cout << "\t\t\t --X-- Not enough Seats available --X-- " << endl;
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
        cout << "\t\t\t --X-- Not enough Seats available --X-- " << endl;
        return 0;
    }
};

class Reservation : public trainn
{
public:
    int rt_no, b, PNR;
    int TotalRS;
    char clss;

    int res() //to reserve ticket
    {
        cout << "\n\n\n\n\n\n\n\n\n\n"
         << "\t\t\t\t       --------------- Ticket Registration -------------- \n\n"
        << "\t\t\t\t                    Enter TRIAN NUMBER : ";
        cin >> rt_no;

        if (rt_no != Tno[0] && rt_no != Tno[1] && rt_no != Tno[2])
        {
            cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
             << "\t\t\t\t                         --X-- Invalid Train Number --X--" << endl;
            return 0;
        }
        {
            do
            {
                cout << "\t\t\t\t                    Choose Class" << endl
                 << "\t\t\t\t                   F - First Class  ,  S - Second Class  :: ";
                cin >> clss;

                switch (clss)
                {
                case 'F':
                    cout << "\n\t\t\t\t                    Enter number of tickets you want to book : ";
                    cin >> b;
                    cout << endl;
                    if (!check_Fbook(b, rt_no))
                    {
                        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
                         << "\t\t\t\t                   --X-- Not enough Tickets Available --X-- " << endl<< endl;
                        return 0;
                    }
                    TotalPrice(rt_no, b, clss);
                    Fbook(rt_no, b);
                    break;

                case 'S':
                    cout << "\t\t\t\t                    Enter number of tickets you want to book : ";
                    cin >> b;
                    if (!check_Sbook(b, rt_no))
                    {
                        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
                        << "\t\t\t\t                     --X-- Not enough Tickets Available --X-- " << endl;
                        return 0;
                    }

                    TotalPrice(rt_no, b, clss);
                    Sbook(rt_no, b);
                    break;

                default:
                    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
                     << "\t\t\t\t                          --X-- Invalid Input --X--" << endl;
                }
            } while (clss != 'F' && clss != 'S');
        }
        return 1;
    }

    void TotalPrice(int rt_no, int b, char clss)
    {
        ifstream fin;
        ofstream fout;

        fin.open("PNR.txt", ios::in);
        fin >> Index;
        file_Ticket.close();

        Index++;
        PNR = Index;

        int i = check_train(rt_no);
        cout << "\n\t\t\t\t                   Ticket No. : " << PNR << endl;
        if (clss == 'F')
        {
            TotalRS = fclass_rs[i] * b;
            cout << "\t\t\t\t                   Total Booked Tickets :" << b << endl
             << "\t\t\t\t                   Class : First Class" << endl
             << "\t\t\t\t                   Total Cost :" << TotalRS << endl;
        }
        else
        {
            TotalRS = sclass_rs[i] * b;
            cout << "\t\t\t\t                   Total Booked Tickets :  " << b << endl
             << "\t\t\t\t                   Class : Second Class" << endl
             << "\t\t\t\t                   Total Cost :  " << TotalRS << endl;
        }

        fout.open("PNR.txt", ios::trunc);
        fout << Index;
        fout.close();
    }

    void Display_Ticket()
    {
        cout << "\n\n\t\t\t\t                        ----- Indian Railwyas ----- \n\n"
             << "\t\t\t\t                            Ticket No. : " << PNR << endl
             << "\t\t\t\t                            Train No.  : " << rt_no << endl
             << "\t\t\t\t                            Booked Tickets : " << b << endl

             << "\t\t\t\t                            Source     :  " << source[check_train(rt_no)] << "\tDestination  : " << dest[check_train(rt_no)] << endl
             << "\t\t\t\t                            Arrival Time   : " << Atime[check_train(rt_no)] << endl
             << "\t\t\t\t                            Class      : " << clss << endl;
        if (clss == 'F')
            cout << "\t\t\t\t                            Price      : " << fclass_rs[check_train(rt_no)] << " * " << b << " = " << TotalRS << endl;

        else
            cout << "\t\t\t\t                            Price      : " << sclass_rs[check_train(rt_no)] << " * " << b << " = " << TotalRS << endl;
    }
    void Delete_Ticket(int tick_no)
    {
        ifstream fin;
        ofstream fout;
        int flag;

        fin.open("Reservation.txt", ios::in);
        fout.open("Temp.txt", ios::out);
        fin.read((char *)this, sizeof(*this));

        while (!fin.eof())
        {
            if (this->PNR == tick_no)
                flag = 1;

            else
                fout.write((char *)this, sizeof(*this));

            fin.read((char *)this, sizeof(*this));
        }

        fout.close();
        fin.close();

        remove("Reservation.txt");
        rename("Temp.txt", "Reservation.txt");

        if (flag == 0)
        {
            cout << "\n\n\n"
                 << "\t\t\t\t                  --X-- Invalid Ticket Number --X--" << endl
                 << "\t\t\t\t                            --- TRY AGAIN --- " << endl;
            system("pause");
            system("cls");
            return;
        }

        cout << "\n\n\n\n\n"
             << "\t\t\t\t                  Your Reservation has been Cancelled......  " << endl;
        system("pause");
        system("cls");
    }
};

char AdminPassword[20] = "vinayakshay";
Reservation Train;

int main()
{
    int ch;
    cout << "\n\n\t\t\t\t\t\t  <---------------  WELCOME TO INDIAN RAILWAYS  --------------->\n " << endl;
    do
    {
        cout << "\n\n\n\n\n\n\n\n"
             << "\t\t\t\t\t\t        **-----------------  Main Menu  ----------------** \n\n"
             << "\t\t\t\t\t\t                          1. Admin  " << endl
             << "\t\t\t\t\t\t                          2. User" << endl
             << "\t\t\t\t\t\t                          3. Exit " << endl<< endl
             << "\n\t\t\t\t\t                 Enter Your Choice  :  ";
        cin >> ch;
        system("cls");

        switch (ch)
        {
        case 1:
            AdminLogin();
            system("cls");
            break;

        case 2:

            UserLogin();
            system("cls");
            break;

        case 3:
            cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
                 << "\t\t\t\t\t            Thank You For Visiting Indian Railways!!" << endl
                 << " \n\n\t\t\t\t\t     ------------------ X-X-X-X-X-X --------------------             \n\n"
                 << "\t\t\t\t\t\t\t\t\t\t            Created by :" << endl
                 << "\t\t\t\t\t\t\t\t\t\t                           Vinay Bhujbal ( 1906012 )" << endl
                 << "\t\t\t\t\t\t\t\t\t\t                           Akshay Gade   ( 1906025 ) " << endl<< endl;
            system("pause");
            exit(0);
        }
    } while (ch > 0 && ch <= 3);

    return 0;
}

void AdminLogin()
{
    char s2[20];

    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
         << "\n\n\t\t\t\t\t                   Enter ADMIN Password :  ";
    cin >> s2;
    system("cls");
    if (strcmp(AdminPassword, s2))
    {
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
             << "\n\n\t\t\t\t\t                  --X-- Invalid Userid / Password --X--" << endl
             << "\t\t\t\t\t                            --- TRY AGAIN --- \n\n\n"
             << endl;
        system("pause");
        system("cls");
    }
    else
    {
        int ch;
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
             << "\t\t\t\t\t              ------------- Logged in as Admin ------------ \n\n\n\n";
        system("pause");
        system("cls");

        do
        {
            cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
             << "\t\t\t\t\t        **-----------------     Admin Menu    ----------------** \n\n"
             << "\t\t\t\t\t                          1. Display Trian Details " << endl
             << "\t\t\t\t\t                          2. Add new Train" << endl
             << "\t\t\t\t\t                          3. Return " << endl<< endl
             << "\n\t\t\t\t\t                    Enter Your Choice  :  ";
            cin >> ch;
            system("cls");

            switch (ch)
            {
            case 1:
                Train.display_train();
                system("pause");
                system("cls");
                break;

            case 2:
                Train.add_train();
                system("pause");
                system("cls");
                break;
            }
        } while (ch < 3 && ch > 0);
    }
}

void UserLogin()
{
    char s1[20], s2[20];
    login ll;
    int ch, flag = 0;
    do
    {
        cout << "\n\n\n\n\n\n\n\n\n\n\n"
             << "\t\t\t\t          -----------------  User Login   ---------------- \n\n"
             << "\t\t\t\t                           1. Create Login " << endl
             << "\t\t\t\t                           2. Login" << endl
             << "\t\t\t\t                           3. Return " << endl << endl
             << "\t\t\t\t                       Enter Your Choice  :  ";
        cin >> ch;
        system("cls");

        switch (ch)
        {
        case 1:
            file_Ticket.open("login.txt", ios::app);
            ll.create_login();
            file_Ticket.write((char *)&ll, sizeof(ll));
            file_Ticket.close();
            
            system("pause");
            system("cls");
            break;

        case 2:
            cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
                 << "\n\t\t\t\t                     Enter USER ID : ";
            cin >> s1;
            cout << "\n\t\t\t\t                     Enter PASSWORD : ";
            cin >> s2;
            
            system("cls");
            
            file_Ticket.open("login.txt", ios::in);
            file_Ticket.read((char *)&ll, sizeof(ll));

            while (!file_Ticket.eof())
            {
                if (!(strcmp(ll.user_id, s1)) && !(strcmp(ll.password, s2)))
                {
                    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
                         << "\n\n\t\t\t\t                   -----  You are Successfully Logged in  ----- \n\n" << endl;
                    system("pause");
                    system("cls");
                    flag = 1;
                    UserMenu();
                    break;
                }
                file_Ticket.read((char *)&ll, sizeof(ll));
            }

            if (!flag)
            {
                cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
                     << "\t\t\t\t                 --X-- Invalid Userid / Password --X--" << endl
                     << "\t\t\t\t                          --- TRY AGAIN --- " << endl;
                system("pause");
                system("cls");
            }

            file_Ticket.close();
            break;
        }
    } while (ch > 0 && ch < 3);
}

void UserMenu()
{
    int flag, x, ch;
    ifstream fout;
    ofstream fin;

    do
    {
        cout << "\n\n\n\n\n\n\n\n\n\n\n"
         << "\t\t\t\t        **-----------------    User Login     ----------------** \n\n"
         << "\t\t\t\t                        1. Display Trian Details  " << endl
         << "\t\t\t\t                        2. Ticket Reservation " << endl
         << "\t\t\t\t                        3. Display Booked Ticket " << endl
         << "\t\t\t\t                        4. Cancel Booked Ticket " << endl
         << "\t\t\t\t                        5. Display All Tickets " << endl
         << "\t\t\t\t                        6. Return " << endl << endl
         << "\t\t\t\t                   Enter Your Choice  :  ";
        cin >> ch;
        system("cls");

        switch (ch)
        {
        case 1:
            Train.display_train();
            system("pause");
            system("cls");
            break;

        case 2:
            x = Train.res();
            system("pause");
            system("cls");
            fin.open("Reservation.txt", ios::app);
            fin.write((char *)&Train, sizeof(Train));
            fin.close();
            break;

        case 3:
            cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
             << "\n\n\t\t\t                      Enter Ticket No. : ";
            cin >> x;
            system("cls");
            fout.open("Reservation.txt", ios::in);
            fout.read((char *)&Train, sizeof(Train));

            while (!fout.eof())
            {
                if (Train.PNR == x)
                {
                    cout << "\n\n\n\n\n\n\n\n\n";

                    Train.Display_Ticket();
                    flag = 1;
                    fout.close();
                    system("pause");
                    system("cls");
                    break;
                }

                fout.read((char *)&Train, sizeof(Train));
            }
            if (!flag)
            {
                cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
                     << "\t\t\t\t                       Invalid Ticket Number " << endl
                     << "\t\t\t\t                         --- TRY AGAIN --- " << endl;
                system("pause");
                system("cls");
            }
            fout.close();
            break;

        case 4:
            cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
                 << "\t\t\t\t                      Enter Ticket No. : ";
            cin >> x;
            system("cls");
            cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";

            Train.Delete_Ticket(x);
            system("cls");
            break;

        case 5:
            cout << "\n\n\t\t\t\t                     Displaying All Tickets  " << endl;
            fout.open("Reservation.txt", ios::in);
            fout.read((char *)&Train, sizeof(Train));

            while (!fout.eof())
            {
                Train.Display_Ticket();
                flag = 1;
                fout.read((char *)&Train, sizeof(Train));
            }
            if (!flag)
            {

                system("cls");
                cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
                 << "\t\t\t\t                         NO Booked Tickets \n\n\n";
            }

            system("pause");
            system("cls");

            fout.close();
            break;
        }
    } while (ch > 0 && ch < 6);
} // end of code
