#include <iostream>
using namespace std;

void set5(int[], int);
void set7(int[], int);

// notice how these two functions 
// effect the array x differently

int main() {
    int i = 0;
	int x[] = { 5,6,7 };

	cout << "original" << endl;
    for (i = 0; i< 3; i++)
		cout << x[i] << " ";
	cout << endl;

	set5(x,3);
	cout << "after set5 " << endl;
    for (i = 0; i< 3; i++)
		cout << x[i] << " ";
	cout << endl;

	set7(x,3);
	cout << "after set7 " << endl;
    for (i = 0; i< 3; i++)
		cout << x[i] << " ";
	cout << endl;


}

void set5(int vals[], int size){
    for (int j=0; j<size; j++)
		vals[j] = 5;


}
void set7(int vals[], int size){
	int temp[ ] = {7,7,7};
	vals = temp;
}