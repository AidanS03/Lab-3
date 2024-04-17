#include <iostream>
#include <ctime>
#include "Heapsort.h"

using namespace std;

int arr[10] = {6, 3, 8, 0, 4, 1, 2, 5, 9, 7};

int main(){
    float elapsedTime;
    int N = 10, randomNumbers;
    bool valid = false;

    fstream randomfile;

    while(valid != true){
		cout << "How many numbers would you like to sort?\n(Please type the code and press enter)\n\n";
		cout << "Amount | Code\n";
		cout << "-------+--------\n25000  |  0\n75000  |  1\n";
		cout << "120000 |  2\n320000 |  3\n500000 |  4\n";
		cin >> randomNumbers;
		switch(randomNumbers){
            case 10: //test case
				randomfile.open("thousand.txt", fstream :: in);
				N = 1000;
				valid = true; 
				break;
			case 0:
				randomfile.open("TwentyFive.txt", fstream :: in);
				N = 25000;
				valid = true; 
				break;
			case 1:
				randomfile.open("SeventyFive.txt", fstream :: in);
				N = 75000;
				valid = true; 
				break;
			case 2:
				randomfile.open("HundredTwenty.txt", fstream :: in);
				N = 120000;
				valid = true; 
				break;
			case 3:
				randomfile.open("ThreeHundredTwenty.txt", fstream :: in);
				N = 320000;
				valid = true; 
				break;
			case 4:
				randomfile.open("FiveHundred.txt", fstream :: in);
				N = 500000;
				valid = true; 
				break;
			default:
				cout << "\n**Not a valid input**\n" << endl;
				valid = false;
				break;
		}	
	}

    elapsedTime = clock();
	for(int i = N/2 - 1; i >= 0; i--){
    	heapify(arr, N, i);
    }
	heapSort(arr, N);
	elapsedTime = (clock() - elapsedTime)/CLOCKS_PER_SEC;

    for(int i =0; i < N; i++){
        cout << arr[i] << endl;
    }
    cout << elapsedTime << endl;
}