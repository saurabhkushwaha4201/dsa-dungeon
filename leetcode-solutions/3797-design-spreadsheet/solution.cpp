class Spreadsheet {
public:
    int totalRows;
    unordered_map<std::string, int> cells;
    Spreadsheet(int rows):totalRows(rows) {

    }
    
    void setCell(string cell, int value) {
        cells[cell] = value;
    }
    
    void resetCell(string cell) {
        cells[cell]= 0;
    }
    
    int getValue(string formula) {
        if (formula[0] != '=') {
            return 0; // Formula must start with '='
        }

        size_t plusPos = formula.find('+');
        if (plusPos == std::string::npos) {
            return 0; // Formula must contain '+'
        }

        // Extract the two operands
        string left = formula.substr(1, plusPos - 1);
        string right = formula.substr(plusPos + 1);

        // Trim spaces from the operands
        left.erase(remove(left.begin(), left.end(), ' '), left.end());
        right.erase(remove(right.begin(), right.end(), ' '), right.end());

        // get values
        int num1 = isalpha(left[0]) ? (cells.count(left) ? cells[left] : 0) : std::stoi(left);
        int num2 = isalpha(right[0]) ? (cells.count(right) ? cells[right] : 0) : std::stoi(right);

        return num1 + num2;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */
