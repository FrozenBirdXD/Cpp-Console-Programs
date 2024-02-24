#include <iostream>
#include <sstream>

double getResult(const double &num1, const double &num2, const int operation)
{
    switch (operation)
    {
    case 1:
        return num1 + num2;
    case 2:
        return num1 - num2;
    case 3:
        return num1 * num2;
    case 4:
        if (num2 == 0)
        {
            std::cout << "Cannot divide by 0" << std::endl;
            return -1.0;
        }
        return num1 / num2;

    default:
        break;
    }
    return 0.0;
}

void programLoop()
{
    while (true)
    {
        std::string input;
        int numInput;
        double result;

        std::cout << "Choose operation: \n1: + \n2: - \n3: * \n4: /"
                  << "\n"
                  << "Number of operation: ";

        std::cin >> input;
        if (input == "end")
        {
            break;
        }

        std::stringstream(input) >> numInput;
        if (numInput > 0 && numInput < 5)
        {
            double num1, num2;
            std::cout << "First operand: ";
            std::cin >> num1;
            std::cout << "Second operand: ";
            std::cin >> num2;
            std::cout << "\v"
                      << "Result: " << getResult(num1, num2, numInput) << "\n\v";
        }
        else
        {
            std::cout << "Invalid operation... Try again" << std::endl;
        }
    }
}

int main()
{
    std::cout << "Simple Calculator"
              << "\n"
              << "Supported Operations: + - * / end" << std::endl;

    programLoop();

    std::cout << "Thank you for using this shitty calculator :)";

    return 0;
}