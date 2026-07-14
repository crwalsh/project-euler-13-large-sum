#include <iostream>
#include <fstream>
#include <string>
#include <utility>


void addition(int colSums[], string& number) {
    int col = 0;
    int placeInd = number.size();
    while(placeInd > 0){
        placeInd--;
        colSums[col] = colSums[col] + (number[placeInd] - '0');
        col++
    }

}


int main() {
    std::ifstream file("input.txt");
    if(!file) {
        std::cerr << "Error: input.txt couldn't open\n";
        return 1; 
    }
    
    std::string number;
    std::string total = "0";
    while(file >> number) {
        addition(total, number);
    }
    std::cout << "Full sum: " << total << "\n";
    std::cout << "First 10 digits: " << total.substr(0, 10) << '\n';
    return 0; 
}



