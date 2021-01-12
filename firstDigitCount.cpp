//this program reads in one int value and keeps a tally of each digit (0-9) that
// occurs in the value  (leading 0's are NOT processed)

#include <iostream>
using namespace std;

int main () {
    
   int digits[10] = { };
   int intVal;
   int adigit;

   cout << "enter an integer value " ;
   cin >> intVal;
   intVal = abs(intVal);

   while (intVal > 0) {
       adigit = intVal % 10;
	   digits[adigit] = digits[adigit] + 1;
       intVal = intVal / 10;
   }

   for (int i = 0; i< 10; i++)
	   cout<< i << " occurs " << digits[i] << " times " << endl;


}