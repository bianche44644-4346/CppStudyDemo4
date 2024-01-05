#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string>
#include <errno.h>
#include <cmath>  // c++�е���ѧ��

#define FZ 1.5 // ����ʹ�õ�����ֵ

using namespace std;

/*�̴����ǳ����ڵ����Ҳ��Ӧ����ٴ���������ͬ�Ĵ���*/

/*�������ڼ��㣬��/��ʱ�䴰�ڵ��������ݵĲ���ֵ, ���Է���һ��doubleֵ*/
double judgementEarthquake(double arr[], int length, int n);  // ������ 1. ���� 2. �����ڴ�С 3. ��ǰ���㴰�ڴ�С

int main(void)
{
	string fileName;
	ifstream file; 
	int nub = 0, short_time = 0, long_time = 0; // account
	double timer_up = 0.0,*sensor = NULL; // time-up gap   sensor points to dynamic memory
	double short_power = 0.0, long_power = 0.0;// ��ʱ�䴰�ڵĲ���ֵ�ͳ�ʱ�䴰�ڵĲ���ֵ
	double radio; // ����

	cout << "Input file name:" << endl;
	cin >> fileName;

	/*Is input success or fail?*/
	if (cin.fail())
	{
		cerr << "Input fail!!!" << endl;
		exit(1); // error exit
	}

	/*open file stream*/
	file.open(fileName.c_str());

	/*judgement: Is file open fail?*/
	if (file.fail())
	{
		cerr << "file open fail, because: " << strerror(errno) << endl;
		exit(1); // error exit
	}
	else  // file open success, reading file data
	{
		file >> nub >> timer_up;

		// legal judgement
		if(nub >=0)
		{
			// legal : dynamic request memory 
			sensor = new double[nub];

			// Gradually read data
			for (int i = 0; i < nub; i++)
			{
				file >> sensor[i];
			}
		}

		cout << "Enter long window data:" << endl;
		cin >> long_time;
		cout << "Enter short window data:" << endl;
		cin >> short_time;

		//�������������ҳ�����ʱ��
		for (int i = long_time-1; i < nub; i++)
		{ // �����Ķ��壬Ӧ�þ���ͨ���ԣ�ͬ���͵����󣬶����Ե��ú���������ֻ��Ҫ��װ��ͬ����Ĵ������,����Ҫ�ٴ����н������⴦�����Ե��ص�ͨ�������Ĳ���
		  // ����
			short_power = judgementEarthquake(sensor, i, short_time);
			long_power = judgementEarthquake(sensor, i, long_time);

			radio = short_power / long_power;

			if (radio > FZ)
			{
				cout << "poosible event at" << i * timer_up << endl;
			}
		}

		// final : release file pointer!!!  put there the cause of only file open success, just need to close it
		file.close();

		delete[] sensor; // �ͷŶ�̬������ڴ�ռ�
	}


	system("pause");

	return 0;
}

double judgementEarthquake(double arr[], int length, int n)
{
	double square = 0.0; // �õ���ƽ��ֵ

	for (int i = 0; i < n; i++)
	{
		square += pow(arr[length - i], 2); // ������ں���ǰ�Ҷ�Ӧ��������ֵȻ����ƽ����
	}

	return square / n; // �����㵽��ƽ���ͳ��Զ�Ӧ����ֵ,�õ���Ӧ���ڵ�����
}
