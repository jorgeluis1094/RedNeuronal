cmake_minimum_required(VERSION 3.5)

project(Red LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Red main.cpp

    redneuronal.h redneuronal.cpp)

include(GNUInstallDirs)
install(TARGETS Red
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
