#include <iostream>
#include <fstream>
#include <string>
#include <utility>

using namespace std;

void addition(int colSums[], string& number) {
    int col = 0;
    int placeInd = number.size();
    while(placeInd > 0){
        placeInd--;
        colSums[col] = colSums[col] + (number[placeInd] - '0');
        col++
    }

}
void carry(int colSums[]){
    int col = 0;
    while(col < maxSpots - 1){
        colSums[col + 1] = colSums[col + 1] +(colSums[col] / 10);
        colSums[col] = colSums[col] % 10;
        col++;
    }

}
string writeAns(const int colSums[]){

    int leftMostCol = maxSpots - 1;
    string answer;

    while(leftMostCol > 0 && colSums[leftMostCol] == 0){
        leftMostCol--;
    }
    while(leftMostCol >= 0){
        answer += colSums[leftMostCol] + '0';
        leftMostCol--;
    }
    return answer;
}

int main() {
    ifstream file("input.txt");
    if(!file) {
        cerr << "Error: input.txt couldn't open\n";
        return 1; 
    }
    
    string number;
    string total = "0";
    while(file >> number) {
        addition(total, number);
    }
    cout << "Full sum: " << total << "\n";
    cout << "First 10 digits: " << total.substr(0, 10) << '\n';
    return 0; 
}



