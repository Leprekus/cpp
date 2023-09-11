#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int main () {

    string text;
    ifstream inputFile("./input.txt");

    vector<int> caloriesArray;
    vector< vector<int> > result;
    vector<int> calorie_sums;
  
      while (getline (inputFile, text)) {
    // Output the text from the file
        if(text.empty()){ 

          result.push_back(caloriesArray);
          caloriesArray.clear();

         } else {
          caloriesArray.push_back(stoi(text));
         }
      }
    
      for(int i = 0; i < result.size(); i++) {

        vector<int> foods = result[i];
        int total_calories = 0;

        for(int z = 0; z < foods.size(); z++) {
          int calories = foods[z];
          total_calories += calories;
        }
        calorie_sums.push_back(total_calories);
        total_calories = 0;

      }
    
      int current_max = 0; 
      for(int c = 0; c < calorie_sums.size(); c++) {
        
        int food_cals = calorie_sums[c];
        if(food_cals > current_max) {
          current_max = food_cals;
        }
      }
      cout << current_max;


    
    return 0;
}