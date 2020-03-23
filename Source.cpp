#include <iostream>
#include <numeric>
#include <algorithm>
#include <thread>
#include <vector>
#include <future>
#include <string>

using namespace std;

// Complete the sherlockAndMinimax function below.
int sherlockAndMinimax(vector<int> arr, int p, int q) {
	int smallestM, localSmallestDifference = abs(arr[0] - p), currentDifference, globalLargestDifference = 0;
	int tempDifference;
	
	//For each M in the range [p, q]...
	for (int m = p; m <= q; m++){
		cout << "M: " << m << "\tnums: \t";
		//Find the smallest value of abs(M - arr[i])
		for (size_t i = 0; i < arr.size(); i++){
			currentDifference = abs(arr[i] - m);
			cout << currentDifference << "\t";
			if (currentDifference < localSmallestDifference) 
				localSmallestDifference = currentDifference;
		}

		cout << "\nSmallest difference: " << localSmallestDifference << "\n\n";

		if (localSmallestDifference > globalLargestDifference) {
			globalLargestDifference = localSmallestDifference;
			smallestM = m;
		}

		localSmallestDifference = abs(arr[0] - p);
		
	}
	
	return smallestM;
}

/*
 * Complete the timeConversion function below.
 */
string timeConversion(string s) {
	string timePeriod = s.substr(s.size() - 2);
	int time = stoi(s.substr(0, 2));

	if (timePeriod == "AM") {
		if (time == 12)
			return s.replace(s.begin(), s.begin() + 2, "00").erase(s.size() - 2);
		else
			return s.erase(s.size() - 2);
	}else {
		if (time == 12)
			return s.erase(s.size() - 2);
		else
			return s.replace(s.begin(), s.begin() + 2, to_string(time + 12)).erase(s.size() - 2);
	}
}

int birthdayCakeCandles(vector<int> ar) {
	return count(ar.begin(), ar.end(), *max_element(ar.begin(), ar.end()));
}

void miniMaxSum(vector<int> arr) {
	sort(arr.begin(), arr.end());
	int least = 0, greatest = 0;
	for (size_t i = 0, j = arr.size() - 1; i < arr.size() - 1; i++, j--)
	{
		least += arr[i];
		greatest += arr[j];
	}
	auto sumLeast = async(launch::async, [&]() { return accumulate(arr.begin(), arr.end() - 1, 0); });
	int sumGreatest = accumulate(arr.begin() + 1, arr.end(), 0);

	cout << sumLeast.get() << " " << sumGreatest << endl;
	cout << least << " " << greatest << endl;

}

int diagonalDifference(vector<vector<int>> arr) {
	int sumLeftDiag = 0, sumRightDiag = 0;

	for (int i = 0, j = 0; i < arr.size(); i++, j++)
		sumLeftDiag += (arr[i][j]);
	for (int i = 0, j = arr[0].size() - 1; i < arr.size(); i++, j--)
		sumRightDiag += (arr[i][j]);

	return abs(sumRightDiag - sumLeftDiag);
}

void printStairCase(int numLevels) {
	//We will need to keep track of the number of spaces, and the number of characters on each level.
	int numSpaces = numLevels - 1, numChars = 1;

	//for each level in the stair case...
	for (int i = 0; i < numLevels; i++){
		
		//indent in the amount of times specified by the value of "numSpaces"
		for (size_t j = 0; j < numSpaces; j++)
			cout << " ";

		//Finally, print the number of characters that goes on the current level
		for (size_t i = 0; i < numChars; i++)		
			cout << "%";
		
		//each subsequent line will have one less space, and one more character than the previous level
		numSpaces--;
		numChars++;
		cout << "\n";
		this_thread::sleep_for(0.1s);
	}
	
}

int main() {
	vector<int> arr{ 5, 6, 2 ,512, 3, 12, 512, 34, 0, 20, 512 };
	vector<vector<int>> nums{ 
		{ 5, 6, 1, 3 },
		{ 6, 2, 1, 0 },
		{ 8, 4, 2, 9 },
		{ 3, 5, 1, 7 }
	};

	//cout << "difference between diagonals: " << diagonalDifference(nums) << "\n";
	//printStairCase(6);
	//miniMaxSum(arr);
	//cout << "Niece can blow out: " << birthdayCakeCandles(arr) << " candles\n\n";
	//cout << "12:59:59PM in military hours: " << timeConversion("12:59:59PM") << endl;
	cout << sherlockAndMinimax({ 1, 5, 8, 14 }, 2, 12) << endl;
	return 0;
}
 