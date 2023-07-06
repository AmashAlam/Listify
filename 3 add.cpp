//Name : Muhammad Huzaifa
//Roll Number : 19B-139-CS
//Section : B
// Subject: Compiler Construction
//Lab : 14
#include <iostream>
#include <map>
#include <string>

std::map<std::string, int> variables;
std::map<std::string, int> intermediate_vars;

void generate_3_address_code(std::string expr) {
    int counter = 1;
    std::string current_var;
    for (int i = 0; i < expr.length(); i++) {
        if (isalpha(expr[i])) {
            current_var += expr[i];
        }
        else {
            if (variables.find(current_var) == variables.end()) {
                std::cout << "Enter value of variable " << current_var << ": ";
                int value;
                std::cin >> value;
                variables[current_var] = value;
            }
            current_var = "";
        }
        if (expr[i] == '*' || expr[i] == '/') {
            std::string new_var = "t" + std::to_string(counter);
            std::cout << new_var << " = " << current_var << " " << expr[i] << " ";
            current_var = new_var;
            counter++;
            i++;
            while (isalpha(expr[i])) {
                current_var += expr[i];
                i++;
            }
            if (variables.find(current_var) == variables.end()) {
                std::cout << "Enter value of variable " << current_var << ": ";
                int value;
                std::cin >> value;
                variables[current_var] = value;
            }
            std::cout << std::endl;
            current_var = new_var;
        }
        else if (expr[i] == '+' || expr[i] == '-') {
            std::string new_var = "t" + std::to_string(counter);
            std::cout << new_var << " = " << current_var << " " << expr[i] << " ";
            current_var = new_var;
            counter++;
            i++;
            while (isalpha(expr[i])) {
                current_var += expr[i];
                i++;
            }
            if (variables.find(current_var) == variables.end()) {
                std::cout << "Enter value of variable " << current_var << ": ";
                int value;
                std::cin >> value;
                variables[current_var] = value;
            }
            std::cout << std::endl;
            current_var = new_var;
        }
    }
    std::cout << "result = " << current_var << std::endl;
}

int main() {
    std::cout << "Enter expression: ";
    std::string expr;
    std::cin >> expr;
    generate_3_address_code(expr);
    return 0;
}
