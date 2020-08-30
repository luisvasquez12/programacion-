#include <iostream>

using namespace std;

int ejLog(int a[5][6], int row, int col, int fin = 0, int start = 0, int retCol = 0) //Toca definir que fin, start y retCol son igual a 0 en la función ya que no funciona si se define despues.
{
    int nextCol;

    if(start > fin)
    {
        return 0;
    }  
    if(fin == 0)
    {
        fin = 5;
    }
        
    bool build = false;
    int middle = (start + fin)/2;

    for(int i = 0; i < col; i++)
    {
        if(a[middle][i] == 0)
        {
            build = true;

            if(middle == 0)
            {
                return i;
            }
            
            nextCol = ejLog(a, row, col, middle, start, retCol);

            if(nextCol < 0)
            {
                retCol = i;
            }   
            else
            {
                retCol = nextCol;
                break;
            }

        }
    }

    if(build == false && ((middle + fin)/2) == middle)
    {
        return 0;
    }
    if(build)
    {
        return retCol;
    }

    return ejLog(a, row, col, fin, middle, retCol);
}

int main()
{
    int city[5][6] =
    {
        {1, 1, 1, 0, 1, 1},
        {0, 1, 0, 0, 0, 1},
        {0, 1, 0, 0, 0, 1},
        {0, 1, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 1}
    };

    cout << ejLog(city, 5, 6) << endl;
}

