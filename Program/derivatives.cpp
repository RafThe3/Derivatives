#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int rows;
    cout << "Enter the degree of the polynomial: ";
    cin >> rows;
    
    vector<int> coefficients(rows, 0), powers(rows, 0);
    cout << "Enter the coefficients of x in the polynomial: ";
    for (int i = 0; i < rows; i++)
    {
        cin >> coefficients[i];
        cout << "Coefficient of x_" << i << ": " << coefficients[i] << endl;
        powers[i] = rows - i - 1;
        cout << "Powers: x^" << powers[i] << endl;
    }

    int tempCoefficient = coefficients[0];
    cout << "f(x) = ";
    for (int j = 0; j < rows; j++)
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

    int newCoefficient, newPower;
    cout << "f'(x) = ";
    for (int d = 0; d < rows; d++)
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