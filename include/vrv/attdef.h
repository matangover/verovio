/////////////////////////////////////////////////////////////////////////////
// Name:        attdef.h
// Author:      Laurent Pugin
// Created:     2014
// Copyright (c) Authors and others. All rights reserved.
/////////////////////////////////////////////////////////////////////////////

#ifndef __VRV_ATT_DEF_H__
#define __VRV_ATT_DEF_H__

#include <string>
#include <utility>
#include <vector>

//----------------------------------------------------------------------------

#include "attclasses.h"
#include "atttypes.h"

//----------------------------------------------------------------------------

namespace vrv {

typedef std::vector<std::pair<std::string, std::string> > ArrayOfStrAttr;

#define VRV_UNSET -0x7FFFFFFF
    
class data_STAFFREL;

//----------------------------------------------------------------------------
// Durations
//----------------------------------------------------------------------------

/**
 * These duration values are used for internal calculation and differ from the
 * MEI data.DURATION types (see below)
 */
#define DUR_MX -1 // maxima
#define DUR_LG 0 // longa
#define DUR_BR 1 // brevis
#define DUR_1 2 // whole note (semibrevis)
#define DUR_2 3 // half note (minima)
#define DUR_4 4 // ...
#define DUR_8 5
#define DUR_16 6
#define DUR_32 7
#define DUR_64 8
#define DUR_128 9
#define DUR_256 10 // this is it for now
// used for alignement
#define DUR_MAX 1024
// mensural duration
#define DUR_MENSURAL_OFFSET (2 * DUR_MAX)
#define DUR_MENSURAL_MASK (2 * DUR_MAX - 1)
// used for mensural alignment
#define DUR_MENSURAL_REF 1728

//----------------------------------------------------------------------------
// MEI data defines
//----------------------------------------------------------------------------

/**
 * The following defines are hand-coded and were not generated by libmei as
 * the ones in ./libmei/atttypes.h. The are generated by hand either because
 * the regroup different types (e.g., data_STEMDIRECTION), because specific
 * values are required (e.g., data_MODUSMAIOR), or because the MEI data type
 * is a pattern and not a closed list and cannot be generated automatically
 * easily (e.g., data_DURATION)
 */

/**
 * A typedef for a list of positive integer.
 * E.g., list { xsd:positiveInteger+ }
 */
typedef std::vector<data_ARTICULATION> data_ARTICULATION_List;

/**
 * MEI data.BEATRPT_REND
 */
enum data_BEATRPT_REND {
    BEATRPT_REND_NONE = 0,
    BEATRPT_REND_4,
    BEATRPT_REND_8,
    BEATRPT_REND_16,
    BEATRPT_REND_32,
    BEATRPT_REND_64,
    BEATRPT_REND_128,
    BEATRPT_REND_mixed
};

/**
 * MEI data.DURATION
 */
enum data_DURATION {
    DURATION_NONE = VRV_UNSET,
    DURATION_long = DUR_LG,
    DURATION_breve,
    DURATION_1,
    DURATION_2,
    DURATION_4,
    DURATION_8,
    DURATION_16,
    DURATION_32,
    DURATION_64,
    DURATION_128,
    DURATION_256,
    DURATION_512,
    DURATION_1024,
    DURATION_2048,
    DURATION_maxima = DUR_MX,
    DURATION_longa = DUR_MENSURAL_OFFSET + DUR_LG,
    DURATION_brevis,
    DURATION_semibrevis,
    DURATION_minima,
    DURATION_semiminima,
    DURATION_fusa,
    DURATION_semifusa
};
    
/**
 * MEI data.FONTSIZENUMERIC
 */
typedef int data_FONTSIZENUMERIC;

/**
 * MEI data.KEYSIGNATURE
 * The maximum is 255 (unsigned char)
 * Order from 7f to 7s should not be changed. This is a special case since we use abs()
 * to get the number of flats or sharps
 */
enum data_KEYSIGNATURE {
    KEYSIGNATURE_NONE = 0,
    KEYSIGNATURE_7f,
    KEYSIGNATURE_6f,
    KEYSIGNATURE_5f,
    KEYSIGNATURE_4f,
    KEYSIGNATURE_3f,
    KEYSIGNATURE_2f,
    KEYSIGNATURE_1f,
    KEYSIGNATURE_0,
    KEYSIGNATURE_1s,
    KEYSIGNATURE_2s,
    KEYSIGNATURE_3s,
    KEYSIGNATURE_4s,
    KEYSIGNATURE_5s,
    KEYSIGNATURE_6s,
    KEYSIGNATURE_7s,
    KEYSIGNATURE_mixed
};

/**
 * MEI data.MEASUREBEAT
 */
typedef std::pair<int, double> data_MEASUREBEAT;

/**
 * MEI data.MIDIBPM
 */
typedef int data_MIDIBPM;

/**
 * MEI data.MIDICHANNEL
 */
typedef int data_MIDICHANNEL;

/**
 * MEI data.MIDIMSPB
 */
typedef int data_MIDIMSPB;

/**
 * MEI data.MIDIVALUE
 */
typedef int data_MIDIVALUE;

/**
 * MEI data.MODUSMAIOR
 * NONE is -3 for perfect value (abs) by default
 */
enum data_MODUSMAIOR { MODUSMAIOR_NONE = -3, MODUSMAIOR_2 = 2, MODUSMAIOR_3 };

/**
 * MEI data.MODUSMINOR
 * NONE is -3 for perfect value (abs) by default
 */
enum data_MODUSMINOR { MODUSMINOR_NONE = -3, MODUSMINOR_2 = 2, MODUSMINOR_3 };

/**
 * MEI data.OCTAVE.DIS
 */
enum data_OCTAVE_DIS { OCTAVE_DIS_NONE = 0, OCTAVE_DIS_8 = 8, OCTAVE_DIS_15 = 15, OCTAVE_DIS_22 = 22 };

/**
 * MEI data.ORIENTATION
 */
enum data_ORIENTATION { ORIENTATION_NONE = 0, ORIENTATION_reversed, ORIENTATION_90CW, ORIENTATION_90CCW };

/**
 * MEI data.PERCENT
 */
typedef int data_PERCENT;

/**
 * MEI data.PITCHNAME
 */
enum data_PITCHNAME {
    PITCHNAME_NONE = 0,
    PITCHNAME_c,
    PITCHNAME_d,
    PITCHNAME_e,
    PITCHNAME_f,
    PITCHNAME_g,
    PITCHNAME_a,
    PITCHNAME_b,
};

/**
 * MEI data.PITCHNAME.GES
 */
enum data_PITCHNAME_GES {
    PITCHNAME_GES_NONE = 0,
    PITCHNAME_GES_c,
    PITCHNAME_GES_d,
    PITCHNAME_GES_e,
    PITCHNAME_GES_f,
    PITCHNAME_GES_g,
    PITCHNAME_GES_a,
    PITCHNAME_GES_b,
    PITCHNAME_GES_none
};

/**
 * MEI data.PROLATIO
 * NONE is -3 for perfect value (abs) by default
 */
enum data_PROLATIO { PROLATIO_NONE = -3, PROLATIO_2 = 2, PROLATIO_3 };

/**
 * MEI data.STEMDIRECTION
 */
enum data_STEMDIRECTION {
    STEMDIRECTION_NONE = 0,
    STEMDIRECTION_up,
    STEMDIRECTION_down,
    STEMDIRECTION_left,
    STEMDIRECTION_right,
    STEMDIRECTION_ne,
    STEMDIRECTION_se,
    STEMDIRECTION_nw,
    STEMDIRECTION_sw,
};

/**
 * MEI data.TIE
 */
enum data_TIE { TIE_NONE = 0, TIE_i, TIE_m, TIE_t };

/**
 * MEI data.TEMPUS
 * NONE is -3 for perfect value (abs) by default
 */
enum data_TEMPUS { TEMPUS_NONE = -3, TEMPUS_2 = 2, TEMPUS_3 };

/**
 * A typedef for a list of positive integer.
 * E.g., list { xsd:positiveInteger+ }
 */
typedef std::vector<int> xsdPositiveInteger_List;


} // namespace vrv

#endif // __VRV_ATT_DEF_H__
