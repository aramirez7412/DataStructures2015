#include <iostream>
#include <cmath>
#include <time.h>
using namespace std;


unsigned long Fib1( int n );
int fib(int n);



int main()
{
	// A recursive function for a function having one parameter that
	// generates the nth Fibonacci number.
	// f(i+2)=fi+f(i+1)

	// The full recursive version:
	float clockF = 0;
	double clockS = 0;



	char ans;
	int N;

		cout << "I will display fibonacci numbers 0-N." << endl;
		cout << "Enter an limit, please. Be patient! This recursive"
		<< endl << "Fibonacci routine will take about 17 "
		<< endl << "seconds for N = 35 alone" << endl;
		cin >> N;
		for ( int i = 0; i < N; i++ )
		cout << Fib1(i) << endl;



	clockF = float((clock())/(double(CLOCKS_PER_SEC)));
	cout << "Time elapsed: " << clockF << endl;




//	clockS = float ((clock())/(double(CLOCKS_PER_SEC)));

	int n = 34;
	cout << fib(n) << endl;
//
	clockF = float((clock())/(double(CLOCKS_PER_SEC))-clockF);
	cout << "Time elapsed: " << clockF << endl;









}

unsigned long Fib1( int n )
{
	if (n == 0 || n == 1)
	return 1;
	return Fib1( n - 1 ) + Fib1( n - 2 );
}


int fib(int n)
{
  /* Declare an array to store fibonacci numbers. */
  int f[n+1];
  int i;

  /* 0th and 1st number of the series are 0 and 1*/
  f[0] = 0;
  f[1] = 1;

  for (i = 2; i <= n; i++)
  {
      /* Add the previous 2 numbers in the series
         and store it */
      f[i] = f[i-1] + f[i-2];
  }

  return f[n];
}
