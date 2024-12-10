#include <omp.h>
#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <conio.h>

using namespace std;

//1

void func()
{
	for (int i = 0; i < 500000; i++)
		rand();
}

int main(){

	//2
	
	omp_set_num_threads(2);

	cout << "for: " << endl;

	#pragma omp parallel for
	for (int i = 0; i < 20; i++){
		cout << "#" << i << omp_get_thread_num() << endl;
		func();	
	}
	cout << endl;
	

	cout << "sections: " << endl;
#pragma omp parallel
	{
#pragma omp sections nowait
		{

#pragma omp section
			for (int i = 0; i < 10; i++)
			{
				cout << " #1 " <<endl;
				func();
			}

#pragma omp section
			for (int i = 0; i < 10; i++)
			{
				cout << " #2 " << endl;
				func();
			}
		}

#pragma omp barrier
		for (int i = 0; i < 10; i++)
		{
			cout << "barrier" << endl;
			func();
		}
	}

	cout << endl;
	
//3

	cout << "Ordered:" << endl;

#pragma omp parallel for ordered schedule(dynamic)
    for (int i = 0; i < 10; i++) {
		func();
#pragma omp ordered
        {
			cout << "Iteration " << i << " thread #" << omp_get_thread_num() << endl;
        }
    }
    cout << endl;

	cout << "Single:" << endl;
#pragma omp parallel
	{
#pragma omp single
		{
		cout << "Single - thread #" << omp_get_thread_num() << endl;
		}
		cout << "Print by different thread #: " << omp_get_thread_num() <<endl;
	}
    cout << endl;



	
//4
	int count = 0; 
	omp_lock_t lock;
	omp_init_lock(&lock);

#pragma omp parallel
	{
		int num = omp_get_thread_num();

		omp_set_lock(&lock);
		cout << "Thread " << num << " in lock." << endl;
		
		count++;
		cout << "Thread " << num << " count = " << count << endl;

		omp_unset_lock(&lock);
	}

	omp_destroy_lock(&lock);

    return (0);
}
