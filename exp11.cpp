#include<bits/stdc++.h>
using namespace std;

class Date{
private:
	int day, month year;
public:
	Date(): date(0), month(0), year(0){}
	
	void setDate(int d, int m, int y){
		if(d<=0 || d>31 || m<=0 || m>12)
			throw invalid_argument("Invalid Date");
			
		day=d;
		month=m;
		year=y;	
	}
	
	void getDate(){
		cout<<"Date: "<<day<<endl;
		cout<<"Month: "<<month<<endl;
		cout<<"Year: "<<year<<endl;
	}
};

class Person{
	private:
		string name;
		Date dob;
	
	public:
		void setName(string name){
			this->name=name;
		}
		
		void setDob(int d, int m, int y){
			dob.setDate(d,m,y);
		}
		
		string getName(){ return name;}
		Date getDob(){ return 
};

int main(){

}
