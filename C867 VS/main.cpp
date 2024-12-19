// C867 VS.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "roster.h"

int main()
{
    cout << "C867 Scripting and Programming - Applications" << std::endl;
    cout << "C++" << std::endl;
    cout << "Student ID: 011818530" << std::endl;
    cout << "Jonathan Bartolo\n" << std::endl;

    const string studentData[] =
    {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY", "A5,Jonathan,Bartolo,jonathan.e.bartolo@gmail.com,28,25,35,41,SOFTWARE"
    };

    const int numStudents = 5;
    Roster roster;

    for (int i = 0; i < numStudents; i++) roster.parse(studentData[i]);
    cout << "Displaying all students: " << std::endl;
    roster.printAll();
    cout << std::endl;
    
    cout << "Displaying students with invalid emails" << std::endl;
    roster.printInvalidEmails();
    cout << std::endl;

    cout << "Displaying average days in course: " << std::endl;
    roster.printAverageDaysInCourse();

    
    cout << "Displaying by degree program SOFTWARE: " << std::endl;
    roster.printByDegreeProgram((SOFTWARE));

    cout << "Removing student with ID A3: " << std::endl;
    roster.remove("A3");
    cout << std::endl;

    cout << "Removing student with ID A3: " << std::endl;
    roster.remove("A3");
    cout << std::endl;

    system("pause");
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
