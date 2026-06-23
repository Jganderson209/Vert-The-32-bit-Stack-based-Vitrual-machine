#ifndef Vert_h
#define Vert_h
#include <iostream>
#include <istream>// For std::cin, so we can tell the vm to do things
#include <vector>// the stack + the memory
#include <random>//For std::random_device so memory loads without manual input
#include <string>
class Vert{
    private:
        std::mt19937 led;//Random input
        std::istream& ScanLee;//Manual input
        std::vector<int> Memory;
        std::vector<int> Stack;
        int Point = 0;//Points to number in memory
    public:
        void run();//Begins the VM
        void Execute(int &index);//VM does things
        void select();//selects how numbers will be put in the memory
        void getManualMemory();//Manual input gets put into the memory
        void getRandomMemory();//Random input gets put into the memory
        int err(std::string prompt, int min, int max);//Handels input & prevents input errors(std::cin)
        int errAuto(std::string prompt, int min, int max); //Same thing but for random input(std::)
        void print(std::string prompt);//prints text to the terminal with a new line in the end
        void printN(std::string prompt);//prints tect to the terminal without a new line in the end
        Vert();//No args constructor
};
#endif