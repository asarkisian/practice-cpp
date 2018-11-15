#include <algorithm>
#include <iostream>                                                      
#include <string>
#include <sstream>

int main(){                                                              
    int space_count = 20, total_blocks = 6;                          
    std::string spaces = "", output = "", symbols = ".", symbols2 = "";  
    
    for(int row=0; row<total_blocks; row++){  
        for(int i=0; i<row; i++){
          if(i==0){ symbols += ">";}
          for(int space=0; space<space_count; space++){spaces += " ";}
          std::cout << spaces << "<" << symbols << std::endl;                 
          symbols.erase(std::remove(symbols.begin(), symbols.end(), '>'), symbols.end());
          spaces = "", space_count -= 1, symbols += "..>";
        }
        for(int i=0; i<row; i++){
          output = spaces + "<";
          for(int space=0; space<space_count; space++){spaces += " ";}
          if(i==0){
            symbols2 = symbols;
            if(row % 2 == 0){std::replace(symbols2.begin(), symbols2.end(), '.', '\"');}
            else{std::replace(symbols2.begin(), symbols2.end(), '.', ':');}
            std::ostringstream row_s;
            row_s << row;
            symbols2.at(symbols2.length() / 2 - 1) = row_s.str().at(0);        
            output += symbols2;  
          }
          else{output += symbols;}
          std::cout << spaces << output << std::endl;
          spaces = "", space_count += 1;
          symbols.erase(std::remove(symbols.begin(), symbols.end(), '>'), symbols.end());
          symbols = symbols.substr(0, symbols.size()-2); 
          if(row-i!=1){symbols += ">";}
        }
    }
    return 0;
}
