#include <iostream>
#include <deque>
#include <fstream>
#include <ctime>
#include <algorithm>

using namespace std;

void PutRandnumbinfile();
template <typename T> void fromFile(deque<T>* deq);
template <typename T> void fromkeybord(deque<T>* deq);
template <typename T> void printDeque(deque<T>* deq);

int main()
{
	srand(time(NULL));
	deque<int>* deq = new deque<int>;
	cout << "Choose how input info: " << endl;
	cout << "1. from file;\n2. from keybord;" << endl;
	int n;
	cin >> n;
	switch (n)
	{
	case 1:
		PutRandnumbinfile();
		fromFile(deq);
		break;
	case 2: 
		fromkeybord(deq);
		break;
	default:
		cout << "Incorect wariant!" << endl;
		break;
	}
	unsigned int time_end = clock();
	cout << "\nTime: " << (double)time_end/1000 << " s" << endl;
 }

void PutRandnumbinfile()
{
	ofstream out;
	string fname;
	cout << "enter a file name: ";
	cin >> fname;
	out.open(fname);
	cout << "enter a number of elements: ";
	int numb;
	cin >> numb;
	if (!out.is_open())
	{
		throw "incortect file name!";
	}
	for (int i = 0, n; i < numb; i++)
	{
		n = rand() % 100;
		out << n << " ";
		if (!(i % 50) && i != 0) out << "\n";
	}
	out.close();
}

template <typename T>
void fromFile(deque<T>* deq)
{
	ifstream from_file;
	int n;
	string fname;
	cout << "enter a file name: ";
	cin >> fname;
	from_file.open(fname);
	if (!from_file.is_open())
	{
		throw "Incorrect file name!";
	}
	while (from_file)
	{
		from_file >> n;
		deq->push_back(n);
	}
	deq->pop_back();
	cout << "deq_1: " << endl;
	printDeque(deq);
	cout << endl << "Rewers deque:\n";
	reverse(deq->begin(), deq->end());
	printDeque(deq);
	cout << endl;
}

template <typename T>
void fromkeybord(deque<T>* deq)
{
	int n ;
	cout << "set data: ";
	while (cin >> n)
	{
		deq->push_back(n);
	}	
	cout << "deq: " << endl;
	printDeque(deq);
	cout << endl << "reverse deq:" << endl;;
	printDeque(deq);
	cout << endl;
}

template <typename T> void printDeque(deque<T>* deq)
{
	for (auto it = deq->begin(); it < deq->end(); it++)
	{
		cout << *it << " ";
	}
}