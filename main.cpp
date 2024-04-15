#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
//Reimann sum formula
double Riemann_Calc(const vector<double>coefficient_number, double rectangles, double int_a, double int_b);

int main (int argc, char* argv[]){

ifstream fin; //beginning of ifstream


  vector<double>coefficient_number;
  string line;
  double rectangles;
  double int_a, int_b;
  bool n_located=false;
  //opening input file
  fin.open(argv[1]);
  while (getline(fin, line)){
//when reaches n file stops
    if (line=="n"){
      n_located = true;
    }
    else if (n_located==false){
      coefficient_number.push_back(stod(line));
    }
    else{
      //add vals to vectors
      rectangles = stod(line);
      getline(fin, line);
      //initalize var after reaching interval
      if (line=="interval"){
        getline(fin, line);
        int_a=stod(line);
        getline(fin,line);
       int_b=stod(line);
    }
  }
//end of while
  }
double area;
  //calling func
  area=Riemann_Calc(coefficient_number, rectangles, int_a, int_b);
  ofstream fout;
//opening output file
  fout.open("output.txt");
//getting ans
  fout<<"Answer: "<<area; 

  //closing files
  fin.close();
  fout.close();
  
  
  
}

//formula (func) implementation
double Riemann_Calc(const vector<double>coefficient_number, double rectangles, double int_a, double int_b){
  double width; 
  double area=0, fxi, xi;
  int i, x; 
  width=(int_b - int_a)/rectangles; 
  for(i=1; i<=rectangles; i++){
    xi = int_a + (i*width);
    fxi=0;
    for(x=0; x<coefficient_number.size(); x++){
      fxi+=coefficient_number[x]*pow(xi, coefficient_number.size()-1-x);
    }
    area+=fxi*width;
  }
  return area; 
}
