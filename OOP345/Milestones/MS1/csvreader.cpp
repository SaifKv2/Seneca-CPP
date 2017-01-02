// OOP345 - Milestone 1 - Ben Mantle - 064329147

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

string& trim(string& string) {

	while (!string.empty() && isspace(string[0])) {
		string.erase(0, 1);
	}
	while (!string.empty() && isspace(string[string.size() - 1])) {
		string.erase(string.size() - 1, 1);
	}

return string;
}

void csvread(string filename, char delimiter, vector <vector<string> > &data) {
	
	ifstream is(filename.c_str());

	if (is.is_open()) {

		string s;

		while (getline(is, s)) {

			auto c = s.find("\r");

			if (c != std::string::npos) {
				s.erase(c, 1);
			}

			stringstream ss(s);
			vector <string> fields;
			string field;
			
			while (getline(ss, field, delimiter)) {

				trim(field);
				fields.push_back(field);
			}

		data.push_back(fields);
		}
	}

	else {
		throw string("Cannot open the file! \n") + filename;
	}
}

int main(int argc, char** argv) {

	std::cout << "\nCommand Line : ";

	for (int i = 0; i < argc; i++)
		std::cout << argv[i] << ' ';

	std::cout << std::endl;

	if (argc != 3) {

		std::cerr << "\n***Incorrect number of arguments***\n";
	}

	else {
		try {
			string filename = argv[1];
			char delimiter = argv[2][0];
			vector <vector<string> >data;
			csvread(filename, delimiter, data);

			for (auto line : data) {
				for (auto field : line) {
					cout << field << " ";
				}
				cout << "\n";
			}
		}
		catch (string& e) {
			cerr << e << "\n";
		}
	}
}