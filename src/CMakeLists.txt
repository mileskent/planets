cmake_minimum_required(VERSION 3.0)
project(sfml-app)

# Locate SFML package
find_package(SFML 2.5 COMPONENTS graphics window system audio REQUIRED)

# Add executable target
add_executable(sfml-app main.cpp)

# Link SFML libraries
target_link_libraries(sfml-app PRIVATE sfml-graphics sfml-window sfml-system sfml-audio)
