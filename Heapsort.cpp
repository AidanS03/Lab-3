#include <iostream>
#include <ctime>
#include "Heapsort.h"

using namespace std;

int arr[10] = {6, 3, 8, 0, 4, 1, 2, 5, 9, 7};

int main(){
    float elapsedTime;
    int N = 10, randomNumbers;
    bool valid = false;

    fstream randomFile, orderedFile;

    while(valid != true){
		cout << "How many numbers would you like to sort?\n(Please type the code and press enter)\n\n";
		cout << "Amount | Code\n";
		cout << "-------+--------\n25000  |  0\n75000  |  1\n";
		cout << "120000 |  2\n320000 |  3\n500000 |  4\n";
		cin >> randomNumbers;
		switch(randomNumbers){
            case 10: //test case
				randomFile.open("thousand.txt", fstream :: in);
				N = 1000;
				valid = true; 
				break;
			case 0:
				randomFile.open("TwentyFive.txt", fstream :: in);
				N = 25000;
				valid = true; 
				break;
			case 1:
				randomFile.open("SeventyFive.txt", fstream :: in);
				N = 75000;
				valid = true; 
				break;
			case 2:
				randomFile.open("HundredTwenty.txt", fstream :: in);
				N = 120000;
				valid = true; 
				break;
			case 3:
				randomFile.open("ThreeHundredTwenty.txt", fstream :: in);
				N = 320000;
				valid = true; 
				break;
			case 4:
				randomFile.open("FiveHundred.txt", fstream :: in);
				N = 500000;
				valid = true; 
				break;
			default:
				cout << "\n**Not a valid input**\n" << endl;
				valid = false;
				break;
		}	
	}

	int ordered[N];//define size of arrays
	int random[N];
	if(randomFile.is_open()){//only do it if file is open, which it should be
		int a, i = 0;
		while(randomFile >> a){ //go line by line and insert numbers from file into array
			ordered[i] = a;
			i++;
		}
	}
	
	orderedFile.open("Sorted.txt", fstream :: out);
	float times[6];

	for(int i = 0; i < 6; i++){
    	elapsedTime = clock();
		for(int j = N/2 - 1; j >= 0; j--){
    		heapify(ordered, N, j);
    	}
		heapSort(ordered, N);
		elapsedTime = (clock() - elapsedTime)/CLOCKS_PER_SEC;
		times[i] = elapsedTime;
		if(randomFile.is_open()){//only do it if file is open, which it should be
		int a, i = 0;
		while(randomFile >> a){ //go line by line and insert numbers from file into array
			ordered[i] = a;
			i++;
		}
	}
	}
	float average = (times[1] + times[2] + times[3] + times[4] + times[5])/5;
	for(int i = 0; i < N; i++){
		orderedFile << ordered[i] << "\n";
	}
	randomFile.close();
	orderedFile.close();

	cout << times[0] << endl;
	cout << times[1] << endl;
	cout << times[2] << endl;
	cout << times[3] << endl;
	cout << times[4] << endl;
    cout << average << endl;
}