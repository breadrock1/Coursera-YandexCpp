#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class FunctionPart {
public:
    FunctionPart(char new_operation, double new_value) {
        value = new_value;
        operation = new_operation;
    }
    double Apply(const double& sourse_value) const {
        if (operation == '+') return sourse_value + value;
        else if (operation == '-') return sourse_value - value;
        else if (operation == '*') return sourse_value * value;
        else return sourse_value / value;
    }
    void Invert() {
        if (operation == '+') operation = '-';
        else if(operation == '-') operation = '+';
        else if (operation == '*') operation = '/';
        else operation = '*';
    }

private:
    char operation;
    double value;
};

class Function {
public:
    void AddPart(char operation, double value) {
        parts.push_back({ operation, value });
    }
    double Apply(double value) const {
        for (const FunctionPart& part : parts)
            value = part.Apply(value);

        return value;
    }
    void Invert() {
        for (FunctionPart& part : parts)
            part.Invert();

        reverse(begin(parts), end(parts));
    }

private:
    vector<FunctionPart> parts;
};