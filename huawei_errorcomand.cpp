/*
开发一个简单错误记录功能小模块，能够记录出错的代码所在的文件名称和行号。
处理:
1.记录最多8条错误记录，对相同的错误记录(即文件名称和行号完全匹配)
  只记录一条，错误计数增加；(文件所在的目录不同，文件名和行号相同也要合并)
2.超过16个字符的文件名称，只记录文件的最后有效16个字符；
 (如果文件名不同，而只是文件名的后16个字符和行号相同，也不要合并)
3.输入的文件可能带路径，记录文件名称不能带路径
*/
#include<bits/stdc++.h>
using namespace std;
bool compare(pair<string, int> a, pair<string, int> b){
    return a.second  > b.second;
}
int main() {
    string input,file;
    vector<pair<string, int>> errors;
    while (getline(cin, input)) {
        if (input.size() == 0)
            break;
        unsigned int f = input.rfind('\\'); // rfind字符串从后往前找'\'.
        file = input.substr(f + 1); // 从f+1位置开始截取字符串
        errors.push_back(make_pair(file, 1));
     // 统计错误记录，若重复计数累加，若不重复新增一条记录在容器
        for(int i = 0; i < (errors.size() - 1); i++) {
            if (errors[i].first == file) {
                errors[i].second++;
                errors.pop_back(); //删去重复的容器末端的记录
                break ;
            }
        }
    }
    // 按数量进行稳定排序，只保留前8个记录
    stable_sort(errors.begin(), errors.end(), compare);
    int idx = 0;
    while (idx < 8 && idx < errors.size()) {
        string check = errors[idx].first;
        int t = check.find(' ');
        if (t > 16) {
            errors[idx].first.erase(0, t - 16);
        }
        cout << errors[idx].first <<' '<<errors[idx].second <<endl;
        idx++;
    }
}

/* input
E:\V1R2\product\fpgadrive.c 1325
*/

/* output
fpgadrive.c 1325 1
*/
