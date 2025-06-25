class Solution {
public:
    vector<int> res;
    map<int, int> frequencia;
    vector<int> recoverArray(int n, vector<int>& somas) {
        sort(somas.begin(), somas.end());
        solve( somas);
        return res;
    }
    
    void solve(vector<int>& somas){
        //Caso Base
        if(somas.size() == 2){
            res.push_back(somas[0]+somas[1]);
            return;
        }
        bool contemZero = false;
        vector<int> v1;
        vector<int> v2;
        int diferenca = somas[1]-somas[0];
        for(int i = 0; i < somas.size(); i++){
            if(!frequencia[somas[i]]){
                v1.push_back(somas[i]);
                frequencia[somas[i]+diferenca]++;
                if(somas[i]==0) contemZero = true;
            }
            else {
                v2.push_back(somas[i]);
                frequencia[somas[i]]--;
            }
        }
        if(contemZero){
            res.push_back(diferenca);
            solve(v1);
        }
        else {
            res.push_back(-diferenca);
            solve(v2);
        }
    }
};