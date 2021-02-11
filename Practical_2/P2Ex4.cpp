#include <iostream> 
using namespace std;

int main()
{
    int r, nbr = 1;
    cout << "Enter number of rows of Floyd's triangle: ";
    cin >> r;

    for(int i = 1; i <= r; i++)
    {
        for(int j = 1; j <= i; ++j){
          cout << nbr << " ";
          ++nbr;
        }

        cout << endl;
    }

    return 0; 
}
