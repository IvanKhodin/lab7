#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

double func(double x)    //True reshenie uravneniya
{
    return (1.0 / 40) * (8 * pow(M_E, 2 * x) + (5 * pow(M_E, 2 * x) - 11) * sin(x) + (37 - 5 * pow(M_E, 2 * x)) * cos(x));
  
} 


double F(double x, double y1, double y2, double y3, int number)       //F(x,yn)
{
    switch (number)
    {
    case 1:
        return (2 * y1 - y1 * x + y1 * x * x + 4 * pow(M_E, (2 * x)) * sin(x) / 25 + 3 * pow(M_E, (2 * x)) * cos(x) / 25 + 3 * x / 5 - 53 / 25);
        break;
    case 2:
        return (2 * y2 - y1 + 2 * y1 * x + pow(M_E, (2 * x)) * sin(x) / 5 + 2 * pow(M_E, (2 * x)) * cos(x) / 5 + 3 / 5);
        break;
    case 3:
        return ( 2 * y3 - y2 + 2 * y1 + cos(x) * pow(M_E, (2 * x)));
        break;
    }
}


int main() {

    ofstream f("points.txt");

    const int n = 20;

    double a = 0; double b = 2; double h = 0.1;
    
    double X;
    double Y1[n+1], Y2[n+1], Y3[n+1];

    double k1[4];
    double k2[4];
    double k3[4];
    double k4[4];
    double k5[4];

    double E[4] = { 0,0,0,0 };
    double e = 0.01;

    int l = 0;
    int t = 1;
    
    for (int j = 0; j < 21; j++) {
        Y1[j] = 0;
        Y2[j] = 0;
        Y3[j] = 0;
    }

    X = a;
    Y1[0] = 1;
    Y2[0] = 0;
    Y3[0] = 0;

    while (X <= b) {

        l++;
        
        for (int i = 1;i <= 3;i++) {
            k1[i] = F(X, Y1[i - 1], Y2[i - 1], Y3[i - 1], i) / 3;
            k2[i] = F(X + h / 3, Y1[i - 1] + h * k1[i], Y2[i - 1] + h * k1[i], Y3[i - 1] + h * k1[i], i) / 3;
            k3[i] = F(X + h / 3, Y1[i - 1] + h * k1[i] / 2 + h * k2[i] / 2, Y2[i - 1] + h * k1[i] / 2 + h * k2[i] / 2, Y3[i - 1] + h * k1[i] / 2 + h * k2[i] / 2, i) / 3;
            k4[i] = F(X + h / 2, Y1[i - 1] + h * k1[i] * 3 / 8 + h * k3[i] * 9 / 8, Y2[i - 1] + h * k1[i] * 3 / 8 + h * k3[i] * 9 / 8, Y3[i - 1] + h * k1[i] * 3 / 8 + h * k3[i] * 9 / 8, i) / 3;
            k5[i] = F(X + h, Y1[i - 1] + h * k1[i] * 3 / 2 - h * k3[i] * 9 / 2 + h * k4[i] * 6, Y2[i - 1] + h * k1[i] * 3 / 2 - h * k3[i] * 9 / 2 + h * k4[i] * 6, Y3[i - 1] + h * k1[i] * 3 / 2 - h * k3[i] * 9 / 2 + h * k4[i] * 6, i) / 3;
            E[i] = h * (k1[i] - 9 * k3[i] / 2 + 4 * k4[i] - k5[i] / 2);
            //cout << k1[i] << " " << k2[i] << " " << k3[i] << " " << k4[i] << " " << k5[i] << " " << E[i] << endl;
        }

        Y1[l] = Y1[l - 1] + h * (k1[1] + 4 * k4[1] + k5[1]) / 2;
        Y2[l] = Y2[l - 1] + h * (k1[2] + 4 * k4[2] + k5[2]) / 2;
        Y3[l] = Y3[l - 1] + h * (k1[3] + 4 * k4[3] + k5[3]) / 2;
        
        /*
        if ((E[1] > 5 * e) && (E[2] > 5 * e) && (E[3] > 5 * e)) {
            h = h / 2;
            cout << "------" << endl;
        }
        else if ((E[1] < 5 * e / 32) && (E[2] < 5 * e / 32) && (E[3] < 5 * e / 32)) {
            h = h * 2;
            cout << "++++++" << endl;
        }
        */

        X += h;

    }
    
    cout << endl << "y(x):" << endl << endl;

    for (int i = 0; i < n; i++) {
        cout << "Y1[" << i / 10.0 << "]=" << Y1[i] << endl;
    }
    
    cout << endl <<  "y'(x):" << endl << endl;

    for (int i = 0; i < n; i++) {
        cout << "Y2[" << i / 10.0 << "]=" << Y2[i] << endl;
    }

    cout << endl << "True reshenie:" << endl << endl;
    for (int i = 0; i < n; i++) {
        X = i / 10.0;
        cout << "Y[" << X << "]=" << func(X) << endl;
    }

    for (int i = 0; i < n; i++)
        f << i / 10.0 << " " << Y1[i] << " " << Y2[i] << endl;


    return 0;

}