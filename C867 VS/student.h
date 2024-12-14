//
//  student.h
//  C867
//
//  Created by Jon on 12/14/24.
//

#pragma once
#include <iostream>
#include "degree.h"
using std::string;
using std::cout;

class Student
{
public:
	const static int daysArraySize = 3;
private:
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int daysToComplete[daysArraySize];
	DegreeProgram degreeProgram;
};