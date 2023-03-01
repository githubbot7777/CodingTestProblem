/*
https://school.programmers.co.kr/learn/courses/30/lessons/92334?language=cpp
�Ű��� �ޱ� 
*/

#include <unordered_map>
#include <bits/stdc++.h>

using namespace std;

/*

*/

vector<string> split(string input, char delimiter)
{
    vector<string> answer;
    stringstream ss(input);
    string temp;
    while (getline(ss, temp, delimiter))
    {
        answer.push_back(temp);
    }
    return answer;
}
int get_id_index(vector<string> id_list, string id)
{
    for (int i = 0; i < id_list.size(); i++)
    {
        if (!id_list[i].compare(id))
            return i;
    }
    return -1;
}
vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer(id_list.size(), 0);

    set<string> report_unique;
    //�ߺ�����
    for (int i = 0; i < report.size(); i++)
        report_unique.insert(report[i]);
    
    unordered_map<string, vector<string>> map;  //<key,value> <�Ű����id, �Ű���id�迭>
    vector<int>reported_count(id_list.size(),0);//id_list�� ����� ȸ���� �Ű���� Ƚ�� ����
   
    for (set<string>::iterator it_set = report_unique.begin(); it_set != report_unique.end(); it_set++)
    {
        vector<string> report_splits;
        report_splits = split(*it_set, ' ');//[0]����id [1]������ �Ű��� id
        int idx = get_id_index(id_list, report_splits[1]);
        if (idx != -1)
            reported_count[idx]++;
            

        auto search = map.find(report_splits[1]);
        if (search != map.end())//���ϴ� �� ã��
        {
            vector<string> reported_id = search->second;
            reported_id.push_back(report_splits[0]);
            //�迭�� ���� �߰��ϰ� �ٽ� map�� �־��ֱ� ����� ����
            search->second = reported_id;
        }
        else {
            map[report_splits[1]] = {report_splits[0]};
        }
    }

    vector<string> reported_id_list;
    for (int i = 0; i < reported_count.size(); i++)
    {
        if (reported_count[i] >= k)
        {
            string id = id_list[i];
            reported_id_list.push_back(id);
        }
    }

    for (int i = 0; i < reported_id_list.size(); i++)
    {
        auto search = map.find(reported_id_list[i]);
        if (search != map.end())//���ϴ� �� ã��
        {
            vector<string> list = search->second;//�Ű�ó������ ������ id list
            for (int j = 0; j < list.size(); j++)
            {
                int idx = get_id_index(id_list, list[j]);
                if (idx != -1)
                    answer[idx]++;
            }
        }

    }
    return answer;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<string>id_list = { "con", "ryan" };
    vector<string>report = { "ryan con", "ryan con", "ryan con", "ryan con" };
    vector<int> result=solution(id_list, report, 2);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
        return 0;
}



