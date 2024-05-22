#include<iostream>
#include<list>
#include<cstdlib>
using namespace std;
class node {
	public:
	int data;
	node *next;
	
	node()
	{
		data=0;
		next=NULL;
	}
};

class ll{
	public:
	node*head;
	node*createnode()
	{
		node*temp=new node[1];
		return temp;
	}
	ll()
	{
		head=NULL;
		
	}
	void addbegin(int data)
	{
		node*q=createnode();
		q->next=NULL;
		head=q;
		q->data=data;
	}
	void addend(int data)
	{
		node*q=createnode();
		node*temp;
		temp=head;
		q->data=data;
		while(temp->next!=NULL)
		{
			temp=temp->next;
			}
temp->next=q;
q->next=NULL;
}
	void addmid(int pos,int data)
	{

		
		node*q=createnode();
		 
		
		node*temp;
		temp=head;
		q->data=data;
		int i=1;
		while(i<pos-1&&temp!=NULL)
		{
			temp=temp->next;
			++i;
		}
		q->next=temp->next;
		temp->next=q;
	}
	int deletebegin()
	{
		if(head==NULL)
		{
			return -1;
		}
		else{
int ans=head->data;
head=head->next;
		return ans;
		
	}
}
	int deleteend(){
	
		node*prev;
		node*current;
		current =head;
		if (head==NULL)
		{
			return -1;
		}
			if (head->next==NULL)
		{
		int ans=head->data;
head=head->next;
		return ans;
		}
		 while(current->next!=NULL)
		 {
		 	prev=current;
		 	current=current->next;
		 }
		 prev->next=NULL;
		 return current->data;
		 
	}
	int deletemid(int pos)
{
	int i=0;
	node*current;
	node*prev;
	current=head;
	if (head->next==NULL)
	{
		int ans=head->data;
head=head->next;
		return ans;
	}
	while(i<pos-1)
	{
		prev=current;
		current=current->next;
		++i;
		if(current==NULL)
		{
			return -1;

		}
		
	}
	prev->next=current->next;
	return current->data;
	
}
void traverse ()
{
	node*temp;
	temp=head;
	while(temp!=NULL)
	{
		cout<<temp->data<<endl;
		temp=temp->next;
	}
}
int search(int data)
{
	if (head==NULL)
	{
		return -1;
}

	node*temp;
	temp=head;
	int count=0;
	while(temp!=NULL)
	{
		count++;
		if(temp->data==data)
		{
			return count;
		}
		else
		{
			temp=temp->next;
		}
	}
	return -1;	
}
	
};
int main()
{
	int choice;
	ll l;
	int data;
	int pos;
	int temp;
	while(1)
	{
		cout<<"enter the command"<<endl;
		cout<<"1.add at begin \n2.add at end\n3.add at anywhere\n4.delete at begin \n5.delete at end \n6.delete at anywhere \n7.traverse \n8.search\n9.exit"<<endl;
		cin>>choice;
		switch(choice)
		{
			case 1:
				
				cout<<"enter the data to add "<<endl;
				cin>>data;
				l.addbegin(data);
				break;
				case 2:
					
				cout<<"enter the data to add "<<endl;
				cin>>data;
				l.addend(data);
				break;
				case 3:
					
					cout<<"enter the position to add"<<endl;
					cin>>pos;
					cout<<"enter the data to add "<<endl;
				cin>>data;
					l.addmid(pos,data);
					break;
					
				case 4:
					
					temp=l.deletebegin();
					if(temp==-1)
					{
						cout<<"data not deleted "<<endl;
					}
					else
					{
						cout<<"the deleted data is "<<temp<<endl;
						
					}
					break;
					case 5:
						
					temp=l.deleteend();
					if(temp==-1)
					{
						cout<<"data not deleted "<<endl;
					}
					else
					{
						cout<<"the deleted data is "<<temp<<endl;

					}
					break;
					case 6:
							if (l.head==NULL)
						{
							cout<<"no element is there to delete"<<endl;
							break;
						}
						else{
						
						cout<<"enter the position to delete"<<endl;
						cin>>pos;
						
					temp=l.deletemid(pos);
					if(temp==-1)
					{
						cout<<"data not deleted "<<endl;
					}
					else
					{
						cout<<"the deleted data is "<<temp<<endl;

					}
					break;
				}
					case 7:
						if (l.head==NULL)
						{
							cout<<"no element is there to traverse"<<endl;
							break;
						}
						else{

						l.traverse();
						break;
					}
						case 8:
								if (l.head==NULL)
						{
							cout<<"no element is there to search"<<endl;
							break;
						}
						else{
							int s;
							cout<<"enter the data to be search"<<endl;
							cin>>s;
							if(l.search(s)==-1)
							{
								cout<<"element not found"<<endl;
							}
							else
							{
								cout<<"element found at"<<l.search(s)<<endl;
							}
							break;
						}
							case 9:
								exit(0);
								break;
								default:
									cout<<"invalid choice"<<endl;
					}
	}
}
