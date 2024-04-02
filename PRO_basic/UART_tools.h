#pragma once

#include <stdint.h>

const auto strPortName = "COM5";
const auto SIZE_BUFF_UART = 8192;
const auto PACK_BUFFER_SIZE = 512;
const auto HEADER_SIZE = 4;
const auto PREFIX = 0x24;
const auto QN_CHANEL_MAX = 64;

struct S_BufferUART {
    uint8_t buf[SIZE_BUFF_UART];
    uint16_t cn_in;
    uint32_t cn_out;
};

enum class CMD {
    CMD_DATA_NOT_QUESTION=0x00,
    CMD_GET_SOFT_REVISION,
    CMD_SET_PERIOD_CHECK,
    CMD_ON_OFF_CHECK,
    CMD_LOOP_DATA=0x13,
    CMD_FREE_DATA_MKIO,
    CMD_GET_TEST_1,
    CMD_GET_TEST_0,
    CMD_GET_TEST_8282,
    CMD_SET_CHANEL_CHECK,
//    CMD_SET_AMPLIF_HEATER,  // коэффициент усиления термоанемометра 0..4 (0 - выключен)
//    CMD_SET_AMPLIF_LM,      // коэффициент усиления сигнала локатора муфт 1..4
//    CMD_SET_AMPLIF_SH,      // коэффициент усиления сигнала шумомера 1..4
//    CMD_SET_DEPTH_MODE,   // увязка по глубине
};

enum {
//enum class STEP {
    STEP_PREFIX=0x00,
    STEP_HEADER,
    STEP_LOAD_PACK
};

struct S_Header {
    uint8_t prefix;
    CMD cmd;
    uint8_t qn_data;
    uint8_t crc;
};

struct S_Pack {
    S_Header header;
    uint8_t data[PACK_BUFFER_SIZE];
};

struct S_ChanelData {
    int chanel;
    int data[2];
};

struct S_LoopData{
    uint32_t time;
    S_ChanelData ch_data[QN_CHANEL_MAX];
};

struct S_QueData {
    uint32_t time;
    uint16_t data[32];
};
