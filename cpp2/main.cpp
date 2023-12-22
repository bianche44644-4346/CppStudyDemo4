#include <iostream>
#include <fstream> // ���ļ������в���
#include <Windows.h>
#include <string>

using namespace std;
#define X 64
#define Y 64

bool isPeak(int map[X][Y], int x,int y); // �ж��Ƿ��Ƿ�ֵ�ĺ���,������Ҫ�ж�ֵ���к���

int main(void)
{
	/*�����к���*/
	int rows, cols;
	int map[X][Y]; /*��Ϊc֮ǰ�ǲ�֧�ֱ䳤���鶨��,���������ڶ�������ʱ,�Ͷ���һ��������(����ʵ��
	                   һ�㲻����ô��)*/
	string fileName; /*����ļ���*/
	ifstream file; /*�����ȡ�ļ����Ķ���*/

	cout << "�������ļ���:" << endl;
	cin >> fileName;

	/*���ļ�*/
	file.open(fileName.c_str());

	/*�ж��ļ��Ƿ�򿪳ɹ�*/
	if (file.fail())  /*ʹ���������,��ʧ�ܷ�����,�򿪳ɹ����ؼ�*/
	{
		cout << "�ļ���ʧ��" << endl;
		exit(1); /*����Ϊ1,�쳣����,����Ϊ0,��������*/
	}

	file >> rows >> cols; /*���ļ�����������������*/

	/*���ʵ�ʵõ���������,��������Ԥ�ƵĴ�С��,���з����Լ��*/
	if (rows > X || cols > Y) //����治�¾ͷ���
	{
		cout << "����Ų�����" << endl;
		exit(1);
	}

	/*�������ļ��ж�ȡ���ݵ���ά����*/
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++) 
		{
			file >> map[i][j]; // ��������
		}
	}

	/*�жϲ���ӡ��ֵ*/
	for (int i = 1; i < rows-1; i++)
	{
		for (int j = 1; j < cols-1; j++)
		{
			if (isPeak(map,i,j))
			{
				//cout << "��ֵ:" << map[i][j] << ' ';
				cout << "��ֵ��������" << i << " ��" << j << endl;
			}
		}
	}

	system("pause");

	/*һ��Ҫ�ǵùر��ļ�*/
	file.close();

	return 0;
}
bool isPeak(int map[X][Y], int x, int y)
{
	if ((map[x-1][y] < map[x][y])  && (map[x + 1][y] < map[x][y])
		&& (map[x][y-1] < map[x][y]) && (map[x][y + 1] < map[x][y]))
	{
		return true;  // �����ĸ������ʹ�����һ����ֵ
	}

	return false; // �ߵ������һ�����Ƿ�ֵ,��Ϊ���������������ֱ���˳���
}