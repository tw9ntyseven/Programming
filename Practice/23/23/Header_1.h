//
//  Header_1.h
//  23
//
//  Created by Admin on 13.11.2020.
//

#pragma once

int Func(int a) {
    if (a > 1) {
        return Func(a - 1) * a
    } else {
        return 1
    }
}
