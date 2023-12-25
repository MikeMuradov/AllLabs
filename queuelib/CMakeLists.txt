file(GLOB hdrs "*.h*")
file(GLOB srcs "*.cpp")

add_library(${queuelib} STATIC ${srcs} ${hdrs})
target_link_libraries(${queuelib} ${LIBRARY_DEPS})
set_target_properties(${queuelib} PROPERTIES LINKER_LANGUAGE CXX)

