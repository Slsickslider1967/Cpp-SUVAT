#include <iostream>
#include <list>
#include <cmath>

using namespace std;

int main();

double calculateS(string u, string v, string a, string t);
double calculateU(string s, string v, string a, string t);
double calculateV(string s, string u, string a, string t);
double calculateA(string s, string u, string v, string t);
double calculateT(string s, string u, string v, string a);
int main()
{
    string S; 
    string U;
    string V;
    string A;
    string T;
    
    char Wanted;

    bool run = true;

    while (run)
    {
        cout << "Welcome to the SUVAT Calc!" << endl;
        cout << "Please enter the variable you wish to calculate (S, U, V, A, T): \nOr enter X to quit: \n";
        cin >> Wanted;
        Wanted = toupper(Wanted);

        if (Wanted == 'S')
        {
            cout << "Designate the unknown as X" << endl;
            cout << "What is the value for U?: ";
            cin >> U;
            cout << "What is the value for V?: ";
            cin >> V;
            cout << "What is the value for A?: ";
            cin >> A;
            cout << "What is the value for T?: ";
            cin >> T;

            cout << "Calculating S..." << endl;

            double result = calculateS(U, V, A, T);
            cout << "The calculated value for S is: " << result << endl;
        }
        else if (Wanted == 'U')
        {
            cout << "Designate the unknown as X" << endl;
            cout << "What is the value for S?: ";
            cin >> S;
            cout << "What is the value for V?: ";
            cin >> V;
            cout << "What is the value for A?: ";
            cin >> A;
            cout << "What is the value for T?: ";
            cin >> T;

            cout << "Calculating U..." << endl;

            double result = calculateU(S, V, A, T);
            cout << "The calculated value for U is: " << result << endl;
        }
        else if (Wanted == 'V')
        {
            cout << "Designate the unknown as X" << endl;
            cout << "What is the value for S?: ";
            cin >> S;
            cout << "What is the value for U?: ";
            cin >> U;
            cout << "What is the value for A?: ";
            cin >> A;
            cout << "What is the value for T?: ";
            cin >> T;

            cout << "Calculating V..." << endl;

            double result = calculateV(S, U, A, T);
            cout << "The calculated value for V is: " << result << endl;
        }
        else if (Wanted == 'A' )
        {
            cout << "Designate the unknown as X" << endl;
            cout << "What is the value for S?: ";
            cin >> S;
            cout << "What is the value for U?: ";
            cin >> U;
            cout << "What is the value for V?: ";
            cin >> V;
            cout << "What is the value for T?: ";
            cin >> T;

            cout << "Calculating A..." << endl;

            double result = calculateA(S, U, V, T);
            cout << "The calculated value for A is: " << result << endl;
        }
        else if (Wanted == 'T')
        {
            cout << "Designate the unknown as X" << endl;
            cout << "What is the value for S?: ";
            cin >> S;
            cout << "What is the value for U?: ";
            cin >> U;
            cout << "What is the value for V?: ";
            cin >> V;
            cout << "What is the value for A?: ";
            cin >> A;

            cout << "Calculating T..." << endl;

            double result = calculateT(S, U, V, A);
            cout << "The calculated value for T is: " << result << endl;
        }
        else if (Wanted == 'X')
        {
            cout << "Exiting the program. Goodbye!" << endl;
            run = false;
        }
        else
        {
            cout << "Invalid input. Please enter S, U, V, A, or T." << endl;
        }


    }
    return 0;
}   

double calculateS(string u, string v, string a, string t)
{
    double U = 0, V = 0, A = 0, T = 0;

    if (u != "x" && u != "X")
        U = stod(u);
    
    if (v != "x" && v != "X")
        V = stod(v);
    
    if (a != "x" && a != "X")
        A = stod(a);
    
    if (t != "x" && t != "X")
        T = stod(t);
    
    // (when V is unknown)
    if (U != 0 && A != 0 && T != 0 && v == "x")
        return (U * T) + (0.5 * A * T * T);
    
    // (when U is unknown)
    else if (V != 0 && A != 0 && T != 0 && u == "x")
        return (V * T) - (0.5 * A * T * T);
    
    // (when T is unknown)
    else if (U != 0 && V != 0 && A != 0 && t == "x")
        return (V * V - U * U) / (2 * A);

    // (when A is unknown)
    else if (U != 0 && V != 0 && T != 0 && a == "x")
        return ((U + V) / 2) * T;
    //when all values are provided
    else if (U != 0 && A != 0 && T != 0)
        return (U * T) + (0.5 * A * T * T);
    else
        return 0;
}

double calculateU(string s, string v, string a, string t)
{
    double S = 0, V = 0, A = 0, T = 0;

    if (s != "x" && s != "X")
        S = stod(s);
    
    if (v != "x" && v != "X")
        V = stod(v);
    
    if (a != "x" && a != "X")
        A = stod(a);
    
    if (t != "x" && t != "X")
        T = stod(t);
    
    //when S is unknown
    if (V != 0 && A != 0 && T != 0 && s == "x")
        return (V - (A * T));
    //when V is unknown
    else if (S != 0 && A != 0 && T != 0 && v == "x")
        return (S - (0.5 * A * T * T)) / T;
    //when A is unknown
    else if (S != 0 && V != 0 && T != 0 &&  a == "x")
        return (2 * S) / T - V;  
    //when T is unknown
    else if (S != 0 && V != 0 && A != 0 && t == "x")
        return sqrt(V * V - (2 * A * S));
    //when all values are provided
    else if (V != 0 && A != 0 && T != 0)
        return V - (A * T);
    else
        return 0;
    
}

double calculateV(string s, string u, string a, string t)
{
    double S = 0, U = 0, A = 0, T = 0;

    if (s != "x" && s != "X")
        S = stod(s);
    
    if (u != "x" && u != "X")
        U = stod(u);
    
    if (a != "x" && a != "X")
        A = stod(a);
    
    if (t != "x" && t != "X")
        T = stod(t);
    
    //when S is unknown
    if (U != 0 && A != 0 && T != 0 && s == "x")
        return U + (A * T);
    //when U is unknown
    else if (S != 0 && A != 0 && T != 0 && u == "x")
        return (S - (0.5 * A * T * T)) / T + (A * T);
    //when A is unknown
    else if (S != 0 && U != 0 && T != 0 &&  a == "x")
        return (2 * S) / T - U + (A * T);  
    //when T is unknown
    else if (S != 0 && U != 0 && A != 0 && t == "x")
        return sqrt(U * U + (2 * A * S));
    //when all values are provided
    else if (U != 0 && A != 0 && T != 0)
        return U + (A * T);
    else
        return 0;
}

double calculateA(string s, string u, string v, string t)
{
    double S = 0, U = 0, V = 0, T = 0;

    if (s != "x" && s != "X")
        S = stod(s);
    
    if (u != "x" && u != "X")
        U = stod(u);
    
    if (v != "x" && v != "X")
        V = stod(v);
    
    if (t != "x" && t != "X")
        T = stod(t);
    
    //when S is unknown
    if (U != 0 && V != 0 && T != 0 && s == "x")
        return (V - U) / T;
    //when U is unknown
    else if (S != 0 && V != 0 && T != 0 && u == "x")
        return (2 * S) / T - V;  
    //when V is unknown
    else if (S != 0 && U != 0 && T != 0 && v == "x")
        return (2 * S) / T - U;  
    //when T is unknown
    else if (S != 0 && U != 0 && V != 0 && t == "x")
        return sqrt(V * V - U * U) / sqrt(2 * S);
    //when all values are provided
    else if (U != 0 && V != 0 && T != 0)
        return (V - U) / T;
    else
        return 0;
}

double calculateT(string s, string u, string v, string a)
{
    double S = 0, U = 0, V = 0, A = 0;

    if (s != "x" && s != "X")
        S = stod(s);
    
    if (u != "x" && u != "X")
        U = stod(u);
    
    if (v != "x" && v != "X")
        V = stod(v);
    
    if (a != "x" && a != "X")
        A = stod(a);
    
    //when S is unknown
    if (U != 0 && V != 0 && A != 0 && s == "x")
        return (V - U) / A;
    //when U is unknown
    else if (S != 0 && V != 0 && A != 0 && u == "x")
        return sqrt((2 * S) / A) - (V / A);  
    //when V is unknown
    else if (S != 0 && U != 0 && A != 0 && v == "x")
        return sqrt((2 * S) / A) - (U / A);
    //when A is unknown 
    else if (S != 0 && U != 0 && V != 0 && a == "x")
        return sqrt((2 * S) / ((V * V - U * U) / (2 * S))) - (U / ((V * V - U * U) / (2 * S)));
    //when all values are provided
    else if (U != 0 && V != 0 && A != 0)
        return (V - U) / A;
    else
        return 0;
}   