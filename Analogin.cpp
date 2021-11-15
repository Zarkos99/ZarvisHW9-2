#include "Analogin.h"
#include<sstream>
#include<fstream>
using std::stringstream;
using std::fstream;


Analogin::Analogin(){
   this->number = 0;
}

Analogin::Analogin(unsigned int n){
   this->number = n;
}

void Analogin::setNumber(unsigned int n){
   this->number = n;
}

int Analogin::readADCsample(){
   stringstream ss;
   ss << ADC_PATH << this->number << "_raw";
   int val;
   fstream fs;
   fs.open(ss.str().c_str(), fstream::in);
   fs >> val;
   fs.close();
   return val;
}

Analogin::~Analogin(){

}
