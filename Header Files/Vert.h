#ifndef Vert_h
#define Vert_h
#include <iostream>// This is almost always used
#include <istream>// For std::cin, so we can tell the vm to do things
#include <vector>// arrays/stacks
#include <random>//For picking random numbers and letting the vm do the stuff without input
#include <string>
class Vert{
    private:
        std::mt19937 led;
        std::istream& ScanLee;
        std::vector<int> Memory;
        std::vector<int> Stack;
        int Point = 0;
    public:
        void run();
        void select();
        std::vector<int> getManualMemory();
        std::vector<int> getRandomMemory();
        void Execute(int &index);
        int err(std::string prompt, int min, int max);
        Vert();
};
#endif