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
        cout << "Please enter the variable you wish to calculate (S, U, V, A, T): ";
        cin >> Wanted;

        if (Wanted == 'S')
        {
            cout << "Designate the unknown as X" << endl;
            cout << "What is the vlaue for U?: ";
            cin >> U;
            cout << "What is the vlaue for V?: ";
            cin >> V;
            cout << "What is the vlaue for A?: ";
            cin >> A;
            cout << "What is the vlaue for T?: ";
            cin >> T;

            cout << "Calculating S..." << endl;

            double result = calculateS(U, V, A, T);
            cout << "The calculated value for S is: " << result << endl;
        }
        else if (Wanted == 'U')
        {
            cout << "Designate the unknown as X" << endl;
            cout << "What is the vlaue for S?: ";
            cin >> S;
            cout << "What is the vlaue for V?: ";
            cin >> V;
            cout << "What is the vlaue for A?: ";
            cin >> A;
            cout << "What is the vlaue for T?: ";
            cin >> T;

            cout << "Calculating U..." << endl;

            double result = calculateU(S, V, A, T);
            cout << "The calculated value for U is: " << result << endl;
        }
        else if (Wanted == 'V')
        {
            // Calculate V
        }
        else if (Wanted == 'A' )
        {
            // Calculate A
        }
        else if (Wanted == 'T')
        {
            // Calculate T
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