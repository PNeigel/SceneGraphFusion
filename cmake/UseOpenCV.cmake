###################
# UseOpenCV.cmake #
###################
find_package(OpenCV 4.0.0 QUIET)
find_package(OpenCV 4.0.0 QUIET CONFIG PATHS ${OpenCV_CONFIG_DIR})
OPTION(WITH_OPENCV "Build with OpenCV support?" ${OpenCV_FOUND})

IF(WITH_OPENCV)
    MESSAGE("WITH_OPENCV: " ${WITH_OPENCV})
  IF(NOT OpenCV_FOUND)
      MESSAGE("OpenCV was not found, it will be downloaded and build externally. If you have installed OpenCV already, set the OpenCV_CONFIG_DIR variable to the directory containing the OpenCVConfig.cmake")
      INCLUDE(ConfigureTimeDependency)
      add_configure_time_dependency(OpenCV)
      find_package(OpenCV REQUIRED)
  ENDIF()
  INCLUDE_DIRECTORIES(${OpenCV_INCLUDE_DIRS})
  link_directories(${OpenCV_LIB_DIRS})
  ADD_DEFINITIONS(-DCOMPILE_WITH_OPENCV)
ELSE()
  ADD_DEFINITIONS(-DCOMPILE_WITHOUT_OPENCV)
ENDIF()
