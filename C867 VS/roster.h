//
//  roster.h
//  C867
//
//  Created by Jon on 12/14/24.
//
#pragma once
#include "student.h"

class Roster
{
private:
	int lastIndex = -1;
	const static int numStudents = 5;
	Student* classRosterArray[numStudents];

public:
	void parse(string row);
	void add(string studentID,
		string firstName,
		string lastName,
		string emailAddress,
		int age,
		int daysInCourse1,
		int daysInCourse2,
		int daysInCourse3,
		DegreeProgram degreeProgram);
	void printAll();
	void printByDegreeProgram(DegreeProgram degreeProgram);
	void printInvalidEmails();
	void printAverageDaysInCourse();
	void remove(string studentID);
	~Roster();
};