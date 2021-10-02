#include <iostream>

using namespace std;

#define DATA_NUMS 4
#define WEIGHT_NUMS 3

float dot(float* v1, float* v2, int len)
{
	float sum = 0;
	for (int i = 0; i < len; i++)
	{
		sum += v1[i] * v2[i];
	}
	return sum;
}

float step(float v)
{
	return v > 0 ? 1 : 0;
}

float forward(float* x, float* w, int len)
{
	float u = dot(x, w, len);
	return step(u);
}

void train(float* w, float* x, float t, float e, int len)
{
	float z = forward(x, w, len);
	for (int i = 0; i < len; i++)
	{
		w[i] += (t - z) * x[i] * e;
	}
}

int main()
{
	float e = 0.1; //학습률
	float x[DATA_NUMS][WEIGHT_NUMS] = {

		{1,0,0},
		{1,0,1},
		{1,0,1},
		{1,1,1} };//입력 데이터

	float t[DATA_NUMS] = { 0,0,0,1 };//논리곱
	//float t[DATA_NUM] = { 0,1,1,1 };//논리합
	float w[WEIGHT_NUMS] = { 0,0,0 };
	
	int epoch = 10;
	for (int i = 0; i < epoch; i++)
	{
		cout << "epoch: " << i << " ";
		for (int j = 0; j < DATA_NUMS; j++)
		{
			train(w, x[j], t[j], e, WEIGHT_NUMS);
		}
		for (int j = 0; j < WEIGHT_NUMS; j++)
		{
			cout << "w" << j << ":" << w[j] << " ";
		}
		cout << endl;
	}

	for (int i = 0; i < DATA_NUMS; i++)
	{
		cout << forward(x[i], w, WEIGHT_NUMS) << " ";
	}
	cout << endl;

	return 0;
}
