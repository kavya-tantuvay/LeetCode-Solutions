class Solution {
public:
    void h(vector<vector<int>>& image){
        int n=image.size();
        for(int i=0;i<n;i++){
            auto it=image[i];
            reverse(it.begin(),it.end());
            image[i]=it;
        }
    }
    void i(vector<vector<int>>& image){
        int n=image.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)image[i][j]=1-image[i][j];
        }
    }
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        h(image);
        i(image);
        return image;
    }
};