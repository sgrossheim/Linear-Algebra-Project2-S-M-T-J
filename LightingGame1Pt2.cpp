#include <iostream>
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
       Switches(); //constructor that sets switches to user input
       int CheckIn(char letter); //checks user input of switch state
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
	//create temporary variables for user input
	int tempa;
	int tempb;
	int tempc;
	int tempd;
	int tempe;

	//get initial state of switches from user (check validity too)
	tempa = CheckIn('A');
	tempb = CheckIn('B');
	tempc = CheckIn('C');
	tempd = CheckIn('D');
	tempe = CheckIn('E');
	
	//assign user input to switches in class (as booleans now)
    A = (tempa == 1);
    B = (tempb == 1);
    C = (tempc == 1);
    D = (tempd == 1);
    E = (tempe == 1);
    
    //output current switch configuration
    Print();
}

//gets user input of light switches state
int Switches::CheckIn(char letter){
	//temp int variable to return
	int in;
	
	//get initial state of switches from user and make sure it's either a 0 or 1
	cout << "Enter initial state of light switch " << letter << " (0 for off and 1 for on): ";
	cin >> in;
	while(in > 1 || in < 0){
		cout << "INVALID - enter 0 for off and 1 for on: ";  
		cin >> in;
	}
	//return checked state of switch
	return in;
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



int main(){
    //instantiation
    Switches panel;
    //panel.Print();
    //cout << endl;
    
    
    return 0;
}