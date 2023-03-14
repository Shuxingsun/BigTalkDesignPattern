cmake_minimum_required(VERSION 3.24)
project(BigTalkDesignPattern)

set(CMAKE_CXX_STANDARD 11)


add_executable(simplyfactory "codes/ch01 simple_factory/simple_factory.cpp")
add_executable(simplyfactory2 "codes/ch01 simple_factory/Operation.cpp" "codes/ch01 simple_factory/Operation.h")
add_executable(strategy "codes/ch02 strategy/strategy.cpp")
add_executable(Cash "codes/ch02 strategy/Cash.cpp")
add_executable(decorator "codes/ch06 decorator/decorator.cpp")
add_executable(decorator2 "codes/ch06 decorator/decorator2.cpp")

add_executable(proxy "codes/ch07_proxy/proxy.cpp")
add_executable(pursuit "codes/ch07_proxy/Pursuit.cpp")
add_executable(factory_method "codes/ch08_factory-method/factory-method.cpp")
add_executable(Leifeng "codes/ch08_factory-method/Leifeng.cpp")
add_executable(Resume "codes/ch09_prototype/Resume.cpp")
add_executable(template_method "codes/ch10_template_method/template_method.cpp")
add_executable(testPaper "codes/ch10_template_method/TestPaper.cpp")