#include <iostream>
using namespace std;

long long zajebistyLicznik = 0;

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

bool **zrobTablice(int rozmiar)
{
    bool **teZle;
    teZle = new bool *[rozmiar];
    for (int i = 0; i < rozmiar; i++)
    {
        teZle[i] = new bool[rozmiar];
    }
    for (int i = 0; i < rozmiar; i++)
    {
        for (int j = 0; j < rozmiar; j++)
        {
            teZle[i][j] = false;
        }
    }
    return teZle;
}

bool wypelnil(int rozmiar, Hetman *listaHetmanow, int poziom, bool **teZle)
{
    zajebistyLicznik++;
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
                byloBicie = true;
                break;
            }
        }
        if ((byloBicie == false) && (!teZle[i][poziom]))
        {
            czyDodano = true;
            listaHetmanow[poziom] = h;
            break;
        }
    }

    if (czyDodano)
    {
        if (poziom + 1 == rozmiar)
        {
            return false;
        }
        wypelnil(rozmiar, listaHetmanow, poziom + 1, teZle);
    }
    else
    {
        for (int i = 0; i < rozmiar; i++)
        {
            teZle[i][poziom] = false;
        }
        teZle[listaHetmanow[poziom - 1].x][poziom - 1] = true;
        wypelnil(rozmiar, listaHetmanow, poziom - 1, teZle);
    }
    return false;
}

void wydrukujHetmanuf(int rozmiar, Hetman listaHetmanow[])
{
    for (int i = 0; i < rozmiar; i++)
    {
        cout << listaHetmanow[i].x << ", " << listaHetmanow[i].y << endl;
    }
    
}

int main()
{
    int rozmiar;
    cin >> rozmiar;
    bool **teZle = zrobTablice(rozmiar);
    Hetman *listaHetmanow=new Hetman[rozmiar];
    wypelnil(rozmiar, listaHetmanow, 0, teZle);
    // Bije(hetman1, hetman2);
    wydrukujHetmanuf(rozmiar, listaHetmanow);
    cout << "zajebisty licznik policzył do: " << zajebistyLicznik << endl;
}