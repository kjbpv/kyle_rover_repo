PROJECT(camera_view)

find_package(OpenCV REQUIRED core features2d imgproc flann highgui video ml)

include_directories($OpenCV_INCLUDE_DIRECTORIES)

ADD_EXECUTABLE(camera_view main.cpp)
TARGET_LINK_LIBRARIES(camera_view ${OpenCV_LIBS})
