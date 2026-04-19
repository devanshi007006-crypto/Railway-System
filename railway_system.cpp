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
        }

        void inputDetail(){

        }



};

class SleeperClass : public Ticket{

    private:
        float SleeperCharge;
        int sleeperSeats; //100

    public:

        void SleeperInput(){

        }

};

class ACclass : public Ticket{

    private:

        float ACcharges;
        int ACseats;  //50

    public:

        void ACinput(){
            
        }


};

void passenger(){

}

class RailwaySystem{


};

int main(){



    return 0;
}