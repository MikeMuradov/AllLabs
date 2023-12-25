cmake_minimum_required(VERSION 2.8...3.13) 
	
set(PROJECT_NAME labs) 
project(${PROJECT_NAME})

set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "Configs" FORCE) #Создается переменная CMAKE_CONFIGURATION_TYPES со значением "Debug;Release" и меткой/разделом Configs, переменная сохраниется в специальном файле доступном из всех файлов,
if(NOT CMAKE_BUILD_TYPE) # проверка имеющихся у компилятора вариантов сборки
  set(CMAKE_BUILD_TYPE Release) #Если нет то устанавливаем Release
endif()

set(stack stack) 
set(stacklib stacklib) 
set(stacktest stacktest)

set(queue queue) 
set(queuelib queuelib) 
set(queuetest queuetest)
set(queueinterface queueinterface)

set(postfix postfix) 
set(postfixlib postfixlib) 
set(postfixtest postfixtest)

set(listlib listlib)

set(polinom polinom) 
set(polinomlib polinomlib) 
set(polinomtest polinomtest)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/gtest)

add_subdirectory(gtest)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/stacklib)
add_subdirectory(stack)
add_subdirectory(stacklib)
add_subdirectory(stacktest)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/queuelib)
add_subdirectory(queue)
add_subdirectory(queuelib)
add_subdirectory(queuetest)
add_subdirectory(queueinterface)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/postfixlib)
add_subdirectory(postfix)
add_subdirectory(postfixlib)
#add_subdirectory(postfixtest)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/listlib)
add_subdirectory(listlib)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/polinomlib)
add_subdirectory(polinom)
add_subdirectory(polinomlib)
#add_subdirectory(polinomtest)
