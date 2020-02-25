class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mymap; //��¼ÿ���ַ�������λ�� 
        int maxn=0, cnt=0;
        int i=0, sp=0; //sp��¼��ǰ�Ӵ��Ŀ�ʼλ�ã����ڴ����ڵ�ǰ�Ӵ������Ǵ�����map�е��ַ� 
        while(i<s.size()){
            if(mymap.find(s[i])!=mymap.end() && mymap[s[i]]>=sp){ //find && mymap[s[i]]>=sp
                cnt=i-mymap[s[i]];
                sp=mymap[s[i]]+1;
            }
            else{ //not find || mymap[s[i]]<sp
                cnt++;
            }
            mymap[s[i]]=i;
            maxn=maxn>cnt?maxn:cnt;
            i++;
        }
        return maxn;
    }
};
