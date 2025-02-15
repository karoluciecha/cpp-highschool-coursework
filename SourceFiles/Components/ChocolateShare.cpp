#include <iostream>
#include <string>

using namespace std;

int canBreakOffPieces(int k, int m, int n)
{
    int x = 0;
    int y = 0;
    int i = 0;

    // Check if we can break off k pieces by making vertical cuts
    while (x < k && i < m)
    {
        x += n;
        i++;
    }
    if (x == k)
    {
        cout << "You can break off " << k << " pieces of chocolate.";
        return 0;
    }

    i = 0;
    // Check if we can break off k pieces by making horizontal cuts
    while (y < k && i < n)
    {
        y += m;
        i++;
    }
    if (y == k)
    {
        cout << "You can break off " << k << " pieces of chocolate.";
        return 0;
    }
    else
    {
        cout << "It is not possible to break off exactly " << k << " pieces of chocolate.";
        return 0;
    }
}

void runChocolateShareProgram()
{
    int k, m, n = 0;
    char answer;
    cout << "WELCOME TO THE MILKA ALPINE CHOCOLATE PROGRAM!";

    do
    {
        do
        {
            cout << "\n\nEnter the length of side A of the chocolate bar: ";
            cin >> m;
        } while (m < 1 || m > 1000000);

        do
        {
            cout << "Enter the length of side B of the chocolate bar: ";
            cin >> n;
        } while (n < 1 || n > 1000000);

        do
        {
            cout << "Enter the number of chocolate pieces to break off: ";
            cin >> k;
        } while (k < 1 || k > 1000000); // Fixed the incorrect condition

        canBreakOffPieces(k, m, n);

        cout << "\n\nDo you want to run the program again? (Y/N): ";
        cin >> answer;
    } while (answer == 'Y' || answer == 'y');

    cout << "\nThank you, come again!\n";
}