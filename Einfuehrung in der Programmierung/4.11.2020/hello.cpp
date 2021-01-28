//tranmankhang1705@gmail.com

#include <iostream>
//Header needed for input and output of C++ programs.
#include <string>
//Header needed for string data type.
int main(){	 //" main()"  is the entry point of the C++ program.
	 	// "int main(") will return an integer value.
	std::string name;
	//Initialize the variable "name" in memory, which has the type "string".
	std::cout << "Name? ";
	//Prints the text to the screen.
	std::cin >> name;
	//Reads user input and assign it to the variable "name".
	std::cout << "Hallo " << name << ", willkommen zur Einfuehrung in die Programmieung!" << std::endl;
	//Print the the text to the screen and insert a new line.
	return 0;
	//The program ends succesfully.
}

