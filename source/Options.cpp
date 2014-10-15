
#include "AVKit/Options.h"

using namespace XSDK;

namespace AVKit
{

struct CodecOptions GetFastH264DecoderOptions()
{
    struct CodecOptions options;

    options.thread_count = 2;
    options.tune = "zerolatency";

    return options;
}

struct CodecOptions GetFastH264EncoderOptions( int bitRate, int picWidth, int picHeight, int gopSize, int timeBaseNum, int timeBaseDen )
{
    struct CodecOptions options;

    options.gop_size = gopSize;
    options.bit_rate = bitRate;
    options.width = picWidth;
    options.height = picHeight;
    options.time_base_num = timeBaseNum;
    options.time_base_den = timeBaseDen;
    options.me_method = 0;
    options.me_subpel_quality = 4;
    options.delay = 0;
    options.thread_count = 6;
    options.refs = 3;
    options.rc_buffer_size = 0;
    options.profile = "baseline";
    options.preset = "ultrafast";
    options.tune = "zerolatency";

    return options;
}

struct CodecOptions GetHLSH264EncoderOptions( int bitRate, int picWidth, int picHeight, int gopSize, int timeBaseNum, int timeBaseDen )
{
    struct CodecOptions options;

    options.gop_size = gopSize;
    options.bit_rate = bitRate;
    options.width = picWidth;
    options.height = picHeight;
    options.time_base_num = timeBaseNum;
    options.time_base_den = timeBaseDen;
    options.delay = 0;
    options.thread_count = 6;
    options.preset = "ultrafast";
    options.tune = "zerolatency";
    options.x264opts = XString::Format("no-scenecut:vbv-maxrate=%d:vbv-bufsize=%d", bitRate / 1000, bitRate / 1000);

    return options;
}

struct CodecOptions GetTranscodeExportH264EncoderOptions( int bitRate, int picWidth, int picHeight, int gopSize, int timeBaseNum, int timeBaseDen )
{
    struct CodecOptions options;

    options.gop_size = gopSize;
    options.bit_rate = bitRate;
    options.width = picWidth;
    options.height = picHeight;
    options.time_base_num = timeBaseNum;
    options.time_base_den = timeBaseDen;
    options.delay = 0;
    options.thread_count = 6;
    options.tune = "zerolatency";

    return options;
}

struct CodecOptions GetJPEGOptions( int picWidth,
                                    int picHeight,
                                    int bitRate,
                                    int qmin,
                                    int qmax )
{
    struct CodecOptions options;

    options.bit_rate = bitRate;
    options.width = picWidth;
    options.height = picHeight;
    options.qmin = qmin;
    options.qmax = qmax;

    return options;
}

}
