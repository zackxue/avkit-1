
#ifndef __AVKit_Locky_h
#define __AVKit_Locky_h

#include "XSDK/XMutex.h"
#include "XSDK/XRef.h"
#include <list>

extern "C"
{
#include "libavcodec/avcodec.h"
#include "libavformat/avformat.h"
};

namespace AVKit
{

class Locky
{
public:
    X_API static void RegisterFFMPEG();
    X_API static void UnregisterFFMPEG();
private:
    Locky();
    Locky( const Locky& obj );
    Locky& operator = ( const Locky& obj );

    static int _LockyCB( void** mutex, enum AVLockOp op );
};

}

#endif
