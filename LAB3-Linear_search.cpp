#include<iostream>
using namespace std;
int main(){
	int key,i;
	int arr[5]={10,20,30,40,50};
	cout<<"Enter Element to search"<<endl;
	cin>>key;
	for(int i=0;i<5;i++){
		if(arr[i]==key){
			cout<<"Element found at index:/n"<<i<<endl;
			return 0;
		 
		}
	}
	 
		cout<<"Element not found!"<<endl;
	return 0;
}
