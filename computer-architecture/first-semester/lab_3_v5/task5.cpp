#include <iostream>

using namespace std;

void stackSum(long long int a, long long int b, long long int& sum) {

	__asm {
		mov eax, [ebp + 8] ;
		mov ebx, [ebp + 16] ;
		add eax, ebx ;
		mov esi, [ebp + 24];
		mov [esi], eax;

		mov eax, [ebp + 12];
		mov ebx, [ebp + 20];
    		adc eax, ebx ;
		mov [esi + 4], eax;
	}
}

void regSum() {
	__asm {
		mov eax, [ebx] 
		add eax, ecx
		mov [esi], eax
	
		mov eax, [ebx + 4]
		mov ecx, [edx + 4]
		adc eax, ecx 
		mov [esi + 4], eax 
	}
}

long long int A = 0; 
long long int B = 0; 
long long int* Sum = 0;

void globalSum() {
	__asm {
		lea ebx, A 
		lea edx, B 
		mov esi, Sum 

		mov eax, [ebx]
		mov ecx, [edx]
		add eax, ecx
		mov [esi], eax
		mov eax, [ebx + 4]
		mov ecx, [edx + 4]
		adc eax, ecx
		mov [esi + 4], eax
	}
}


int main() {

	setlocale(LC_ALL, "rus");
	
	long long int a = 0x0000000000000004;
	long long int b = 0x000000000000000A;
	
	long long int sum = 0;

	
	stackSum(a, b, sum);
	cout << "Сумма через стек: " << sum << endl;
	sum = 0; // Обнуляем сумму для следующих вариантов передачи.


	__asm {
		lea ebx, a 
		lea edx, b 
		lea esi, sum
	}
	regSum();
	cout << "Сумма через регистры: " << sum << endl;
	sum = 0;
	
	A = a;
	B = b;
	Sum = &sum;
	globalSum();
	cout << "Сумма через глобальные переменные: " << sum << endl;
	sum = 0;

	return 0;
}

