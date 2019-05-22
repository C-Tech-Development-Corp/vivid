#pragma once

#include "vivid/types.h"

#include <glm/mat3x3.hpp>
#include <string>
#include <optional>

namespace vivid {


//  CIE L*a*b* \in [ (0, -86.1827, -107.86); (100, 98.2343, 94.478) ]
namespace lab {
    lab_t fromXyz( const xyz_t& );
    lab_t fromLch( const lch_t& );
}


//  CIE L*C*h(ab) \in [ (0, 0, 0); (100, 140, 360) ]
namespace lch {
    lch_t fromLab( const lab_t& );
    lch_t fromSrgb( const srgb_t& );
    lch_t fromXyz( const xyz_t& );  //  (-)
}


//  hsv \in [0; 1]
namespace hsv {
    hsv_t fromHsl( const hsl_t& );  //  (-)
    hsv_t fromRgb( const rgb_t& );
}


//  hsl \in [0; 1]
namespace hsl {
    hsl_t fromIndex( const uint8_t );   //  *
    hsl_t fromHsv( const hsv_t& );      //  (-)
    hsl_t fromRgb( const rgb_t& );
}


//  sRGB
namespace srgb {
    srgb_t fromLrgb( const lrgb_t& );
    srgb_t fromXyz( const xyz_t& );     //  to sRGB
    srgb_t fromLch( const lch_t& );     //  (-)
    srgb_t fromAdobe( const adobe_t& ); //  (-)
    srgb_t fromIndex( const uint8_t );       //  (-)
    srgb_t fromName( const std::string& );   //  NOTE: fails silently with return black
}


//  linear rgb
namespace lrgb {
    lrgb_t fromSrgb( const srgb_t& );
    lrgb_t fromRgb( const rgb_t&, const float gamma );
}


//  rgb \in [0; 1]
namespace rgb
{
    rgb_t fromRgb8( const col8_t& );
    rgb_t fromRgb32( const uint32_t );      //  (-)
    rgb_t fromHsv( const hsv_t& );
    rgb_t fromHsl( const hsl_t& );
    rgb_t fromHex( const std::string& );    //  (-)
}


//  adobe rgb
namespace adobe {
    static const float gamma = 2.19921875f;
    adobe_t fromSrgb( const srgb_t& );  //  (-)
    adobe_t fromXyz( const xyz_t& );
}


//  rgb8 \in [0;255]
namespace rgb8 {
    col8_t fromRgb( const rgb_t& );
    col8_t fromRgb32( const uint32_t );
    col8_t fromIndex( const uint8_t );      //  *
    col8_t fromName( const std::string& );  //  NOTE: fails silently with return black
    col8_t fromHex( const std::string& );   //  (-)
}


//  rgb32 as 0xffRRGGBB
namespace rgb32 {
    uint32_t fromRgb( const rgb_t& );       //  (-)
    uint32_t fromRgb8( const col8_t& );
    uint32_t fromHex( const std::string& );
}


//  ansi color index (for use in e.g. ansi escape codes)
namespace index {
    uint8_t fromRgb( const rgb_t& );        //  (-)
    uint8_t fromRgb8( const col8_t& );      //  *
    uint8_t fromHsl( const hsl_t& );        //  (-)
    uint8_t fromHex( const std::string& );  //  (-)
    std::optional<uint8_t> fromName( const std::string& );
}


//  hex string
namespace hex {
    std::string fromRgb( const rgb_t& );    //  (-)
    std::string fromRgb8( const col8_t& );
    std::string fromRgb32( const uint32_t );
    std::string fromIndex( const uint8_t ); //  *
}


//  (nearest) xterm color name
namespace name {
    const std::string& fromRgb( const rgb_t& );    //  (-)
    const std::string& fromIndex( const uint8_t );
}


//  CIE XYZ \in [ (0, 0, 0), profiles::XYZ_d65 ]
namespace xyz {
    xyz_t fromLab( const lab_t& );
    xyz_t fromSrgb( const srgb_t& );
    xyz_t fromLch( const lch_t& );  //  (-)
    xyz_t fromAdobe( const adobe_t& );
}



}   //  ::vivid
