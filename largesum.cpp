#include <iostream>
#include <fstream>
#include <string>
#include <utility>


void addition(std::string& total, std::string number) {
    if(number.length() > total.length()) {
        std::swap(total, number);
    }
    int totalindex = static_cast<int>(total.length()) - 1;
    int numindex = static_cast<int>(number.length()) -1;
    int remainder = 0; 
    for(; numindex >= 0; numindex--) {
        int totaldigit = total[totalindex] - '0';
        int numdigit = number[numindex] - '0';
        // implement remainder too 
        int sum = totaldigit + numdigit + remainder; 
        total[totalindex] = (sum % 10) + '0';
        remainder = sum / 10; 
        
        totalindex--;
    }
    
    while(totalindex >= 0 && remainder > 0) {
        int sum = (total[totalindex] - '0' + remainder);
        total[totalindex--] = (sum % 10) + '0';
        remainder = sum / 10; 
    }
    if(remainder > 0) {
        total.insert(total.begin(), remainder + '0');
    }
    int i = 0; 
    while(total[i] == '0') {
        total.erase(i, i);
        i++; 
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



