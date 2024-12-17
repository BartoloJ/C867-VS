//
//  roster.cpp
//  C867
//
//  Created by Jon on 12/14/24.
//
#include "roster.h"

void Roster::parse(string studentdata)
{

	int rhs = studentdata.find(",");
	string sID = studentdata.substr(0, rhs);

	int lhs = rhs + 1;
	rhs = studentdata.find(",", lhs);
	string fn = studentdata.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
    rhs = studentdata.find(",", lhs);
	string ln = studentdata.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = studentdata.find(",", lhs);
	string ea = studentdata.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = studentdata.find(",", lhs);
	int age = stod(studentdata.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = studentdata.find(",", lhs);
	int d1 = stod(studentdata.substr(lhs, rhs - lhs));
	lhs = rhs + 1;
	rhs = studentdata.find(",", lhs);
	int d2 = stod(studentdata.substr(lhs, rhs - lhs));
	lhs = rhs + 1;
	rhs = studentdata.find(",", lhs);
	int d3 = stod(studentdata.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	string degreeStr = studentdata.substr(lhs);

	DegreeProgram dp;
	if (degreeStr == "NETWORK") dp = NETWORK;
	else if (degreeStr == "SOFTWARE") dp = SOFTWARE;
	else if (degreeStr == "SECURITY") dp = SECURITY;

	add(sID, fn, ln, ea, age, d1, d2, d3, dp);
}

void Roster::add(string sID, string sFirstName, string sLastName, string sEmailAddress, int sAge, int sDays1, int sDays2, int sDays3, DegreeProgram dp)
{
	int darr[3] = { sDays1, sDays2, sDays3 };
	studentRosterArray[++lastIndex] = new Student(sID, sFirstName, sLastName, sEmailAddress, sAge, darr, dp);
}