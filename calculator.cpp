#include<iostream>
#include<string>

using namespace std;

class Operation{
	float num1;
    float num2;
    
public:
	Operation(float n, float m) {
        num1 = n;
        num2 = m;
    }
	
	float add(float number, float number1){
		float result=number + number1;
		cout<<result;
	}
	
	float division(float number, float number1){
		if (number1 != 0) {
            float result=number / number1;
            cout<<result;
        } else {
            cout << "Error: Division by zero." << endl;
            return 0; // Handling division by zero
        }
	}
	
	float multiply(float number, float number1){
		float result=number * number1;
		cout<<result;
	}
	
	float substract(float number, float number1){
		float result=number - number1;
		cout<<result;
	}
};

int main()
{	
	
	string choice;
  float num1;
	float num2;
	
		Operation ezra(num1, num2);
		
	cout<<"Enter the first number:" << endl;
	cin>>num1;
	
	cout<<"Operations:" << endl;
	cin>>choice;
	
	cout<<"Enter the second number:" << endl;
	cin>>num2;
	
	if(choice=="+"){
		ezra.add(num1, num2);
	}else if(choice=="*"){
		ezra.multiply(num1, num2);
	}else if(choice=="-"){
		ezra.substract(num1, num2);
	}else if(choice=="/"){
		ezra.division(num1, num2);
	}else{
		cout<<"ERROR";
	}
	
return 0;
	
}
