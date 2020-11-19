//
//  Header_2.h
//  23
//
//  Created by Admin on 13.11.2020.
//

#ifndef Header_2_h
#define Header_2_h

double Func2(int x, int k = 5) {
	double sum = 0;
	int minus = -1;

	for (int i = 0; i < k; i++){
		minus *= -1;
		sum += minus * pow(x, 2 * i + 1) / F(2 * i + 1);
	}

	return sum;
}

#endif Header_2_h
