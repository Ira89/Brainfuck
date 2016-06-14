#ifndef BRAINFUCK_INTERPRETER_H
#define BRAINFUCK_INTERPRETER_H

#include <iostream>
#include <vector>
#include <string>

const int MAX_SIZE = 30000;
const int MOD = 256;
const int MAX_ADD_SIZE = 10;

class BrainfuckInterpreter{

    private:
        std::string commandLine;
        bool isOpenChar(char ch);
        bool isCloseChar(char ch);

    public:
        BrainfuckInterpreter(std::string str) : commandLine(str){};
        BrainfuckInterpreter(const BrainfuckInterpreter &);
        const BrainfuckInterpreter & operator=(const BrainfuckInterpreter &);
        ~BrainfuckInterpreter(){};
        void parseCommand();
};

bool BrainfuckInterpreter::isOpenChar(char ch){
	return ch == '(' || ch == '[';
}

bool BrainfuckInterpreter::isCloseChar(char ch){
	return ch == ')' || ch == ']';
}

void BrainfuckInterpreter::parseCommand(){

    std::vector<int> stackBr;
    int wo[MAX_SIZE + MAX_ADD_SIZE];
    int wc[MAX_SIZE + MAX_ADD_SIZE];

    int sizeCommandLine = commandLine.size();
    for(int i = 0; i < sizeCommandLine; ++i){
        char ch = commandLine[i];
        if(isOpenChar(ch)){
            stackBr.push_back(i);
        }
        else if(isCloseChar(ch)){
            int top = stackBr.back();
            stackBr.pop_back();
            wc[top] = i;
            wo[i] = top;
        }
    }

    int var = 0;
    int ptr = 0;
    int tape[MAX_SIZE] = {0};

    for(int i = 0; i < sizeCommandLine; ++i){
        switch(commandLine[i]){
            case '>': ptr = (ptr + 1) % MAX_SIZE; break;
            case '<': ptr = (ptr + MAX_SIZE - 1) % MAX_SIZE; break;
            case '|': ptr = 0; break;
            case ',': case ';': std::cin >> tape[ptr]; break;
            case '.': case ':': std::cout << tape[ptr] << " "; break;
            case '=': tape[ptr] = tape[(ptr + MAX_SIZE - 1) % MAX_SIZE]; break;
            case '0': tape[ptr] = 0; break;
            case '!': var = tape[ptr]; break;
            case '?': tape[ptr] = var % MOD; break;
            case '*': tape[ptr] = (tape[ptr] * tape[(ptr + MAX_SIZE - 1) % MAX_SIZE]) % MOD; break;
            case '/': tape[ptr] /= tape[(ptr + MAX_SIZE - 1) % MAX_SIZE];
            case '+': tape[ptr] = (tape[ptr] + 1 ) % MOD; break;
            case '-': if (tape[ptr] > 0) --tape[ptr]; break;
            case '^': std::cout << var << std::endl; break;
            case '$': var = ptr; break;
            case '[': if(tape[ptr] == 0) i = wc[i]; break;
            case ']': i = wo[i] - 1; break;
            case '(': if(tape[ptr] == 0) i = wc[i]; break;
            case ')': break;
            case ' ': break;
            default: std::cout << "unknown command" << std::endl;
        }
    }
}

#endif // BRAINFUCK_INTERPRETER_H
