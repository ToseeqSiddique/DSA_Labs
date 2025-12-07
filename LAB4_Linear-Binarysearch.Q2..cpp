//write a C++ program that:
//takes an array of student roll numbers.
//if the entered roll number is Even, perform Binary search in ascending order.
//if the entered roll number is Odd, perform Binary search in descending order.
//Display the position of the roll number if found.
#include<iostream>
using namespace std;
int main(){
	int n,key;
	int rollno[n];
	cout<<"Enter number of students:"<<endl;
	cin>>n;
	cout<<"Enter Roll numbers:"<<endl;
	for(int i=0;i<n;i++){
		cin>>rollno[i];
	}
	cout<<"Enter Roll number to search:"<<endl;
	cin>>key;
	int result=-1;//flag variable
	int temp;
	int low=0,high=n-1,mid;
	if(key%2==0){
		cout<<"Roll number is Even:"<<endl;
		for(int i=0;i<n-1;i++){
			for(int j=0;j<n-i-1;j++){
				if(rollno[j]>rollno[j+1]){
					temp=rollno[j];
					rollno[j]=rollno[j+1];
					rollno[j+1]=temp;
				}
			}
		}cout<<"Array sorted in Ascending order:"<<endl;
		for(int i=0;i<n;i++){
			cout<<rollno[i]<<endl;
		}
		int low=0,high=n-1,mid;
		while(low<=high){
			mid=(low+high)/2;
			if(rollno[mid]==key){
				result=mid;
				break;
			}else if(rollno[mid]<key){
				low=mid+1;
			}else{
				high=mid-1;
			}
		}
	}else{
		cout<<"Roll number is Odd:"<<endl;
		for(int i=0;i<n-1;i++){
			for(int j=0;j<n-i-1;j++){
				if(rollno[j]<rollno[j+1]){
				   temp=rollno[j];
				   rollno[j]=rollno[j+1]; 
				   rollno[j+1]=temp;
				}
			}
		}cout<<"Array sorted in Descending order:"<<endl;
		for(int i=0;i<n;i++){
			cout<<rollno[i]<<endl;
			 
		}while(low<=high){
			 
			if(rollno[mid]==key){
				result=mid;
				break;
			}else if(rollno[mid]>key){
				low=mid+1;
			}else{
				high=mid-1;
			}
		}
	}
	if(result!=-1){
		cout<<"Roll Number is found at position:"<<result+1<<endl;
	}else{
		cout<<"Roll Number not found!"<<endl;
	}
	return 0;
}
