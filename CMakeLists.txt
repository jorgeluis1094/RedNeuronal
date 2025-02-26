cmake_minimum_required(VERSION 3.5)

project(Red LANGUAGES CXX)
#FIND_PACKAGE( OpenCV REQUIRED )

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Red main.cpp
    redneuronal.h redneuronal.cpp)

#include_directories(${DIR}/headers /opt/local/include)
#link_directories (${DIR}/src/utils /opt/local/lib)



#include_directories(${DIR}/headers /usr/local/include/opencv4/opencv2/)
#link_directories (${DIR}/src/utils /usr/local/lib)


find_package( OpenCV REQUIRED )
if( OpenCV_FOUND )
list( APPEND ThirdParty_LIBS ${OpenCV_LIBS} )
    include_directories( ${OpenCV_INCLUDE_DIRS} )
endif( OpenCV_FOUND )



TARGET_LINK_LIBRARIES( Red ${OpenCV_LIBS} )

include(GNUInstallDirs)
install(TARGETS Red
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)


