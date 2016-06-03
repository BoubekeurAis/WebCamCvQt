PROJECT(WebCamCVQT)
find_package(OpenCV REQUIRED )


# Find Qt.
find_package(Qt5Core)
find_package(Qt5Gui)
find_package(Qt5Widgets)
find_package(Qt5OpenGL)
find_package(Qt5Multimedia)
find_package(Qt5MultimediaWidgets)


## GenerationDatabase files
SET(WebCamCVQT_SRCS
	RGBCamera.cpp
	main.cpp
	qcvwidget.cpp
)

SET(WebCamCVQT_HDRS
	RGBCamera.h
	qcvwidget.h
)

SET(WebCamCVQT_UI
	qcvwidget.ui
)

QT5_WRAP_CPP(WebCamCVQT_HEADERS_MOC ${WebCamCVQT_HDRS})
QT5_WRAP_UI(WebCamCVQT_UI_HEADERS ${WebCamCVQT_UI})

SOURCE_GROUP("Moc Files" FILES ${WebCamCVQT_HEADERS_MOC})
SOURCE_GROUP("Ui Files" FILES ${WebCamCVQT_UI} ${WebCamCVQT_UI_HEADERS})

INCLUDE_DIRECTORIES(
	${CMAKE_BINARY_DIR}
	${OpenCV_INCLUDE_DIRS}/include
  )
LINK_DIRECTORIES(${PCL_LIBRARY_DIRS}
				${OpenCV_LIBRARY_DIRS}
				)
ADD_DEFINITIONS (${PCL_DEFINITIONS})
  
SET( DEPS
	${Qt5Widgets_LIBRARIES} 
	${Qt5Gui_LIBRARIES} 
	${Qt5Core_LIBRARIES} 
	${Qt5OpenGL_LIBRARIES}
	${Qt5Multimedia}
	${Qt5MultimediaWidgets}
	${OpenCV_LIBS}
	)
	
ADD_EXECUTABLE(WebCamCVQT
  ${WebCamCVQT_SRCS} 
  ${WebCamCVQT_HDRS}
  ${WebCamCVQT_HEADERS_MOC} 
  ${WebCamCVQT_UI_HEADERS}
  )

TARGET_LINK_LIBRARIES(WebCamCVQT ${DEPS} )





