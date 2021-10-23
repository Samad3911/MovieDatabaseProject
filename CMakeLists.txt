cmake_minimum_required(VERSION 3.5)
project(MovieDB)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

set (HEADERS
  include/movie.h
  include/movieduration.h
  include/releasedate.h
  include/supportingcast.h
  include/moviedatabasemenu.h
  database/imoviedatabase.h
  database/moviedatabase.h
  moviecontroller/moviecontroller.h
)



set (SOURCES
  src/movie.cpp
  src/releasedate.cpp
  src/movieduration.cpp
  src/supportingcast.cpp
  database/moviedatabase.cpp
  moviecontroller/moviecontroller.cpp
  src/moviedatabasemenu.cpp
  src/main.cpp
)

add_executable(MovieDB ${SOURCES} ${HEADERS})             

target_link_libraries(MovieDB 
pthread
)     

