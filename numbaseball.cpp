#include <bits/stdc++.h>
using namespace std;
//Data types
class AI_t{
public:
	AI_t();
	~AI_t();
	//get input number from AI
	vector<int> get_num();
private:
	AI_t& operator= (AI_t&);

};

//function prototypes
//convert given string into an array of int
vector<int> split_numbers(string rawData);
//generate random numbers
const vector<int> gen_num();
//get input number from user
vector<int> get_num();
//returns whether answer contains input numbers and whether they are in right position
vector<vector<bool>> check_answer(const vector<int>& comNum, vector<int>& input);
//prints rule of number baseball
void print_rule();

//function definitions
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
	string tempInput;
	getline(cin, tempInput);
	
}


//main
int main()
{
    cout <<"숫자야구입니다."<<endl;
	print_rule();
    cout <<"세 개의 숫자를 생성중입니다..."<<endl;
	const auto comNum = gen_num();
    cout << "숫자 생성 완료"<<endl;
	
	while(1)
	{
		auto exit = false;
    	auto attempt = 0;
    	while(1)
    	{
    	    cout << "답으로 사용할 ";
    	    auto userNum{get_num()};
			if((userNum[0] == userNum[1]) && (userNum[1] == userNum[2]))
				exit = true;
			if(exit)
				break;
    	    auto strike = 0, ball = 0;
			auto result = check_answer(comNum, userNum);
			cout << strike << "스트라이크와 " << ball << "볼입니다!" << endl;
			attempt++;
			if(strike == 3)
		    	break;
    	}
		if(exit)
			break;
    	cout << attempt << "번의 시도만에 성공했습니다!" << endl;
	}
	cout << "종료합니다..." << endl;
	return 0;
}
