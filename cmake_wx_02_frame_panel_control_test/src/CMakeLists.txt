cmake_minimum_required(VERSION 3.1.0)

project(wx)
set( project_name wx )

IF(WIN32)
  IF(MSVC)
    # debug flag
	SET(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} /D_DEBUG /D__WXDEBUG__ /W4 /Zi /Od /Ob1 /MTd /fp:precise /fp:except-")
	SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /D_DEBUG /D__WXDEBUG__ /W4 /Zi /Od /Ob1 /MTd /fp:precise /fp:except-")
	# release flag
	SET(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} /W3 /Zi /Od /Ob1 /GF /EHsc /MT /Gy /fp:precise /fp:except- /Zc:wchar_t /Gd /TC")
	SET(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /W3 /Zi /Od /Ob1 /GF /EHsc /MT /Gy /fp:precise /fp:except- /Zc:wchar_t /Gd /TP")
	#
    SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /SAFESEH:NO /DYNAMICBASE:NO ")	#/NODEFAULTLIB:LIBCMTD.lib /NODEFAULTLIB:libcpmtd.lib /NODEFAULTLIB:boost_system.lib /NODEFAULTLIB:boost_thread.lib
	#
	MESSAGE ("CMAKE_CXX_FLAGS_RELEASE: " "${CMAKE_CXX_FLAGS_RELEASE}")
  ENDIF()
ENDIF()

include_directories(
	../;
	../src;
	../../extern/wxwidget/lib/winnt_x86/mswud;
	../../extern/wxwidget/include;
)

link_directories(
    ../../extern/wxwidget/lib/winnt_x86;
)

# Populate a CMake variable with the sources
FILE(GLOB project_sources
    main.cpp
    wxposframe.cpp
)

FILE(GLOB project_headers
    main.h
    wxposframe.h
)

SET( project_resources 

)

# mark as startup project
IF(WIN32 AND MSVC)
	set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${project_name})
ENDIF()

# Tell CMake to create the project executable
add_executable( ${project_name} WIN32 ${project_sources} ${project_headers} ${project_resources})

TARGET_LINK_LIBRARIES (${PROJECT_NAME}
	iphlpapi.lib 
	wxbase29ud_net.lib 
	wxmsw29ud_core.lib 
	wxbase29ud.lib 
	wxtiffd.lib 
	wxjpegd.lib 
	wxpngd.lib 
	wxzlibd.lib 
	wxregexud.lib 
	wxexpatd.lib 
	winmm.lib 
	comctl32.lib 
	rpcrt4.lib 
	wsock32.lib 
	odbc32.lib 
)
