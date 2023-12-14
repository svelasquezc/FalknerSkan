file(GLOB HEADERS CMAKE_CONFIGURE_DEPENDS "${PROJECT_SOURCE_DIR}/include/*.hpp")

add_executable(FalknerSkan main.cpp)

target_link_libraries(FalknerSkan PRIVATE Eigen3::Eigen)

target_include_directories(FalknerSkan PUBLIC ../include)

target_compile_features(FalknerSkan PRIVATE cxx_std_17)

# IDEs should put the headers in a nice place
source_group(
  TREE "${PROJECT_SOURCE_DIR}/include"
  PREFIX "Header Files"
  FILES ${HEADERS}
  )
