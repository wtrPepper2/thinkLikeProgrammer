#include <iostream>
#include <string>
using std::cin;
using std::cout;

// This project performs the work needed from Think Like a Programmer, page 91:
// Variable LEngth String Manipulation
//
// Develop an app that has three functions:
// 1. append       
//    append a charactor at the end of a string
// 2. concatonate
//    add the second string to the end of the first string
// 3. characterAt
//    display the character at a position of a string
//    assume this is the most frequenct request.

enum class functionType
{
	blank,
	characterAt,
	append,
	concatonate
};

void characterAt( void );
void append( void );
void concatonate(void);


void characterAt()
{
	std::string inputString;
	unsigned int charIndex;
	


	cout << "Enter the string: ";

	// this command gets a sentence, not just the first word.
//	std::getline(cin, inputString);
	cin >> inputString;


	cout << "\n" << "Which char to see: ";
	cin >> charIndex;

	unsigned int stringSize = (unsigned int)inputString.size();

	char * heapPtr = new char[stringSize];
	char * stringStart = heapPtr;


	// copy the string into the heap space
	for (unsigned int x = 0; x <= stringSize; x++)
	{
		*heapPtr = inputString[x];
		heapPtr++;
	}

	if (charIndex <= stringSize)
	{
		// now get the cahr at a specific index
		cout << "the char at index " << charIndex << " is " << *(stringStart + charIndex) << "\n";
	}
	else
	{
		cout << "index requested is out of bounds\n";
	}
}


// takes a string, and char, and appends the character after the string.
void append()
{
	std::string inputString, outputString;
	char * stringStart;
	char charAppend;

	cout << "Enter the string: ";

	// this command gets a sentence, not just the first word.
	//	std::getline(cin, inputString);
	cin >> inputString;

	cout << "\n" << "Enter char to append:  ";
	cin >> charAppend;

	unsigned int stringSize = (unsigned int)inputString.size();
	
	stringSize += 1;

	char * heapPtr = new char[stringSize];
	stringStart = heapPtr;

	// copy the string into the heap space
	for (unsigned int x = 0; x < stringSize-1; x++)
	{
		*heapPtr = inputString[x];
		heapPtr++;
	}

	// now append the char to the end of the string
	*heapPtr = charAppend;
	heapPtr++;

	// we need to append a null to define the end of the string
	*heapPtr = '\0';
	
	// now the copy the string from the heap to the output variable
	outputString = std::string(stringStart, stringSize);
	cout << "Appended string: " << outputString << "\n";
}


// takes two strings, and appends the second string after the first
void concatonate()
{

	std::string inputString1, inputString2, outputString;
	char * stringStart;
	

	cout << "Enter first string: ";

	// this command gets a sentence, not just the first word.
	//	std::getline(cin, inputString);
	cin >> inputString1;

	cout << "\n" << "Enter second string:  ";
	cin >> inputString2;

	unsigned int stringSize1 = (unsigned int)inputString1.size();
	unsigned int stringSize2 = (unsigned int)inputString2.size();
	unsigned int stringSize = stringSize1 + stringSize2 + 1;


	char * heapPtr = new char[stringSize];
	stringStart = heapPtr;
	
	// copy the string into the heap space
	for (unsigned int x = 0; x < stringSize1; x++, heapPtr++)
	{
		*heapPtr = inputString1[x];
	//	heapPtr++;
	}


	for (unsigned int x = 0; x < stringSize2; x++, heapPtr++)
	{
		*heapPtr = inputString2[x];
	//	heapPtr++;
	}

	// we need to append a null to define the end of the string
	*heapPtr = '\0';

	// now the copy the string from the heap to the output variable
	outputString = std::string(stringStart, stringSize);
	cout << "Concatinated string: " << outputString << "\n";
}


int main()
{
	int inputReq;
	functionType function;

	// determine  which of the three we want to do
	cout << "Choose a function" << "\n";
	cout << "1=characterAt, 2=append, 3=concatonate: ";
	cin >> inputReq;
	function = (functionType)inputReq;

	switch (function)
		{
		case functionType::characterAt:
			characterAt();
			break;

		case functionType::append:
			append();
			break;

		case functionType::concatonate:
			concatonate();
			break;

		default:
			// do nothing here yet.
			break;
		};

	return 0;
}