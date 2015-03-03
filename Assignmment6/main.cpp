#include "BinaryHeap.h"
#include "Header.h"
#include <string>
#include <queue>
#include <iomanip>
using namespace std;
class LessThanPriority
{
public:
	bool operator()(Node<int, string> lhs, Node<int, string> rhs)
	{
		if(lhs.returnPriority() == rhs.returnPriority())
		{
			return lhs.getData() < rhs.getData();
		}
		else
		{
			return lhs.returnPriority() < rhs.returnPriority();
		}
	}

};

//bool compare(Node<int, string> lhs, Node<int, string> rhs);



int main()
{

	//Vairiables to be inserted to the priority queue
	Node<int, string> AliceA(3, "Alice Ailment");
	Node<int, string> IreneIll(1, "Irene Ill");
	Node<int, string> SidS(4, "Sid Sickly");
	Node<int, string> CathyC(5, "Cathy Coughing");
	Node<int, string> FrankF(7, "Frank Feeling Bad");
	Node<int, string> BobB(2, "Bob Bleeding");
	Node<int, string> SamS(5, "Sam Sneezing");
	Node<int, string> TomT(1000, "Tom Temperature");
	Node<int, string> PaulaP(1000, "Paula Pain");
	Node<int, string> temp(0," ");
//
	priorityQueue<int, string> hospitalList;
	hospitalList.insert(AliceA);
	hospitalList.insert(IreneIll);
	hospitalList.insert(SidS);
	hospitalList.insert(CathyC);
	hospitalList.insert(FrankF);
	hospitalList.insert(BobB);
	hospitalList.insert(SamS);


	clock newClock(12, 0);

	while(!hospitalList.isEmpty())
	{
		temp = hospitalList.viewMax();
					cout << "Treating: " <<temp.getData()<< " at "
						 << newClock.getCurrentTime() << endl;
		newClock.setTimer(20);

		while(!newClock.isTimerComplete())
		{
			newClock.incrementSysClock();


			if(newClock.getCurrentTime() == "01:30")
			{
				cout << endl << endl;
				cout << "***************************************************" << endl;
				cout << endl  << "***Emergency! Pausing All treatments! at "
					 << newClock.getCurrentTime() << " ****" << endl << endl;


				hospitalList.insert(PaulaP);

				clock innerClock(1,30);
				innerClock.setTimer(20);
				while(!innerClock.isTimerComplete())
				{
					innerClock.incrementSysClock();
				}


				temp = hospitalList.viewMax();
				cout << "Finished: " << temp.getData() << " at "
					 << innerClock.getCurrentTime() << endl;
				cout << "***************************************************"
								 << endl << endl;
				hospitalList.removeMax();


				newClock = innerClock;
			}

			if(newClock.getCurrentTime() == "02:10")
			{
				cout << endl << endl;
				cout << "***************************************************" << endl;
				cout << endl << endl  << "***Emergency! Pausing All treatments! at "
					 << newClock.getCurrentTime() << " ****" << endl << endl;

				hospitalList.insert(TomT);

				clock innerClock(2,10);
				innerClock.setTimer(20);
				while(!innerClock.isTimerComplete())
				{
					innerClock.incrementSysClock();
				}

				cout << left;
				temp = hospitalList.viewMax();
				cout << endl <<  "Finished: " << temp.getData() << " at "
					 << innerClock.getCurrentTime() << endl;
				cout << "***************************************************"
					 << endl << endl;
				hospitalList.removeMax();


				newClock = innerClock;
			}

		}
		temp = hospitalList.viewMax();

		cout << "Finished: " << temp.getData() << " at "
			 << newClock.getCurrentTime() << endl << endl;
		hospitalList.removeMax();
		newClock.clearTimer();

	}

	cout << endl << endl;
	cout << "*******************************************************" << endl;
	cout << "* Using the priority Queue STL                        *" << endl;
	cout << "*******************************************************" << endl;
//
	priority_queue< Node<int,string>, vector< Node<int,string> > , LessThanPriority > q;

	q.push(AliceA);
	q.push(IreneIll);
	q.push(SidS);
	q.push(CathyC);
	q.push(FrankF);
	q.push(BobB);
	q.push(SamS);


	clock someClock(12, 0);

		while(!q.empty())
		{
			temp = q.top();
						cout << "Treating: " <<temp.getData()<< " at "
							 << someClock.getCurrentTime() << endl;
			someClock.setTimer(20);

			while(!someClock.isTimerComplete())
			{
				someClock.incrementSysClock();


				if(someClock.getCurrentTime() == "01:30")
				{
					cout << endl << endl;
					cout << "***************************************************" << endl;
					cout << endl  << "***Emergency! Pausing All treatments! at "
						 << someClock.getCurrentTime() << " ****" << endl << endl;
					cout << "***************************************************" << endl;

					q.push(PaulaP);

					clock innerClock(1,30);
					innerClock.setTimer(20);
					while(!innerClock.isTimerComplete())
					{
						innerClock.incrementSysClock();
					}


					temp = q.top();
					cout << "Finished: " << temp.getData() << " at "
						 << innerClock.getCurrentTime() << endl;
					q.pop();


					someClock = innerClock;
				}

				if(someClock.getCurrentTime() == "02:10")
				{
					cout << "***************************************************" << endl;

					cout << endl  << "***Emergency! Pausing All treatments! at "
						 << someClock.getCurrentTime() << " ****" << endl << endl;

					q.push(TomT);

					clock innerClock(2,10);
					innerClock.setTimer(20);
					while(!innerClock.isTimerComplete())
					{
						innerClock.incrementSysClock();
					}

					cout << left;
					temp = q.top();
					cout << endl <<  "Finished: " << temp.getData() << " at "
						 << innerClock.getCurrentTime() << endl << endl;
					cout << "***************************************************"
						 << endl << endl;

					q.pop();


					newClock = innerClock;
				}

			}
			temp = q.top();

			cout << "Finished: " << temp.getData() << " at "
				 << someClock.getCurrentTime() << endl << endl;
			q.pop();
			someClock.clearTimer();

		}


}

