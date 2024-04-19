#include <iostream>
using namespace std;

//-------------------------------------------------------------------------------------------------------
//Math Project 2
//By Group 4: Montana Merkle, Thomas Ludwig, Joseph Pope, Sarah Grossheim
//Lighting Game 1, Question 2
//Linear Algebra
//Dr.Quinn
//-------------------------------------------------------------------------------------------------------

//*****************************************
//Class declaration
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
//Class definition
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
	
	//return true and set count of turns for each switch if working configuration (can be turned into 11111 or already off)
	if((A==false)&&(B==false)&&(C==false)&&(D==true)&&(E==true)){
		numE++;
		return true;
	}
	else if((A==true)&&(B==true)&&(C==true)&&(D==false)&&(E==false)){
		numB++;
		return true;
	}
	else if((A==true)&&(B==false)&&(C==true)&&(D==false)&&(E==true)){
		numC++;
		numA++;
		numE++;
		return true;
	}
	else if((A==false)&&(B==true)&&(C==false)&&(D==true)&&(E==false)){
		numB++;
		numA++;
		numC++;
		return true;
	}
	else if((A==true)&&(B==false)&&(C==false)&&(D==false)&&(E==true)){
		numC++;
		numB++;
		numE++;
		return true;
	}
	else if((A==false)&&(B==true)&&(C==true)&&(D==true)&&(E==false)){
		numC++;
		return true;
	}
	else if((A==false)&&(B==false)&&(C==true)&&(D==false)&&(E==false)){
		numE++;
		numD++;
		return true;
	}
	else if((A==true)&&(B==true)&&(C==false)&&(D==true)&&(E==true)){
		numA++;
		numE++;
		return true;
	}
	else if((A==false)&&(B==true)&&(C==true)&&(D==false)&&(E==true)){
		numE++;
		numC++;
		return true;
	}
	else if((A==true)&&(B==false)&&(C==false)&&(D==true)&&(E==false)){
		numB++;
		numC++;
		return true;
	}
	else if((A==true)&&(B==true)&&(C==false)&&(D==false)&&(E==false)){
		numA++;
		return true;
	}
	else if((A==false)&&(B==false)&&(C==true)&&(D==true)&&(E==true)){
		numD++;
		return true;
	}
	else if((A==true)&&(B==false)&&(C==true)&&(D==true)&&(E==false)){
		numA++;
		numC++;
		return true;
	}
	else if((A==false)&&(B==true)&&(C==false)&&(D==false)&&(E==true)){
		numD++;
		numC++;
		return true;
	}
	else if((A==true)&&(B==true)&&(C==true)&&(D==true)&&(E==true)){
		numD++;
		numA++;
		return true;
	}
	//if they're already all off, dont change turns and stays at 0
	else if((A==false)&&(B==false)&&(C==false)&&(D==false)&&(E==false)){
		return true;
	}
	
	//everything else: false
	return false;
}

int main(){
	//define local variables (count number of times each light is toggled and result of solvable method)
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
    if (result == true){
    	cout << "This configuration is solvable to reach the all off state: 00000" << endl;
		cout << "Turns needed for each switch: " << endl;
		cout << "A: " << numA << endl;
		cout << "B: " << numB << endl;
		cout << "C: " << numC << endl; 
		cout << "D: " << numD << endl;
		cout << "E: " << numE << endl;
	}
	else
    	cout << "This configuration is not solvable and can not reach the all off state: 00000" << endl;
    
    return 0;
}
