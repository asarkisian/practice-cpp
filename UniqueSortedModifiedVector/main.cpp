#include <iostream>
#include <vector>

using namespace std;

void displayNumbers(const vector<int> n){
  
  for(int i=0; i<n.size(); i++){
    cout << n.at(i) << endl;
  }
  
  return;
}

void removeDuplicateNumbers(vector<int>& n){
  
  for(int x=n.size() - 1; x>=0; x--){
    for(int y=n.size() - 1; y>=0; y--){
      if(x != y){
        if(n.at(x) == n.at(y)){
          n.erase(n.begin() + x);
        }
      }
    }
  }
  
  return;
}

void sortNumbers(vector<int>& n){
  int temp=0;
  
  for(int x=0; x<n.size(); x++){
    for(int y=0; y<n.size(); y++){
      if(n.at(x) < n.at(y)){
        temp = n.at(x);
        n.at(x) = n.at(y);
        n.at(y) = temp;
      }
    }
  }
  
  return;
}

void removeEvenNumbers(vector<int>& n){
  
  for(int i=n.size() - 1; i>= 0; i--){
    if(n.at(i)%2 == 0){
      n.erase(n.begin() + i);
    }
  }
  
  return;
}

int main(){
  
  vector<int> numbers(20);
  
  numbers.at(0) = 3;
  numbers.at(1) = 2;
  numbers.at(2) = 6;
  numbers.at(3) = 3;
  numbers.at(4) = 9;
  numbers.at(5) = 8;
  numbers.at(6) = 2;
  numbers.at(7) = 6;
  numbers.at(8) = 5;
  numbers.at(9) = 1;
  numbers.at(10) = 4;
  numbers.at(11) = 7;
  numbers.at(12) = 7;
  numbers.at(13) = 10;
  numbers.at(14) = 1;
  numbers.at(15) = 4;
  numbers.at(16) = 3;
  numbers.at(17) = 3;
  numbers.at(18) = 2;
  numbers.at(19) = 0;
  
  removeDuplicateNumbers(numbers);
  sortNumbers(numbers);
  removeEvenNumbers(numbers);
  displayNumbers(numbers);
  
  return 0;
}
