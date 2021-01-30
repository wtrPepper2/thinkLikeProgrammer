// classRoster.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "classRoster.h"





// adds record to teacher class
void teacher::addRecord()
{
	string studentName;
	string studentId;
	unsigned int studentGrade;
	
	studentRecord * previousHeadNode;
	

	cout << " Enter Name: ";
	cin >> studentName;
	cout << studentName << "\n";
	
	
	cout << " Enter ID: ";
	cin >> studentId;
	cout << studentId << "\n";

	cout << " Enter Grade: ";
	cin >> studentGrade;
	cout << studentGrade << "\n";



	if ( !numRecords)
	{
		// create the first record, and store the pointer to it as the head node pointer.
		headNode = new studentRecord( studentName, studentId, studentGrade );

		numRecords++;
	}
	else
	{
		// store the next node down the list, this was the head before the next node.
		previousHeadNode = headNode;

		// create the next record, and store the pointer to it as the head node pointer.
		headNode = new studentRecord(studentName, studentId, studentGrade);
		headNode->nextStudentRecord = previousHeadNode;

		numRecords++;
	}
}






void teacher::deleteRecord()
{
	string deleteRecord;
	string nodeId;
	studentRecord * deleteNode;


	cout << "Enter Student ID for record to delete: ";
	cin >> deleteRecord;

	// point to first record in linked list
	studentRecord * student = headNode;


	// find record in linked list
	for (; student != nullptr ; )
	{
		nodeId = student->nextStudentRecord->id;

		if (student->nextStudentRecord->id == deleteRecord)
		{
			break;
		}

		student = student->nextStudentRecord;
	}

	// did we find the record?
	if (student == nullptr)
	{
		// never found record
		cout << "Never found record";
	}
	else if (student->nextStudentRecord->id == deleteRecord)
	{
		// setup next node pointer, and delete requestedrecord
		deleteNode = student->nextStudentRecord;
		student->nextStudentRecord = student->nextStudentRecord->nextStudentRecord;
		delete deleteNode;
	}
}


void teacher::average()
{
	unsigned int sum{ 0 }, numStudents{ 0 };
	float average{ 0.0 };

	// point to first record in linked list
	studentRecord * student = headNode;


	// get sum of all students, from linked list nodes
	for (; student != nullptr; numStudents++)
	{
		sum += student->grade;
		student = student->nextStudentRecord;
	}

	average = sum / numStudents;

	cout << "Grade Total = " << sum << " Number of students = " << numStudents << "\n";
	cout << "Average = " << average << "\n";
}





int main()
{
	char input;

	// create teacher object
	teacher teachClass;



	do {
		cout << "Enter (a)dd, (d)elete, a(v)erage or e(x)it: ";
		cin >> input;

		switch( input ) 
		{
			case 'a':
				teachClass.addRecord();
				break;

			case 'd':
				teachClass.deleteRecord();
				break;

			case 'v':
				teachClass.average();

			case 'x':
				// do nothing for now
				break;

			default:
				break;
		}



	} while (input != 'x');

	cout << "Ending function";

    return 0;
}

