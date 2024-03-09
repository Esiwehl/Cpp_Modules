#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

int instructions(char *str){
	std::cerr << "Incorrect usage:" << str <<
		" <filename> <search> <replace>" << std::endl;
	return 1;
}

std::string replaceString(std::string input, std::string& toFind, std::string& toReplace){
	size_t pos = 0, lastPos = 0;
	std::string newString;

	if (toFind.empty())
		return input;

	while ((pos = input.find(toFind, lastPos)) != std::string::npos){
		newString += input.substr(lastPos, pos - lastPos);
		newString += toReplace;
		lastPos = pos + toFind.size();
	}
	newString += input.substr(lastPos);
	return newString;
}

int main(int argc, char **argv){
	if (argc != 4)
		return instructions(argv[0]);

	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];

	std::ifstream inFile(filename);
    if (!inFile) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return 1;
    }

    std::string outFilename = filename + ".replace";
    std::ofstream outFile(outFilename);
    if (!outFile) {
        std::cerr << "Error creating file: " << outFilename << std::endl;
        return 1;
    }

	std::string line;
	while (getline(inFile, line)){
		outFile << replaceString(line, s1, s2);
		if (inFile.eof())
			break;
		outFile << std::endl;
	}

	inFile.close();
	outFile.close();
}