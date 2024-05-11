#include<bits/stdc++.h>
using namespace std;

class Day{
	int day,month,year;

	public:

	Day(int d,int m,int y): day(d),month(m), year(y){}
	bool isLeapYear();
	bool isValidDay();
	void incrementDate();
	int getDay();
	int getMonth();
	int getYear();
#if 0
	bool isLeapYear(){
		return (year%4==0 && year%100!=0) || (year%400==0);	
	}

	bool isValidDay(){
		if(month<1 || month>12 || day>31 || year>=2024){ return false; } 
		int dayMonth[]={31,28+isLeapYear(),31,30,31,30,31,31,30,31,30,31};
		return day<=dayMonth[month-1];
	}

	void incrementDate(){
	int dayMonth[]={31,28+isLeapYear(),31,30,31,30,31,31,30,31,30,31};
		if(++day>=dayMonth[month-1]){
			day=1;
			if(++month>12){
				month=1;
				year++;
			}		
		}
	}
	int getDay(){ return day; }
	int getMonth(){ return month; }
	int getYear(){ return year; }
#endif
};






	bool Day::isLeapYear(){
		return (year%4==0 && year%100!=0) || (year%400==0);	
	}

	bool Day::isValidDay(){
		if(month<1 || month>12 || day>31 || year>=2024){ return false; } 
		int dayMonth[]={31,28+isLeapYear(),31,30,31,30,31,31,30,31,30,31};
		return day<=dayMonth[month-1];
	}

	void Day::incrementDate(){
	int dayMonth[]={31,28+isLeapYear(),31,30,31,30,31,31,30,31,30,31};
		if(++day>=dayMonth[month-1]){
			day=1;
			if(++month>12){
				month=1;
				year++;
			}		
		}
	}
	int Day::getDay(){ return day; }
	int Day::getMonth(){ return month; }
	int Day::getYear(){ return year; }

int main(){
	int da,m,y;
	cin>>da>>m>>y;
	Day d(da,m,y);
	

	if(d.isLeapYear()){
		cout<<"This is leap year"<<endl;
	}
	else{
		cout<<"This is not a leap year"<<endl;
	}

	if(d.isValidDay()){
		cout<<"This is valid day"<<endl;
	}
	else{
		cout<<"This is not a valid day"<<endl;
	}
	d.incrementDate();
	
	cout<<d.getDay()<<"-"<<d.getMonth()<<"-"<<d.getYear()<<endl;
	cout<<d.getDay()<<"/"<<d.getMonth()<<"/"<<d.getYear()<<endl;

	string month[]={"JAN", "FEB", "MAR", "APR", "MAY", "JUN", "JUL", "AUG", "SEP", "OCT", "NOV", "DEC"};
	cout<<d.getDay()<<"/"<<month[d.getMonth()-1]<<"/"<<d.getYear()<<endl;
}
