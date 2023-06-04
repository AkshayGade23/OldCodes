#include <fstream>
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
using namespace std;
void gotoxy(int x, int y)
{
    printf("%c[%d;%df", 0x1B, y, x);
}
class TourBus
{
private:
    int bid;
    char destination[200];
    char time[50];
    int max_seats;
    int booked;

public:
    TourBus()
    {
        bid = 0;
        max_seats = 50;
        booked = 0;
        strcpy(time, "9:10am");
        strcpy(destination, "");
    }
    void input();
    void show();
    void display();
    int getid()
    {
        return bid;
    }
    void book()
    {
        booked++;
    }
    char *getDestination()
    {
        return destination;
    }
    char *getTime()
    {
        return time;
    }
    int getBooked()
    {
        return booked;
    }
    int getMax()
    {
        return max_seats;
    }
};
class Ticket
{
    char name[50];
    TourBus bus;

public:
    void generate(char cname[], TourBus tb)
    {
        strcpy(name, cname);
        bus = tb;
    }
    void display()
    {
        cout << "Customer Name :- " << name << endl;
        cout << "Details of Bus :- " << endl;
        bus.show();
    }
};
void TourBus::input()
{
    system("cls");
    system("color 07");
    for (int i = 0; i < 21; i++)
    {
        gotoxy(9, i);
        cout << "::";
        gotoxy(75, i);
        cout << "::";
    }

    for (int i = 10; i < 75; i++)
    {
        gotoxy(i, 0);
        cout << "::";
    }

    for (int i = 75; i >= 9; i--)
    {
        gotoxy(i, 20);
        cout << "::";
    }
    gotoxy(35, 2);
    cout << "\n\n\t\t\t\tInstalling Bus ";
    gotoxy(12, 7);
    cout << "Enter Bus Id :-" << endl;
    gotoxy(42, 7);
    cin >> bid;
    gotoxy(12, 9);
    cout << "Enter Bus Destination :-" << endl;
    gotoxy(42, 9);
    cin >> destination;
    gotoxy(12, 11);
    cout << "Enter the time of Bus :-" << endl;
    gotoxy(42, 11);
    cin >> time;
}
void TourBus::display()
{
    cout << "Bus id is :-" << bid << endl;

    cout << "Bus destination is :-" << destination << endl;
    cout << "Bus arrival time is :-" << time << endl;
    cout << "Total seats :-" << max_seats << endl;
    cout << " Total Booked seats :-" << booked << endl;
}
void TourBus::show()
{
    system("cls");
    system("color 07");
    for (int i = 0; i < 21; i++)
    {
        gotoxy(9, i);
        cout << "::";
        gotoxy(75, i);
        cout << "::";
    }
    for (int i = 10; i < 75; i++)
    {
        gotoxy(i, 0);
        cout << "::";
    }

    for (int i = 75; i >= 9; i--)
    {
        gotoxy(i, 20);
        cout << "::";
    }
    gotoxy(12, 5);

    cout << "Bus Id is :-" << bid << endl;
    gotoxy(12, 7);
    cout << "Desination is :-" << destination << endl;
    gotoxy(12, 9);
    cout << "Time is :-" << time << endl;
    gotoxy(12, 11);
    cout << "No. of seats remaining :-" << max_seats - booked << endl;
}
int main()
{
    int ch;
    int id, chk = 0;
    fstream F, G;
    TourBus b;
    Ticket t;
    int exit;

    do
    {
        system("cls");
        system("color 07");

        for (int i = 0; i < 21; i++)
        {
            gotoxy(9, i);
            cout << "|";
            gotoxy(75, i);
            cout << "|";
        }
        gotoxy(10, 5);
        cout << "Press 1 - Add a New Tour Bus" << endl;
        gotoxy(10, 7);
        cout << "Press 2 - Show Selected Bus" << endl;
        gotoxy(10, 9);
        cout << "Press 3 - Display All Buses" << endl;
        gotoxy(10, 11);
        cout << "Press 4 - Delete a Bus" << endl;
        gotoxy(10, 13);
        cout << "Press 5 - Book a ticket " << endl;
        gotoxy(10, 15);
        cout << "Press 6 - Display Booked Tickets " << endl;
        gotoxy(10, 17);
        gotoxy(10, 19);
        cout << "Enter your choice :-";
        gotoxy(42, 19);
        cin >> ch;
        switch (ch)
        {
        case 1:
            F.open("tour.dat", ios::app | ios::binary);
            b.input();
            F.write((char *)&b, sizeof(b));
            F.close();
            gotoxy(12, 13);
            cout << "Bus added Successfully..." << endl;
            Sleep(10);
            getch();
            // clrscr();
            break;
        case 2:
        {
            system("cls");
            system("color 07");

            for (int i = 0; i < 21; i++)
            {
                gotoxy(9, i);
                cout << "::";
                gotoxy(75, i);
                cout << "::";
            }

            for (int i = 10; i < 75; i++)
            {
                gotoxy(i, 0);
                cout << "::";
            }

            for (int i = 75; i >= 9; i--)
            {
                gotoxy(i, 20);
                cout << "::";
            }
            gotoxy(12, 2);
            cout << "Enter the bus id to be displayed :-";
            cin >> id;
            F.open("tour.dat", ios::in | ios::binary);
            if (F.fail())
                cout << "Can't open file " << endl;
            else
            {
                while (F.read((char *)&b, sizeof(b)))
                {
                    if (b.getid() == id)
                    {
                        b.show();
                        chk = 1;
                        break;
                    }
                }
                if (chk == 0)
                    cout << "Bus not Found..." << endl;
                Sleep(10);
            }
            F.close();
            getch();
        }
        break;
        case 3:
        {

            system("cls");
            system("color 07");

            F.open("tour.dat", ios::in | ios::binary);
            if (F.fail())
                cout << "Can't open file " << endl;
            else
            {
                while (F.read((char *)&b, sizeof(b)))
                {
                    b.display();
                }
            }
            F.close();
            gotoxy(10, 20);
            cout << "Press a key to continue... ";
            getch();
        }
        break;
        case 4:
        {
            system("cls");
            system("color 07");

            for (int i = 0; i < 21; i++)
            {
                gotoxy(9, i);
                cout << "::";
                gotoxy(75, i);
                cout << "::";
            }

            for (int i = 10; i < 75; i++)
            {
                gotoxy(i, 0);
                cout << "::";
            }

            for (int i = 75; i >= 9; i--)
            {
                gotoxy(i, 20);
                cout << "::";
            }

            chk = 0;
            gotoxy(12, 5);
            cout << "Enter the bus id to be deleted :-";
            cin >> id;
            F.open("tour.dat", ios::in | ios::binary);
            G.open("temp.dat", ios::out | ios::binary);

            if (F.fail())
                cout << "Can't open file " << endl;
            else
            {
                while (F.read((char *)&b, sizeof(b)))
                {
                    if (b.getid() != id)
                    {
                        G.write((char *)&b, sizeof(b));
                    }
                    else
                    {
                        b.show();
                        chk = 1;
                    }
                }
                if (chk == 0)
                {
                    gotoxy(12, 7);
                    cout << "Bus not Found..." << endl;
                }
                else
                {
                    gotoxy(12, 13);
                    cout << "Bus Deleted..." << endl;
                }
            }
            F.close();
            G.close();
            remove("tour.dat");
            rename("temp.dat", "tour.dat");
            getch();
        }
        break;
        case 5:
        {
            char dest[70], cname[50];
            int bid;
            system("cls");
            system("color 07");
            for (int i = 0; i < 21; i++)
            {
                gotoxy(9, i);
                cout << "::";
                gotoxy(75, i);
                cout << "::";
            }

            for (int i = 10; i < 75; i++)
            {
                gotoxy(i, 0);
                cout << "::";
            }

            for (int i = 75; i >= 9; i--)
            {
                gotoxy(i, 20);
                cout << "::";
            }
            gotoxy(12, 5);
            cout << "Enter the destination :-";
            gotoxy(42, 5);
            cin >> dest;
            F.open("tour.dat", ios::in | ios::out | ios::binary);
            if (F.fail())
                cout << "Can't open file " << endl;
            else
            {
                while (F.read((char *)&b, sizeof(b)))
                {
                    if (strcmp(b.getDestination(), dest) == 0)
                    {
                        b.show();
                        chk = 1;
                        gotoxy(12, 13);
                        cout << "Enter the customer name :-";
                        gotoxy(42, 13);
                        cin >> cname;
                        b.book();
                        t.generate(cname, b);
                        G.open("tickets.dat", ios::app | ios::binary);
                        G.write((char *)&t, sizeof(t));
                        G.close();
                        F.seekp(F.tellg() - sizeof(b), ios::beg);
                        F.write((char *)&b, sizeof(b));
                        gotoxy(12, 15);
                        cout << "Ticket booked..." << endl;
                        break;
                    }
                }
                if (chk == 0)
                {
                    gotoxy(12, 8);
                    cout << "No Bus Found..." << endl;
                }
            }
            F.close();
            getch();
        }
        break;
        case 6:
        {
            cout << "Booked Tickets. " << endl;
            G.open("tickets.dat", ios::in | ios::binary);
            if (G.fail())
                cout << "can't open file " << endl;
            else
            {
                while (G.read((char *)&t, sizeof(t)))
                    t.display();
            }
            G.close();
            gotoxy(12, 13);
            cout << "Press a key to continue... ";
            getch();
        }
        }
    } while (ch != 7);
    return 0;
}