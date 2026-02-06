#include <iostream>
#include <vector>
using namespace std;

class Math
{
    public:

    void calculateDerivative()
    {
        // Take user input for degree of the polynomial
        int polynomialDegree;
        vector<int> coefficients, powers;
        cout << "Enter the degree of the polynomial: ";
        cin >> polynomialDegree;
        coefficients.assign(polynomialDegree, 0);
        powers.assign(polynomialDegree, 0);

        // Take user input of coefficients of x in the polynomial
        cout << "Enter the " << polynomialDegree << " coefficient(s) of x in the polynomial: " << endl;
        for (int i = 0; i < polynomialDegree; i++)
        {
            powers[i] = polynomialDegree - i - 1;
            cout << "Coefficient of x_" << i << ": ";
            cin >> coefficients[i];
            
            // Output test
            /*
            cout << "Coefficient of x_" << i << ": " << coefficients[i] << endl;
            cout << "Power of x_" << i << ": x^" << powers[i] << endl;
            */
        }

        // Arrage initial function
        int tempCoefficient = coefficients[0];
        cout << endl << "f(x) = ";
        for (int j = 0; j < polynomialDegree; j++)
        {
            if (j > 0)
            {
                tempCoefficient = coefficients[j] < 0 ? -coefficients[j] : coefficients[j];
                cout << ((coefficients[j] < 0) ? "- " : "+ ");
            }
        
            if (powers[j] > 1)
            {
                cout << tempCoefficient << "x^" << powers[j] << " ";
            }
            else if (powers[j] == 1)
            {
                cout << tempCoefficient <<  "x ";
            }
            else
            {
                cout << tempCoefficient;
            }
        }
        cout << endl;

        // Calculate derivative of f(x)
        int newCoefficient, newPower;
        cout << "f'(x) = ";
        for (int d = 0; d < polynomialDegree; d++)
        {
            newCoefficient = coefficients[d] * powers[d];
            newPower = powers[d] - 1 < 0 ? 0 : powers[d] - 1;
        
            if (d > 0)
            {
                newCoefficient = coefficients[d] < 0 ? -newCoefficient : newCoefficient;

                if (newPower == 0 && newCoefficient == 0)
                {
                    cout << "";
                }
                else
                {
                    cout << ((coefficients[d] < 0) ? "- " : "+ ");
                }
            }

            if (newPower > 1)
            {
                cout << newCoefficient  << "x^" << newPower << " ";
            }
            else if (newPower == 1)
            {
                cout << newCoefficient  << "x ";
            }
            else
            {
                if (newCoefficient != 0)
                {
                    cout << newCoefficient;
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
            
            if (sum == 0)
            {
                if (coefficient == 1 && power == 1)
                {
                    cout << i;
                }
            }
            else
            {
                if (power == 1 && coefficient != 1)
                {
                    cout << coefficient << "(" << i << ")";
                }
                else if (power != 1 && coefficient == 1)
                {
                    cout << "(" << i << ")^" << power;
                }
                else
                {
                    cout << coefficient << "(" << i << ")^" << power;
                }
                
            }


            if (i != max - 1)
            {
                cout << " + ";
            }
        }
        cout << " = " << sum << endl;
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

    //math.calculateDerivative();
    math.calculateSummation();
    //program.terminate();
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