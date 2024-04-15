#include <iostream>
#include <time.h>
#include <string>
using namespace std;

//Montana Merkle
//Math Project 2
//Linear Algebra

//*****************************************
//Class header or declaration
//*****************************************

class Square{
private:    
      //Data representation
      int numbers[9];
      std::string colors[9];
public:
       //constructors
       Square(); //constructor that sets switches to random
       void Print() const; //Print method
       void Hit(int indexChange); //change state of square
       void One();
       void Two();
       void Three();
       void Four();
       void Five();
       void Six();
       void Seven();
       void Eight();
       void Nine();
};     

//*****************************************
//Class implementation or definition
//*****************************************

//constructor
Square::Square(){   
	//seed rand()
	srand(time(NULL));
	      
	//rand()%3 will set each number to random number between 0-3             
    for(int i = 0; i < 9; i++){
    	numbers[i] = (rand()%3);
	}
    cout << "Square set to random" << endl;

	//set colors to correct state based on random number generated
	for(int i = 0; i < 9; i++){
		if(numbers[i] == 0)
			colors[i] = "off";
		else if(numbers[i] == 1)
			colors[i] = "red";
		else
			colors[i] = "green";
	}
	
	//A = (1);
	//B = (0);
	//C = (1);
	//D = (0);
	//E = (1);
}

//outputs current state of switches
void Square::Print() const{
	cout << "Current State of Square: " << endl;
	cout << numbers[0] << "    " << numbers[1] << "    " << numbers[2] << endl;
    cout << numbers[3] << "    " << numbers[4] << "    " << numbers[5] << endl;
    cout << numbers[6] << "    " << numbers[7] << "    " << numbers[8] << endl;
    
    cout << "---------------------------------------------------------------------" << endl;
	
    cout << colors[0] << "       " << colors[1] << "       " << colors[2] << endl;
    cout << colors[3] << "       " << colors[4] << "       " << colors[5] << endl;
    cout << colors[6] << "       " << colors[7] << "       " << colors[8] << endl;
}

void Square::Hit(int indexChange){
	//incriments number based on index and mod by 3
	numbers[indexChange] = ((numbers[indexChange] + 1) %3);
	
	//assign correct color based on new number
	if(numbers[indexChange] == 0)
		colors[indexChange] = "off";
	else if(numbers[indexChange] == 1)
		colors[indexChange] = "red";
	else
		colors[indexChange] = "green";
}

void Square::One(){
	Hit(0);
	Hit(1);
	Hit(3);
	Hit(4);
	Print();
}

void Square::Two(){
	Hit(0);
	Hit(1);
	Hit(2);
	Print();
}

void Square::Three(){
	Hit(1);
	Hit(2);
	Hit(4);
	Hit(5);
	Print();
}

void Square::Four(){
	Hit(0);
	Hit(3);
	Hit(6);
	Print();
}

void Square::Five(){
	Hit(1);
	Hit(3);
	Hit(4);
	Hit(5);
	Hit(7);
	Print();
}

void Square::Six(){
	Hit(2);
	Hit(5);
	Hit(8);
	Print();
}

void Square::Seven(){
	Hit(3);
	Hit(4);
	Hit(6);
	Hit(7);
	Print();
}

void Square::Eight(){
	Hit(6);
	Hit(7);
	Hit(8);
	Print();
}

void Square::Nine(){
	Hit(4);
	Hit(5);
	Hit(7);
	Hit(8);
	Print();
}

//function for menu
void menu(){
	cout << "1 - Square One" << endl;
	cout << "2 - Square Two" << endl;
	cout << "3 - Square Three" << endl;
	cout << "4 - Square Four" << endl;
	cout << "5 - Square Five" << endl;
	cout << "6 - Square Six" << endl;	
	cout << "7 - Square Seven" << endl;
	cout << "8 - Square Eight" << endl;
	cout << "9 - Square Nine" << endl;
	cout << "0 - Quit" << endl;
}

//*****************************************
//Main
//*****************************************

int main(){
    //instantiation
    Square panel;
    panel.Print();
    cout << endl;
    
    //define variables
	int choice = 0;
	
	//outputs menu and gets user choice
	menu();
	cout << "Enter Menu Selection: ";
	cin >> choice;
	cout << endl;
  
    while (choice != 0){
    	if (choice == 1)
    		panel.One();
    	else if (choice == 2)
    		panel.Two();
    	else if (choice == 3)
    		panel.Three();
    	else if (choice == 4)
    		panel.Four();
    	else if (choice == 5)
    		panel.Five();
    	else if (choice == 6)
    		panel.Six();
    	else if (choice == 7)
    		panel.Seven();
    	else if (choice == 8)
    		panel.Eight();
    	else if (choice == 9)
    		panel.Nine();
    		
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