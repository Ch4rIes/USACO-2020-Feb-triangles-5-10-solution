#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL, LL> pii;
typedef pair<LL, LL> pll;
typedef pair<string, string> pss;
typedef vector<LL> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef vector<LL> vl;
typedef vector<vl> vvl;

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}

bool cmp(pair<LL , LL> a , pair<LL , LL > b){
    return a.second < b.second;
}

int main() {
    setIO("triangles");
    LL N; cin >> N;
    vector<pair<LL, LL>> sortedX;
    vector<pair<LL, LL>> sortedY;
    vector<vector<LL>> byX(20002);
    vector<vector<LL>> byY(20002);
    for(LL i = 0 ; i < N ; i++){
        LL x , y;
        cin >> x >> y;
        x += 10003; y+=10003;
        byX[x].push_back(y);
        byY[y].push_back(x);// cout<<"N"<<endl;
//        sortedX.push_back(make_pair(x , y));
//        sortedY.push_back(make_pair(x , y));
    }
//    sort(sortedX.begin() , sortedX.end());
//    sort(sortedY.begin() , sortedY.end() , cmp);
    LL sum = 0;

    for(LL i = 0 ; i < byY.size() ; i++){
        if(byY[i].size() > 1) {
            for (LL j = 0; j < byY[i].size(); j++) {
                for (LL h = j + 1; h < byY[i].size(); h++) {
                    LL base = abs(byY[i][j] - byY[i][h]);
                    if (byX[byY[i][j]].size() >= 1) {
                        for (LL m : byX[byY[i][j]]) {
                            sum += abs(i - m) * base;
                        }
                    }
                    if (byX[byY[i][h]].size() >= 1) {
                        for (LL m : byX[byY[i][h]]) {
                            sum += abs(i - m) * base;
                        }
                    }
                }
            }
        }
    }
    cout << sum %(1000000007)<<endl;
}