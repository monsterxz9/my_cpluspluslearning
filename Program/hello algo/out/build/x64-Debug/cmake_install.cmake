# Install script for directory: E:/program/Dev C++ 文件/hello algo

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "E:/program/Dev C++ 文件/hello algo/out/install/x64-Debug")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("E:/program/Dev C++ 文件/hello algo/out/build/x64-Debug/include/cmake_install.cmake")
  include("E:/program/Dev C++ 文件/hello algo/out/build/x64-Debug/chapter_computational_complexity/cmake_install.cmake")
  include("E:/program/Dev C++ 文件/hello algo/out/build/x64-Debug/chapter_array_and_linkedlist/cmake_install.cmake")
  include("E:/program/Dev C++ 文件/hello algo/out/build/x64-Debug/chapter_sorting/cmake_install.cmake")
  include("E:/program/Dev C++ 文件/hello algo/out/build/x64-Debug/chapter_tree/cmake_install.cmake")
  include("E:/program/Dev C++ 文件/hello algo/out/build/x64-Debug/chapter_stack_and_queue/cmake_install.cmake")
  include("E:/program/Dev C++ 文件/hello algo/out/build/x64-Debug/chapter_heap/cmake_install.cmake")

endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "E:/program/Dev C++ 文件/hello algo/out/build/x64-Debug/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
