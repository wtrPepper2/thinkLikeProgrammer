#include <iostream>
#include <string>

using std::cin;
using std::cout;


void luhnCheck(void);




// perform a luhn type checksum on and long input
// the luhncheck takes a sum of the input digits some doubled, and
// that sum should be an even divisor of 10
// for instance: 1762483   (the checksum digit is 3)
// 3+  (8*2==>) 1+6 +4 + (2*2==>) 4 +6 + (7*2==>) 1+4 +1 =  30 
// which is a divisor of 10 and is correct.
void luhnCheck()
{
	unsigned long inputVal;
	std::string valStr;

	cout << "Enter input value: ";
	cin >> inputVal;


	std::string inputStr = std::to_string(inputVal);
	cout << "Value = " << inputStr <<"\n";

	size_t n_elements = inputStr.length();
	size_t digits = n_elements;
	size_t iterator = 0;
	int sum = 0;
	int buffer;

	// knowing the length we can determine where the digit doublers are
	if ((n_elements % 2) == 0)
	{
		// even number of digits
		while( iterator != digits )
		{
			valStr = inputStr[iterator];
			buffer = std::stoi(valStr);

			// doubler routine are even values of index, note [0] is MSB
			if ((iterator % 2) == 0)
			{
				if (buffer >= 5)
					sum += 1 + (buffer * 2) % 10;
				else
					sum += buffer * 2;
			}
			else
				sum += buffer;
			
			++iterator;
		}
	}
	else
	{
		// odd number of digits
		while (iterator != digits)
		{
			valStr = inputStr[iterator];
			buffer = std::stoi(valStr);
			
			// just add even values of index, note [0] is MSB
			if ((iterator % 2) == 0)
				sum += buffer;
			else
			{
				// doubler routine are odd values of index
				if (buffer >= 5)
					sum += 1 + (buffer * 2) % 10;
				else
					sum += buffer * 2;
			}
			++iterator;
		}
	}

	// test if number has the Luhn checksum arleady in
	if ((sum % 10) == 0)
		cout << "Success, number includes Luhn Checksum";
	else
		cout << "Sum =" << sum;
}



int main()
{
	luhnCheck();
	return 0;
}