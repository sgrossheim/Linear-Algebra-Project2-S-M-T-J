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
       bool Solvable(int& numA, int& numB, int& numC, int& numD, int& numE);
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
	cout << endl;
	cout << "Current State of Switches: " << endl;
    cout << "A    B    C    D    E" << endl;
    cout << A << "    " << B << "    " << C << "    " << D << "    " << E << endl;
}

//determines if configuration is solvable
bool Switches::Solvable(int& numA, int& numB, int& numC, int& numD, int& numE){
	//get number of lights on
	int count = 0;
	if (A == true)
		count++;
	if (B == true)
		count++;
	if (C == true)
		count++;
	if (D == true)
		count++;
	if (E == true)
		count++;
		
	// if count is even
	if ((count % 2) == 0){
		//if c is on
		if(C == true)
			return false;
		//if a and b are on
		if(((A == true) && (B == true)) || ((D == true) && (E == true))){
			//determine if grouping results in 2 or 1 turns
			if(count == 4){
				numA = 1;
				numE = 1;
			}
			else
				if(A == true)
					numA = 1;
				else
					numE = 1;	
			return true;
		}
	}
	
	//if only one switch on
	else if (count == 1)
		return false;
		
	//if odd and grouped together (three in a row) or (10101)
	else if(((A == true)&&(B == true)&&(C == true)) || ((B == true)&&(C == true)&&(D == true)) || ((C == true)&&(D == true)&&(E == true)) || ((A == true)&&(C == true)&&(E == true))){
		//determine number of turns - either all on or group of three
		if (count == 5){
			numB = 1;
			numE = 1;
		}
		else
			//if grouping of three of ABC
			if((A == true) && (B == true))
				numB = 1;
			//if grouping of three of BCD
			else if((B == true) && (C == true))
				numC = 1;
			//if three where ACE are on
			else if((A == true) && (C == true)){
				numA = 1;
				numE = 1;
				numC = 1;
			}
			//if grouping of three of CDE
			else
				numD = 1;
		return true;
	}
	
	//if they're already all off, dont change turns and stays at 0
	else if (count == 0)
		return true;
	
	//everything else: false
	return false;
}

int main(){
	//define local variables
	bool result;
	int numA = 0;
    int numB = 0;
    int numC = 0;
    int numD = 0;
    int numE = 0;
	
    //instantiation
    Switches panel;
    result = panel.Solvable(numA, numB, numC, numD, numE);
    cout << endl;
    
    //output results
    if (result == 1){
    	cout << "This configuration is solvable" << endl;
		cout << "Turns needed for each switch: " << endl;
		cout << "A: " << numA << endl;
		cout << "B: " << numB << endl;
		cout << "C: " << numC << endl; 
		cout << "D: " << numD << endl;
		cout << "E: " << numE << endl;
	}
	else
    	cout << "This configuration is not solvable." << endl;
    
    return 0;
}
