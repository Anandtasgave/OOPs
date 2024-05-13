#include<bits/stdc++.h>
#include "vehicl.h"
using namespace std;

class Vehicle{
	private:
	int numWheels;
	string color;
	int maxSpeed;
	int maxGears;
	int curGear;
	int curSpeed;
	bool started;
	bool stoped;
	
	public:
	Vehicle(int wheel, string c, int s, int g){}
	
	int getWheels();
	int getMaxGears();
	int getMaxSpeed();
	int getSpeed();
	
	
	//start
	void start();
	//stop
	void stop();
	
	void display();
	
	//next Gear
	void nextGear();
	
	//prev Gear
	void prevGear();
	
	// increase speed
	void incSpeed();
	
	// decrease speed
	void decSpeed();
	
};

int main(){
	int wheels, maxspeed, maxgear;
	string color;
	cin>>wheels>>maxspeed>>maxgear>>color;
	Vehicle car(wheels, color, maxspeed, maxgear);
	int ch;
	do{
		
		cout<<"\n1.start\n";
		cout<<"2.Increase speed\n";
		cout<<"3.Decrease speed\n";
		cout<<"4.Stop";
		cout<<"\nEnter your choice:\n";
		cin>>ch;
		
		switch(ch){ 
			case 1:
				car.start();
				break;
			case 2:
				car.incSpeed();
				break;
			case 3:
				car.decSpeed();
				break;
			case 4:
				car.stop();
				break;
			default:
				cout<<"Invalid Choice.\nEnter correct choice.";
		}
		
	}while(ch!=4);
	
}
