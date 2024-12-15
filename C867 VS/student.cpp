//
//  student.cpp
//  C867
//
//  Created by Jon on 12/14/24.
//
#include "student.h"
Student::Student()
{
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->emailAddress = "";
	this->age = 0;
	for (int i = 0; i < daysArraySize; i++) this->daysToComplete[i] = 0;
	this->degreeProgram = DegreeProgram::SECURITY;
	
}

Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysToComplete[], DegreeProgram degreeProgram)
{
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->age = age;
	for (int i = 0; i < daysArraySize; i++) this->daysToComplete[i] = daysToComplete[i];
	this->degreeProgram = degreeProgram;

}