#include <iostream>
#include <string>
using namespace std;

class TempConverter
{

public:
    double CelsuisToFahrenheit(double celsius)
    {
        return (celsius * 9.0 / 5.0)+32.0;
    }

    double CelsuisToKelvin (double celsius)
    {
        return celsius + 273.15;
    }

    double FahrenheitToCelsuis(double fahrenheit)
    {
        return (fahrenheit - 32.0) * 5.0 / 9.0;
    }

    double FahrenheitToKelvin(double fahrenheit)
    {
        return (fahrenheit + 459.67) * 5.0 / 9.0;
    }

    double KelvinToCelsius(double kelvin)
    {
        return kelvin - 273.15;
    }

    double KelvinToFahrenheit(double kelvin)
    {
        return (kelvin * 9.0 / 5.0) - 459.67;
    }
};



int main()
{
    double temperature;
    char unit;
    TempConverter converter;

    cout << "Enter temperature value: ";
    cin >> temperature;
    cout << "Enter the unit of the temperature (C-Celsius,F-Fahrenheit,K-Kelvin)";
    cin >> unit;

    switch (unit)
    {
    case 'c':
    case 'C':
        cout << "Temperature in Fahrenheit: " << converter.CelsuisToFahrenheit(temperature) << " F" << endl;
        cout << "Temperature in Kelvin: " << converter.CelsuisToKelvin(temperature) << " K" << endl;
        break;

    case 'f':
    case 'F':
        cout << "Temperature in Celsius: " << converter.FahrenheitToCelsuis(temperature) << " C" << endl;
        cout << "Temperature in Kelvin: " << converter.FahrenheitToKelvin(temperature) << " K" << endl;
        break;

    case 'k':
    case 'K':
        cout << "Temperature in Celsius: " << converter.KelvinToCelsius(temperature) << " C" << endl;
        cout << "Temperature in Fahrenheit: " << converter.KelvinToFahrenheit(temperature) << " F" << endl;
        break;

    default:
        cout << "Invalid unit entered." << endl;
    }





    return 0;
}

