/*******************************************************************************
 * Name        : largesum.cpp
 * Author      : Ciaran Walsh, Lynsey Overturf, Ashley Qian
 * Version     : 1.0
 * Date        : July 13, 2026
 * Description : Solution to Project Euler #13 - Large Sum (Modified)
 *               https://projecteuler.net/problem=13
 ******************************************************************************/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int maxSpots = 55;

void addition(int colSums[], const string& number) {
    int col = 0;
    int placeInd = number.size();
    while(placeInd > 0){
        placeInd--;
        colSums[col] = colSums[col] + (number[placeInd] - '0');
        col++;
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
    string total;
    int colSums[maxSpots] = {};

    while(file >> number) {
        addition(colSums, number);
    }
    carry(colSums);
    total = writeAns(colSums);

    cout << "Full sum: " << total << "\n";
    cout << "First 10 digits: " << total.substr(0, 10) << '\n';
    return 0; 
}
