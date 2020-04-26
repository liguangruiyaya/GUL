﻿/**@file           CGNSSCoord
 *  @brief         坐标类
 *  @details       所有坐标相关的算法
 *  @author        wuchuanfei@sixens.com
 *  @date          2020/04/14
 *  @version       1.0
 *  @note          暂无
 *  @copyright     Copyright(c) 2019-2020 Beijing Sixents Technology Co., Ltd. All rights reserved.
 */

#ifndef _GNSS_COMMON_DEF_H
#define _GNSS_COMMON_DEF_H
#include <string>
#include "GNSSDataStruct.h"

namespace sixents
{
    namespace GNSSUtilityLib
    {
#define UNREFERENCED_PARAMETER(P) (P)

        // 枚举值定义
        // 时间类型定义
        enum TIME_TYPE
        {
            NONE = 0, // 不支持的时间类型
            UTC = 1, // UTC
            GPS,     // GPS
            GLONASS, // 格洛纳斯
            GALILEO, // 伽利略
            BDS      // 北斗
        };

        // 坐标系统类型定义
        enum COORDINATE_SYS_TYPE
        {
            WGS84 = 1, // GPS坐标系
            PZ90,      // 格洛纳斯坐标系
            ITRF96,    // 伽利略坐标系
            CGCS2000   // 北斗坐标系
        };

        // 坐标类型
        enum COORDINATE_TYPE
        {
            XYZ = 1, // 空间直角坐标系
            BLH,     // 大地坐标
            ENU      // 站心坐标
        };

        // 错误码定义
        const static INT32 RETURN_SUCCESS = 0; // 成功
        const static INT32 RETURN_FAIL = -1;   // 失败
        // static const int RETURN_PACKAGE_LENGHT_ERROR = -2; // 包长度错误
        // static const int RETURN_CRC_CHECK_FAILED = -3;     // CRC校验失败
        // static const int RETURN_STATION_CORRECT = -4;      // StatioinId校验失败
        // static const int RETURN_PERMISSION_ERROR = -5;     // 权限错误
        // static const int RETURN_UNSUPPORTED_RTCM_MSG = -6; // 暂不支持的协议
        // static const int RETURN_NOT_INITIALIZED = -7;      // 未初始化
        // static const int RETURN_INVALID_PARAMETER = -8;    // 无效参数

        // 常量定义
        // For Accuracy
        const int COORDINATE_ACCURACY = 9;  // 空间直角坐标，以及大地坐标中高程的精确度
        const int BLH_ACCURACY = 11;        // 大地坐标中经纬度的精确度
        const int MSEC_ACCURACY = 3;        // 秒的精确度(精确到毫秒)(包括时间的秒和角度的秒)
        const int MATRIX_ACCURACY = 6;      // 矩阵中double数据的精确度
        const int DEGREE_ACCURACY = 9;      // 小数度的精确度(小数后9位)
        // For Time
        const std::string DAY_INTERVAL = "-";      /* 日期间隔符 */
        const std::string TIME_INTERVAL = ":";     /* 时间间隔符 */
        const std::string WEEK_SEC_INTERVAL = ","; /* 周内秒间隔符 */

        const INT32 DAY_OF_YEAR[12] = { 1,32,60,91,121,152,182,213,244,274,305,335 }; /* 一年中，当前月距1月1号的天数*/
        const int DAY_IN_EACH_MON[48]={
            31,28,31,30,31,30,31,31,30,31,30,31,31,28,31,30,31,30,31,31,30,31,30,31,
            31,29,31,30,31,30,31,31,30,31,30,31,31,28,31,30,31,30,31,31,30,31,30,31
        };  /* # of days in a month */
        const static SStandardTime EPOCHT0 = {1970, 1, 1, 0, 0, 0, 0};
        const static DOUBLE GPST0[] = {1980, 1, 6, 0, 0, 0}; /* gps time reference */
        const static DOUBLE GST0[] = {1999, 8, 22, 0, 0, 0}; /* galileo system time reference */
        const static DOUBLE BDT0[] = {2006, 1, 1, 0, 0, 0};  /* beidou time reference */

        const UINT64 EPOCH_TO_GPST0 = 315964800;
        const UINT64 EPOCH_TO_GALT0 = 935280000;
        const UINT64 EPOCH_TO_BDT0 = 1136073600;

        const INT32 BASE_60 = 60;  // 60 进制, ，时间进制
        const INT32 SEC_IN_DAY = 24 * 60 * 60;  // 一天内的秒数 86400
        const INT32 DAY_IN_WEEK = 7;           // 一周内的天数
        const INT32 WEEK_SEC = DAY_IN_WEEK * SEC_IN_DAY; // 一周内的秒数 604800

        const INT32 MONTH_IN_YEAR = 12;  // 一年内的月数
        const INT32 DAY_IN_YEAR = 365;   // 一年内的天数
        const INT32 DAY_IN_4YEAR = 1461; // 四年(含一个闰年)的总天数
        const INT32 MONTH_IN_4YRAR = 48; // 四年(含一个闰年)的总月数
        const INT32 CURRENT_MAX_YEAR = 2099; // 当前支持的最大天数
        const INT32 LEAP_YEAR_INTERVAL = 4;    // 闰年间隔
        // For Time Leap 跳秒值
        const INT32 WEEK_BETWEEN_GPS_GAL = 1024;  // GPS 与 Galileo 之间相差1024周
        const INT32 GPSWEEK_TO_BDSWEEK = 1356;
        const INT32 THREE_HOUR = 3;    // Glonass 与 UTC 之间的跳秒值
        const INT32 SEC_OF_3HOUR = 10800;
        /* leap seconds (y,month,d,h,min,s,utc-gpst) */
        const static DOUBLE GPS_LEAPSEC_INFO[65][7] = {{2017, 1, 1, 0, 0, 0, -18},
                                                       {2015, 7, 1, 0, 0, 0, -17},
                                                       {2012, 7, 1, 0, 0, 0, -16},
                                                       {2009, 1, 1, 0, 0, 0, -15},
                                                       {2006, 1, 1, 0, 0, 0, -14},
                                                       {1999, 1, 1, 0, 0, 0, -13},
                                                       {1997, 7, 1, 0, 0, 0, -12},
                                                       {1996, 1, 1, 0, 0, 0, -11},
                                                       {1994, 7, 1, 0, 0, 0, -10},
                                                       {1993, 7, 1, 0, 0, 0, -9},
                                                       {1992, 7, 1, 0, 0, 0, -8},
                                                       {1991, 1, 1, 0, 0, 0, -7},
                                                       {1990, 1, 1, 0, 0, 0, -6},
                                                       {1988, 1, 1, 0, 0, 0, -5},
                                                       {1985, 7, 1, 0, 0, 0, -4},
                                                       {1983, 7, 1, 0, 0, 0, -3},
                                                       {1982, 7, 1, 0, 0, 0, -2},
                                                       {1981, 7, 1, 0, 0, 0, -1},
                                                       {1980, 1, 6, 0, 0, 0, 0}};

        /* leap seconds (y,m,d,h,m,s,utc-gpst) */
        const static DOUBLE BDS_LEAPSEC_INFO[65][7] = {{2017, 1, 1, 0, 0, 0, -4},
                                                       {2015, 7, 1, 0, 0, 0, -3},
                                                       {2012, 7, 1, 0, 0, 0, -2},
                                                       {2009, 1, 1, 0, 0, 0, -1},
                                                       {2006, 1, 1, 0, 0, 0, 0}};

        // For Angle
        const static INT32 ANGLE_LENGTH = 11;
        const static DOUBLE PI = 3.1415926535897932;     /* pi */
        const static DOUBLE D2R = (PI / 180.0);          /* deg to rad */
        const static DOUBLE R2D = (180.0 / PI);          /* rad to deg */
        const static DOUBLE SIN_5 = -0.0871557427476582; /* sin(-5.0 deg) */
        const static DOUBLE COS_5 = 0.9961946980917456;  /* cos(-5.0 deg) */
        const INT32 DEG_TO_SEC = 3600;                   /* 角度转秒 */


        const static DOUBLE J2_GLO = 1.0826257E-3; /* 2nd zonal harmonic of geopot   ref [2] */
        const static INT32 MAX_ITER_KEPLER = 30;   /* max number of iteration of Kelpler */
        const static DOUBLE RTOL_KEPLER = 1E-14;   /* relative tolerance for Kepler equation */
        const static DOUBLE RE_GLO = 6378136.0;    /* radius of earth (m)            ref [2] */

        const static DOUBLE GPS_GRAVITATION = 3.9860050E14;   /* gravitational constant         ref [1] */
        const static DOUBLE GLO_GRAVITATION = 3.9860044E14;   /* gravitational constant         ref [2] */
        const static DOUBLE GAL_GRAVITATION = 3.986004418E14; /* earth gravitational constant   ref [7] */
        const static DOUBLE BDS_GRAVITATION = 3.986004418E14; /* earth gravitational constant   ref [9] */

        const static DOUBLE GPS_ANGULAR_VELOCITY = 7.2921151467E-5; /* earth angular velocity (IS-GPS) (rad/s) */
        const static DOUBLE GLO_ANGULAR_VELOCITY = 7.292115E-5;     /* earth angular velocity (rad/s) ref [2] */
        const static DOUBLE GAL_ANGULAR_VELOCITY = 7.2921151467E-5; /* earth angular velocity (rad/s) ref [7] */
        const static DOUBLE BDS_ANGULAR_VELOCITY = 7.292115E-5;     /* earth angular velocity (rad/s) ref [9] */
        const static DOUBLE DOUBLE_ZONE_LITTLE = -1E9;
        const static DOUBLE DOUBLE_ZONE_BIG = 1E9;

        const INT32 GPSLEAP_TO_BDSLEAP = 14;

        const INT32 NUM_ONE = 1;
        const INT32 NUM_SIX = 6;
        const INT32 FIFTEEN_MIN_TO_SEC = 15;

        const double LAT_ACCURACY = 1.0e-08;            //计算大地纬度B时的精度
        const double EARTH_OBLATEO = 1 / 298.257222101; //扁率

        const double EARTH_LONG_RADIUS = 6378137;                                                //长半径
        const double EARTH_SHORT_RADIUS = EARTH_LONG_RADIUS - EARTH_OBLATEO * EARTH_LONG_RADIUS; //短半径
        const double E2 = (EARTH_LONG_RADIUS * EARTH_LONG_RADIUS - EARTH_SHORT_RADIUS * EARTH_SHORT_RADIUS)
                          / (EARTH_LONG_RADIUS * EARTH_LONG_RADIUS); // e为第一偏心率
    }                                                                // end namespace GNSSUtilityLib
} // end namespace sixents

#endif
