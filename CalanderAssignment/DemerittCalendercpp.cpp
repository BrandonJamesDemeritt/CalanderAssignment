#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {

	//declare variables
	bool leapYear = false;
	bool exit = false;
	char userExit = 'y';
	unsigned int numMonth = 1;
	unsigned int year = 0;
	unsigned int dayCount;
	unsigned int startPosition = 0;
	unsigned int width;
	string startDay;
	string month;

	//loop to generate calenders until user exits
	while (!exit) {

		//ask for year and read in 4 digit int
		cout << "Please enter a year (4 digits): ";
		cin >> year;

		//ask for month using numbers 1-12 and read in int.
		cout << endl << "Please enter a month using numbers (1 - 12): ";
		cin >> numMonth;

		//ask for first three letters of starting day, read in string
		cout << endl << "Please enter the starting day of the month using the first three letters (Mon, Tue, etc.): ";
		cin >> startDay;

		//find out if leap year
		leapYear = false;
		if ((year % 4 == 0) && (year % 100 != 0)) {
			leapYear = true;
		}
		if (year % 400 == 0) {
			leapYear = true;
		}

		//assign month string based on previous user input
		switch (numMonth) {
			case 1:
				month = "January";
				break;
			case 2:
				month = "February";
				break;
			case 3:
				month = "March";
				break;
			case 4:
				month = "April";
				break;
			case 5:
				month = "May";
				break;
			case 6:
				month = "June";
				break;
			case 7:
				month = "July";
				break;
			case 8:
				month = "August";
				break;
			case 9:
				month = "September";
				break;
			case 10:
				month = "October";
				break;
			case 11:
				month = "November";
				break;
			case 12:
				month = "December";
				break;
		}

		//set startDay user input string to all lowercase
		for (int i = 0; i < startDay.size(); ++i) {
			startDay.at(i) = tolower(startDay.at(i));
		}

		//use startDay to determine value of startPosition
		if (startDay == "sun") {
			startPosition = 0;
		}
		else if (startDay == "mon") {
			startPosition = 1;
		}
		else if (startDay == "tue") {
			startPosition = 2;
		}
		else if (startDay == "wed") {
			startPosition = 3;
		}
		else if (startDay == "thu") {
			startPosition = 4;
		}
		else if (startDay == "fri") {
			startPosition = 5;
		}
		else if (startDay == "sat") {
			startPosition = 6;
		}		
		
		//find dayCount depending on month input
		if ((numMonth == 1) || (numMonth == 3) || (numMonth == 5) || (numMonth == 7) || (numMonth == 8) || (numMonth == 10) || (numMonth == 12)) {
			dayCount = 31;
		}
		else if ((numMonth == 4) || (numMonth == 6) || (numMonth == 9) || (numMonth == 11)) {
			dayCount = 30;
		}
		else if (numMonth == 2) {
			if (leapYear == true) {
				dayCount = 29;
			}
			else dayCount = 28;
		}

		//output Month and year title bar
		
		//find width variable to determine amount of leading spaces needed to center align month name and year
		width = (27 - (month.length() + 5)) / 2;

		//output leading spaces
		cout << endl;
		for (int i = 0; i < width; ++i) {
			cout << " ";
		}

		//output month and year
		cout << month << " " << year << endl;

		//output Day column headers
		cout << endl << setw(3) << "Sun " << "Mon " << "Tue " << "Wed " << "Thu " << "Fri " << "Sat" << endl;

		//use start position to output any needed leading spaces
		for (int i = startPosition; i > 0; --i) {
			cout << "    ";
		}

		//output days
		int j;
		for (j = 1; j <= dayCount;) {
			//check if at calendar end and break loop if so
			if (j > dayCount) {
				break;
			}
			//check if first week to adjust for not having a full seven days in that week to print
			if (j == 1) {
				for (int i = startPosition; i < 7; i++) {
					cout << setw(3) << right << j;
					//check if end of week to not output space
					if (i != 6) {
						cout << " ";
					}
					j++;
				}
				cout << endl;
			}
			//if not first week output days
			else {
				for (int i = 0; i < 7; i++) {
					cout << setw(3) << right << j;
					j++;
					//check if end of week to not output space
					if (i != 6) {
						cout << " ";
					}
					//check if at month end and break loop if so
					if (j > dayCount) {
						break;
					}
				}
				cout << endl;
			}
		}

		//ask if want to generate a new calender or exit
		cout << endl << "Would you like to view another month? (y/n) (n to exit): ";
		cin >> userExit;
		if (userExit == 'n') {
			exit = true;
		}
	}

	return 0;
}