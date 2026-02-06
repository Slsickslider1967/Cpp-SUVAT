#include <cmath>
#include <string>

using namespace std;

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
    //when V is unknown - use quadratic formula: S = Ut + 0.5*A*t^2
    // Rearranged: 0.5*A*t^2 + U*t - S = 0
    // t = (-U + sqrt(U^2 + 2*A*S)) / A
    else if (S != 0 && U != 0 && A != 0 && v == "x")
    {
        double discriminant = U * U + 2 * A * S;
        if (discriminant < 0)
            return 0; // No real solution
        return (-U + sqrt(discriminant)) / A;
    }
    //when A is unknown 
    else if (S != 0 && U != 0 && V != 0 && a == "x")
        return sqrt((2 * S) / ((V * V - U * U) / (2 * S))) - (U / ((V * V - U * U) / (2 * S)));
    //when all values are provided
    else if (U != 0 && V != 0 && A != 0)
        return (V - U) / A;
    else
        return 0;
}   