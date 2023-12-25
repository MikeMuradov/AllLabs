file(GLOB hdrs "*.h*")
file(GLOB srcs "*.cpp")

add_library(${postfixlib} STATIC ${srcs} ${hdrs})
target_link_libraries(${postfixlib} ${LIBRARY_DEPS})


