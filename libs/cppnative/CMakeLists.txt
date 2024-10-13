message(STATUS "Standard Library Build - ON")

# Build io
file(GLOB IO_FILES io/io.h io/io.cpp)
add_library(io SHARED ${IO_FILES})
target_link_libraries(io vm)