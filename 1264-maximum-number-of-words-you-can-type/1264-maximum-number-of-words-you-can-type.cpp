class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        int cnt=0;
        int words=0;
        int n=text.size();

        for(int i=0;i<text.size();i++){
            string word="";
            int bad=0;
            while(i<n && text[i]!=' '){
                word+=text[i];
                if(brokenLetters.find(text[i])!=string::npos){
                    bad++;
                }
                i++;
            }
            words++;
            if(bad>0)cnt++;
        }
        return words-cnt;

    }
};