#include <iostream>
#include <string>
#include "Student.h"
#include <list>

// craeate student objects
Student john = Student("John", "M", 18);
Student femi = Student("Femi", "M", 17);
Student lisa = Student("Lisa", "F", 19);
Student ashley = Student("Ashley", "F", 19);

// list of Students
std::list<Student> students = { john,femi,lisa,ashley };

// menu items
std::string menuItems[4] = {
	"Show all students",
	"Add student",
	"Show student details",
	"Delete student",
};

int showMenu() {
	// for displaying menu items
	std::cout << "\n\n=====\nMENU\n=====\n";

	int i = 0;
	for (std::string item : menuItems) {
		i++;
		std::cout << i << ". " << item << "\n";
	}

	int option = 0;
	std::cout << "Select an item: ";
	std::cin >> option;
	
	option-=1;

	if (0 > option > i-1 ) {
		std::cout << "\nPlease select a valid option!";
		return showMenu();
	}

	return option;
}

void showAllStudents() {
	// for showing all the students
	std::cout << "\nThese are all the students:\n\n";

	int i = 0;
	for (Student student : students) {
		i++;
		std::cout << i << ". " << student.getName() << "\n";
	}
}

void showStudentDetails() {
	// for showing the details of one student
	std::cout << "\n\nPlease select a Student.\n\n";
	showAllStudents();

	std::cout << "Select one: ";
	int option;
	std::cin >> option;

	// first create an iterator
	std::list<Student>::iterator iter = students.begin();

	// advance to position
	std::advance(iter, option-1);

	// assign the current iterator val to a student object of readability
	Student s = *iter;

	// show the details
	s.showDetails();

	std::cout << "\n";
}

void deleteStudent() {
	// deletes a student from the list
	std::cout << "\nSelect a student for deleting:\n\n";

	showAllStudents();

	int option = 0;
	std::cout << "Which one do you want to delete? ";

	std::cin >> option;
		
	int ix = 0;
	for (Student student : students) {
		ix++;
		if (option == ix) {
			std::cout << "Removing " << student.getName() << "\n";
			students.remove(student); // this is only possible because it has operators in its class
			std::cout << "Removed!\n";
			break;
		}
	}
}

void addStudent() {
	// adds a student to the list
	std::string name;
	std::cout << "\nAdd a new name: ";
	std::cin >> name;

	std::string gender;
	std::cout << "\nSelect a gender M (Male), F (Female), O (Other): ";
	std::cin >> gender;

	int age;
	std::cout << "\nHow old is this student: ";
	std::cin >> age;

	Student student = Student(name, gender, age);
	students.push_back(student);

	std::cout << "Added the student " << student.getName();
}

int main(){
	std::cout << "\n\nWELCOME TO MY SCHOOL REGISTRY MANAGEMENT APP\n\n";

	int option = 0;
	while (true){
		 option = showMenu();
	
		switch (option) {
			case 0:
				showAllStudents();
				break;
			case 1:
				addStudent();
				break;
			case 2:
				showStudentDetails();
				break;
			case 3:
				deleteStudent();
				break;
		}
	}
}