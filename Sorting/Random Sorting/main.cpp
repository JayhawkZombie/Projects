 /**
  * @author Kurt Slagle
  * @file main.cpp
  * random number generator
  *
  *
  */

#include <random>
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <chrono>

int main(int argc, char *argv[])
{
    std::ofstream OUT("out.txt");
    std::cout << argv[0] << std::endl;
    std::string numNum = argv[1];

    int numberOfNumbers = std::stoi(argv[1]);
    int lowerNumber = std::stoi(argv[2]);
    int upperNumber = std::stoi(argv[3]);
    std::cout << numberOfNumbers << " numbers from " << lowerNumber << " to " << upperNumber << std::endl;

    std::default_random_engine generator(time(nullptr));
    std::uniform_int_distribution<int> distribution(lowerNumber, upperNumber);
    int counter{0};
    int randomNumber{0};
    OUT << numberOfNumbers << "\n";

    for (int i = 0; i < numberOfNumbers; i++)
    {
       randomNumber = distribution(generator);
       OUT << randomNumber << "\n";
       std::cout << randomNumber << std::endl;
       counter++;
    }
    std::cout << "Generated " << counter << " numbers" << std::endl;
    OUT.close();
    return 0;
}
