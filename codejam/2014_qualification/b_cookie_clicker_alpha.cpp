#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int t = 1, n;
    double c, f, x;
    int i, j;
    cin>>n;
    while (t <= n) {
        cin>>c>>f>>x;
        double min_cost, cum = 0, tmp;
        int cum_cl = 0;
        min_cost = x/2;
        for (i = 0; ; i++) {
            cum += c/(2+cum_cl*f);
            cum_cl++;
            tmp = x/(2+cum_cl*f) + cum;
            if (min_cost < tmp)
                break;
            min_cost = tmp;
        }
        printf("Case #%d: %.7f\n", t, min_cost);
        t++;
    }
    return 0;
}
