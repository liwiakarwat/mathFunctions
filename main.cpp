#include <iostream>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include <vector>
#include "mathFun.h"
#include <limits>

using namespace std;

int main()
{
    //return chosen row in Pascal's triangle
    cout << "Enter row number: ";
    int rowP;               //row number
    cin >> rowP;
    vector<long long int> pascal = pascalTriangle(rowP);
    for(int i =0;i<=rowP;i++)
        cout << pascal[i] << " ";
    cout << endl;

    // calculate area of triangle by Heron formula
    cout << "Enter the length of the triangles sides: ";
    double A, B, C;            //length of the triangles sides
    cin >> A >> B >> C;
    cout << HeronFormula(A, B, C) << endl;
    cout << endl;

    //calculate solution to equation
    cout << "Give me a, b, c of ax^2 + bx + c = 0: ";
    double a, b, c;
    cin >> a >> b >> c;
    pair<double,double> deltaResoult = delta(a, b, c);
    if(deltaResoult.first!=numeric_limits<double>::max())
        cout << "x1 = " << deltaResoult.first << " x2 = " << deltaResoult.second << endl;

    //compresses sets to the least of them needed
    vector<pair<double,double> > sets, compressedStes;
    int amount;
    cout << "Enter amount of sets to compress: ";
    cin >> amount;
    double fst, sec;
    cout << "Enter range of each set: ";
    for(int i =0;i<amount;i++)
    {
        cin >> fst >> sec;
        sets.push_back(make_pair(fst,sec));
    }
    compressedStes = compressSets(sets);
    for(int i =0;i<compressedStes.size();i++)
        cout << i+1 << " set "<<compressedStes[i].first << " " << compressedStes[i].second<< endl;

    //calculates x and y form 2 equations
    double a1, A1, b1, B1, c1, C1;
    cout << "Enter a, b, c of ax + by = c: ";
    cin >> a1 >> b1 >> c1;
    cout << "Enter A, B, C of Ax + By = C: ";
    cin >> A1 >> B1 >> C1;
	pair<double, double> resoultXY = calcTwoUnknowns(a1, b1, c1, A1, B1, C1);
	if(resoultXY.first == numeric_limits<double>::max())
        cout << "x = " << resoultXY.first << " y = " << resoultXY.second<< endl;

    return 0;
}
