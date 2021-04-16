#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <climits>
using namespace std;
//Data types
class AI_t{
public:
    AI_t();
    ~AI_t();
    //get input number from AI
    vector<int> get_num();
    void append(pair<vector<int>, vector<int>> oneHistory);
    
private:
    //AI_t& operator= (AI_t&);
    vector<pair<vector<int>, vector<int>>> history;
};

//function prototypes
//convert given string into an array of int
vector<int> split_numbers(string rawData);
//generate random numbers
const vector<int> gen_num();
//get input number from user
vector<int> get_num();
//returns strikes and balls
vector<vector<bool>> check_answer(const vector<int>& comNum, vector<int>& input);
//prints rule of number baseball
void print_rule();

//function definitions
void AI_t::append(pair<vector<int>, vector<int>> oneHistory)
{
    history.push_back(oneHistory);
}
vector<int> AI_t::get_num()
{

}
void print_rule()
{
    cout << "서로 다른 세 개의 0부터 9까지의 숫자 세 개를 입력하여 정답을 맞히면 됩니다." << endl;
    cout << "해당하는 위치에 해당하는 숫자가 있으면 이를 스트라이크라고 합니다." << endl;
    cout << "해당하는 위치 외에 해당하는 숫자가 있으면 볼이라고 합니다." << endl;
    cout << "3스트라이크를 하면 이깁니다. 같은 숫자 세 개를 입력하면 종료합니다." << endl;
}
const vector<int> gen_num()
{
    srand(time(NULL));
    vector<int> retval = {rand() % 10, rand() % 10, rand() % 10};
    while((retval[0] == retval[1]) || ((retval[1] == retval[2]) || (retval[2] == retval[0])))
    {
        for(int i = 0; i <= 2; i++)
        {
            if(i != 2)
            {
                if(retval[i] == retval[i+1])
                    retval[i] = rand() % 10;
            }
            else
                if(retval[2] == retval[0])
                    retval[i] = rand() % 10;
        }
    }
    return retval;
}
vector<int> get_num()
{
    cout << "세 개의 숫자를 입력하세요 : ";
    vector<int> retval;
    while(retval.size() != 3)
    {
        string tempInput;
        getline(cin, tempInput);
        //cin.ignore(INT_MAX, '\n');
        for (auto i : tempInput)
        {
            if('0' <= i && i <= '9')
                retval.push_back(i - '0');
            if(retval.size() == 3)
                break;
        }
    }
    return retval;
}
vector<vector<bool>> check_answer(const vector<int>& comNum, vector<int>& input)
{
    vector<bool> strike{false, false, false}, ball{false, false, false};
    for (auto& i : comNum)
    {
        auto id = distance(comNum.begin(), find(comNum.begin(), comNum.end(), i));
        for (auto& j : input)
        {
            auto jd = distance(input.begin(), find(input.begin(), input.end(), j));
            if(i == j)
            {
                if(id == jd)
                    strike[id] = true;
                else
                    ball[id] = true;
            }
        }
    }
    return {strike, ball};
}


//main
int main()
{
    cout <<"숫자야구입니다."<<endl;
    print_rule();
    cout <<"세 개의 숫자를 생성중입니다..."<<endl;
    const auto comNum = gen_num();
    cout << "숫자 생성 완료"<<endl;
    auto isUser = true;
    //cout << "AI가 답을 맞춰볼까요? (Y | n) : ";
    //char sw;
    //cin >> sw;
    //switch (sw)
    //{
    //case 'Y':
    //case 'y':
    //    isUser = false;
    //    break;
    //case 'N':
    //case 'n':
    //    isUser = true;
    //    break;
    //default:
    //    cout << "잘못 입력하셨습니다. 사용자 입력으로 전환합니다." << endl;
    //    isUser = true;
    //    break;
    //}
    //cin.ignore(INT_MAX, '\n');
    //AI_t AI;
    auto exit = false;
    auto attempt = 0;
    while(1)
    {
        cout << "답으로 사용할 ";
        vector<int> userNum;
        if(isUser)
        {
            userNum = get_num();
            if((userNum[0] == userNum[1]) && (userNum[1] == userNum[2])) 
            {    
                exit = true;
                break;
            }
        }
        //else
            //userNum = AI.get_num();
        auto strike = 0, ball = 0;
        auto result = check_answer(comNum, userNum);
        for (const auto& i : result[0]) if(i) strike ++;
        for (const auto& i : result[1]) if(i) ball++;
        cout << strike << "스트라이크와 " << ball << "볼입니다!" << endl;
        attempt++;
        //if(!isUser) 
            //AI.append(make_pair(vector<int>{strike, ball}, userNum));
        if(strike == 3)
            break;
    }
    if(exit)
        goto end;
    cout << attempt << "번의 시도만에 성공했습니다!" << endl;
    end:
    cout << "종료합니다..." << endl;
    return 0;
}
