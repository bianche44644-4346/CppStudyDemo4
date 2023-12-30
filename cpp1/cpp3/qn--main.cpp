#include <iostream>
#include <Windows.h>
#include <string.h>
#include <string>
#include <fstream>
#include <errno.h>

using namespace std;

#define fileBallAcount 33  // �ļ������ŵ�����
#define linesCount 7 // һ�����߸�����

bool calculate(const char* fileName, int* cout,int len);

/*������ʦ��˼·*/
int main(void)
{
	/*�����ļ���,�ļ����Լ���ز������ں����з�װ,����ֻ��Ҫ�����ļ����ֺʹ�Ž�������鼴��*/
	string fileName;
	int count[fileBallAcount] = { 0 };/*�ļ����ܹ���33�����ݽ��м���*/

	cout << "�������ļ���" << endl;
	cin >> fileName;

	/*��ȫ���-- �Ƿ�����ɹ�*/
	if (cin.fail())
	{
		cerr << "�ļ�������ʧ��" << endl; /*cerr��C���Ե�stderr����,��������Ϣ�������׼�������*/
		exit(1); /*��������*/
	}

	/*����ɹ�����ú���,����true�����ɹ�,�෴����ʧ��*/
	if (calculate(fileName.c_str(), count, fileBallAcount))
	{
		// ��������ɹ������count�е�����
		for (int i = 1; i < fileBallAcount; i++)
		{
			cout << i << "������" << count[i] << "��" << endl;
		}
	}
	else
	{
		cout << "����ʧ��" << endl;
	}


	system("pause");

	return 0;
}

/*����const char*fileName ����Ϊ���ļ���open������Ҫʹ��C���Ե��ַ���,�����ڴ˴�������װ����ͬ*/
bool calculate(const char* fileName, int* count,int len) /*������Ϊ��������,����Ҫ���䳤�ȴ���*/
{
	int ballData[linesCount] = {0}; // ��¼��ȡ��һ�е���������
	int i = 0;

	/*������--������ļ����ǿ�*/
	if (!strcmp(fileName,"")) // ���Ϊ���򷵻�0
	{
		cerr << "�����ļ���Ϊ��" << endl;

		return false;
	}

	/*�ļ����������ļ�*/
	ifstream file;  // �����ļ������

	file.open(fileName);

	/*������--�ļ��Ƿ�򿪳ɹ�*/
	if (file.fail())
	{
		cerr << "�ļ���ʧ�ܣ�ԭ��" << strerror(errno) << endl;

		file.close();
		return false;  // �ļ���ʧ�ܷ���false
	}

	/*�򿪳ɹ�,��ȡ�ļ��е����ݣ�һ��������ȡ�Ĺ��̣�ʹ��ѭ��*/
	
	while (!file.eof()) // �����ļ���β,�Ǿ�ֹͣѭ���������ļ��������ŷ���ture
	{
		int line = 0;
		/*��ȡһ������Ҳ��һ��ѭ���Ĺ���,ʹ��ѭ��*/
		for (i = 0; i < linesCount; i++)
		{
			file >> ballData[i];
		}
		line++;

		/*���һ�е����ݲ�����7���ǾͲ�����ͳ��*/
		if (i >= 7)
		{
			i = 0;
			/*ʹ��ָ���count��ÿһ��Ԫ�ؽ���++*/
			/*������֤--�ļ��е�ֵ���ܳ���(�˴��Ǹ�ָ���ʼλ��+һ��ֵ,����Ӧ���ڷ�Χ�ڵ�ͬʱ,��֤���ݴ���0)*/
			if (ballData[i] > 0 && ballData[i] <= 33)
				(*(count + ballData[i++]))++;
			else
				file.close();
				return false;
			continue;
		}
		else 
		{
			cout << "��" << line << "�����ݲ���7����ϣ����7��" << endl;
			continue;
		}
	}

	file.close();
	return true;
}