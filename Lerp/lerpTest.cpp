#include <iostream>
#include <cmath>

int main(){
    int x = 0;
    int target = 10;
    while(x != target){
        std::cout << x << std::endl;
        x = std::lerp(x, target, 0.1f);
    }
    return 0;
}