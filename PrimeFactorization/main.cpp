#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

bool is_prime(const int n){
    
    bool is_p = true;
    
    for(int i=2; i<sqrt(n)+1; i++){
        
        if(n % i == 0 and i != n){
            is_p = false;
            break;
        }
    }
    
    return is_p;
}

void prime_factorization(int n){
    
    int n_copy = n;
    bool is_prime_found = false;
    vector<int> prime_factors;
    
    while(true){
        
        is_prime_found = false;
        
        for(int i=2; i<n; i++){
            if(n % i == 0){
               if(is_prime(i)){
                   prime_factors.push_back(i);
                   
                   n = static_cast<int>(n / i);
                   is_prime_found = true;
                   break;
               }
            }
        }
        
        if(!is_prime_found){
            prime_factors.push_back(n);
            break;
        }
    }
    
    cout << "Prime Factors: ";
    for(unsigned int i=0; i<prime_factors.size(); ++i){
        cout << prime_factors.at(i) << ", ";
    }
    
    return;
}

int main(){
    
    int num = 0;
    
    cout << "Enter a natural number: ";
    cin >> num;
    
    prime_factorization(num);
    
    return 0;
}
