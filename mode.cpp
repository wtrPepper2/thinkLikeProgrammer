#include <iostream>
using std::cin;
using std::cout;

// input data
int surveyData[] = { 4,7,7,9,9,9,8,3,3,3,3,10 };

// frequency array of input data from 1-10.
// 0 entry should never have a value besides 0.
int modeStat[11];

struct modeData_t {
	int mode;
	int maxCnt;
}modeData;

// function prototype
void getMode( void );


void getMode()
{
	int buffer;
	

	size_t n_elements = sizeof(surveyData) / sizeof(int);

	// setup modeStat with the frequency of each mode
	for (int cnt = 0; cnt < n_elements; cnt++)
	{
		// get next mode
		buffer = surveyData[cnt];

		// add it to the modeStat entry
		modeStat[buffer] += 1;
	}

	// initialize the max data
	modeData.mode = modeStat[0];
	modeData.maxCnt = 0;

	// determine the maximum value and that mode
	for (int cnt = 1; cnt < 11; cnt++)
	{
		if (modeStat[cnt] > modeData.maxCnt)
		{
			modeData.maxCnt = modeStat[cnt];
			modeData.mode = cnt;
		}
	}
}




int main()
{
	int val;

	getMode();
	cout << "mode = " << modeData.mode << "\n";
	cout << "anc its count = " << modeData.maxCnt << "\n";

	return 0;
}