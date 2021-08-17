SET(targetname libDataLoader)

INCLUDE(UseOpenCV)
INCLUDE(UseEigen3)

SET(sources
        src/dataloader_scannet.cpp
        src/dataloader_3rscan.cpp
        ScanNetLoader/sensorData.cpp
)
SET(headers
        include/dataLoader/dataset_loader.h
        include/dataLoader/dataset_loader_facotry.h
)


ADD_COMPILE_DEFINITIONS(_ENABLE_EXTENDED_ALIGNED_STORAGE)
#ADD_COMPILE_DEFINITIONS(_DISABLE_EXTENDED_ALIGNED_STORAGE) not sure if this or the previous
ADD_LIBRARY(${targetname} ${sources} ${headers})
TARGET_INCLUDE_DIRECTORIES(${targetname} PUBLIC ./include)
TARGET_INCLUDE_DIRECTORIES(${targetname} PUBLIC ${PROJECT_SOURCE_DIR})
TARGET_INCLUDE_DIRECTORIES(${targetname} PUBLIC ${DIRENT_INCLUDE_DIR})