class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
      //  vector<int>suff(n,0);
    
      int area=0;
        // for(int i=0;i<n;i++){
        //     int curr_dep=min(depth,height[i]);

        //    area=max((i-idx)*curr_dep,area);

        //    if(depth<height[i]){
        //     idx=i;depth=height[i];
        //    }
           
        // }

        
        int i=0;
        int j=height.size()-1;
        while(i<j){
            area=max(area,(j-i)*min(height[i],height[j]));
            if(height[i]<height[j]){
                i++;
            }else{
                j--;
            }
        }

        return area;
    }
};