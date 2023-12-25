set(nameMain "Main")

file(GLOB hdrs "*.h*")
file(GLOB srcs "*.cpp" "../src/*.cpp")
file(GLOB resx "*.resx")

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /SUBSYSTEM:WINDOWS /ENTRY:${nameMain}")
add_executable(${queueinterface} WIN32 ${srcs} ${hdrs} ${resx}) 
target_link_libraries(${queueinterface} ${queuelib}) 
set_target_properties(${queueinterface} PROPERTIES
    VS_DOTNET_REFERENCES "System;System.Data;System.Drawing;System.Windows.Forms;System.Xml"
    VS_GLOBAL_ROOTNAMESPACE ${queueinterface}
    COMMON_LANGUAGE_RUNTIME ""
    CMAKE_VS_TARGET_FRAMEWORK_VERSION "v4.7.2"
)

