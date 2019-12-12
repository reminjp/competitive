#ifndef CONSTRAINTS_HPP
#define CONSTRAINTS_HPP

#include <cstdint>
#include <cstddef>

const size_t MIN_N = 625;
const size_t MAX_N = 625;

const size_t MIN_C = 1;
const size_t MAX_C = 100;

const int64_t TIME_LIMIT = 10000;
const int64_t TIME_LAST = static_cast<int64_t>(TIME_LIMIT * 0.95);

const size_t INDEXED = 1;

const size_t MAX_DEGREE = 5;

const size_t MIN_N_ORDER = 0;
const size_t MAX_N_ORDER = 1;

const size_t MIN_ID = 1;
const size_t MAX_ID = TIME_LAST + 1;

const size_t MIN_FREQ = 1;
const size_t MAX_FREQ = 2;

const size_t COST_SPEEDWAY = 1;
const size_t SCALE_HIGHWAY = 4;
const size_t SCALE_ROAD = 4;

const size_t INTERVAL = 5;

const size_t P_LIGHT_MIN = 10;
const size_t P_LIGHT_MAX = 30;
const size_t T_WARNING_MIN = 50;
const size_t T_WARNING_MAX = 120;

const double P_JAM = 0.25;
const double P_MOVE = 0.1;
#endif
