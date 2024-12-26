#include "pch.h"
#include "MiniTesk.h"

using namespace std;

// ==========================================================
// �迭�� ����� 5���� ���ڸ� �Է¹ް�, �հ�� ����� ��ȯ�غ���.
// Array_Add : �迭�� ��� ���Ҹ� �����ִ� �Լ�
// Array_Avg : �迭 ������ ����� ���ϴ� �Լ�
// Array_Tesk : ���� �Լ�
// ==========================================================

int* Create_Array(int _Cnt)
{
	int* New_Arry_ptr = new int[_Cnt];

	return New_Arry_ptr;
}

void Del_Array(int* _Arr_ptr)
{
	if (_Arr_ptr != nullptr)
		delete _Arr_ptr;

	return;
}

int Array_Add(int* _Arr_int_ptr, int _Arr_Cnt)
{
	int Acc_Num = 0;
	for (int i = 0; i < _Arr_Cnt; ++i)
	{
		Acc_Num += _Arr_int_ptr[i];
	}

	return Acc_Num;
}

float Array_Avg(int* _Arr_int_ptr, int _Arr_Cnt)
{
	float Avg_Num = 0;
	Avg_Num = (float)Array_Add(_Arr_int_ptr, _Arr_Cnt) / (float)_Arr_Cnt;

	return Avg_Num;
}

void Array_Tesk()
{
	int Arr_Count = 0;
	int SortType = 0;

	cout << "���� �迭�� ���� ���� �Է����ּ���." << endl;
	cin >> Arr_Count;

	int* New_Arr_ptr = Create_Array(Arr_Count);

	cout << "�迭�� �� ���� ���� �Է����ּ���." << endl;

	for (int i = 0; i < Arr_Count; ++i)
	{
		cin >> New_Arr_ptr[i];
	}

	cout << "���Ĺ���� ������ �ּ���!\n�������� : 1\n�������� : 2\n";
	cin >> SortType;

	heapSort(New_Arr_ptr, Arr_Count, SortType);

	cout << "�迭 ���� ��� : ";
	for (int i = 0; i < Arr_Count; ++i)
	{
		cout << New_Arr_ptr[i] << " ";
	}
	cout << endl;

	cout << "�迭 ������ ������ " << Array_Add(New_Arr_ptr, Arr_Count) << "�Դϴ�." << endl;
	cout << "�迭 ������ ����� " << Array_Avg(New_Arr_ptr, Arr_Count) << "�Դϴ�." << endl;

	Del_Array(New_Arr_ptr);

	return;
}


// ==========================================================
// ����ڰ� �Է��� ���� �迭�� �����ϴ� ���α׷� �����ϱ�
// ���� 1. ��������, �������� ������ �����ؾ� �Ѵ�.
// ���� 2. ���� 1�� �Է��ϸ� �������� ����, 2�� ������ �������� ������ �ؾ��Ѵ�.
// ���� 3. algorithm�� sort()�� ����ϸ� �ȵȴ�.
// ���� 4. ���������� �������� ������ ���� �Լ��� ������ ��.
// ==========================================================

void Heapify(int* _Arr_ptr, int _CurIdx, int _Cnt, int _SortType)
{
	int left = _CurIdx * 2 + 1;
	int right = _CurIdx * 2 + 2;
	int MinMax = _CurIdx;

	if (_SortType == 1)
	{
		if (left < _Cnt && _Arr_ptr[left] > _Arr_ptr[MinMax])
			MinMax = left;
		if (right < _Cnt && _Arr_ptr[right] > _Arr_ptr[MinMax])
			MinMax = right;
	}
	else if (_SortType == 2)
	{
		if (left < _Cnt && _Arr_ptr[left] < _Arr_ptr[MinMax])
			MinMax = left;
		if (right < _Cnt && _Arr_ptr[right] < _Arr_ptr[MinMax])
			MinMax = right;
	}

	if (MinMax != _CurIdx)
	{
		Arr_Swap(_Arr_ptr, MinMax, _CurIdx);
		Heapify(_Arr_ptr, MinMax, _Cnt, _SortType);
	}
}

void Arr_Swap(int* _Arr_ptr, int fst, int sec)
{
	int temp = _Arr_ptr[fst];
	_Arr_ptr[fst] = _Arr_ptr[sec];
	_Arr_ptr[sec] = temp;
}

void BuildHeap(int* _Arr_ptr, int _Cnt, int _SortType)
{
	for (int i = _Cnt / 2 - 1; i >= 0; --i)
	{
		Heapify(_Arr_ptr, i, _Cnt, _SortType);
	}
}

void heapSort(int* _Arr_ptr, int _Cnt, int _SortType)
{
	BuildHeap(_Arr_ptr, _Cnt, _SortType);
	for (int TreeSize = _Cnt - 1; TreeSize >= 0; --TreeSize)
	{
		Arr_Swap(_Arr_ptr, 0, TreeSize);
		Heapify(_Arr_ptr, 0, TreeSize, _SortType);
	}
}