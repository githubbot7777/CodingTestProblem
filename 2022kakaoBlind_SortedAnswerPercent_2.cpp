/*
https://school.programmers.co.kr/learn/courses/30/lessons/92341
주차요금계산 
*/


#include <bits/stdc++.h>
using namespace std;

/*
기본요금+ [올림(누적주차시간-기본시간)/단위시간]*단위요금
*/
int calPrice(vector<int> fees,int minutes)
{
    if (fees[0] > minutes)//기본시간보다 적게 주차 기본요금 지불
        return fees[1];
    else//double 형변환 안하면 이상한값나옴 올림 계산할경우 고려해야함
        return fees[1] + ceil((minutes - (double)fees[0]) / (double)fees[2]) * fees[3];
}

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


vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;

    map<int,string> in_cars;//<번호판,입차시간>
    map<int, int> pay_cars;//<번호판,주차시간(분)>
    for (int i = 0; i < records.size(); i++)
    {
        //record[0]=입차시간,record[1]=번호판,record[2]=in or out
        vector<string> record = split(records[i], ' ');
        int car_num = stoi(record[1]);
        if (!record[2].compare("IN"))
        {
            in_cars[car_num] = record[0];
        }
        else {
            auto search = in_cars.find(car_num);
            if (search != in_cars.end())
            {
               string start_time= search->second;
               vector<string>start_times = split(start_time, ':');//"시간:분"
               
               string end_time = record[0];
               vector<string>end_times = split(end_time, ':');
               
               int start_minute = stoi(start_times[0]) * 60 + stoi(start_times[1]);
               int end_minute = stoi(end_times[0]) * 60 + stoi(end_times[1]);
               int times = end_minute - start_minute;

               auto it = pay_cars.find(car_num);
               if (it != pay_cars.end())
               {
                   pay_cars[car_num] += times;
               }
               else {
                   pay_cars[car_num] = times;
               }
              
               
               in_cars.erase(search);
            }
           
        }
        
    }

    for (auto it=in_cars.begin();it!=in_cars.end();it++)
    {
        int car_num = it->first;
        string start_time = it->second;
        vector<string>start_times = split(start_time, ':');//"시간:분"
        int start_minute = stoi(start_times[0]) * 60 + stoi(start_times[1]);
        int end_minute = 23*60+59;

        int times = end_minute - start_minute;

        auto it_pay = pay_cars.find(car_num);
        if (it_pay != pay_cars.end())
        {
            pay_cars[car_num] += times;
        }
        else {
            pay_cars[car_num] = times;
        }
        
    }
    
    for (auto it = pay_cars.begin(); it != pay_cars.end(); it++)
    {
        int key = it->first;
        int value = it->second;
        int price = calPrice(fees, value);
        answer.push_back(price);
        cout <<"누적시간: "<<value <<" " << "[" << key << " , " << price << "]" << "\n";
    }
    return answer;
}




int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<int> fees = { 180, 5000, 10, 600 };
    vector<string> records = { "05:34 5961 IN", "06:00 0000 IN", "06:34 0000 OUT", "07:59 5961 OUT", "07:59 0148 IN", "18:59 0000 IN", "19:09 0148 OUT", "22:59 5961 IN", "23:00 5961 OUT" };
    
    solution(fees, records);
  
   

        return 0;
}



