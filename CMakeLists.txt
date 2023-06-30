# CMakeList.txt: Cpptool 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#

# 将源代码添加到此项目的可执行文件。
add_executable (Cpptool "main.cpp" "threadpool.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
	set_property(TARGET Cpptool PROPERTY CXX_STANDARD 20)
	set_property(TARGET Cpptool PROPERTY CXX_STANDARD_REQUIRED ON)
	if(CMAKE_HOST_UNIX)
		TARGET_LINK_LIBRARIES(Cpptool pthread)
		message("current platform: Linux ")
	elseif(CMAKE_HOST_WIN32)
		message("current platform: Windows ") 
	else()
		message("current platform: unkonw ")
	endif()
	#SET(CMAKE_CXX_STANDARD 20)
	#SET(CMAKE_CXX_STANDARD_REQUIRED ON)
endif()

#if (MSVC_VERSION GREATER_EQUAL "1914")
#    add_compile_options("/Zc:__cplusplus") 
#endif()

# TODO: 如有需要，请添加测试并安装目标。
