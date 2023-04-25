cmake_minimum_required(VERSION 3.24)
project(lab6)

set(CMAKE_CXX_STANDARD 11)

add_executable(lab6 main.cpp AIBot.cpp joystick.cpp ScreenObject.h ScreenObject.cpp BatteryChargers.cpp BatteryChargers.h helper.h ServerFarmers.cpp ServerFarmers.h CaringCapacitors.cpp CaringCapacitors.h RebelResistors.cpp RebelResistors.h AIPoisonPill.cpp AIPoisonPill.h)
