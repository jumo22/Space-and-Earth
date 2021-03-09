#include <iostream>
#include <fstream>
//Iulia Moroti 1231A
using namespace std;
int binarySearch(int c[], int l, int r, int fuel, int start){
    if (r >= l){
        int mid = l + (r - l) / 2;
        if ( (fuel >= c[mid]) && (fuel < c[mid + 1]) )
            return mid+1;
        if (fuel == c[mid]){
            int ans = mid + 1;
            for (int i = mid + 1; i <= r; i++){
                if (fuel == c[i])
                    ans = i + 1;
                if (fuel < c[i])
                    break;
            }
            return ans;
        }
        if (fuel < c[mid])
            return binarySearch(c, l, mid - 1, fuel, start);
        return binarySearch(c, mid + 1, r, fuel, start);
    }
    return start;
}

int planning(int start, int* planets, int* iplanets, int n, int fuelav){
    int ansclck, anscclck, endp = 2 * n - 1, cfuel, ccfuel;
     if (start == 0){
        ansclck = binarySearch(planets, start, endp, fuelav, start) + 1;
        anscclck = binarySearch(iplanets, start, endp, fuelav, start) + 1;
     }
    else{
        cfuel = planets[start - 1] + fuelav;
        ccfuel = iplanets[n - start - 1] + fuelav;
        ansclck = binarySearch(planets, start, endp, cfuel, start) - start + 1;
        anscclck = binarySearch(iplanets, n - start, endp, ccfuel, n - start) - (n - start) + 1;
    }
    if (ansclck > n)
        ansclck = n;
    if (anscclck > n)
        anscclck = n;
    int ans = max(ansclck, anscclck);
    return ans;
}

int main()
{
    ifstream spacein("space.in");
    if (!spacein) {
        cerr << "No such file found.";
        return -1;
    }
    ofstream spaceout("space.out");
    int line_no=1;
    string line;
    int n, t, start, fuelav;
    spacein >> n >> t;
    line_no++;
    /*if (n > 10000){
        spaceout << "Limit of planets exceeded, leaving this solar system is strictly forbidden.\n";
        return -1;
    }*/
    int planets[2 * n] = {0};
    int iplanets[2 * n] = {0};

    while (getline(spacein, line) && (line_no < t + 3)){
        if (line_no == 2){
            for (int i = 0; i < n; i++){
                spacein >> planets[i];
                }
            for (int i = 0; i < n; i++){
                planets[i + n] = planets[i];
            }

            for (int i = (2 * n - 1), j = 0; i >= 0; i-- && j++){
                iplanets[j] = planets[i];
            }
            for (int i = 0; i < 2 * n; i++){
                planets[i + 1] += planets[i];
                iplanets[i + 1] += iplanets[i];
                }
            line_no++;
        }
        else{
            spacein >> start >> fuelav;
            spaceout << planning(start, planets, iplanets, n, fuelav) << "\n";
            line_no++;
        }
    }
    spaceout.close();
    return 0;
}
