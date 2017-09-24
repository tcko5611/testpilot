#ifndef OSGEARTH_H
#define OSGEARTH_H

#include "osgearth_global.h"

class OSGEARTH_LIB_EXPORT OsgEarth {
public:
    static void registerQmlTypes();
    static void initialize();

private:
    static bool registered;
    static bool initialized;

    static void initializePathes();
    static void initializeCache();

    // Sets the WindowingSystem to Qt.
    static void initWindowingSystem();

    static void displayInfo();
};

#endif // OSGEARTH_H
