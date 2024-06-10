#include<iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include<Windows.h>

using namespace std;

const string RESET = "\033[0m";
const string RED = "\033[31m";
const string GREEN = "\033[32m";
const string YELLOW = "\033[33m";
const string BLUE = "\033[34m";
const string MAGENTA = "\033[35m";
const string CYAN = "\033[36m";
const string WHITE = "\033[37m";
const string BOLD = "\033[1m";
const string UNDERLINE = "\033[4m";
struct record
{
    string name;
    string cnic;
    string phoneno;
    string DOB;
    string classtype;

} a;

// Pattern For INTRO
void pattern()
{
    cout << endl << endl << endl << endl;
    cout << YELLOW << setw(80) << "  __        __   _                            " << RESET << endl;
    cout << YELLOW << setw(80) << " \\ \\      / /__| | ___ ___  _ __ ___   ___   " << RESET << endl;
    cout << YELLOW << setw(80) << "  \\ \\ /\\ / / _ \\ |/ __/ _ \\| '_ ` _ \\ / _ \\  " << RESET << endl;
    cout << YELLOW << setw(80) << "   \\ V  V /  __/ | (_| (_) | | | | | |  __/  " << RESET << endl;
    cout << YELLOW << setw(80) << "    \\_/\\_/ \\___|_|\\___\\___/|_| |_| |_|\\___|  " << RESET << endl;

    cout << endl << endl << endl << endl;


    cout << GREEN << setw(28) << "" << "***************************************************************" << RESET << endl;
    cout << GREEN << setw(28) << "" << "*                      TRAIN BOOKING SYSTEM                   *" << RESET << endl;
    cout << GREEN << setw(28) << "" << "*-------------------------------------------------------------*" << RESET << endl;
    cout << GREEN << setw(28) << "" << "*        ____                                                 *" << RESET << endl;
    cout << GREEN << setw(28) << "" << "*    ___|    |__                                              *" << RESET << endl;
    cout << GREEN << setw(28) << "" << "*  _|  _|____|  |_                                            *" << RESET << endl;
    cout << GREEN << setw(28) << "" << "* |  |          |__=================[ ]__                     *" << RESET << endl;
    cout << GREEN << setw(28) << "" << "* |__|__________|  |                 |  \\                     *" << RESET << endl;
    cout << GREEN << setw(28) << "" << "*    |__________|__|_  ____  ____  __|___\\______              *" << RESET << endl;
    cout << GREEN << setw(28) << "" << "*    /| |  |  | |   ||_||_||_||_||   |  |       \\             *" << RESET << endl;
    cout << GREEN << setw(28) << "" << "*   /_|_|__|__|_|___||_||_||_||_||___|__|_________\\           *" << RESET << endl;
    cout << GREEN << setw(28) << "" << "*( o ) ( o ) ( o ) ( o ) ( o ) ( o ) ( o ) ( o ) ( o ) ( o )  *" << RESET << endl;
    cout << GREEN << setw(28) << "" << "***************************************************************" << RESET << endl;
    cout << endl << endl << endl << endl;
}

// function for booking a ticket
int BookaTicket(string& name, string& cnic, string& phoneno, string& DOB, int& ticketnum, string& trainname, string& departure, string& destination, string& classtype, int& payment)
{
    system("CLS");
    cout << endl;
    cout << "\t";
    for (int i = 0; i < 100; i++)
    {
        cout << YELLOW << "=" << RESET;
    }
    cout << endl;
    cout << CYAN << "\t\t\t\t\t\t PLEASE BOOK A TICKET :" << RESET << endl;
    cout << "\t";
    for (int i = 0; i < 100; i++)
    {
        cout << YELLOW << "=" << RESET;
    }
    cout << endl;
    cout << endl << endl;
    cout << CYAN << "\t\t\tEnter your name : " << RESET;
    cin.ignore();
    getline(cin, a.name);
    while (a.name.length() == 0)
    {
        cout << RED << "\t\t\tInvalid Name !" << RESET << endl;
        getline(cin, a.name);
    }
    name = a.name;

    cout << CYAN << "\t\t\tEnter your CNIC :(00000-0000000-0) in this format " << RESET;
    getline(cin, a.cnic);
    while (a.cnic.length() != 15 || a.cnic[5] != '-' || a.cnic[13] != '-')
    {
        cout << RED << "\t\t\tInvalid Format !" << RESET << endl;
        cout << endl;
        cout << GREEN << "\t\t\tPlease Try Again !" << RESET << endl;
        getline(cin, a.cnic);
    }
    cnic = a.cnic;

    cout << CYAN << "\t\t\tEnter your phone number: (0000-0000000)" << RESET;
    getline(cin, a.phoneno);
    while (a.phoneno.length() != 12 || a.phoneno[4] != '-')
    {
        cout << RED << "\t\t\tInvalid Format !" << RESET << endl;
        cout << endl;
        cout << GREEN << "\t\t\tPlease Try Again !" << RESET << endl;
        getline(cin, a.phoneno);
    }
    phoneno = a.phoneno;

    cout << CYAN << "\t\t\tEnter your date of birth (DD-MM-YYYY):" << RESET;
    getline(cin, a.DOB);
    while (a.DOB.length() != 10 || a.DOB[2] != '-' || a.DOB[5] != '-')
    {
        cout << RED << "\t\t\tInvalid Format !" << RESET << endl;
        cout << endl;
        cout << GREEN << "Please Try Again !" << RESET << endl;
        getline(cin, a.DOB);
    }
    cout << endl << endl;
    DOB = a.DOB;
    int a, b, c;
i:
    {
        do
        {
            // Options for departure
            cout << YELLOW << "\t\t\t======================" << RESET << endl;
            cout << CYAN << "\t\t\tSELECT YOUR DEPARTURE" << RESET << endl;
            cout << YELLOW << "\t\t\t======================" << RESET << endl;
            cout << endl << endl;
            cout << GREEN << "\t\t\t------------------------" << RESET << endl;
            cout << endl << endl;
            cout << CYAN << "\t\t\t1. Karachi" << RESET << endl;
            cout << CYAN << "\t\t\t2. Lahore" << RESET << endl;
            cout << CYAN << "\t\t\t3. Faisalabad" << RESET << endl;
            cout << CYAN << "\t\t\t4. Multan" << RESET << endl;
            cout << CYAN << "\t\t\t5. Rawalpindi" << RESET << endl;
            cin >> b;
            if (b == 0)
                break;
            // Cases for different departure locations
            switch (b)
            {
            case 1:
                departure = "Karachi";
                break;
            case 2:
                departure = "Lahore";
                break;
            case 3:
                departure = "Faisalabad";
                break;
            case 4:
                departure = "Multan";
                break;
            case 5:
                departure = "Rawalpindi";
                break;
            default:
                cout << RED << "\t\t\tInvalid choice, please select again." << RESET << endl;
                continue;
            }
            break;
        } while (true);
        cout << endl << endl;

        // Options for destinations
        do
        {
            cout << CYAN << "\t\t\t========================" << RESET << endl;
            cout << YELLOW << "\t\t\tSELECT YOUR DESTINATION" << RESET << endl;
            cout << CYAN << "\t\t\t========================" << endl;
            cout << endl << endl;
            cout << GREEN << "\t\t\t-------------------------" << RESET << endl;
            cout << endl << endl;
            cout << YELLOW << "\t\t\t1. Karachi" << RESET << endl;
            cout << YELLOW << "\t\t\t2. Lahore" << RESET << endl;
            cout << YELLOW << "\t\t\t3. Faisalabad" << RESET << endl;
            cout << YELLOW << "\t\t\t4. Multan" << RESET << endl;
            cout << YELLOW << "\t\t\t5. Rawalpindi" << RESET << endl;
            cin >> c;
            if (c == 0)
                break;
            if ((b == 1 && c == 1) || (b == 2 && c == 2) || (b == 3) && (c == 3) || (b == 4) && (c == 4) || (b == 5) && (c == 5))
            {
                cout << endl << endl << endl;
                cout << RED << "\t\t\tDepartment and Destination is not Same :" << RESET << endl;
                goto i;
            }
            cout << endl << endl << endl;
            // Cases for different destinations
            switch (c)
            {
            case 1:
                destination = "Karachi";
                break;
            case 2:
                destination = "Lahore";
                break;
            case 3:
                destination = "Faisalabad";
                break;
            case 4:
                destination = "Multan";
                break;
            case 5:
                destination = "Rawalpindi";
                break;
            default:
                cout << RED << "\t\t\tInvalid choice, please select again." << RESET << endl;
                continue;
            }

            break;
        } while (true);
    }
    cout << endl << endl << endl;
    do
    {
        cout << YELLOW << "\t\t\t======================" << RESET << endl;
        cout << CYAN << "\t\t\tSELECT YOUR CLASS TYPE" << RESET << endl;
        cout << YELLOW << "\t\t\t======================" << RESET << endl;
        cout << endl << endl;
        cout << GREEN << "\t\t\t----------------------" << RESET << endl;
        cout << endl << endl;
        cout << CYAN << "\t\t\t1.Business class" << RESET << endl;
        cout << CYAN << "\t\t\t2.Executive class" << RESET << endl;
        cout << CYAN << "\t\t\t3.Economy class" << RESET << endl;

        cin >> a;
        if (a == 0)
            break;
        switch (a)
        {
        case 1:
            classtype = "Business class";
            break;
        case 2:
            classtype = " Executive class";
            break;
        case 3:
            classtype = "Economy class";
            break;
        default:
            cout << RED << "\t\t\tInvalid choice, please select again." << RESET << endl;
            continue;
        }
        break;

    } while (true);
    // Calculating new payment
    if (b == 1 && c == 2 || b == 2 && c == 1)
    {
        if (a == 1)
        {
            payment = 6000;
            cout << CYAN << "\t\t\tYour Class is Buisness Class :" << RESET << endl;
            cout << endl;
            cout << YELLOW << "\t\t\tYour Payment is : " << payment << RESET;
        }
        else if (a == 2)
        {
            payment = 4000;
            cout << CYAN << "\t\t\tYour Class is Executive Class :" << RESET << endl;
            cout << endl;
            cout << YELLOW << "\t\t\tYour Payment is : " << payment << RESET;
        }
        else
        {
            payment = 3000;
            cout << CYAN << "\t\t\tYour Class is Economy Class :" << RESET << endl;
            cout << endl;
            cout << YELLOW << "\t\t\tYour Payment is : " << payment << RESET;
        }
    }
    else if (b == 1 && c == 3 || b == 3 && c == 1)
    {
        if (a == 1)
        {
            payment = 5000;
            cout << CYAN << "\t\t\tYour Class is Buisness Class :" << RESET << endl;
            cout << endl;
            cout << YELLOW << "\t\t\tYour Payment is : " << payment << RESET;
        }
        else if (a == 2)
        {
            payment = 3500;
            cout << CYAN << "\t\t\tYour Class is Executive Class :" << RESET << endl;
            cout << endl;
            cout << YELLOW << "\t\t\tYour Payment is : " << payment << RESET;
        }
        else
        {
            payment = 2500;
            cout << CYAN << "\t\t\tYour Class is Economy Class :" << RESET << endl;
            cout << endl;
            cout << YELLOW << "\t\t\tYour Payment is : " << payment << RESET;
        }
    }
    else if (b == 1 && c == 4 || b == 4 && c == 1)
    {
        if (a == 1)
        {
            payment = 4000;
            cout << CYAN << "\t\t\tYour Class is Buisness Class :" << RESET << endl;
            cout << endl;
            cout << YELLOW << "\t\t\tYour Payment is : " << payment << RESET;
        }
        else if (a == 2)
        {
            payment = 2500;
            cout << CYAN << "\t\t\tYour Class is Executive Class :" << RESET << endl;
            cout << endl;
            cout << YELLOW << "\t\t\tYour Payment is : " << payment << RESET;
        }
        else
        {
            payment = 2000;
            cout << CYAN << "\t\t\tYour Class is Economy Class :" << RESET << endl;
            cout << endl;
            cout << YELLOW << "\t\t\tYour Payment is : " << payment << RESET;
        }
    }
    else if (b == 1 && c == 5 || b == 5 && c == 1)
    {
        if (a == 1)
        {
            payment = 10000;
            cout << CYAN << "\t\t\tYour Class is Buisness Class :" << RESET << endl;
            cout << endl;
            cout << YELLOW << "Your Payment is : " << payment << RESET;
        }
        else if (a == 2)
        {
            payment = 7000;
            cout << CYAN << "\t\t\tYour Class is Executive Class :" << RESET << endl;
            cout << endl;
            cout << YELLOW << "\t\t\tYour Payment is : " << payment << RESET;
        }
        else
        {
            payment = 5000;
            cout << CYAN << "\t\t\tYour Class is Economy Class :" << RESET << endl;
            cout << endl;
            cout << YELLOW << "\t\t\tYour Payment is : " << payment << RESET;
        }
    }
    else if (b == 2 && c == 3 || b == 3 && c == 2)
    {
        if (a == 1)
        {
            payment = 2000;
            cout << CYAN << "\t\t\tYour Class is Buisness Class :" << RESET << endl;
            cout << endl;
            cout << YELLOW << "\t\t\tYour Payment is : " << payment << RESET;
        }
        else if (a == 2)
        {
            payment = 1500;
            cout << CYAN << "\t\t\tYour Class is Executive Class :" << RESET << endl;
            cout << endl;
            cout << "\t\t\tYour Payment is : " << payment << RESET;
        }
        else
        {
            payment = 1000;
            cout << CYAN << "\t\t\tYour Class is Economy Class :" << RESET << endl;
            cout << endl;
            cout << YELLOW << "\t\t\tYour Payment is : " << payment << RESET;
        }
    }
    else if (b == 2 && c == 4 || b == 4 && c == 2)
    {
        if (a == 1)
        {
            payment = 6000;
            cout << CYAN << "\t\t\tYour Class is Buisness Class :" << RESET << endl;
            cout << endl;
            cout << YELLOW << "\t\t\tYour Payment is : " << payment << RESET;
        }
        else if (a == 2)
        {
            payment = 4000;
            cout << CYAN << "\t\t\tYour Class is Executive Class :" << RESET << endl;
            cout << endl;
            cout << YELLOW << "\t\t\tYour Payment is : " << payment << RESET;
        }
        else
        {
            payment = 6000;
            cout << CYAN << "\t\t\tYour Class is Economy Class :" << RESET << endl;
            cout << endl;
            cout << YELLOW << "\t\t\tYour Payment is : " << payment << RESET;
        }
    }
    else if (b == 2 && c == 5 || b == 5 && c == 2)
    {
        if (a == 1)
        {
            payment = 3000;
            cout << CYAN << "\t\t\tYour Class is Buisness Class :" << RESET << endl;
            cout << endl;
            cout << YELLOW << "\t\t\tYour Payment is : " << payment << RESET;
        }
        else if (a == 2)
        {
            payment = 2000;
            cout << CYAN << "\t\t\tYour Class is Executive Class :" << RESET << endl;
            cout << endl;
            cout << YELLOW << "\t\t\tYour Payment is : " << payment << RESET;
        }
        else
        {
            payment = 1100;
            cout << CYAN << "\t\t\tYour Class is Economy Class :" << RESET << endl;
            cout << endl;
            cout << YELLOW << "\t\t\tYour Payment is : " << payment << RESET;
        }
    }
    else if (b == 3 && c == 4 || b == 4 && c == 3)
    {
        if (a == 1)
        {
            payment = 5500;
            cout << CYAN << "\t\t\tYour Class is Buisness Class :" << RESET << endl;
            cout << endl;
            cout << YELLOW << "\t\t\tYour Payment is : " << payment << RESET;
        }
        else if (a == 2)
        {
            payment = 4400;
            cout << CYAN << "\t\t\tYour Class is Economy Class :" << RESET << endl;
            cout << endl;
            cout << YELLOW << "\t\t\tYour Payment is : " << payment << RESET;
        }
        else
        {
            payment = 3300;
            cout << CYAN << "\t\t\tYour Class is Economy Class :" << RESET << endl;
            cout << endl;
            cout << YELLOW << "\t\t\tYour Payment is : " << payment << RESET;
        }
    }
    else if (b == 3 && c == 5 || b == 5 && c == 3)
    {
        if (a == 1)
        {
            payment = 2500;
            cout << CYAN << "\t\t\tYour Class is Buisness Class :" << RESET << endl;
            cout << endl;
            cout << YELLOW << "\t\t\tYour Payment is : " << payment << RESET;
        }
        else if (a == 2)
        {
            payment = 1500;
            cout << CYAN << "\t\t\tYour Class is Executive Class :" << RESET << endl;
            cout << endl;
            cout << YELLOW << "\t\t\tYour Payment is : " << payment << RESET;
        }
        else
        {
            payment = 500;
            cout << CYAN << "\t\t\tYour Class is Economy Class :" << RESET << endl;
            cout << endl;
            cout << YELLOW << "\t\t\tYour Payment is : " << payment << RESET;
        }
    }
    else if (b == 4 && c == 5 || b == 5 && c == 4)
    {
        if (a == 1)
        {
            payment = 8000;
            cout << CYAN << "\t\t\tYour Class is Buisness Class :" << RESET << endl;
            cout << endl;
            cout << YELLOW << "\t\t\tYour Payment is : " << payment << RESET;
        }
        else if (a == 2)
        {
            payment = 7000;
            cout << CYAN << "\t\t\tYour Class is Executive Class :" << RESET << endl;
            cout << endl;
            cout << YELLOW << "\t\t\tYour Payment is : " << payment << RESET;
        }
        else
        {
            payment = 4000;
            cout << CYAN << "\t\t\tYour Class is Economy Class :" << RESET << endl;
            cout << endl;
            cout << YELLOW << "Your Payment is : " << payment << RESET;
        }
        cout << endl;
    }
    cout << endl << endl;
    // Options for trains with different timings
    do
    {
        cout << CYAN << "\t\t\t======================================" << RESET << endl;
        cout << YELLOW << "\t\t\tFOLLOWING TRAINS WILL GO TO ALL ROUTES" << RESET << endl;
        cout << CYAN << "\t\t\t======================================" << RESET << endl;
        cout << endl << endl;
        cout << GREEN << "\t\t\t--------------------------------------" << RESET << endl;
        cout << endl << endl;
        cout << YELLOW << "1 = orange line (departure time = 12:30 AM)" << RESET << endl;
        cout << YELLOW << "2 = blue line (departure time = 5:30 AM)" << RESET << endl;
        cout << YELLOW << "3 = green line (departure time = 10:00 AM)" << RESET << endl;
        cout << YELLOW << "4 = red line (departure time = 2:30 PM)" << RESET << endl;
        cout << YELLOW << "5 = yellow line (departure time = 6:30 PM)" << RESET << endl;
        cout << YELLOW << "Select your train (enter 0 to exit): ";
        cin >> a;
        if (a == 0)
            break;
        switch (a)
        {
        case 1:
            trainname = "orange line (departure time = 12:30 AM)";
            break;
        case 2:
            trainname = "blue line (departure time = 5:30 AM)";
            break;
        case 3:
            trainname = "green line (departure time = 10:00 AM)";
            break;
        case 4:
            trainname = "red line (departure time = 2:30 PM)";
            break;
        case 5:
            trainname = "yellow line (departure time = 6:30 PM)";
            break;
        default:
            cout << RED << "Invalid choice, please select again." << RESET << endl;
            continue;
        }
        break;
    } while (true);
    return 0;
}

int printTicket(const string& name, const string& cnic, const string& phoneno, const string& DOB, int ticketnum, const string& trainname, const string& departure, const string& destination, const string& classtype, int payment)
{
    system("CLS");
    cout << endl;
    cout << "\t";
    for (int i = 0; i < 100; i++)
    {
        cout << CYAN << "=" << RESET;
    }
    cout << endl;
    cout << YELLOW << "\t\t\t\t\t\t PRINTED TICKET :" << RESET << endl;
    cout << "\t";
    for (int i = 0; i < 100; i++)
    {
        cout << CYAN << "=" << RESET;
    }
    cout << endl;
    cout << endl << endl;
    // Getting the user information
    cout << "\n\n";
    cout << RED << "\t\t============================================================================================" << RESET << endl;
    cout << endl << endl;
    cout << YELLOW << "\t\t\t** Train Ticket **\n" << RESET;
    cout << "\n";
    cout << YELLOW << "\t\t\t\tTicket Number: " << ticketnum << RESET << endl;
    cout << "\n";
    cout << YELLOW << "\t\t\t\tSelected Train: " << trainname << RESET << endl;
    cout << "\n";
    cout << YELLOW << "\t\t\t\tClass Type : " << classtype << RESET << endl;
    cout << "\n";
    cout << YELLOW << "\t\t\t\tDeparture: " << departure << RESET << endl;
    cout << "\n";
    cout << YELLOW << "\t\t\t\tDestination: " << destination << RESET << endl;
    cout << "\n";
    cout << YELLOW << "\t\t\t\tName: " << name << RESET << endl;
    cout << "\n";
    cout << YELLOW << "\t\t\t\tDate of Birth: " << DOB << RESET << endl;
    cout << "\n";
    cout << YELLOW << "\t\t\t\tCNIC: " << cnic << RESET << endl;
    cout << "\n";
    cout << YELLOW << "\t\t\t\tPhone Number: " << phoneno << RESET << endl;
    cout << "\n";
    cout << YELLOW << "\t\t\t\tYour payment is = " << payment << " RS." << RESET << endl;
    cout << "\n";
    cout << YELLOW << "\t\t\t** Enjoy your journey! **\n" << RESET;
    cout << "\n\n";
    cout << RED << "\t\t============================================================================================" << RESET << endl;
    return 0;
}

int editrecord(string& name, string& cnic, string& phoneno, string& DOB, int& ticketnum, string& trainname, string& departure, string& destination, string& classtype, int& payment)
{

    system("CLS");
    cout << endl;
    cout << "\t";
    for (int i = 0; i < 100; i++)
    {
        cout << YELLOW << "=" << RESET;
    }
    cout << endl;
    cout << CYAN << "\t\t\t\t\t\t PLEASE EDIT A TICKET :" << RESET << endl;
    cout << "\t";
    for (int i = 0; i < 100; i++)
    {
        cout << YELLOW << "=" << RESET;
    }
    cout << endl;
    cout << endl << endl;

    int a, b, c;
i:
    {
        do
        {
            // Options for departure
            cout << YELLOW << "\t\t\t======================" << RESET << endl;
            cout << CYAN << "\t\t\tSELECT YOUR DEPARTURE" << RESET << endl;
            cout << YELLOW << "\t\t\t======================" << RESET << endl;
            cout << endl << endl;
            cout << GREEN << "\t\t\t------------------------" << RESET << endl;
            cout << endl << endl;
            cout << CYAN << "\t\t\t1. Karachi" << RESET << endl;
            cout << CYAN << "\t\t\t2. Lahore" << RESET << endl;
            cout << CYAN << "\t\t\t3. Faisalabad" << RESET << endl;
            cout << CYAN << "\t\t\t4. Multan" << RESET << endl;
            cout << CYAN << "\t\t\t5. Rawalpindi" << RESET << endl;
            cin >> b;
            if (b == 0)
                break;
            // Cases for different departure locations
            switch (b)
            {
            case 1:
                departure = "Karachi";
                break;
            case 2:
                departure = "Lahore";
                break;
            case 3:
                departure = "Faisalabad";
                break;
            case 4:
                departure = "Multan";
                break;
            case 5:
                departure = "Rawalpindi";
                break;
            default:
                cout << RED << "\t\t\tInvalid choice, please select again." << RESET << endl;
                continue;
            }
            break;
        } while (true);
        cout << endl << endl;

        // Options for destinations
        do
        {
            cout << CYAN << "\t\t\t========================" << RESET << endl;
            cout << YELLOW << "\t\t\tSELECT YOU DESTINATION" << RESET << endl;
            cout << CYAN << "\t\t\t========================" << endl;
            cout << endl << endl;
            cout << GREEN << "\t\t\t-------------------------" << RESET << endl;
            cout << endl << endl;
            cout << YELLOW << "\t\t\t1. Karachi" << RESET << endl;
            cout << YELLOW << "\t\t\t2. Lahore" << RESET << endl;
            cout << YELLOW << "\t\t\t3. Faisalabad" << RESET << endl;
            cout << YELLOW << "\t\t\t4. Multan" << RESET << endl;
            cout << YELLOW << "\t\t\t5. Rawalpindi" << RESET << endl;
            cin >> c;
            if (c == 0)
                break;
            if ((b == 1 && c == 1) || (b == 2 && c == 2) || (b == 3) && (c == 3) || (b == 4) && (c == 4) || (b == 5) && (c == 5))
            {
                cout << endl << endl << endl;
                cout << RED << "\t\t\tDepartment and Destination is not Same :" << RESET << endl;
                goto i;
            }
            cout << endl << endl << endl;
            // Cases for different destinations
            switch (c)
            {
            case 1:
                destination = "Karachi";
                break;
            case 2:
                destination = "Lahore";
                break;
            case 3:
                destination = "Faisalabad";
                break;
            case 4:
                destination = "Multan";
                break;
            case 5:
                destination = "Rawalpindi";
                break;
            default:
                cout << RED << "\t\t\tInvalid choice, please select again." << RESET << endl;
                continue;
            }

            break;
        } while (true);
    }
    cout << endl << endl << endl;
    do
    {
        cout << YELLOW << "\t\t\t======================" << RESET << endl;
        cout << CYAN << "\t\t\tSELECT YOUR CLASS TYPE" << RESET << endl;
        cout << YELLOW << "\t\t\t======================" << RESET << endl;
        cout << endl << endl;
        cout << GREEN << "\t\t\t----------------------" << RESET << endl;
        cout << endl << endl;
        cout << CYAN << "\t\t\t1.Business class" << RESET << endl;
        cout << CYAN << "\t\t\t2.Executive class" << RESET << endl;
        cout << CYAN << "\t\t\t3.Economy class" << RESET << endl;

        cin >> a;
        if (a == 0)
            break;
        switch (a)
        {
        case 1:
            classtype = "Business class";
            break;
        case 2:
            classtype = " Executive class";
            break;
        case 3:
            classtype = "Economy class";
            break;
        default:
            cout << RED << "\t\t\tInvalid choice, please select again." << RESET << endl;
            continue;
        }
        break;

    } while (true);
    // Calculating new payment
    if (b == 1 && c == 2 || b == 2 && c == 1)
    {
        if (a == 1)
        {
            payment = 6000;
            cout << CYAN << "\t\t\tYour Class is Buisness Class :" << RESET << endl;
            cout << endl;
            cout << YELLOW << "\t\t\tYour Payment is : " << payment << RESET;
        }
        else if (a == 2)
        {
            payment = 4000;
            cout << CYAN << "\t\t\tYour Class is Executive Class :" << RESET << endl;
            cout << endl;
            cout << YELLOW << "\t\t\tYour Payment is : " << payment << RESET;
        }
        else
        {
            payment = 3000;
            cout << CYAN << "\t\t\tYour Class is Economy Class :" << RESET << endl;
            cout << endl;
            cout << YELLOW << "\t\t\tYour Payment is : " << payment << RESET;
        }
    }
    else if (b == 1 && c == 3 || b == 3 && c == 1)
    {
        if (a == 1)
        {
            payment = 5000;
            cout << CYAN << "\t\t\tYour Class is Buisness Class :" << RESET << endl;
            cout << endl;
            cout << YELLOW << "\t\t\tYour Payment is : " << payment << RESET;
        }
        else if (a == 2)
        {
            payment = 3500;
            cout << CYAN << "\t\t\tYour Class is Executive Class :" << RESET << endl;
            cout << endl;
            cout << YELLOW << "\t\t\tYour Payment is : " << payment << RESET;
        }
        else
        {
            payment = 2500;
            cout << CYAN << "\t\t\tYour Class is Economy Class :" << RESET << endl;
            cout << endl;
            cout << YELLOW << "\t\t\tYour Payment is : " << payment << RESET;
        }
    }
    else if (b == 1 && c == 4 || b == 4 && c == 1)
    {
        if (a == 1)
        {
            payment = 4000;
            cout << CYAN << "\t\t\tYour Class is Buisness Class :" << RESET << endl;
            cout << endl;
            cout << YELLOW << "\t\t\tYour Payment is : " << payment << RESET;
        }
        else if (a == 2)
        {
            payment = 2500;
            cout << CYAN << "\t\t\tYour Class is Executive Class :" << RESET << endl;
            cout << endl;
            cout << YELLOW << "\t\t\tYour Payment is : " << payment << RESET;
        }
        else
        {
            payment = 2000;
            cout << CYAN << "\t\t\tYour Class is Economy Class :" << RESET << endl;
            cout << endl;
            cout << YELLOW << "\t\t\tYour Payment is : " << payment << RESET;
        }
    }
    else if (b == 1 && c == 5 || b == 5 && c == 1)
    {
        if (a == 1)
        {
            payment = 10000;
            cout << CYAN << "\t\t\tYour Class is Buisness Class :" << RESET << endl;
            cout << endl;
            cout << YELLOW << "Your Payment is : " << payment << RESET;
        }
        else if (a == 2)
        {
            payment = 7000;
            cout << CYAN << "\t\t\tYour Class is Executive Class :" << RESET << endl;
            cout << endl;
            cout << YELLOW << "\t\t\tYour Payment is : " << payment << RESET;
        }
        else
        {
            payment = 5000;
            cout << CYAN << "\t\t\tYour Class is Economy Class :" << RESET << endl;
            cout << endl;
            cout << YELLOW << "\t\t\tYour Payment is : " << payment << RESET;
        }
    }
    else if (b == 2 && c == 3 || b == 3 && c == 2)
    {
        if (a == 1)
        {
            payment = 2000;
            cout << CYAN << "\t\t\tYour Class is Buisness Class :" << RESET << endl;
            cout << endl;
            cout << YELLOW << "\t\t\tYour Payment is : " << payment << RESET;
        }
        else if (a == 2)
        {
            payment = 1500;
            cout << CYAN << "\t\t\tYour Class is Executive Class :" << RESET << endl;
            cout << endl;
            cout << "\t\t\tYour Payment is : " << payment << RESET;
        }
        else
        {
            payment = 1000;
            cout << CYAN << "\t\t\tYour Class is Economy Class :" << RESET << endl;
            cout << endl;
            cout << YELLOW << "\t\t\tYour Payment is : " << payment << RESET;
        }
    }
    else if (b == 2 && c == 4 || b == 4 && c == 2)
    {
        if (a == 1)
        {
            payment = 6000;
            cout << CYAN << "\t\t\tYour Class is Buisness Class :" << RESET << endl;
            cout << endl;
            cout << YELLOW << "\t\t\tYour Payment is : " << payment << RESET;
        }
        else if (a == 2)
        {
            payment = 4000;
            cout << CYAN << "\t\t\tYour Class is Executive Class :" << RESET << endl;
            cout << endl;
            cout << YELLOW << "\t\t\tYour Payment is : " << payment << RESET;
        }
        else
        {
            payment = 6000;
            cout << CYAN << "\t\t\tYour Class is Economy Class :" << RESET << endl;
            cout << endl;
            cout << YELLOW << "\t\t\tYour Payment is : " << payment << RESET;
        }
    }
    else if (b == 2 && c == 5 || b == 5 && c == 2)
    {
        if (a == 1)
        {
            payment = 3000;
            cout << CYAN << "\t\t\tYour Class is Buisness Class :" << RESET << endl;
            cout << endl;
            cout << YELLOW << "\t\t\tYour Payment is : " << payment << RESET;
        }
        else if (a == 2)
        {
            payment = 2000;
            cout << CYAN << "\t\t\tYour Class is Executive Class :" << RESET << endl;
            cout << endl;
            cout << YELLOW << "\t\t\tYour Payment is : " << payment << RESET;
        }
        else
        {
            payment = 1100;
            cout << CYAN << "\t\t\tYour Class is Economy Class :" << RESET << endl;
            cout << endl;
            cout << YELLOW << "\t\t\tYour Payment is : " << payment << RESET;
        }
    }
    else if (b == 3 && c == 4 || b == 4 && c == 3)
    {
        if (a == 1)
        {
            payment = 5500;
            cout << CYAN << "\t\t\tYour Class is Buisness Class :" << RESET << endl;
            cout << endl;
            cout << YELLOW << "\t\t\tYour Payment is : " << payment << RESET;
        }
        else if (a == 2)
        {
            payment = 4400;
            cout << CYAN << "\t\t\tYour Class is Economy Class :" << RESET << endl;
            cout << endl;
            cout << YELLOW << "\t\t\tYour Payment is : " << payment << RESET;
        }
        else
        {
            payment = 3300;
            cout << CYAN << "\t\t\tYour Class is Economy Class :" << RESET << endl;
            cout << endl;
            cout << YELLOW << "\t\t\tYour Payment is : " << payment << RESET;
        }
    }
    else if (b == 3 && c == 5 || b == 5 && c == 3)
    {
        if (a == 1)
        {
            payment = 2500;
            cout << CYAN << "\t\t\tYour Class is Buisness Class :" << RESET << endl;
            cout << endl;
            cout << YELLOW << "\t\t\tYour Payment is : " << payment << RESET;
        }
        else if (a == 2)
        {
            payment = 1500;
            cout << CYAN << "\t\t\tYour Class is Executive Class :" << RESET << endl;
            cout << endl;
            cout << YELLOW << "\t\t\tYour Payment is : " << payment << RESET;
        }
        else
        {
            payment = 500;
            cout << CYAN << "\t\t\tYour Class is Economy Class :" << RESET << endl;
            cout << endl;
            cout << YELLOW << "\t\t\tYour Payment is : " << payment << RESET;
        }
    }
    else if (b == 4 && c == 5 || b == 5 && c == 4)
    {
        if (a == 1)
        {
            payment = 8000;
            cout << CYAN << "\t\t\tYour Class is Buisness Class :" << RESET << endl;
            cout << endl;
            cout << YELLOW << "\t\t\tYour Payment is : " << payment << RESET;
        }
        else if (a == 2)
        {
            payment = 7000;
            cout << CYAN << "\t\t\tYour Class is Executive Class :" << RESET << endl;
            cout << endl;
            cout << YELLOW << "\t\t\tYour Payment is : " << payment << RESET;
        }
        else
        {
            payment = 4000;
            cout << CYAN << "\t\t\tYour Class is Economy Class :" << RESET << endl;
            cout << endl;
            cout << YELLOW << "Your Payment is : " << payment << RESET;
        }
        cout << endl;
    }
    cout << endl << endl;
    // Options for trains with different timings
    do
    {
        cout << CYAN << "\t\t\t========================================" << RESET << endl;
        cout << YELLOW << "\t\t\tFOLLOWING TRAINS WILL GO TO ALL ROUTES " << RESET << endl;
        cout << CYAN << "\t\t\t========================================" << RESET << endl;
        cout << endl << endl;
        cout << GREEN << "\t\t\t--------------------------------------" << RESET << endl;
        cout << endl << endl;
        cout << YELLOW << "1 = orange line (departure time = 12:30 AM)" << RESET << endl;
        cout << YELLOW << "2 = blue line (departure time = 5:30 AM)" << RESET << endl;
        cout << YELLOW << "3 = green line (departure time = 10:00 AM)" << RESET << endl;
        cout << YELLOW << "4 = red line (departure time = 2:30 PM)" << RESET << endl;
        cout << YELLOW << "5 = yellow line (departure time = 6:30 PM)" << RESET << endl;
        cout << YELLOW << "Select your train (enter 0 to exit): ";
        cin >> a;
        if (a == 0)
            break;
        switch (a)
        {
        case 1:
            trainname = "orange line (departure time = 12:30 AM)";
            break;
        case 2:
            trainname = "blue line (departure time = 5:30 AM)";
            break;
        case 3:
            trainname = "green line (departure time = 10:00 AM)";
            break;
        case 4:
            trainname = "red line (departure time = 2:30 PM)";
            break;
        case 5:
            trainname = "yellow line (departure time = 6:30 PM)";
            break;
        default:
            cout << RED << "Invalid choice, please select again." << RESET << endl;
            continue;
        }
        break;
    } while (true);
    return 0;
}


void viewrecord()
{
    system("cls");

    string searchKey; // Variable to store ticket number or CNIC
    cout << YELLOW << "\n\n\t\t\tEnter the CNIC: " << RESET;
    cin.ignore();
    getline(cin, searchKey);
    while (searchKey.length() != 15 || searchKey[5] != '-' || searchKey[13] != '-')
    {
        cout << RED << "\t\t\tInvalid Format !" << RESET << endl;
        cout << endl;
        cout << GREEN << "\t\t\tPlease Try Again !" << RESET << endl;
        getline(cin, searchKey);
    }

    ifstream rec("Details.txt");
    bool found = false;

    if (!rec) {
        cout << RED << "\n\nFile not found!\n" << RESET;
        return;
    }

    string line;
    while (getline(rec, line))
    {
        string ticketNumber, train, departure, destination, name, dateOfBirth, CNIC, phoneNumber, classtype;


        ticketNumber = line;
        if (!getline(rec, train))
            break;
        if (!getline(rec, departure))
            break;
        if (!getline(rec, destination))
            break;
        if (!getline(rec, name))
            break;
        if (!getline(rec, dateOfBirth))
            break;
        if (!getline(rec, CNIC))
            break;
        if (!getline(rec, phoneNumber))
            break;
        if (!getline(rec, classtype))
            break;

        // Check if ticket number or CNIC matches the search key
        if (CNIC == searchKey)
        {
            found = true;
            cout << CYAN << "\n\n\t\t*** VIEW DETAILS ***" << RESET;
            cout << CYAN << "\n\nTicket Number: " << ticketNumber << RESET << endl;
            cout << YELLOW << "\n**********************************" << RESET;
            cout << CYAN << "\n\nTrain: " << train << RESET << endl;
            cout << YELLOW << "\n**********************************" << RESET;
            cout << CYAN << "\n\nDeparture: " << departure << RESET << endl;
            cout << YELLOW << "\n**********************************" << RESET;
            cout << CYAN << "\n\nDestination: " << destination << RESET << endl;
            cout << YELLOW << "\n**********************************" << RESET;
            cout << CYAN << "\n\nName: " << name << RESET << endl;
            cout << YELLOW << "\n**********************************" << RESET;
            cout << CYAN << "\n\nDate of Birth: " << dateOfBirth << RESET << endl;
            cout << YELLOW << "\n**********************************" << RESET;
            cout << CYAN << "\n\nCNIC: " << CNIC << RESET << endl;
            cout << YELLOW << "\n**********************************" << RESET;
            cout << CYAN << "\n\nPhone Number: " << phoneNumber << RESET << endl;
            cout << YELLOW << "\n**********************************" << RESET;
            cout << CYAN << "\n\nClass Type: " << classtype << RESET << endl;
            cout << YELLOW << "\n**********************************\n" << RESET;
        }
    }

    if (!found)
    {
        cout << RED << "\n\nNo record found with this CNIC." << RESET << endl;
    }

    rec.close();
}

void view_allRecords()
{
    system("CLS");
    cout << endl;
    cout << "\t";
    for (int i = 0; i < 100; i++)
    {
        cout << CYAN << "=" << RESET;
    }
    cout << endl;
    cout << YELLOW << "\t\t\t\t\t\t ALL RECORDS :" << RESET << endl;
    cout << "\t";
    for (int i = 0; i < 100; i++)
    {
        cout << CYAN << "=" << RESET;
    }
    cout << endl;
    cout << endl << endl;
retry:
    string username;
    string password;
    cout << YELLOW << "\t\t\tEnter the Username : " << RESET;
    cin >> username;
    cout << endl;
    cout << YELLOW << "\t\t\tEnter the Password : " << RESET;
    cin >> password;
    cout << endl;
    if (username != "@semendproject" || password != "project123")
    {
        cout << RED << "\t\t\tInvalid Credentials :" << RESET << endl;
        goto retry;
    }
    if (username == "@semendproject" && password == "project123")
    {
        ifstream filem;
        filem.open("record.txt");
        if (!filem)
        {
            cout << RED << "\t\t\tFile is not Found !" << RESET << endl;
            exit(0);
        }
        else
        {
            ifstream filem("record.txt");
            string in;
            while (getline(filem, in))
            {
                cout << CYAN << in << RESET << endl;
            }
            filem.close();
        }
    }
}
int main()
{

    string name, cnic, phoneno, DOB, classtype;
    string trainname, departure, destination;
    int choice, payment = 0;
    int ticketnum = 0;

    pattern();

    cout << endl << endl;
    do
    {
        // Display menu options
        // Asking the user to select an option according to his requirement
        cout << endl;
        cout << YELLOW << "\t\t\t\t\t\t============" << RESET << endl;
        cout << CYAN << "\t\t\t\t\t\t MAIN MENU" << RESET << endl;
        cout << YELLOW << "\t\t\t\t\t\t============" << RESET << endl;
        cout << endl << endl;
        cout << GREEN << "\t\t\t\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << RESET << endl;
        cout << endl << endl;
        cout << CYAN << "\t\t\t\t\t\t1. Book a Ticket" << RESET << endl;
        cout << CYAN << "\t\t\t\t\t\t2. View a Ticket" << RESET << endl;
        cout << CYAN << "\t\t\t\t\t\t3. Edit a Ticket" << RESET << endl;
        cout << CYAN << "\t\t\t\t\t\t4. Print a Ticket" << RESET << endl;
        cout << CYAN << "\t\t\t\t\t\t5. View All Records" << RESET << endl;
        cout << CYAN << "\t\t\t\t\t\t6. Exit" << RESET << endl;
        cout << endl;
        cout << YELLOW << "\t\t\tEnter your choice: " << RESET;
        cin >> choice;

        // Performing actions based on user's choice
        switch (choice)
        {
        case 1:
            BookaTicket(name, cnic, phoneno, DOB, ticketnum, trainname, departure, destination, classtype, payment);
            ticketnum++;
            cout << endl << endl;
            cout << CYAN << "Ticket is Successfully Booked :" << RESET << endl;

            if (ticketnum == 0)
            {
                cout << endl << endl;
                cout << RED << "Ticket is Not Booked :" << RESET << endl;
            }
            break;
        case 2:

        {
            ofstream rec("Details.txt", ios::app);
            if (!rec) {
                cout << "File not found!" << endl;
            }
            else {
                rec << ticketnum << endl;
                rec << trainname << endl;
                rec << departure << endl;
                rec << destination << endl;
                rec << name << endl;
                rec << DOB << endl;
                rec << cnic << endl;
                rec << phoneno << endl;
                rec << classtype << endl;
            }
            rec.close();
            viewrecord();
        }
        break;
        case 3:
            editrecord(name, cnic, phoneno, DOB, ticketnum, trainname, departure, destination, classtype, payment);
            break;

        case 4:
            printTicket(name, cnic, phoneno, DOB, ticketnum, trainname, departure, destination, classtype, payment);
            break;
        case 5:
        {
            ofstream file;
            file.open("record.txt", ios::app);
            // ...
            file << " " << endl;
            file << " " << endl;
            file << " " << endl;
            file << "\t\t*** Train Ticket ***" << endl;
            ;
            file << " " << endl;
            file << "\t\t\t\tTicket Number : " << ticketnum << endl;
            file << " " << endl;
            file << "\t\t\t\tSelected Train :" << trainname << endl;
            file << " " << endl;
            file << "\t\t\t\tDeparture :" << departure << endl;
            file << " " << endl;
            file << "\t\t\t\tDestination : " << destination << endl;
            file << " " << endl;
            file << "\t\t\t\tName : " << name << endl;
            file << " " << endl;
            file << "\t\t\t\tDate of Birth : " << " " << DOB;
            file << " " << endl;
            file << "\t\t\t\tCNIC : " << cnic << endl;
            file << " " << endl;
            file << "\t\t\t\tPhone Number : " << phoneno << endl;
            file << " " << endl;
            file << "\t\t\t\tClass Type : " << classtype << endl;
            file << " " << endl;
            file.close();
            view_allRecords();
            break;
        }
        case 6:
        {
            cout << "Exiting program..." << endl;
            ofstream file;
            file.open("record.txt", ios::app);
            // ...
            file << " " << endl;
            file << " " << endl;
            file << " " << endl;
            file << "\t\t*** Train Ticket ***" << endl;
            ;
            file << " " << endl;
            file << "\t\t\t\tTicket Number : " << ticketnum << endl;
            file << " " << endl;
            file << "\t\t\t\tSelected Train :" << trainname << endl;
            file << " " << endl;
            file << "\t\t\t\tDeparture :" << departure << endl;
            file << " " << endl;
            file << "\t\t\t\tDestination : " << destination << endl;
            file << " " << endl;
            file << "\t\t\t\tName : " << name << endl;
            file << " " << endl;
            file << "\t\t\t\tDate of Birth : " << " " << DOB;
            file << " " << endl;
            file << "\t\t\t\tCNIC : " << cnic << endl;
            file << " " << endl;
            file << "\t\t\t\tPhone Number : " << phoneno << endl;
            file << " " << endl;
            file << "\t\t\t\tClass Type : " << classtype << endl;
            file << " " << endl;
            file.close();
            return 0;
            break;
        }
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }

    } while (choice != 6);

    return 0;
}