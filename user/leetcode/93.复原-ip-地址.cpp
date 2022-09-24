/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原 IP 地址
 */

// @lc code=start
class Solution
{
public:
    vector<string> restoreIpAddresses(string s)
    {
        vector<string> res;
        int loc = 0;
        int len = s.size();
        int num1, num2, num3, num4;
        int temp;
        string str1, str2, str3, str4;
        for(int i=1; i<4 && loc+i<=len; i++)
        {
            for(int j=1; j<4 && loc+i+j<=len; j++)
            {
                for(int k=1; k<4 && loc+i+j+k<=len; k++)
                {
                    for(int m=1; m<4 && loc+i+j+k+m<=len; m++)
                    {
                        // 截取四个段 每个段最多取 3 个字符
                        str1 = s.substr(loc, i);
                        str2 = s.substr(loc+i, j);
                        str3 = s.substr(loc+i+j, k);
                        str4 = s.substr(loc+i+j+k, m);
                        // 长度不符 不要
                        if(loc+i+j+k+m != len)    continue;
                        // 多余前导 0 不要
                         if(i != 1 && str1[0] == '0')    continue;
                        if(j != 1 && str2[0] == '0')    continue;
                        if(k != 1 && str3[0] == '0')    continue;
                        if(m != 1 && str4[0] == '0')    continue;
                        // string 转 int
                        num1 = stoi(str1);
                        num2 = stoi(str2);
                        num3 = stoi(str3);
                        num4 = stoi(str4);
                        // 最大超过 255 不要
                        temp = max(max(num1, num2), max(num3, num4));
                        if(temp > 255)  continue;

                        // 以上所有条件符合 存答案
                        res.push_back(str1+"."+str2+"."+str3+"."+str4);
                    }
                }
            }
        }
        return res;
    }
};
// @lc code=end
