file(GLOB Skoge_SRC "*.cpp" "*.hpp") # Gets all the cpp and hpp files

add_executable(SkogeExe ${Skoge_SRC}) # Creating the Executable
target_link_libraries(SkogeExe PRIVATE sfml-system sfml-window sfml-graphics sfml-network sfml-audio) # Linking needed Libraries