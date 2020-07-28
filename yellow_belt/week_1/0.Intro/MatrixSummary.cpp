#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>

using namespace std;

class Matrix {
public:
    Matrix() {
        this->rows = 0;
        this->columns = 0;

        matrix[0][0] = 0;
    }

    Matrix(const int& num_rows, const int& num_cols) {
        this->rows = num_rows;
        this->columns = num_cols;

        for (int i = 0; i < num_rows; ++i) {
            matrix[i].resize(num_cols);
        }
    }

    void Reset(const int& num_rows, const int& num_cols) {
        for (int i = 0; i < num_rows; ++i) {
            matrix[i].resize(num_cols);
        }
    }

    int At(const int& num_row, const int& num_col) const {
        return matrix[num_row].at(num_col);
    }

//    int At(const int& num_row, const int& num_col){
//        return &matrix[num_row].at(num_col);
//    }

    int GetNumRows() const { return this->rows; }

    int GetNumColumns() const {return this->columns; }

private:
    int rows, columns;
    vector<vector<int>> matrix;
};

ostream& operator << (ostream& stream, const Matrix& matrix) {
    stream << setw(4) << setfill('0') << date.getYear() << '-'
           << setw(2) << setfill('0') << date.getMonth() << '-'
           << setw(2) << setfill('0') << date.getDay();

    return stream;
}

void ignoring(stringstream& inputStream, const string& input) {
    if (inputStream.peek() != '-')
        throw runtime_error("Wrong date format: " + input);
    inputStream.ignore(1);
}

istream& operator >> (istream& inputStream, Date& date) {
    int day, month, year;
    day = month = year = 10000;

    string input, end;

    if (inputStream >> input) {
        stringstream stream(input);

        stream >> year;
        ignoring(stream, input);

        stream >> month;
        ignoring(stream, input);

        stream >> day;
        stream >> end;

        if (year > -1 && year < 10000 && month < 10000 && day < 10000 && end.empty()) {
            date = Date(day, month, year);
            return inputStream;
        } else throw runtime_error("Wrong date format: " + input);

    } else throw runtime_error("Wrong date format: " + input);
}

int main() {
    Matrix one;
    Matrix two;

    cin >> one >> two;
    cout << one + two << endl;

    return 0;
}
