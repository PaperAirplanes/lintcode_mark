/*
�˿�����Ϸ���Ӧ�ö��Ƚ���Ϥ�ˣ�һ������54����ɣ���3~A��2��4�ţ�С��1�ţ�
����1�š������С�����������ַ����ַ�����ʾ�����У�Сдjoker��ʾС����
��дJOKER��ʾ������:)
3 4 5 6 7 8 9 10 J Q K A 2 joker JOKER
���������ƣ�������֮���á�-�����ӣ�ÿ���Ƶ�ÿ�����Կո�ָ���
��-������û�пո��磺4 4 4 4-joker JOKER
��Ƚ������ƴ�С������ϴ���ƣ���������ڱȽϹ�ϵ�����ERROR

��������
��1������ÿ���ƿ����Ǹ��ӣ����ӣ�˳�ӣ�����5�ţ���������ը�����ĸ����Ͷ����е�һ�֣����������������
     �����뱣֤�����ƶ��ǺϷ��ģ�˳���Ѿ���С�������У�
��2������ը���Ͷ������Ժ������ƱȽ�֮�⣬�������͵���ֻ�ܸ���ͬ���͵Ĵ��ڱȽϹ�ϵ
    ���磬���Ӹ����ӱȽϣ������������Ƚϣ��������ǲ���������磺�����Ӳ�ֳɸ��ӣ�
��3����С��������ƽʱ�˽�ĳ���������ͬ�����ӣ����ӣ������Ƚ������С��
     ˳�ӱȽ���С�ƴ�С��ը������ǰ�����е��ƣ�ը��֮��Ƚ������С�������������ƣ�
��4������������Ʋ��������ȵ������

����ʾ��
��1������ը���Ͷ���֮�⣬��������ͬ���ͱȽϡ�
��2�������Ѿ���֤�Ϸ��ԣ����ü�������Ƿ��ǺϷ����ơ�
��3�������˳���Ѿ�������С����������˲�����������.
*/
#include <bits/stdc++.h>
using namespace std;
int main() {
    string line;
    while(getline(cin, line)){
       // joker Joker ͨɱ
        if (line.find("joker JOKER") != -1)
            cout << "joker JOKER"<<endl;
        else {
            int f = line.find('-');
            string card1 = line.substr(0, f); //ǰ����
            string card2 = line.substr(f+1);  //������
            int c1 = count(card1.begin(), card1.end(),' '); //ͨ���ҿո�ȷ������
            int c2 = count(card2.begin(), card2.end(),' ');
            string first1 = card1.substr(0, card1.find(' ')); // �Ƚϵ�һ���ƾͿ�����
            string first2 = card2.substr(0, card2.find(' '));
            string str = "345678910JQKA2jokerJOKER";
            if (c1 == c2) {
                if (str.find(first1) > str.find(first2)) cout << card1 <<endl;
                else cout << card2 <<endl;
            }else {
                if (c1 == 3) cout << card1 <<endl;
                else if (c2 == 3) cout << card2 <<endl;
                else cout <<"ERROR"<<endl;
            }
        }
    }
}
/* input
4 4 4 4-joker JOKER
4 4 4 4-5 5 5 5
*/

/* output
joker Joker
5 5 5 5
*/
