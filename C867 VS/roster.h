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
	Student* studentRosterArray[numStudents];

public:
	void parse(string row);
	void add(string sID,
		string sFirstName,
		string sLastName,
		string sEmailAddress,
		int sAge,
		int sDays1,
		int sDays2,
		int sDays3,
		DegreeProgram dp);
	void printAll();
	void printByDegreeProgram(DegreeProgram dp);
	void printInvalidIDs();
	void printAverageDays();
	void removeStudentByID(string studentID);
	~Roster();
};