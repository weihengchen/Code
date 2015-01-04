#include <iostream>
using namespace std;

int main()
{
    int t = 1, n;
    int r1, r2;
    int card1[4][4], card2[4][4];
    int i, j, k, ans = 0;
    cin>>n;
    while (t <= n) {
        cout<<"Case #"<<t<<": ";
        cin>>r1;
        for (i = 0; i < 4; i++) {
            for (j = 0; j < 4; j++) {
                cin>>card1[i][j];
            }
        }
        cin>>r2;
        for (i = 0; i < 4; i++) {
            for (j = 0; j < 4; j++) {
                cin>>card2[i][j];
            }
        }
        k = 0;
        ans = -1;
        for (i = 0; i < 4; i++) {
            for (j = 0; j < 4; j++) {
                if (card1[r1-1][i] == card2[r2-1][j]) {
                    k++;
                    ans = card1[r1-1][i];
                }
            }
        }
        if (k > 1) 
            cout<<"Bad magician!"<<endl;
        else if (k == 0) 
            cout<<"Volunteer cheated!"<<endl;
        else
            cout<<ans<<endl;
        t++;
    }
    return 0;
}
