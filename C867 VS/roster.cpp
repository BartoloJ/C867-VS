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

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram)
{
	int darr[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };
	classRosterArray[++lastIndex] = new Student(studentID, firstName, lastName, emailAddress, age, darr, degreeProgram);
}

void Roster::printAll()
{
	Student::printHeader();
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		cout << classRosterArray[i]->getStudentID(); cout << '\t';
		cout << classRosterArray[i]->getFirstName(); cout << '\t';
		cout << classRosterArray[i]->getLastName(); cout << '\t';
		cout << classRosterArray[i]->getEmailAddress(); cout << '\t';
		cout << classRosterArray[i]->getAge(); cout << '\t';
		cout << classRosterArray[i]->getDaysToComplete()[0]; cout << '\t';
		cout << classRosterArray[i]->getDaysToComplete()[1]; cout << '\t';
		cout << classRosterArray[i]->getDaysToComplete()[2]; cout << '\t';
		cout << degreeProgramTypeStrings[classRosterArray[i]->getDegreeProgram()] << std::endl;
	}
}

void Roster::printByDegreeProgram(DegreeProgram dp)
{
	Student::printHeader();
	for (int i = 0; i <= Roster::lastIndex; i++) {
		if (Roster::classRosterArray[i]->getDegreeProgram() == dp) classRosterArray[i]->print();
	}
	cout << std::endl;
}

void Roster::printInvalidEmails()
{
	bool any = false;
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		string emailAddress = (classRosterArray[i]->getEmailAddress());
		if (emailAddress.find('@') == string::npos || emailAddress.find('.') == string::npos || emailAddress.find(' ') != string::npos)
		{
			any = true;
			cout << emailAddress << ": " << classRosterArray[i]->getLastName() << std::endl;
		}
	}
	if (!any) cout << "NONE" << std::endl;
}

void Roster::printAverageDaysInCourse()
{
	for (int i = 0; i <= Roster::lastIndex; i++) {
		cout << classRosterArray[i]->getStudentID() << ": ";
		cout << (classRosterArray[i]->getDaysToComplete()[0] + classRosterArray[i]->getDaysToComplete()[1] + classRosterArray[i]->getDaysToComplete()[2]) / 3.0 <<  std::endl;
	}
	cout << std::endl;
}

void Roster::remove(string studentID)
{
	bool success = false;
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		if (classRosterArray[i]->getStudentID() == studentID)
		{
			success = true;
			if (i < numStudents - 1)
			{
				Student* temp = classRosterArray[i];
				classRosterArray[i] = classRosterArray[numStudents - 1];
				classRosterArray[numStudents - 1] = temp;
			}
			Roster::lastIndex--;
		}
	}
	if (success)
	{
		cout << studentID << " removed from roster." << std::endl << std::endl;
		this->printAll();
	}
	else cout << studentID << " not found." << std::endl << std::endl;
}

Roster::~Roster()
{
	cout << "Destructor called" << std::endl << std::endl;
	for (int i = 0; i < numStudents; i++)
	{
		cout << "Destroying student #" << i + 1 << std::endl;
		delete classRosterArray[i];
		classRosterArray[i] = nullptr;
	}
}