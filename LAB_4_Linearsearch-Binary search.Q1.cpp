 //Design a c++ program that can perform both searches based on user selection,
 //and display results clearly and accurately.
#include<iostream>
using namespace std;
int main(){
	int n,key,choice;
	int arr[n];
	cout<<"Enter the number of students:"<<endl;
	cin>>n;
	cout<<"Enter Roll number:"<<endl;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}cout<<"Choose Method:"<<endl;
	cout<<"1.Linear search for unsorted:"<<endl;
	cout<<"2.Binary search for sorted:"<<endl;
	
	cout<<"Enter your choice:"<<endl;
	cin>>choice;
	cout<<"Enter Roll number to search:"<<endl;
	cin>>key;
	int result=-1;
	if(choice==1){
		for(int i=0;i<n;i++){
		 if(arr[i]==key){
		 	result=i;
		 	break;
		 }
		}
	}else if(choice==2){
		int low=0,high=n-1,mid;
		while(low<=high){
			mid=(low+high)/2;
			if(arr[mid]==key){
				result=mid;
				break;
			}else if(arr[mid]<key){
				low=mid+1;
			}else{
				high=mid-1;
			}
	}
		}else{
			 cout<<"Invalid data return 0:"<<endl;
		}if(result!=-1){
			cout<<"Roll number found at position:"<<result+1<<endl;
		}else{
			cout<<"Roll number not found:"<<endl;
		}
	return 0;
}
