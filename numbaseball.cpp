#include <bits/stdc++.h>
using namespace std;
//Data types
class AI_t{
public:
	AI_t();
	~AI_t();
private:
	AI_t& operator= (AI_t&);

};

//function prototypes
//convert given string into an array of int
vector<int> split_numbers(string rawData);
//generate random numbers
const vector<int> gen_num();
//get input number from user of AI
vector<int> get_num();
//returns whether answer contains input numbers and whether they are in right position
vector<vector<bool>> check_answer(vector<int> input);


//function definitions


//main
int main()
{
    cout <<"숫자야구입니다."<<endl;
	cout << "서로 다른 세 개의 0부터 9까지의 숫자 세 개를 입력하여 정답을 맞히면 됩니다." << endl;
	cout << "해당하는 위치에 해당하는 숫자가 있으면 이를 스트라이크라고 합니다." << endl;
	cout << "해당하는 위치 외에 해당하는 숫자가 있으면 볼이라고 합니다." << endl;
	cout << "3스트라이크를 하면 이깁니다. 같은 숫자 세 개를 입력하면 종료합니다." << endl;
	cout << "숫자는 하나씩 입력하셔야 합니다." << endl;
	cout << "예) 123 (X) 1 2 3 (O)";
    while(1)
	{
		bool exit = false;
		cout <<"세 개의 숫자를 생성중입니다..."<<endl;
	    int yourNum[3] = {rand() % 10, rand() % 10, rand() % 10};
	    while(1)
	    {
			if((yourNum[0] != yourNum[1]) && ((yourNum[1] != yourNum[2]) && (yourNum[2] != yourNum[0])))
	    		break;
			for(int i = 0; i <= 2; i++)
			{
		    	if(i != 2)
				if(yourNum[i] == yourNum[i+1])
				    yourNum[i] = rand() % 10;
		    	else
					if(yourNum[2] == yourNum[0])
			    	yourNum[i] = rand() % 10;
			}
    	}
    	int comNum[3];
    	for(int i = 0; i <= 2; i++)
			comNum[i] = yourNum[i];
    	cout << "숫자 생성 완료"<<endl;
    	int attempt = 0;
    	while(1)
    	{
    	    cout << "정답을 입력하세요" << endl;
    	    for(int i = 0; i<= 2; i++)
			{
		    	cout << i+1 << "번째 숫자 : ";
		    	cin >> yourNum[i];
			}
			if((yourNum[0] == yourNum[1]) && (yourNum[1] == yourNum[2]))
				exit = true;
			if(exit)
				break;
    	    int strike = 0, ball = 0;
			for(int i = 0; i <= 2; i++)
		    	for(int i2 = 0; i2 <= 2; i2++)
					if(comNum[i] == yourNum[i2])
				    	if(i == i2)
							strike++;
		    			else
							ball++;
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
