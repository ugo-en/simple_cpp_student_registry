#include <string>;

class Student
{
	private:
		std::string name, gender;
		int age;

	public:
		// it needs operators so that comparisons can be made
		bool operator == (const Student& s) const { return name == s.name; }
		bool operator != (const Student& s) const { return !operator==(s); }

		Student(std::string name, std::string gender, int age) {
			this->name = name;
			this->gender = gender;
			this->age = age;
		}

		// define the getters
		std::string getName() {
			return this->name;
		}
		std::string getGender() {
			return this->gender;
		}

		int getAge() {
			return this->age;
		}

		// define the setters
		void setName(std::string n) {
			this->name = n;
		}
		void setGender(std::string g) {
			this->gender = g;
		}
		void setAge(int a) {
			this->age = a;
		}

		// public methods here
		void showDetails() {
			std::cout << "\n\nSTUDENT DETAILS\n";
			std::cout << "Name: " << this->name << std::endl;
			std::cout << "Age: " << this->age << std::endl;
			std::cout << "Gender: " << this->gender << std::endl;
			std::cout << std::endl;
		}
};

