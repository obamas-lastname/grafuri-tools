#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>

using namespace std;

ifstream fin("input.in");

int n, m, a[101][101], i, j, g[101], L[101], p=0;
int x[105], // coada pentru parcurgerea in latime
    v[105]; // vector caracteristic care precizeaza daca un varf a fost sau nu vizitat


void bf(int varf, int nrc)
{
    int st, dr;
    st = dr = 1;
    v[varf] = nrc;
    x[1] = varf;
    while(st <= dr)
    {
        int k = x[st];
        for(int i = 1; i <= n ; ++i)
            if(v[i] == 0 && a[k][i] == 1)
            {
                dr ++;
                v[i] = nrc;
                x[dr] = i;
            }
        st ++;
    }
}

/*void m_input()
{
    fin>>n>>m;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)

}
*/
void muchii_input()
{
    int i , j;
    fin >> n;
    while(fin >> i >> j)
    {
        a[i][j] = a[j][i] = 1;
    }
    cout<<"Graf citit."<<endl;
}

void comp_conexe()
{
    int i , j;
    int nrc = 0;
    for(int i=1; i <= n ;++i)
        if(v[i] == 0 )
        {
            nrc ++;
            bf(i , nrc);
        }
    cout << nrc << " Componente conexe:" << endl;
    for(int i=1 ; i<= nrc ; ++i)
    {
        for(int j = 1; j<= n ;++j)
            if(v[j] == i)
                cout << j << " ";
        cout << endl;
    }
}

void comp_conexe2()
{
    int i , j;
    int nrc = 0;
    for(int i=1; i <= n ;++i)
        if(v[i] == 0 )
        {
            nrc ++;
            bf(i , nrc);
        }
    cout << nrc-1 << " Muchii trebuie adaugate:" << endl;
    for(int i = 2; i<=nrc ; i++)
    {
        int varf = 0;
        for(int j = 1 ; j <= n && varf == 0 ; ++j)
            if(v[j] == i)
                varf = j;
        cout << 1 << " " << varf << endl;
    }
}

void grade()
{
    int i , j;
    for(int i = 1 ;  i <= n ; i++){
        g[i] = 0;
        for(int j = 1; j <= n ; ++j)
            if(a[i][j] == 1)
                g[i] ++;
    }

    for(int i = 1 ;  i <= n ; i++)
        cout << g[i] << " ";
}

void afis_matrice()
{
    for(int i=1;i<=n;i++)
    {
       for(int j=1;j<=n;j++)
            cout<<a[i][j]<<" ";

        cout<<endl;
    }

}

void Euler(int k)
{
    for(int i = 1 ; i <= n ; i ++)
        if(a[k][i] == 1)
        {
            a[k][i] = a[i][k] = 0;
            Euler(i);
        }
    L[++p] = k;
}

void este_euler()
{
    Euler(1);
    cout << p << " Varfuri in acest ciclu eulerian: \n";
    for(int i =1 ; i <= p ; i ++)
        cout << L[i] << " ";
}

void afis_menu()
{
    cout<<" Ce vrei sa faci cu graful? Alege optiunea:"<<endl;
    cout<<" 1) Afiseaza componente conexe "<<endl;
    cout<<" 2) Afiseaza ce muchii ar trebui adaugate pentru ca graful sa fie conex "<<endl;
    cout<<" 3) Afiseaza gradul fiecarui varf "<<endl;
    cout<<" 4) Afiseaza matricea de adiacenta "<<endl;
    cout<<" 5) Afiseaza ciclu eulerian "<<endl;
}

int main() {
    int r;
    muchii_input();
    afis_menu();
    cin>>r;
    switch (r){
    case 1:
        comp_conexe();
        break;

    case 2:
        comp_conexe2();
        break;

    case 3:
        grade();
        break;

    case 4:
        afis_matrice();
        break;

    case 5:
        este_euler();
        break;
    }
    return 0;
}
