#include <iostream>
#include <algorithm>
#include <ctime>
#include <random>
using namespace std;

//Sarah Grossheim
//Math Project 2
//Linear Algebra

// Function declarations
void randConfig(int (&a)[3], int (&b)[3], int (&c)[3]);
void printStates(int a[], int b[], int c[]);
char menu();
void swap(int array[], int size);

int main()
{
	// Declare switches & variables
	int arrayA[] = {0, 1, 2};
	int arrayB[] = {0, 1, 2};
	int arrayC[] = {0, 1, 2};
	char choice;
	
	// Random configuration
	randConfig(arrayA, arrayB, arrayC);
	
	// Print states
	printStates(arrayA, arrayB, arrayC);
	
	// Display menu
	choice = menu();
	
	while(choice != 'q')
	{
		if(choice == 'a')
		{
			swap(arrayA, 3);
			swap(arrayB, 3);
			printStates(arrayA, arrayB, arrayC);
			choice = menu();
		}
		else if(choice == 'b')
		{
			swap(arrayB, 3);
			swap(arrayA, 3);
			swap(arrayC, 3);
			printStates(arrayA, arrayB, arrayC);
			choice = menu();
		}
		else if(choice == 'c')
		{
			swap(arrayC, 3);
			swap(arrayB, 3);
			printStates(arrayA, arrayB, arrayC);
			choice = menu();
		}
		else
		{
			cout << "Invalid Menu selection. Try again." << endl << endl;
			printStates(arrayA, arrayB, arrayC);
			menu();
		}
	}
	
	return 0;
	
}

// function to swap the array's orders
void randConfig(int (&a)[3], int (&b)[3], int (&c)[3])
{
	// Generate a random number between 0 and 2 to determine what 
	// valid pattern the array could be
	srand(time(0));
    int randA = rand() % 3;
    int randB = rand() % 3;
    int randC = rand() % 3;
    int validPatterns1[] = {0, 1, 2};
    int validPatterns2[] = {1, 2, 0};
    int validPatterns3[] = {2, 0, 1};
    
    // Change A
    if(randA == 0)
    {
    	for(int i = 0; i<3; i++)
    	{
    		a[i] = validPatterns1[i];
		}
	}
	else if(randA == 1)
	{
		for(int i = 0; i<3; i++)
    	{
    		a[i] = validPatterns2[i];
		}
	}
    else if(randA == 2)
    {
    	for(int i = 0; i<3; i++)
    	{
    		a[i] = validPatterns3[i];
		}
	}
	
    // Change B
    if(randB == 0)
    {
    	for(int i = 0; i<3; i++)
    	{
    		b[i] = validPatterns1[i];
		}
	}
	else if(randB == 1)
	{
		for(int i = 0; i<3; i++)
    	{
    		b[i] = validPatterns2[i];
		}
	}
    else if(randB == 2)
    {
    	for(int i = 0; i<3; i++)
    	{
    		b[i] = validPatterns3[i];
		}
	}
	
	// Change C
    if(randC == 0)
    {
    	for(int i = 0; i<3; i++)
    	{
    		c[i] = validPatterns1[i];
		}
	}
	else if(randC == 1)
	{
		for(int i = 0; i<3; i++)
    	{
    		c[i] = validPatterns2[i];
		}
	}
    else if(randC == 2)
    {
    	for(int i = 0; i<3; i++)
    	{
    		c[i] = validPatterns3[i];
		}
	}
	
    // Test Cases to make sure the order of the arrays are always:
    // [0, 1, 2] , [1, 2, 0], or [2, 0, 1]
    cout << "A" << endl;
    for(int i = 0; i<3; i++)
    {
    	cout << a[i] << " ";
 	}
 	cout << endl << "B" << endl;
 	for(int i = 0; i<3; i++)
    {
    	cout << b[i] << " ";
 	}
 	cout << endl << "C" << endl;
 	for(int i = 0; i<3; i++)
    {
    	cout << c[i] << " ";
 	}
 	cout << endl;
}

// Function for printing the current states of switches
void printStates(int a[],int b[],int c[])
{
	cout << "Current state of switches: " << endl;
	cout << "A          B          C" << endl;
	string colorA;
	string colorB;
	string colorC;
	
	// Check for array A
	if(a[0] == 0)
	{
		colorA = "off";
	}
	else if(a[0] == 1)
	{
		colorA = "red";
	}	
	else if(a[0] == 2)
	{
		colorA = "green";
	}
	
	// Check for array B
	if(b[0] == 0)
	{
		colorB = "off";
	}
	else if(b[0] == 1)
	{
		colorB = "red";
	}	
	else if(b[0] == 2)
	{
		colorB = "green";
	}
	
	// Check for array C
	if(c[0] == 0)
	{
		colorC = "off";
	}
	else if(c[0] == 1)
	{
		colorC = "red";
	}	
	else if(c[0] == 2)
	{
		colorC = "green";
	}
	
	
	cout << colorA << "       " << colorB << "       " << colorC << endl;
	
}

// function for menu and selection
char menu(){
	char choice;
	
	cout << "a - Switch A" << endl;
	cout << "b - Switch B" << endl;
	cout << "c - Switch C" << endl;
	cout << "q - Quit" << endl << endl;
	
	cout << "Enter Menu Selection: ";
	cin >> choice;
	cout << endl;	
	
	return choice;
}

// function to swap states
void swap(int array[], int size)
{
	// Save the first element
	int temp = array[0];
	for(int i = 0; i < size - 1; i++)
	{
		// Shift elements to the left
		array[i] = array[i+1];
	}
	// assign the saved element to the last position
	array[size-1] = temp;
}
