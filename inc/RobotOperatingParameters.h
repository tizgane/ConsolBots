#ifndef ROBOT_OPERATING_PARAMETERS_HH_
#define ROBOT_OPERATING_PARAMETERS_HH_

#include <iostream>
#include <fstream>

class RobotOperatingParameters {
    int poziom_baterii;
    int zajeta_pamiec;
    int zuzycie_czesci;

public:
    RobotOperatingParameters();
    ~RobotOperatingParameters();
    void stan();
    void aktual_pamieci(const int& zmiana_zajecia_pamieci);
    void aktual_baterii(const int& zmiana_poziomu_baterii);
    void aktual_czesci(const int& zmiana_zuzycia_czesci);
};

#endif
