#include <iostream>
using namespace std;

struct Hetman
{
    int x;
    int y;
};

bool Bije(Hetman hetman1, Hetman hetman2)
{
    if (hetman1.x == hetman2.x)
    {
        return true;
    }
    else if (hetman1.y == hetman2.y)
    {
        return true;
    }
    else if (hetman1.x + hetman2.y == hetman1.y + hetman2.x)
    {
        return true;
    }
    else if (hetman1.x + hetman1.y == hetman2.y + hetman2.x)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void wypelnil(int rozmiar, Hetman listaHetmanow[], int poziom, int DontUseThatX)
{
    bool czyDodano = false;
    for (int i = 0; i < rozmiar; i++)
    {
        Hetman h;
        h.x = i;
        h.y = poziom;
        bool byloBicie = false;
        for (int j = 0; j < poziom; j++)
        {
            if (Bije(h, listaHetmanow[j]))
            {
                byloBicie=true;
                break;
            }
        }
        if ((byloBicie==false) && (DontUseThatX != i))
        {
            czyDodano=true;
            listaHetmanow[poziom] = h;
            cout << h.x << ", " << h.y << endl;
            break;
        }
        
    }
    if (czyDodano)
    {
        if (poziom+1 == rozmiar)
        {
            exit;
        }
        wypelnil(rozmiar, listaHetmanow, poziom+1, -1);
    }
    else
    {
        wypelnil(rozmiar, listaHetmanow, poziom-1, listaHetmanow[poziom-1].x);
    }    
}

int main()
{
    int rozmiar;
    cin >> rozmiar;
    Hetman listaHetmanow[rozmiar];
    wypelnil(rozmiar, listaHetmanow, 0, -1);
    //Bije(hetman1, hetman2);
}