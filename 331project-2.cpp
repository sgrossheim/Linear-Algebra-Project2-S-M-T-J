#include <iostream>
using namespace std;

const string line = "----------------------------------";
const int MAX = 100;
// FUNCTION DECLARATIONS ------------------------

int GetChoice();
void FillMatrixA(int matrixA[][MAX], int& r1, int& c1);
void FillMatrixB(int matrixB[][MAX], int& r2, int& c2);
void PrintMatrixA(int matrixA[][MAX], int& r1,int& c1);
void PrintMatrixB(int matrixB[][MAX], int& r2,int& c2);
void CircleOperation(int matrixA[][MAX], int matrixB[][MAX], int& r1, int& c1, int& r2, int & c2);
void CrossOperation(int matrixA[][MAX], int matrixB[][MAX], int matrixC[][MAX], int& r1, int& c1, int& r2, int & c2);
// DRIVER ------------------
int main(){
	int choice = GetChoice();
	int matrixA[MAX][MAX];
	int matrixB[MAX][MAX];
	int r1,c1,r2,c2;
	
	    while (choice != 0){
        if (choice == 1){
            FillMatrixA(matrixA, r1, c1);
        }
        else if(choice == 2){
            FillMatrixB(matrixB, r2, c2);
        }
        else if(choice == 3){
            PrintMatrixA(matrixA, r1, c1);
		}
		else if(choice == 4){
			PrintMatrixB(matrixB, r2, c2);
		}
		else if(choice == 5){
			CircleOperation(matrixA, matrixB, r1, c1, r2, c2);
		}
		else if(choice == 6){
			CrossOperation(matrixA, matrixB, matrixC, r1, c1, r2, c2);
		}
        choice = GetChoice();
    }
    return 0;
}	





//FUNCTION DEFINITIONS ---------------------

int GetChoice(){
	int result = 0;
    cout << endl << line << endl;
    cout << "Enter the choice you want to complete: " << endl;
    cout << "1: Fill Matrix A" << endl;
    cout << "2: Fill Matrix B" << endl;
    cout << "3: Print Matrix A" << endl;
    cout << "4: Print Matrix B" << endl;
    cout << "5: Compute Circle Operation" << endl;
    cout << "6: Compute Cross Operation" << endl;
    cout << "0: Stop" << endl;

    cin >> result;
    cout << line << endl << endl;
    return result;
}

void FillMatrixA(int matrixA[][MAX], int& r1, int& c1){
	cout << "How many rows in matrix A?" << endl;
	cin >> r1;
	cout << "How many columns in matrix A?" << endl;
	cin >> c1;
	
	cout << "Enter the elements in matrix A by rows:" << endl;
		for (int i =0; i < r1; i++){
			for (int j=0; j < c1; j++){
				cout << "Enter value of position (" << i+1 << ", " << j+1 << ") " << endl;
				cin >> matrixA[i][j];
			}
		}
}

void FillMatrixB(int matrixB[][MAX], int& r2, int& c2){
	cout << "How many rows in matrix B?" << endl;
	cin >> r2;
	cout << "How many columns in matrix B?" << endl;
	cin >> c2;
	
	cout << "Enter the elements in matrix B by rows:" << endl;
		for (int i =0; i < r2; i++){
			for (int j=0; j < c2; j++){
				cout << "Enter value of position (" << i+1 << ", " << j+1 << ") " << endl;
				cin >> matrixB[i][j];
			}
		}
}

void PrintMatrixA(int matrixA[][MAX], int& r1,int& c1){
	cout << "Matrix A" << endl;
	for (int i = 0; i < r1; i++){
		for(int j = 0; j < c1; j++){
			cout << matrixA[i][j] << " ";
		}
		cout << endl;
	}
	
	cout << endl;
}

void PrintMatrixB(int matrixB[][MAX], int& r2,int& c2){
	cout << "Matrix B" << endl;
	for (int i = 0; i < r2; i++){
		for(int j = 0; j < c2; j++){
			cout << matrixB[i][j] << " ";
		}
		cout << endl;
	}

}

void CircleOperation(int matrixA[][MAX], int matrixB[][MAX], int& r1, int& c1, int& r2, int & c2){
	int r, c;
	int matrixC[MAX][MAX];
	cout << "Doing circle operation..." << endl << endl;
	if((r1 == r2) & (c1 == c2)){
		r = r1;
		c = c1;
		matrixC[MAX][MAX];
		for(int i = 0; i < r; i++){
			for(int j = 0; j < c; j++){
				matrixC[i][j] = matrixA[i][j] * matrixB[i][j];
			}
		}
	cout << "Matrix after circle operation:" << endl;
	cout << "New matrix" << endl;
	for (int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
			cout << matrixC[i][j] << " ";
		}
		cout << endl;
	}
	}else {
		cout << "Cannot calculate. Matrices must be the same size. Returning to menu" << endl;		
	} 
}

void CrossOperation(int matrixA[][MAX], int matrixB[][MAX], int matrixC[][MAX], int& r1, int& c1) {
	
	cout << "Doing Cross Operation..." << endl << endl;
    cout << "Result of A ⊕ B:" << endl;
    for (int i = 0; i < r1; ++i) {
        for (int j = 0; j < c1; ++j) {
            for (int k = 0; k < r1; ++k) {
                for (int l = 0; l < c1; ++l) {
                    matrixC[i * r1 + k][j * c1 + l] = matrixA[i][j] * matrixB[k][l];
                }
            }
        }
    }
    
    cout << "Matrix after cross operation:" << endl;
    cout << "New matrix" << endl;
	for (int i = 0; i < r1; i++){
		for(int j = 0; j < c1; j++){
			cout << matrixC[i][j] << " ";
		}
		cout << endl;
	}
}

