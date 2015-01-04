#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int digit_cal(unsigned long long num) {
    int count;
    for (count = 0; num; count++)
        num &= num-1;
    return count;
}
int main()
{
    int t = 1, n;
    scanf("%d", &n);
    int num, len;
    int i, j;
    char dig[50];
    vector<unsigned long long> origin, final;
    map<unsigned long long, int> map_num2int;
    unsigned long long tmp;
    int ans;
    while (t <= n) {
        scanf("%d%d", &num, &len);
        origin.clear();
        final.clear();
        ans = 10000;
        map_num2int.clear();
        for (i = 0; i < num; i++) {
            scanf("%s", dig);
            tmp = 0;
            for (j = 0; dig[j] != 0; j++)
                tmp = (tmp<<1) + dig[j]-'0';
            origin.push_back(tmp);
        }
        for (i = 0; i < num; i++) {
            scanf("%s", dig);
            tmp = 0;
            for (j = 0; dig[j] != 0; j++)
                tmp = (tmp<<1) + dig[j]-'0';
            final.push_back(tmp);
            map_num2int[tmp] = 0;
        }
        for (i = 0; i < final.size(); i++) {
            tmp = origin[0]^final[i];
            for (j = 1; j < origin.size(); j++) {
                unsigned long long k = ((~(origin[j]&tmp))&tmp)|(origin[j]&(~tmp));
                if (map_num2int.find(k) == map_num2int.end())
                    break;
            }
            if (j == origin.size()) {
                if (ans > digit_cal(tmp))
                    ans = digit_cal(tmp);
            }
        }
        cout<<"Case #"<<t<<": ";
        if (ans == 10000) {
            cout<<"NOT POSSIBLE"<<endl;
        } else {
            cout<<ans<<endl;
        }
        t++;
    }
    return 1;
}
