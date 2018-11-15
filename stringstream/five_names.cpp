#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main(int argc, char** argv){
  
  stringstream stream;
  string temp = "";
  
  // 5 names combined
  
  for(int i = 0; i < 5; i++)
  {
    cout << "Enter a name: ";
    getline(cin, temp);
    
    stream << temp;
    stream << ", ";
  }
  
  cout << "Stream: " << stream.str() << endl;
  
  return(EXIT_SUCCESS);
}
