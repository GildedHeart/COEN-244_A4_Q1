#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Utility.h"
//D:\School test\iot-shard.txt

int main() {
	int shardIndex = 0;
	int sampleSize = 0;
	int attributeCount = 0;

	std::string inputFilePath;
	std::string outputFilePath;
	std::string firstLine;
	std::string line;

	std::cout << "Please enter the file path for the RT_IOT2022 data: \n";
	getline(std::cin, inputFilePath);

	std::ifstream inputFile(inputFilePath);

	if (!inputFile) {
		throw std::runtime_error("No file was found at [" + inputFilePath + "].\n");
	} 

	nextLine();

	std::cout << "Please enter the file path where you woluld like the shards to be stored: \n";
	getline(std::cin, outputFilePath);

	nextLine();

	std::cout << "Please enter how many data samples would you like per shard: \n";
	std::cin >> sampleSize;

	nextLine();
	
	getline(inputFile, firstLine);

	while (!inputFile.eof()) {
		std::string token;

		std::ofstream outputFile( outputFilePath + "\\shard_" + std::to_string(shardIndex) + ".txt");

		if (attributeCount < 1) {
			std::stringstream firstLineInfo(firstLine);
			while (getline(firstLineInfo, token, ',')) {
				outputFile << token << std::endl;
				attributeCount++;
			}
			outputFile << "\nThere are " << std::to_string(attributeCount) << " attributes.\n\n";
		}
		else
		{
			std::stringstream firstLineInfo(firstLine);
			while (getline(firstLineInfo, token, ',')) {
				outputFile << token << std::endl;
			}
			outputFile << "\nThere are " << std::to_string(attributeCount) << " attributes.\n\n";
		}

		for (int i = 0; i < sampleSize; i++) {
			getline(inputFile, line);
			outputFile << "Data : [" << line << "]\n\n";
			line.clear();
		}

		shardIndex++;
		outputFile.close();
	}

	inputFile.close();

	std::cout << "Please check your files for shard_0 to shard_" << std::to_string(shardIndex - 1) << ".\n";

	return 0;
}
