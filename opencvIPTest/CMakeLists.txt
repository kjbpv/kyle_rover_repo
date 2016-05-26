PROJECT(opencvIPTest)

find_package(OpenCV REQUIRED core features2d imgproc flann highgui video ml)

include_directories($OpenCV_INCLUDE_DIRECTORIES)

ADD_EXECUTABLE(opencvIPTest main.cpp)
TARGET_LINK_LIBRARIES(opencvIPTest ${OpenCV_LIBS})
