/*
����һ���򵥴����¼����Сģ�飬�ܹ���¼����Ĵ������ڵ��ļ����ƺ��кš�
����:
1.��¼���8�������¼������ͬ�Ĵ����¼(���ļ����ƺ��к���ȫƥ��)
  ֻ��¼һ��������������ӣ�(�ļ����ڵ�Ŀ¼��ͬ���ļ������к���ͬҲҪ�ϲ�)
2.����16���ַ����ļ����ƣ�ֻ��¼�ļ��������Ч16���ַ���
 (����ļ�����ͬ����ֻ���ļ����ĺ�16���ַ����к���ͬ��Ҳ��Ҫ�ϲ�)
3.������ļ����ܴ�·������¼�ļ����Ʋ��ܴ�·��
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
        unsigned int f = input.rfind('\\'); // rfind�ַ����Ӻ���ǰ��'\'.
        file = input.substr(f + 1); // ��f+1λ�ÿ�ʼ��ȡ�ַ���
        errors.push_back(make_pair(file, 1));
     // ͳ�ƴ����¼�����ظ������ۼӣ������ظ�����һ����¼������
        for(int i = 0; i < (errors.size() - 1); i++) {
            if (errors[i].first == file) {
                errors[i].second++;
                errors.pop_back(); //ɾȥ�ظ�������ĩ�˵ļ�¼
                break ;
            }
        }
    }
    // �����������ȶ�����ֻ����ǰ8����¼
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
