#include <iostream>
#include <string>

int main(){
    int space_count = 20, total_blocks = 6;
    std::string spaces = "", symbols = ".";

    for(int row=0; row<total_blocks; row++){ 
        for(int i=0; i<row; i++){
            for(int space=0; space<space_count; space++){spaces += " ";}
            std::cout << spaces << symbols << std::endl;
            spaces = "";
            space_count -= 1;
            symbols += "..";
        }

        for(int i=0; i<row; i++){
            for(int space=0; space<space_count; space++){spaces += " ";}
            std::cout << spaces << symbols << std::endl;
            spaces = "";
            space_count += 1;
            symbols = symbols.substr(0, symbols.size()-2);
        }
    }
    return 0;
}
