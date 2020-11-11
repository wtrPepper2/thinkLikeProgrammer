
// covers half a square exercise from "Think Like a Programmer", page 26.


#include <iostream>
using std::cin;
using std::cout;


void halfAsquare(void);
void sideWayPyramid(void);


// routine prints #'s into a pattern.  not 5x5 but diagonally cut in half
// #####
// ####
// ###
// ##
// #
//
// outputting using only '#' and'/n'
void halfAsquare()
{
	std::size_t  x, y, numlbs;

	// outer loop sets up number of lbs per interation and prints 5 lines
	for (x = 0, numlbs = 5; x < 5; x++, numlbs--)
	{
		// inner loop varies printing the #'s per line
		for (y = 0; y < numlbs; y++)
		{
			cout << '#';
		}
		cout << '\n';
	}
}


// display the following using only #'s and \n for output
//
// #
// ##
// ###
// ####
// ###
// ##
// #
void sideWayPyramid(void)
{
	size_t x;
	size_t numlbs[] = {1, 2, 3, 4, 3, 2, 1};

	// use a range-based loop
	for( size_t numlb: numlbs )
	{
		for (x = 0; x < numlb; x++)
		{
			cout << '#';
		}
		cout << '\n';
	}
}





int main()
{

//	halfAsquare();
	sideWayPyramid();

	return 0;
}