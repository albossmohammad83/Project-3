//this program reads in one int value and keeps a tally of each digit (0-9) that
// occurs in the value   (value must be fewer than 15 digits)  

#include <iostream>
using namespace std;

void getNumber(char chs[], int size, int& numfilled);
void countDigits(char chs[], int sizeChArr, int digCount[], int sizeDigArr);
void printDigCount(int digCount[], int size);

int main () {
   const int SIZE = 15; 
   int digits[10] = { };    //initialize 'counters' to 0
   char value[SIZE];        //value which is input, in char form
   int howmany;

   getNumber(value,SIZE,howmany);    //gets number from user, stores digits in array value, howmany
                                     //is updated to reflect the number of digits in the value
  
   countDigits(value,howmany,digits,10);

   printDigCount(digits,10);

}

void getNumber(char chs[], int size, int& numfilled) {
     char current;
     int index = 0;
     cout << "Please enter an integer, "<< size << " chars or less, followed by <ENTER> " ;

	 cin.get(current);

	 while (current != '\n') {
        chs[index] = current;
		index++;
	    cin.get(current);
	 }

	 numfilled = index;

}

void countDigits(char chs[], int sizeChArr, int digCount[], int sizeDigArr){
    int dig;
	for (int i = 0; i < sizeChArr ; i++){
            dig = chs[i] - '0';
            digCount[dig]++;
	}
}

void printDigCount(int digCount[], int size){
    for ( int i = 0; i < size; i++)
		cout << i << ": " << digCount[i] << endl;


}
