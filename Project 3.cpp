/*Mohammad Abdelrahman
CIS 278
Project 3

*/

#include <iostream>
#include <sstream>
#include <cstring>
#include <cctype>
using namespace std;

bool isFull(int seats[], int size);
bool isEmpty(int seats[], int size);
int seatsLeft(int seats[], int size);
bool validSeatNum(int seatNo, int size);
bool seatVacant(int seatNo, int seats[]);
bool reserveSeat(int seatNo, int seats[], int size);
bool cancelReserve(int seatsNo, int seats[], int size);
int furthestFront(int seats[], int size);
int furthestRear(int seats[], int size);
bool getSeatNo(int& value);
void trainTripData(int seats[], int size);

int main() {

	const int MAXSEATS = 15;
	int trainTrip[MAXSEATS];
	int seatNo, optionNo;

	for (int i = 0; i < MAXSEATS; i++)
		trainTrip[i] = 0;

	cout << "Enter a number of the following: \n" << "1.Check if train is full \n" << "2.Check if train is empty \n" 
		 << "3.Reserve a particular seat, if available \n" << "4.Reserve a seat furthest to the front \n"
		 << "5.Reserve a seat furthest to the rear \n" << "6.Cancel a particular seat reservation \n" 
		 << "7.Print out all train trip data \n" << "8.Exit \n" << "Note (True = 1, False = 0)" << endl;

	do{
		cin >> optionNo;
		switch (optionNo)
		{
		case 1:
			cout << isFull(trainTrip, MAXSEATS) << endl;
			break;
		case 2:
			cout << isEmpty(trainTrip, MAXSEATS) << endl;
			break;
		case 3:
			do {
				cout << "Enter seat number to reserve: ";
				cin >> seatNo;
			} while (!getSeatNo(seatNo));
			reserveSeat(seatNo, trainTrip, MAXSEATS);
			break;
		case 4:
			if (furthestFront(trainTrip, MAXSEATS) == -1)
				cout << "Train is full no reservation was made!" << endl;
			else
				reserveSeat(furthestFront(trainTrip, MAXSEATS), trainTrip, MAXSEATS);
			break;
		case 5:
			if (furthestRear(trainTrip, MAXSEATS) == -1)
				cout << "Train is full no reservation was made!" << endl;
			else
				reserveSeat(furthestRear(trainTrip, MAXSEATS), trainTrip, MAXSEATS);
			break;
		case 6:
			do {
				cout << "Enter seat number to cancel: ";
				cin >> seatNo;
			} while (!getSeatNo(seatNo));
			cancelReserve(seatNo, trainTrip, MAXSEATS);
			break;
		case 7:
			trainTripData(trainTrip, MAXSEATS);
			break;
		}
	} while (optionNo != 8);
	
	if (optionNo == 8)
		return 0;
}

bool isFull(int seats[], int size){
	int full = 0;
	for (int i = 0; i < size; i++){
		if (seats[i] == 1)
			full++;
		else
			continue;
	}
	if (full == size)
		return true;
	else
		return false;
}

bool isEmpty(int seats[], int size){
	int empty = 0;
	for (int i = 0; i < size; i++){
		if (seats[i] == 0)
			empty++;
		else
			continue;
	}
	if (empty == size)
		return true;
	else
		return false;
}
int seatsLeft(int seats[], int size){
	int avalSeats = 0;
	for (int i = 0; i < size; i++){
		if (seats[i] == 0)
			avalSeats++;
	}
	return avalSeats;
}

bool validSeatNum(int seatNo, int size){
	return (seatNo < size && seatNo >= 0);
}

bool seatVacant(int seatNo, int seats[]){
	if ( validSeatNum(seatNo, 15) )
		return (seats[seatNo] == 0);
	else
		return false;

}

bool reserveSeat(int seatNo, int seats[], int size){
	if (!isFull(seats, size) && validSeatNum(seatNo, size) && seats[seatNo] == 0){
		seats[seatNo] = 1;
		cout << "Reserved!" << endl;
		return true;
	}
	else{
		cout << "Unavailable" << endl;
		return false;
	}
}

bool cancelReserve(int seatsNo, int seats[], int size){
	if (!isEmpty(seats, size) && validSeatNum(seatsNo, size) && seats[seatsNo] == 1){
		seats[seatsNo] = 0;
		cout << "Canceled!" << endl;
		return true;
	}
	else{
		cout << "Unavailable" << endl;
		return false;
	}
}

int furthestFront(int seats[], int size){
	if (!isFull(seats, size)){
		for (int i = 0; i < size; i++){
			if (seats[i] == 0)
				return i;
			else
				continue;
		}
	}
	else
		return -1;
}

int furthestRear(int seats[], int size){
	if (!isFull(seats, size)){
		for (int i = size - 1; i >= 0; i--){
			if (seats[i] == 0)
				return i;
			else
				continue;
		}
	}
	else
		return -1;
}

bool getSeatNo(int& value){
	ostringstream convert;
	convert << value;
	string seatNumber = convert.str();
	for (int i = 0; i < seatNumber.length(); i++){
		if (seatNumber.at(i) - 0 == seatNumber.at(i))
		{
		}
		else
			return false;
	}
	value = atoi(seatNumber.c_str());
	return true;
}

void trainTripData(int seats[], int size){
	int avalSeats = 0;
	for (int i = 0; i < size; i++){
		if (seats[i] == 0){
			avalSeats++;
			cout << "Seat #" << i << " is Empty" << endl;
		}
		else
			cout << "Seat #" << i << " is Reserved" << endl;
	}
	cout << "Number of empty seats: " << avalSeats << endl;
}