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
        int Totalseats;  //200

    public:

       Ticket(){
        Totalseats = 200;
        baseFare = 0;
       }

        void inputDetail(){
            cout << "Enter Ticket ID: ";
            cin >> TicketID;

            cout << "Enter Passenger Name: ";
            cin >> passengerName;

            cout << "Enter Age: ";
            cin >> age;

            getchar(); 

            cout << "Enter Destination: ";
            getline(cin,Destination);

            cout << "Enter Distance (km): ";
            cin >> distanceTravel;

        }

        void calculateFare(){

            baseFare = distanceTravel * 1.5;

        }

        virtual void display(){
            cout << "Ticket ID: " << TicketID <<endl;
            cout << "Name: " << passengerName <<endl;
            cout << "Age: " << age <<endl;
            cout << "Destination: " << Destination <<endl;
            cout << "Distance: " << distanceTravel <<endl;
            cout << "Base Fare: " << baseFare <<endl;
        }

};

class SleeperClass : public Ticket{

    private:
        float SleeperCharge;
        int sleeperSeats; //100

    public:

        SleeperClass(){
            sleeperSeats = 100;
            SleeperCharge = 0;
        }

        void SleeperInput(){
            inputDetail();
        
        }
        // sleeper
        void CalculateScharge(){
            SleeperCharge = baseFare + 200;
            sleeperSeats--;
        }

        void display() override {
            Ticket::display();
            cout << "Sleeper Charge: " << SleeperCharge <<endl;
            cout << "Remaining Sleeper Seats: " << sleeperSeats << endl;
        }

};

class ACclass : public Ticket{

    private:

        float ACcharges;
        int ACseats;  //50

    public:
        ACclass(){
            ACseats = 50;
            ACcharges = 0;
        }

        void ACinput(){
            inputDetail();
           
        }

        void CalculateACcharge() {
            ACcharges = baseFare + 500;
            ACseats--;

        }


         void display() override{
            Ticket::display();
            cout << "AC Charge: " << ACcharges <<endl;
            cout << "Remaining AC Seats: " << ACseats << endl;
        }

};

void passenger(){

}

class RailwaySystem{
public:

    void bookTicket(){
        int choice;
        cout << "1. Sleeper"<<endl;
        cout<<"2. AC"<<endl;
        cout<<"3. Regural"<<endl;
        cout<<"Choose Class: ";
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
        else if(choice == 3){
            Ticket* t;
            t->inputDetail();
            t->calculateFare();
            t->display();
        }
        else{
            cout << "Invalid Choice!"<<endl;
        }
     }
     void viewTickets(){
     }
     void cancelTicket(){
     }
     void showStatus(){
        
    }



};

int main(){
   

    return 0;
}
