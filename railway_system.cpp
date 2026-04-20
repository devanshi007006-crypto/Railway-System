#include<iostream>
#include<string>
#include<iomanip>
using namespace std; 

class Ticket{
    protected:

        int TicketID;
        string passengerName;
        float distanceTravel; // in km
        float baseFare;
        string Destination;
        int age;
        int Totalseats;  //150 

    public:

        int setSeats(){
            Totalseats=150;
            sleeperSeats = 100;
            ACseats = 50;
        }

        void inputDetail(){
            cout << "Enter Ticket ID: ";
            cin >> TicketID;

            cout << "Enter Passenger Name: ";
            cin >> passengerName;

            cout << "Enter Age: ";
            cin >> age;

            cout << "Enter Destination: ";
            cin >> Destination;

            cout << "Enter Distance (km): ";
            cin >> distanceTravel;

            baseFare = distanceTravel * 2;

        }
        virtual void calculateFare() = 0; // polymorphism

        virtual void display(){
            cout << "\nTicket ID: " << TicketID;
            cout << "\nName: " << passengerName;
            cout << "\nAge: " << age;
            cout << "\nDestination: " << Destination;
            cout << "\nDistance: " << distanceTravel;
         }



};

class SleeperClass : public Ticket{

    private:
        float SleeperCharge;
        int sleeperSeats; //100

    public:

        void SleeperInput(){
             inputDetail();
        }
        void display(){
             Ticket::display();
             cout << "\nClass: Sleeper";
             cout << "\nFare: " << totalFare << endl;
    }

};

class ACclass : public Ticket{

    private:

        float ACcharges;
        int ACseats;  //50

    public:

        void ACinput(){
            inputDetail();   
        }
         void display(){
            Ticket::display();
            cout << "\nClass: AC";
            cout << "\nFare: " << totalFare << endl;
         }

};

void passenger(){

}

class RailwaySystem{
public:

    void bookTicket(){
        int choice;
        cout << "\n1. Sleeper\n2. AC\nChoose Class: ";
        cin >> choice;

        if(choice == 1){
            SleeperClass s;
            s.SleeperInput();
            s.calculateFare();
            s.display();
        }
        else if(choice == 2){
            ACclass a;
            a.ACinput();
            a.calculateFare();
            a.display();
        }
        else{
            cout << "Invalid Choice!\n";
        }
     }
     void viewTickets(){
     }
     void cancelTicket(){
     }
     void showStatus(){
        cout << "\nTotal Tickets Booked: " << Ticket::totalTickets;
        cout << "\nAvailable Sleeper Seats: " << Ticket::sleeperSeats;
        cout << "\nAvailable AC Seats: " << Ticket::ACseats << endl;
    }



};

int main(){
    RailwaySystem rs;
    int choice;

    do{
        cout << "\n===== RAILWAY SYSTEM =====\n";
        cout << "1. Book Ticket\n";
        cout << "2. View Tickets\n";
        cout << "3. Cancel Ticket\n";
        cout << "4. Seat Status\n";
        cout << "5. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch(choice){
            case 1: rs.bookTicket(); break;
            case 2: rs.viewTickets(); break;
            case 3: rs.cancelTicket(); break;
            case 4: rs.showStatus(); break;
            case 5: cout << "Thank You!\n"; break;
            default: cout << "Invalid Choice!\n";
        }

    }while(choice != 5);

    return 0;
}
