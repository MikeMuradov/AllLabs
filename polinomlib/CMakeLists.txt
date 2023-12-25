file(GLOB hdrs "*.h*")
file(GLOB srcs "*.cpp")

add_library(${polinomlib} STATIC ${srcs} ${hdrs})
target_link_libraries(${polinomlib} ${LIBRARY_DEPS})

