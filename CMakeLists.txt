cmake_minimum_required(VERSION 3.8)

project(TravelingSalesperson VERSION 1.0)

# Add the executable
add_executable(TravelingSalesperson src/main.cpp)

# Set SFML directory
set(SFML_DIR "${CMAKE_SOURCE_DIR}/Dependencies/lib/cmake/SFML")

# Find SFML package
find_package(SFML 2.6 COMPONENTS system window graphics REQUIRED)

# Include SFML directories
include_directories(${CMAKE_SOURCE_DIR}/Dependencies/include)

# Link SFML libraries
target_link_libraries(TravelingSalesperson PRIVATE
    sfml-graphics
    sfml-system
    sfml-window
)

# Set C++ standard
set_property(TARGET TravelingSalesperson PROPERTY CXX_STANDARD 17)
set_property(TARGET TravelingSalesperson PROPERTY CXX_STANDARD_REQUIRED ON)

# Copy SFML DLLs to output directory if needed
# Note: This step is optional based on whether you're using SFML DLLs
# set(SFML_DLL_DIR "${CMAKE_SOURCE_DIR}/Dependencies/bin")
# add_custom_command(TARGET TravelingSalesperson POST_BUILD
#     COMMAND ${CMAKE_COMMAND} -E copy_if_different
#     ${SFML_DLL_DIR}/$<CONFIG>/sfml-graphics$<$<CONFIG:Debug>:-d>-2.dll
#     ${SFML_DLL_DIR}/$<CONFIG>/sfml-system$<$<CONFIG:Debug>:-d>-2.dll
#     ${SFML_DLL_DIR}/$<CONFIG>/sfml-window$<$<CONFIG:Debug>:-d>-2.dll
#     $<TARGET_FILE_DIR:TravelingSalesperson>
# )

