#include <iostream>
#include <string>
#include <cstring>
#include <fstream>

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
int Index ;

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
        //  f.open("G:\\MINI project\\train2.txt", ios::out);
        cout
            << "\ncreate user id:";
        cin >> user_id;
        cout << "\ncreate password:";
        cin >> password;

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

class trainn
{
public:
    fstream f;
    int max_T = 4;
    int Tno[4] = {1002, 1003};
    char source[4][10] = {"Pune", "Pune", "Pune", "Pune"};
    char dest[4][50] = {"Nagpur", "Chennai", "pune", "pune"};
    char Atime[4][50] = {"8:10 AM", "7:10 AM", "12:00 AM", "12:00 AM"};

    int total_seats = 60;

    int fbooked[4] = {0, 0, 0, 0};
    int sbooked[4] = {0, 0, 0, 0};
    int fclass_rs[4] = {100, 150};
    int sclass_rs[4] = {50, 75};
    int added_train = 2;

    void add_train() //adding new trains
    {
        if (added_train == 4) //checking if train entry is full
        {
            
            cout << "------  No more trains can be added  ------" << endl;
        }
        else
        {
            //taking input
            cout << "Enter the train number : ";
            cin >> Tno[added_train];

            cout << "Enter source of the train : ";
            scanf("%s", &source[added_train][0]);

            cout << "Enter the destination of the train : ";
            scanf("%s", &dest[added_train][0]);

            cout << "Enter the arrival time of the train : ";
            scanf("%s", &Atime[added_train][0]);

            cout << "Enter the first class seat price : ";
            cin >> fclass_rs[added_train];

            cout << "Enter the second class seat price : ";
            cin >> sclass_rs[added_train];

            cout << endl;
            added_train++;
        }
    }
    void display_train()
    {
        cout << endl
             << endl
             << "        **-----------------    Train Details     ----------------** \n";
        for (int i = 0; i < added_train; i++)
        {
            cout << endl
                 << "\t\tTrain number :\t" << Tno[i] << endl;
            printf("\t\tSource       :\t");
            puts(source[i]);
            printf("\t\tDestination  :\t%s \n", dest[i]);
            printf("\t\tArrival Time :\t%s \n", Atime[i]);
            cout << "\t\tFirst Class  :  30 seats     Booked : " << fbooked[i] << " seats" << endl
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

class Reservation : public trainn
{
public:
    int rt_no, b, PNR;
    int TotalRS;
    char clss;

    int res() //to reserve ticket
    {
        cout << "Enter train number:";
        cin >> rt_no;

        if (rt_no != Tno[0] && rt_no != Tno[1] && rt_no != Tno[2])
        {
            cout << "wrong Train number entered";
            return 0;
        }

        {

            do
            {
                cout << "Choose Class" << endl;
                cout << "F- First Class" << endl
                     << "S- Second Class" << endl;
                cin >> clss;

                switch (clss)
                {
                case 'F':
                    cout << "Enter number of tickets you want to book:";
                    cin >> b;
                    if (!check_Fbook(b, rt_no))
                    {
                        return 0;
                    }
                    TotalPrice(rt_no, b, clss);
                    Fbook(rt_no, b);
                    break;

                case 'S':
                    cout << "Enter number of tickets you want to book:";
                    cin >> b;
                    if (!check_Sbook(b, rt_no))
                    {
                        return 0;
                    }

                    TotalPrice(rt_no, b, clss);
                    Sbook(rt_no, b);
                    break;

                default:
                    cout << "Invalid Input" << endl;
                }
            } while (clss != 'F' && clss != 'S');
        }

        cout << "Your ticket booked successfully!!" << endl;
        return 1;
    }

    void TotalPrice(int rt_no, int b, char clss)
    {   
        file_Ticket.open("index.dat", ios::in);
        file_Ticket >> Index;
        file_Ticket.close();
   
        Index++;
        PNR = Index;

        int i = check_train(rt_no);
        cout << "Ticket No. : " << PNR << endl;
        if (clss == 'F')
        {
            TotalRS = fclass_rs[i] * b;
            cout << "Total Booked Tickets :" << b << endl;
            cout << "Class : First Class" << endl;
            cout << "Total Cost :" << TotalRS << endl;
        }
        else
        {
            TotalRS = sclass_rs[i] * b;
            cout << "'\nTotal Booked Tickets :" << b << endl;
            cout << "Class : Second Class" << endl;
            cout << "Total Cost :" << TotalRS << endl;
        }

        file_Ticket.open("index.dat", ios::out);
        file_Ticket << Index;
        file_Ticket.close();
    }

    void Display_Ticket()
    {
        cout << " -------- Indian Railwyas -------- \n"
             << endl;
        cout << " Ticket No. : " << PNR << endl
             << " Train No.  : " << rt_no << endl
             << " Booked Tickets : " << b << endl;

        cout << " Source  :  " << source[check_train(rt_no)] << "\t\tDestination  : " << dest[check_train(rt_no)] << endl
             << " Arrival Time : " << Atime[check_train(rt_no)] << endl
             << " Class  : " << clss << endl;
        if (clss == 'F')
            cout << " Price : " << fclass_rs[check_train(rt_no)] << " * " << b << " = " << TotalRS << endl;

        else
            cout << " Price : " << sclass_rs[check_train(rt_no)] << " * " << b << " = " << TotalRS << endl;
    }
};

char AdminPassword[20] = "vinayakshay";
Reservation Train;

int main()
{
    int ch;
    cout << " <---------------  WELCOME TO INDIAN RAILWAYS  --------------->\n\n "<<endl;
     do
    {
        cout << endl
             << endl
             << "        **-----------------  Main Menu  ----------------** \n\n";
        cout << "                          1. Admin  " << endl;
        cout << "                          2. User" << endl;
        cout << "                          3. Exit " << endl
             << endl;
        cout << "       Enter Your Choice  :  ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            AdminLogin();
            break;

        case 2:
            UserLogin();
            break;

        case 3:

            cout << " Thank You For Indian Railways!!" << endl;
            exit(0);
        }
    }
    while (ch > 0 && ch <= 3)
        ;

    return 0;
}

void AdminLogin()
{
    char s2[20];

    cout << "Enter Admin Password :  ";
    cin >> s2;
    if (strcmp(AdminPassword, s2))
    {
        cout << "  Invalid Userid / Password " << endl
             << "  --- TRY AGAIN --- " << endl;
    }
    else
    {
        int ch;

        cout << " -------- Logged in as Admin -------- " << endl;

        do
        {
            cout << endl
                 << endl
                 << "        **-----------------     Admin Menu    ----------------** \n\n";
            cout << "                          1. Display Trian Details " << endl;
            cout << "                          2. Add new Train" << endl;
            cout << "                          3. Return " << endl
                 << endl;
            cout << "       Enter Your Choice  :  ";
            cin >> ch;
            switch (ch)
            {
            case 1:
                Train.display_train();
                break;

            case 2:
                Train.add_train();
                break;
            }
        } while (ch < 3 && ch > 0);
    }
}
void UserLogin()
{
    char s1[20], s2[20];
    login ll;
    fstream file_lg;
    int ch, flag = 0;
    do
    {
        cout << endl
             << endl
             << "        **-----------------    User Login     ----------------** \n\n";
        cout << "                          1. Create Login " << endl;
        cout << "                          2. Login" << endl;
        cout << "                          3. Return " << endl
             << endl;
        cout << "       Enter Your Choice  :  ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            file_Ticket.open("login.txt", ios::app);
            ll.create_login();
            file_Ticket.write((char *)&ll, sizeof(ll));
            file_Ticket.close();
            break;
        case 2:

            cout << "\nEnter user id:";
            cin >> s1;
            cout << "\nEnter password:";
            cin >> s2;
            file_Ticket.open("login.txt", ios::in);
            file_Ticket.read((char *)&ll, sizeof(ll));
            while (!file_lg.eof())
            {
                if (!(strcmp(ll.user_id, s1)) && !(strcmp(ll.password, s2)))
                {
                    cout << " --------you are successfully logged in-------- " << endl;
                    flag = 1;
                    UserMenu();
                    break;
                }
                file_Ticket.read((char *)&ll, sizeof(ll));
            }
            if (!flag)
            {
                cout << "  Invalid Userid / Password " << endl
                     << "  --- TRY AGAIN --- " << endl;
            }
            file_Ticket.close();
            break;
        }
    } while (ch > 0 && ch < 3);
}

void UserMenu(void)
{

    int flag,x,ch;

    do
    {
        cout << endl
             << endl
             << "        **-----------------    User Login     ----------------** \n\n";
        cout << "                          1. Display Trian Details  " << endl;
        cout << "                          2. Ticket Reservation " << endl;
        cout << "                          3. Display Booked Ticket " << endl;
        cout << "                          4. Cancel Booked Ticket " << endl;
        cout << "                          5. Return " << endl
             << endl;
        cout << "       Enter Your Choice  :  ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            Train.display_train();
            break;

        case 2:
             x = Train.res();
            file_Ticket.open("Reservation.txt", ios::app);
            file_Ticket.write((char *)&Train, sizeof(Train));
            file_Ticket.close();
            break;

        case 3:
            cout << " Enter Ticket No. : ";
            cin >> x;
            file_Ticket.open("Reservation.txt", ios::in);
            file_Ticket.read((char *)&Train, sizeof(Train));

            while (!file_Ticket.eof())
            {    
                if (Train.PNR == x)
                {   
                    Train.Display_Ticket();
                    flag = 1;
                }
                file_Ticket.read((char *)&Train, sizeof(Train));
            }
            if (!flag)
            {
                cout << "  Invalid Userid / Password " << endl
                     << "  --- TRY AGAIN --- " << endl;
            }
            break;

            case 4:
            break;
       }
    }while(ch>0 && ch <5);

}