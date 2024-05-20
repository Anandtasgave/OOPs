#include<iostream>
#include<string>
#include<iomanip>

using namespace std;

int main(){
string movieName;
double adultTicket,childTicket, charity;
int numAdultTicketSold; 
int numofChildTicketSold;

cout<<"Enter the movie name: ";
getline(cin, movieName);

cout<<"Enter Adult ticket price:";
cin>>adultTicket;

cout<<"Enter Child ticket price:";
cin>>childTicket;

cout<<"Enter Charity donation percentage:";
cin>>charity;

cout<<"Enter the number of Adult ticket sold: ";
cin>>numAdultTicketSold;

cout<<"Enter the number of Child ticket sold: ";
cin>>numofChildTicketSold;

int totalTicketSold=numAdultTicketSold + numofChildTicketSold;


double totalGrossAmount=(adultTicket * numAdultTicketSold)+(childTicket*numofChildTicketSold);
double donation=totalGrossAmount*(charity/100);
double netAmount=totalGrossAmount-donation;

cout<<endl<<endl;
cout<<"Movie Name:"<<setfill('*')<<setw(41)<<movieName<<endl;
cout<<"Number of tickets sold:"<<setw(23)<<totalTicketSold<<endl;
cout<<"Gross Amount:"<<setw(38)<<fixed<<setprecision(2)<<totalGrossAmount<<endl;
cout<<"Percentage of gross Amount Donation:"<<setw(13)<<charity<<"%"<<endl;
cout<<"Amount Donated:"<<setw(35)<<fixed<<setprecision(2)<<donation<<endl;
cout<<"Net Sale:"<<setw(42)<<fixed<<setprecision(2)<<netAmount<<endl;

}
