#include "Vert.h"
#include "Opcode.h"
    Vert::Vert() : ScanLee(std::cin), led(std::random_device{}()){}
    void Vert::select(){
        int eep = err("Manual (1.) or Random (2.)",1,2);
        if(eep == 1) getManualMemory();
        else getRandomMemory();
        run();
    }
    void Vert::getManualMemory(){
        int eep = 112212121212;
        bool isMainLoop = false;
        while(eep > 0){
            if (Memory.size() < 1){
                Memory.push_back(1);
                eep = err("Opicode PUSH(1) has been initialy placed into Memory\nPlease enter any number" ,1,50);
                isMainLoop = true;
                Memory.push_back(eep);
            }
            
            if(isMainLoop){
                eep = err("Please enter an Opcode(1.PUSH, 2.ADD, 3.PRINT,0.HALT)",0,3);
                
                if(eep == 1){
                    eep = err("Please enter a number to PUSH",1,50);
                    Memory.push_back(1);
                }
                Memory.push_back(eep);
            }
        }
    }
    void Vert::getRandomMemory(){

    }
    void Vert::run(){
        //this should run the steps
        while(Point < Memory.size()){//Safely increment the IP
            Execute(Memory[Point]);
            Point++;
        }
    }
    void Vert::Execute(int &index){
        Opcode Command = static_cast<Opcode>(index);
        switch(Command){//decode
            case Opcode::HALT: 
                std::exit(0);
                break;
            case Opcode::PUSH:
                Point++;
                Stack.push_back(Memory[Point]);
                break;
            case Opcode::ADD:
                if(Stack.size() < 2);
                else{
                    int firstNum = Stack.back();
                    Stack.pop_back();
                    int secondNum = Stack.back();
                    Stack.pop_back();
                    Stack.push_back(firstNum + secondNum);
                }
                break;
            case Opcode::PRINT:
                if(Stack.size() >= 1)
                    print(std::to_string(Stack.back()));
        }
    }
    int Vert::err(std::string prompt, int min, int max){
        int choice = 0;
        bool ValPut = false;
     
        while (!ValPut) {
            print(prompt);
            ScanLee >> choice;
            
            if (ScanLee.fail()) {
                print("Invalid input! Please enter a number.");
                ScanLee.clear(); 
                ScanLee.ignore(10000, '\n'); 
                continue; 
            }
                        
            if (choice >= min && choice <= max) {
                ValPut = true;
            } else {
                print("Please enter a number between " + std::to_string(min) + " and " + std::to_string(max));
            }
        }
     
        return choice;
    }
    int main(){
        Vert v;
        v.select();
        return 0;
    }
    void print(std::string prompt){
        std::cout << prompt + "\n" << std::endl;
    }