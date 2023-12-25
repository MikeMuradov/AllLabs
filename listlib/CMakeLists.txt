file(GLOB hdrs "*.h*")
file(GLOB srcs "*.cpp")

add_library(${listlib} STATIC ${srcs} ${hdrs})
target_link_libraries(${listlib} ${LIBRARY_DEPS})

