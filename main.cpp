//
//  main.cpp
//  testTimeConversion
//
//  Created by Clifford Campo on 11/2/18.
//  Copyright © 2018 CliffordCampo. All rights reserved.
//


#include "timeConversionBaseClass.hpp"
#include "StopWatch.hpp"
using namespace std;
int main(int argc, const char * argv[]) {
    // insert code here...
    cout << "Hello, " << *(argv +0) << endl;
    const char *gregorian;
    timeConversionBaseClass *tc;
    static StopWatch sw;
    tc = new timeConversionBaseClass;
    for (int i=1; i < argc; i++ )  {
        const char *gd = *(argv + i);
        string string_gd = string(gd);
        
        sw.Restart();
        double jd = tc->gregorianToJulian(gd);
        cout << "Julian Day equivaluent of " << gd << " is " << std::fixed << std::setprecision(9) << jd << ".\n Execution Time " << sw.ElapsedUs() << " µ-sec." << endl;
        sw.Restart();
        gregorian = tc->julianToGregorian(&jd);
        cout << "The Gregorian Calendar equivalent of jd = " << std::fixed << std::setprecision(9) << jd << " is " << gregorian << ".\n Execution Time " << sw.ElapsedUs() << " µ-sec." << " µ-sec." << endl;
    }
    double d1 = 2299160; //The Gregorian Calendar equivalent of jd = 2299160.000000000 is 1582-10-4 0:0:0.
    sw.Restart();
    gregorian = tc->julianToGregorian(&d1);
    cout << "The Gregorian Calendar equivalent of jd = " << std::fixed << std::setprecision(9) << d1 << " is " << gregorian << ".\n Execution Time " << sw.ElapsedUs() << " µ-sec." << " µ-sec." << endl;
    double d2 = 1867216.25; //The Gregorian Calendar equivalent of jd = 1867216.250000000 is 400-2-28 6:0:0.
    sw.Restart();
    gregorian = tc->julianToGregorian(&d2);
    cout << "The Gregorian Calendar equivalent of jd = " << std::fixed << std::setprecision(9) << d2 << " is " << gregorian << ".\n Execution Time " << sw.ElapsedUs() << " µ-sec." << " µ-sec." << endl;
    delete tc;
    return 0;
}
