#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <mmintrin.h>
#include <xmmintrin.h>
#include <immintrin.h>
#include <dvec.h>
#include <emmintrin.h>
#include <dvec.h>


int main()
{
// 1
   //MMX - paddsw
	short dq1[4] = { 30000, 20000, 40000, 50000 };
	short dq2[4] = { 10000, 30000, 20000, 40000 };
	short res[4];

	_asm { //mmx
		movd mm0, dq1
		movd mm1, dq2
		paddsw mm0, mm1  
		movd res, mm0 
	}
	printf("%s\n", "Summing elements of vectors dq1 + dq2 :");
	for (int i = 0; i < 4; i++)
	{
		printf("%d ", res[i]);
	}
	printf("\n");


	//SSE shufps
	float a[4] = { 1.5, 2.5, 3.5, 4.5 };
	float result[4];

	_asm {
		movups xmm0, a
		shufps xmm0, xmm0, 0x1B
		movups result, xmm0
	}

	printf("%s\n" "Shuffle elements in array :");
	printf("Result: %f, %f, %f, %f\n", result[0], result[1], result[2], result[3]);

	// AVX  
	float ab[4] = { 1.5, 2.5, 3.5, 4.5 };
	float bb[4] = { 1.5, 2.5, 3.5, 4.5 };

	_asm {
		vmovups ymm0, ab
		vmovups ymm1, bb
		vcmpeqps ymm2, ymm0, ymm1 
	}


	// 2) 
	__m64 m1 = _mm_set_pi8(10, -5, 20, -15, 30, -25, 40, -35);  
	__m64 m2 = _mm_set_pi8(-3, 15, -6, 25, -9, 35, -12, 45); 
	__m64 result1 = _mm_add_pi8(m1, m2);

	__m128 m3 = _mm_set_ps(4.0, 3.0, 2.0, 1.0);
	__m128 m4 = _mm_set_ps(8.0, 7.0, 6.0, 5.0);
	__m128 result2 = _mm_mul_ps(m3, m4); 
	 
	__m256 m5 = _mm256_set_ps(6.0, 1.0, 6.0, 5.0, 8.0, 3.0, 2.0, 9.0);
	__m256 m6 = _mm256_set_ps(7.0f, 5.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0);
	__m256 result3 = _mm256_div_ps(m5, m6); 

	//3)

	F64vec2 f1{ 12, 4 };
	F64vec2 f2{ 3, 4 };
	F64vec2 f3 = _mm_and_pd(f1, f2);


	return 0;

	}
