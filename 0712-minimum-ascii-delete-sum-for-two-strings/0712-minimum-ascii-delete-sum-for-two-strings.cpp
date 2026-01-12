class Solution {
    private :
    int t[1001][1001];
public:
    int minimumDeleteSum(string s1, string s2) {
        int n1=s1.size(), n2=s2.size();
        long asci=0;
       memset(t,-1,sizeof(t));
        t[n1][n2]=0;
        for(int j=n2-1;j>=0;j--){
            t[n1][j]=s2[j]+t[n1][j+1];
        }
        for(int i=n1-1;i>=0;i--){
            t[i][n2]=s1[i]+t[i+1][n2];
        }


        for(int i=n1-1;i>=0;i--){
            for(int j=n2-1;j>=0;j--){
                
                if(s1[i]==s2[j]){
                    t[i][j]=t[i+1][j+1];
                    
                }
                else{
                    t[i][j]=min(s1[i]+t[i+1][j],s2[j]+t[i][j+1]);
                }
            }
        }
        return  t[0][0];
    }
};