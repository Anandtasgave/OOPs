#include<bits/stdc++.h>
using namespace std;

struct Person{
string name, add, bd;
int number;

void setname(string n){ name=n; }
void setadd(string ad){ add=ad; }
void setbd(string bid){ bd=bid; }
void setnum(int num){ number=num; }

string getname(){return name;}
string getadd(){return add;}
string getbd(){return bd;}
int getnum(){return number;}
};

struct Student{
char div;
string prn;
int avg;

void setclass(char c){ div=c; }
void setprn(string pr){ prn=pr; }
void setavg(int av){ avg=av; }

char getclass(){return div;}
string getprn(){return prn;}
int getavg(){return avg;}
};

struct Employee{
string des;
int salary;
void setdes(string pos){ des=pos; }
void setsalary(int sal){ salary=sal; }

string getdes(){return des;}
int getsalary(){return salary;}
};

int main(){
Person p;
p.setname("Bob");
p.setadd("1/34 lane 2");
p.setbd("23-12-2004");
p.setnum(1234567890);

cout<<p.getname()<<" "<<p.getadd()<<" "<<p.getbd()<<" "<<p.getnum()<<endl;


Student s;
s.setclass('B');
s.setprn("22UCS133");
s.setavg(81);

cout<<s.getclass()<<" "<<s.getprn()<<" "<<s.getavg()<<endl;

Employee e;
e.setdes("Manager");
e.setsalary(10000);

cout<<e.getdes()<<" "<<e.getsalary()<<endl;
}
