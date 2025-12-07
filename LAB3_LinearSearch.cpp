//Write a program that asks the user to enter search key to search any element in array using linear searching method.
//You are given the marks of 30 students in three subjects,make result of the students.
#include<iostream>
using namespace std;
int main(){
	const int size=30;
	int key;
	int rollno[size]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30};
	int PF[size]={55,56,50,58,59,50,60,65,66,67,68,69,61,75,76,77,87,98,90,80,76,54,59,51,72,83,93,83,81,51};
	int OOP[size]={ 40,54,63,76,87,98,34,23,65,76,88,98,78,89,77,65,76,34,76,45,33,24,53,12,32,54,35,62,55,50};
	int DSA[size]={ 77,65,76,34,76,45,33,24,53,12,32,54,35,62,55,50,55,56,50,58,59,50,60,65,66,67,68,69,61,75};
	cout<<"Enter Roll number to search :"<<endl;
	cin>>key;
	int index=-1;//flag variable
	for(int i=0;i<30;i++){
		if(rollno[i]==key){
		index=i;
			break;
		}
	}if(index!=-1){
		int total=PF[index]+OOP[index]+DSA[index];
		float percentage=total/3.0;
		char grade;
		float gpa;
		if(percentage>=80){
				grade='A';gpa=4.0;
			}else if(percentage>=72){
				grade='B';gpa=3.5;
			}else if(percentage>=65){
				grade='C';gpa=3.0;
			}
			else if(percentage>=50){
				grade='D';gpa=2.00;
			}else if(percentage<50){
				grade='F';gpa=0.0;
			}
			cout<<"........Student Result......... "<<endl;
			cout<<"Roll Number:"<<rollno[index]<<endl;
			cout<<"PF marks:"<<PF[index]<<endl;
			cout<<"OOP marks:"<<OOP[index]<<endl;
			cout<<"DSA marks:"<<DSA[index]<<endl;
			cout<<"Total marks:"<<total<<"/3.0"<<endl;
			cout<<"Percentage:"<<percentage<<"%"<<endl;
			cout<<"Grade:"<<grade<<endl;
			cout<<"GPA:"<<gpa<<endl;
		}
		else{
			cout<<"Result not found!"<<endl;
		}
		return 0;
}
