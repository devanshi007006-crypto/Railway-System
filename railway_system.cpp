#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
using namespace std; 

class RailwaySystem;

class Ticket{

    public:

        int TicketID;
        string passengerName;
        float distanceTravel; // in km
        float baseFare;
        string Destination;
        int age;
        int Totalseats;  //200
        
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

            cin.ignore(); 
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
            
            SleeperCharge = 0;
        }

        void SleeperInput(){
            inputDetail();
        
        }
        // sleeper
        void CalculateScharge(){
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
    Ticket tickets[200];
    int count = 0;

    RailwaySystem(){
        count = 0;
    }

    void bookTicket(){
        int choice;
        cout << "1. Sleeper class"<<endl;
        cout<<"2. AC Class"<<endl;
        cout<<"3. Regular Class"<<endl;
        cout<<"Choose Class: ";
        cin >> choice;

        if(count >= 100){
            cout<<"No more bookings possible!"<<endl;
            return;
        }


        if(choice == 1){
            SleeperClass s;
            s.SleeperInput();
            s.calculateFare();
            s.CalculateScharge();
            s.display();

            tickets[count++] = s; // store
        }
        else if(choice == 2){
            ACclass a;
            a.ACinput();
            a.calculateFare();
            a.CalculateACcharge();
            a.display();

            tickets[count++] = a; // store
        }
        else if(choice == 3){
            Ticket* t;
            t->inputDetail();
            t->calculateFare();
            t->display();

            tickets[count++] = *t; // store
        }
        else{
            cout << "Invalid Choice!"<<endl;
        }
     }
     void viewTickets(){
       
        if(count == 0){
            cout<<"No tickets booked yet!\n";
            return;
        }

        cout<<"\n--- All Tickets ---\n";
        for(int i=0; i<count; i++){
            cout<<"\nTicket "<<i+1<<endl;
            tickets[i].display();
        }
     }
     void cancelTicket(){

            int id;
            cout<<"Enter Ticket ID to cancel: ";
            cin>>id;
    
            for(int i=0; i<count; i++){
                if(tickets[i].TicketID == id){
                    cout<<"Ticket Cancelled: "<<tickets[i].passengerName<<endl;
                    for(int j=i; j<count-1; j++){
                        tickets[j] = tickets[j+1];
                    }
                    count--;
                    return;
                }
            }
            cout<<"Ticket ID not found!"<<endl;

     }

     void showStatus(){
         cout<<"Total Tickets: "<<t.Totalseats<<endl;
         cout<<"Sleeper Seats Left: "<<s.sleeperSeats<<endl;
         cout<<"AC Seats Left: "<<a.ACseats<<endl;
        
    }

};

int main(){
    RailwaySystem rs;
    fstream file("tickets.txt", ios::out | ios::app);
    int ch;

    file.open("tickets.txt", ios::out);

    
    do{
        cout<<"1.Book Ticket."<<endl;
        cout<<"2.View Tickets."<<endl;
        cout<<"3.Cancel Ticket."<<endl;
        cout<<"4.Status."<<endl;
        cout<<"5.Exit."<<endl;
        cout<<"Choice:";
        cin>>ch;

        switch(ch){
            case 1: {rs.bookTicket(); break;}
            case 2: {rs.viewTickets(); break;}
            case 3: {rs.cancelTicket(); break;}
            case 4: {rs.showStatus(); break;}
        }
    }
        while(ch != 5);


    file << "TicketID,PassengerName,Age,Destination,Distance,BaseFare" <<endl; // Header for CSV
    for(int i=0; i<rs.count; i++){
        file << rs.tickets[i].TicketID << ","
             << rs.tickets[i].passengerName << ","
             << rs.tickets[i].age << ","
             << rs.tickets[i].Destination << ","
             << rs.tickets[i].distanceTravel << ","
             << rs.tickets[i].baseFare << "\n";
    }

    file.close();
    return 0;
   
}
