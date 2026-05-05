#include<iostream>
#include<string>
#include<iomanip>
using namespace std; 

class RailwaySystem{};

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

        friend class RailwaySystem;

};

class SleeperClass : public Ticket{

    private:
        float SleeperCharge;
        int sleeperSeats; //100

    public:

        SleeperClass(){
            if(age < 12){
                baseFare *= 0.5; // 50% discount for children
            }
            else if(age >= 60){
                baseFare *= 0.7; // 30% discount for senior citizens
            }
            else{
                baseFare = baseFare; // No discount for adults
            }
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

        friend class RailwaySystem;

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
            if(age < 12){
                baseFare *= 0.5; // 50% discount for children
            }
            else if(age >= 60){
                baseFare *= 0.7; // 30% discount for senior citizens
            }
            else{
                baseFare = baseFare; // No discount for adults
            }
            ACcharges = baseFare + 500;
            ACseats--;

        }


         void display() override{
            Ticket::display();
            cout << "AC Charge: " << ACcharges <<endl;
            cout << "Remaining AC Seats: " << ACseats << endl;
        }

        friend class RailwaySystem;

};


class RailwaySystem{

    Ticket t;
    SleeperClass s;
    ACclass a;
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
         cout<<"Total Tickets: "<<t.Totalseats<<endl;
         cout<<"Sleeper Seats Left: "<<s.sleeperSeats<<endl;
         cout<<"AC Seats Left: "<<a.ACseats<<endl;
        
    }



};

int main(){
    RailwaySystem rs;
    int ch;

    do{
        cout<<"1.Book Ticket."<<endl;
        cout<<"2.View Tickets."<<endl;
        cout<<"3.Status."<<endl;
        cout<<"4.Exit."<<endl;
        cout<<"Choice:"<<endl;
        cin>>ch;

        switch(ch){
            case 1: rs.bookTicket();
            case 2: rs.viewTickets();
            case 3: rs.showStatus();
        }
    }
        while(ch != 4);
    return 0;
   
}
