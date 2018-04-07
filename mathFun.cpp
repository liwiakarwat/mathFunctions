#include <iostream>
#include <utility>
#include <cmath>
#include <vector>
#include <limits>

using namespace std;

long long int factorial(int number)
{
	int result = 1;
	if (number == 0)
		return 1;
	else
		for (int i = 1; i <= number; i++)
			result *= i;
	return result;
}

/////////////////////////////////////////

vector<long long int>  pascalTriangle(int row)
{
    vector<long long int> v;
	int number;
	for (int i = 0; i <= row; i++)
	{
	    // using binomial theorem, counts selected row in pascal triangle
		number = 0;
		number = (factorial(row)) / (factorial(row - i)*factorial(i));
		v.push_back(number);
	}
    return v;
}

/////////////////////////////////////////

double HeronFormula(double a, double b, double c)
{
	double area;
	area = (sqrt((a + b + c)*(a + b - c)*(a - b + c)*(-a + b + c))) / 4;
	return area;
}

/////////////////////////////////////////

pair<double, double> delta(double a, double b, double c)
{
	double delta;
	delta = (b*b - 4 * a*c);
	double x1 = numeric_limits<double>::max(), x2 = numeric_limits<double>::max();
	pair<double, double> x;
	if (delta<0)
	{
		cout << "Doesn't exist" << endl;
		x = make_pair(x1, x2);
		return x;
	}
	else {
		delta = sqrt(delta);
		x1 = (-b + delta) / (2 * a);
		x2 = (-b - delta) / (2 * a);
		x = make_pair(x1, x2);
		return x;
	}
}


/////////////////////////////////////////

vector<pair<double, double> > compressSets(vector<pair<double, double> > sets)
{
	vector<pair<double, double> > resoult;
	if (sets.empty())
	{
		cout << "Set is empty!";
		return resoult;
	}
	resoult.push_back(sets[0]);
	for (int i = 1; i<sets.size(); i++)
	{
	    // compression algorithm
		for (int j = 0; j<resoult.size(); j++)
		{
			if (resoult[j].first <= sets[i].first)
			{
				if (resoult[j].second >= sets[i].first)
				{
					if (resoult[j].second<sets[i].second)
					{
						resoult[j].second = sets[i].second;
					}
				}
				else resoult.push_back(make_pair(sets[i].first, sets[i].second));
			}
			else
			{
				if (resoult[j].first <= sets[i].second)
				{
					if (resoult[j].second<sets[i].second)
					{
						resoult[j].first = sets[i].first;
						resoult[j].second = sets[i].second;
					}
					else resoult[j].first = sets[i].first;
				}
				else resoult.push_back(make_pair(sets[i].first, sets[i].second));

			}
		}
	}
	return resoult;
}

/////////////////////////////////////////

pair<double,double> calcTwoUnknowns(double a,double  b,double  c,double  A,double  B,double  C)
{
    pair<double,double> falseResoult = make_pair(numeric_limits<double>::max(),numeric_limits<double>::max());
    double detMain, detX, detY;
    detMain = (a*B)-(A*b);
    detX = (c*B)-(C*b);
    detY = (a*B)-(A*b);
    if(detMain == 0)
    {
        if(detX!=0||detY!=0)
        {
            cout<< "There isn't any solution :(" << endl;
            return falseResoult;
        }
        cout << "There is infinity number of solution." << endl;
        return falseResoult;
    }
    double x = detX/detMain, y = detY/detMain;
    pair<double,double> resoult = make_pair(x,y);
    return resoult;
}
