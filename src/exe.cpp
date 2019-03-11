#include <iostream>
#include <string>
#define SIZE_VECTOR (4)

int main(){
    const char* listExes[SIZE_VECTOR] = {"./mainn", "./mainv", "./mainvx", "./mainvx2"};
    for(int i = 0; i < SIZE_VECTOR; ++i){
        system((const char*)listExes[i]);
        std::cout << listExes[i] << std::endl;
    }

}