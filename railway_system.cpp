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

       Ticket(){
        Totalseats = 150;
       }

        void inputDetail(){
            cout << "Enter Ticket ID: ";
            cin >> TicketID;

            cout << "Enter Passenger Name: ";
            cin >> passengerName;

            cout << "Enter Age: ";
            cin >> age;

            cout << "Enter Destination: ";
            getline(cin,Destination);

            cout << "Enter Distance (km): ";
            cin >> distanceTravel;

        }

        void calculateFare(){

        }
        virtual void display(){
            cout << "Ticket ID: " << TicketID <<endl;
            cout << "Name: " << passengerName <<endl;
            cout << "Age: " << age <<endl;
            cout << "Destination: " << Destination <<endl;
            cout << "Distance: " << distanceTravel <<endl;
         }



};

class SleeperClass : public Ticket{

    private:
        float SleeperCharge;
        int sleeperSeats; //100

    public:

        void SleeperInput(){
        
        }
        // sleeper
        void CalculateScharge(){

        }

        void display() override {
             Ticket::display();
             
        }

};

class ACclass : public Ticket{

    private:

        float ACcharges;
        int ACseats;  //50

    public:

        void ACinput(){
           
        }

        void CalculateACcharge() {

        }


         void display() override{
            Ticket::display();
          
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
