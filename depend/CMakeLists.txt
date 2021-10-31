include(FetchContent) # Contains functions for CMake we need

# This command fetches the 2.5.1 Source Code of SFML
FetchContent_Declare(sfml GIT_REPOSITORY "https://github.com/SFML/SFML" GIT_TAG 2f11710abc5aa478503a7ff3f9e654bd2078ebab)

add_subdirectory(sfml)