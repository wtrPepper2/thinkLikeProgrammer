#pragma once

// classRoster is exercise from Think Like a Programmer book, page 118.
//
// Maintain a class roster including:
//  students name
//  ID
// final grade, 0-100
//
// the program should allow for additions and removals of students
// display a particular student, via ID, with grade displayed as
// number and letter grade (see table below for number to letter grade),
// and display the average score for the class.
//
// here is the table for grade number to letter:
//      Number			Letter
//     97-100            A
//     90-92             A-
//     87-89             B+
//     83-86             B
//     80-82             B-
//     77-79             C+
//     73-76             C
//     70-72             C-
//     67-69             D+
//     60-66             D
//     0-59              F

#include <string>
#include <iostream>
using std::string;
using std::cin;
using std::cout;


// this is the student record class
// the first record in the lined list has nullptr for nextStudentRecord.
class studentRecord
{
public:

	studentRecord(string nameIn, string idIn, char gradeIn) :nextStudentRecord{nullptr} {
		name = nameIn;
		id = idIn;
		grade = gradeIn;
	}

	// private data
	string name;
	string id;
	unsigned int grade;

	class studentRecord * nextStudentRecord;
};


// this is the teacher class
class teacher
{
	public:
		teacher() : numRecords{ 0 }
		{};

		studentRecord * findID(string id);

		// pointer to the head node, first node in linked list.
		studentRecord * headNode;

		void addRecord();
		void deleteRecord();
		void average();


	private:
		char numRecords;

};

