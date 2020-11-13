//
//  Header_2.h
//  23
//
//  Created by Admin on 13.11.2020.
//

#ifndef Header_2_h
#define Header_2_h

double Func2(int x, int k = 5) {
    double minus, sum, _x;
    minus = -1;
    sum = 0;
    _x = x;
    
    for (int i = 0, j = 3; i < k; i++, j+= 2){
        _x *= x * x;
        sum += minus * (_x / F(j));
    }
    return sum;
}

#endif Header_2_h
