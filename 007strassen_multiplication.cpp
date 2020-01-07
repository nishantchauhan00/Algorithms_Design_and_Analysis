#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include <string.h>

using namespace std;

int main()
{
    int a = 1, b = 2, c = 3, d = 4, e = 5, f = 6, g = 7, h = 8;
    // | a b | e f |   1: a(e-h)    2: (a+b)h    3: (c+d)e    4: d(g-e)
    // | c d | g h |   5: (a+d)(e+h)    6: (b-d)(g+h)    7: (a-c)(e+f)
    int p[8];
    p[1] = a * (e - h);
    p[2] = (a + b) * h;
    p[3] = (c + d) * e;
    p[4] = d * (g - e);
    p[5] = (a + d) * (e + h);
    p[6] = (b - d) * (g + h);
    p[7] = (a - c) * (e + f);

    int ans[4];
    ans[0] = (p[4] + p[5] + p[6] - p[2]);
    ans[1] = (p[1] + p[2]);
    ans[2] = (p[3] + p[4]);
    ans[3] = (p[1] + p[5] - p[3] - p[7]);
    cout << "Product of strassen multiplication: \n"
         << ans[0] << "\t" << ans[1] << "\n"
         << ans[2] << "\t" << ans[3];

    return 0;
}