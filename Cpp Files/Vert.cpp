    /*
                Ideas!
            - add a GUI
            - show status of VM while it does stuff
            - add more opcodes
            - use a sleep_for() after each thing the vm does, so the user can activly see everything happening
            - make two different runs, one that immediatly does the calculations, and one that uses the sleep_for()
    */ 
#include "Vert.h"
#include "Opcode.h"
    Vert::Vert() : ScanLee(std::cin), led(std::random_device{}())/*No args constructor*/{}
    void Vert::select(){
        int eep = err("Manual (1.) or Random (2.)",1,2);
        if(eep == 1) getManualMemory();
        else getRandomMemory();
        run();//begins the VM
    }
    void Vert::getManualMemory(){
        int eep = 1;//cannot equal 0 because it would then go past the while loop
        bool isMainLoop = false;
        while(eep > 0){
            if (Memory.size() < 1){
                Memory.push_back(1);//immediatly added because nothing else could be done at this time(except for halt)
                eep = err("Opicode PUSH(1) has been initialy placed into Memory\nPlease enter any number" ,1,50);
                isMainLoop = true;//makes the main loop accessable
                Memory.push_back(eep);//adds pushed number
            }
            
            if(isMainLoop){
                eep = errAuto("Please enter an Opcode(1.PUSH, 2.ADD, 3.PRINT, 4. SUBTRACT, 5. MULTIPLY, 6. DIVIDE, 0.HALT)",0,6);                if(eep == 1){
                    eep = err("Please enter a number to PUSH",1,50);
                    Memory.push_back(1);
                }
                Memory.push_back(eep);
            }
        }
    }
    void Vert::getRandomMemory(){
        int eep = 1;//cannot equal 0 because it would then go past the while loop
        bool isMainLoop = false;
        while(eep > 0){
            if (Memory.size() < 1){
                Memory.push_back(1);//immediatly added because nothing else could be done at this time(except for halt)
                eep = errAuto("Opicode PUSH(1) has been initialy placed into Memory\nPlease enter any number" ,1,50);
                isMainLoop = true;//makes the main loop accessable
                Memory.push_back(eep);//adds pushed number
            }
            
            if(isMainLoop){
                eep = errAuto("Please enter an Opcode(1.PUSH, 2.ADD, 3.PRINT, 4. SUBTRACT, 5. MULTIPLY, 6. DIVIDE, 0.HALT)",0,6);
                if(eep == 1){
                    eep = errAuto("Please enter a number to PUSH",1,50);
                    Memory.push_back(1);
                }
                Memory.push_back(eep);
            }
        }
    }
    void Vert::run(){
        while(Point < Memory.size()){//Safely increment the IP
            Execute(Memory[Point]);//Takes the pointed number inside the memory and decides what to do with it
            Point++;//looks at next number in memory
        }
    }
    void Vert::Execute(int &index){
        //Add subtraction,multiplication, and division
        Opcode Command = static_cast<Opcode>(index);//turns the number into its Opcode alternative
        switch(Command){//decode
            case Opcode::HALT: 
                std::exit(0);//stops the program
                break;
            case Opcode::PUSH:
                Point++;//next number
                Stack.push_back(Memory[Point]);//adds the number being pointed at in the memory
                break;//stops loop
            case Opcode::ADD:
                if(Stack.size() < 2);//prevents underflow
                else{
                    int firstNum = Stack.back();//equals the most recent added number
                    Stack.pop_back();//deletes recently added number
                    int secondNum = Stack.back();
                    Stack.pop_back();
                    Stack.push_back(firstNum + secondNum);//adds the sum of the two removed numbers 
                }
                break;//stops loop
            case Opcode::PRINT:
                if(Stack.size() >= 1)//prevents underflow
                    printN(std::to_string(Stack.back()) + " ");
                break;
            case Opcode::SUB:
                if(Stack.size() < 2);//prevents underflow
                else{
                    int firstNum = Stack.back();//equals the most recent added number
                    Stack.pop_back();//deletes recently added number
                    int secondNum = Stack.back();
                    Stack.pop_back();
                    Stack.push_back( secondNum- firstNum);//subtracts the sum of the two removed numbers 
                }
                break;
            case Opcode::DIV:
                if(Stack.size() < 2);//prevents underflow
                else{
                    int firstNum = Stack.back();//equals the most recent added number
                    Stack.pop_back();//deletes recently added number
                    int secondNum = Stack.back();
                    Stack.pop_back();
                    Stack.push_back(secondNum / firstNum);//Divides the sum of the two removed numbers 
                }
                break;
            case Opcode::MULTIPLY:
                if(Stack.size() < 2);//prevents underflow
                else{
                    int firstNum = Stack.back();//equals the most recent added number
                    Stack.pop_back();//deletes recently added number
                    int secondNum = Stack.back();
                    Stack.pop_back();
                    Stack.push_back(firstNum * secondNum);//multiplies the sum of the two removed numbers 
                }
                break;
        }
    }
    int Vert::errAuto(std::string prompt, int min, int max){
        std::uniform_int_distribution<int> dist(min,max);
        int choice = dist(led);
        print(prompt);
        print("Random picked [" + std::to_string(choice) + "]");
        return choice;
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
    void Vert:: print(std::string prompt){
        std::cout << prompt + "\n" << std::endl;
    }
    void Vert:: printN(std::string prompt){
        std::cout << prompt << std::endl;
    }