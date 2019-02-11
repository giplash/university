//
//  InvalidYear.h
//  lab-1
//
//  Created by Viktor Anashkin on 12/22/18.
//  Copyright © 2018 BSU. All rights reserved.
//

#ifndef InvalidYear_h
#define InvalidYear_h
#include <stdexcept>

struct InvalidYear : public std::exception
{
    const char * what () const throw ()
    {
        return "Invalid year error";
    }
};
#endif /* InvalidYear_h */
