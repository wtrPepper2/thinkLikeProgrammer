// there are three states that are transitioned.  Each state
// perform a specific function on the input data, returning data.
//
//  U = uppercase : State 0
//  L = lowercase : State 1
//  P = punctuation : State 2
//  Start in U, then when input is 0, transition to L, then when 
//  input is 0 transition to P, then when input is 0, transition to U
//  U==>L==>P==>U==>L==>P....
// 
//  See the state function for a description of what it is supposed to do.

#include <iostream>


using std::cin;
using std::cout;

char ulState( int );
char lState(int);
char pState(int);
void runStateMachine(int);
void displayData(void);



// define the states of the state machine
enum class CurrentState {
	ustate,
	lstate,
	pstate
};


// data to display after an input
struct displayData
{
	int input;
	char output;
	CurrentState state;
};

struct displayData displayCurrentData;


// lookup table for puncuation
char pStateTable[] = { '0', '|', '?', '.', ',', ' ', ';', '"', ':' };


// Uppercase States
// Function: takes modulo 27 and adds 64 to input data
char uState( int inputData)
{
	char val{};
	val = inputData % 27;

	// if it is a non-zero then make it uppercase
	if (val != 0)
		val += 64;
	else
		val = 48;   // make val equal number 0

	return val;
}


// Lowercase States
// Function: takes modulo 27 and adds 96 to input data
char lState(int inputData)
{
	char val{};
	val = inputData % 27;

	// if it is a non-zero then make it lowercase
	if (val != 0)
		val += 96;
	else
		val = 48;   // make val equal number 0

	return val;
}




// Puncuation State
// function: takes input performs a modulo 9 and returns value based on lookup 
// table, here is the table:
//
//		Input	Output
//		1		|
//		2		?
//		3		.
//		4		'
//		5		[space]
//		6		;
//		7		"
//		8		:
//
char pState(int inputData)
{
	int arrayIndex{};
	
	arrayIndex = inputData % 9;
	return pStateTable[arrayIndex];
}




// state machine for this system
void runStateMachine( int newData)
{

	switch (displayCurrentData.state)
	{
		case CurrentState::ustate: {
			displayCurrentData.input = newData;
			displayCurrentData.output = uState(newData);

			if (displayCurrentData.output == '0')
				displayCurrentData.state = CurrentState::lstate;
			}
			break;

		case CurrentState::lstate: {
			displayCurrentData.input = newData;
			displayCurrentData.output = lState(newData);

			if (displayCurrentData.output == '0')
				displayCurrentData.state = CurrentState::pstate;
			}
			break;

		case CurrentState::pstate: {
			displayCurrentData.input = newData;
			displayCurrentData.output = pState(newData);

			if (displayCurrentData.output == '0')
				displayCurrentData.state = CurrentState::ustate;
			}
			break;

		default: {
			cout << "Error, unkown type";
			}
	};
}


// routine to display result of coded process on input number
void displayData()
{
	char currentState{};

	currentState = (char)displayCurrentData.state + 48;

	cout << "Input value= " << displayCurrentData.input << "\n";
	cout << "Code output= " << displayCurrentData.output << "\n";
	cout << "Current State= " << currentState << "\n\n";
}


// main routine.
int main()
{
	int newData{};
	displayCurrentData.state = CurrentState::ustate;
	
	for (;;) {
		cout << "Enter in new data to be decoded\n";
		cin >> newData;

		runStateMachine( newData );
		displayData();
	} 
	
	return 0;
}




