#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int t = 1, n;
    int r, c, m;
    int i, j;
    int ans = 1;
    char matrix[50][50];
    cin>>n;
    while (t <= n) {
        cin>>r>>c>>m;
        ans = 1;
        for (i = 0; i < r; i++) {
            for (j = 0; j < c; j++) {
                matrix[i][j]='*';
            }
        }
        int re = r*c - m;
        if (re == 1) {
            matrix[0][0]='c';
        } else if (r >= 3 && c >= 3) {
            if (re%2 == 0) {
                if (re < 4) ans = -1;
                else {
                    re-=4;
                    for (i = 0; i < 2; i++) {
                        matrix[0][i] = '.';
                        matrix[1][i] = '.';
                    }
                    for (i = 2; i < r && re > 0; i++) {
                        re-=2;
                        matrix[i][0] = '.';
                        matrix[i][1] = '.';
                    }
                    for (i = 2; i < c && re > 0; i++) {
                        re-=2;
                        matrix[0][i] = '.';
                        matrix[1][i] = '.';
                    }
                    if (matrix[2][2] == '.')
                        re+=1;
                    for (i = 2; i < r && re > 0; i++) {
                        for (j = 2; j < c && re > 0; j++) {
                            matrix[i][j] = '.';
                            re--;
                        }
                    }
                }
            } else if (re < 9) {
                ans = -1;
            } else {
                for (i = 0; i < 3; i++) {
                    matrix[0][i] = '.';
                    matrix[1][i] = '.';
                    matrix[2][i] = '.';
                }
                re -= 9;
                for (i = 3; i < r && re > 0; i++) {
                    re-=2;
                    matrix[i][0] = '.';
                    matrix[i][1] = '.';
                }
                for (i = 3; i < c && re > 0; i++) {
                    re-=2;
                    matrix[0][i] = '.';
                    matrix[1][i] = '.';
                }
                re+=1;
                for (i = 2; i < r && re > 0; i++) {
                    for (j = 2; j < c && re > 0; j++) {
                        matrix[i][j] = '.';
                        re--;
                    }
                }
            }
        } else if (r == 1 || c == 1) {
            if (r == 1) {
                for(i = 0; i < c && re > 0; i++, re--)
                    matrix[0][i] = '.';
            } else {
                for(i = 0; i < r && re > 0; i++, re--)
                    matrix[i][0] = '.';
            }
        } else {
            if (re%2 == 1 || re < 4)
                ans = -1;
            else {
                matrix[0][0]='.';
                matrix[1][0]='.';
                matrix[0][1]='.';
                matrix[1][1]='.';
                re-=4;
                if (r == 2) {
                    for (j = 2; j < c && re > 0; j++) {
                        re-=2;
                        matrix[0][j]='.';
                        matrix[1][j]='.';
                    }
                } else {
                    for (i = 2; i < r && re > 0; i++) {
                        re-=2;
                        matrix[i][0]='.';
                        matrix[i][1]='.';
                    }
                }
            }
        }
        matrix[0][0]='c';
        cout<<"Case #"<<t<<":"<<endl;
        if (ans == -1)
            cout<<"Impossible"<<endl;
        else {
            for (i = 0; i < r; i++) {
                for (j = 0; j < c; j++) {
                    cout<<matrix[i][j];
                }
                cout<<endl;
            }
        }
        t++;
    }
    return 0;
}
