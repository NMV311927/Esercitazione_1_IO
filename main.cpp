#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;


// rescaling function
double res(double x) {
    return( (3.0/4.0)*x-(7.0/4.0));
}


// recursive mean function
double rem(double xn, double x, double n){
    return( (1.0/n) * ((n-1.0)*xn + x) );
}


// read from file and process
int main() {
    ifstream file("data.txt");
    ofstream ofile("result.txt");

    if (!file){
        cerr << "Error opening file" << endl;
        return 1;
    }

    if (ofile.is_open()){
        ofile << "# N" << " Mean" << endl;
    
        string line;
        double n=1.0;
        double xn=0.0;

        while (getline(file,line)){
            double num;
            stringstream ss(line);
            ss >> num;
            double x=res(num);

            if (n==1) {
                xn=x;
            } else { 
                xn=rem(xn,x,n);
            }
       
            ofile << n << " " << xn << endl;
            n++;
        }
        
    }

    file.close();
    ofile.close();
    return 0;
}

