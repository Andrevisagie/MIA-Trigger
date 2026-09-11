cmake_minimum_required(VERSION 3.12)
project(MIA-Trigger VERSION 1.0)

# Ensure C++ standard is set
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# -------------------------------------------------------------------
# Fetch Submodules / Dependencies
# -------------------------------------------------------------------
include(FetchContent)

FetchContent_Declare(
    intelliwip-populate
    GIT_REPOSITORY https://github.com
    GIT_TAG        master
)

# Populate manually instead of using MakeAvailable to prevent CMake 
# from looking for a non-existent root CMakeLists.txt in the submodules repo
FetchContent_GetProperties(intelliwip-populate)
if(NOT intelliwip-populate_POPULATED)
    FetchContent_Populate(intelliwip-populate)
    
    # NOTE: If there are independent library folders inside the downloaded 
    # submodules folder that contain their own CMakeLists.txt, add them here:
    # add_subdirectory(${intelliwip-populate_SOURCE_DIR}/<folder_name>)
endif()

# -------------------------------------------------------------------
# Project Target Configuration
# -------------------------------------------------------------------
# Define the executable using the source files found in your repository
add_executable(MIA-Trigger
    src/MiaTriggerController.cpp
    src/MiaTriggerEntry.cpp
    src/MiaTriggerProcessor.cpp
)

# Include the local 'include' directory for headers
target_include_directories(MIA-Trigger PRIVATE include)

# Include the downloaded submodules directory so your source files can find its headers
target_include_directories(MIA-Trigger PRIVATE ${intelliwip-populate_SOURCE_DIR})
