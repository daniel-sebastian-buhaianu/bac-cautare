#include <iostream>
#include <fstream>
#define NMAX 499
using namespace std;
ifstream fin("bac.txt");
int cb(int, int*, int);
int main()
{
    int n, i, v[NMAX+1], x, poz;
    fin >> n;
    for (i = 0; i < n; i++) fin >> v[i];
    fin >> x;
    fin.close();
    poz = cb(x, v, n);
    if (x == v[poz])
        cout << x;
    else if (poz == n || (x < v[poz] && poz > 0))
        cout << v[poz-1];
    else
        cout << "nu exista";
    return 0;
}
int cb(int x, int* v, int n)
{
    int st, dr, mij;
    st = -1, dr = n;
    while (dr-st > 1)
    {
        mij = st + (dr-st)/2;
        if (v[mij] < x)
            st = mij;
        else
            dr = mij;
    }
    return dr;
}
