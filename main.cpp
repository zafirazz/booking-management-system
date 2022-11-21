#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

void main_menu();

class Menu{
    protected:
        string usname;
    public:
        Menu(){
            system("color 0A");
            cout<< "Enter your name: ";
            cin >> usname;
            main_menu();
        }

        ~Menu(){}
};

class Users{
public:
    static string neptun;
    string name, roomNum;
    int mobile;
    char all[999];

    void get_user(){
        ofstream out("users.txt", ios::app);
        {
            cout << "Enter Student's Neptun Code: ";
            cin >> neptun;
            cout << "Enter Student's Full Name: ";
            cin >> name;
            cout << "Enter Student's room number: ";
            cin >> roomNum;
            cout << "Enter Student's Mobile Number: ";
            cin >> mobile;
            }
            out << "\nUser Neptun Code: " << neptun << "\nName: " << name <<"\nRoom No: " << roomNum << "\nMobile Number: " << mobile << "\n";
            out.close();
            cout << "\nYou were added to the user's list!\n" << "\n";
    }

 void show_info()
    {
        ifstream in("users.txt");
        {
            if(!in){
                cout << "File Error!" << endl;
            }
            while(!(in.eof()))
            {
                in.getline(all, 999);
                cout << all << endl;
            }
            in.close();
        }
    }
};

string Users::neptun;

class WashingMachines{
    public:
        int choice, cost;
        static int finalcost;
        int reservation_time;

        void welcoming_message(){
            cout << "------------Washing Machines in Szanto Dormitory------------"<<endl;
            cout << "1. Book Alpha washing machine-200huf for 40 minutes"<<endl;
            cout << "2. Book Sigma washing machine-250huf for 40 minutes"<<endl;

            cout << "\nSelect washing machine by typing its number: ";
            cin >> choice;

            int machine_choice;

            if (choice==1){
                cost = 200;
                cout << "You will need to pay " << cost << "forints " << endl;
                cout << "Are you sure you want to book Alpha? Type 1-yes or 2-no: ";
                cin >> machine_choice;
                    if (machine_choice==1){
                        finalcost = cost;
                        cout << "You have booked Alpha!" << endl;
                        cout << "Go back to main menu to take receipt." << endl;
                    } else if (machine_choice==2){
                        welcoming_message();
                    } else {
                        cout << "Invalid input. Back to menu" << endl;
                        welcoming_message();
                    }
            } else if (choice==2){
                cost=250;
                cout << "You will need to pay " << cost << "forints " << endl;
                cout << "Are you sure you want to book Sigma? Type 1-yes or 2-no: ";
                cin >> machine_choice;
                if (machine_choice==1){
                    finalcost = cost;
                    cout << "You have booked Sigma!" << endl;
                    cout << "Go back to main menu to take receipt." << endl;
                } else if (machine_choice==2){
                    welcoming_message();
                } else {
                    cout << "Invalid input. Back to menu" << endl;
                    welcoming_message();
                }
            } else {
                cout << "Invalid input. Back to menu." << endl;
                main_menu();
            }

            cout << "Press 1 to go back to Main menu: ";
            cin >> machine_choice;
            if (machine_choice==1){
                main_menu();
            } else {
                main_menu();
            }
        }
};

int WashingMachines::finalcost;


class Billing: public WashingMachines, Users{
    public:
        void receipt(){
            ofstream outf("receipt.txt");
            {
                outf << "-------Szanto Washing Machines-------" << endl;
                outf << "---------------Receipt---------------" << endl;
                outf << "_____________________________________" << endl;

                outf << "Student's neptun code: " << Users::neptun << endl;
                outf << "Total: " << endl;
                outf << "Washing Machine cost: " << WashingMachines::finalcost << endl;
                outf << "_____________________________________" << endl;
                outf << "Total charge: " << WashingMachines::finalcost << endl;
                outf << "_____________________________________" << endl;
                outf << "--------------Thank you--------------" << endl;
            }
            outf.close();
        }

        void show_receipt(){
            ifstream inf("receipt.txt");
            {
                if (!inf){
                    cout << "error" << endl;
                }
                while (!(inf.eof())){
                    inf.getline(all, 999);
                    cout << all << endl;
                }
            }
            inf.close();
        }
};

void main_menu(){
    int ch1;
    int ch;
    int goback;

    cout << "Szanto Washing Machines\n" << endl;
    cout << "---------Main Menu--------" << endl;

    cout << "Student management -> 1\t" << endl;
    cout << "Washing Machine booking -> 2\t" << endl;
    cout << "Bill -> 3\t" << endl;
    cout << "Exit -> 4\t" << endl;

    cout << "\nEnter your choice: ";
    cin >> ch1;

    Users variant1;
    WashingMachines variant2;
    Billing variant3;

    if (ch1==1){
        cout << "----------Users----------" << endl;
        cout << "1. Enter New User" << endl;
        cout << "2. See previous users" << endl;

        cout<<"\nEnter your choice: ";
        cin >> ch;

        if (ch==1){
            variant1.get_user();
        } else if (ch==2){
            variant1.show_info();
        } else {
            cout << "error" << endl;
            main_menu();
        }
        cout << "Press 1 to go back to main menu: "<< endl;
        cin >> goback;
        if (goback==1){
            main_menu();
        } else {
            main_menu();
        }
    } else if (ch1==2){
        variant2.welcoming_message();
    } else if (ch1==3){
        variant3.receipt();
        cout << "Your receipt is in receipt.txt" << endl;
        cout << "If you want to see it on the screen, enter 1: "<<endl;

        cin >> goback;
        if (goback==1){
            variant3.show_receipt();
        } else {
            main_menu();
        }
    } else if(ch==4) {
        cout<<"Exiting..."<< endl;
        Menu();
    } else {
        cout << "error" << endl;
        main_menu();
    }
}

int main(){
    Menu startObj;
    return 0;
}
