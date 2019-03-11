#include <iostream>
#include <chrono>
#include <fstream>
#include <sstream>
#include <boost/random/random_device.hpp>
#include <jsoncpp/json/json.h>
#include <string>
#include <cstring>
#include "funcs.h"

using namespace std::chrono;
#define SIZE (10000000)
#define SIZE_FUNC (6)

std::string selectMode(const char *nameFile){
    if (strcmp(nameFile, "./mainn") == 0) return "norm";
    else if (strcmp(nameFile, "./mainv") == 0) return "vec";
    else if (strcmp(nameFile, "./mainvx") == 0) return "mavx";
    else if (strcmp(nameFile, "./mainvx2") == 0) return "mavx2";
}

void destroy(double *a, double *b){
    delete a;
    delete b;
}

void randomGen(double *a, double *b){
    boost::random::random_device gen;
	const long int MAX = gen.max();

    for(int i = 0; i < SIZE; ++i) {
		a[i] = (double)gen()/MAX;
        b[i] = (double)gen()/MAX;
    }

}

int main(int argc, const char *argv[]){

    double *a{new double[SIZE]};
    double *b{new double[SIZE]};

    randomGen(a, b);
    auto mode = selectMode(argv[0]);
    

    std::ofstream myfile;
    std::stringstream ss;
    ss << "Tempo_" << mode << ".json";
    
    myfile.open(ss.str());
    
    Json::Value event;
  
    double result;
    
    std::string name;

    auto now = high_resolution_clock::now();
    
    for(int func = 0; func < SIZE_FUNC; ++func){
        for(unsigned long n = 10; n < SIZE; n += 500000){
            auto now = high_resolution_clock::now();
        
            switch (func){
                    
                case 0:
                    result = inner_prod(a, b, n);
                    name = "inner_prod";
                    break;
                
                case 1:
                    result = sum_positive(a, n);
                    name = "sum_positive";
                    break;

                case 2:
                    sqrt_element(a, n);
                    name = "sqrt_element";
                    break;

                case 3:
                    exp_element(a, n);
                    name = "exp_element";
                    break;

                case 4:
                    log_element(a, n);
                    name = "log_element";
                    break;

                case 5:
                    gauss(a, b, n);
                    name = "gauss";
                    break;        
                
                default:
                    return 0;
            } 

            auto end_time = duration_cast<duration<double>>(high_resolution_clock::now() - now).count();    
            std::stringstream sn;
            sn << name << "_" << mode;
            event[sn.str()][std::to_string(n)] = end_time;
        }
    }

    myfile << event <<std::endl;
    myfile.close();
    destroy(a, b);
}