#include <iostream>
#include <vector>
using namespace std;

class Math
{
    public:

    void calculateDerivative()
    {
        // Take user input for degree of the polynomial

        int polyDegree;
        vector<int> coeffs, powers;
        cout << "Enter the degree of the polynomial: ";
        cin >> polyDegree;
        coeffs.assign(polyDegree, 0);
        powers.assign(polyDegree, 0);

        // Take user input of coefficients of x in the polynomial
        cout << "Enter the " << polyDegree << " coefficient(s) of x in the polynomial and its constant: " << endl;
        for (int i = 0; i <= polyDegree; i++)
        {
            powers[i] = polyDegree - i;

            if (i == polyDegree)
            {
                cout << "Constant: ";
            }
            else
            {
                cout << "Coefficient of x_" << i << ": ";
            }

            cin >> coeffs[i];
        }

        // Arrage initial function

        int tempCoeff = coeffs[0];
        cout << endl << "f(x) = ";
        for (int j = 0; j <= polyDegree; j++)
        {
            if (j > 0)
            {
                tempCoeff = fabs(coeffs[j]);
                cout << ((coeffs[j] < 0) ? "- " : "+ ");
            }
        
            if (powers[j] > 1)
            {
                cout << tempCoeff << "x^" << powers[j] << " ";
            }
            else if (powers[j] == 1)
            {
                cout << tempCoeff <<  "x ";
            }
            else
            {
                cout << tempCoeff;
            }
        }
        cout << endl;

        // Calculate derivative of f(x)

        int newCoeff, newPower;
        bool isZero = false;
        cout << "f'(x) = ";
        for (int d = 0; d < polyDegree; d++)
        {
            newCoeff = powers[d] * coeffs[d];
            newPower = powers[d] - 1 < 0 ? 0 : powers[d] - 1;

            if (d > 0 || newCoeff == 0)
            {
                if (((newPower == 0 || newPower > 0) && newCoeff == 0) || (coeffs[d - 1] == 0 && newCoeff != 0))
                {
                    cout << "";
                }
                else
                {
                    cout << (coeffs[d] < 0 ? "" : "+ ");
                }
            }

            if (newPower > 1)
            {
                if (newCoeff == 0)
                {
                    cout << "";
                }
                else
                {
                    cout << newCoeff << "x^" << newPower << " ";
                }
            }
            else if (newPower == 1)
            {
                if (newCoeff == 0)
                {
                    cout << "";
                }
                else
                {
                    cout << newCoeff << "x ";
                }
            }
            else
            {
                if (newCoeff != 0)
                {
                    cout << newCoeff;
                }
            }
        }
        cout << endl;
    }

    void calculateSummation()
    {
        int min, max, coefficient, power, sum = 0;

        cout << "Enter the minimum range of values to calculate: ";
        cin >> min;
        cout << "Enter the maximum range of values to calculate: ";
        cin >> max;
        cout << "Enter the coefficient of i: ";
        cin >> coefficient;
        cout << "Enter the power of i: ";
        cin >> power;

        for (int i = min; i < max; ++i)
        {
            sum += coefficient * pow(i, power);
            
            if (sum == 0 || (coefficient == 1 && power == 1))
            {
                cout << i;
            }
            else
            {
                cout << coefficient << "(" << i << ")^" << power;
            }


            if (i != max - 1)
            {
                cout << " + ";
            }
        }
        cout << " = " << sum;
    }
};

class Program
{
    public:

    void terminate()
    {
        int var;
        cout << endl << "Enter any key + ENTER to terminate the program...";
        cin >> var;
    }
};

int main()
{
    Math math;
    Program program;

    math.calculateDerivative();
    //math.calculateSummation();
    program.terminate();
    return 0;
}


// pascal's triangle

/*
    vector<vector<int>> matrix(rows, vector<int>(rows, 0)); // allocated matrix

    for (int n = 0; n < rows; n++)
    {
        int columns = n + 1;
        for (int k = 0; k < columns; k++)
        {
            matrix[n][k] = k == 0 || k == n ? 1 : matrix[n - 1][k - 1] + matrix[n - 1][k];
            cout << matrix[n][k] << " ";
        }
        cout << endl;
    }
    */