#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{
    int t = 1, n;
    cin>>n;
    int num;
    int i, j;
    double tmp;
    vector<double> nao, ken;
    int war, dewar;
    while (t <= n) {
        cin>>num;
        nao.clear();
        ken.clear();
        for (i = 0; i < num; i++) {
            cin>>tmp;
            nao.push_back(tmp);
        }
        for (i = 0; i < num; i++) {
            cin>>tmp;
            ken.push_back(tmp);
        }
        sort(nao.begin(), nao.end());
        sort(ken.begin(), ken.end());
        war = 0;
        for (i = 0, j = 0; i < num && j < num;) {
            if ( nao[i] <= ken[j]) {
                i++;
                j++;
            } else {
                while (j < num && nao[i] > ken[j]) j++;
            }
        }
        war = num-i;
        dewar = 0;
        for (i = 0, j = 0; i < num && j < num;) {
            if (nao[i] > ken[j]) {
                i++;
                j++;
                dewar++;
            } else {
                while (i < num && nao[i] <= ken[j]) i++;
            }
        }
        cout<<"Case #"<<t<<": "<<dewar<<" "<<war<<endl;
        t++;
    }
    return 1;
}
