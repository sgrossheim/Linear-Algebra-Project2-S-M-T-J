#include <iostream>
#include <time.h>
using namespace std;

//Montana Merkle
//Math Project 2
//Linear Algebra

//*****************************************
//Class header or declaration
//*****************************************

class Switches{
private:    
      //Data representation
      bool A;
      bool B;
      bool C;
      bool D;
      bool E;
public:
       //constructors
       Switches(); //constructor that sets switches to random
       void Print() const; //Print method
       void Swap(bool& spefswitch); //swap state of switch
       void SwitchA();
       void SwitchB();
       void SwitchC();
       void SwitchD();
       void SwitchE();
};     

//*****************************************
//Class implementation or definition
//*****************************************

//constructor
Switches::Switches(){   
	//seed rand()
	srand(time(NULL));
	      
	//rand()%2 will determine if random number generated is even and sets to true if so             
    A = (rand()%2==0);
    B = (rand()%2==0);
    C = (rand()%2==0);
    D = (rand()%2==0);
    E = (rand()%2==0);
    cout << "Switches set to random" << endl;
}

//outputs current state of switches
void Switches::Print() const{
	cout << "Current State of Switches: " << endl;
    cout << "A    B    C    D    E" << endl;
    cout << A << "    " << B << "    " << C << "    " << D << "    " << E << endl;
}

void Switches::Swap(bool& spefswitch){
	if (spefswitch == false)
		spefswitch = true;
	else
		spefswitch = false;
}

void Switches::SwitchA(){
	Swap(A);
	Swap(B);
	Print();
}

void Switches::SwitchB(){
	Swap(B);
	Swap(A);
	Swap(C);
	Print();
}

void Switches::SwitchC(){
	Swap(C);
	Swap(B);
	Swap(D);
	Print();
}

void Switches::SwitchD(){
	Swap(D);
	Swap(C);
	Swap(E);
	Print();
}

void Switches::SwitchE(){
	Swap(E);
	Swap(D);
	Print();
}

//function for menu
void menu(){
	cout << "a - Switch A" << endl;
	cout << "b - Switch B" << endl;
	cout << "c - Switch C" << endl;
	cout << "d - Switch D" << endl;
	cout << "e - Switch E" << endl;
	cout << "q - Quit" << endl;	
}

int main(){
    //instantiation
    Switches panel;
    panel.Print();
    cout << endl;
    
    //define variables
	char choice = 'q';
	
	//outputs menu and gets user choice
	menu();
	cout << "Enter Menu Selection: ";
	cin >> choice;
	cout << endl;
  
    while (choice != 'q'){
    	if (choice == 'a')
    		panel.SwitchA();
    	else if (choice == 'b')
    		panel.SwitchB();
    	else if (choice == 'c')
    		panel.SwitchC();
    	else if (choice == 'd')
    		panel.SwitchD();
    	else if (choice == 'e')
    		panel.SwitchE();
    		
    	//if selection is invalid output error and call for menu output
		else{
			cout << "Invalid Menu Selection" << endl;
			menu();
		}
		
		//calls for new user choice
		cout << endl;
		cout << "Enter Menu Selection: ";
		cin >> choice;
		cout << endl;
	}
    return 0;
}