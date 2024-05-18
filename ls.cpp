#include<bits/stdc++.h>
using namespace std;

template<typename T>

bool ls(T arr[], int n, T key){
	for(int i=0; i<n;i++){
		if(arr[i]==key) return true;
	}
	return false;
}

template<typename T>
void bs(T arr[], int n){
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-i-1;j++){
			if(arr[j]>arr[j+1]){
				T temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
}

template<typename T>
void printArray(T arr[], int n){
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0; i<n;i++){
		cin>>arr[i];
	} 
	int key;
	cin>>key;
	if(ls(arr, n, key)) cout<<"Found"<<endl;
	else cout<<"Not Found"<<endl;
	bs(arr, n);
	printArray(arr, n);
}

