#include <iostream>
#include <iomanip>
using namespace std;

void greetUser();
void add(int a, int b);
void subtract(int a, int b);
void multiply(int a, int b);
void divide(int a, int b);
void fahrenheitToCelsius(float f);
void celsiusToFahrenheit(float c);
void dollarsToPesos(float dollars);
void pesosToDollars(float pesos);

int main() 
{
    int choice, subChoice;
    int a, b;
    float f, c, dollars, pesos;

    cout << fixed << setprecision(2);
    greetUser();

    do {
        cout << "\n1. Arithmetic Operations (Add, Subtract, Multiply, Divide)" << endl;
        cout << "2. Temperature Conversion (Fahrenheit <-> Celsius)" << endl;
        cout << "3. Currency Conversion (Dollar <-> Peso)" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice (1–4): ";
        cin >> choice;

        switch(choice) 
        {
            case 1:
                cout << "--- ARITHMETIC OPERATIONS ---" << endl;
                cout << "1. Add" << endl;
                cout << "2. Subtract" << endl;
                cout << "3. Multiply" << endl;
                cout << "4. Divide" << endl;
                cout << "Enter your choice (1–4): ";
                cin >> subChoice;

                cout << "Enter two integers: ";
                cin >> a >> b;

                switch (subChoice) 
                {
                    case 1: add(a, b); break;
                    case 2: subtract(a, b); break;
                    case 3: multiply(a, b); break;
                    case 4: divide(a, b); break;
                    default: cout << "Invalid arithmetic choice!" << endl;
                }
                break;

            case 2:
                cout << "--- TEMPERATURE CONVERSION ---" << endl;
                cout << "1. Fahrenheit to Celsius" << endl;
                cout << "2. Celsius to Fahrenheit" << endl;
                cout << "Enter your choice (1–2): ";
                cin >> subChoice;

                if (subChoice == 1) {
                    cout << "Enter Fahrenheit temperature: ";
                    cin >> f;
                    fahrenheitToCelsius(f);
                }
                else if (subChoice == 2) {
                    cout << "Enter Celsius temperature: ";
                    cin >> c;
                    celsiusToFahrenheit(c);
                }
                else {
                    cout << "Invalid temperature choice!" << endl;
                }
                break;

            case 3:
                cout << "--- CURRENCY CONVERSION ---" << endl;
                cout << "1. Dollars to Pesos" << endl;
                cout << "2. Pesos to Dollars" << endl;
                cout << "Enter your choice (1–2): ";
                cin >> subChoice;

                if (subChoice == 1) {
                    cout << "Enter amount in Dollars: ";
                    cin >> dollars;
                    dollarsToPesos(dollars);
                } 
                else if (subChoice == 2) {
                    cout << "Enter amount in Pesos: ";
                    cin >> pesos;
                    pesosToDollars(pesos);
                } 
                else {
                    cout << "Invalid currency choice!" << endl;
                }
                break;

            case 4:
                cout << "Thank you for using the program. Goodbye!" << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 4);

    return 0;
}

void greetUser() {
    cout << "Welcome to the Multi-Function Calculator!" << endl;
}

void add(int a, int b) {
    cout << "Sum: " << (a + b) << endl;
}

void subtract(int a, int b) {
    cout << "Difference: " << (a - b) << endl;
}

void multiply(int a, int b) {
    cout << "Product: " << (a * b) << endl;
}

void divide(int a, int b) {
    if (b != 0)
        cout << "Quotient: " << (a / float(b)) << endl;
    else
        cout << "Error: Cannot divide by zero!" << endl;
}

void fahrenheitToCelsius(float f) {
    float c = (f - 32) * 5 / 9;
    cout << f << "°F = " << c << "°C" << endl;
}

void celsiusToFahrenheit(float c) {
    float f = (c * 9 / 5) + 32;
    cout << c << "°C = " << f << "°F" << endl;
}

void dollarsToPesos(float dollars) {
    float pesos = dollars * 58.46; 
    cout << dollars << " Dollars = " << pesos << " Pesos" << endl;
}

void pesosToDollars(float pesos) {
    float dollars = pesos / 58.46;
    cout << pesos << " Pesos = " << dollars << " Dollars" << endl;
}



